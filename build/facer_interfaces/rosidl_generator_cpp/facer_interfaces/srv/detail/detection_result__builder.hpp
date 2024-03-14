// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from facer_interfaces:srv/DetectionResult.idl
// generated code does not contain a copyright notice

#ifndef FACER_INTERFACES__SRV__DETAIL__DETECTION_RESULT__BUILDER_HPP_
#define FACER_INTERFACES__SRV__DETAIL__DETECTION_RESULT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "facer_interfaces/srv/detail/detection_result__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace facer_interfaces
{

namespace srv
{

namespace builder
{

class Init_DetectionResult_Request_apply_result
{
public:
  Init_DetectionResult_Request_apply_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::facer_interfaces::srv::DetectionResult_Request apply_result(::facer_interfaces::srv::DetectionResult_Request::_apply_result_type arg)
  {
    msg_.apply_result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::facer_interfaces::srv::DetectionResult_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::facer_interfaces::srv::DetectionResult_Request>()
{
  return facer_interfaces::srv::builder::Init_DetectionResult_Request_apply_result();
}

}  // namespace facer_interfaces


namespace facer_interfaces
{

namespace srv
{

namespace builder
{

class Init_DetectionResult_Response_angle
{
public:
  explicit Init_DetectionResult_Response_angle(::facer_interfaces::srv::DetectionResult_Response & msg)
  : msg_(msg)
  {}
  ::facer_interfaces::srv::DetectionResult_Response angle(::facer_interfaces::srv::DetectionResult_Response::_angle_type arg)
  {
    msg_.angle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::facer_interfaces::srv::DetectionResult_Response msg_;
};

class Init_DetectionResult_Response_time
{
public:
  explicit Init_DetectionResult_Response_time(::facer_interfaces::srv::DetectionResult_Response & msg)
  : msg_(msg)
  {}
  Init_DetectionResult_Response_angle time(::facer_interfaces::srv::DetectionResult_Response::_time_type arg)
  {
    msg_.time = std::move(arg);
    return Init_DetectionResult_Response_angle(msg_);
  }

private:
  ::facer_interfaces::srv::DetectionResult_Response msg_;
};

class Init_DetectionResult_Response_thruster_direction
{
public:
  explicit Init_DetectionResult_Response_thruster_direction(::facer_interfaces::srv::DetectionResult_Response & msg)
  : msg_(msg)
  {}
  Init_DetectionResult_Response_time thruster_direction(::facer_interfaces::srv::DetectionResult_Response::_thruster_direction_type arg)
  {
    msg_.thruster_direction = std::move(arg);
    return Init_DetectionResult_Response_time(msg_);
  }

private:
  ::facer_interfaces::srv::DetectionResult_Response msg_;
};

class Init_DetectionResult_Response_buoyancy_direction
{
public:
  explicit Init_DetectionResult_Response_buoyancy_direction(::facer_interfaces::srv::DetectionResult_Response & msg)
  : msg_(msg)
  {}
  Init_DetectionResult_Response_thruster_direction buoyancy_direction(::facer_interfaces::srv::DetectionResult_Response::_buoyancy_direction_type arg)
  {
    msg_.buoyancy_direction = std::move(arg);
    return Init_DetectionResult_Response_thruster_direction(msg_);
  }

private:
  ::facer_interfaces::srv::DetectionResult_Response msg_;
};

class Init_DetectionResult_Response_is_finished
{
public:
  explicit Init_DetectionResult_Response_is_finished(::facer_interfaces::srv::DetectionResult_Response & msg)
  : msg_(msg)
  {}
  Init_DetectionResult_Response_buoyancy_direction is_finished(::facer_interfaces::srv::DetectionResult_Response::_is_finished_type arg)
  {
    msg_.is_finished = std::move(arg);
    return Init_DetectionResult_Response_buoyancy_direction(msg_);
  }

private:
  ::facer_interfaces::srv::DetectionResult_Response msg_;
};

class Init_DetectionResult_Response_get_result
{
public:
  Init_DetectionResult_Response_get_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DetectionResult_Response_is_finished get_result(::facer_interfaces::srv::DetectionResult_Response::_get_result_type arg)
  {
    msg_.get_result = std::move(arg);
    return Init_DetectionResult_Response_is_finished(msg_);
  }

private:
  ::facer_interfaces::srv::DetectionResult_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::facer_interfaces::srv::DetectionResult_Response>()
{
  return facer_interfaces::srv::builder::Init_DetectionResult_Response_get_result();
}

}  // namespace facer_interfaces

#endif  // FACER_INTERFACES__SRV__DETAIL__DETECTION_RESULT__BUILDER_HPP_
