// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from control_interfaces:msg/AUVBuoyancy.idl
// generated code does not contain a copyright notice

#ifndef CONTROL_INTERFACES__MSG__DETAIL__AUV_BUOYANCY__STRUCT_H_
#define CONTROL_INTERFACES__MSG__DETAIL__AUV_BUOYANCY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/AUVBuoyancy in the package control_interfaces.
typedef struct control_interfaces__msg__AUVBuoyancy
{
  float now_depth;
} control_interfaces__msg__AUVBuoyancy;

// Struct for a sequence of control_interfaces__msg__AUVBuoyancy.
typedef struct control_interfaces__msg__AUVBuoyancy__Sequence
{
  control_interfaces__msg__AUVBuoyancy * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} control_interfaces__msg__AUVBuoyancy__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CONTROL_INTERFACES__MSG__DETAIL__AUV_BUOYANCY__STRUCT_H_
