#pragma once

// @generated by torchgen/gen.py from Function.h

#include <ATen/Context.h>
#include <ATen/DeviceGuard.h>
#include <ATen/TensorUtils.h>
#include <ATen/TracerMode.h>
#include <ATen/core/Generator.h>
#include <ATen/core/Reduction.h>
#include <ATen/core/Tensor.h>
#include <c10/core/Scalar.h>
#include <c10/core/Storage.h>
#include <c10/core/TensorOptions.h>
#include <c10/util/Deprecated.h>
#include <c10/util/Optional.h>



#include <ATen/ops/_cudnn_init_dropout_state_ops.h>

namespace at {


// aten::_cudnn_init_dropout_state(float dropout, bool train, int dropout_seed, *, ScalarType? dtype=None, Layout? layout=None, Device? device=None, bool? pin_memory=False) -> Tensor
TORCH_API inline at::Tensor _cudnn_init_dropout_state(double dropout, bool train, int64_t dropout_seed, at::TensorOptions options) {
    return at::_ops::_cudnn_init_dropout_state::call(dropout, train, dropout_seed, optTypeMetaToScalarType(options.dtype_opt()), options.layout_opt(), options.device_opt(), options.pinned_memory_opt());
}

// aten::_cudnn_init_dropout_state(float dropout, bool train, int dropout_seed, *, ScalarType? dtype=None, Layout? layout=None, Device? device=None, bool? pin_memory=False) -> Tensor
TORCH_API inline at::Tensor _cudnn_init_dropout_state(double dropout, bool train, int64_t dropout_seed, c10::optional<at::ScalarType> dtype, c10::optional<at::Layout> layout, c10::optional<at::Device> device, c10::optional<bool> pin_memory) {
    return at::_ops::_cudnn_init_dropout_state::call(dropout, train, dropout_seed, dtype, layout, device, pin_memory);
}

}
