from setuptools import find_packages, setup

package_name = 'task2_drum_detection'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='mario',
    maintainer_email='mario@todo.todo',
    description='drum detection',
    license='Apache License 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'drum_detection = task2_drum_detection.drum_detection:main',
        ],
    },
)
