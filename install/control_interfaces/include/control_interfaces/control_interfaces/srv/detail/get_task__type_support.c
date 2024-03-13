// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from control_interfaces:srv/GetTask.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "control_interfaces/srv/detail/get_task__rosidl_typesupport_introspection_c.h"
#include "control_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "control_interfaces/srv/detail/get_task__functions.h"
#include "control_interfaces/srv/detail/get_task__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void control_interfaces__srv__GetTask_Request__rosidl_typesupport_introspection_c__GetTask_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  control_interfaces__srv__GetTask_Request__init(message_memory);
}

void control_interfaces__srv__GetTask_Request__rosidl_typesupport_introspection_c__GetTask_Request_fini_function(void * message_memory)
{
  control_interfaces__srv__GetTask_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember control_interfaces__srv__GetTask_Request__rosidl_typesupport_introspection_c__GetTask_Request_message_member_array[1] = {
  {
    "apply_result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(control_interfaces__srv__GetTask_Request, apply_result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers control_interfaces__srv__GetTask_Request__rosidl_typesupport_introspection_c__GetTask_Request_message_members = {
  "control_interfaces__srv",  // message namespace
  "GetTask_Request",  // message name
  1,  // number of fields
  sizeof(control_interfaces__srv__GetTask_Request),
  control_interfaces__srv__GetTask_Request__rosidl_typesupport_introspection_c__GetTask_Request_message_member_array,  // message members
  control_interfaces__srv__GetTask_Request__rosidl_typesupport_introspection_c__GetTask_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  control_interfaces__srv__GetTask_Request__rosidl_typesupport_introspection_c__GetTask_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t control_interfaces__srv__GetTask_Request__rosidl_typesupport_introspection_c__GetTask_Request_message_type_support_handle = {
  0,
  &control_interfaces__srv__GetTask_Request__rosidl_typesupport_introspection_c__GetTask_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_control_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, control_interfaces, srv, GetTask_Request)() {
  if (!control_interfaces__srv__GetTask_Request__rosidl_typesupport_introspection_c__GetTask_Request_message_type_support_handle.typesupport_identifier) {
    control_interfaces__srv__GetTask_Request__rosidl_typesupport_introspection_c__GetTask_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &control_interfaces__srv__GetTask_Request__rosidl_typesupport_introspection_c__GetTask_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "control_interfaces/srv/detail/get_task__rosidl_typesupport_introspection_c.h"
// already included above
// #include "control_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "control_interfaces/srv/detail/get_task__functions.h"
// already included above
// #include "control_interfaces/srv/detail/get_task__struct.h"


// Include directives for member types
// Member `task_name`
// Member `buoyancy_direction`
// Member `thruster_direction`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void control_interfaces__srv__GetTask_Response__rosidl_typesupport_introspection_c__GetTask_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  control_interfaces__srv__GetTask_Response__init(message_memory);
}

void control_interfaces__srv__GetTask_Response__rosidl_typesupport_introspection_c__GetTask_Response_fini_function(void * message_memory)
{
  control_interfaces__srv__GetTask_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember control_interfaces__srv__GetTask_Response__rosidl_typesupport_introspection_c__GetTask_Response_message_member_array[6] = {
  {
    "task_name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(control_interfaces__srv__GetTask_Response, task_name),  // bytes offset in struct
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
    offsetof(control_interfaces__srv__GetTask_Response, is_finished),  // bytes offset in struct
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
    offsetof(control_interfaces__srv__GetTask_Response, buoyancy_direction),  // bytes offset in struct
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
    offsetof(control_interfaces__srv__GetTask_Response, thruster_direction),  // bytes offset in struct
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
    offsetof(control_interfaces__srv__GetTask_Response, time),  // bytes offset in struct
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
    offsetof(control_interfaces__srv__GetTask_Response, angle),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers control_interfaces__srv__GetTask_Response__rosidl_typesupport_introspection_c__GetTask_Response_message_members = {
  "control_interfaces__srv",  // message namespace
  "GetTask_Response",  // message name
  6,  // number of fields
  sizeof(control_interfaces__srv__GetTask_Response),
  control_interfaces__srv__GetTask_Response__rosidl_typesupport_introspection_c__GetTask_Response_message_member_array,  // message members
  control_interfaces__srv__GetTask_Response__rosidl_typesupport_introspection_c__GetTask_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  control_interfaces__srv__GetTask_Response__rosidl_typesupport_introspection_c__GetTask_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t control_interfaces__srv__GetTask_Response__rosidl_typesupport_introspection_c__GetTask_Response_message_type_support_handle = {
  0,
  &control_interfaces__srv__GetTask_Response__rosidl_typesupport_introspection_c__GetTask_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_control_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, control_interfaces, srv, GetTask_Response)() {
  if (!control_interfaces__srv__GetTask_Response__rosidl_typesupport_introspection_c__GetTask_Response_message_type_support_handle.typesupport_identifier) {
    control_interfaces__srv__GetTask_Response__rosidl_typesupport_introspection_c__GetTask_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &control_interfaces__srv__GetTask_Response__rosidl_typesupport_introspection_c__GetTask_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "control_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "control_interfaces/srv/detail/get_task__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers control_interfaces__srv__detail__get_task__rosidl_typesupport_introspection_c__GetTask_service_members = {
  "control_interfaces__srv",  // service namespace
  "GetTask",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // control_interfaces__srv__detail__get_task__rosidl_typesupport_introspection_c__GetTask_Request_message_type_support_handle,
  NULL  // response message
  // control_interfaces__srv__detail__get_task__rosidl_typesupport_introspection_c__GetTask_Response_message_type_support_handle
};

static rosidl_service_type_support_t control_interfaces__srv__detail__get_task__rosidl_typesupport_introspection_c__GetTask_service_type_support_handle = {
  0,
  &control_interfaces__srv__detail__get_task__rosidl_typesupport_introspection_c__GetTask_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, control_interfaces, srv, GetTask_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, control_interfaces, srv, GetTask_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_control_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, control_interfaces, srv, GetTask)() {
  if (!control_interfaces__srv__detail__get_task__rosidl_typesupport_introspection_c__GetTask_service_type_support_handle.typesupport_identifier) {
    control_interfaces__srv__detail__get_task__rosidl_typesupport_introspection_c__GetTask_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)control_interfaces__srv__detail__get_task__rosidl_typesupport_introspection_c__GetTask_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, control_interfaces, srv, GetTask_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, control_interfaces, srv, GetTask_Response)()->data;
  }

  return &control_interfaces__srv__detail__get_task__rosidl_typesupport_introspection_c__GetTask_service_type_support_handle;
}
