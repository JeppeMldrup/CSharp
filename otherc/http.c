#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/types.h>
#include <netdb.h>
#include <unistd.h>

int main()
{
	struct addrinfo hints;
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;

	struct addrinfo *serverinfo;
	int status = getaddrinfo("www.example.com", "80", &hints, &serverinfo);
	
	int sockfd = socket(serverinfo->ai_family, serverinfo->ai_socktype, serverinfo->ai_protocol);

	char header[] = "GET /index.html HTTP/1.1\r\nHOST:example.org\r\n\r\n";

	if(connect(sockfd, serverinfo->ai_addr, serverinfo->ai_addrlen) < 0)
	{
		return -1;
	}
	
	write(sockfd, header, strlen(header));
	char buffer[2048];
	read(sockfd, buffer, 2048);
	printf("%s", buffer);

	printf("Press ENTER key to continue...\n");
	getchar();
	
	return 0;
}
