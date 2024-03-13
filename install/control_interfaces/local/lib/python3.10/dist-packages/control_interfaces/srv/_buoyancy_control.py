# generated from rosidl_generator_py/resource/_idl.py.em
# with input from control_interfaces:srv/BuoyancyControl.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_BuoyancyControl_Request(type):
    """Metaclass of message 'BuoyancyControl_Request'."""

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
                'control_interfaces.srv.BuoyancyControl_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__buoyancy_control__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__buoyancy_control__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__buoyancy_control__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__buoyancy_control__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__buoyancy_control__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class BuoyancyControl_Request(metaclass=Metaclass_BuoyancyControl_Request):
    """Message class 'BuoyancyControl_Request'."""

    __slots__ = [
        '_modify_depth',
        '_new_depth',
    ]

    _fields_and_field_types = {
        'modify_depth': 'boolean',
        'new_depth': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.modify_depth = kwargs.get('modify_depth', bool())
        self.new_depth = kwargs.get('new_depth', float())

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
        if self.modify_depth != other.modify_depth:
            return False
        if self.new_depth != other.new_depth:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def modify_depth(self):
        """Message field 'modify_depth'."""
        return self._modify_depth

    @modify_depth.setter
    def modify_depth(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'modify_depth' field must be of type 'bool'"
        self._modify_depth = value

    @builtins.property
    def new_depth(self):
        """Message field 'new_depth'."""
        return self._new_depth

    @new_depth.setter
    def new_depth(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'new_depth' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'new_depth' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._new_depth = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import math

# already imported above
# import rosidl_parser.definition


class Metaclass_BuoyancyControl_Response(type):
    """Metaclass of message 'BuoyancyControl_Response'."""

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
                'control_interfaces.srv.BuoyancyControl_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__buoyancy_control__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__buoyancy_control__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__buoyancy_control__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__buoyancy_control__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__buoyancy_control__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class BuoyancyControl_Response(metaclass=Metaclass_BuoyancyControl_Response):
    """Message class 'BuoyancyControl_Response'."""

    __slots__ = [
        '_is_succeeded',
        '_now_depth',
    ]

    _fields_and_field_types = {
        'is_succeeded': 'boolean',
        'now_depth': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.is_succeeded = kwargs.get('is_succeeded', bool())
        self.now_depth = kwargs.get('now_depth', float())

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
        if self.is_succeeded != other.is_succeeded:
            return False
        if self.now_depth != other.now_depth:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def is_succeeded(self):
        """Message field 'is_succeeded'."""
        return self._is_succeeded

    @is_succeeded.setter
    def is_succeeded(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_succeeded' field must be of type 'bool'"
        self._is_succeeded = value

    @builtins.property
    def now_depth(self):
        """Message field 'now_depth'."""
        return self._now_depth

    @now_depth.setter
    def now_depth(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'now_depth' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'now_depth' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._now_depth = value


class Metaclass_BuoyancyControl(type):
    """Metaclass of service 'BuoyancyControl'."""

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
                'control_interfaces.srv.BuoyancyControl')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__buoyancy_control

            from control_interfaces.srv import _buoyancy_control
            if _buoyancy_control.Metaclass_BuoyancyControl_Request._TYPE_SUPPORT is None:
                _buoyancy_control.Metaclass_BuoyancyControl_Request.__import_type_support__()
            if _buoyancy_control.Metaclass_BuoyancyControl_Response._TYPE_SUPPORT is None:
                _buoyancy_control.Metaclass_BuoyancyControl_Response.__import_type_support__()


class BuoyancyControl(metaclass=Metaclass_BuoyancyControl):
    from control_interfaces.srv._buoyancy_control import BuoyancyControl_Request as Request
    from control_interfaces.srv._buoyancy_control import BuoyancyControl_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
