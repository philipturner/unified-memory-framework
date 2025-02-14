// Copyright (C) 2023 Intel Corporation
// Under the Apache License v2.0 with LLVM Exceptions. See LICENSE.TXT.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef UMF_NULL_PROVIDER_H
#define UMF_NULL_PROVIDER_H

#include <umf/memory_provider.h>

#if defined(__cplusplus)
extern "C" {
#endif

extern struct umf_memory_provider_ops_t UMF_NULL_PROVIDER_OPS;

#if defined(__cplusplus)
}
#endif

#endif // UMF_NULL_PROVIDER_H
