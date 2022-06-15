/* Number of partitions fixed. Size may or may not vary. No spanning allowed. Partitions made statically. */

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i, j, numofblock = 0, totalmemory = 0, blocksize = 0, totalintfrag, totalextfrag;
    printf("Enter Total memory: ");
    scanf("%d", &totalmemory);

    printf("Enter size of blocks: ");
    scanf("%d", &blocksize);

    numofblock = totalmemory / blocksize;
    int procsize[numofblock], internalfragmentation[numofblock];

    printf("Enter %d Processes: \n", numofblock);
    for ( i = 0; i < numofblock; i++)
            do
            {
                printf("Process %d: ", i+1);
                scanf("%d", &procsize[i]);
                if (procsize[i] > blocksize)
                    {
                        printf("Size of Process More than Size of Memory or block. Try again.\n");
                        i--;
                    }
            } while (procsize[i] > blocksize);
    
    for ( i = 0; i < numofblock; i++)
        internalfragmentation[i] = blocksize - procsize[i];
    
    printf("\nPROCESS\tBLOCKSIZE\tMEMORY REQUIRED\tINTERNALFRAGMENTATION\n");
    for ( i = 0; i < numofblock; i++)
        {   
            printf("P[%d]\t%d\t\t%d\t\t%d\n", i+1, blocksize, procsize[i], internalfragmentation[i]);
            totalintfrag += internalfragmentation[i];
        }
    totalextfrag = totalintfrag;
    printf("\nTotal Internal Fragmentation: %d", totalintfrag);
    printf("\nTotal External Fragmentation: %d", totalextfrag);
    
    return 0;
}
