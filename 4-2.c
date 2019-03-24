#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	pid_t pid;
	pid = fork();
	if (pid > 0){
        fork();
    	while(1){
    	    printf ("%d I am the child of pid=%d!\n",getpid(),getppid());
            sleep(10);
        }

	}
	else if (pid == 0){
        pid = fork();
        if(pid > 0){
	    pid = fork();
	    printf ("%d I am the child of pid=%d!\n",getpid(),getppid());
	    sleep(1);
            if(pid > 0)
	        exit(0);		
	}		
    	while(1){
    	    printf ("%d I am the child of pid=%d!\n",getpid(),getppid());
            sleep(1);
        }
	}
	else if (pid == -1)
    	perror ("fork");
	return 0;
}

