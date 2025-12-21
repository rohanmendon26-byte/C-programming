#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *ptr, n;
    printf("Enter the size of the array you want to create:");
    scanf("%d", &n);

    ptr = (int *)malloc(n * sizeof(int));
    if (ptr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("Enter the value of no %d of this array ", i);
        scanf("%d", &ptr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        printf("The value of %d at this array is %d \n", i, ptr[i]);
    }

    free(ptr); // ✅ release memory
    printf("Memory freed successfully!\n");
    return 0;
}