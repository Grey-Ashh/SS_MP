#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i,diff;
	int seek=0;
	printf("Enter the size: ");
	scanf("%d",&n);
	int mem[n+1];
	printf("Enter the items: ");
	for(i=1;i<n+1;i++)	
	{
		scanf("%d",&mem[i]);
	}
	printf("Enter the initial head position: ");
	scanf("%d",&mem[0]);
	for(i=0;i<n;i++)
	{
		printf("%d->",mem[i]);
		if(i!=n-2)
		{
			printf(" -> ");
		}
		diff=abs(mem[i+1]-mem[i]);
		seek+=diff;
	}
	printf("Seek time= %d\n",seek);
	return 0;
}
