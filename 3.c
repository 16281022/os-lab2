#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(){
    pid_t pid;
    pid = fork();
    if (pid == 0){
        pid = fork();
        if(pid > 0)
            fork(); 
    	printf ("pid = %d ppid = %d!\n",getpid(),getppid());
        sleep(1);
    }
    else if (pid > 0){
        fork();
    	printf ("pid = %d ppid = %d!\n",getpid(),getppid());
        sleep(1);
    }
    else if (pid == -1)
    	perror ("fork");
    return 0;
}

