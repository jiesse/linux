#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#define SERVER_PORT 20000
#define BUFFER_SIZE 256



char buffer[BUFFER_SIZE];

int main(int argc, const char *argv[])
{
    
    char c;
    int i, len, n;
    int server_sock, client_sock;
    socklen_t client_len;
    struct sockaddr_in server, client;
    struct in_addr in;

    if((server_sock = socket(AF_INET, SOCK_STREAM, 0))<0)
    {
        perror("socket") ;
        exit(-1);
    }
    else
    {
         printf("socket ok\n");
    }
    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);
    server.sin_addr.s_addr = htons(INADDR_ANY);

    if(bind(server_sock, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
    
        perror("bind");
        exit(-1);

    }
    else 
    {
         printf("bind ok\n");
    }

    if((listen(server_sock, 5))<0)
    {
        perror("listen") ;
        exit(-1);

    }
    else
    {
         printf("listen ok\n");
    }
    while(1)
    {
        client_len = sizeof(client) ;
        if((client_sock = accept(server_sock,(struct sockaddr *)&client, &client_len)) < 0)
        {
            close(server_sock) ;
            perror("accept");
            exit(-1);
        
        }
        else
        {
        
            printf("accept ok\n");
            in.s_addr = client.sin_addr.s_addr;

        }
        while((len = recv(client_sock, buffer, BUFFER_SIZE,0))> 0)
        {
             printf("%s\n",buffer);
        }
        close(client_sock);

    
    
    }
    close(server_sock);
    exit(1);

    return 0;
}






