// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from control_interfaces:msg/AUVBuoyancy.idl
// generated code does not contain a copyright notice

#ifndef CONTROL_INTERFACES__MSG__DETAIL__AUV_BUOYANCY__TRAITS_HPP_
#define CONTROL_INTERFACES__MSG__DETAIL__AUV_BUOYANCY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "control_interfaces/msg/detail/auv_buoyancy__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace control_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const AUVBuoyancy & msg,
  std::ostream & out)
{
  out << "{";
  // member: now_depth
  {
    out << "now_depth: ";
    rosidl_generator_traits::value_to_yaml(msg.now_depth, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AUVBuoyancy & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: now_depth
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "now_depth: ";
    rosidl_generator_traits::value_to_yaml(msg.now_depth, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AUVBuoyancy & msg, bool use_flow_style = false)
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
  const control_interfaces::msg::AUVBuoyancy & msg,
  std::ostream & out, size_t indentation = 0)
{
  control_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use control_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const control_interfaces::msg::AUVBuoyancy & msg)
{
  return control_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<control_interfaces::msg::AUVBuoyancy>()
{
  return "control_interfaces::msg::AUVBuoyancy";
}

template<>
inline const char * name<control_interfaces::msg::AUVBuoyancy>()
{
  return "control_interfaces/msg/AUVBuoyancy";
}

template<>
struct has_fixed_size<control_interfaces::msg::AUVBuoyancy>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<control_interfaces::msg::AUVBuoyancy>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<control_interfaces::msg::AUVBuoyancy>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CONTROL_INTERFACES__MSG__DETAIL__AUV_BUOYANCY__TRAITS_HPP_
