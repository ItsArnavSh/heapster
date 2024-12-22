#include "main.h"
#include "allocate.h"
#include "util.h"
#include "debug.h"
#include "memory.h"
int main(){
    startUP();
    uint16_t size = 4;
    uint8_t* mem1 = (uint8_t*)alloc(size);
    uint8_t* mem2 = (uint8_t*)alloc(size);
    uint8_t* mem3 = (uint8_t*)alloc(size);
    uint8_t* mem4 = (uint8_t*)alloc(size);
    //release(mem1);
    release(mem2);
    release(mem3);
    printMemory();
}
