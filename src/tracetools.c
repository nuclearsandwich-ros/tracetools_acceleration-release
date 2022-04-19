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

#include "tracetools_acceleration/tracetools.h"

#ifndef TRACETOOLS_DISABLED

#ifdef TRACETOOLS_LTTNG_ENABLED
# include "tracetools_acceleration/tp_call.h"
# define CONDITIONAL_TP(...) \
  tracepoint(TRACEPOINT_PROVIDER, __VA_ARGS__)
#else
# define CONDITIONAL_TP(...)
#endif

bool ros_trace_compile_status()
{
#ifdef TRACETOOLS_LTTNG_ENABLED
  return true;
#else
  return false;
#endif
}

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
#else
# pragma warning(push)
# pragma warning(disable: 4100)
#endif

// Silly examples for simple vadd kernel
void TRACEPOINT(
  vadd_pre,
  const char * iteration)
{
  CONDITIONAL_TP(
    vadd_pre,
    iteration);
}

void TRACEPOINT(
  vadd_post,
  const char * iteration)
{
  CONDITIONAL_TP(
    vadd_post,
    iteration);
}

// ros2_kria packages for proprioception
void TRACEPOINT(
  kria_power,
  const double power)
{
  CONDITIONAL_TP(
    kria_power,
    power);
}

void TRACEPOINT(
  kria_power_dt,
  const double power,
  const double dt)
{
  CONDITIONAL_TP(
    kria_power_dt,
    power,
    dt);
}

void TRACEPOINT(
  kria_voltage,
  const double voltage)
{
  CONDITIONAL_TP(
    kria_voltage,
    voltage);
}

void TRACEPOINT(
  kria_current,
  const double current)
{
  CONDITIONAL_TP(
    kria_current,
    current);
}

#ifndef _WIN32
# pragma GCC diagnostic pop
#else
# pragma warning(pop)
#endif

#endif  // TRACETOOLS_DISABLED
