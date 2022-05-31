#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "spinlock.h"
#include "proc.h"

int trace(int mask){
    struct proc *p = myproc();
    p->mask = mask;
    return 0;
}