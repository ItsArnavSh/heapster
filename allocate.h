#ifndef ALLOCATE_H
#define ALLOCATE_H
#include <stdint.h>
#include "memory.h"
#include "util.h"
void* alloc(uint16_t);
void* shrink(uint16_t size,void* mem,chunkDetails data);
#endif
