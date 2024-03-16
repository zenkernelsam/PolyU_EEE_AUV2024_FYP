
import serial.tools.list_ports
from pymavlink import mavutil
import time

class pixhawk:
    def __init__(self,port) -> None:
        self.master = mavutil.mavlink_connection(port)
        print("waiting for heartbeat")
        self.master.wait_heartbeat()
        print("Connected")
         # Configure AHRS2 message to be sent at 1Hz
        self.request_message_interval(mavutil.mavlink.MAVLINK_MSG_ID_AHRS2, 20)
      # Request all parameters
    def request_message_interval(self,message_id: int, frequency_hz: float):
        """
        Request MAVLink message in a desired frequency,
        documentation for SET_MESSAGE_INTERVAL:
            https://mavlink.io/en/messages/common.html#MAV_CMD_SET_MESSAGE_INTERVAL

        Args:
            message_id (int): MAVLink message ID
            frequency_hz (float): Desired frequency in Hz
        """
        self.master.mav.command_long_send(
            self.master.target_system, self.master.target_component,
            mavutil.mavlink.MAV_CMD_SET_MESSAGE_INTERVAL, 0,
            message_id, # The MAVLink message ID
            1e6 / frequency_hz, # The interval between two messages in microseconds. Set to -1 to disable and 0 to request default rate.
            0, 0, 0, 0, # Unused parameters
            0, # Target address of message stream (if message has target address fields). 0: Flight-stack default (recommended), 1: address of requestor, 2: broadcast.
        )
    def getData(self):
        _arming = 0  # seems not useful
        # arming = (self.master.recv_match(type='HEARTBEAT', blocking=True).to_dict())
        # position = (self.master.recv_match(type='GLOBAL_POSITION_INT', blocking=True).to_dict())
        state = (self.master.recv_match(type='AHRS2', blocking=True).to_dict())
        # _arming = int(arming['system_status'])
        # heading = int(position['hdg'] / 100)
        heading = 0
        if heading > 180:
            heading -= 360

        # dep_lev = int(position['alt'] / 10)
        dep_lev = float(state['altitude'])
        pitch = float(("{0:.2f}".format((state['pitch'] * 180) / 3.1415)))
        roll = float(("{0:.2f}".format((state['roll'] * 180) / 3.1415)))
        yaw = float(("{0:.2f}".format((state['yaw'] * 180) / 3.1415)))
        return dep_lev


if __name__ == "__main__":
  portN = None
  for port in serial.tools.list_ports.comports():
      if "usb" in port.name or "ACM" in port.name:
          portN = port.device
          print(portN)
  pix = pixhawk(portN)
  while True:
      print(pix.getData())

  # # Request all parameters
  # master.mav.param_request_list_send(
  #     master.target_system, master.target_component
  # )

  # master.mav.param_set_send(
  #     master.target_system, master.target_component,
  #     b'MOT_1_DIRECTION',
  #     -1,
  #     mavutil.mavlink.MAV_PARAM_TYPE_REAL32
  # )
  # while True:
  #     time.sleep(0.01)
  #     try:
  #         message = master.recv_match(type='PARAM_VALUE', blocking=True).to_dict()
  #         print('name: %s\tvalue: %d' % (message['param_id'],
  #                                        message['param_value']))
  #     except Exception as error:
  #         print(error)
  #         sys.exit(0)
