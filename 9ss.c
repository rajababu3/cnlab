#include<sys/stat.h>
#include<netinet/in.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>

#define FIFO1 "fifo1"
#define FIFO2 "fifo2"
#define PERMS 0666

char fname[256];

int main()
{
	ssize_t n;
	int readfd,writefd,fd;
	char buff[512];
	if((mkfifo(FIFO1,PERMS))<0)
		printf("\n Cannot create fifo fike");
	if((mkfifo(FIFO2,PERMS))<0)
		printf("\n Cannot create fifo file");
	printf("\n Waiting for the connection requested\n");
	readfd=open(FIFO1, O_RDONLY,0);
	writefd=open(FIFO2, O_WRONLY,0);

	printf("\nConnection Established");
	read(readfd, fname,255);
	printf("\n Client has requested for the file: %s", fname);
	fd=open(fname, O_RDWR);
	while((n=read(fd,buff,512))>0){
		write(writefd,buff,n);
	}
	printf("\n \n Request Completed\n\n");
	close(FIFO1);
	unlink(FIFO1);
	close(FIFO2);
	unlink(FIFO2);
	return 0;
}