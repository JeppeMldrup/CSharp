#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>

typedef struct server
{
    int listen_fd;
} server_t;

int server_listen(server_t* server)
{
    int err = 0;
    struct sockaddr_in server_addr; 

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(8080);

    err = (server->listen_fd = socket(
                AF_INET,
                SOCK_STREAM,
                0));
    if(err == -1)
    {
        printf("Failed to set up socket\n");
        return err;
    }

    err = bind(
            server->listen_fd,
            (struct sockaddr*)&server_addr,
            sizeof(server_addr));
    if(err == -1)
    {
        printf("Failed to bind socket to address\n");
        return err;
    }

    err = listen(server->listen_fd, 4);
    if(err == -1)
    {
        printf("Failed to start listening\n");
        return err;
    }
}

int server_accept(server_t* server)
{
    int err = 0;
    int conn_fd;
    struct sockaddr_in client_addr;
    socklen_t client_len;
    char buffer[10];
   
    client_len = sizeof(client_addr);

    err = (conn_fd = accept(
                server->listen_fd, 
                (struct sockaddr*)&client_addr, 
                &client_len));
    if(err == -1)
    {
        printf("Failed to accept connection\n");
        return err;
    }

    printf("Client connected\n");

    err = recv(
            conn_fd,
            &buffer,
            10,
            0);
    if(err == -1)
    {
        printf("Failed to read message\n");
        return err;
    }

    printf("Recieved: %s\n", buffer);

    err = close(conn_fd);
    if(err == -1)
    {
        printf("Failed to close connection\n");
        return err;
    }
}

int main(int argc, char *argv[])
{
    int err = 0;
    server_t server = { 0 };

    err = server_listen(&server);
    if(err)
    {
        printf("Failed to listen\n");
        return err;
    }

    for (;;)
    {
        err = server_accept(&server);
        if(err){
            printf("Failed to accept connection\n");
            return err;
        }
    }

    return 0;
}
