// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from facer_interfaces:srv/DetectionResult.idl
// generated code does not contain a copyright notice

#ifndef FACER_INTERFACES__SRV__DETAIL__DETECTION_RESULT__FUNCTIONS_H_
#define FACER_INTERFACES__SRV__DETAIL__DETECTION_RESULT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "facer_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "facer_interfaces/srv/detail/detection_result__struct.h"

/// Initialize srv/DetectionResult message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * facer_interfaces__srv__DetectionResult_Request
 * )) before or use
 * facer_interfaces__srv__DetectionResult_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_facer_interfaces
bool
facer_interfaces__srv__DetectionResult_Request__init(facer_interfaces__srv__DetectionResult_Request * msg);

/// Finalize srv/DetectionResult message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_facer_interfaces
void
facer_interfaces__srv__DetectionResult_Request__fini(facer_interfaces__srv__DetectionResult_Request * msg);

/// Create srv/DetectionResult message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * facer_interfaces__srv__DetectionResult_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_facer_interfaces
facer_interfaces__srv__DetectionResult_Request *
facer_interfaces__srv__DetectionResult_Request__create();

/// Destroy srv/DetectionResult message.
/**
 * It calls
 * facer_interfaces__srv__DetectionResult_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_facer_interfaces
void
facer_interfaces__srv__DetectionResult_Request__destroy(facer_interfaces__srv__DetectionResult_Request * msg);

/// Check for srv/DetectionResult message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_facer_interfaces
bool
facer_interfaces__srv__DetectionResult_Request__are_equal(const facer_interfaces__srv__DetectionResult_Request * lhs, const facer_interfaces__srv__DetectionResult_Request * rhs);

/// Copy a srv/DetectionResult message.
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
ROSIDL_GENERATOR_C_PUBLIC_facer_interfaces
bool
facer_interfaces__srv__DetectionResult_Request__copy(
  const facer_interfaces__srv__DetectionResult_Request * input,
  facer_interfaces__srv__DetectionResult_Request * output);

/// Initialize array of srv/DetectionResult messages.
/**
 * It allocates the memory for the number of elements and calls
 * facer_interfaces__srv__DetectionResult_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_facer_interfaces
bool
facer_interfaces__srv__DetectionResult_Request__Sequence__init(facer_interfaces__srv__DetectionResult_Request__Sequence * array, size_t size);

/// Finalize array of srv/DetectionResult messages.
/**
 * It calls
 * facer_interfaces__srv__DetectionResult_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_facer_interfaces
void
facer_interfaces__srv__DetectionResult_Request__Sequence__fini(facer_interfaces__srv__DetectionResult_Request__Sequence * array);

/// Create array of srv/DetectionResult messages.
/**
 * It allocates the memory for the array and calls
 * facer_interfaces__srv__DetectionResult_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_facer_interfaces
facer_interfaces__srv__DetectionResult_Request__Sequence *
facer_interfaces__srv__DetectionResult_Request__Sequence__create(size_t size);

/// Destroy array of srv/DetectionResult messages.
/**
 * It calls
 * facer_interfaces__srv__DetectionResult_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_facer_interfaces
void
facer_interfaces__srv__DetectionResult_Request__Sequence__destroy(facer_interfaces__srv__DetectionResult_Request__Sequence * array);

/// Check for srv/DetectionResult message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_facer_interfaces
bool
facer_interfaces__srv__DetectionResult_Request__Sequence__are_equal(const facer_interfaces__srv__DetectionResult_Request__Sequence * lhs, const facer_interfaces__srv__DetectionResult_Request__Sequence * rhs);

/// Copy an array of srv/DetectionResult messages.
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
ROSIDL_GENERATOR_C_PUBLIC_facer_interfaces
bool
facer_interfaces__srv__DetectionResult_Request__Sequence__copy(
  const facer_interfaces__srv__DetectionResult_Request__Sequence * input,
  facer_interfaces__srv__DetectionResult_Request__Sequence * output);

/// Initialize srv/DetectionResult message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * facer_interfaces__srv__DetectionResult_Response
 * )) before or use
 * facer_interfaces__srv__DetectionResult_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_facer_interfaces
bool
facer_interfaces__srv__DetectionResult_Response__init(facer_interfaces__srv__DetectionResult_Response * msg);

/// Finalize srv/DetectionResult message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_facer_interfaces
void
facer_interfaces__srv__DetectionResult_Response__fini(facer_interfaces__srv__DetectionResult_Response * msg);

/// Create srv/DetectionResult message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * facer_interfaces__srv__DetectionResult_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_facer_interfaces
facer_interfaces__srv__DetectionResult_Response *
facer_interfaces__srv__DetectionResult_Response__create();

/// Destroy srv/DetectionResult message.
/**
 * It calls
 * facer_interfaces__srv__DetectionResult_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_facer_interfaces
void
facer_interfaces__srv__DetectionResult_Response__destroy(facer_interfaces__srv__DetectionResult_Response * msg);

/// Check for srv/DetectionResult message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_facer_interfaces
bool
facer_interfaces__srv__DetectionResult_Response__are_equal(const facer_interfaces__srv__DetectionResult_Response * lhs, const facer_interfaces__srv__DetectionResult_Response * rhs);

/// Copy a srv/DetectionResult message.
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
ROSIDL_GENERATOR_C_PUBLIC_facer_interfaces
bool
facer_interfaces__srv__DetectionResult_Response__copy(
  const facer_interfaces__srv__DetectionResult_Response * input,
  facer_interfaces__srv__DetectionResult_Response * output);

/// Initialize array of srv/DetectionResult messages.
/**
 * It allocates the memory for the number of elements and calls
 * facer_interfaces__srv__DetectionResult_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_facer_interfaces
bool
facer_interfaces__srv__DetectionResult_Response__Sequence__init(facer_interfaces__srv__DetectionResult_Response__Sequence * array, size_t size);

/// Finalize array of srv/DetectionResult messages.
/**
 * It calls
 * facer_interfaces__srv__DetectionResult_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_facer_interfaces
void
facer_interfaces__srv__DetectionResult_Response__Sequence__fini(facer_interfaces__srv__DetectionResult_Response__Sequence * array);

/// Create array of srv/DetectionResult messages.
/**
 * It allocates the memory for the array and calls
 * facer_interfaces__srv__DetectionResult_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_facer_interfaces
facer_interfaces__srv__DetectionResult_Response__Sequence *
facer_interfaces__srv__DetectionResult_Response__Sequence__create(size_t size);

/// Destroy array of srv/DetectionResult messages.
/**
 * It calls
 * facer_interfaces__srv__DetectionResult_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_facer_interfaces
void
facer_interfaces__srv__DetectionResult_Response__Sequence__destroy(facer_interfaces__srv__DetectionResult_Response__Sequence * array);

/// Check for srv/DetectionResult message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_facer_interfaces
bool
facer_interfaces__srv__DetectionResult_Response__Sequence__are_equal(const facer_interfaces__srv__DetectionResult_Response__Sequence * lhs, const facer_interfaces__srv__DetectionResult_Response__Sequence * rhs);

/// Copy an array of srv/DetectionResult messages.
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
ROSIDL_GENERATOR_C_PUBLIC_facer_interfaces
bool
facer_interfaces__srv__DetectionResult_Response__Sequence__copy(
  const facer_interfaces__srv__DetectionResult_Response__Sequence * input,
  facer_interfaces__srv__DetectionResult_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // FACER_INTERFACES__SRV__DETAIL__DETECTION_RESULT__FUNCTIONS_H_
