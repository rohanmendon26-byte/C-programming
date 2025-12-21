#include<stdio.h>
char STR[100],PAT[100],REP[100],ans[100];

void readstring()
{
    printf("Enter the main string:\n");
    scanf("%[^\n]",STR);
    getchar();
    printf("Enter the pattern string:\n");
    scanf("%[^\n]",PAT);
    getchar();
    printf("Enter the replace string:\n");
    scanf("%[^\n]",REP);
    getchar();
}

void searchreplacestring()
{
    int i,j,c,m,k,flag=0;
    i=j=c=m=0;
    while(STR[c]!='\0')
    {
        if(STR[m]==PAT[i])
        {
            m++;
            i++;
            if(PAT[i]=='\0')
            {
                flag=1;
                for(k=0;REP[k]!='\0';k++,j++)
                {
                    ans[j]=REP[k];
                    i=0;
                    c=m;
                }
            }
        }
            else
            {
                ans[j]=STR[c];
                j++;
                c++;
                i=0;
                m=c;
            }
        }
    
        if(flag==0)
        {
            printf("pattern does'nt found:\n");
        }
        else
        {
            ans[j]='\0';
            printf("The resultant string is %s\n",ans);
        }
}

int main()
{
    readstring();
    searchreplacestring();
}