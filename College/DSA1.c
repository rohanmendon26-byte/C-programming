#include <stdio.h>
#include <stdlib.h>
#define MAX_DAYS 7

struct Day
{
    char *dayname;
    int date;
    char *activityDescription;
};

void create(struct Day *calender)
{
    for (int i = 0; i < MAX_DAYS; i++)
    {
        calender[i].dayname = malloc(20 * sizeof(char));
        calender[i].activityDescription = malloc(100 * sizeof(char));
    }
}

void read(struct Day *calender)
{
    for (int i = 0; i < MAX_DAYS; i++)
    {
        printf("\nEnter details for day %d:\n", i + 1);

        printf("Enter day name: ");
        scanf("%19s", calender[i].dayname); // limit input to 19 chars

        printf("Enter date: ");
        scanf("%d", &calender[i].date);

        getchar(); // clear newline

        printf("Enter activity description: ");
        scanf(" %[^\n]", calender[i].activityDescription);
    }
}

void display(struct Day *calender)
{
    printf("\nWeeks Activity Details Report:\n");
    printf("%-10s %-10s %-30s\n", "Day", "Date", "Activitydescription");
    for (int i = 0; i < MAX_DAYS; i++)
    {
        printf("%-10s %-10d %-30s\n",
               calender[i].dayname,
               calender[i].date,
               calender[i].activityDescription);
    }
}

void freeMemory(struct Day *calender)
{
    for (int i = 0; i < MAX_DAYS; i++)
    {
        free(calender[i].dayname);
        free(calender[i].activityDescription);
    }
}

int main()
{
    struct Day *calender = malloc(sizeof(struct Day) * MAX_DAYS);
    if (calender == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    create(calender);
    read(calender);
    display(calender);
    freeMemory(calender);
    free(calender);

    return 0;
}
