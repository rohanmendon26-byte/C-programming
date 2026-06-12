#include<stdio.h>
#define MAX 20

int x[MAX];
int s[MAX];
int d;
int flag=0;

void sumofsub(int m,int k,int r){
    int i;
    x[k]=1;

    if(m+s[k]==d){
        flag=1;
        printf("{ ");
        for(i=1;i<=k;i++){
            if(x[i]==1){
                printf("%d",s[i]);
            }
        }
        printf("}\n");
    }

    else if((m+s[k]+s[k+1]<=d)){
        sumofsub(m+s[k],k+1,r-s[k]);
    }

    if((m+r-s[k]>=d)&&(m+s[k+1]<=d)){
        x[k]=0;
        sumofsub(m,k+1,r-s[k]);
    }
}


int main(){
    int n;
    int i;
    int sum=0;

    printf("\nEnter the number of elements:");
    scanf("%d",&n);

    printf("\nEnter the values:");
    for(i=1;i<=n;i++){
        scanf("%d",&s[i]);
        sum+=s[i];
    }

    printf("\nEnter the value of d:");
        scanf("%d",&d);
    

    if(sum<d ||s[1]>d){
        printf("\nThe given problem instance does not have a solution:");
        return 0;
    }

    else{
        printf("\nSubssets are:");
        sumofsub(0,1,sum);
    }

    if(flag==0){
        printf("\nNo subset possible");
    }
}