#include "main.h"
#include "allocate.h"
#include "util.h"
#include "debug.h"
#include "memory.h"
int main(){
    startUP();
    void* mem = alloc(50);
    void* mem2 = alloc(50);
    release(mem);
    printMemory();
}
