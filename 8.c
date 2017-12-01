#include<stdio.h>
#include<stdlib.h>

struct node
{
	int dist[20];
	int from[20];
}rt[10];

int main()
{
	int dmat[25][25];
	int n,i,j,k,count;
	printf("\nEnter number of nides: ");
	scanf("%d",&n);
	printf("\nEnter Cost Matrix: \n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			scanf("%d",&dmat[i][j]);
			dmat[i][i]=0;
			rt[i].dist[j]=dmat[i][j];
			rt[i].from[j]=j;
		}
	do
	{
		count=0;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				for(k=0;k<n;k++){
					if(rt[i].dist[j]>dmat[i][k]+rt[k].dist[j]){
						rt[i].dist[j]=dmat[i][k]+rt[k].dist[j];
						rt[i].from[j]=k;
						count++;
					}
				}
	}while(count!=0);
	for(i=0;i<n;i++)
	{
		printf("\nState Value for router %d is\n", i);
		for(j=0;j<n;j++){
			printf("\n\t\tVia router %d, distance is %d ", rt[i].from[j], rt[i].dist[j]);
		}
	}
	return 0;
}