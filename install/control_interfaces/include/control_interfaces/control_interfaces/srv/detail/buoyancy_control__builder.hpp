// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from control_interfaces:srv/BuoyancyControl.idl
// generated code does not contain a copyright notice

#ifndef CONTROL_INTERFACES__SRV__DETAIL__BUOYANCY_CONTROL__BUILDER_HPP_
#define CONTROL_INTERFACES__SRV__DETAIL__BUOYANCY_CONTROL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "control_interfaces/srv/detail/buoyancy_control__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace control_interfaces
{

namespace srv
{

namespace builder
{

class Init_BuoyancyControl_Request_new_depth
{
public:
  explicit Init_BuoyancyControl_Request_new_depth(::control_interfaces::srv::BuoyancyControl_Request & msg)
  : msg_(msg)
  {}
  ::control_interfaces::srv::BuoyancyControl_Request new_depth(::control_interfaces::srv::BuoyancyControl_Request::_new_depth_type arg)
  {
    msg_.new_depth = std::move(arg);
    return std::move(msg_);
  }

private:
  ::control_interfaces::srv::BuoyancyControl_Request msg_;
};

class Init_BuoyancyControl_Request_modify_depth
{
public:
  Init_BuoyancyControl_Request_modify_depth()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BuoyancyControl_Request_new_depth modify_depth(::control_interfaces::srv::BuoyancyControl_Request::_modify_depth_type arg)
  {
    msg_.modify_depth = std::move(arg);
    return Init_BuoyancyControl_Request_new_depth(msg_);
  }

private:
  ::control_interfaces::srv::BuoyancyControl_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::control_interfaces::srv::BuoyancyControl_Request>()
{
  return control_interfaces::srv::builder::Init_BuoyancyControl_Request_modify_depth();
}

}  // namespace control_interfaces


namespace control_interfaces
{

namespace srv
{

namespace builder
{

class Init_BuoyancyControl_Response_now_depth
{
public:
  explicit Init_BuoyancyControl_Response_now_depth(::control_interfaces::srv::BuoyancyControl_Response & msg)
  : msg_(msg)
  {}
  ::control_interfaces::srv::BuoyancyControl_Response now_depth(::control_interfaces::srv::BuoyancyControl_Response::_now_depth_type arg)
  {
    msg_.now_depth = std::move(arg);
    return std::move(msg_);
  }

private:
  ::control_interfaces::srv::BuoyancyControl_Response msg_;
};

class Init_BuoyancyControl_Response_is_succeeded
{
public:
  Init_BuoyancyControl_Response_is_succeeded()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BuoyancyControl_Response_now_depth is_succeeded(::control_interfaces::srv::BuoyancyControl_Response::_is_succeeded_type arg)
  {
    msg_.is_succeeded = std::move(arg);
    return Init_BuoyancyControl_Response_now_depth(msg_);
  }

private:
  ::control_interfaces::srv::BuoyancyControl_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::control_interfaces::srv::BuoyancyControl_Response>()
{
  return control_interfaces::srv::builder::Init_BuoyancyControl_Response_is_succeeded();
}

}  // namespace control_interfaces

#endif  // CONTROL_INTERFACES__SRV__DETAIL__BUOYANCY_CONTROL__BUILDER_HPP_
