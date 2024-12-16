#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>

int main() {
    size_t size = 1; // Allocate 4 KB (one page)

    // Use mmap to allocate memory
    void *memory = mmap(
        NULL,                // Let the kernel choose the address
        size,                // Size of the mapping
        PROT_READ | PROT_WRITE, // Memory is readable and writable
        MAP_PRIVATE | MAP_ANONYMOUS, // Private and not backed by a file
        -1,                  // No file descriptor needed
        0                    // Offset (irrelevant for anonymous mappings)
    );

    // Check if mmap failed
    if (memory == MAP_FAILED) {
        perror("mmap failed");
        return 1;
    }

    printf("Memory allocated at: %p\n", memory);

    // Use the memory
    strcpy((char *)memory, "Hello, mmap!");
    printf("Stored string: %s\n", (char *)memory);

    // Cleanup: Unmap the memory when done
    if (munmap(memory, size) == -1) {
        perror("munmap failed");
        return 1;
    }

    printf("Memory unmapped successfully.\n");
    return 0;
}
