#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netdb.h>

int main(int argc,char* argv[])
{
	struct sockaddr_in server;
	if (argc != 2)
	{
		printf("Input format not correct.");
	}
	
	int sockfd = socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd == -1)
	{
		printf("Error in socket creation.");
	}
	
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(atoi(argv[1]));
	
	if(bind(sockfd,(struct sockaddr*)&server,sizeof(server))<0)
	{
		printf("Error in binding.");
	}
	
	char buffer[100];
	printf("Server waiting.\n");
	
	int i=sizeof(server);
	int k=(recvfrom(sockfd,buffer,100,0,(struct sockaddr*)&server,&i));
  	if(k<0)
    		printf("error in receiving\n");
	printf("Got a datagram: %s",buffer);
	return 0;
}


/**
user@user:~/$ gcc udpserver.c -o server
user@user:~/$ ./server 8080
Server waiting.
Got a datagram: hii this is from client
**/
