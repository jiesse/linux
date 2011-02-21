#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define SERVER_PORD 20000
#define BUFFER_SIZE 10 

char buffer[BUFFER_SIZE];


int main(int argc, const char *argv[])
{

    int n, len;
    int fd;
    int client_sock;
    socklen_t server_len;
    struct sockaddr_in server;

    if(argc < 2)
    {
        printf("argument input error\n");
        exit(-1);

    }
    if((client_sock = socket(AF_INET, SOCK_STREAM,0)) < 0)
    {
        perror("socket") ;
        exit(-1);

    }
    else
    {
        printf("creat socket ok\n");

    }
    bzero(&server, sizeof(server));

    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORD);
    server.sin_addr.s_addr= inet_addr(argv[1]);

    server_len = sizeof(server);

    if(connect(client_sock,(struct sockaddr *)&server,server_len)<0)
    {
        perror("connect") ;
        exit(-1);

    }
    else
    {
        printf("connect ok\n");
    }

    fd = open("Linux C编程一站式学习6.14--宋劲衫.pdf", O_RDONLY ,0644);
    if(fd < 0)
    {
        perror("open") ;
        exit(-1);
    }

    while((len = read(fd ,buffer, BUFFER_SIZE)) > 0)
    {
            send(client_sock,buffer,len,0) ;

    }

    close(fd);
    sleep(1);
    close(client_sock);

    return 0;
}





