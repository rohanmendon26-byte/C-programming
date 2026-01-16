#include<stdio.h>
#include<stdlib.h>
#define MAX_DAYS 7

struct day
{
    char *dayname;
    int date;
    char *activitydescrription;
};

void create(struct day *calender)
{
    int i;
    for(i=0;i<MAX_DAYS;i++)
    {
        calender[i].dayname=(char *)malloc(20*sizeof(char));
        calender[i].activitydescrription=(char *)malloc(100*sizeof(char));
    }
}

void read(struct day *calender)
{
    int i;
    printf("\nWeek activity details report\n");
    for(i=0;i<MAX_DAYS;i++)
    {
        printf("\nDetails for day %d:\n",i+1);
        printf("\nEnter the dayname:\n");
        scanf("%s",calender[i].dayname);
        printf("\nEnter the date:\n");
        scanf("%d",&calender[i].date);
        printf("\nEnter the activity description:\n");
        scanf(" %[^\n]",calender[i].activitydescrription);
    }
}

void display(struct day *calender)
{
    int i;
    printf("\n %-10s %-10s %-30s\n","Day","Date","ActivityDescription");
    for(i=0;i<MAX_DAYS;i++)
    {
        printf("\n %-10s %-10d %-30s",calender[i].dayname,calender[i].date,calender[i].activitydescrription);
    }
}


void freememory(struct day *calender)
{
    int i;
    for(i=0;i<MAX_DAYS;i++)
    {
        free(calender[i].dayname);
        free(calender[i].activitydescrription);
    }
}

int main()
{
    struct day *calender=(struct day *)malloc(sizeof(struct day)*MAX_DAYS);
    if(calender==NULL)
    {
        printf("\nMemory is not available\n");
        return 1;
    }
    create(calender);
    read(calender);
    display(calender);
    freememory(calender);
    free(calender);
}