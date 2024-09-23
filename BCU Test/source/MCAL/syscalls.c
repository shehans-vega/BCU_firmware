
#include <unistd.h>

// Stub implementation for _exit
void _exit(int status) {
    while (1) {
        // Loop indefinitely to halt the program
    }
}

// Stub implementation for sbrk
void* sbrk(int incr) {
    extern char _end; // Defined by the linker
    static char* heap_end; // Points to the end of the heap

    if (heap_end == 0) {
        heap_end = &_end; // Initialize heap_end
    }
    
    char* prev_heap_end = heap_end;
    heap_end += incr; // Move the heap pointer
    return (void*) prev_heap_end; // Return the old end of the heap
}

// Stub implementation for kill
int kill(int pid, int sig) {
    return -1; // Indicate failure
}

// Stub implementation for getpid
int getpid(void) {
    return 1; // Return a dummy process ID
}
