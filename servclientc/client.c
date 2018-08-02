#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>

#define bytes 1024

int main(int argc, char *argv[])
{
    int err = 0;
    int sockfd;
    struct sockaddr_in sock_addr;
    socklen_t sock_len;
    char buffer[bytes], tempBuf[bytes], id;

    sock_len = sizeof(sock_addr);

    sock_addr.sin_family = AF_INET;
    sock_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    sock_addr.sin_port = htons(8000);

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
    
    read(sockfd, &id, 1); //recieve id

    printf("Type message to send to server: ");
    read(STDIN_FILENO, tempBuf, bytes);
    buffer[0] = id;
    strcat(buffer, tempBuf); //join id and message together

    err = send(sockfd, &buffer, strlen(buffer), 0); //send message and id
    if(err == -1)
    {
        printf("Failed to send message\n");
        return err;
    }

    printf("Sent: %s\n", buffer);

    return 0;
}
