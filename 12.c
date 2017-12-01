#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#define bucketSize 1000

void abc(int a, int b)
{
	if(a>bucketSize)
		printf("\nBucket Overflow\n");
	else
	{
		usleep(500000);
		while(a>b){
			printf("\n%d bytes outputed", b);
			a-=b;
			usleep(500000);
		}
		if(a>0){
			printf("\n \t Last %d bytes outputed\n",a);
			printf("\n Output Success");
		}
	}
}

int main()
{
	int op,pktSize;
	int i;
	printf("\nEnter output rate: ");
	scanf("%d", &op);
	for(i=1;i<=5;i++){
		usleep(rand()%5000000);
		pktSize=random()%1250;
		printf("\n Packet Number %d \t Paket Size %d ", i,pktSize);
		abc(pktSize,op);
	}
}