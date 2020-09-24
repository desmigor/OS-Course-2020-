#include <stdio.h>
#include <stdlib.h>

/*
Round Robin Algorithm

Enter number of processes: 4
Enter Arrival time of process[1]: 0
Enter Burst time of process[1]: 9
Enter Arrival time of process[2]: 1
Enter Burst time of process[2]: 5
Enter Arrival time of process[3]: 2
Enter Burst time of process[3]: 3
Enter Arrival time of process[4]: 3
Enter Burst time of process[4]: 4
Enter Time Quantum: 5
P#       AT      BT      TAT     WT

P2       1       5       9       4
P3       2       3       11      8
P4       3       4       14      10
P1       0       9       21      12

Average Waiting Time= 8.500000
Average Turnaround Time = 13.750000

This is a FIFO algorithm and each is executed process should be 
executed according to quantum Time as the table shows
*/

/*__________
Igor Mpore
BS19-06
*/

int main(){
	int bt[10],at[10],tat=0,wt=0,ct[10]={0},rt[10];
	int n,sum=0,time_quantum,time,remain,flag=0;
	float totalTAT=0,totalWT=0;
	printf("Enter number of processes: ");
	scanf("%d",&n);
	remain=n;
	int i,j,k;
	
	for (i=0;i<n;i++){
		printf ("Enter Arrival time of process[%d]: ",i+1);
		scanf("%d",&at[i]);
		printf ("Enter Burst time of process[%d]: ",i+1);
		scanf("%d",&bt[i]);
		rt[i]=bt[i];
	}
	
printf("Enter Time Quantum: "); 
  scanf("%d",&time_quantum); 
  
  //Finding the Completion time
  for (j=0;j<n;j++){
		if(j==0) 
		sum=sum+at[0];
		sum=sum+bt[j];
		ct[j]=ct[j]+sum;
	}
	
  printf("P#\t AT\t BT\t TAT\t WT\t \n\n"); 
  for(time=0,i=0;remain!=0;) 
  { 
    if(rt[i]<=time_quantum && rt[i]>0) 
    { 
      time+=rt[i]; 
      rt[i]=0; 
      flag=1; 
    } 
    else if(rt[i]>0) 
    { 
      rt[i]-=time_quantum; 
      time+=time_quantum; 
    } 
    if(rt[i]==0 && flag==1) 
    { 
      remain--; 
      printf("P%d\t %d\t %d\t %d\t %d\n",i+1,at[i],bt[i],time-at[i],time-at[i]-bt[i]); 
      wt+=time-at[i]-bt[i]; 
      tat+=time-at[i]; 
      flag=0; 
    } 
    if(i==n-1) 
      i=0; 
    else if(at[i+1]<=time) 
      i++; 
    else 
      i=0; 
  }
	printf("\nAverage Waiting Time= %f\n",wt*1.0/n); 
  printf("Average Turnaround Time = %f",tat*1.0/n);
	return 0;
}

