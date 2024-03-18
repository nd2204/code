#ifndef DN_MEMORY_H
#define DN_MEMORY_H

#include "defines.h"

typedef enum memory_tag
{
    MEMORY_TAG_UNKNOWN,
    MEMORY_TAG_NODE,
    MEMORY_TAG_MAX_TAGS,
} memory_tag;

void memory_system_initialize();
void memory_system_shutdown();
void* dn_allocate(u64 size, memory_tag tag);
const char* get_memory_unit(u64 size_in_byte, f32 *out_amount);
void print_mem_usage();
void dn_free(void* block);

#endif // DN_MEMORY_H
