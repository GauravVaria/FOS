#include<stdio.h>

int main()
{

int i, j, n, temp; 
float waittimeavg,turnaroundtimeavg;

printf("\nEnter the number of processes -- ");
scanf("%d", &n);

int process[n], bursttime[n], waittime[n], turnaroundtime[n];

for(i=0;i<n;i++)
    {
        process[i]=i;
        printf("Enter Burst Time for Process %d -- ", i+1);
        scanf("%d", &bursttime[i]);
    }

for(i=0;i<n;i++)
    for(j=i+1;j<n;j++)
        if(bursttime[i]>bursttime[j])
            {
                temp=bursttime[i];
                bursttime[i]=bursttime[j];
                bursttime[j]=temp;
                temp=process[i];
                process[i]=process[j];
                process[j]=temp;
            }
waittime[0] = waittimeavg = 0;
turnaroundtime[0] = turnaroundtimeavg = bursttime[0]; 

for(i=1;i<n;i++)
    {
        waittime[i] = waittime[i-1] +bursttime[i-1];
        turnaroundtime[i] = turnaroundtime[i-1] +bursttime[i];
        waittimeavg = waittimeavg + waittime[i];
        turnaroundtimeavg = turnaroundtimeavg + turnaroundtime[i];
    }

printf("\n\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n");

for(i=0;i<n;i++)
    printf("\n\t P%d \t\t %d \t\t %d \t\t %d", process[i], bursttime[i], waittime[i], turnaroundtime[i]);

printf("\nAverage Waiting Time -- %f", waittimeavg/n);
printf("\nAverage Turnaround Time -- %f", turnaroundtimeavg/n); 

return 0;
}
