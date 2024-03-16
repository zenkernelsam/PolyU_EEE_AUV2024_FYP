// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from control_interfaces:msg/AUVStatus.idl
// generated code does not contain a copyright notice

#ifndef CONTROL_INTERFACES__MSG__DETAIL__AUV_STATUS__STRUCT_H_
#define CONTROL_INTERFACES__MSG__DETAIL__AUV_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'task_name'
// Member 'thruster_direction'
// Member 'buoyancy_direction'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/AUVStatus in the package control_interfaces.
typedef struct control_interfaces__msg__AUVStatus
{
  rosidl_runtime_c__String task_name;
  rosidl_runtime_c__String thruster_direction;
  rosidl_runtime_c__String buoyancy_direction;
  float buoyancy_setpoint;
  float buoyancy_now_depth;
} control_interfaces__msg__AUVStatus;

// Struct for a sequence of control_interfaces__msg__AUVStatus.
typedef struct control_interfaces__msg__AUVStatus__Sequence
{
  control_interfaces__msg__AUVStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} control_interfaces__msg__AUVStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CONTROL_INTERFACES__MSG__DETAIL__AUV_STATUS__STRUCT_H_
