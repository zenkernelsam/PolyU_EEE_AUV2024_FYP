// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from control_interfaces:srv/GetCommand.idl
// generated code does not contain a copyright notice

#ifndef CONTROL_INTERFACES__SRV__DETAIL__GET_COMMAND__TRAITS_HPP_
#define CONTROL_INTERFACES__SRV__DETAIL__GET_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "control_interfaces/srv/detail/get_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace control_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetCommand_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: get_command
  {
    out << "get_command: ";
    rosidl_generator_traits::value_to_yaml(msg.get_command, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetCommand_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: get_command
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "get_command: ";
    rosidl_generator_traits::value_to_yaml(msg.get_command, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetCommand_Request & msg, bool use_flow_style = false)
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
  const control_interfaces::srv::GetCommand_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  control_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use control_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const control_interfaces::srv::GetCommand_Request & msg)
{
  return control_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<control_interfaces::srv::GetCommand_Request>()
{
  return "control_interfaces::srv::GetCommand_Request";
}

template<>
inline const char * name<control_interfaces::srv::GetCommand_Request>()
{
  return "control_interfaces/srv/GetCommand_Request";
}

template<>
struct has_fixed_size<control_interfaces::srv::GetCommand_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<control_interfaces::srv::GetCommand_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<control_interfaces::srv::GetCommand_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace control_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetCommand_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: task_name
  {
    out << "task_name: ";
    rosidl_generator_traits::value_to_yaml(msg.task_name, out);
    out << ", ";
  }

  // member: buoyancy_direction
  {
    out << "buoyancy_direction: ";
    rosidl_generator_traits::value_to_yaml(msg.buoyancy_direction, out);
    out << ", ";
  }

  // member: thruster_direction
  {
    out << "thruster_direction: ";
    rosidl_generator_traits::value_to_yaml(msg.thruster_direction, out);
    out << ", ";
  }

  // member: time
  {
    out << "time: ";
    rosidl_generator_traits::value_to_yaml(msg.time, out);
    out << ", ";
  }

  // member: angle
  {
    out << "angle: ";
    rosidl_generator_traits::value_to_yaml(msg.angle, out);
    out << ", ";
  }

  // member: count
  {
    out << "count: ";
    rosidl_generator_traits::value_to_yaml(msg.count, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetCommand_Response & msg,
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

  // member: buoyancy_direction
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "buoyancy_direction: ";
    rosidl_generator_traits::value_to_yaml(msg.buoyancy_direction, out);
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

  // member: time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time: ";
    rosidl_generator_traits::value_to_yaml(msg.time, out);
    out << "\n";
  }

  // member: angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angle: ";
    rosidl_generator_traits::value_to_yaml(msg.angle, out);
    out << "\n";
  }

  // member: count
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "count: ";
    rosidl_generator_traits::value_to_yaml(msg.count, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetCommand_Response & msg, bool use_flow_style = false)
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
  const control_interfaces::srv::GetCommand_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  control_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use control_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const control_interfaces::srv::GetCommand_Response & msg)
{
  return control_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<control_interfaces::srv::GetCommand_Response>()
{
  return "control_interfaces::srv::GetCommand_Response";
}

template<>
inline const char * name<control_interfaces::srv::GetCommand_Response>()
{
  return "control_interfaces/srv/GetCommand_Response";
}

template<>
struct has_fixed_size<control_interfaces::srv::GetCommand_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<control_interfaces::srv::GetCommand_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<control_interfaces::srv::GetCommand_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<control_interfaces::srv::GetCommand>()
{
  return "control_interfaces::srv::GetCommand";
}

template<>
inline const char * name<control_interfaces::srv::GetCommand>()
{
  return "control_interfaces/srv/GetCommand";
}

template<>
struct has_fixed_size<control_interfaces::srv::GetCommand>
  : std::integral_constant<
    bool,
    has_fixed_size<control_interfaces::srv::GetCommand_Request>::value &&
    has_fixed_size<control_interfaces::srv::GetCommand_Response>::value
  >
{
};

template<>
struct has_bounded_size<control_interfaces::srv::GetCommand>
  : std::integral_constant<
    bool,
    has_bounded_size<control_interfaces::srv::GetCommand_Request>::value &&
    has_bounded_size<control_interfaces::srv::GetCommand_Response>::value
  >
{
};

template<>
struct is_service<control_interfaces::srv::GetCommand>
  : std::true_type
{
};

template<>
struct is_service_request<control_interfaces::srv::GetCommand_Request>
  : std::true_type
{
};

template<>
struct is_service_response<control_interfaces::srv::GetCommand_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CONTROL_INTERFACES__SRV__DETAIL__GET_COMMAND__TRAITS_HPP_
