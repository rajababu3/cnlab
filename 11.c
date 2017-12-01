#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int gcd(long m, long n)
{
	long r;
	while(n!=0)
	{
		r=m%n;
		m=n;
		n=r;
	}
	return m;
}

int main()
{
	long elems=0,i=0,phi=0,p=0,q=0,n=0,d=0,j=0,e=0;
	char message[256];
	long encrypted[100]={0}, dec[100]={0};

	printf("\nEnter Message: ");
	scanf("%s",message);
	printf("\n Enter Two Large Prime Numbers: P and Q: ");
	scanf("%ld%ld",&p,&q);
	n=p*q;
	phi=(p-1)*(q-1);
	printf("\n N=%ld, Phi=%ld\n", n, phi);
	for(i=2;i<phi;i++)
		if(gcd(i,phi)==1){
			break;
		}
	e=i;
	printf("\n Encryption Key(Public Key) is %ld",e);
	for(i=2;i<phi;i++){
		if((e*i-1)%phi==0)
			break;
	}
	d=i;
	printf("\n Dec Key(Private Key) is %ld ", d);
	elems=strlen(message);
	for(i=0;i<elems;i++){
		encrypted[i]=1;
		for(j=0;j<e;j++)
			encrypted[i]=(encrypted[i]*message[i])%n;
	}
	printf("\n  Message in Numbers: \t");
	for(i=0;i<elems;i++)
		printf("%d ",message[i]);
	printf("\n Enc Message in Numbers: \t");
	for(i=0;i<elems;i++)
		printf("%ld ",encrypted[i]);

	for(i=0;i<elems;i++){
		dec[i]=1;
		for(j=0;j<d;j++)
			dec[i]=(dec[i]*encrypted[i])%n;
	}

	printf("\n Dec Message in Numbers: \t");
	for(i=0;i<elems;i++)
		printf("%ld ",dec[i]);
	printf("\n Original Message:");
	for(i=0;i<elems;i++)
		printf("%c ",(char)dec[i]);
	printf("\n");

	return 0;
}