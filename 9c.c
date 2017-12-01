#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	int create_socket,cont;
	int bufsize=1024;
	char *buffer = malloc(bufsize);
	char fname[256];
	struct sockaddr_in address;

	if((create_socket=socket(AF_INET,SOCK_STREAM,0))>0)
		printf("\n Socket Cretaed");
	address.sin_family=AF_INET;
	address.sin_port = htons(15000);
	if((connect(create_socket,(struct sockaddr *)&address, sizeof(address)))==0)
		printf("\n Connection accepted %s ", argv[1]);
	printf("\n Enter the file name to request: ");
	scanf("%s", fname);
	send(create_socket,fname,sizeof(fname),0);
	printf("\n Request accepted\n Receiving file\n");
	while((cont=recv(create_socket,buffer,bufsize,0))>0){
		write(1,buffer,cont);
	}
	printf("\nEOF\n");
	return close(create_socket);
}