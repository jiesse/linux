#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    int res;

    res = fork();
    if(res < 0)
    {
        perror("fork") ;
        exit(1);
    
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
            sleep(3) ;
            kill(getppid(),9);
            printf("kill ok\n");

    }
    return 0;
}
