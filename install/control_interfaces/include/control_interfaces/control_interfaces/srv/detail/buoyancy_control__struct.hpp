// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from control_interfaces:srv/BuoyancyControl.idl
// generated code does not contain a copyright notice

#ifndef CONTROL_INTERFACES__SRV__DETAIL__BUOYANCY_CONTROL__STRUCT_HPP_
#define CONTROL_INTERFACES__SRV__DETAIL__BUOYANCY_CONTROL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__control_interfaces__srv__BuoyancyControl_Request __attribute__((deprecated))
#else
# define DEPRECATED__control_interfaces__srv__BuoyancyControl_Request __declspec(deprecated)
#endif

namespace control_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct BuoyancyControl_Request_
{
  using Type = BuoyancyControl_Request_<ContainerAllocator>;

  explicit BuoyancyControl_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->modify_depth = false;
      this->new_depth = 0.0f;
    }
  }

  explicit BuoyancyControl_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->modify_depth = false;
      this->new_depth = 0.0f;
    }
  }

  // field types and members
  using _modify_depth_type =
    bool;
  _modify_depth_type modify_depth;
  using _new_depth_type =
    float;
  _new_depth_type new_depth;

  // setters for named parameter idiom
  Type & set__modify_depth(
    const bool & _arg)
  {
    this->modify_depth = _arg;
    return *this;
  }
  Type & set__new_depth(
    const float & _arg)
  {
    this->new_depth = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    control_interfaces::srv::BuoyancyControl_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const control_interfaces::srv::BuoyancyControl_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<control_interfaces::srv::BuoyancyControl_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<control_interfaces::srv::BuoyancyControl_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      control_interfaces::srv::BuoyancyControl_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<control_interfaces::srv::BuoyancyControl_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      control_interfaces::srv::BuoyancyControl_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<control_interfaces::srv::BuoyancyControl_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<control_interfaces::srv::BuoyancyControl_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<control_interfaces::srv::BuoyancyControl_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__control_interfaces__srv__BuoyancyControl_Request
    std::shared_ptr<control_interfaces::srv::BuoyancyControl_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__control_interfaces__srv__BuoyancyControl_Request
    std::shared_ptr<control_interfaces::srv::BuoyancyControl_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BuoyancyControl_Request_ & other) const
  {
    if (this->modify_depth != other.modify_depth) {
      return false;
    }
    if (this->new_depth != other.new_depth) {
      return false;
    }
    return true;
  }
  bool operator!=(const BuoyancyControl_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BuoyancyControl_Request_

// alias to use template instance with default allocator
using BuoyancyControl_Request =
  control_interfaces::srv::BuoyancyControl_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace control_interfaces


#ifndef _WIN32
# define DEPRECATED__control_interfaces__srv__BuoyancyControl_Response __attribute__((deprecated))
#else
# define DEPRECATED__control_interfaces__srv__BuoyancyControl_Response __declspec(deprecated)
#endif

namespace control_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct BuoyancyControl_Response_
{
  using Type = BuoyancyControl_Response_<ContainerAllocator>;

  explicit BuoyancyControl_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_succeeded = false;
      this->now_depth = 0.0f;
    }
  }

  explicit BuoyancyControl_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_succeeded = false;
      this->now_depth = 0.0f;
    }
  }

  // field types and members
  using _is_succeeded_type =
    bool;
  _is_succeeded_type is_succeeded;
  using _now_depth_type =
    float;
  _now_depth_type now_depth;

  // setters for named parameter idiom
  Type & set__is_succeeded(
    const bool & _arg)
  {
    this->is_succeeded = _arg;
    return *this;
  }
  Type & set__now_depth(
    const float & _arg)
  {
    this->now_depth = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    control_interfaces::srv::BuoyancyControl_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const control_interfaces::srv::BuoyancyControl_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<control_interfaces::srv::BuoyancyControl_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<control_interfaces::srv::BuoyancyControl_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      control_interfaces::srv::BuoyancyControl_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<control_interfaces::srv::BuoyancyControl_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      control_interfaces::srv::BuoyancyControl_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<control_interfaces::srv::BuoyancyControl_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<control_interfaces::srv::BuoyancyControl_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<control_interfaces::srv::BuoyancyControl_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__control_interfaces__srv__BuoyancyControl_Response
    std::shared_ptr<control_interfaces::srv::BuoyancyControl_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__control_interfaces__srv__BuoyancyControl_Response
    std::shared_ptr<control_interfaces::srv::BuoyancyControl_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BuoyancyControl_Response_ & other) const
  {
    if (this->is_succeeded != other.is_succeeded) {
      return false;
    }
    if (this->now_depth != other.now_depth) {
      return false;
    }
    return true;
  }
  bool operator!=(const BuoyancyControl_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BuoyancyControl_Response_

// alias to use template instance with default allocator
using BuoyancyControl_Response =
  control_interfaces::srv::BuoyancyControl_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace control_interfaces

namespace control_interfaces
{

namespace srv
{

struct BuoyancyControl
{
  using Request = control_interfaces::srv::BuoyancyControl_Request;
  using Response = control_interfaces::srv::BuoyancyControl_Response;
};

}  // namespace srv

}  // namespace control_interfaces

#endif  // CONTROL_INTERFACES__SRV__DETAIL__BUOYANCY_CONTROL__STRUCT_HPP_
