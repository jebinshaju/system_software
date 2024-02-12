#include<sys/socket.h>
#include<netdb.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(int argc,char* argv[])
{
	struct sockaddr_in client;
	if (argc != 3)
	{
		printf("Input format not connect");
	}
	int sockfd = socket(AF_INET,SOCK_DGRAM,0);
	if (sockfd ==-1)
	{
		printf("Error in socket creation");
	}
	
	client.sin_family = AF_INET;
	client.sin_addr.s_addr = INADDR_ANY;
	client.sin_port = htons(atoi(argv[2]));
	
	char buffer[100];
	printf("Enter message to be send to server: ");
	fgets(buffer,100,stdin);
	
	if(sendto(sockfd,buffer,sizeof(buffer),0,(struct sockaddr*)&client,sizeof(client)),0)
	{
		printf("Error in sending");
	}
	return 0;
}

/**
user@user:~/$ gcc udpclient.c -o client
user@user:~/$ ./client localhost 8080
Enter message to be send to server: hii this is from client 
**/
