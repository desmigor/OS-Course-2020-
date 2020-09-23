#include <stdio.h>
#include <stdlib.h>

void clrscr()
{
 system("@cls||clear");	
}





int main(){
	clrscr();
	int bt[10]={0},at[10]={0},tat[10]={0},wt[10]={0},ct[10]={0};
	int n,sum=0;
	float totalTAT=0,totalWT=0;
	printf("Enter number of processes: ");
	scanf("%d",&n);
	printf("Enter Arrival time and burst time of each process: \n");
	int i=0,j=0,k=0;
	
	for (i=0;i<n;i++){
		printf ("Arrival time of process[%d]: ",i+1);
		scanf("%d",&at[i]);
		printf ("Burst time of process[%d]: ",i+1);
		scanf("%d",&bt[i]);
	}
	
	
	
	for (j=0;j<n;j++){
		if(j==0) sum+=at[0];
		sum+=bt[j];
		ct[j]+=sum;
	}
	
	
	
	for (k=0;k<n;k++){
		tat[k]=ct[k]-at[k];
		totalTAT+=tat[k];
	}
	
	
	for (k=0;k<n;k++){
		wt[k]=tat[k]-bt[k];
		totalWT+=wt[k];
	}
	
	
	printf("P#\t AT\t BT\t CT\t TAT\t WT\t \n\n");
	
	for (i=0;i<n;i++){
		printf("P%d\t %d\t %d\t %d\t %d\t %d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
	}
	
	printf("\nAverage TurnAround time= %f\n",totalTAT/n);
	printf("Average WT= %f\n\n", totalWT/n);
	
	return 0;
}

