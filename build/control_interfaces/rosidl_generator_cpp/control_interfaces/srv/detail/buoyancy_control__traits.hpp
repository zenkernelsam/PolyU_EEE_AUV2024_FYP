// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from control_interfaces:srv/BuoyancyControl.idl
// generated code does not contain a copyright notice

#ifndef CONTROL_INTERFACES__SRV__DETAIL__BUOYANCY_CONTROL__TRAITS_HPP_
#define CONTROL_INTERFACES__SRV__DETAIL__BUOYANCY_CONTROL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "control_interfaces/srv/detail/buoyancy_control__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace control_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const BuoyancyControl_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: modify_depth
  {
    out << "modify_depth: ";
    rosidl_generator_traits::value_to_yaml(msg.modify_depth, out);
    out << ", ";
  }

  // member: new_depth
  {
    out << "new_depth: ";
    rosidl_generator_traits::value_to_yaml(msg.new_depth, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BuoyancyControl_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: modify_depth
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "modify_depth: ";
    rosidl_generator_traits::value_to_yaml(msg.modify_depth, out);
    out << "\n";
  }

  // member: new_depth
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "new_depth: ";
    rosidl_generator_traits::value_to_yaml(msg.new_depth, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BuoyancyControl_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace control_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use control_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const control_interfaces::srv::BuoyancyControl_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  control_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use control_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const control_interfaces::srv::BuoyancyControl_Request & msg)
{
  return control_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<control_interfaces::srv::BuoyancyControl_Request>()
{
  return "control_interfaces::srv::BuoyancyControl_Request";
}

template<>
inline const char * name<control_interfaces::srv::BuoyancyControl_Request>()
{
  return "control_interfaces/srv/BuoyancyControl_Request";
}

template<>
struct has_fixed_size<control_interfaces::srv::BuoyancyControl_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<control_interfaces::srv::BuoyancyControl_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<control_interfaces::srv::BuoyancyControl_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace control_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const BuoyancyControl_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: is_succeeded
  {
    out << "is_succeeded: ";
    rosidl_generator_traits::value_to_yaml(msg.is_succeeded, out);
    out << ", ";
  }

  // member: now_depth
  {
    out << "now_depth: ";
    rosidl_generator_traits::value_to_yaml(msg.now_depth, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BuoyancyControl_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: is_succeeded
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_succeeded: ";
    rosidl_generator_traits::value_to_yaml(msg.is_succeeded, out);
    out << "\n";
  }

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

inline std::string to_yaml(const BuoyancyControl_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace control_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use control_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const control_interfaces::srv::BuoyancyControl_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  control_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use control_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const control_interfaces::srv::BuoyancyControl_Response & msg)
{
  return control_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<control_interfaces::srv::BuoyancyControl_Response>()
{
  return "control_interfaces::srv::BuoyancyControl_Response";
}

template<>
inline const char * name<control_interfaces::srv::BuoyancyControl_Response>()
{
  return "control_interfaces/srv/BuoyancyControl_Response";
}

template<>
struct has_fixed_size<control_interfaces::srv::BuoyancyControl_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<control_interfaces::srv::BuoyancyControl_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<control_interfaces::srv::BuoyancyControl_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<control_interfaces::srv::BuoyancyControl>()
{
  return "control_interfaces::srv::BuoyancyControl";
}

template<>
inline const char * name<control_interfaces::srv::BuoyancyControl>()
{
  return "control_interfaces/srv/BuoyancyControl";
}

template<>
struct has_fixed_size<control_interfaces::srv::BuoyancyControl>
  : std::integral_constant<
    bool,
    has_fixed_size<control_interfaces::srv::BuoyancyControl_Request>::value &&
    has_fixed_size<control_interfaces::srv::BuoyancyControl_Response>::value
  >
{
};

template<>
struct has_bounded_size<control_interfaces::srv::BuoyancyControl>
  : std::integral_constant<
    bool,
    has_bounded_size<control_interfaces::srv::BuoyancyControl_Request>::value &&
    has_bounded_size<control_interfaces::srv::BuoyancyControl_Response>::value
  >
{
};

template<>
struct is_service<control_interfaces::srv::BuoyancyControl>
  : std::true_type
{
};

template<>
struct is_service_request<control_interfaces::srv::BuoyancyControl_Request>
  : std::true_type
{
};

template<>
struct is_service_response<control_interfaces::srv::BuoyancyControl_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CONTROL_INTERFACES__SRV__DETAIL__BUOYANCY_CONTROL__TRAITS_HPP_
