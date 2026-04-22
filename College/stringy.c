#include<stdio.h>

char STR[100],PAT[100],REP[100],ans[100];

void readstring()
{
    printf("\nEnter the main string:");
    scanf(" %[^\n]",STR);
    getchar();
    printf("\nEnter the pattern string:");
    scanf(" %[^\n]",PAT);
    getchar();
    printf("\nEnter the replace string:");
    scanf(" %[^\n]",REP);
    getchar();
}

void searchreplacestring()
{
    int i,j,c,m,k,flag=0;
    i=j=m=c=0;
    while(STR[c]!='\0')
    {
        if(STR[m]==PAT[i])
        {
            m++;
            i++;
            if(PAT[i]=='\0')
            {
                flag=1;
                for(int k=0;REP[k]!='\0';k++,j++)
                    ans[j]=REP[k];
                i=0;
                c=m;
            }
        }
        else
        {
            ans[j]=STR[c];
            j++;
            c++;
            m=c;
            i=0;
        }
    }
    if(flag==0)
    {
        printf("\nPattern doesn't exist");
    }
    else
    {
        ans[j]='\0';
        printf("\nThe resultant string is %s:",ans);
    }
}

void main()
{
    readstring();
    searchreplacestring();
}
