// Server side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <netinet/in.h>

#define PORT	 8080
#define MAXLINE 1024

void reversestr(char *strng) 
{ 
  // declare variable 
  int i, len, temp; 
  len = strlen(strng); // use strlen() to get the length of str string 

  // use for loop to iterate the string 
  for (i = 0; i < len/2; i++) 
  { 
  // temp variable use to temporary hold the string 
   temp = strng[i]; 
   strng[i] = strng[len - i - 1]; 
   strng[len - i - 1] = temp; 
  } 
 } 
// Driver code
int main() {
	int sockfd;
	char buffer[MAXLINE];
	char *hello = "COnverted in bytes";
	struct sockaddr_in servaddr, cliaddr;
	
	// Creating socket file descriptor
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}
	
	//memset(&servaddr, 0, sizeof(servaddr));
	//memset(&cliaddr, 0, sizeof(cliaddr));
	
	// Filling server information
	servaddr.sin_family = AF_INET; // IPv4
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(PORT);
	
	// Bind the socket with the server address
	if ( bind(sockfd, (const struct sockaddr *)&servaddr,
			sizeof(servaddr)) < 0 )
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	
	int len, n;
	
	len = sizeof(cliaddr); //len is value/resuslt
	bool temp = true;
	while(true){
	n = recvfrom(sockfd, (char *)buffer, MAXLINE,
				0, ( struct sockaddr *) &cliaddr,
				&len);
	buffer[n] = '\0';
	if(strcmp(buffer,"exit") == 0){
		printf("Exiting the program(server)!");
		break;
	}
	reversestr(buffer);
	printf("Client : %s\n", buffer);
	sendto(sockfd, (const char *)hello, strlen(hello),
		0, (const struct sockaddr *) &cliaddr,
			len);
	}
	return 0;
}
