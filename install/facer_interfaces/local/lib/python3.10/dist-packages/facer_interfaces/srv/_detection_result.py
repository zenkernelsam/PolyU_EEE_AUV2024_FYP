# generated from rosidl_generator_py/resource/_idl.py.em
# with input from facer_interfaces:srv/DetectionResult.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_DetectionResult_Request(type):
    """Metaclass of message 'DetectionResult_Request'."""

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
            module = import_type_support('facer_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'facer_interfaces.srv.DetectionResult_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__detection_result__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__detection_result__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__detection_result__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__detection_result__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__detection_result__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class DetectionResult_Request(metaclass=Metaclass_DetectionResult_Request):
    """Message class 'DetectionResult_Request'."""

    __slots__ = [
        '_apply_result',
    ]

    _fields_and_field_types = {
        'apply_result': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.apply_result = kwargs.get('apply_result', bool())

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
        if self.apply_result != other.apply_result:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def apply_result(self):
        """Message field 'apply_result'."""
        return self._apply_result

    @apply_result.setter
    def apply_result(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'apply_result' field must be of type 'bool'"
        self._apply_result = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_DetectionResult_Response(type):
    """Metaclass of message 'DetectionResult_Response'."""

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
            module = import_type_support('facer_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'facer_interfaces.srv.DetectionResult_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__detection_result__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__detection_result__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__detection_result__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__detection_result__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__detection_result__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class DetectionResult_Response(metaclass=Metaclass_DetectionResult_Response):
    """Message class 'DetectionResult_Response'."""

    __slots__ = [
        '_get_result',
        '_is_finished',
        '_buoyancy_direction',
        '_thruster_direction',
        '_time',
        '_angle',
    ]

    _fields_and_field_types = {
        'get_result': 'string',
        'is_finished': 'boolean',
        'buoyancy_direction': 'string',
        'thruster_direction': 'string',
        'time': 'uint8',
        'angle': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.get_result = kwargs.get('get_result', str())
        self.is_finished = kwargs.get('is_finished', bool())
        self.buoyancy_direction = kwargs.get('buoyancy_direction', str())
        self.thruster_direction = kwargs.get('thruster_direction', str())
        self.time = kwargs.get('time', int())
        self.angle = kwargs.get('angle', int())

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
        if self.get_result != other.get_result:
            return False
        if self.is_finished != other.is_finished:
            return False
        if self.buoyancy_direction != other.buoyancy_direction:
            return False
        if self.thruster_direction != other.thruster_direction:
            return False
        if self.time != other.time:
            return False
        if self.angle != other.angle:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def get_result(self):
        """Message field 'get_result'."""
        return self._get_result

    @get_result.setter
    def get_result(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'get_result' field must be of type 'str'"
        self._get_result = value

    @builtins.property
    def is_finished(self):
        """Message field 'is_finished'."""
        return self._is_finished

    @is_finished.setter
    def is_finished(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_finished' field must be of type 'bool'"
        self._is_finished = value

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
            assert value >= 0 and value < 256, \
                "The 'time' field must be an unsigned integer in [0, 255]"
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
            assert value >= 0 and value < 256, \
                "The 'angle' field must be an unsigned integer in [0, 255]"
        self._angle = value


class Metaclass_DetectionResult(type):
    """Metaclass of service 'DetectionResult'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('facer_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'facer_interfaces.srv.DetectionResult')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__detection_result

            from facer_interfaces.srv import _detection_result
            if _detection_result.Metaclass_DetectionResult_Request._TYPE_SUPPORT is None:
                _detection_result.Metaclass_DetectionResult_Request.__import_type_support__()
            if _detection_result.Metaclass_DetectionResult_Response._TYPE_SUPPORT is None:
                _detection_result.Metaclass_DetectionResult_Response.__import_type_support__()


class DetectionResult(metaclass=Metaclass_DetectionResult):
    from facer_interfaces.srv._detection_result import DetectionResult_Request as Request
    from facer_interfaces.srv._detection_result import DetectionResult_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
