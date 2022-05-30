#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[]){
    int n, pid, cpid,fd[2][2];
    char buf[100];
    // 双向通信需要两个管道
    pipe(fd[0]);
    pipe(fd[1]);
    pid = fork();
    if (pid == 0) {
        n = read(fd[1][0],buf,sizeof(buf));
        cpid = getpid();
        // write(fd[0][1],sprintf("%d: received ping\n",cpid),17);
        fprintf(fd[0][1],"%d: received ping\n",cpid);
        n = read(fd[1][0],buf,sizeof(buf));
        write(1,buf,n);
    } else {
        write(fd[1][1],"\n",1);
        n = read(fd[0][0],buf,sizeof(buf));
        write(1,buf,n);
        cpid = getpid();
        fprintf(fd[1][1],"%d: received pong\n",cpid);
    }
    exit(0);
}
