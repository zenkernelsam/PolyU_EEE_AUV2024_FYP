// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from facer_interfaces:srv/DetectionResult.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "facer_interfaces/srv/detail/detection_result__struct.h"
#include "facer_interfaces/srv/detail/detection_result__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool facer_interfaces__srv__detection_result__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[63];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("facer_interfaces.srv._detection_result.DetectionResult_Request", full_classname_dest, 62) == 0);
  }
  facer_interfaces__srv__DetectionResult_Request * ros_message = _ros_message;
  {  // apply_result
    PyObject * field = PyObject_GetAttrString(_pymsg, "apply_result");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->apply_result = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * facer_interfaces__srv__detection_result__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of DetectionResult_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("facer_interfaces.srv._detection_result");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "DetectionResult_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  facer_interfaces__srv__DetectionResult_Request * ros_message = (facer_interfaces__srv__DetectionResult_Request *)raw_ros_message;
  {  // apply_result
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->apply_result ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "apply_result", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "facer_interfaces/srv/detail/detection_result__struct.h"
// already included above
// #include "facer_interfaces/srv/detail/detection_result__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool facer_interfaces__srv__detection_result__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[64];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("facer_interfaces.srv._detection_result.DetectionResult_Response", full_classname_dest, 63) == 0);
  }
  facer_interfaces__srv__DetectionResult_Response * ros_message = _ros_message;
  {  // get_result
    PyObject * field = PyObject_GetAttrString(_pymsg, "get_result");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->get_result, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // is_finished
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_finished");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->is_finished = (Py_True == field);
    Py_DECREF(field);
  }
  {  // buoyancy_direction
    PyObject * field = PyObject_GetAttrString(_pymsg, "buoyancy_direction");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->buoyancy_direction, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // thruster_direction
    PyObject * field = PyObject_GetAttrString(_pymsg, "thruster_direction");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->thruster_direction, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // time
    PyObject * field = PyObject_GetAttrString(_pymsg, "time");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->time = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // angle
    PyObject * field = PyObject_GetAttrString(_pymsg, "angle");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->angle = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * facer_interfaces__srv__detection_result__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of DetectionResult_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("facer_interfaces.srv._detection_result");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "DetectionResult_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  facer_interfaces__srv__DetectionResult_Response * ros_message = (facer_interfaces__srv__DetectionResult_Response *)raw_ros_message;
  {  // get_result
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->get_result.data,
      strlen(ros_message->get_result.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "get_result", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // is_finished
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->is_finished ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_finished", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // buoyancy_direction
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->buoyancy_direction.data,
      strlen(ros_message->buoyancy_direction.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "buoyancy_direction", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // thruster_direction
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->thruster_direction.data,
      strlen(ros_message->thruster_direction.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "thruster_direction", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // time
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->time);
    {
      int rc = PyObject_SetAttrString(_pymessage, "time", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // angle
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->angle);
    {
      int rc = PyObject_SetAttrString(_pymessage, "angle", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
