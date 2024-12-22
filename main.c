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
    uint16_t size = 20;
    uint8_t* mem1 = (uint8_t*)alloc(size);
    uint8_t* mem2 = (uint8_t*)alloc(size);
    uint8_t* mem3 = (uint8_t*)alloc(size);
    release(mem1);
    for(uint8_t *i=mem1-1;i<mem3;i++){
      //  printBinary(*i);
    }
    //printf("\n\n");
    //printBinary(*(mem2-3));
    //printf("\n\n%d\n",totalBytes(decodeSize(mem2)));
    //printBinary(*(mem2-totalBytes(decodeSize(mem2))));
    //printDetails(getDetailsBack(mem2-totalBytes(decodeSize(mem2))-2));
    release(mem2);
    printMemory();
}
