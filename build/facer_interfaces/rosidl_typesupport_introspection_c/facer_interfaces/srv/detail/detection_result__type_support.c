// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from facer_interfaces:srv/DetectionResult.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "facer_interfaces/srv/detail/detection_result__rosidl_typesupport_introspection_c.h"
#include "facer_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "facer_interfaces/srv/detail/detection_result__functions.h"
#include "facer_interfaces/srv/detail/detection_result__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void facer_interfaces__srv__DetectionResult_Request__rosidl_typesupport_introspection_c__DetectionResult_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  facer_interfaces__srv__DetectionResult_Request__init(message_memory);
}

void facer_interfaces__srv__DetectionResult_Request__rosidl_typesupport_introspection_c__DetectionResult_Request_fini_function(void * message_memory)
{
  facer_interfaces__srv__DetectionResult_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember facer_interfaces__srv__DetectionResult_Request__rosidl_typesupport_introspection_c__DetectionResult_Request_message_member_array[1] = {
  {
    "apply_result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(facer_interfaces__srv__DetectionResult_Request, apply_result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers facer_interfaces__srv__DetectionResult_Request__rosidl_typesupport_introspection_c__DetectionResult_Request_message_members = {
  "facer_interfaces__srv",  // message namespace
  "DetectionResult_Request",  // message name
  1,  // number of fields
  sizeof(facer_interfaces__srv__DetectionResult_Request),
  facer_interfaces__srv__DetectionResult_Request__rosidl_typesupport_introspection_c__DetectionResult_Request_message_member_array,  // message members
  facer_interfaces__srv__DetectionResult_Request__rosidl_typesupport_introspection_c__DetectionResult_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  facer_interfaces__srv__DetectionResult_Request__rosidl_typesupport_introspection_c__DetectionResult_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t facer_interfaces__srv__DetectionResult_Request__rosidl_typesupport_introspection_c__DetectionResult_Request_message_type_support_handle = {
  0,
  &facer_interfaces__srv__DetectionResult_Request__rosidl_typesupport_introspection_c__DetectionResult_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_facer_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, facer_interfaces, srv, DetectionResult_Request)() {
  if (!facer_interfaces__srv__DetectionResult_Request__rosidl_typesupport_introspection_c__DetectionResult_Request_message_type_support_handle.typesupport_identifier) {
    facer_interfaces__srv__DetectionResult_Request__rosidl_typesupport_introspection_c__DetectionResult_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &facer_interfaces__srv__DetectionResult_Request__rosidl_typesupport_introspection_c__DetectionResult_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "facer_interfaces/srv/detail/detection_result__rosidl_typesupport_introspection_c.h"
// already included above
// #include "facer_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "facer_interfaces/srv/detail/detection_result__functions.h"
// already included above
// #include "facer_interfaces/srv/detail/detection_result__struct.h"


// Include directives for member types
// Member `get_result`
// Member `buoyancy_direction`
// Member `thruster_direction`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void facer_interfaces__srv__DetectionResult_Response__rosidl_typesupport_introspection_c__DetectionResult_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  facer_interfaces__srv__DetectionResult_Response__init(message_memory);
}

void facer_interfaces__srv__DetectionResult_Response__rosidl_typesupport_introspection_c__DetectionResult_Response_fini_function(void * message_memory)
{
  facer_interfaces__srv__DetectionResult_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember facer_interfaces__srv__DetectionResult_Response__rosidl_typesupport_introspection_c__DetectionResult_Response_message_member_array[6] = {
  {
    "get_result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(facer_interfaces__srv__DetectionResult_Response, get_result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "is_finished",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(facer_interfaces__srv__DetectionResult_Response, is_finished),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "buoyancy_direction",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(facer_interfaces__srv__DetectionResult_Response, buoyancy_direction),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "thruster_direction",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(facer_interfaces__srv__DetectionResult_Response, thruster_direction),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(facer_interfaces__srv__DetectionResult_Response, time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "angle",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(facer_interfaces__srv__DetectionResult_Response, angle),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers facer_interfaces__srv__DetectionResult_Response__rosidl_typesupport_introspection_c__DetectionResult_Response_message_members = {
  "facer_interfaces__srv",  // message namespace
  "DetectionResult_Response",  // message name
  6,  // number of fields
  sizeof(facer_interfaces__srv__DetectionResult_Response),
  facer_interfaces__srv__DetectionResult_Response__rosidl_typesupport_introspection_c__DetectionResult_Response_message_member_array,  // message members
  facer_interfaces__srv__DetectionResult_Response__rosidl_typesupport_introspection_c__DetectionResult_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  facer_interfaces__srv__DetectionResult_Response__rosidl_typesupport_introspection_c__DetectionResult_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t facer_interfaces__srv__DetectionResult_Response__rosidl_typesupport_introspection_c__DetectionResult_Response_message_type_support_handle = {
  0,
  &facer_interfaces__srv__DetectionResult_Response__rosidl_typesupport_introspection_c__DetectionResult_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_facer_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, facer_interfaces, srv, DetectionResult_Response)() {
  if (!facer_interfaces__srv__DetectionResult_Response__rosidl_typesupport_introspection_c__DetectionResult_Response_message_type_support_handle.typesupport_identifier) {
    facer_interfaces__srv__DetectionResult_Response__rosidl_typesupport_introspection_c__DetectionResult_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &facer_interfaces__srv__DetectionResult_Response__rosidl_typesupport_introspection_c__DetectionResult_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "facer_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "facer_interfaces/srv/detail/detection_result__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers facer_interfaces__srv__detail__detection_result__rosidl_typesupport_introspection_c__DetectionResult_service_members = {
  "facer_interfaces__srv",  // service namespace
  "DetectionResult",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // facer_interfaces__srv__detail__detection_result__rosidl_typesupport_introspection_c__DetectionResult_Request_message_type_support_handle,
  NULL  // response message
  // facer_interfaces__srv__detail__detection_result__rosidl_typesupport_introspection_c__DetectionResult_Response_message_type_support_handle
};

static rosidl_service_type_support_t facer_interfaces__srv__detail__detection_result__rosidl_typesupport_introspection_c__DetectionResult_service_type_support_handle = {
  0,
  &facer_interfaces__srv__detail__detection_result__rosidl_typesupport_introspection_c__DetectionResult_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, facer_interfaces, srv, DetectionResult_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, facer_interfaces, srv, DetectionResult_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_facer_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, facer_interfaces, srv, DetectionResult)() {
  if (!facer_interfaces__srv__detail__detection_result__rosidl_typesupport_introspection_c__DetectionResult_service_type_support_handle.typesupport_identifier) {
    facer_interfaces__srv__detail__detection_result__rosidl_typesupport_introspection_c__DetectionResult_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)facer_interfaces__srv__detail__detection_result__rosidl_typesupport_introspection_c__DetectionResult_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, facer_interfaces, srv, DetectionResult_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, facer_interfaces, srv, DetectionResult_Response)()->data;
  }

  return &facer_interfaces__srv__detail__detection_result__rosidl_typesupport_introspection_c__DetectionResult_service_type_support_handle;
}
