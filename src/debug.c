#include "debug.h"
#include "memory.h"
#include "util.h"
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
void printDetails(chunkDetails data) {
    printf("\n---------------------\n");
    printf("Chunk Details:\n");
    printf("Memory Start Address: %p\n", data.memStart);
    printf("Total Size: %u bytes\n", data.TotalSize);
    printf("Available Size: %u bytes\n", data.availableSize);
    printf("Metadata Size: %u bytes\n", data.metaSize);
    printf("Status: %s\n", data.status ? "Free" : "Allocated");
    printf("---------------------\n");
}
void analyseChunk(void* memory){
    //Assume we got to the start of a chunk and now we will break it down
    chunkDetails data = getDetails(memory);

}
void printMemory(){
    uint8_t *loc = memStart;
    chunkDetails data;
    data = getDetails(loc);
    while(data.TotalSize!=0){
        printDetails(data);
        loc += data.TotalSize+1;
        data = getDetails(loc);
    }
}
