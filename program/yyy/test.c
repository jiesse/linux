#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, const char *argv[])
{
    int i = 0;
    int len = 0;
    char buff[4]= "";
    write(STDOUT_FILENO,"---",4);
    for (i = 0; i < 1000; i++) 
    {
        sprintf(buff,"%d",i);
        len = strlen(buff);
        write(STDOUT_FILENO,buff,len);
        usleep(10000);
        write(STDOUT_FILENO,"\b\b\b\b",len);
    }

    return 0;
}
