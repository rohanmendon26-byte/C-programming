#include <stdio.h>

#define MAX 25

int main()
{
    int frag[MAX], b[MAX], f[MAX];
    int bf[MAX] = {0}, ff[MAX];
    int i, j, nb, nf;
    int highest, temp;

    printf("\n\tMemory Management Scheme - Worst Fit\n");

    printf("\nEnter number of blocks: ");
    scanf("%d", &nb);

    printf("Enter number of files: ");
    scanf("%d", &nf);

    printf("\nEnter size of each block:\n");
    for (i = 0; i < nb; i++)
    {
        printf("Block %d: ", i + 1);
        scanf("%d", &b[i]);
    }

    printf("\nEnter size of each file:\n");
    for (i = 0; i < nf; i++)
    {
        printf("File %d: ", i + 1);
        scanf("%d", &f[i]);
    }

    for (i = 0; i < nf; i++)
    {
        highest = -1;
        ff[i] = -1;

        for (j = 0; j < nb; j++)
        {
            if (bf[j] == 0)
            {
                temp = b[j] - f[i];
                if (temp >= 0 && temp > highest)
                {
                    highest = temp;
                    ff[i] = j;
                }
            }
        }

        if (ff[i] != -1)
        {
            frag[i] = highest;
            bf[ff[i]] = 1;
        }
        else
        {
            frag[i] = -1;
        }
    }

    printf("\nFile No\tFile Size\tBlock No\tBlock Size\tFragment");
    for (i = 0; i < nf; i++)
    {
        if (ff[i] != -1)
            printf("\n%d\t%d\t\t%d\t\t%d\t\t%d",
                   i + 1, f[i], ff[i] + 1, b[ff[i]], frag[i]);
        else
            printf("\n%d\t%d\t\tNot Allocated",
                   i + 1, f[i]);
    }

    return 0;
}
