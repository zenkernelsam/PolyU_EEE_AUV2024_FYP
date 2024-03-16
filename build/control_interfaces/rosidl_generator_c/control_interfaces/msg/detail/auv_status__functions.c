// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from control_interfaces:msg/AUVStatus.idl
// generated code does not contain a copyright notice
#include "control_interfaces/msg/detail/auv_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `task_name`
// Member `thruster_direction`
// Member `buoyancy_direction`
#include "rosidl_runtime_c/string_functions.h"

bool
control_interfaces__msg__AUVStatus__init(control_interfaces__msg__AUVStatus * msg)
{
  if (!msg) {
    return false;
  }
  // task_name
  if (!rosidl_runtime_c__String__init(&msg->task_name)) {
    control_interfaces__msg__AUVStatus__fini(msg);
    return false;
  }
  // thruster_direction
  if (!rosidl_runtime_c__String__init(&msg->thruster_direction)) {
    control_interfaces__msg__AUVStatus__fini(msg);
    return false;
  }
  // buoyancy_direction
  if (!rosidl_runtime_c__String__init(&msg->buoyancy_direction)) {
    control_interfaces__msg__AUVStatus__fini(msg);
    return false;
  }
  // buoyancy_setpoint
  // buoyancy_now_depth
  return true;
}

void
control_interfaces__msg__AUVStatus__fini(control_interfaces__msg__AUVStatus * msg)
{
  if (!msg) {
    return;
  }
  // task_name
  rosidl_runtime_c__String__fini(&msg->task_name);
  // thruster_direction
  rosidl_runtime_c__String__fini(&msg->thruster_direction);
  // buoyancy_direction
  rosidl_runtime_c__String__fini(&msg->buoyancy_direction);
  // buoyancy_setpoint
  // buoyancy_now_depth
}

bool
control_interfaces__msg__AUVStatus__are_equal(const control_interfaces__msg__AUVStatus * lhs, const control_interfaces__msg__AUVStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // task_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->task_name), &(rhs->task_name)))
  {
    return false;
  }
  // thruster_direction
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->thruster_direction), &(rhs->thruster_direction)))
  {
    return false;
  }
  // buoyancy_direction
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->buoyancy_direction), &(rhs->buoyancy_direction)))
  {
    return false;
  }
  // buoyancy_setpoint
  if (lhs->buoyancy_setpoint != rhs->buoyancy_setpoint) {
    return false;
  }
  // buoyancy_now_depth
  if (lhs->buoyancy_now_depth != rhs->buoyancy_now_depth) {
    return false;
  }
  return true;
}

bool
control_interfaces__msg__AUVStatus__copy(
  const control_interfaces__msg__AUVStatus * input,
  control_interfaces__msg__AUVStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // task_name
  if (!rosidl_runtime_c__String__copy(
      &(input->task_name), &(output->task_name)))
  {
    return false;
  }
  // thruster_direction
  if (!rosidl_runtime_c__String__copy(
      &(input->thruster_direction), &(output->thruster_direction)))
  {
    return false;
  }
  // buoyancy_direction
  if (!rosidl_runtime_c__String__copy(
      &(input->buoyancy_direction), &(output->buoyancy_direction)))
  {
    return false;
  }
  // buoyancy_setpoint
  output->buoyancy_setpoint = input->buoyancy_setpoint;
  // buoyancy_now_depth
  output->buoyancy_now_depth = input->buoyancy_now_depth;
  return true;
}

control_interfaces__msg__AUVStatus *
control_interfaces__msg__AUVStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  control_interfaces__msg__AUVStatus * msg = (control_interfaces__msg__AUVStatus *)allocator.allocate(sizeof(control_interfaces__msg__AUVStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(control_interfaces__msg__AUVStatus));
  bool success = control_interfaces__msg__AUVStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
control_interfaces__msg__AUVStatus__destroy(control_interfaces__msg__AUVStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    control_interfaces__msg__AUVStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
control_interfaces__msg__AUVStatus__Sequence__init(control_interfaces__msg__AUVStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  control_interfaces__msg__AUVStatus * data = NULL;

  if (size) {
    data = (control_interfaces__msg__AUVStatus *)allocator.zero_allocate(size, sizeof(control_interfaces__msg__AUVStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = control_interfaces__msg__AUVStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        control_interfaces__msg__AUVStatus__fini(&data[i - 1]);
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
control_interfaces__msg__AUVStatus__Sequence__fini(control_interfaces__msg__AUVStatus__Sequence * array)
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
      control_interfaces__msg__AUVStatus__fini(&array->data[i]);
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

control_interfaces__msg__AUVStatus__Sequence *
control_interfaces__msg__AUVStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  control_interfaces__msg__AUVStatus__Sequence * array = (control_interfaces__msg__AUVStatus__Sequence *)allocator.allocate(sizeof(control_interfaces__msg__AUVStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = control_interfaces__msg__AUVStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
control_interfaces__msg__AUVStatus__Sequence__destroy(control_interfaces__msg__AUVStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    control_interfaces__msg__AUVStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
control_interfaces__msg__AUVStatus__Sequence__are_equal(const control_interfaces__msg__AUVStatus__Sequence * lhs, const control_interfaces__msg__AUVStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!control_interfaces__msg__AUVStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
control_interfaces__msg__AUVStatus__Sequence__copy(
  const control_interfaces__msg__AUVStatus__Sequence * input,
  control_interfaces__msg__AUVStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(control_interfaces__msg__AUVStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    control_interfaces__msg__AUVStatus * data =
      (control_interfaces__msg__AUVStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!control_interfaces__msg__AUVStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          control_interfaces__msg__AUVStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!control_interfaces__msg__AUVStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
