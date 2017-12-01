#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd,cont,create_socket,new_socket,addrelen;
	int buffSize = 1024;
	char fname[256];
	char *buffer = malloc(buffSize);
	struct sockaddr_in address;
	if((create_socket=socket(AF_INET,SOCK_STREAM,0))>0)
		printf("\n Socket was Created");
	address.sin_family=AF_INET;
	address.sin_addr.s_addr=INADDR_ANY;
	address.sin_port = htons(15000);
	if(bind(create_socket,(struct sockaddr *)&address, sizeof(address))==0)
		printf("\n Biniding socket");
	listen(create_socket,3);
	addrelen=sizeof(struct sockaddr_in);
	new_socket=accept(create_socket,(struct sockaddr*)&address, &addrelen);
	if(new_socket>0)
		printf("\n Connected to the client");
	recv(new_socket,fname,255,0);
	printf("\n Client has requested for the file %s \n", fname);
	if((fd=open(fname,O_RDONLY))<0){
		perror("\n File Not Found\n");
		exit(0);
	}else{
		while((cont=read(fd,buffer,buffSize))>0){
			send(new_socket,buffer,cont,0);
		}
	}
	printf("\n Finished Tranferring File\n\n");
	close(new_socket);
	return close(create_socket);
}