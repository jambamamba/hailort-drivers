// SPDX-License-Identifier: GPL-2.0
/**
 * Copyright (c) 2019-2022 Hailo Technologies Ltd. All rights reserved.
 **/

#ifndef _HAILO_COMMON_HAILO_RESOURCE_H_
#define _HAILO_COMMON_HAILO_RESOURCE_H_

#include "types.h"

struct hailo_resource {
    uintptr_t   address;
    size_t      size;
};

#ifdef __cplusplus
extern "C" {
#endif

// Implemented by the specific platform
uint32_t hailo_resource_read32(struct hailo_resource *resource, size_t offset);
uint16_t hailo_resource_read16(struct hailo_resource *resource, size_t offset);
uint8_t hailo_resource_read8(struct hailo_resource *resource, size_t offset);
void hailo_resource_write32(struct hailo_resource *resource, size_t offset, uint32_t value);
void hailo_resource_write16(struct hailo_resource *resource, size_t offset, uint16_t value);
void hailo_resource_write8(struct hailo_resource *resource, size_t offset, uint8_t value);

void hailo_resource_read_buffer(struct hailo_resource *resource, size_t offset, size_t count, void *to);
int hailo_resource_write_buffer(struct hailo_resource *resource, size_t offset, size_t count, const void *from);

// Transfer (read/write) the given resource into/from transfer params.
int hailo_resource_transfer(struct hailo_resource *resource, struct hailo_memory_transfer_params *transfer);

#ifdef __cplusplus
}
#endif

#endif /* _HAILO_COMMON_HAILO_RESOURCE_H_ */