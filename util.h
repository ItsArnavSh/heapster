#ifndef UTIL_H
#define UTIL_H
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
uint8_t noOfBits(uint16_t);
uint32_t getSize(void* loc);
uint32_t sizeCalc(uint32_t size);
uint32_t totalBytes(uint32_t num);
void* encode(void* loc,uint32_t totalSize,bool allocated);
uint32_t decodeSize(void* loc);
void printBinary(uint32_t num);
void getStatus(uint32_t num);
typedef struct chunkDetails{
    void* memStart;
    uint32_t TotalSize;
    uint32_t availableSize;
    uint8_t metaSize;
    bool status;
}chunkDetails;
chunkDetails getDetails(void* loc);
#endif
