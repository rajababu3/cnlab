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
	int readfd,writefd,fd;
	ssize_t n;
	char buff[512];
	if(mkfifo(FIFO1,PERMS)<0)
		printf("Error");
	if(mkfifo(FIFO2,PERMS)<0)
		printf("Error");
	printf("\n Waiting for the connection\n");
	readfd=open(FIFO1, O_RDONLY,0);
	writefd=open(FIFO2, O_WRONLY,0);
	printf("\n connection Established\n");
	read(readfd,fname,255);
	printf("\n Client has requested file %s", fname);
	fd=open(fname,O_RDWR);
	while((n=read(fd,buff,512))>0)
		write(writefd,buff,n);

	close(readfd); unlink(FIFO1);
	close(writefd); unlink(FIFO2);
}