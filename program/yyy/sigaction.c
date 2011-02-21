#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>


void fun(int i)
{
    printf("child process exit\n");
}



int main(int argc, const char *argv[])
{
    
    int res;
    struct sigaction child;
    child.sa_handler = fun;
    child.sa_flags = 0;
    sigemptyset(&child.sa_mask);

    sigaction(SIGCHLD, &child, NULL);
    sigaction(SIGINT, &child, NULL);

    if((res =fork()) < 0)
    {
        perror("fork")  ;
        exit(-1);
    
    }
    if(res > 0)
    {
        while(1)
        {
        sleep(1) ;
        printf("hello world\n");
        }
    
    }
    else 
    {
        sleep(5) ;
    }



    return 0;
}
