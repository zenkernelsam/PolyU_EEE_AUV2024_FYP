// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from facer_interfaces:srv/DetectionResult.idl
// generated code does not contain a copyright notice
#include "facer_interfaces/srv/detail/detection_result__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "facer_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "facer_interfaces/srv/detail/detection_result__struct.h"
#include "facer_interfaces/srv/detail/detection_result__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _DetectionResult_Request__ros_msg_type = facer_interfaces__srv__DetectionResult_Request;

static bool _DetectionResult_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _DetectionResult_Request__ros_msg_type * ros_message = static_cast<const _DetectionResult_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: apply_result
  {
    cdr << (ros_message->apply_result ? true : false);
  }

  return true;
}

static bool _DetectionResult_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _DetectionResult_Request__ros_msg_type * ros_message = static_cast<_DetectionResult_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: apply_result
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->apply_result = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_facer_interfaces
size_t get_serialized_size_facer_interfaces__srv__DetectionResult_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _DetectionResult_Request__ros_msg_type * ros_message = static_cast<const _DetectionResult_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name apply_result
  {
    size_t item_size = sizeof(ros_message->apply_result);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _DetectionResult_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_facer_interfaces__srv__DetectionResult_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_facer_interfaces
size_t max_serialized_size_facer_interfaces__srv__DetectionResult_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: apply_result
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = facer_interfaces__srv__DetectionResult_Request;
    is_plain =
      (
      offsetof(DataType, apply_result) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _DetectionResult_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_facer_interfaces__srv__DetectionResult_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_DetectionResult_Request = {
  "facer_interfaces::srv",
  "DetectionResult_Request",
  _DetectionResult_Request__cdr_serialize,
  _DetectionResult_Request__cdr_deserialize,
  _DetectionResult_Request__get_serialized_size,
  _DetectionResult_Request__max_serialized_size
};

static rosidl_message_type_support_t _DetectionResult_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_DetectionResult_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, facer_interfaces, srv, DetectionResult_Request)() {
  return &_DetectionResult_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "facer_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "facer_interfaces/srv/detail/detection_result__struct.h"
// already included above
// #include "facer_interfaces/srv/detail/detection_result__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // buoyancy_direction, get_result, thruster_direction
#include "rosidl_runtime_c/string_functions.h"  // buoyancy_direction, get_result, thruster_direction

// forward declare type support functions


using _DetectionResult_Response__ros_msg_type = facer_interfaces__srv__DetectionResult_Response;

static bool _DetectionResult_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _DetectionResult_Response__ros_msg_type * ros_message = static_cast<const _DetectionResult_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: get_result
  {
    const rosidl_runtime_c__String * str = &ros_message->get_result;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: is_finished
  {
    cdr << (ros_message->is_finished ? true : false);
  }

  // Field name: buoyancy_direction
  {
    const rosidl_runtime_c__String * str = &ros_message->buoyancy_direction;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: thruster_direction
  {
    const rosidl_runtime_c__String * str = &ros_message->thruster_direction;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: time
  {
    cdr << ros_message->time;
  }

  // Field name: angle
  {
    cdr << ros_message->angle;
  }

  return true;
}

static bool _DetectionResult_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _DetectionResult_Response__ros_msg_type * ros_message = static_cast<_DetectionResult_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: get_result
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->get_result.data) {
      rosidl_runtime_c__String__init(&ros_message->get_result);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->get_result,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'get_result'\n");
      return false;
    }
  }

  // Field name: is_finished
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->is_finished = tmp ? true : false;
  }

  // Field name: buoyancy_direction
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->buoyancy_direction.data) {
      rosidl_runtime_c__String__init(&ros_message->buoyancy_direction);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->buoyancy_direction,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'buoyancy_direction'\n");
      return false;
    }
  }

  // Field name: thruster_direction
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->thruster_direction.data) {
      rosidl_runtime_c__String__init(&ros_message->thruster_direction);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->thruster_direction,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'thruster_direction'\n");
      return false;
    }
  }

  // Field name: time
  {
    cdr >> ros_message->time;
  }

  // Field name: angle
  {
    cdr >> ros_message->angle;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_facer_interfaces
size_t get_serialized_size_facer_interfaces__srv__DetectionResult_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _DetectionResult_Response__ros_msg_type * ros_message = static_cast<const _DetectionResult_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name get_result
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->get_result.size + 1);
  // field.name is_finished
  {
    size_t item_size = sizeof(ros_message->is_finished);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name buoyancy_direction
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->buoyancy_direction.size + 1);
  // field.name thruster_direction
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->thruster_direction.size + 1);
  // field.name time
  {
    size_t item_size = sizeof(ros_message->time);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name angle
  {
    size_t item_size = sizeof(ros_message->angle);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _DetectionResult_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_facer_interfaces__srv__DetectionResult_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_facer_interfaces
size_t max_serialized_size_facer_interfaces__srv__DetectionResult_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: get_result
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: is_finished
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: buoyancy_direction
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: thruster_direction
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: time
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: angle
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = facer_interfaces__srv__DetectionResult_Response;
    is_plain =
      (
      offsetof(DataType, angle) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _DetectionResult_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_facer_interfaces__srv__DetectionResult_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_DetectionResult_Response = {
  "facer_interfaces::srv",
  "DetectionResult_Response",
  _DetectionResult_Response__cdr_serialize,
  _DetectionResult_Response__cdr_deserialize,
  _DetectionResult_Response__get_serialized_size,
  _DetectionResult_Response__max_serialized_size
};

static rosidl_message_type_support_t _DetectionResult_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_DetectionResult_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, facer_interfaces, srv, DetectionResult_Response)() {
  return &_DetectionResult_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "facer_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "facer_interfaces/srv/detection_result.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t DetectionResult__callbacks = {
  "facer_interfaces::srv",
  "DetectionResult",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, facer_interfaces, srv, DetectionResult_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, facer_interfaces, srv, DetectionResult_Response)(),
};

static rosidl_service_type_support_t DetectionResult__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &DetectionResult__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, facer_interfaces, srv, DetectionResult)() {
  return &DetectionResult__handle;
}

#if defined(__cplusplus)
}
#endif
