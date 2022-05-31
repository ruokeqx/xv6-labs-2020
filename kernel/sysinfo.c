#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "spinlock.h"
#include "proc.h"
#include "sysinfo.h"

int sysinfo(uint64 addr){
    struct proc *p = myproc();
    struct sysinfo info;
    info.freemem = freemem();
    info.nproc = procnum();
    if(copyout(p->pagetable, addr, (char *)&info, sizeof(info)) < 0)
      return -1;
    return 0;
}