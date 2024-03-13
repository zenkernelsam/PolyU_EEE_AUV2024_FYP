// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from control_interfaces:srv/BuoyancyControl.idl
// generated code does not contain a copyright notice
#include "control_interfaces/srv/detail/buoyancy_control__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
control_interfaces__srv__BuoyancyControl_Request__init(control_interfaces__srv__BuoyancyControl_Request * msg)
{
  if (!msg) {
    return false;
  }
  // modify_depth
  // new_depth
  return true;
}

void
control_interfaces__srv__BuoyancyControl_Request__fini(control_interfaces__srv__BuoyancyControl_Request * msg)
{
  if (!msg) {
    return;
  }
  // modify_depth
  // new_depth
}

bool
control_interfaces__srv__BuoyancyControl_Request__are_equal(const control_interfaces__srv__BuoyancyControl_Request * lhs, const control_interfaces__srv__BuoyancyControl_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // modify_depth
  if (lhs->modify_depth != rhs->modify_depth) {
    return false;
  }
  // new_depth
  if (lhs->new_depth != rhs->new_depth) {
    return false;
  }
  return true;
}

bool
control_interfaces__srv__BuoyancyControl_Request__copy(
  const control_interfaces__srv__BuoyancyControl_Request * input,
  control_interfaces__srv__BuoyancyControl_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // modify_depth
  output->modify_depth = input->modify_depth;
  // new_depth
  output->new_depth = input->new_depth;
  return true;
}

control_interfaces__srv__BuoyancyControl_Request *
control_interfaces__srv__BuoyancyControl_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  control_interfaces__srv__BuoyancyControl_Request * msg = (control_interfaces__srv__BuoyancyControl_Request *)allocator.allocate(sizeof(control_interfaces__srv__BuoyancyControl_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(control_interfaces__srv__BuoyancyControl_Request));
  bool success = control_interfaces__srv__BuoyancyControl_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
control_interfaces__srv__BuoyancyControl_Request__destroy(control_interfaces__srv__BuoyancyControl_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    control_interfaces__srv__BuoyancyControl_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
control_interfaces__srv__BuoyancyControl_Request__Sequence__init(control_interfaces__srv__BuoyancyControl_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  control_interfaces__srv__BuoyancyControl_Request * data = NULL;

  if (size) {
    data = (control_interfaces__srv__BuoyancyControl_Request *)allocator.zero_allocate(size, sizeof(control_interfaces__srv__BuoyancyControl_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = control_interfaces__srv__BuoyancyControl_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        control_interfaces__srv__BuoyancyControl_Request__fini(&data[i - 1]);
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
control_interfaces__srv__BuoyancyControl_Request__Sequence__fini(control_interfaces__srv__BuoyancyControl_Request__Sequence * array)
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
      control_interfaces__srv__BuoyancyControl_Request__fini(&array->data[i]);
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

control_interfaces__srv__BuoyancyControl_Request__Sequence *
control_interfaces__srv__BuoyancyControl_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  control_interfaces__srv__BuoyancyControl_Request__Sequence * array = (control_interfaces__srv__BuoyancyControl_Request__Sequence *)allocator.allocate(sizeof(control_interfaces__srv__BuoyancyControl_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = control_interfaces__srv__BuoyancyControl_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
control_interfaces__srv__BuoyancyControl_Request__Sequence__destroy(control_interfaces__srv__BuoyancyControl_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    control_interfaces__srv__BuoyancyControl_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
control_interfaces__srv__BuoyancyControl_Request__Sequence__are_equal(const control_interfaces__srv__BuoyancyControl_Request__Sequence * lhs, const control_interfaces__srv__BuoyancyControl_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!control_interfaces__srv__BuoyancyControl_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
control_interfaces__srv__BuoyancyControl_Request__Sequence__copy(
  const control_interfaces__srv__BuoyancyControl_Request__Sequence * input,
  control_interfaces__srv__BuoyancyControl_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(control_interfaces__srv__BuoyancyControl_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    control_interfaces__srv__BuoyancyControl_Request * data =
      (control_interfaces__srv__BuoyancyControl_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!control_interfaces__srv__BuoyancyControl_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          control_interfaces__srv__BuoyancyControl_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!control_interfaces__srv__BuoyancyControl_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
control_interfaces__srv__BuoyancyControl_Response__init(control_interfaces__srv__BuoyancyControl_Response * msg)
{
  if (!msg) {
    return false;
  }
  // is_succeeded
  // now_depth
  return true;
}

void
control_interfaces__srv__BuoyancyControl_Response__fini(control_interfaces__srv__BuoyancyControl_Response * msg)
{
  if (!msg) {
    return;
  }
  // is_succeeded
  // now_depth
}

bool
control_interfaces__srv__BuoyancyControl_Response__are_equal(const control_interfaces__srv__BuoyancyControl_Response * lhs, const control_interfaces__srv__BuoyancyControl_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // is_succeeded
  if (lhs->is_succeeded != rhs->is_succeeded) {
    return false;
  }
  // now_depth
  if (lhs->now_depth != rhs->now_depth) {
    return false;
  }
  return true;
}

bool
control_interfaces__srv__BuoyancyControl_Response__copy(
  const control_interfaces__srv__BuoyancyControl_Response * input,
  control_interfaces__srv__BuoyancyControl_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // is_succeeded
  output->is_succeeded = input->is_succeeded;
  // now_depth
  output->now_depth = input->now_depth;
  return true;
}

control_interfaces__srv__BuoyancyControl_Response *
control_interfaces__srv__BuoyancyControl_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  control_interfaces__srv__BuoyancyControl_Response * msg = (control_interfaces__srv__BuoyancyControl_Response *)allocator.allocate(sizeof(control_interfaces__srv__BuoyancyControl_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(control_interfaces__srv__BuoyancyControl_Response));
  bool success = control_interfaces__srv__BuoyancyControl_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
control_interfaces__srv__BuoyancyControl_Response__destroy(control_interfaces__srv__BuoyancyControl_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    control_interfaces__srv__BuoyancyControl_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
control_interfaces__srv__BuoyancyControl_Response__Sequence__init(control_interfaces__srv__BuoyancyControl_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  control_interfaces__srv__BuoyancyControl_Response * data = NULL;

  if (size) {
    data = (control_interfaces__srv__BuoyancyControl_Response *)allocator.zero_allocate(size, sizeof(control_interfaces__srv__BuoyancyControl_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = control_interfaces__srv__BuoyancyControl_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        control_interfaces__srv__BuoyancyControl_Response__fini(&data[i - 1]);
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
control_interfaces__srv__BuoyancyControl_Response__Sequence__fini(control_interfaces__srv__BuoyancyControl_Response__Sequence * array)
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
      control_interfaces__srv__BuoyancyControl_Response__fini(&array->data[i]);
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

control_interfaces__srv__BuoyancyControl_Response__Sequence *
control_interfaces__srv__BuoyancyControl_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  control_interfaces__srv__BuoyancyControl_Response__Sequence * array = (control_interfaces__srv__BuoyancyControl_Response__Sequence *)allocator.allocate(sizeof(control_interfaces__srv__BuoyancyControl_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = control_interfaces__srv__BuoyancyControl_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
control_interfaces__srv__BuoyancyControl_Response__Sequence__destroy(control_interfaces__srv__BuoyancyControl_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    control_interfaces__srv__BuoyancyControl_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
control_interfaces__srv__BuoyancyControl_Response__Sequence__are_equal(const control_interfaces__srv__BuoyancyControl_Response__Sequence * lhs, const control_interfaces__srv__BuoyancyControl_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!control_interfaces__srv__BuoyancyControl_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
control_interfaces__srv__BuoyancyControl_Response__Sequence__copy(
  const control_interfaces__srv__BuoyancyControl_Response__Sequence * input,
  control_interfaces__srv__BuoyancyControl_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(control_interfaces__srv__BuoyancyControl_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    control_interfaces__srv__BuoyancyControl_Response * data =
      (control_interfaces__srv__BuoyancyControl_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!control_interfaces__srv__BuoyancyControl_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          control_interfaces__srv__BuoyancyControl_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!control_interfaces__srv__BuoyancyControl_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
