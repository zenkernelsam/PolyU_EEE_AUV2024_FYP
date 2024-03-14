from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='facer_input',
            executable='capture_image',
            name='capture_image',
            output='screen',
            emulate_tty=True,
            parameters=[
                {'timer_period': 1.0}
            ]
        )
    ])