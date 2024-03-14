import os
from glob import glob

from setuptools import find_packages, setup

package_name = 'facer_input'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),

        (os.path.join('share', package_name), glob('launch/*launch.[pxy][yma]*')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='mario',
    maintainer_email='mario@todo.todo',
    description='Image collection',
    license='TApache License 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'capture_image = facer_input.capture_image:main',
        ],
    },
)
