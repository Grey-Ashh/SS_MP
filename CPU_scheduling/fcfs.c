#include<stdio.h>

int main()
{
    int n;
    printf("Enter the no of processes: ");
    scanf("%d",&n);
    int p[n],at[n],bt[n],ct[n],tat[n],wt[n];
    int i,j,temp1,temp2,temp3;
    float avgtat,avgwt;
    printf("Enter the AT in order: ");
    for (i=0;i<n;i++)
    {
        scanf("%d",&at[i]);
        p[i]=i;
    }
    printf("Enter the BT in order: ");
    for (i=0;i<n;i++)
        scanf("%d",&bt[i]);
    
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(at[j]>at[j+1])
            {
                temp1=p[j];
                p[j]=p[j+1];
                p[j+1]=temp1;

                temp2=at[j];
                at[j]=at[j+1];
                at[j+1]=temp2;

                temp3=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp3;
            }
        }
    }
    
    ct[0]=at[0]+bt[0];
    for(i=1;i<n;i++)
    {
        int temp=0;
        if(at[i]>ct[i-1])
        {
            temp=at[i]-ct[i-1];
        }
        ct[i]=ct[i-1]+bt[i]+temp;
    }

    for(i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }

    printf("the table is: \n");
    printf("No\tAT\tBT\tCT\tTAT\tWT\n");
    for (i=0;i<n;i++)
    {
	printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    avgtat=0;
    avgwt=0;
    for(i=0;i<n;i++)
    {
	avgtat+=tat[i];
	avgwt+=wt[i];
    }
    printf("\nAvarage TAT=%f\nAvarage WT=%f\n",avgtat/n,avgwt/n);
}
