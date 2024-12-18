//We will just see when the OS causes a Seg Fault
//It will occur only when we run out of the storage IT has given us
#include <stdint.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
void segfaultHandler(int sig,siginfo_t *info,void *context){
    printf("Segmentation fault occurred!\n");
    printf("Faulting address: %p\n", info->si_addr);
    exit(1);
}
void signalCreater(){
    struct sigaction sa;
    sa.sa_sigaction = segfaultHandler;  // Use the custom handler
    sa.sa_flags = SA_SIGINFO;  // Use the siginfo_t structure
    sigemptyset(&sa.sa_mask);  // No additional signals to block during the handler
    if (sigaction(SIGSEGV, &sa, NULL) == -1) {
        perror("sigaction failed");
    }
}
//Now we will create a function that will simply take in the size to make and will before crashing give away the size that was actually created
void crasher(uint32_t size){
    char *memory = mmap(NULL,size,PROT_READ | PROT_WRITE,MAP_PRIVATE | MAP_ANONYMOUS,-1,0);
    printf("Starting memory is: %p\n",memory);
    while(1){
        *(memory--) = 'A';//Just fill it up with As
    }
}
int main() {
    // Set up the signal handler for SIGSEGV (segfault)
    signalCreater();

    crasher(1);

    return 0;
}
