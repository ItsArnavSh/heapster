#ifndef FREE_H
#define FREE_H
#include <stdint.h>
#include "util.h"
//There are 4 classes of free memory
//A >=19 Bytes
//B 10-18 Bytes
//C 3-9 Bytes
//D 1,2 Bytes

void* createFreeA(void* memory,uint16_t size);
void release(void* mem);
#endif
