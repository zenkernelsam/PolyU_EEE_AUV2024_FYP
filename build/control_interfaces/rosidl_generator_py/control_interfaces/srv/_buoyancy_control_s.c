// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from control_interfaces:srv/BuoyancyControl.idl
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
#include "control_interfaces/srv/detail/buoyancy_control__struct.h"
#include "control_interfaces/srv/detail/buoyancy_control__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool control_interfaces__srv__buoyancy_control__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[65];
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
    assert(strncmp("control_interfaces.srv._buoyancy_control.BuoyancyControl_Request", full_classname_dest, 64) == 0);
  }
  control_interfaces__srv__BuoyancyControl_Request * ros_message = _ros_message;
  {  // modify_depth
    PyObject * field = PyObject_GetAttrString(_pymsg, "modify_depth");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->modify_depth = (Py_True == field);
    Py_DECREF(field);
  }
  {  // new_depth
    PyObject * field = PyObject_GetAttrString(_pymsg, "new_depth");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->new_depth = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * control_interfaces__srv__buoyancy_control__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of BuoyancyControl_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("control_interfaces.srv._buoyancy_control");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "BuoyancyControl_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  control_interfaces__srv__BuoyancyControl_Request * ros_message = (control_interfaces__srv__BuoyancyControl_Request *)raw_ros_message;
  {  // modify_depth
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->modify_depth ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "modify_depth", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // new_depth
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->new_depth);
    {
      int rc = PyObject_SetAttrString(_pymessage, "new_depth", field);
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
// #include "control_interfaces/srv/detail/buoyancy_control__struct.h"
// already included above
// #include "control_interfaces/srv/detail/buoyancy_control__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool control_interfaces__srv__buoyancy_control__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[66];
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
    assert(strncmp("control_interfaces.srv._buoyancy_control.BuoyancyControl_Response", full_classname_dest, 65) == 0);
  }
  control_interfaces__srv__BuoyancyControl_Response * ros_message = _ros_message;
  {  // is_succeeded
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_succeeded");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->is_succeeded = (Py_True == field);
    Py_DECREF(field);
  }
  {  // now_depth
    PyObject * field = PyObject_GetAttrString(_pymsg, "now_depth");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->now_depth = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * control_interfaces__srv__buoyancy_control__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of BuoyancyControl_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("control_interfaces.srv._buoyancy_control");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "BuoyancyControl_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  control_interfaces__srv__BuoyancyControl_Response * ros_message = (control_interfaces__srv__BuoyancyControl_Response *)raw_ros_message;
  {  // is_succeeded
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->is_succeeded ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_succeeded", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // now_depth
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->now_depth);
    {
      int rc = PyObject_SetAttrString(_pymessage, "now_depth", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
