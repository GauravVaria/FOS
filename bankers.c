#include <stdio.h>
#define processes 5
#define resources 3
int rear = 0;
void push(int arr[], int data)
{
    arr[rear] = data;
    rear = rear + 1;
}
struct resource
{
    int a, b, c;
} max[processes], need[processes], available, allocated[processes];

int main(int argc, char const *argv[])
{
    int finish[processes], sum, pass = 0, sequence[processes];
    printf("\nEnter Allocated Resources A B C: ");
    for (int i = 0; i < processes; i++)
    {
        scanf("%d %d %d", &allocated[i].a, &allocated[i].b, &allocated[i].c);
    }

    printf("\nEnter Max Resources A B C: ");
    for (int i = 0; i < processes; i++)
    {
        scanf("%d %d %d", &max[i].a, &max[i].b, &max[i].c);
    }

    printf("\nEnter Available Resources: ");
    scanf("%d %d %d", &available.a, &available.b, &available.c);

    for (int i = 0; i < processes; i++)
    {
        need[i].a = max[i].a - allocated[i].a;
        need[i].b = max[i].b - allocated[i].b;
        need[i].c = max[i].c - allocated[i].c;
    }

    for (int i = 0; i < processes; i++)
    {
        finish[i] = 0;
    }
    do
    {
        for (int i = 0; i < processes; i++)
        {
            if (finish[i] == 0 && need[i].a <= available.a && need[i].b <= available.b && need[i].c <= available.c)
            {
                available.a += allocated[i].a;
                available.b += allocated[i].b;
                available.c += allocated[i].c;
                finish[i] = 1;
                push(sequence, i);
            }
        }
        for (int j = 0; j < processes; j++)
        {
            sum += finish[j];
        }
        if (sum == 5)
        {
            printf("\nSystem is in safe state.\nSafe sequence = ");
            for (int i = 0; i < processes; i++)
            {
                printf("%d ", sequence[i]);
            }
            
            break;
        }
        else
        {
            printf("\nSystem is not in safe state after pass %d.", pass);
        }
        pass += 1;
        sum = 0;
    } while (pass != processes);

    return 0;
}
