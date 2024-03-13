// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from control_interfaces:srv/BuoyancyControl.idl
// generated code does not contain a copyright notice

#ifndef CONTROL_INTERFACES__SRV__DETAIL__BUOYANCY_CONTROL__STRUCT_H_
#define CONTROL_INTERFACES__SRV__DETAIL__BUOYANCY_CONTROL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/BuoyancyControl in the package control_interfaces.
typedef struct control_interfaces__srv__BuoyancyControl_Request
{
  bool modify_depth;
  float new_depth;
} control_interfaces__srv__BuoyancyControl_Request;

// Struct for a sequence of control_interfaces__srv__BuoyancyControl_Request.
typedef struct control_interfaces__srv__BuoyancyControl_Request__Sequence
{
  control_interfaces__srv__BuoyancyControl_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} control_interfaces__srv__BuoyancyControl_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/BuoyancyControl in the package control_interfaces.
typedef struct control_interfaces__srv__BuoyancyControl_Response
{
  bool is_succeeded;
  float now_depth;
} control_interfaces__srv__BuoyancyControl_Response;

// Struct for a sequence of control_interfaces__srv__BuoyancyControl_Response.
typedef struct control_interfaces__srv__BuoyancyControl_Response__Sequence
{
  control_interfaces__srv__BuoyancyControl_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} control_interfaces__srv__BuoyancyControl_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CONTROL_INTERFACES__SRV__DETAIL__BUOYANCY_CONTROL__STRUCT_H_
