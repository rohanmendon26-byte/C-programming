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
    printf("\n producer produces item %d:\n",x);
    ++mutex;
}

void consumer()
{
    --mutex;
    --full;
    ++empty;
    printf("\nConsumer consumes item %d\n",x);
    --x;
    ++mutex;
}
int main()
{
    int ch;
    while(1)
    {
        printf("\n1.Producer\n2.Consumer\n3.Exit:");
        printf("\nEnter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
               if((mutex==1)&&(empty!=0))
               {
                producer();
               }
               else{
                printf("\nBuffer is full\n");
               }
               break;

            case 2:
               if((mutex==1)&&(full!=0))
               {
                consumer();
               }
               else{
                printf("\nBuffer is empty\n");
               }
               break;

            case 3:
               exit(0);
               break;
        }
    }
}