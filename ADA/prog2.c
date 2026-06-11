#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int a[],int low,int mid,int high){
    int left=low;
    int right=mid+1;
    int i,k=0;
    int temp[300000];

    while(left<=mid && right<=high){
        if(a[left]<=a[right])
           temp[k++]=a[left++];
        else
           temp[k++]=a[right++];

        }
        while(left<=mid)
           temp[k++]=a[left++];
        while(right<=high)
           temp[k++]=a[right++];

        for(i=0;i<k;i++)
            a[low+i]=temp[i];
}

void mergesort(int a[],int low,int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}


int main(){
    srand(time(NULL));
    clock_t start,end;
    int n,i;

    printf("Enter the array size:\n");
    scanf("%d",&n);
    int a[n];

    for(i=0;i<n;i++){
        a[i]=rand()%10000;
    }

    start=clock();
    mergesort(a,0,n-1);
    end=clock();

    double time_taken=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time taken =%f\n",time_taken);

    for(i=0;i<10;i++){
        printf("%d\t",a[i]);
    }
}