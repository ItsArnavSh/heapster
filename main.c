#include "main.h"
#include "allocate.h"
#include "util.h"
#include "debug.h"
#include "memory.h"
int main(){
    startUP();
    /*
    uint16_t size =2041;
    uint8_t* mem = (uint8_t*)alloc(size);
    uint8_t* start = mem-(decodeSize(mem)-size)/2;
    printDetails(getDetails(start));
    printDetails(getDetailsBack(start+getDetails(start).TotalSize-1));
    */
    uint16_t size = 10;
    uint8_t* mem1 = (uint8_t*)alloc(size);
    uint8_t* mem2 = (uint8_t*)alloc(size);
    uint8_t* mem3 = (uint8_t*)alloc(size);
    release(mem1);
    release(mem2);
    printMemory();
}
