// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from control_interfaces:msg/AUVBuoyancy.idl
// generated code does not contain a copyright notice

#ifndef CONTROL_INTERFACES__MSG__DETAIL__AUV_BUOYANCY__STRUCT_HPP_
#define CONTROL_INTERFACES__MSG__DETAIL__AUV_BUOYANCY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__control_interfaces__msg__AUVBuoyancy __attribute__((deprecated))
#else
# define DEPRECATED__control_interfaces__msg__AUVBuoyancy __declspec(deprecated)
#endif

namespace control_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct AUVBuoyancy_
{
  using Type = AUVBuoyancy_<ContainerAllocator>;

  explicit AUVBuoyancy_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->now_depth = 0.0f;
    }
  }

  explicit AUVBuoyancy_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->now_depth = 0.0f;
    }
  }

  // field types and members
  using _now_depth_type =
    float;
  _now_depth_type now_depth;

  // setters for named parameter idiom
  Type & set__now_depth(
    const float & _arg)
  {
    this->now_depth = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    control_interfaces::msg::AUVBuoyancy_<ContainerAllocator> *;
  using ConstRawPtr =
    const control_interfaces::msg::AUVBuoyancy_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<control_interfaces::msg::AUVBuoyancy_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<control_interfaces::msg::AUVBuoyancy_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      control_interfaces::msg::AUVBuoyancy_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<control_interfaces::msg::AUVBuoyancy_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      control_interfaces::msg::AUVBuoyancy_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<control_interfaces::msg::AUVBuoyancy_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<control_interfaces::msg::AUVBuoyancy_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<control_interfaces::msg::AUVBuoyancy_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__control_interfaces__msg__AUVBuoyancy
    std::shared_ptr<control_interfaces::msg::AUVBuoyancy_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__control_interfaces__msg__AUVBuoyancy
    std::shared_ptr<control_interfaces::msg::AUVBuoyancy_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AUVBuoyancy_ & other) const
  {
    if (this->now_depth != other.now_depth) {
      return false;
    }
    return true;
  }
  bool operator!=(const AUVBuoyancy_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AUVBuoyancy_

// alias to use template instance with default allocator
using AUVBuoyancy =
  control_interfaces::msg::AUVBuoyancy_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace control_interfaces

#endif  // CONTROL_INTERFACES__MSG__DETAIL__AUV_BUOYANCY__STRUCT_HPP_
