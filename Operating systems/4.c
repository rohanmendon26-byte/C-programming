#include<stdio.h>
#include<stdlib.h>
int mutex=1;
int full=0;
int empty=5;
int x=0;

void producer()
{
    --mutex;
    ++full;
    --empty;
    ++x;
    printf("Producer produces item %d\n",x);
    ++mutex;
}

void consumer()
{
    --mutex;
    --full;
    ++empty;
    printf("Consumer consumes item %d\n",x);
    --x;
    ++mutex;
}

int main()
{
    int n,i;
    printf("\n1.press 1 for producer\n2.press 2 for consumer\n3.press 3 for exit\n");
    while(1)
    {
        printf("Enter your choice:");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                if((mutex==1)&&(empty!=0))
                {
                    producer();
                }
                else
                {
                    printf("Buffer is full\n");
                }
                break;

            case 2:
                if((mutex==1)&&(full!=0))
                {
                    consumer();
                }
                else
                {
                    printf("Buffer is empty\n");
                }
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice:\n");
                break;
        }
    }
}