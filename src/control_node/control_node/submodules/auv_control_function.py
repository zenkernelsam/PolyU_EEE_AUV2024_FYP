#FYP AUV Control Designed by Cisco HE
#20058054d@connect.polyu.hk
#Function: including main control functions to control AUV's thruster and the buoyancy system (i.e. water_pump)
#Branch from ~/orangepi/dev/robot_IR.py
import evdev
import os
import math
#import atexit #removed
import time
import wiringpi
from wiringpi import GPIO

#AUV Electrical Machine Initialization

# Define conditions to initialize ESC and water pump DC driver: 50Hz
frequency_Hz = 50
period = 1 / frequency_Hz * 1E9

water_pump_hz = 100
water_pump_period = (1/100)*1E9
# End of initialization of PWM frequeny and period


#Initialize duty cycle (5% for thruster, 80% for water pump) for thrust_control(percentage)
thruster_speed = 5
pump_voltage = 99
target = ""
wording = ""



#Define init_pwm() to initialize PWM Channel:
def init_pwm(channel):
    pwm = "pwmchip"+str(channel)
    os.system(f"echo 0 > /sys/class/pwm/{pwm}/export")

def call_bash(pwm, period, duty_cycle):
    print("Debug: call_bash() has been called.")
    os.system(f"sudo echo 0 > /sys/class/pwm/{pwm}/pwm0/enable")
    os.system("sudo echo " + str(math.trunc(period)) + f" > /sys/class/pwm/{pwm}/pwm0/period")
    os.system("sudo echo " + str(math.trunc(duty_cycle)) + f" > /sys/class/pwm/{pwm}/pwm0/duty_cycle")
    os.system(f"sudo echo 1 > /sys/class/pwm/{pwm}/pwm0/enable")
    print("call_bash() is finished")


#Define thruster_move(thruster,period,d_cycle,time) to adjust PWM signals of thrusters and water pump (including period, duty cycle and ON/OFF)
#thruster: left/right/water_pump, period, duty cycle, moving time till stop (second)
def thruster_move(thruster,period,d_cycle,t):
    print("Debug: thruster_move() has been called. Thruster: {}, Period: {}, d_cycle: {}, t: {} seconds".format(thruster,period,d_cycle,str(t)))

     #Normalize duty_cycle

    ###OFFSET THRUSTER SPEEDS HERE###
    duty_cycle_L = period*(1-float(d_cycle)/100)
    duty_cycle_R = period*(1-float(d_cycle+0.5)/100)

    #Adjusting PWN Parameters
    if thruster == "left":
        call_bash("pwmchip2", period, duty_cycle_L)
    elif thruster == "right":
        call_bash("pwmchip3", period, duty_cycle_R)
    elif thruster == "all":
        call_bash("pwmchip2", period, duty_cycle_L)
        call_bash("pwmchip3", period, duty_cycle_R)
    elif thruster == "water_pump1":
        call_bash("pwmchip2", period, duty_cycle_L)
    elif thruster == "water_pump2":
        call_bash("pwmchip5", period, duty_cycle_L)
    else:
        print("Error: thruster is unknown: {}".format(thruster))
        return False
    
    #Automatically switch OFF (4.5Hz) after t seconds. If t=0, ON is kept.
    if t != 0:
        print(f"{thruster} will stop after {t} seconds...")
        time.sleep(t)
        off_duty_cycle = period*(1-5/100)
        if thruster == "left":
            os.system("sudo echo " + str(math.trunc(off_duty_cycle)) + f" > /sys/class/pwm/pwmchip2/pwm0/duty_cycle")
        elif thruster == "right":
            os.system("sudo echo " + str(math.trunc(off_duty_cycle)) + f" > /sys/class/pwm/pwmchip3/pwm0/duty_cycle")
        elif thruster == "all":
            os.system("sudo echo " + str(math.trunc(off_duty_cycle)) + f" > /sys/class/pwm/pwmchip2/pwm0/duty_cycle")
            os.system("sudo echo " + str(math.trunc(off_duty_cycle)) + f" > /sys/class/pwm/pwmchip3/pwm0/duty_cycle")
    print("thruster_move() is finished")
    return True

#Define thruster_control(type, level) to control thruster or water-pump's speed by direct adding percentage of duty cycle 
#(inside this function also calls thruster_move(), this function just does some data calculations for convenient use)
#type: all(all thrusters)/left (left thruster)/right (right thruster)
#Level: percentage you add to the duty cycle i.e. 0.2 for duty cycle + 0.2% and -0.2 for duty cycle - 0.2% 
def thruster_control(type,level):

    global thruster_speed #5-10
    global pump_voltage #0-99
    print("Debug: thruster_control has been called. Type: {}, Level: {}".format(type,str(level)))
    if type == "all":
        if 4.9 < round(thruster_speed + level,2) <= 10.1 and level < 0:
            thruster_speed += level
            if thruster_move("left",period, thruster_speed,0) == True and thruster_move("right",period, thruster_speed,0) == True:
                print("All thrusters Duty Cycle is changed: {}%".format(round(thruster_speed,2)))
            else:
                print("Error in line 62")

        elif 4.9 <= round(thruster_speed + level,2) < 10.1 and level > 0:
            thruster_speed += level
            if thruster_move("left",period, thruster_speed,0) == True and thruster_move("right",period, thruster_speed,0) == True:
                print("All thrusters Duty Cycle is changed: {}%".format(round(thruster_speed,2)))
            else:
                print("Error in line 69")

        else:
            print("Out of level. Duty cycle: {}%".format(thruster_speed))

    elif type == "left" or type == "right":
        if 4.9 < round(thruster_speed + level,2) <= 10.1 and level < 0:
            thruster_speed += level
            if thruster_move(type,period,thruster_speed,0) == True:
                print("{} Duty Cycle is changed: {}%".format(type,round(thruster_speed,2)))
            else:
                print("Error in line 80")

        elif 4.9 <= round(thruster_speed + level,2) < 10.1 and level > 0:
            thruster_speed += level
            if thruster_move(type,period,thruster_speed,0) == True:
                print("{} Duty Cycle is changed: {}%".format(type,round(thruster_speed,2)))
            else:
                print("Error in line 87")

        else:
            print("Out of level. Duty cycle: {}%".format(thruster_speed))


    elif type == "water_pump":
        if 0 < round(pump_voltage + level,2) <= 98 and level < 0: #I make maximum voltage: 12*0.98 ~= 11.76V
            pump_voltage += level
            if thruster_move(type,period,pump_voltage,0) == True:
                print("Water Pump Duty Cycle is changed: {}%".format(round(pump_voltage,2)))
                print("Water Pump Voltage: {}V".format(12*pump_voltage/100))
            else:
                print("Error in line 100")
        elif 0 <= round(pump_voltage + level,2) < 98 and level > 0:
            pump_voltage += level
            if thruster_move(type,period,pump_voltage,0) == True:
                print("*Water Pump Duty Cycle is changed: {}%".format(round(pump_voltage,2)))
                print("Water Pump Voltage: {}V".format(12*pump_voltage/100))
            else:
                print("Error in line 107")

    print("thruster_control() is finished")

#direction: in/out/stop, time: second
def water_pump(type, direction, t):
    if type == 1:
        A = 3
        B = 4
    elif type == 2:
        A = 19
        B = 20
    else:
        print("Error: type is unknown: {}".format(type))
    print("Debug: water_pump() has been called. Type: {}, Direction: {}, Time: {} seconds".format(type,direction,str(t)))
    if direction == "in":
        wiringpi.digitalWrite(A, GPIO.HIGH)
        wiringpi.digitalWrite(B, GPIO.LOW)
    elif direction == "out":
        wiringpi.digitalWrite(A, GPIO.LOW)
        wiringpi.digitalWrite(B, GPIO.HIGH)
    elif direction == "stop":
        wiringpi.digitalWrite(A, GPIO.LOW)
        wiringpi.digitalWrite(B, GPIO.LOW)
    else:
        print("Error: water_direction is unknown: {}".format(direction))
        return False
    if t != 0:
        # Automatically stop after t seconds. If time is 0, the function remains operating
        time.sleep(t)
        wiringpi.digitalWrite(3, GPIO.LOW)
        wiringpi.digitalWrite(4, GPIO.LOW)
    print("water_pump() is finished.")
    return True

#Define a function to re-initialize PWM if the program is exited
def reinit():
    print("\nExit, reinitializing PWM Channel to stop thruster...")
    if thruster_move("left",period,4.5,0) == True and thruster_move("right",period,4.5,0) == True and water_pump("stop",0) == True:
        print("Complete re-initialization")
    else:
        print("Error occurred before re-initializating to exit.")

def IR_control():
    ###START OF IR REMOTE CONTROL###
    
     # IR Remote Controller Path
    device_path = '/dev/input/event0' 
    device = evdev.InputDevice(device_path)
    for event in device.read_loop():
        if event.type == evdev.ecodes.EV_KEY and event.value == 1: #Some conditions when pressing button on IR remote controller
            match evdev.ecodes.KEY[event.code]:
                case "KEY_1":
                    target = "left"
                    wording = "Left thruster"
                    print("Left thruster is now selected. You can press UP/DOWN Botton to adjust thruster speed.\n")
                case "KEY_2":
                    target = "right"
                    wording = "Right thruster"
                    print("Right thruster is now selected. You can press UP/DOWN Botton to adjust thruster speed.\n")
                case "KEY_3":
                    target = "all"
                    wording = "All thrusters"
                    print("All thrusters are now selected. You can press UP/DOWN Botton to adjust thruster speed.\n")                    
                case "KEY_0":
                    target = "water_pump"
                    wording = "Water pump"
                    print("Water pump is now selected. You can press UP/DOWN Botton to adjust DC motor voltage.\n")
                case "KEY_4":
                    water_pump(1,"in", 0)
                    print("Water pump 1 is sucking in water\n")
                case "KEY_6":
                    water_pump(1,"out",0)
                    print("Water pump 1 is sucking out water\n")
                case "KEY_5":
                    water_pump(1,"stop",0)
                    print("Water pump 1 is stopped")
                case "KEY_7":
                    water_pump(2,"in", 0)
                    print("Water pump 2 is sucking in water\n")
                case "KEY_9":
                    water_pump(2,"out",0)
                    print("Water pump 2 is sucking out water\n")
                case "KEY_8":
                    water_pump(2,"stop",0)
                    print("Water pump 2 is stopped")
                case "KEY_UP":
                    if target == "":
                        print("You haven't selected.")
                        continue
                    thruster_control(target, 0.2)
                    print(f"{wording}'s PWM duty cycle is increased by 0.2%\n")
                case "KEY_DOWN":
                    if target == "":
                        print("You haven't selected.")
                        continue
                    thruster_control(target,-0.2)
                    print(f"{wording}'s PWM duty cycle is decreased by 0.2%\n")
                case "KEY_BACK":
                    print("Exiting the program.\n")
                    break
                case _:
                    print("Invalid Control.")
###END OF IR REMOTE CONTROL###

def auv_init():

    print("Start Initialization...")
    #Initialize GPIO Control Channel for water pump:
    wiringpi.wiringPiSetup()
    #Pin 08 --> wPi Pin 3 [GPIO: HIGH/LOW --> ON/OFF]
    #Pin 10 --> wPi Pin 4 [GPIO: HIGH/LOW --> ON/OFF]
    #Pin 29 --> wPi Pin 19 [GPIO: HIGH/LOW --> ON/OFF]
    #Pin 31 --> wPi Pin 20 [GPIO: HIGH/LOW --> ON/OFF]

    #Buoyancy motor driver 1
    wiringpi.pinMode(3, GPIO.OUTPUT)
    wiringpi.pinMode(4, GPIO.OUTPUT)

    #Buoyancy motor driver 2
    wiringpi.pinMode(19, GPIO.OUTPUT)
    wiringpi.pinMode(20, GPIO.OUTPUT)

    #Initialize PWM Channel for thrusters and water pump [pwmchip2, pwmchip3, pwmchip4]
    init_pwm(2)
    init_pwm(3)
    init_pwm(4)
    init_pwm(5)

    #Initial thrusters' PWM signals: 50Hz, 4.5%
    thruster_move("left", period, 4.5, 0)
    thruster_move("right", period, 4.5, 0)

    #Initialize water_pump's PWM signal: 100Hz, 99% or others (then 12V*0.8=9.6V)
    thruster_move("water_pump",(1/100)*1E9, pump_voltage,0)

    #Initialization Complete
    print("Complete Initialization.")


#Thruster case for ROS2
#def thruster_system(parameter, time, angle):
def thruster_system(parameter):
    #print(f"[thruster_system] Hardware Control: Thruster; Direction: {parameter},{time},{angle}")
    print(f"[thruster_system] Hardware Control: Thruster; Direction: {parameter}")
    #Using time control
    #if angle == 0 and time != 0:
    match parameter:
        case "Forward":
            return thruster_move("all", period, 6, 0) #Move forward with duty cycle 6% and non-stop
        case "Left":
                return thruster_move("right", period, 6, 0) #Move left with duty cycle 6% and non-stop
        case "Right":
            return thruster_move("left", period, 6, 0)#Move right with duty cycle 6% and non-stop
        case "None":
            return True
        #Using angle control
        ###Still building up a angle control function using MPU6050###
        #elif angle != 0 and time == 0:

            #print("[X] Angle control is not available")
            #return False
        
        #else:
            #return False

