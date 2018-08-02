#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>

#define maxClients 9
#define bytes 1024

typedef struct Clients{
    char id;
    int client_fd;
    struct sockaddr_in client_addr;
} client;
 
int main(int argc, char *argv[])
{
    int err = 0;
    struct sockaddr_in server_addr, buffer_addr;
    int listen_fd, buffer_fd;
    char input, buffer[bytes], message[bytes];
    client client[maxClients];

    socklen_t client_len;
    client_len = sizeof(buffer_addr);

    err = (listen_fd = socket(
                AF_INET,
                SOCK_STREAM,
                0));
    if(err == -1)
    {
        printf("Failed to set up socket\n");
        return err;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(8000);

    err = bind(listen_fd,
            (struct sockaddr*)&server_addr,
            sizeof(server_addr));
    if(err == -1)
    {
        printf("Failed to bind socket to address\n");
        return err;
    }

    err = listen(listen_fd, 4);
    if(err == -1)
    {
        printf("Failed to start listening\n");
        return err;
    }

    for (;;)
    {
        memset(&buffer_fd, 0, sizeof(buffer_fd));
        err = (buffer_fd = accept(listen_fd,
                (struct sockaddr*)&buffer_addr,
                &client_len));
        if(err < 0)
        {
            printf("Failed to accept connection from client\n");
            return err;
        }

        if(&buffer_fd != 0) //if a connection is accepted add it to the list
        {
            for(int i = 0; i < maxClients; ++i)
            {
                if(&client[i].id != NULL) //checking client space is taken
                    continue;
                client[i].client_fd = buffer_fd;
                printf("Client connected\n");
                
                client[i].id = (char)i; //store id tag
                send(client[i].client_fd, &client[i].id, 1, 0); //send id tag
            }
        }
        for(int i = 0; i < maxClients; ++i)
        {
            while(1)  //check for messages sent by clients
            {
                if((err = recv(client[i].client_fd, &buffer, bytes, 0) == 0))
                    break;
                else if(err == -1)
                {
                    printf("Failed to read message\n");
                    return err;
                }
            }

            memcpy(message, &buffer[1], bytes-1); //copy message from buffer
            
            if(buffer[0] != '\0')
            {
                printf("\nRecieved: %s", buffer);
                for(int i = 0; i < maxClients; ++i)
                {
                    if(buffer[0] == i)
                        continue;
                    else if(&client[i].id == NULL)
                        continue;

                    send(client[i].client_fd, &message, strlen(message), 0);
                }
            }
            else
                printf("Failed to recieve message\n");

            if(read(STDIN_FILENO, &input, 1) ==   0)
                continue;
            else if(input == 'q')
                return 0;
        }   
    }

    return 0;
}

int sendToAllBut(char id, char message[bytes], struct Clients client[maxClients])
{
}

/*Pseudocode
 *
 * class client
 * {
 *      socket client_socket;
 *      int id;
 *      addr socket_addr;
 * }
 *
 * main()
 * {
 *      int err
 *      socket serv_socket;
 *      client clients[maxClients];
 *      socket buffer_socket;
 *      socketlen_t socketlen;
 *
 *      serv_socket = socket();
 *      serv_socket = bind();
 *      serv_socket = listen();
 *
 *      while(1)
 *      {
 *          if((buffer_socket = acceptconnection()) != -1)
 *          {
 *              for(int i = 0; i < maxClients; ++i)
 *              {
 *                  if(client[i] == null){
 *                      client[i].client_socket = &buffer_socket;
 *                      client[i].id = i;
 *                      sendToClient(i, i);
 *                      break;
 *                  }
 *                  else
 *                      continue;
 *              }
 *          }
 *          for(int i = 0; i < maxClients; ++i)
 *          {
 *              if((recv(clients[i].client_socket, buffer_message, messageLength)) != -1)
 *              {
 *                  if(buffermessage[0] == i)
 *                  {
 *                      copy(message, buffermessage[1], messageLength-1);
 *                      sendMsgToAllBut(message, i);
 *                  }
 *                  else
 *                      sendMsg(clients[i], "Invalid message");
 *              }
 *          }
 *      }
 * }
 *
 */
