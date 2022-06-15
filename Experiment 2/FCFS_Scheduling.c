#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i, n, bursttime[10], waittime[10], turnaroundtime[10], totalwait, totalturn;
    float averagewait,averageturn;

    printf("Enter Number of Processes: ");
    scanf("%d", &n);
    
    printf("\nEnter Burst time of Processes: \n");
    for ( i = 0; i < n; i++)
    {
        scanf("%d", &bursttime[i]);
    }

    waittime[0] = 0;
    turnaroundtime[0] = bursttime[0];

    totalwait = 0;
    totalturn = turnaroundtime[0];

    for ( i = 1; i < n; i++)
    {
        waittime[i] = turnaroundtime[i-1];
        turnaroundtime[i] = waittime[i] + bursttime[i];
        totalwait = totalwait + waittime[i];
        totalturn = totalturn + turnaroundtime[i];
    }
    
    printf("\nProcess\tBurst\tWait\tTurnAround\n");
    for ( i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\n", i+1, bursttime[i], waittime[i], turnaroundtime[i]);
    }
    averagewait = totalwait/n;
    averageturn = totalturn/n;
    printf("\nAverage Wait Time: %.2f", averagewait);
    printf("\nAverage Turn Time: %.2f", averageturn);

    return 0;
}
