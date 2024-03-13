# generated from rosidl_generator_py/resource/_idl.py.em
# with input from control_interfaces:srv/GetCommand.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GetCommand_Request(type):
    """Metaclass of message 'GetCommand_Request'."""

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
                'control_interfaces.srv.GetCommand_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__get_command__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__get_command__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__get_command__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__get_command__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__get_command__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GetCommand_Request(metaclass=Metaclass_GetCommand_Request):
    """Message class 'GetCommand_Request'."""

    __slots__ = [
        '_get_command',
    ]

    _fields_and_field_types = {
        'get_command': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.get_command = kwargs.get('get_command', bool())

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
        if self.get_command != other.get_command:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def get_command(self):
        """Message field 'get_command'."""
        return self._get_command

    @get_command.setter
    def get_command(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'get_command' field must be of type 'bool'"
        self._get_command = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_GetCommand_Response(type):
    """Metaclass of message 'GetCommand_Response'."""

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
                'control_interfaces.srv.GetCommand_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__get_command__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__get_command__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__get_command__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__get_command__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__get_command__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GetCommand_Response(metaclass=Metaclass_GetCommand_Response):
    """Message class 'GetCommand_Response'."""

    __slots__ = [
        '_task_name',
        '_buoyancy_direction',
        '_thruster_direction',
        '_time',
        '_angle',
        '_count',
    ]

    _fields_and_field_types = {
        'task_name': 'string',
        'buoyancy_direction': 'string',
        'thruster_direction': 'string',
        'time': 'uint32',
        'angle': 'uint32',
        'count': 'uint32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.task_name = kwargs.get('task_name', str())
        self.buoyancy_direction = kwargs.get('buoyancy_direction', str())
        self.thruster_direction = kwargs.get('thruster_direction', str())
        self.time = kwargs.get('time', int())
        self.angle = kwargs.get('angle', int())
        self.count = kwargs.get('count', int())

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
        if self.buoyancy_direction != other.buoyancy_direction:
            return False
        if self.thruster_direction != other.thruster_direction:
            return False
        if self.time != other.time:
            return False
        if self.angle != other.angle:
            return False
        if self.count != other.count:
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
    def time(self):
        """Message field 'time'."""
        return self._time

    @time.setter
    def time(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'time' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'time' field must be an unsigned integer in [0, 4294967295]"
        self._time = value

    @builtins.property
    def angle(self):
        """Message field 'angle'."""
        return self._angle

    @angle.setter
    def angle(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'angle' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'angle' field must be an unsigned integer in [0, 4294967295]"
        self._angle = value

    @builtins.property
    def count(self):
        """Message field 'count'."""
        return self._count

    @count.setter
    def count(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'count' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'count' field must be an unsigned integer in [0, 4294967295]"
        self._count = value


class Metaclass_GetCommand(type):
    """Metaclass of service 'GetCommand'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('control_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'control_interfaces.srv.GetCommand')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__get_command

            from control_interfaces.srv import _get_command
            if _get_command.Metaclass_GetCommand_Request._TYPE_SUPPORT is None:
                _get_command.Metaclass_GetCommand_Request.__import_type_support__()
            if _get_command.Metaclass_GetCommand_Response._TYPE_SUPPORT is None:
                _get_command.Metaclass_GetCommand_Response.__import_type_support__()


class GetCommand(metaclass=Metaclass_GetCommand):
    from control_interfaces.srv._get_command import GetCommand_Request as Request
    from control_interfaces.srv._get_command import GetCommand_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
