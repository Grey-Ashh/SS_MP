
#include<stdio.h>
int main()
{
	int at[10],bt[10],pr[10];
        int n,i,j,temp,time=0,count,over=0,sum_wait=0,sum_turnaround=0,start;
        float avgwait,avgturn;
        printf("Enter the number of processes: ");
        scanf("%d",&n);
	printf("Enter the AT in order: ");
    	for (i=0;i<n;i++)
    	{
        	scanf("%d",&at[i]);
        	pr[i]=i;
    	}
    	printf("Enter the BT in order: ");
    	for (i=0;i<n;i++)
        	scanf("%d",&bt[i]);

        for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(at[i]>at[j])
			{
					temp=at[i];
					at[i]=at[j];
                                        at[j]=temp;
                                        temp=bt[i];
                                        bt[i]=bt[j];
                                        bt[j]=temp;
                                        temp=pr[i];
                                        pr[i]=pr[j];
                                        pr[j]=temp;     
                         }                   
                 }
	}
        //printf("\n\nProcess\t|Arrival time\t|Execution time\t|Start time\t|End time\t|waiting                                     time\t|Turnaround time\n\n");
	printf("No\tAT\tBT\tCT\tTAT\tWT\n");
            while(over<n)
            {
		count=0;
		for(i=over;i<n;i++)
                {
                	if(at[i]<=time)
                	        count++;
                        else
                	        break;
                        }
                        if(count>1)
                        {
                        	for(i=over;i<over+count-1;i++)
                                {
                                	for(j=i+1;j<over+count;j++)
                                        {
                                        	if(bt[i]>bt[j])
                                                {
                                                	temp=at[i];
                                                        at[i]=at[j];
                                                        at[j]=temp;
                                                        temp=bt[i];
                                                        bt[i]=bt[j];
                                                        bt[j]=temp;
                                                        temp=pr[i];
                                                        pr[i]=pr[j];
                                                        pr[j]=temp;     
                                                 }
                                        }                     
                                 }
                        }
                        time+=bt[over];
                        //printf("p[%d]\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\n",pr[over],
                        //            at[over],bt[over],start,time,time-at[over]-bt[over],time-at[over]);
			printf("%d\t%d\t%d\t%d\t%d\t%d\n",pr[over],at[over],bt[over],time,time-at[over],time-at[over]-bt[over]);
                        sum_wait+=time-at[over]-bt[over];
                        sum_turnaround+=time-at[over];
                        over++;
            }
            avgwait=(float)sum_wait/(float)n;
            avgturn=(float)sum_turnaround/(float)n;
            printf("Average waiting time is %f\n",avgwait);
            printf("Average turnaround time is %f\n",avgturn);
            return 0;
} 
