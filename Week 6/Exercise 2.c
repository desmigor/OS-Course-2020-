#include <stdio.h>
#include <stdlib.h>

/*
Here, the Burst time is sorted in Ascending Order

Enter number of processes: 3
Enter Arrival time of process[1]: 2
Enter Burst time of process[1]: 6
Enter Arrival time of process[2]: 1
Enter Burst time of process[2]: 4
Enter Arrival time of process[3]: 3
Enter Burst time of process[3]: 10
P#       AT      BT      CT      TAT     WT

P1       2       4       6       4       0
P2       1       6       12      11      5
P3       3       10      22      19      9

Average TurnAround time= 11.333333
Average WT= 4.666667

Here, the shortest job is done first, so the processes are sorted according
to their burst time
*/

/*__________
Igor Mpore
BS19-06
*/

int main(){
	int bt[10]={0},at[10]={0},tat[10]={0},wt[10]={0},ct[10]={0},p[10]={0};
	int n,sum=0;
	float totalTAT=0,totalWT=0;
	printf("Enter number of processes: ");
	scanf("%d",&n);
	int i,j,k;
	
	for (i=0;i<n;i++){
		printf ("Enter Arrival time of process[%d]: ",i+1);
		scanf("%d",&at[i]);
		printf ("Enter Burst time of process[%d]: ",i+1);
		scanf("%d",&bt[i]);
		p[i]=i+1;
	}

//sorting of burst times
int temp,pos;
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }
  
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
  
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
    
    
	for (j=0;j<n;j++){
		if(j==0) 
		sum=sum+at[0];
		sum=sum+bt[j];
		ct[j]=ct[j]+sum;
	}
	
	for (k=0;k<n;k++){
		tat[k]=ct[k]-at[k];
		totalTAT=totalTAT+tat[k];
	}
	
	for (k=0;k<n;k++){
		wt[k]=tat[k]-bt[k];
		totalWT+=wt[k];
	}
	
	printf("P#\t AT\t BT\t CT\t TAT\t WT\t \n\n");
	
	for (i=0;i<n;i++)
		printf("P%d\t %d\t %d\t %d\t %d\t %d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
	
	printf("\nAverage TurnAround time= %f\n",totalTAT/n);
	printf("Average WT= %f\n\n", totalWT/n);
	return 0;
}

