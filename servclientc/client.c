#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    int err = 0;
    int sockfd;
    struct sockaddr_in sock_addr;
    socklen_t sock_len;
    char *buffer = "Hello!";

    sock_len = sizeof(sock_addr);

    sock_addr.sin_family = AF_INET;
    sock_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    sock_addr.sin_port = htons(8080);

    err = (sockfd = socket(
                AF_INET,
                SOCK_STREAM,
                0
                ));
    if(err == -1)
    {
        printf("Failed to set up socket\n");
        return err;
    }

    err = connect(
            sockfd,
            (struct sockaddr*)&sock_addr,
            sock_len
            );
    if(err == -1)
    {
        printf("Failed to connect\n");
        return err;
    }

    printf("Connected to server!\n");

    err = send(sockfd, &buffer, strlen(buffer), 0);
    if(err == -1)
    {
        printf("Failed to send message\n");
        return err;
    }

    printf("Sent: %s\n", buffer);

    return 0;
}
