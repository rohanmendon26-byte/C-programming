#include<stdio.h>
#define MAX_ITEMS 100

int getNextItem(double weight[],double value[],double ratio[],int nItems){
    double highest=0;
    int index=-1;
    int i;
    for(i=0;i<nItems;i++){
        if(ratio[i]>highest){
            highest=ratio[i];
            index=i;
        }
    }
    return index;
}


double computeMaxValue(double w,double weight[],double value[],double ratio[],int nItems){
    double cw=0;
    double cv=0;
    printf("\nItems Considered are:");
    while(cw<w){
        int item=getNextItem(weight,value,ratio,nItems);
        if(item==-1){
            break;
        }

        printf("%d",item+1);
        if(cw+weight[item]<=w){
            cw+=weight[item];
            cv+=value[item];
            ratio[item]=0;
        }

        else{
            cv+=ratio[item]*(w-cw);
            cw+=(w-cw);
            break;
        }
    }
    return cv;
}


int main(){
    int nItems,i;
    double weight[MAX_ITEMS];
    double value[MAX_ITEMS];
    double ratio[MAX_ITEMS];
    double w;

    printf("\nEnter the number of items:");
    scanf("%d",&nItems);

    printf("\nEnter the Weight of the item:");
    for(i=0;i<nItems;i++){
        scanf("%lf",&weight[i]);
    }

    printf("\nEnter the Value of the item:");
    for(i=0;i<nItems;i++){
        scanf("%lf",&value[i]);
    }

    for(i=0;i<nItems;i++){
        ratio[i]=value[i]/weight[i];
    }

    printf("\nEnter the capacity of knapsack:");
    scanf("%lf",&w);

    printf("\nMaximum value in Capacity %.2f is %.2f",w,computeMaxValue(w,weight,value,ratio,nItems));
}