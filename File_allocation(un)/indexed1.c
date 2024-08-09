#include<stdio.h>
#include<string.h>
struct file
{
	char name[20];
	int nob, blocks[30];
} f[30];
int main()
{
	int i, j, n;
	char s[20];
	printf("Enter no of files : ");
	scanf("%d",&n);
	for(i=0; i<n; i++)
	{
		printf("\nEnter file name %d :",i+1);
		scanf("%s",f[i].name);
		printf("Enter no of blocks in file %d :",i+1);
		scanf("%d",&f[i].nob);
		printf("Enter the blocks of the file :");
		for(j=0; j<f[i].nob; j++)
			scanf("%d",&f[i].blocks[j]);
	}
	printf("\nEnter the file name to be searched : ");
	scanf("%s",s);
	for(i=0; i<n; i++)
		if(strcmp(s, f[i].name)==0)
			break;
	if(i==n)
		printf("\nFile Not Found");
	else
	{
		printf("\nFILE NAME NO OF BLOCKS BLOCKS OCCUPIED");
		printf("\n %s\t\t%d\t",f[i].name,f[i].nob);
		for(j=0; j<f[i].nob; j++)
			printf("%d, ",f[i].blocks[j]);
	}
	return 0;
}
