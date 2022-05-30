#include "kernel/types.h"
#include "user/user.h"

void prime(int* p){
    int primenum,num,fd[2],pid;
    if(read(p[0], &primenum,sizeof(primenum)) == 0){ // != 1 无输出 因为是4
        exit(0);
    }
    printf("prime %d\n",primenum);
    pipe(fd);
    while(read(p[0], &num,sizeof(num))){
        if (num % primenum != 0){
            write(fd[1],&num,sizeof(num));
        }
    }
    pid = fork();
    if (pid == 0){
        close(fd[1]);
        prime(fd);
        close(fd[0]);
    }else{
        close(fd[0]); // fd[0] for read; father don't need read
        close(fd[1]); // already write all data
        wait((int *) 0);
    }
    exit(0);
}

int main(int argc, char *argv[]){
    int fd[2],pid;
    pipe(fd);
    for (int i=2;i<=35;i++){
        write(fd[1],&i,sizeof(i));
    }

    pid = fork();
    if (pid == 0){
        close(fd[1]);
        prime(fd);
        close(fd[0]);
    }else{
        close(fd[0]); // fd[0] for read; father don't need read
        close(fd[1]); // already write all data
        wait((int *) 0);
    }
    exit(0);
}
