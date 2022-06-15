#include <stdio.h>
int main(int argc, char const *argv[])
{
    int i, j, n, wait = 0, maxburst = 0;
    float averageturn=0, averagewait=0, totalturn=0, totalwait=0; 
    printf("Enter Number of Processes: ");
    scanf("%d", &n);
    int turnaroundtime[n], bursttime[n], timeslice, waittime[n], burst2[n];

    for ( i = 0; i < n; i++)
    {
        printf("\nEnter Burst Time for Process %d -- \n", i+1);
        scanf("%d", &bursttime[i]);
        burst2[i] = bursttime[i];
        if (bursttime[i] > maxburst)
            maxburst = bursttime[i];
    }
    
    printf("\nEnter Time Slice: ");
    scanf("%d", &timeslice);

    for ( i = 0; i < (maxburst/timeslice)+1; i++)
        for ( j = 0; j < n; j++)
            if (bursttime[j]!=0)
                if (bursttime[j]<=timeslice)
                    {
                        turnaroundtime[j] = wait + bursttime[j];
                        wait = wait + bursttime[j];
                        bursttime[j] = 0;
                    }
                else
                    {
                        bursttime[j] = bursttime[j] - timeslice;
                        wait = wait + timeslice;
                    }

    for ( i = 0; i < n; i++)
    {
        waittime[i] = turnaroundtime[i] - burst2[i];
        totalturn = totalturn + turnaroundtime[i];
        totalwait = totalwait + waittime[i];
    }
    
    printf("\nAverage TurnAround Time: %.2f", totalturn/n);
    printf("\nAverage Wait Time: %.2f", totalwait/n);

    printf("\nPROCESS\tBURST\tWAIT\tTURNAROUND\n");

    for ( i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\n", i+1, burst2[i], waittime[i], turnaroundtime[i]);
    }

    return 0;
}
