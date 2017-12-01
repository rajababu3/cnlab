#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<netinet/in.h>

int main(int argc, char  *argv[])
{
	int create_socket,cont;
	int buffSize=1024;
	char *buffer = malloc(buffSize);
	char fname[256];
	struct sockaddr_in address;

	if((create_socket=socket(AF_INET,SOCK_STREAM,0))>0)
		printf("\n The Socket was created");
	address.sin_family=AF_INET;
	address.sin_port=htons(15000);

	if((connect(create_socket,(struct sockaddr*)&address,sizeof(address)))==0)
		printf("\n Connection Established");
	printf("\n Enter filename to request from the server: ");
	scanf("%s", fname);
	send(create_socket,fname,sizeof(fname),0);
	while((cont=recv(create_socket,buffer,buffSize,0))>0){
		write(1,buffer,cont);
	}
	printf("\n\nEOF\n\n");
	return close(create_socket); 
}