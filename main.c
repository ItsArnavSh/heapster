#include "main.h"
#include "allocate.h"
#include "util.h"
#include "debug.h"
#include "memory.h"
int main(){
    startUP();
    void* mem = alloc(50);
    printMemory();
    release(mem);
    printf("after free:\n");
    printMemory();
}
