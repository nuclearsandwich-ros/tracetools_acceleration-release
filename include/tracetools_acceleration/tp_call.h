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

// Provide fake header guard for cpplint
#undef TRACETOOLS_ACCELERATION__TP_CALL_H_
#ifndef TRACETOOLS_ACCELERATION__TP_CALL_H_
#define TRACETOOLS_ACCELERATION__TP_CALL_H_

#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER ros2_acceleration

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "tracetools_acceleration/tp_call.h"

#if !defined(_TRACETOOLS_ACCELERATION__TP_CALL_H_) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define _TRACETOOLS_ACCELERATION__TP_CALL_H_

#include <lttng/tracepoint.h>

#include <stdint.h>
#include <stdbool.h>


// Silly examples for simple vadd kernel instrumentation and benchmarking
// of acceleration_examples
TRACEPOINT_EVENT(
  TRACEPOINT_PROVIDER,  // tracepoint provider name
  vadd_pre,             // tracepoint name
  TP_ARGS(              // input arguments, see https://lttng.org/docs/v2.12/#doc-tpp-def-input-args
    const char *, iteration_arg
  ),
  TP_FIELDS(            // output event fields, see https://lttng.org/man/3/lttng-ust/v2.12/#doc-ctf-macros
    ctf_string(iteration, iteration_arg)
    ctf_string(version, tracetools_acceleration_VERSION)  // dump the version of the package
  )
)

TRACEPOINT_EVENT(
  TRACEPOINT_PROVIDER,
  vadd_post,
  TP_ARGS(
    const char *, iteration_arg
  ),
  TP_FIELDS(
    ctf_string(iteration, iteration_arg)
    ctf_string(version, tracetools_acceleration_VERSION)  // dump the version of the package
  )
)

// ros2_kria packages for proprioception
//// power
TRACEPOINT_EVENT(
  TRACEPOINT_PROVIDER,  // tracepoint provider name
  kria_power,             // tracepoint name
  TP_ARGS(              // input arguments, see https://lttng.org/docs/v2.12/#doc-tpp-def-input-args
    const double, power_arg
  ),
  TP_FIELDS(            // output event fields, see https://lttng.org/man/3/lttng-ust/v2.12/#doc-ctf-macros
    ctf_float(double, power, power_arg)
    ctf_string(version, tracetools_acceleration_VERSION)  // dump the version of the package
  )
)

TRACEPOINT_EVENT(
  TRACEPOINT_PROVIDER,  // tracepoint provider name
  kria_power_dt,        // tracepoint name
  TP_ARGS(              // input arguments, see https://lttng.org/docs/v2.12/#doc-tpp-def-input-args
    const double, power_arg,
    const double, dt_arg
  ),
  TP_FIELDS(            // output event fields, see https://lttng.org/man/3/lttng-ust/v2.12/#doc-ctf-macros
    ctf_float(double, power, power_arg)
    ctf_float(double, dt, dt_arg)
    ctf_string(version, tracetools_acceleration_VERSION)  // dump the version of the package
  )
)

//// voltage
TRACEPOINT_EVENT(
  TRACEPOINT_PROVIDER,  // tracepoint provider name
  kria_voltage,             // tracepoint name
  TP_ARGS(              // input arguments, see https://lttng.org/docs/v2.12/#doc-tpp-def-input-args
    const double, voltage_arg
  ),
  TP_FIELDS(            // output event fields, see https://lttng.org/man/3/lttng-ust/v2.12/#doc-ctf-macros
    ctf_float(double, voltage, voltage_arg)
    ctf_string(version, tracetools_acceleration_VERSION)  // dump the version of the package
  )
)
//// current
TRACEPOINT_EVENT(
  TRACEPOINT_PROVIDER,  // tracepoint provider name
  kria_current,             // tracepoint name
  TP_ARGS(              // input arguments, see https://lttng.org/docs/v2.12/#doc-tpp-def-input-args
    const double, current_arg
  ),
  TP_FIELDS(            // output event fields, see https://lttng.org/man/3/lttng-ust/v2.12/#doc-ctf-macros
    ctf_float(double, current, current_arg)
    ctf_string(version, tracetools_acceleration_VERSION)  // dump the version of the package
  )
)

#endif  // _TRACETOOLS_ACCELERATION__TP_CALL_H_

#include <lttng/tracepoint-event.h>

#endif  // TRACETOOLS_ACCELERATION__TP_CALL_H_
