// No internal fragmentation. External frag may occur as spanning not allowed. Partitions created on basis of size of process.
// External fragmentation will occur if 2 processes are executed and new process which can get memory allocated after combining
// blocks of 2 executed processes but cannot get memory allocated as it will be non contiguous and hence ext. frag. occurs
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i, numproc, memorysize, totintfrag = 0, choice;

    printf("Enter total size of memory: ");
    scanf("%d", &memorysize);

    printf("\nEnter number of processes: ");
    scanf("%d", &numproc);
    
    int procsize[numproc], blocksize[numproc], intfrag[numproc];
    printf("\nEnter size of each process: ");
    for ( i = 0; i < numproc; i++)
    {
        printf("\nProcess %d: ", i+1);
        scanf("%d", &procsize[i]);
        blocksize[i] = procsize[i];
        intfrag[i] = blocksize[i] - procsize[i];
        totintfrag += intfrag[i];
    }
    
    printf("\nPROCESS\tMEMORY REQUIRED\tBLOCKSIZE\tINTERNAL FRAGMENTATION\n");
    for ( i = 0; i < numproc; i++)
        printf("P[%d]\t%d\t\t%d\t\t%d\n", i+1, procsize[i], blocksize[i], intfrag[i]);

    printf("\nTotal Internal Fragmentation: %d", totintfrag);
    return 0;
}
