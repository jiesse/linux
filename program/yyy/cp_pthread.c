#include <stdio.h>
#include <pthread.h>

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>

#include <stdlib.h>

#include <string.h>
#include <unistd.h>
int fd_old, fd_new;
int len;
char buff[256];
int file_len;
int count = 0;
char *q;
char *p;
int i;
int n;
struct stat buffer_new;

void* fun(void *arg)
{

    int k = 0;
    int j = 0;
    k = i;
   
    if(k == n )
    {

        memcpy(q+k*len,p+k*len,file_len%len);
        //sleep(1);
        return (void*)count;
         
    }
    memcpy(q+k*len,p+k*len,len); return (void *)count;
    /*
    for (j = k*len; j < (k+1)*len; j++) 
    {
         
        *(q+j) = *(p+j);
    }
    */

}

void *prt(void *arg)
{
    int res = 0; 
    int len_s = 0;
    char buffer[6] = "";
    while(1)
    {
        
        fstat(fd_new, &buffer_new);
        count = buffer_new.st_size;

        res =(int) ((count*100)/file_len);
        sprintf(buffer,"%d%c",res,'%');
        len_s = strlen(buffer);
        write(STDOUT_FILENO,buffer,len_s);
        usleep(1);
        write(STDOUT_FILENO,"\b\b\b\b\b",len_s);
        if(res == 100)break;
        
    }
    return NULL;

}
int main(int argc, const char *argv[])
{

    struct stat buffer;

    void *tret;

    pthread_t pth[10];
    pthread_t time;


    fd_old = open(argv[1], O_RDONLY);

    fd_new = open(argv[2], O_RDWR | O_CREAT , 0777);
    n = atoi(argv[3]);
    printf("%d\n",n);

    fstat(fd_old, &buffer);
    file_len = buffer.st_size;


    printf("%d\n",file_len);
    len = file_len/n;
    p = mmap(NULL, file_len, PROT_READ, MAP_SHARED, fd_old, 0 );    
    q = mmap(NULL, file_len, PROT_WRITE, MAP_SHARED, fd_new, 0 );    

    write(STDOUT_FILENO,"------",6);

    pthread_create(&time, NULL, prt, NULL);
    
    for (i = 0; i < n+1; i++) 
    {

        if(i == n)
        {
            lseek(fd_new,file_len%len-1,SEEK_CUR);
            write(fd_new,"c",1);
        
        }
        else
        {
            lseek(fd_new,len-1,SEEK_CUR);
            write(fd_new,"c",1);
        
        }
        pthread_create(&pth[i], NULL, fun, NULL);
        //printf("this is pthread %d\n",i);
    }
    for (i = 0; i < n+1; i++) 
    {
        pthread_join(pth[i],&tret);

    }
    pthread_join(time,&tret);

    close(fd_old);
    close(fd_new);

    printf("\n");

    return 0;
}
