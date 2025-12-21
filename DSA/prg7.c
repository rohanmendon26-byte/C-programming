#include <stdio.h>
#include <stdlib.h>

struct node
{
    char usn[25], name[25], branch[25];
    int sem;
    long int phone;
    struct node *link;
};

typedef struct node *NODE;

NODE start = NULL;
int count = 0;

/* Create a student node */
NODE create()
{
    NODE snode;
    snode = (NODE)malloc(sizeof(struct node));

    if (snode == NULL)
    {
        printf("Memory not available\n");
        exit(1);
    }

    printf("Enter USN Name Branch Sem Phone:\n");
    scanf("%s %s %s %d %ld",
          snode->usn,
          snode->name,
          snode->branch,
          &snode->sem,
          &snode->phone);

    snode->link = NULL;
    count++;
    return snode;
}

/* Insert at front */
NODE insertfront()
{
    NODE temp = create();
    temp->link = start;
    return temp;
}

/* Delete from front */
NODE deletefront()
{
    NODE temp;

    if (start == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }

    temp = start;
    start = start->link;

    printf("Deleted student USN: %s\n", temp->usn);
    free(temp);
    count--;

    return start;
}

/* Insert at end */
NODE insertend()
{
    NODE cur, temp = create();

    if (start == NULL)
        return temp;

    cur = start;
    while (cur->link != NULL)
        cur = cur->link;

    cur->link = temp;
    return start;
}

/* Delete from end */
NODE deleteend()
{
    NODE cur, prev;

    if (start == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }

    if (start->link == NULL)
    {
        printf("Deleted student USN: %s\n", start->usn);
        free(start);
        count--;
        return NULL;
    }

    prev = NULL;
    cur = start;

    while (cur->link != NULL)
    {
        prev = cur;
        cur = cur->link;
    }

    printf("Deleted student USN: %s\n", cur->usn);
    free(cur);
    prev->link = NULL;
    count--;

    return start;
}

/* Display list */
void display()
{
    NODE cur;
    int num = 1;

    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("\n--- Student Details ---\n");
    cur = start;

    while (cur != NULL)
    {
        printf("%d] USN:%s Name:%s Branch:%s Sem:%d Phone:%ld\n",
               num,
               cur->usn,
               cur->name,
               cur->branch,
               cur->sem,
               cur->phone);

        cur = cur->link;
        num++;
    }

    printf("Total students = %d\n", count);
}

/* Stack demo using SLL */
void stackdemo()
{
    int ch;

    while (1)
    {
        printf("\n--- STACK DEMO USING SLL ---");
        printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            start = insertfront();
            break;

        case 2:
            start = deletefront();
            break;

        case 3:
            display();
            break;

        case 4:
            return;

        default:
            printf("Invalid choice\n");
        }
    }
}

/* Main function */
int main()
{
    int ch, i, n;

    while (1)
    {
        printf("\n--- MENU ---");
        printf("\n1.Create SLL");
        printf("\n2.Display");
        printf("\n3.Insert at end");
        printf("\n4.Delete at end");
        printf("\n5.Stack demo");
        printf("\n6.Exit");
        printf("\nEnter choice: ");

        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter number of students: ");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
                start = insertfront();
            break;

        case 2:
            display();
            break;

        case 3:
            start = insertend();
            break;

        case 4:
            start = deleteend();
            break;

        case 5:
            stackdemo();
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
}
