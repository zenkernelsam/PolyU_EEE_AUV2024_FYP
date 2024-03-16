// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from control_interfaces:msg/AUVBuoyancy.idl
// generated code does not contain a copyright notice

#ifndef CONTROL_INTERFACES__MSG__DETAIL__AUV_BUOYANCY__BUILDER_HPP_
#define CONTROL_INTERFACES__MSG__DETAIL__AUV_BUOYANCY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "control_interfaces/msg/detail/auv_buoyancy__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace control_interfaces
{

namespace msg
{

namespace builder
{

class Init_AUVBuoyancy_now_depth
{
public:
  Init_AUVBuoyancy_now_depth()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::control_interfaces::msg::AUVBuoyancy now_depth(::control_interfaces::msg::AUVBuoyancy::_now_depth_type arg)
  {
    msg_.now_depth = std::move(arg);
    return std::move(msg_);
  }

private:
  ::control_interfaces::msg::AUVBuoyancy msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::control_interfaces::msg::AUVBuoyancy>()
{
  return control_interfaces::msg::builder::Init_AUVBuoyancy_now_depth();
}

}  // namespace control_interfaces

#endif  // CONTROL_INTERFACES__MSG__DETAIL__AUV_BUOYANCY__BUILDER_HPP_
