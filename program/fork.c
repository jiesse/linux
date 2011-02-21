#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, const char *argv[])
{

    int res, res_fork, res_child;
    res = fork();
    if(res < 0)
    {
        perror("fork") ;
        exit(-1);
    }
    if(res > 0)
    {
        /*
           res_fork = fork();
           if(res_fork > 0)
           {
           while(1) { sleep(1) ;printf("this is parent\n");}
           }
           else
           {
           while(1) { sleep(1) ;printf("this is parent's 2 child\n");}
           }
           */

        printf("parent\n");
        wait(NULL);
    }
    if(res == 0)
    {
        while(1)
        {
            sleep(1);
            printf("error\n");
        }

        /*
           res_child = fork();
           if(res_child > 0)
           {
           while(1) { sleep(1) ;printf("this is child\n");}
           }
           else
           {
           while(1) { sleep(1) ;printf("this is child's child\n");}
           }
           */
    }
    return 0;
}
