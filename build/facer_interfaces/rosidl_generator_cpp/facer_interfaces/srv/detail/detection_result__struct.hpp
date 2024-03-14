// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from facer_interfaces:srv/DetectionResult.idl
// generated code does not contain a copyright notice

#ifndef FACER_INTERFACES__SRV__DETAIL__DETECTION_RESULT__STRUCT_HPP_
#define FACER_INTERFACES__SRV__DETAIL__DETECTION_RESULT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__facer_interfaces__srv__DetectionResult_Request __attribute__((deprecated))
#else
# define DEPRECATED__facer_interfaces__srv__DetectionResult_Request __declspec(deprecated)
#endif

namespace facer_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DetectionResult_Request_
{
  using Type = DetectionResult_Request_<ContainerAllocator>;

  explicit DetectionResult_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->apply_result = false;
    }
  }

  explicit DetectionResult_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->apply_result = false;
    }
  }

  // field types and members
  using _apply_result_type =
    bool;
  _apply_result_type apply_result;

  // setters for named parameter idiom
  Type & set__apply_result(
    const bool & _arg)
  {
    this->apply_result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    facer_interfaces::srv::DetectionResult_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const facer_interfaces::srv::DetectionResult_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<facer_interfaces::srv::DetectionResult_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<facer_interfaces::srv::DetectionResult_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      facer_interfaces::srv::DetectionResult_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<facer_interfaces::srv::DetectionResult_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      facer_interfaces::srv::DetectionResult_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<facer_interfaces::srv::DetectionResult_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<facer_interfaces::srv::DetectionResult_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<facer_interfaces::srv::DetectionResult_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__facer_interfaces__srv__DetectionResult_Request
    std::shared_ptr<facer_interfaces::srv::DetectionResult_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__facer_interfaces__srv__DetectionResult_Request
    std::shared_ptr<facer_interfaces::srv::DetectionResult_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DetectionResult_Request_ & other) const
  {
    if (this->apply_result != other.apply_result) {
      return false;
    }
    return true;
  }
  bool operator!=(const DetectionResult_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DetectionResult_Request_

// alias to use template instance with default allocator
using DetectionResult_Request =
  facer_interfaces::srv::DetectionResult_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace facer_interfaces


#ifndef _WIN32
# define DEPRECATED__facer_interfaces__srv__DetectionResult_Response __attribute__((deprecated))
#else
# define DEPRECATED__facer_interfaces__srv__DetectionResult_Response __declspec(deprecated)
#endif

namespace facer_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DetectionResult_Response_
{
  using Type = DetectionResult_Response_<ContainerAllocator>;

  explicit DetectionResult_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->get_result = "";
      this->is_finished = false;
      this->buoyancy_direction = "";
      this->thruster_direction = "";
      this->time = 0;
      this->angle = 0;
    }
  }

  explicit DetectionResult_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : get_result(_alloc),
    buoyancy_direction(_alloc),
    thruster_direction(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->get_result = "";
      this->is_finished = false;
      this->buoyancy_direction = "";
      this->thruster_direction = "";
      this->time = 0;
      this->angle = 0;
    }
  }

  // field types and members
  using _get_result_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _get_result_type get_result;
  using _is_finished_type =
    bool;
  _is_finished_type is_finished;
  using _buoyancy_direction_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _buoyancy_direction_type buoyancy_direction;
  using _thruster_direction_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _thruster_direction_type thruster_direction;
  using _time_type =
    uint8_t;
  _time_type time;
  using _angle_type =
    uint8_t;
  _angle_type angle;

  // setters for named parameter idiom
  Type & set__get_result(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->get_result = _arg;
    return *this;
  }
  Type & set__is_finished(
    const bool & _arg)
  {
    this->is_finished = _arg;
    return *this;
  }
  Type & set__buoyancy_direction(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->buoyancy_direction = _arg;
    return *this;
  }
  Type & set__thruster_direction(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->thruster_direction = _arg;
    return *this;
  }
  Type & set__time(
    const uint8_t & _arg)
  {
    this->time = _arg;
    return *this;
  }
  Type & set__angle(
    const uint8_t & _arg)
  {
    this->angle = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    facer_interfaces::srv::DetectionResult_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const facer_interfaces::srv::DetectionResult_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<facer_interfaces::srv::DetectionResult_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<facer_interfaces::srv::DetectionResult_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      facer_interfaces::srv::DetectionResult_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<facer_interfaces::srv::DetectionResult_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      facer_interfaces::srv::DetectionResult_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<facer_interfaces::srv::DetectionResult_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<facer_interfaces::srv::DetectionResult_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<facer_interfaces::srv::DetectionResult_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__facer_interfaces__srv__DetectionResult_Response
    std::shared_ptr<facer_interfaces::srv::DetectionResult_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__facer_interfaces__srv__DetectionResult_Response
    std::shared_ptr<facer_interfaces::srv::DetectionResult_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DetectionResult_Response_ & other) const
  {
    if (this->get_result != other.get_result) {
      return false;
    }
    if (this->is_finished != other.is_finished) {
      return false;
    }
    if (this->buoyancy_direction != other.buoyancy_direction) {
      return false;
    }
    if (this->thruster_direction != other.thruster_direction) {
      return false;
    }
    if (this->time != other.time) {
      return false;
    }
    if (this->angle != other.angle) {
      return false;
    }
    return true;
  }
  bool operator!=(const DetectionResult_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DetectionResult_Response_

// alias to use template instance with default allocator
using DetectionResult_Response =
  facer_interfaces::srv::DetectionResult_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace facer_interfaces

namespace facer_interfaces
{

namespace srv
{

struct DetectionResult
{
  using Request = facer_interfaces::srv::DetectionResult_Request;
  using Response = facer_interfaces::srv::DetectionResult_Response;
};

}  // namespace srv

}  // namespace facer_interfaces

#endif  // FACER_INTERFACES__SRV__DETAIL__DETECTION_RESULT__STRUCT_HPP_
