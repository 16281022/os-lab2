#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
 
int main()
{
    pid_t pid;
    pid = fork ();
    if ( pid == 0 )       // 子进程
    {
        int ret;
        ret = execl ("/usr/bin/vi", "vi","/home/zhy/2.c", NULL);
        if (ret == -1)
           perror ("execl");
        printf ("I am the baby!\n");
    }
    else if( pid > 0)
    {
        printf ("I am the parent of pid=%d!\n", pid);
        while(1){
        }
    }
    return 0;
}


