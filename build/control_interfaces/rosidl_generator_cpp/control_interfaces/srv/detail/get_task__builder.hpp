// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from control_interfaces:srv/GetTask.idl
// generated code does not contain a copyright notice

#ifndef CONTROL_INTERFACES__SRV__DETAIL__GET_TASK__BUILDER_HPP_
#define CONTROL_INTERFACES__SRV__DETAIL__GET_TASK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "control_interfaces/srv/detail/get_task__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace control_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetTask_Request_apply_result
{
public:
  Init_GetTask_Request_apply_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::control_interfaces::srv::GetTask_Request apply_result(::control_interfaces::srv::GetTask_Request::_apply_result_type arg)
  {
    msg_.apply_result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::control_interfaces::srv::GetTask_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::control_interfaces::srv::GetTask_Request>()
{
  return control_interfaces::srv::builder::Init_GetTask_Request_apply_result();
}

}  // namespace control_interfaces


namespace control_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetTask_Response_angle
{
public:
  explicit Init_GetTask_Response_angle(::control_interfaces::srv::GetTask_Response & msg)
  : msg_(msg)
  {}
  ::control_interfaces::srv::GetTask_Response angle(::control_interfaces::srv::GetTask_Response::_angle_type arg)
  {
    msg_.angle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::control_interfaces::srv::GetTask_Response msg_;
};

class Init_GetTask_Response_time
{
public:
  explicit Init_GetTask_Response_time(::control_interfaces::srv::GetTask_Response & msg)
  : msg_(msg)
  {}
  Init_GetTask_Response_angle time(::control_interfaces::srv::GetTask_Response::_time_type arg)
  {
    msg_.time = std::move(arg);
    return Init_GetTask_Response_angle(msg_);
  }

private:
  ::control_interfaces::srv::GetTask_Response msg_;
};

class Init_GetTask_Response_thruster_direction
{
public:
  explicit Init_GetTask_Response_thruster_direction(::control_interfaces::srv::GetTask_Response & msg)
  : msg_(msg)
  {}
  Init_GetTask_Response_time thruster_direction(::control_interfaces::srv::GetTask_Response::_thruster_direction_type arg)
  {
    msg_.thruster_direction = std::move(arg);
    return Init_GetTask_Response_time(msg_);
  }

private:
  ::control_interfaces::srv::GetTask_Response msg_;
};

class Init_GetTask_Response_buoyancy_direction
{
public:
  explicit Init_GetTask_Response_buoyancy_direction(::control_interfaces::srv::GetTask_Response & msg)
  : msg_(msg)
  {}
  Init_GetTask_Response_thruster_direction buoyancy_direction(::control_interfaces::srv::GetTask_Response::_buoyancy_direction_type arg)
  {
    msg_.buoyancy_direction = std::move(arg);
    return Init_GetTask_Response_thruster_direction(msg_);
  }

private:
  ::control_interfaces::srv::GetTask_Response msg_;
};

class Init_GetTask_Response_is_finished
{
public:
  explicit Init_GetTask_Response_is_finished(::control_interfaces::srv::GetTask_Response & msg)
  : msg_(msg)
  {}
  Init_GetTask_Response_buoyancy_direction is_finished(::control_interfaces::srv::GetTask_Response::_is_finished_type arg)
  {
    msg_.is_finished = std::move(arg);
    return Init_GetTask_Response_buoyancy_direction(msg_);
  }

private:
  ::control_interfaces::srv::GetTask_Response msg_;
};

class Init_GetTask_Response_task_name
{
public:
  Init_GetTask_Response_task_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetTask_Response_is_finished task_name(::control_interfaces::srv::GetTask_Response::_task_name_type arg)
  {
    msg_.task_name = std::move(arg);
    return Init_GetTask_Response_is_finished(msg_);
  }

private:
  ::control_interfaces::srv::GetTask_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::control_interfaces::srv::GetTask_Response>()
{
  return control_interfaces::srv::builder::Init_GetTask_Response_task_name();
}

}  // namespace control_interfaces

#endif  // CONTROL_INTERFACES__SRV__DETAIL__GET_TASK__BUILDER_HPP_
