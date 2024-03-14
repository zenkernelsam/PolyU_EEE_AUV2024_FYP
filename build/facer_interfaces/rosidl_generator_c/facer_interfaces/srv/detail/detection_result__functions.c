// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from facer_interfaces:srv/DetectionResult.idl
// generated code does not contain a copyright notice
#include "facer_interfaces/srv/detail/detection_result__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
facer_interfaces__srv__DetectionResult_Request__init(facer_interfaces__srv__DetectionResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // apply_result
  return true;
}

void
facer_interfaces__srv__DetectionResult_Request__fini(facer_interfaces__srv__DetectionResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // apply_result
}

bool
facer_interfaces__srv__DetectionResult_Request__are_equal(const facer_interfaces__srv__DetectionResult_Request * lhs, const facer_interfaces__srv__DetectionResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // apply_result
  if (lhs->apply_result != rhs->apply_result) {
    return false;
  }
  return true;
}

bool
facer_interfaces__srv__DetectionResult_Request__copy(
  const facer_interfaces__srv__DetectionResult_Request * input,
  facer_interfaces__srv__DetectionResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // apply_result
  output->apply_result = input->apply_result;
  return true;
}

facer_interfaces__srv__DetectionResult_Request *
facer_interfaces__srv__DetectionResult_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  facer_interfaces__srv__DetectionResult_Request * msg = (facer_interfaces__srv__DetectionResult_Request *)allocator.allocate(sizeof(facer_interfaces__srv__DetectionResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(facer_interfaces__srv__DetectionResult_Request));
  bool success = facer_interfaces__srv__DetectionResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
facer_interfaces__srv__DetectionResult_Request__destroy(facer_interfaces__srv__DetectionResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    facer_interfaces__srv__DetectionResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
facer_interfaces__srv__DetectionResult_Request__Sequence__init(facer_interfaces__srv__DetectionResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  facer_interfaces__srv__DetectionResult_Request * data = NULL;

  if (size) {
    data = (facer_interfaces__srv__DetectionResult_Request *)allocator.zero_allocate(size, sizeof(facer_interfaces__srv__DetectionResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = facer_interfaces__srv__DetectionResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        facer_interfaces__srv__DetectionResult_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
facer_interfaces__srv__DetectionResult_Request__Sequence__fini(facer_interfaces__srv__DetectionResult_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      facer_interfaces__srv__DetectionResult_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

facer_interfaces__srv__DetectionResult_Request__Sequence *
facer_interfaces__srv__DetectionResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  facer_interfaces__srv__DetectionResult_Request__Sequence * array = (facer_interfaces__srv__DetectionResult_Request__Sequence *)allocator.allocate(sizeof(facer_interfaces__srv__DetectionResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = facer_interfaces__srv__DetectionResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
facer_interfaces__srv__DetectionResult_Request__Sequence__destroy(facer_interfaces__srv__DetectionResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    facer_interfaces__srv__DetectionResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
facer_interfaces__srv__DetectionResult_Request__Sequence__are_equal(const facer_interfaces__srv__DetectionResult_Request__Sequence * lhs, const facer_interfaces__srv__DetectionResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!facer_interfaces__srv__DetectionResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
facer_interfaces__srv__DetectionResult_Request__Sequence__copy(
  const facer_interfaces__srv__DetectionResult_Request__Sequence * input,
  facer_interfaces__srv__DetectionResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(facer_interfaces__srv__DetectionResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    facer_interfaces__srv__DetectionResult_Request * data =
      (facer_interfaces__srv__DetectionResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!facer_interfaces__srv__DetectionResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          facer_interfaces__srv__DetectionResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!facer_interfaces__srv__DetectionResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `get_result`
// Member `buoyancy_direction`
// Member `thruster_direction`
#include "rosidl_runtime_c/string_functions.h"

bool
facer_interfaces__srv__DetectionResult_Response__init(facer_interfaces__srv__DetectionResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // get_result
  if (!rosidl_runtime_c__String__init(&msg->get_result)) {
    facer_interfaces__srv__DetectionResult_Response__fini(msg);
    return false;
  }
  // is_finished
  // buoyancy_direction
  if (!rosidl_runtime_c__String__init(&msg->buoyancy_direction)) {
    facer_interfaces__srv__DetectionResult_Response__fini(msg);
    return false;
  }
  // thruster_direction
  if (!rosidl_runtime_c__String__init(&msg->thruster_direction)) {
    facer_interfaces__srv__DetectionResult_Response__fini(msg);
    return false;
  }
  // time
  // angle
  return true;
}

void
facer_interfaces__srv__DetectionResult_Response__fini(facer_interfaces__srv__DetectionResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // get_result
  rosidl_runtime_c__String__fini(&msg->get_result);
  // is_finished
  // buoyancy_direction
  rosidl_runtime_c__String__fini(&msg->buoyancy_direction);
  // thruster_direction
  rosidl_runtime_c__String__fini(&msg->thruster_direction);
  // time
  // angle
}

bool
facer_interfaces__srv__DetectionResult_Response__are_equal(const facer_interfaces__srv__DetectionResult_Response * lhs, const facer_interfaces__srv__DetectionResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // get_result
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->get_result), &(rhs->get_result)))
  {
    return false;
  }
  // is_finished
  if (lhs->is_finished != rhs->is_finished) {
    return false;
  }
  // buoyancy_direction
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->buoyancy_direction), &(rhs->buoyancy_direction)))
  {
    return false;
  }
  // thruster_direction
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->thruster_direction), &(rhs->thruster_direction)))
  {
    return false;
  }
  // time
  if (lhs->time != rhs->time) {
    return false;
  }
  // angle
  if (lhs->angle != rhs->angle) {
    return false;
  }
  return true;
}

bool
facer_interfaces__srv__DetectionResult_Response__copy(
  const facer_interfaces__srv__DetectionResult_Response * input,
  facer_interfaces__srv__DetectionResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // get_result
  if (!rosidl_runtime_c__String__copy(
      &(input->get_result), &(output->get_result)))
  {
    return false;
  }
  // is_finished
  output->is_finished = input->is_finished;
  // buoyancy_direction
  if (!rosidl_runtime_c__String__copy(
      &(input->buoyancy_direction), &(output->buoyancy_direction)))
  {
    return false;
  }
  // thruster_direction
  if (!rosidl_runtime_c__String__copy(
      &(input->thruster_direction), &(output->thruster_direction)))
  {
    return false;
  }
  // time
  output->time = input->time;
  // angle
  output->angle = input->angle;
  return true;
}

facer_interfaces__srv__DetectionResult_Response *
facer_interfaces__srv__DetectionResult_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  facer_interfaces__srv__DetectionResult_Response * msg = (facer_interfaces__srv__DetectionResult_Response *)allocator.allocate(sizeof(facer_interfaces__srv__DetectionResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(facer_interfaces__srv__DetectionResult_Response));
  bool success = facer_interfaces__srv__DetectionResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
facer_interfaces__srv__DetectionResult_Response__destroy(facer_interfaces__srv__DetectionResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    facer_interfaces__srv__DetectionResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
facer_interfaces__srv__DetectionResult_Response__Sequence__init(facer_interfaces__srv__DetectionResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  facer_interfaces__srv__DetectionResult_Response * data = NULL;

  if (size) {
    data = (facer_interfaces__srv__DetectionResult_Response *)allocator.zero_allocate(size, sizeof(facer_interfaces__srv__DetectionResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = facer_interfaces__srv__DetectionResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        facer_interfaces__srv__DetectionResult_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
facer_interfaces__srv__DetectionResult_Response__Sequence__fini(facer_interfaces__srv__DetectionResult_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      facer_interfaces__srv__DetectionResult_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

facer_interfaces__srv__DetectionResult_Response__Sequence *
facer_interfaces__srv__DetectionResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  facer_interfaces__srv__DetectionResult_Response__Sequence * array = (facer_interfaces__srv__DetectionResult_Response__Sequence *)allocator.allocate(sizeof(facer_interfaces__srv__DetectionResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = facer_interfaces__srv__DetectionResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
facer_interfaces__srv__DetectionResult_Response__Sequence__destroy(facer_interfaces__srv__DetectionResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    facer_interfaces__srv__DetectionResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
facer_interfaces__srv__DetectionResult_Response__Sequence__are_equal(const facer_interfaces__srv__DetectionResult_Response__Sequence * lhs, const facer_interfaces__srv__DetectionResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!facer_interfaces__srv__DetectionResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
facer_interfaces__srv__DetectionResult_Response__Sequence__copy(
  const facer_interfaces__srv__DetectionResult_Response__Sequence * input,
  facer_interfaces__srv__DetectionResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(facer_interfaces__srv__DetectionResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    facer_interfaces__srv__DetectionResult_Response * data =
      (facer_interfaces__srv__DetectionResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!facer_interfaces__srv__DetectionResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          facer_interfaces__srv__DetectionResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!facer_interfaces__srv__DetectionResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
