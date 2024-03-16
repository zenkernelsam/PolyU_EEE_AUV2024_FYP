// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from control_interfaces:msg/AUVBuoyancy.idl
// generated code does not contain a copyright notice
#include "control_interfaces/msg/detail/auv_buoyancy__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
control_interfaces__msg__AUVBuoyancy__init(control_interfaces__msg__AUVBuoyancy * msg)
{
  if (!msg) {
    return false;
  }
  // now_depth
  return true;
}

void
control_interfaces__msg__AUVBuoyancy__fini(control_interfaces__msg__AUVBuoyancy * msg)
{
  if (!msg) {
    return;
  }
  // now_depth
}

bool
control_interfaces__msg__AUVBuoyancy__are_equal(const control_interfaces__msg__AUVBuoyancy * lhs, const control_interfaces__msg__AUVBuoyancy * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // now_depth
  if (lhs->now_depth != rhs->now_depth) {
    return false;
  }
  return true;
}

bool
control_interfaces__msg__AUVBuoyancy__copy(
  const control_interfaces__msg__AUVBuoyancy * input,
  control_interfaces__msg__AUVBuoyancy * output)
{
  if (!input || !output) {
    return false;
  }
  // now_depth
  output->now_depth = input->now_depth;
  return true;
}

control_interfaces__msg__AUVBuoyancy *
control_interfaces__msg__AUVBuoyancy__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  control_interfaces__msg__AUVBuoyancy * msg = (control_interfaces__msg__AUVBuoyancy *)allocator.allocate(sizeof(control_interfaces__msg__AUVBuoyancy), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(control_interfaces__msg__AUVBuoyancy));
  bool success = control_interfaces__msg__AUVBuoyancy__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
control_interfaces__msg__AUVBuoyancy__destroy(control_interfaces__msg__AUVBuoyancy * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    control_interfaces__msg__AUVBuoyancy__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
control_interfaces__msg__AUVBuoyancy__Sequence__init(control_interfaces__msg__AUVBuoyancy__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  control_interfaces__msg__AUVBuoyancy * data = NULL;

  if (size) {
    data = (control_interfaces__msg__AUVBuoyancy *)allocator.zero_allocate(size, sizeof(control_interfaces__msg__AUVBuoyancy), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = control_interfaces__msg__AUVBuoyancy__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        control_interfaces__msg__AUVBuoyancy__fini(&data[i - 1]);
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
control_interfaces__msg__AUVBuoyancy__Sequence__fini(control_interfaces__msg__AUVBuoyancy__Sequence * array)
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
      control_interfaces__msg__AUVBuoyancy__fini(&array->data[i]);
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

control_interfaces__msg__AUVBuoyancy__Sequence *
control_interfaces__msg__AUVBuoyancy__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  control_interfaces__msg__AUVBuoyancy__Sequence * array = (control_interfaces__msg__AUVBuoyancy__Sequence *)allocator.allocate(sizeof(control_interfaces__msg__AUVBuoyancy__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = control_interfaces__msg__AUVBuoyancy__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
control_interfaces__msg__AUVBuoyancy__Sequence__destroy(control_interfaces__msg__AUVBuoyancy__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    control_interfaces__msg__AUVBuoyancy__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
control_interfaces__msg__AUVBuoyancy__Sequence__are_equal(const control_interfaces__msg__AUVBuoyancy__Sequence * lhs, const control_interfaces__msg__AUVBuoyancy__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!control_interfaces__msg__AUVBuoyancy__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
control_interfaces__msg__AUVBuoyancy__Sequence__copy(
  const control_interfaces__msg__AUVBuoyancy__Sequence * input,
  control_interfaces__msg__AUVBuoyancy__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(control_interfaces__msg__AUVBuoyancy);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    control_interfaces__msg__AUVBuoyancy * data =
      (control_interfaces__msg__AUVBuoyancy *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!control_interfaces__msg__AUVBuoyancy__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          control_interfaces__msg__AUVBuoyancy__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!control_interfaces__msg__AUVBuoyancy__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
