#ifndef _SYSCALLS_H
#define _SYSCALLS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <errno.h>     // Ensure errno and ENOMEM are included
#include <stdint.h>    // Ensure uint8_t is defined
#include <stddef.h>    // For size_t


void *sbrk(size_t incr) {
  extern uint8_t __heap_base__;
  extern uint8_t __heap_end__;
  static uint8_t *p = &__heap_base__;
  static uint8_t *newp;

  newp = p + incr;
  if (newp > &__heap_end__) {
    errno = ENOMEM;
    return (void *)-1;
  }
  return p = newp;
}

// Dummy implementation for embedded systems

    // _exit: Immediate program termination
    void _exit(int status) {
        // Normally, you would reset the system or stop execution here
        while(1);  // Infinite loop to halt execution
    }

    // getpid: Return a dummy process ID
    int getpid(void) {
        return 1;  // Return a fixed process ID
    }

    // kill: Dummy implementation (does nothing)
    int kill(int pid, int sig) {
        return 0;  // Pretend it succeeded
    }



#ifdef __cplusplus
}
#endif

#endif
