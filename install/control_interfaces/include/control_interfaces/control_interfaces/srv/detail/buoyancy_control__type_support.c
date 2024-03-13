// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from control_interfaces:srv/BuoyancyControl.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "control_interfaces/srv/detail/buoyancy_control__rosidl_typesupport_introspection_c.h"
#include "control_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "control_interfaces/srv/detail/buoyancy_control__functions.h"
#include "control_interfaces/srv/detail/buoyancy_control__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void control_interfaces__srv__BuoyancyControl_Request__rosidl_typesupport_introspection_c__BuoyancyControl_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  control_interfaces__srv__BuoyancyControl_Request__init(message_memory);
}

void control_interfaces__srv__BuoyancyControl_Request__rosidl_typesupport_introspection_c__BuoyancyControl_Request_fini_function(void * message_memory)
{
  control_interfaces__srv__BuoyancyControl_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember control_interfaces__srv__BuoyancyControl_Request__rosidl_typesupport_introspection_c__BuoyancyControl_Request_message_member_array[2] = {
  {
    "modify_depth",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(control_interfaces__srv__BuoyancyControl_Request, modify_depth),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "new_depth",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(control_interfaces__srv__BuoyancyControl_Request, new_depth),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers control_interfaces__srv__BuoyancyControl_Request__rosidl_typesupport_introspection_c__BuoyancyControl_Request_message_members = {
  "control_interfaces__srv",  // message namespace
  "BuoyancyControl_Request",  // message name
  2,  // number of fields
  sizeof(control_interfaces__srv__BuoyancyControl_Request),
  control_interfaces__srv__BuoyancyControl_Request__rosidl_typesupport_introspection_c__BuoyancyControl_Request_message_member_array,  // message members
  control_interfaces__srv__BuoyancyControl_Request__rosidl_typesupport_introspection_c__BuoyancyControl_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  control_interfaces__srv__BuoyancyControl_Request__rosidl_typesupport_introspection_c__BuoyancyControl_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t control_interfaces__srv__BuoyancyControl_Request__rosidl_typesupport_introspection_c__BuoyancyControl_Request_message_type_support_handle = {
  0,
  &control_interfaces__srv__BuoyancyControl_Request__rosidl_typesupport_introspection_c__BuoyancyControl_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_control_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, control_interfaces, srv, BuoyancyControl_Request)() {
  if (!control_interfaces__srv__BuoyancyControl_Request__rosidl_typesupport_introspection_c__BuoyancyControl_Request_message_type_support_handle.typesupport_identifier) {
    control_interfaces__srv__BuoyancyControl_Request__rosidl_typesupport_introspection_c__BuoyancyControl_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &control_interfaces__srv__BuoyancyControl_Request__rosidl_typesupport_introspection_c__BuoyancyControl_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "control_interfaces/srv/detail/buoyancy_control__rosidl_typesupport_introspection_c.h"
// already included above
// #include "control_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "control_interfaces/srv/detail/buoyancy_control__functions.h"
// already included above
// #include "control_interfaces/srv/detail/buoyancy_control__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void control_interfaces__srv__BuoyancyControl_Response__rosidl_typesupport_introspection_c__BuoyancyControl_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  control_interfaces__srv__BuoyancyControl_Response__init(message_memory);
}

void control_interfaces__srv__BuoyancyControl_Response__rosidl_typesupport_introspection_c__BuoyancyControl_Response_fini_function(void * message_memory)
{
  control_interfaces__srv__BuoyancyControl_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember control_interfaces__srv__BuoyancyControl_Response__rosidl_typesupport_introspection_c__BuoyancyControl_Response_message_member_array[2] = {
  {
    "is_succeeded",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(control_interfaces__srv__BuoyancyControl_Response, is_succeeded),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "now_depth",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(control_interfaces__srv__BuoyancyControl_Response, now_depth),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers control_interfaces__srv__BuoyancyControl_Response__rosidl_typesupport_introspection_c__BuoyancyControl_Response_message_members = {
  "control_interfaces__srv",  // message namespace
  "BuoyancyControl_Response",  // message name
  2,  // number of fields
  sizeof(control_interfaces__srv__BuoyancyControl_Response),
  control_interfaces__srv__BuoyancyControl_Response__rosidl_typesupport_introspection_c__BuoyancyControl_Response_message_member_array,  // message members
  control_interfaces__srv__BuoyancyControl_Response__rosidl_typesupport_introspection_c__BuoyancyControl_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  control_interfaces__srv__BuoyancyControl_Response__rosidl_typesupport_introspection_c__BuoyancyControl_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t control_interfaces__srv__BuoyancyControl_Response__rosidl_typesupport_introspection_c__BuoyancyControl_Response_message_type_support_handle = {
  0,
  &control_interfaces__srv__BuoyancyControl_Response__rosidl_typesupport_introspection_c__BuoyancyControl_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_control_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, control_interfaces, srv, BuoyancyControl_Response)() {
  if (!control_interfaces__srv__BuoyancyControl_Response__rosidl_typesupport_introspection_c__BuoyancyControl_Response_message_type_support_handle.typesupport_identifier) {
    control_interfaces__srv__BuoyancyControl_Response__rosidl_typesupport_introspection_c__BuoyancyControl_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &control_interfaces__srv__BuoyancyControl_Response__rosidl_typesupport_introspection_c__BuoyancyControl_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "control_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "control_interfaces/srv/detail/buoyancy_control__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers control_interfaces__srv__detail__buoyancy_control__rosidl_typesupport_introspection_c__BuoyancyControl_service_members = {
  "control_interfaces__srv",  // service namespace
  "BuoyancyControl",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // control_interfaces__srv__detail__buoyancy_control__rosidl_typesupport_introspection_c__BuoyancyControl_Request_message_type_support_handle,
  NULL  // response message
  // control_interfaces__srv__detail__buoyancy_control__rosidl_typesupport_introspection_c__BuoyancyControl_Response_message_type_support_handle
};

static rosidl_service_type_support_t control_interfaces__srv__detail__buoyancy_control__rosidl_typesupport_introspection_c__BuoyancyControl_service_type_support_handle = {
  0,
  &control_interfaces__srv__detail__buoyancy_control__rosidl_typesupport_introspection_c__BuoyancyControl_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, control_interfaces, srv, BuoyancyControl_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, control_interfaces, srv, BuoyancyControl_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_control_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, control_interfaces, srv, BuoyancyControl)() {
  if (!control_interfaces__srv__detail__buoyancy_control__rosidl_typesupport_introspection_c__BuoyancyControl_service_type_support_handle.typesupport_identifier) {
    control_interfaces__srv__detail__buoyancy_control__rosidl_typesupport_introspection_c__BuoyancyControl_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)control_interfaces__srv__detail__buoyancy_control__rosidl_typesupport_introspection_c__BuoyancyControl_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, control_interfaces, srv, BuoyancyControl_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, control_interfaces, srv, BuoyancyControl_Response)()->data;
  }

  return &control_interfaces__srv__detail__buoyancy_control__rosidl_typesupport_introspection_c__BuoyancyControl_service_type_support_handle;
}
