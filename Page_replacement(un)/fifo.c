    #include <stdio.h>  
    int main()  
    {  
        int pageFaults = 0;  
        int frames;  
        int m, n, s,i, pages;     
        
        
        printf("Enter the no of pages : ");
	scanf("%d",&pages);
	int incomingStream[pages]; 
	printf("Enter the page referance string: ");
	for(i=0;i<pages;i++)
		scanf("%d",&incomingStream[i]);
	printf("Enter the no of frames : ");
	scanf("%d",&frames);
	printf("Incoming");
        for(int x=0;x<frames;x++)
        	 printf(" \t\t Frame %d ",x+1); 
        int temp[frames];  
        for(m = 0; m < frames; m++)  
        {  
            temp[m] = -1;  
        }  
        for(m = 0; m < pages; m++)  
        {  
            s = 0;   
            for(n = 0; n < frames; n++)  
            {  
                if(incomingStream[m] == temp[n])  
                {  
                    s++;  
                    pageFaults--;  
                }  
            }  
            pageFaults++;  
            if((pageFaults <= frames) && (s == 0))  
            {  
                temp[m] = incomingStream[m];  
            }  
            else if(s == 0)  
            {  
                temp[(pageFaults - 1) % frames] = incomingStream[m];  
            }  
            printf("\n");  
            printf("%d\t\t\t",incomingStream[m]);  
            for(n = 0; n < frames; n++)  
            {  
                if(temp[n] != -1)  
                    printf(" %d\t\t\t", temp[n]);  
                else  
                    printf(" - \t\t\t");  
            }  
        }  
        printf("\nTotal Page Faults:\t%d\n", pageFaults);  
        return 0;  
    }  
