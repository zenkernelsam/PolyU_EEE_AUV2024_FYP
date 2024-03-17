from launch import LaunchDescription           # launch文件的描述类
from launch_ros.actions import Node            # 节点启动的描述类

def generate_launch_description():             # 自动生成launch文件的函数
    return LaunchDescription([                 # 返回launch文件的描述信息
        #Node(                                  # 配置一个节点的启动
        #    package='facer_input',             # 节点所在的功能包
        #    executable='capture_image',        # 节点的可执行文件
        #),
        #Node(                                  # 配置一个节点的启动
        #    package='task1_flare_detection',   # 节点所在的功能包
        #    executable='flare_detection',      # 节点的可执行文件
        #),
        Node(
            package='buoyancy_node',
            executable='buoyancy_node_test',      
            arguments=['True','3'],
        ),
        Node(
            package='task1_node',
            executable='task1_node', 
            arguments=['False', 'Up','Forward'],   
        ),
        Node(
            package='master_node',
            executable='master_node',                 
        ),
        Node(
            package='control_node',
            executable='control_node',            
        )
    ])