#pragma once

// @generated by torchgen/gen.py from NativeFunction.h

#include <c10/core/Scalar.h>
#include <c10/core/Storage.h>
#include <c10/core/TensorOptions.h>
#include <c10/util/Deprecated.h>
#include <c10/util/Optional.h>
#include <c10/core/QScheme.h>
#include <ATen/core/Reduction.h>
#include <ATen/core/Tensor.h>
#include <tuple>
#include <vector>


namespace at {
namespace native {

TORCH_API at::Tensor sspaddmm(const at::Tensor & self, const at::Tensor & mat1, const at::Tensor & mat2, const at::Scalar & beta=1, const at::Scalar & alpha=1);
TORCH_API at::Tensor & _sspaddmm_out_only_sparse(const at::Tensor & self, const at::Tensor & mat1, const at::Tensor & mat2, const at::Scalar & beta, const at::Scalar & alpha, at::Tensor & out);
TORCH_API at::Tensor & _sspaddmm_out_only_sparse_cuda(const at::Tensor & self, const at::Tensor & mat1, const at::Tensor & mat2, const at::Scalar & beta, const at::Scalar & alpha, at::Tensor & out);
TORCH_API at::Tensor & _sspaddmm_out_cpu(const at::Tensor & self, const at::Tensor & mat1, const at::Tensor & mat2, const at::Scalar & beta, const at::Scalar & alpha, at::Tensor & out);
TORCH_API at::Tensor & _sspaddmm_out_cuda(const at::Tensor & self, const at::Tensor & mat1, const at::Tensor & mat2, const at::Scalar & beta, const at::Scalar & alpha, at::Tensor & out);

} // namespace native
} // namespace at
