from setuptools import find_packages, setup

package_name = 'buoyancy_node'
submodules = "buoyancy_node/submodules"
setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name, submodules],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='orangepi',
    maintainer_email='orangepi@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'buoyancy_node = buoyancy_node.buoyancy_node:main',
            'buoyancy_node_test = buoyancy_node.buoyancy_node_test:main',
        ],
    },
)
