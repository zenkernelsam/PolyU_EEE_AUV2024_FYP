// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from control_interfaces:msg/AUVBuoyancy.idl
// generated code does not contain a copyright notice

#ifndef CONTROL_INTERFACES__MSG__DETAIL__AUV_BUOYANCY__FUNCTIONS_H_
#define CONTROL_INTERFACES__MSG__DETAIL__AUV_BUOYANCY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "control_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "control_interfaces/msg/detail/auv_buoyancy__struct.h"

/// Initialize msg/AUVBuoyancy message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * control_interfaces__msg__AUVBuoyancy
 * )) before or use
 * control_interfaces__msg__AUVBuoyancy__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_control_interfaces
bool
control_interfaces__msg__AUVBuoyancy__init(control_interfaces__msg__AUVBuoyancy * msg);

/// Finalize msg/AUVBuoyancy message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_control_interfaces
void
control_interfaces__msg__AUVBuoyancy__fini(control_interfaces__msg__AUVBuoyancy * msg);

/// Create msg/AUVBuoyancy message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * control_interfaces__msg__AUVBuoyancy__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_control_interfaces
control_interfaces__msg__AUVBuoyancy *
control_interfaces__msg__AUVBuoyancy__create();

/// Destroy msg/AUVBuoyancy message.
/**
 * It calls
 * control_interfaces__msg__AUVBuoyancy__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_control_interfaces
void
control_interfaces__msg__AUVBuoyancy__destroy(control_interfaces__msg__AUVBuoyancy * msg);

/// Check for msg/AUVBuoyancy message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_control_interfaces
bool
control_interfaces__msg__AUVBuoyancy__are_equal(const control_interfaces__msg__AUVBuoyancy * lhs, const control_interfaces__msg__AUVBuoyancy * rhs);

/// Copy a msg/AUVBuoyancy message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_control_interfaces
bool
control_interfaces__msg__AUVBuoyancy__copy(
  const control_interfaces__msg__AUVBuoyancy * input,
  control_interfaces__msg__AUVBuoyancy * output);

/// Initialize array of msg/AUVBuoyancy messages.
/**
 * It allocates the memory for the number of elements and calls
 * control_interfaces__msg__AUVBuoyancy__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_control_interfaces
bool
control_interfaces__msg__AUVBuoyancy__Sequence__init(control_interfaces__msg__AUVBuoyancy__Sequence * array, size_t size);

/// Finalize array of msg/AUVBuoyancy messages.
/**
 * It calls
 * control_interfaces__msg__AUVBuoyancy__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_control_interfaces
void
control_interfaces__msg__AUVBuoyancy__Sequence__fini(control_interfaces__msg__AUVBuoyancy__Sequence * array);

/// Create array of msg/AUVBuoyancy messages.
/**
 * It allocates the memory for the array and calls
 * control_interfaces__msg__AUVBuoyancy__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_control_interfaces
control_interfaces__msg__AUVBuoyancy__Sequence *
control_interfaces__msg__AUVBuoyancy__Sequence__create(size_t size);

/// Destroy array of msg/AUVBuoyancy messages.
/**
 * It calls
 * control_interfaces__msg__AUVBuoyancy__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_control_interfaces
void
control_interfaces__msg__AUVBuoyancy__Sequence__destroy(control_interfaces__msg__AUVBuoyancy__Sequence * array);

/// Check for msg/AUVBuoyancy message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_control_interfaces
bool
control_interfaces__msg__AUVBuoyancy__Sequence__are_equal(const control_interfaces__msg__AUVBuoyancy__Sequence * lhs, const control_interfaces__msg__AUVBuoyancy__Sequence * rhs);

/// Copy an array of msg/AUVBuoyancy messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_control_interfaces
bool
control_interfaces__msg__AUVBuoyancy__Sequence__copy(
  const control_interfaces__msg__AUVBuoyancy__Sequence * input,
  control_interfaces__msg__AUVBuoyancy__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // CONTROL_INTERFACES__MSG__DETAIL__AUV_BUOYANCY__FUNCTIONS_H_
