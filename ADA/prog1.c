#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sorting(int arr[], int n)
{
    int i, j, k, t;
    for (i = 0; i <=n-2; i++)
    {
        j = i;
        for (k =i; k <=n-1; k++)
        {
            if (arr[k] < arr[j])
                j = k;
        }
        t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
}

int main()
{
    srand(time(NULL));
    clock_t start, end;
    int n, i;

    printf("Enter the number of elements:");
    scanf("%d", &n);

    int a[n];
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 10000;
    }

    start = clock();
    sorting(a, n);
    end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken:%f\n", time_taken);
    for (i = 0; i < 10; i++)
    {
        printf("%d\t", a[i]);
    }
}