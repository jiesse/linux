#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    
    int fd;
    off_t currpos;

    fd = open("aka_test",O_RDWR | O_CREAT, 0777);
    if(fd < 0)
    {
        perror("open /aka_test") ;
        exit(1);
    }
    currpos = lseek(fd,100,SEEK_END);
    write(fd, "hello",6);
    printf("%d\n",(int)currpos);
    if(currpos < 0)
    {
        perror("lseek aka_test") ;
        exit(1);
    }

    close(fd);


    return 0;
}
