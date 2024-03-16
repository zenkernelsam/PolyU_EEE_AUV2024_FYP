// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from control_interfaces:msg/AUVStatus.idl
// generated code does not contain a copyright notice

#ifndef CONTROL_INTERFACES__MSG__DETAIL__AUV_STATUS__STRUCT_HPP_
#define CONTROL_INTERFACES__MSG__DETAIL__AUV_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__control_interfaces__msg__AUVStatus __attribute__((deprecated))
#else
# define DEPRECATED__control_interfaces__msg__AUVStatus __declspec(deprecated)
#endif

namespace control_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct AUVStatus_
{
  using Type = AUVStatus_<ContainerAllocator>;

  explicit AUVStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->task_name = "";
      this->thruster_direction = "";
      this->buoyancy_direction = "";
      this->buoyancy_setpoint = 0.0f;
      this->buoyancy_now_depth = 0.0f;
    }
  }

  explicit AUVStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : task_name(_alloc),
    thruster_direction(_alloc),
    buoyancy_direction(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->task_name = "";
      this->thruster_direction = "";
      this->buoyancy_direction = "";
      this->buoyancy_setpoint = 0.0f;
      this->buoyancy_now_depth = 0.0f;
    }
  }

  // field types and members
  using _task_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _task_name_type task_name;
  using _thruster_direction_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _thruster_direction_type thruster_direction;
  using _buoyancy_direction_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _buoyancy_direction_type buoyancy_direction;
  using _buoyancy_setpoint_type =
    float;
  _buoyancy_setpoint_type buoyancy_setpoint;
  using _buoyancy_now_depth_type =
    float;
  _buoyancy_now_depth_type buoyancy_now_depth;

  // setters for named parameter idiom
  Type & set__task_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->task_name = _arg;
    return *this;
  }
  Type & set__thruster_direction(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->thruster_direction = _arg;
    return *this;
  }
  Type & set__buoyancy_direction(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->buoyancy_direction = _arg;
    return *this;
  }
  Type & set__buoyancy_setpoint(
    const float & _arg)
  {
    this->buoyancy_setpoint = _arg;
    return *this;
  }
  Type & set__buoyancy_now_depth(
    const float & _arg)
  {
    this->buoyancy_now_depth = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    control_interfaces::msg::AUVStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const control_interfaces::msg::AUVStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<control_interfaces::msg::AUVStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<control_interfaces::msg::AUVStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      control_interfaces::msg::AUVStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<control_interfaces::msg::AUVStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      control_interfaces::msg::AUVStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<control_interfaces::msg::AUVStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<control_interfaces::msg::AUVStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<control_interfaces::msg::AUVStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__control_interfaces__msg__AUVStatus
    std::shared_ptr<control_interfaces::msg::AUVStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__control_interfaces__msg__AUVStatus
    std::shared_ptr<control_interfaces::msg::AUVStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AUVStatus_ & other) const
  {
    if (this->task_name != other.task_name) {
      return false;
    }
    if (this->thruster_direction != other.thruster_direction) {
      return false;
    }
    if (this->buoyancy_direction != other.buoyancy_direction) {
      return false;
    }
    if (this->buoyancy_setpoint != other.buoyancy_setpoint) {
      return false;
    }
    if (this->buoyancy_now_depth != other.buoyancy_now_depth) {
      return false;
    }
    return true;
  }
  bool operator!=(const AUVStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AUVStatus_

// alias to use template instance with default allocator
using AUVStatus =
  control_interfaces::msg::AUVStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace control_interfaces

#endif  // CONTROL_INTERFACES__MSG__DETAIL__AUV_STATUS__STRUCT_HPP_
