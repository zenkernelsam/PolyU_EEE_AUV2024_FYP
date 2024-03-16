# generated from rosidl_generator_py/resource/_idl.py.em
# with input from control_interfaces:msg/AUVStatus.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_AUVStatus(type):
    """Metaclass of message 'AUVStatus'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('control_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'control_interfaces.msg.AUVStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__auv_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__auv_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__auv_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__auv_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__auv_status

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class AUVStatus(metaclass=Metaclass_AUVStatus):
    """Message class 'AUVStatus'."""

    __slots__ = [
        '_task_name',
        '_thruster_direction',
        '_buoyancy_direction',
        '_buoyancy_setpoint',
        '_buoyancy_now_depth',
    ]

    _fields_and_field_types = {
        'task_name': 'string',
        'thruster_direction': 'string',
        'buoyancy_direction': 'string',
        'buoyancy_setpoint': 'float',
        'buoyancy_now_depth': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.task_name = kwargs.get('task_name', str())
        self.thruster_direction = kwargs.get('thruster_direction', str())
        self.buoyancy_direction = kwargs.get('buoyancy_direction', str())
        self.buoyancy_setpoint = kwargs.get('buoyancy_setpoint', float())
        self.buoyancy_now_depth = kwargs.get('buoyancy_now_depth', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.task_name != other.task_name:
            return False
        if self.thruster_direction != other.thruster_direction:
            return False
        if self.buoyancy_direction != other.buoyancy_direction:
            return False
        if self.buoyancy_setpoint != other.buoyancy_setpoint:
            return False
        if self.buoyancy_now_depth != other.buoyancy_now_depth:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def task_name(self):
        """Message field 'task_name'."""
        return self._task_name

    @task_name.setter
    def task_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'task_name' field must be of type 'str'"
        self._task_name = value

    @builtins.property
    def thruster_direction(self):
        """Message field 'thruster_direction'."""
        return self._thruster_direction

    @thruster_direction.setter
    def thruster_direction(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'thruster_direction' field must be of type 'str'"
        self._thruster_direction = value

    @builtins.property
    def buoyancy_direction(self):
        """Message field 'buoyancy_direction'."""
        return self._buoyancy_direction

    @buoyancy_direction.setter
    def buoyancy_direction(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'buoyancy_direction' field must be of type 'str'"
        self._buoyancy_direction = value

    @builtins.property
    def buoyancy_setpoint(self):
        """Message field 'buoyancy_setpoint'."""
        return self._buoyancy_setpoint

    @buoyancy_setpoint.setter
    def buoyancy_setpoint(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'buoyancy_setpoint' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'buoyancy_setpoint' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._buoyancy_setpoint = value

    @builtins.property
    def buoyancy_now_depth(self):
        """Message field 'buoyancy_now_depth'."""
        return self._buoyancy_now_depth

    @buoyancy_now_depth.setter
    def buoyancy_now_depth(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'buoyancy_now_depth' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'buoyancy_now_depth' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._buoyancy_now_depth = value
