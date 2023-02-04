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



#include <ATen/ops/einsum_ops.h>

namespace at {


// aten::einsum(str equation, Tensor[] tensors) -> Tensor
TORCH_API inline at::Tensor einsum(c10::string_view equation, at::TensorList tensors) {
    return at::_ops::einsum::call(equation, tensors);
}

}
