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
    int i;
    printf("Activity details report:\n");
    for(i=0;i<MAX_DAYS;i++)
    {
        printf("Details for day %d \n",i+1);
        printf("Enter the dayname:\n");
        scanf("%s",calender[i].dayname);
        printf("Enter the date:\n");
        scanf("%d",&calender[i].date);
        getchar();
        printf("Enter the activity description:\n");
        scanf("%s",calender[i].activitydescription);
    }
}

void display(struct day *calender)
{
    int i;
    printf("Week activity details report\n");
    printf("%-10s %-10s %-10s\n","Day","Date","ActivityDescription");
    for(i=0;i<MAX_DAYS;i++)
    {
        printf("%-10s %-10d %30s\n",calender[i].dayname,calender[i].date,calender[i].activitydescription);
    }
}

void freememory(struct day *calender)
{
    int i;
    for(i=0;i<MAX_DAYS;i++)
    {
    free(calender[i].dayname);
    free(calender[i].activitydescription);
    }
}


int main()
{
    struct day *calender=(struct day *)malloc(MAX_DAYS*sizeof(struct day));
    if(calender==NULL)
    {
        printf("memory allocation failed\n");
    }
    create(calender);
    read(calender);
    display(calender);
    freememory(calender);
    free(calender);
}

