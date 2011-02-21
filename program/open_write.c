#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>



int main(int argc, const char *argv[])
{
    int fd;
    char arr[256];
    struct stat buf;
    fd = open("akaedu",O_RDONLY);
    if(fd < 0)
    {
          printf("error\n");
          exit(-1);
    }
    fstat(fd,&buf);
    read(fd, arr, buf.st_size);
    close(fd);

    fd = open("aka",O_RDWR | O_CREAT, 0777);
    if(fd < 0)
    {
          printf("error\n");
          exit(-1);
    }

    write(fd, arr, buf.st_size);
    close(fd);
    
    return 0;
}
