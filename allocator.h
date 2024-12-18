#ifndef ALLOCATOR_H
#define ALLOCATOR_H
#include <stdint.h>
#include <sys/types.h>
#include "memStatus.h"
void* allocate(uint32_t bytes);
#endif
