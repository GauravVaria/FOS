#include <stdio.h>

int mutex = 1, full = 0, empty = 3, x = 0; 

int signal(int s)
{
    return ++s;
}

int wait(int s)
{
    return --s;
}

void producer()
{
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    x++;
    printf("\nProducer Produces item %d\n", x);
    mutex = signal(mutex);
}

void consumer()
{
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("\nConsumer consumes item %d\n", x);
    x--;
    mutex = signal(mutex);
}

int main(int argc, char const *argv[])
{
    int choice;
    do
    {
        printf("Enter your choice: \n1:Produce\n2:Consume\n3:Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (mutex == 1 && empty!=0)
                producer();
            else
                printf("Buffer is Full!\n");
            break;
        
        case 2:
            if(mutex==1 && full != 0)
                consumer();
            else
                printf("Buffer is Empty!\n");
            break;
        case 3:
            printf("\nExiting Program");
            break;
        default:
            printf("Invalid Choice\n");
        }
    } while (choice!=3);
    
    
    return 0;
}
