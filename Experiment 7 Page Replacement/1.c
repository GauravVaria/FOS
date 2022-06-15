#include <stdio.h>
int frame[3];

void display();
int main(int argc, char const *argv[])
{
    int framesize = 3, i, j, pagefault;
    int pages[12]={2,3,2,1,5,2,4,5,3,2,5,2};

    for ( i = 0; i < 3; i++)
    {
        frame[i] = -1;
    }
    display();

    for ( i = 0; i < 12; i++)
    {
        
        
    }
    display();

    return 0;
}
void display()
{
    int i;
    printf("\n");
    for ( i = 0; i < 3; i++)
        printf("%d\t", frame[i]);
}