// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from control_interfaces:srv/GetCommand.idl
// generated code does not contain a copyright notice

#ifndef CONTROL_INTERFACES__SRV__DETAIL__GET_COMMAND__BUILDER_HPP_
#define CONTROL_INTERFACES__SRV__DETAIL__GET_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "control_interfaces/srv/detail/get_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace control_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetCommand_Request_get_command
{
public:
  Init_GetCommand_Request_get_command()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::control_interfaces::srv::GetCommand_Request get_command(::control_interfaces::srv::GetCommand_Request::_get_command_type arg)
  {
    msg_.get_command = std::move(arg);
    return std::move(msg_);
  }

private:
  ::control_interfaces::srv::GetCommand_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::control_interfaces::srv::GetCommand_Request>()
{
  return control_interfaces::srv::builder::Init_GetCommand_Request_get_command();
}

}  // namespace control_interfaces


namespace control_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetCommand_Response_count
{
public:
  explicit Init_GetCommand_Response_count(::control_interfaces::srv::GetCommand_Response & msg)
  : msg_(msg)
  {}
  ::control_interfaces::srv::GetCommand_Response count(::control_interfaces::srv::GetCommand_Response::_count_type arg)
  {
    msg_.count = std::move(arg);
    return std::move(msg_);
  }

private:
  ::control_interfaces::srv::GetCommand_Response msg_;
};

class Init_GetCommand_Response_angle
{
public:
  explicit Init_GetCommand_Response_angle(::control_interfaces::srv::GetCommand_Response & msg)
  : msg_(msg)
  {}
  Init_GetCommand_Response_count angle(::control_interfaces::srv::GetCommand_Response::_angle_type arg)
  {
    msg_.angle = std::move(arg);
    return Init_GetCommand_Response_count(msg_);
  }

private:
  ::control_interfaces::srv::GetCommand_Response msg_;
};

class Init_GetCommand_Response_time
{
public:
  explicit Init_GetCommand_Response_time(::control_interfaces::srv::GetCommand_Response & msg)
  : msg_(msg)
  {}
  Init_GetCommand_Response_angle time(::control_interfaces::srv::GetCommand_Response::_time_type arg)
  {
    msg_.time = std::move(arg);
    return Init_GetCommand_Response_angle(msg_);
  }

private:
  ::control_interfaces::srv::GetCommand_Response msg_;
};

class Init_GetCommand_Response_thruster_direction
{
public:
  explicit Init_GetCommand_Response_thruster_direction(::control_interfaces::srv::GetCommand_Response & msg)
  : msg_(msg)
  {}
  Init_GetCommand_Response_time thruster_direction(::control_interfaces::srv::GetCommand_Response::_thruster_direction_type arg)
  {
    msg_.thruster_direction = std::move(arg);
    return Init_GetCommand_Response_time(msg_);
  }

private:
  ::control_interfaces::srv::GetCommand_Response msg_;
};

class Init_GetCommand_Response_buoyancy_direction
{
public:
  explicit Init_GetCommand_Response_buoyancy_direction(::control_interfaces::srv::GetCommand_Response & msg)
  : msg_(msg)
  {}
  Init_GetCommand_Response_thruster_direction buoyancy_direction(::control_interfaces::srv::GetCommand_Response::_buoyancy_direction_type arg)
  {
    msg_.buoyancy_direction = std::move(arg);
    return Init_GetCommand_Response_thruster_direction(msg_);
  }

private:
  ::control_interfaces::srv::GetCommand_Response msg_;
};

class Init_GetCommand_Response_task_name
{
public:
  Init_GetCommand_Response_task_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetCommand_Response_buoyancy_direction task_name(::control_interfaces::srv::GetCommand_Response::_task_name_type arg)
  {
    msg_.task_name = std::move(arg);
    return Init_GetCommand_Response_buoyancy_direction(msg_);
  }

private:
  ::control_interfaces::srv::GetCommand_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::control_interfaces::srv::GetCommand_Response>()
{
  return control_interfaces::srv::builder::Init_GetCommand_Response_task_name();
}

}  // namespace control_interfaces

#endif  // CONTROL_INTERFACES__SRV__DETAIL__GET_COMMAND__BUILDER_HPP_
