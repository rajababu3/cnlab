#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>

int main()
{
	int cont,create_socket,new_socket,fd,addrelen;
	int bufsize=1024;
	char *buffer = malloc(bufsize);
	char fname[256];
	struct sockaddr_in address;

	if((create_socket=socket(AF_INET,SOCK_STREAM,0))>0)
		printf("\n Socket Created\n");
	address.sin_family = AF_INET;
	address.sin_addr.s_addr= INADDR_ANY;
	address.sin_port = htons(15000);
	if((bind(create_socket,(struct sockaddr *)&address, sizeof(address)))==0)
		printf("\n Binding Socket\n");
	listen(create_socket,3);
	addrelen=sizeof(struct sockaddr_in);
	new_socket=accept(create_socket, (struct sockaddr *)&address, &addrelen);
	if(new_socket > 0)
		printf("\n Connected");
	recv(new_socket,fname,256,0);
	fd=open(fname,O_RDONLY);
	while((cont=read(fd,buffer,bufsize))>0)
		send(new_socket,buffer,cont,0);
	printf("\n Request Completed\n");
	close(new_socket);
	return close(create_socket);
}