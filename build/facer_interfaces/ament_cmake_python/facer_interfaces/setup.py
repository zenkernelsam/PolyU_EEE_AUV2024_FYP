from setuptools import find_packages
from setuptools import setup

setup(
    name='facer_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('facer_interfaces', 'facer_interfaces.*')),
)
