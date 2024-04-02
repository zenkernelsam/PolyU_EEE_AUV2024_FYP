from launch import LaunchDescription          
from launch_ros.actions import Node          

def generate_launch_description():            
    return LaunchDescription([                 
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
