#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>

#define FIFO1 "fifo1"
#define FIFO2 "fifo2"
#define PERMS 0666
char fname[256];
int main()
{
	int readfd,writefd;
	ssize_t n;
	char buff[512];
	printf("\n Trying for the connection\n");
	writefd=open(FIFO1, O_WRONLY,0);
	readfd=open(FIFO2, O_RDONLY,0);
	printf("\n connection Established\n");
	printf("\n Enter the filename to request from the server:\n");
	scanf("%s",fname);
	write(writefd,fname,strlen(fname));
	printf("\n Waiting for the server to reply\n");
	while((n=read(readfd,buff,512))>0)
		write(1,buff,n);

	close(readfd); 
	close(writefd); 
	return 0;
}