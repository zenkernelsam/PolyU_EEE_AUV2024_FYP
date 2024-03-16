// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from control_interfaces:msg/AUVStatus.idl
// generated code does not contain a copyright notice

#ifndef CONTROL_INTERFACES__MSG__DETAIL__AUV_STATUS__BUILDER_HPP_
#define CONTROL_INTERFACES__MSG__DETAIL__AUV_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "control_interfaces/msg/detail/auv_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace control_interfaces
{

namespace msg
{

namespace builder
{

class Init_AUVStatus_buoyancy_now_depth
{
public:
  explicit Init_AUVStatus_buoyancy_now_depth(::control_interfaces::msg::AUVStatus & msg)
  : msg_(msg)
  {}
  ::control_interfaces::msg::AUVStatus buoyancy_now_depth(::control_interfaces::msg::AUVStatus::_buoyancy_now_depth_type arg)
  {
    msg_.buoyancy_now_depth = std::move(arg);
    return std::move(msg_);
  }

private:
  ::control_interfaces::msg::AUVStatus msg_;
};

class Init_AUVStatus_buoyancy_setpoint
{
public:
  explicit Init_AUVStatus_buoyancy_setpoint(::control_interfaces::msg::AUVStatus & msg)
  : msg_(msg)
  {}
  Init_AUVStatus_buoyancy_now_depth buoyancy_setpoint(::control_interfaces::msg::AUVStatus::_buoyancy_setpoint_type arg)
  {
    msg_.buoyancy_setpoint = std::move(arg);
    return Init_AUVStatus_buoyancy_now_depth(msg_);
  }

private:
  ::control_interfaces::msg::AUVStatus msg_;
};

class Init_AUVStatus_buoyancy_direction
{
public:
  explicit Init_AUVStatus_buoyancy_direction(::control_interfaces::msg::AUVStatus & msg)
  : msg_(msg)
  {}
  Init_AUVStatus_buoyancy_setpoint buoyancy_direction(::control_interfaces::msg::AUVStatus::_buoyancy_direction_type arg)
  {
    msg_.buoyancy_direction = std::move(arg);
    return Init_AUVStatus_buoyancy_setpoint(msg_);
  }

private:
  ::control_interfaces::msg::AUVStatus msg_;
};

class Init_AUVStatus_thruster_direction
{
public:
  explicit Init_AUVStatus_thruster_direction(::control_interfaces::msg::AUVStatus & msg)
  : msg_(msg)
  {}
  Init_AUVStatus_buoyancy_direction thruster_direction(::control_interfaces::msg::AUVStatus::_thruster_direction_type arg)
  {
    msg_.thruster_direction = std::move(arg);
    return Init_AUVStatus_buoyancy_direction(msg_);
  }

private:
  ::control_interfaces::msg::AUVStatus msg_;
};

class Init_AUVStatus_task_name
{
public:
  Init_AUVStatus_task_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AUVStatus_thruster_direction task_name(::control_interfaces::msg::AUVStatus::_task_name_type arg)
  {
    msg_.task_name = std::move(arg);
    return Init_AUVStatus_thruster_direction(msg_);
  }

private:
  ::control_interfaces::msg::AUVStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::control_interfaces::msg::AUVStatus>()
{
  return control_interfaces::msg::builder::Init_AUVStatus_task_name();
}

}  // namespace control_interfaces

#endif  // CONTROL_INTERFACES__MSG__DETAIL__AUV_STATUS__BUILDER_HPP_
