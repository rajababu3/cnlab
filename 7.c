#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N strlen(g)

char cs[256],t[256],g[]="10001000000100001";
int a,e,c;

void xor(){
	for(c=1;c<N;c++){
		if(cs[c]==g[c])
			cs[c]='0';
		else
			cs[c]='1';
	}
}

void crc()
{
	for(e=0;e<N;e++) cs[e]=t[e];
	do{
		if(cs[0]=='1')
			xor();
		for(c=0;c<N-1;c++)
			cs[c]=cs[c+1];
		cs[c]=t[e++];
	}while(e<=a+N-1);
}

int main()
{
	printf("\nEnter Poly: ");
	scanf("%s",t);
	printf("\n Generating polynomial is: %s", g);
	a=strlen(t);
	for(e=a;e<a+N-1;e++)
		t[e]='0';
	printf("\nModified t[u] is %s ", t);
	crc();
	printf("\nChecksum is %s ", cs);
	for(e=a;e<a+N-1;e++)
		t[e]=cs[e-a];
	printf("\nFinal Codeword is %s ", t);
	printf("\n Test Error Detection (0) Yes and (1)No?: ");
	scanf("%d",&e);
	if(e==0){
		printf("\nEnter the position where error is to be inserted: ");
		scanf("%d",&e);
		if(t[e]=='0')
			t[e]='1';
		else
			t[e]='0';
		printf("\n Errornous data is %s ",t);
	}
	crc();
	for(e=0; (e<N-1)&&(cs[e]!='1'); e++);
	if(e<N-1)
		printf("\n Error detected\n");
	else
		printf("\n No Error detected");
	return 0;
}


















