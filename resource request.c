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
} max[processes], need[processes], available, allocated[processes], request[processes];

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
    int i = 1;
    request[i].a = 1;
    request[i].b = 0;
    request[i].c = 2;
    if (request[i].a <= need[i].a && request[i].b <= need[i].b && request[i].c <= need[i].c)
    {
        if (request[i].a <= available.a && request[i].b <= available.b && request[i].c <= available.c)
        {
            available.a -= request[i].a;
            available.b -= request[i].b;
            available.c -= request[i].c;
            allocated[i].a += request[i].a;
            allocated[i].b += request[i].b;
            allocated[i].c += request[i].c;
            need[i].a -= request[i].a;
            need[i].b -= request[i].b;
            need[i].c -= request[i].c;
        }
        else
        {
            printf("\nProcess must wait resources unavailable.");
        }
    }
    else
    {
        printf("\nReq exceeds max");
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
}
