#include<stdio.h>
#include<stdlib.h>
#define MAX_DAYS 7

struct day
{
    char *dayname;
    int date;
    char *activitydescription;
};

void create(struct day *calender)
{
    for(int i=0;i<MAX_DAYS;i++)
    {
        calender[i].dayname=(char *)malloc(MAX_DAYS*sizeof(char));
        calender[i].activitydescription=(char *)malloc(MAX_DAYS*sizeof(char));
    }
}

void read(struct day *calender)
{
    printf("\nActivity details report");
    for(int i=0;i<MAX_DAYS;i++)
    {
        printf("\nDetails for day %d:",i+1);
        printf("\nEnter the dayname:");
        scanf("%s",calender[i].dayname);
        printf("\nEnter your date:");
        scanf("%d",&calender[i].date);
        getchar();
        printf("\nEnter the activitydescription:");
        scanf(" %[^\n]",calender[i].activitydescription);
    }
}


void display(struct day *calender)
{
    printf("\nWeek activity details report");
    printf("\n%-10s %-10s %-30s","Day","Date","ActivityDescription");
    for(int i=0;i<MAX_DAYS;i++)
    {
        printf("\n%-10s %-10d %-30s",calender[i].dayname,calender[i].date,calender[i].activitydescription);
    }
}


void freememory(struct day *calender)
{
    for(int i=0;i<MAX_DAYS;i++)
    {
        free(calender[i].dayname);
        free(calender[i].activitydescription);
    }
}


void main()
{
    struct day *calender=(struct day *)malloc(MAX_DAYS*sizeof(struct day));
    if(calender==NULL)
    {
        printf("\nMemory is full");
        return;
    }
    create(calender);
    read(calender);
    display(calender);
    freememory(calender);
    free(calender);
    return;
}