#include "kernel/types.h"
#include "user/user.h"

// See kernel/sysproc.c for the xv6 kernel code that implements the sleep system call (look for sys_sleep), user/user.h for the C definition of sleep callable from a user program, and user/usys.S for the assembler code that jumps from user code into the kernel for sleep.
// user.h中的 int sleep(int); 在ulibc.c中实现了 所以导入user/user.h即可用sleep
int main(int argc, char *argv[]){
  if(argc < 2){
    printf("Error: input sleep time!");
    exit(0);
  }
  sleep(atoi(argv[1]));
  exit(0);
}
