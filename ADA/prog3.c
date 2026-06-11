#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int a[],int low,int high){
    int i=low;
    int j=high;
    int pivot=a[low];

    while(i<j){
        while(a[i]<=pivot && i<=high-1)
             i++;
        while(a[j]>pivot && j>=low+1)
             j--;
        if(i<j)
           swap(&a[i],&a[j]);
    }
    swap(&a[low],&a[j]);
    return j;
}

void quicksort(int a[],int low,int high){
    if(low<high){
        int pivotIndex=partition(a,low,high);
        quicksort(a,low,pivotIndex-1);
        quicksort(a,pivotIndex+1,high);
    }
}


int main()
{
    srand(time(NULL));
    clock_t start,end;
    int i,n;
    printf("Enter the array size:\n");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
        a[i]=rand()%1000;

    start=clock();
    quicksort(a,0,n-1);
    end=clock();

    double time_taken=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time taken=%d\n",time_taken);

    for(i=0;i<10;i++){
        printf("%d\t",a[i]);
    }
}