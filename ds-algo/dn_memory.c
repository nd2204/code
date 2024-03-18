#include "dn_memory.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KIBIBYTES 1024
#define MEBIBYTES 1024 * 1024
#define GIBIBYTES 1024 * 1024 * 1024

typedef struct memory_stat {
    u64 total_allocated;
    u64 tagged_allocations[MEMORY_TAG_MAX_TAGS];
} memory_stat;

static memory_stat* state_ptr = NULL;

static const char* memory_tag_strings[MEMORY_TAG_MAX_TAGS] = {
    "UNKNOWN",
    "NODE   ",
};

void memory_system_initialize() {
    if (!state_ptr)
    {
        state_ptr = malloc(sizeof(memory_stat));
        state_ptr->total_allocated = 0;
        memset(state_ptr->tagged_allocations, 0, sizeof(state_ptr->tagged_allocations));
    }
}

void memory_system_shutdown()
{
    if(state_ptr)
    {
        free(state_ptr);
    }
}

void dn_free(void* block)
{
    if (block) {
        free(block);
    }
}

void* dn_allocate(u64 size, memory_tag tag) {
    if (state_ptr)
    {
        state_ptr->total_allocated += size;
        state_ptr->tagged_allocations[tag] += size;
    }
    return malloc(size);
}

const char* get_memory_unit(u64 size_in_byte, f32 *out_amount)
{
    if (size_in_byte >= GIBIBYTES) {
        *out_amount = (f32)size_in_byte/GIBIBYTES;
        return "GiB";
    } else if (size_in_byte >= MEBIBYTES) {
        *out_amount = (f32)size_in_byte/MEBIBYTES;
        return "MiB";
    } else if (size_in_byte >= KIBIBYTES) {
        *out_amount = (f32)size_in_byte/MEBIBYTES;
        return "KiB";
    } else {
        *out_amount = (f32)size_in_byte;
        return "B";
    }
}

void print_mem_usage()
{
    if (!state_ptr) {
        printf("memory system not initialized");
        return;
    }
    char buffer[8000] = "Total memory allocated:\n";
    i32 offset = strlen(buffer);
    for (int i = 0; i < MEMORY_TAG_MAX_TAGS; ++i)
    {
        f32 amount = 0.0f;
        const char* unit = get_memory_unit(state_ptr->tagged_allocations[i], &amount);
        if (state_ptr->tagged_allocations[i] < 1024)
            offset = offset + snprintf(buffer + offset, 8000,"%s: %d%s\n",memory_tag_strings[i], (i32)amount, unit);
        else
            offset = offset + snprintf(buffer + offset, 8000,"%s: %.2f%s\n",memory_tag_strings[i], amount, unit);
    }
    printf("%s", buffer);
}
