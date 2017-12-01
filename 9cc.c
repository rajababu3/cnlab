#include<sys/stat.h>
#include<netinet/in.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define FIFO1 "fifo1"
#define FIFO2 "fifo2"
#define PERMS 0666

char fname[256];

int main()
{
	ssize_t n;
	int readfd,writefd,fd;
	char buff[512];
	printf("\n Trying to connect to server\n");
	writefd=open(FIFO1,O_WRONLY,0);
	readfd=open(FIFO2,O_RDONLY,0);
	printf("\n Connected to the server");
	printf("\n Enter file name tio request from the server");
	scanf("%s", fname);
	write(writefd,fname,strlen(fname),0);
	while((n=read(readfd,buff,512))>0){
		write(1,buff,n);
	}
	printf("\n \n EOFn\n");
	return 0;
}