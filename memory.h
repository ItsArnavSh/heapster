#ifndef MEMORY_H
#define MEMORY_H
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <sys/mman.h>
#define ALLOCSIZE 12287
extern void* memStart;//For the entire memory
extern void* freeStart;//For the large free blocks
extern void* buckets[9];//For storing 10 to 18 bytes
#endif
