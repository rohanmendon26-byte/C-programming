#include<stdio.h>
#include<stdlib.h>
#define MAX_DAYS 7

struct day{
    char *dayname;
    int date;
    char *activitydescription;
};

void create(struct day *calender)
{
    for(int i=0;i<MAX_DAYS;i++)
    {
        calender[i].dayname=(char*)malloc(20*sizeof(char));
        calender[i].activitydescription=(char*)malloc(100*sizeof(char));
    }
}

void read(struct day *calender)
{
    for(int i=0;i<MAX_DAYS;i++)
    {
        printf("\nActivity details for day %d:",i+1);
        printf("\nEnter the dayname:");
        scanf("%s",calender[i].dayname);
        printf("\nEnter the date:");
        scanf("%d",&calender[i].date);
        printf("\nEnter the Activity Description:");
        scanf(" %[^\n]",calender[i].activitydescription);
    }
}

void display(struct day *calender)
{
    printf("\nWeek's Activity details report");
    printf("\n%-10s %-10s %-30s","Day","Date","Activity Description");
    for(int i=0;i<MAX_DAYS;i++)
    {
        printf("\n%-10s %-10d %-10s",calender[i].dayname,calender[i].date,calender[i].activitydescription);
    }
}


void freememory(struct day*calender)
{
    for(int i=0;i<MAX_DAYS;i++)
    {
        free(calender[i].dayname);
        free(calender[i].activitydescription);
    }
}


int main()
{
    struct day *calender=(struct day *)malloc(sizeof(struct day)*MAX_DAYS);
    if(calender==NULL)
    {
        printf("\nMemory is not available:");
        return 1;
    }
    create(calender);
    read(calender);
    display(calender);
    freememory(calender);
    free(calender);
    return 0;
}