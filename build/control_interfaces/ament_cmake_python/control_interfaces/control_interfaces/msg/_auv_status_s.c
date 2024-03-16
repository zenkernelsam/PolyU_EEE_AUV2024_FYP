// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from control_interfaces:msg/AUVStatus.idl
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
#include "control_interfaces/msg/detail/auv_status__struct.h"
#include "control_interfaces/msg/detail/auv_status__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool control_interfaces__msg__auv_status__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[45];
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
    assert(strncmp("control_interfaces.msg._auv_status.AUVStatus", full_classname_dest, 44) == 0);
  }
  control_interfaces__msg__AUVStatus * ros_message = _ros_message;
  {  // task_name
    PyObject * field = PyObject_GetAttrString(_pymsg, "task_name");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->task_name, PyBytes_AS_STRING(encoded_field));
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
  {  // buoyancy_setpoint
    PyObject * field = PyObject_GetAttrString(_pymsg, "buoyancy_setpoint");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->buoyancy_setpoint = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // buoyancy_now_depth
    PyObject * field = PyObject_GetAttrString(_pymsg, "buoyancy_now_depth");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->buoyancy_now_depth = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * control_interfaces__msg__auv_status__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of AUVStatus */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("control_interfaces.msg._auv_status");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "AUVStatus");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  control_interfaces__msg__AUVStatus * ros_message = (control_interfaces__msg__AUVStatus *)raw_ros_message;
  {  // task_name
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->task_name.data,
      strlen(ros_message->task_name.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "task_name", field);
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
  {  // buoyancy_setpoint
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->buoyancy_setpoint);
    {
      int rc = PyObject_SetAttrString(_pymessage, "buoyancy_setpoint", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // buoyancy_now_depth
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->buoyancy_now_depth);
    {
      int rc = PyObject_SetAttrString(_pymessage, "buoyancy_now_depth", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
