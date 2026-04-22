#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[],int low,int high){
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot && i<=high-1)
              i++;
        while(arr[j]>pivot && j>=low+1)
              j--;
    
        if(i<j)
            swap(&arr[i],&arr[j]);
    }
    swap(&arr[low],&arr[j]);
    return j;
}

void quicksort(int arr[],int low,int high){
    if(low<high){
        int pivotIndex=partition(arr,low,high);
        quicksort(arr,low,pivotIndex-1);
        quicksort(arr,pivotIndex+1,high);
    }
}


void main(){
    int i,n;
    clock_t start,end;
    printf("Enter the array size:");
    scanf("%d",&n);
    int a[n];
    srand(time(NULL));
    for(i=0;i<n;i++){
        a[i]=rand()/1000;
    }
    start=clock();
    quicksort(a,0,n-1);
    end=clock();
    printf("\n");
    double time_taken=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time taken:%f\n",time_taken);

    for(i=0;i<10;i++){
        printf("%d\t",a[i]);
    }

}