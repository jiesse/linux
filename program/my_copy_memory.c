#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>

#define N 2

int len_sub;
int len_end;

void my_cp_mem(int lensub, int fd_1, int fd_2, int i)
{

    int *p;
    int *q;

    lseek(fd_2, lensub-1, SEEK_CUR);
    write(fd_2,"c",1);


    p = mmap(NULL, lensub, PROT_READ, MAP_SHARED, fd_1, 0 );    

    q = mmap(NULL, lensub, PROT_WRITE, MAP_SHARED, fd_2, 0 );    

    memcpy(q,p,lensub);

    if(i == N-1)
    {
        lseek(fd_2, len_end-1, SEEK_CUR);
        write(fd_2,"c",1);
        
        p = mmap(NULL, len_end, PROT_READ, MAP_SHARED, fd_1, 0 );    

        q = mmap(NULL, len_end, PROT_WRITE, MAP_SHARED, fd_2, 0 );    

        memcpy(q,p,len_end);
        exit(1);

    }
}
void my_fork(int lensub_t, int fd_1, int fd_2, int i)
{
    int res;

    res = fork();

    if(res < 0)
    {
        perror("fork") ;
        exit(-1);
    }
    if(res > 0)
    {
        my_cp_mem(lensub_t,fd_1,fd_2,i);
        printf("this is %d process\n",i);
        wait(NULL);
    }
    if(res == 0)
    {
        // len_sub+=len_sub;
        my_cp_mem(lensub_t,fd_1,fd_2,i);
        printf("this is %d process\n",i+2);
    }

} 
int main(int argc, const char *argv[])
{

    int fd_1, fd_2;
    int len;
    int i;
    struct stat buf;

    fd_1 = open("file1",O_RDONLY);
    fd_2 = open("file2",O_RDWR | O_CREAT, 0777);

    fstat(fd_1, &buf);
    len = buf.st_size;
    printf("%d\n",len);
    len_sub = len/N;
    len_end = len%N;


    for (i = 0; i < N; i++) 
    {
        my_fork(len_sub,fd_1,fd_2,i);
    }


    close(fd_1);
    close(fd_2);
    return 0;
}








