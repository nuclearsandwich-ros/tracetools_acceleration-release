/*
    ____  ____
   /   /\/   /
  /___/  \  /   Copyright (c) 2021, Xilinx®.
  \   \   \/    Author: Víctor Mayoral Vilches <victorma@xilinx.com>
   \   \
   /   /
  /___/   /\
  \   \  /  \
   \___\/\___\

Inspired by https://gitlab.com/ros-tracing/ros2_tracing

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

/** \mainpage tracetools_acceleration: tracing tools and instrumentation for ROS 2
 *  Hardware Acceleration Working Group.
 *
 * `tracetools_acceleration` provides utilities to instrument ROS 2 selected packages
 *  that demonstrate hardware acceleration.
 *
 * It provides two main headers:
 *
 * - tracetools/tracetools.h
 *   - instrumentation functions
 * - tracetools/utils.hpp
 *   - utility functions
 */

#ifndef TRACETOOLS_ACCELERATION__TRACETOOLS_H_
#define TRACETOOLS_ACCELERATION__TRACETOOLS_H_

#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "tracetools_acceleration/config.h"
#include "tracetools_acceleration/visibility_control.hpp"

#ifndef TRACETOOLS_DISABLED
/// Call a tracepoint.
/**
 * This is the preferred method over calling the actual function directly.
 */
#  define TRACEPOINT(event_name, ...) \
  (ros_trace_ ## event_name)(__VA_ARGS__)
#  define DECLARE_TRACEPOINT(event_name, ...) \
  TRACETOOLS_PUBLIC void ros_trace_ ## event_name(__VA_ARGS__);
#else
#  define TRACEPOINT(event_name, ...) ((void) (0))
#  define DECLARE_TRACEPOINT(event_name, ...)
#endif

#ifdef __cplusplus
extern "C"
{
#endif

/// Get tracing compilation status.
/**
 * \return `true` if tracing is enabled, `false` otherwise
 */
TRACETOOLS_PUBLIC bool ros_trace_compile_status();

/// `vadd_pre`
/**
 * Tracepoint before calling vadd acceleration kernel
 *
 * Notes the `tracetools_acceleration` version automatically.
 *
 * \param[in] iteration string with iteration number
 */
DECLARE_TRACEPOINT(
  vadd_pre,
  const char * iteration)


/// `vadd_post`
/**
 * Tracepoint after calling vadd acceleration kernel
 *
 * Notes the `tracetools` version automatically.
 *
 * \param[in] iteration string with iteration number
 */
DECLARE_TRACEPOINT(
  vadd_post,
  const char * iteration)


/// `kria_power`
/**
 * Tracepoint to trace power
 *
 * Notes the `tracetools` version automatically.
 *
 * \param[in] power value
 */
DECLARE_TRACEPOINT(
  kria_power,
  const double power)


/// `kria_power_dt`
/**
 * Tracepoint to trace power, includes the differential time value
 * computed from the CPU loop. This might be re-calculated based on
 * on the tracing information.
 *
 * Notes the `tracetools` version automatically.
 *
 * \param[in] power value
 */
DECLARE_TRACEPOINT(
  kria_power_dt,
  const double power,
  const double dt)

/// `kria_voltage`
/**
 * Tracepoint to trace voltage
 *
 * Notes the `tracetools` version automatically.
 *
 * \param[in] voltage value
 */
DECLARE_TRACEPOINT(
  kria_voltage,
  const double voltage)


/// `kria_current`
/**
 * Tracepoint to trace current
 *
 * Notes the `tracetools` version automatically.
 *
 * \param[in] current value
 */
DECLARE_TRACEPOINT(
  kria_current,
  const double current)

#ifdef __cplusplus
}
#endif

#endif  // TRACETOOLS_ACCELERATION__TRACETOOLS_H_
