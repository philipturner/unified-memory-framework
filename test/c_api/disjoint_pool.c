// Copyright (C) 2023 Intel Corporation
// Under the Apache License v2.0 with LLVM Exceptions. See LICENSE.TXT.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#include <stdlib.h>

#include "provider_null.h"
#include "test_helpers.h"
#include "umf/pools/pool_disjoint.h"

void test_disjoint_pool_default_params(void) {
    umf_memory_provider_handle_t provider = nullProviderCreate();
    enum umf_result_t retp;
    umf_memory_pool_handle_t pool = NULL;
    struct umf_disjoint_pool_params params = umfDisjointPoolParamsDefault();
    retp = umfPoolCreate(&UMF_DISJOINT_POOL_OPS, provider, &params, &pool);

    // TODO: use asserts
    if (retp != UMF_RESULT_SUCCESS) {
        abort();
    }

    umfPoolDestroy(pool);
    umfMemoryProviderDestroy(provider);
}

void test_disjoint_pool_shared_limits(void) {
    umf_memory_provider_handle_t provider = nullProviderCreate();
    enum umf_result_t retp;
    umf_memory_pool_handle_t pool = NULL;
    struct umf_disjoint_pool_params params = umfDisjointPoolParamsDefault();

    struct umf_disjoint_pool_shared_limits *limits =
        umfDisjointPoolSharedLimitsCreate(1024);
    params.SharedLimits = limits;

    retp = umfPoolCreate(&UMF_DISJOINT_POOL_OPS, provider, &params, &pool);

    // TODO: use asserts
    if (retp != UMF_RESULT_SUCCESS) {
        abort();
    }

    umfPoolDestroy(pool);
    umfMemoryProviderDestroy(provider);
    umfDisjointPoolSharedLimitsDestroy(limits);
}

int main(void) {
    test_disjoint_pool_default_params();
    return 0;
}
