// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from control_interfaces:msg/AUVStatus.idl
// generated code does not contain a copyright notice

#ifndef CONTROL_INTERFACES__MSG__DETAIL__AUV_STATUS__TRAITS_HPP_
#define CONTROL_INTERFACES__MSG__DETAIL__AUV_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "control_interfaces/msg/detail/auv_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace control_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const AUVStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: task_name
  {
    out << "task_name: ";
    rosidl_generator_traits::value_to_yaml(msg.task_name, out);
    out << ", ";
  }

  // member: thruster_direction
  {
    out << "thruster_direction: ";
    rosidl_generator_traits::value_to_yaml(msg.thruster_direction, out);
    out << ", ";
  }

  // member: buoyancy_direction
  {
    out << "buoyancy_direction: ";
    rosidl_generator_traits::value_to_yaml(msg.buoyancy_direction, out);
    out << ", ";
  }

  // member: buoyancy_setpoint
  {
    out << "buoyancy_setpoint: ";
    rosidl_generator_traits::value_to_yaml(msg.buoyancy_setpoint, out);
    out << ", ";
  }

  // member: buoyancy_now_depth
  {
    out << "buoyancy_now_depth: ";
    rosidl_generator_traits::value_to_yaml(msg.buoyancy_now_depth, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AUVStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: task_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "task_name: ";
    rosidl_generator_traits::value_to_yaml(msg.task_name, out);
    out << "\n";
  }

  // member: thruster_direction
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "thruster_direction: ";
    rosidl_generator_traits::value_to_yaml(msg.thruster_direction, out);
    out << "\n";
  }

  // member: buoyancy_direction
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "buoyancy_direction: ";
    rosidl_generator_traits::value_to_yaml(msg.buoyancy_direction, out);
    out << "\n";
  }

  // member: buoyancy_setpoint
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "buoyancy_setpoint: ";
    rosidl_generator_traits::value_to_yaml(msg.buoyancy_setpoint, out);
    out << "\n";
  }

  // member: buoyancy_now_depth
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "buoyancy_now_depth: ";
    rosidl_generator_traits::value_to_yaml(msg.buoyancy_now_depth, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AUVStatus & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace control_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use control_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const control_interfaces::msg::AUVStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  control_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use control_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const control_interfaces::msg::AUVStatus & msg)
{
  return control_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<control_interfaces::msg::AUVStatus>()
{
  return "control_interfaces::msg::AUVStatus";
}

template<>
inline const char * name<control_interfaces::msg::AUVStatus>()
{
  return "control_interfaces/msg/AUVStatus";
}

template<>
struct has_fixed_size<control_interfaces::msg::AUVStatus>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<control_interfaces::msg::AUVStatus>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<control_interfaces::msg::AUVStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CONTROL_INTERFACES__MSG__DETAIL__AUV_STATUS__TRAITS_HPP_
