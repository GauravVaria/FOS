#include<stdio.h>

int main()
{

int i,j,n,maxburst;
float averagewaittime=0,averageturntime=0,wait=0, totalturntime = 0, totalwaittime = 0;

printf("Enter the no of processes -- "); // 2
scanf("%d",&n);

int bursttime[n],waittime[n],turnaroundtime[n],timeslice,ct[n];

for(i=0;i<n;i++) 
    {
    printf("\nEnter burst time for process %d -- ", i+1); // 5, 20
    scanf("%d",&bursttime[i]);
    ct[i]=bursttime[i]; // CT = Copy of Burst time array to get original values later
    }

printf("\nEnter the size of time slice -- "); // 10
scanf("%d",&timeslice);
maxburst=bursttime[0];

for(i=1;i<n;i++) // Find Maximum Burst Time 
    if(maxburst<bursttime[i])
        maxburst=bursttime[i];

for(i=0;i<(maxburst/timeslice)+1;i++) // Execute loop until max burst is executed
    for(j=0;j<n;j++) // Execute for all processes
        if(bursttime[j]!=0) // Check if process is executed
		    if(bursttime[j]<=timeslice) // Check if burst can be finished under one time quantum
                {
                    turnaroundtime[j]=wait+bursttime[j]; // turnaround[0] = 0 + 5 = 5
                    wait=wait+bursttime[j]; // wait = 0 + 5 = 5
                    bursttime[j]=0; // PROCESS FULLY EXECUTED
                }
            else // If Process cannot be executed under one time quantum
	            {
                    bursttime[j]=bursttime[j]-timeslice; // PROCESS EXECUTED UNTIL TIME SLICE
                    wait=wait+timeslice; // Used to calculate turnaroundtime
                }

for(i=0;i<n;i++)
    {
        waittime[i]=turnaroundtime[i]-ct[i]; // Wait-time = Turnaround - (original) Burst
        totalturntime+=turnaroundtime[i]; 
        totalwaittime+=waittime[i];
	}
printf("\nThe Average Turnaround time is -- %f", totalturntime/n);
printf("\nThe Average Waiting time is -- %f ", totalwaittime/n);

printf("\n\tPROCESS\t BURST TIME \t WAITING TIME\tTURNAROUND TIME\n");

for(i=0;i<n;i++)
    printf("\t%d \t %d \t\t %d \t\t %d \n",i+1,ct[i],waittime[i],turnaroundtime[i]);

return 0;
}
