// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from facer_interfaces:srv/DetectionResult.idl
// generated code does not contain a copyright notice

#ifndef FACER_INTERFACES__SRV__DETAIL__DETECTION_RESULT__TRAITS_HPP_
#define FACER_INTERFACES__SRV__DETAIL__DETECTION_RESULT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "facer_interfaces/srv/detail/detection_result__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace facer_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const DetectionResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: apply_result
  {
    out << "apply_result: ";
    rosidl_generator_traits::value_to_yaml(msg.apply_result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DetectionResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: apply_result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "apply_result: ";
    rosidl_generator_traits::value_to_yaml(msg.apply_result, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DetectionResult_Request & msg, bool use_flow_style = false)
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

}  // namespace facer_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use facer_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const facer_interfaces::srv::DetectionResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  facer_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use facer_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const facer_interfaces::srv::DetectionResult_Request & msg)
{
  return facer_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<facer_interfaces::srv::DetectionResult_Request>()
{
  return "facer_interfaces::srv::DetectionResult_Request";
}

template<>
inline const char * name<facer_interfaces::srv::DetectionResult_Request>()
{
  return "facer_interfaces/srv/DetectionResult_Request";
}

template<>
struct has_fixed_size<facer_interfaces::srv::DetectionResult_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<facer_interfaces::srv::DetectionResult_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<facer_interfaces::srv::DetectionResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace facer_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const DetectionResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: get_result
  {
    out << "get_result: ";
    rosidl_generator_traits::value_to_yaml(msg.get_result, out);
    out << ", ";
  }

  // member: is_finished
  {
    out << "is_finished: ";
    rosidl_generator_traits::value_to_yaml(msg.is_finished, out);
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
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DetectionResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: get_result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "get_result: ";
    rosidl_generator_traits::value_to_yaml(msg.get_result, out);
    out << "\n";
  }

  // member: is_finished
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_finished: ";
    rosidl_generator_traits::value_to_yaml(msg.is_finished, out);
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DetectionResult_Response & msg, bool use_flow_style = false)
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

}  // namespace facer_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use facer_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const facer_interfaces::srv::DetectionResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  facer_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use facer_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const facer_interfaces::srv::DetectionResult_Response & msg)
{
  return facer_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<facer_interfaces::srv::DetectionResult_Response>()
{
  return "facer_interfaces::srv::DetectionResult_Response";
}

template<>
inline const char * name<facer_interfaces::srv::DetectionResult_Response>()
{
  return "facer_interfaces/srv/DetectionResult_Response";
}

template<>
struct has_fixed_size<facer_interfaces::srv::DetectionResult_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<facer_interfaces::srv::DetectionResult_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<facer_interfaces::srv::DetectionResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<facer_interfaces::srv::DetectionResult>()
{
  return "facer_interfaces::srv::DetectionResult";
}

template<>
inline const char * name<facer_interfaces::srv::DetectionResult>()
{
  return "facer_interfaces/srv/DetectionResult";
}

template<>
struct has_fixed_size<facer_interfaces::srv::DetectionResult>
  : std::integral_constant<
    bool,
    has_fixed_size<facer_interfaces::srv::DetectionResult_Request>::value &&
    has_fixed_size<facer_interfaces::srv::DetectionResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<facer_interfaces::srv::DetectionResult>
  : std::integral_constant<
    bool,
    has_bounded_size<facer_interfaces::srv::DetectionResult_Request>::value &&
    has_bounded_size<facer_interfaces::srv::DetectionResult_Response>::value
  >
{
};

template<>
struct is_service<facer_interfaces::srv::DetectionResult>
  : std::true_type
{
};

template<>
struct is_service_request<facer_interfaces::srv::DetectionResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<facer_interfaces::srv::DetectionResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // FACER_INTERFACES__SRV__DETAIL__DETECTION_RESULT__TRAITS_HPP_
