#include "kernel/types.h"
#include "kernel/param.h"
#include "user/user.h"

int main(int argc, char *argv[]){
    int pid,count=0;
    char *execargv[MAXARG],buf[100];
    for(int i = 1; i < argc; i++){
        execargv[i-1] = argv[i];
    }
    while(read(0,&buf[count++],sizeof(char))){
        if(buf[count-1] == '\n'){
            buf[count-1] = '\0';
            execargv[argc-1] = buf;
            execargv[argc] = 0;
            count=0;
            // 每行创建一个子进程运行
            pid = fork();
            if(pid == 0){
                exec(execargv[0], execargv);
                printf("exec failed!\n");
                exit(1);
            } else {
                wait((int *) 0);
            }
        }
    }
    exit(0);
}