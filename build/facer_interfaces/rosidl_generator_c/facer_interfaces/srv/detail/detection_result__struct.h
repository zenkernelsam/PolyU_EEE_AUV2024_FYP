// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from facer_interfaces:srv/DetectionResult.idl
// generated code does not contain a copyright notice

#ifndef FACER_INTERFACES__SRV__DETAIL__DETECTION_RESULT__STRUCT_H_
#define FACER_INTERFACES__SRV__DETAIL__DETECTION_RESULT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/DetectionResult in the package facer_interfaces.
typedef struct facer_interfaces__srv__DetectionResult_Request
{
  /// 申请结果
  bool apply_result;
} facer_interfaces__srv__DetectionResult_Request;

// Struct for a sequence of facer_interfaces__srv__DetectionResult_Request.
typedef struct facer_interfaces__srv__DetectionResult_Request__Sequence
{
  facer_interfaces__srv__DetectionResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} facer_interfaces__srv__DetectionResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'get_result'
// Member 'buoyancy_direction'
// Member 'thruster_direction'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/DetectionResult in the package facer_interfaces.
typedef struct facer_interfaces__srv__DetectionResult_Response
{
  /// 获取结果
  rosidl_runtime_c__String get_result;
  bool is_finished;
  rosidl_runtime_c__String buoyancy_direction;
  rosidl_runtime_c__String thruster_direction;
  uint8_t time;
  uint8_t angle;
} facer_interfaces__srv__DetectionResult_Response;

// Struct for a sequence of facer_interfaces__srv__DetectionResult_Response.
typedef struct facer_interfaces__srv__DetectionResult_Response__Sequence
{
  facer_interfaces__srv__DetectionResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} facer_interfaces__srv__DetectionResult_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FACER_INTERFACES__SRV__DETAIL__DETECTION_RESULT__STRUCT_H_
