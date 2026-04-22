#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int a[],int low,int mid,int high){
    int left=low;
    int right=mid+1;
    int k=0;
    int temp[300000];
    int i;

    while(left<=mid && right<=high){
        if(a[left]<=a[right])
           temp[k++]=a[left++];
        else
           temp[k++]=a[right++];
    }

    while(left<=mid){
        temp[k++]=a[left++];
    }

    while(right<=high){
        temp[k++]=a[right++];
    }

    for(i=0;i<k;i++){
        a[low+i]=temp[i];
    }

}

void MergeSort(int a[],int low,int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        MergeSort(a,low,mid);
        MergeSort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

void main(){
    int n,i;
    srand(time(NULL));
    clock_t start,end;
    printf("Enter the array size:");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        a[i]=rand()/1000;
    }

    start=clock();
    MergeSort(a,0,n-1);
    end=clock();

    double time_taken=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time taken:%f\n",time_taken);

    for(i=0;i<10;i++){
        printf("%d\t",a[i]);
    }
}