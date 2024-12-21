#include "main.h"
#include "allocate.h"
#include "util.h"
#include "debug.h"
#include "memory.h"
int main(){
    startUP();
    alloc(100);
    alloc(200);
    printMemory();
}
