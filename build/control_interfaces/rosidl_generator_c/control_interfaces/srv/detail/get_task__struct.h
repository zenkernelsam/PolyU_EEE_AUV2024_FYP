// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from control_interfaces:srv/GetTask.idl
// generated code does not contain a copyright notice

#ifndef CONTROL_INTERFACES__SRV__DETAIL__GET_TASK__STRUCT_H_
#define CONTROL_INTERFACES__SRV__DETAIL__GET_TASK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/GetTask in the package control_interfaces.
typedef struct control_interfaces__srv__GetTask_Request
{
  bool apply_result;
} control_interfaces__srv__GetTask_Request;

// Struct for a sequence of control_interfaces__srv__GetTask_Request.
typedef struct control_interfaces__srv__GetTask_Request__Sequence
{
  control_interfaces__srv__GetTask_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} control_interfaces__srv__GetTask_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'task_name'
// Member 'buoyancy_direction'
// Member 'thruster_direction'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/GetTask in the package control_interfaces.
typedef struct control_interfaces__srv__GetTask_Response
{
  rosidl_runtime_c__String task_name;
  bool is_finished;
  rosidl_runtime_c__String buoyancy_direction;
  rosidl_runtime_c__String thruster_direction;
  uint8_t time;
  uint8_t angle;
} control_interfaces__srv__GetTask_Response;

// Struct for a sequence of control_interfaces__srv__GetTask_Response.
typedef struct control_interfaces__srv__GetTask_Response__Sequence
{
  control_interfaces__srv__GetTask_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} control_interfaces__srv__GetTask_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CONTROL_INTERFACES__SRV__DETAIL__GET_TASK__STRUCT_H_
