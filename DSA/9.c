#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

struct polyterm{
    int coefficient;
    int pow_x;
    int pow_y;
    int pow_z;
    struct polyterm *next;
};

typedef struct polyterm *POLYPTR;

POLYPTR fnInsertTerm(POLYPTR poly,int coef,int pow_x,int pow_y,int pow_z)
{
    POLYPTR cur;
    POLYPTR newnode=(struct polyterm *)malloc(sizeof(struct polyterm));
    newnode->coefficient=coef;
    newnode->pow_x=pow_x;
    newnode->pow_y=pow_y;
    newnode->pow_z=pow_z;
    newnode->next=NULL;

    cur=poly;
    while(cur->next!=poly)
    {
        cur=cur->next;
    }
    cur->next=newnode;
    newnode->next=poly;
    return poly;
}


void fnDispPolynomial(POLYPTR poly)
{
    if(poly->next==poly)
    {
        printf("\nPolynomial is empty");
        return;
    }
    POLYPTR cur=poly->next;
    do
    {
        printf("%dx^%dy^%dz^%d",cur->coefficient,cur->pow_x,cur->pow_y,cur->pow_z);
        cur=cur->next;
        if((cur!=poly))
        {
            if(cur->coefficient>0)
               printf("+");
            else
               printf("");
        }
    }while(cur!=poly);
    printf("\n");
}


int fnEvaluatePOLYnomial(POLYPTR poly,int x,int y,int z)
{
    int result=0;
    if(poly->next==poly)
    {
        return result;
    }
    POLYPTR cur=poly->next;
    do
    {
        int termValue=cur->coefficient;
        termValue*=pow(x,cur->pow_x);
        termValue*=pow(x,cur->pow_y);
        termValue*=pow(x,cur->pow_z);
        result+=termValue;
        cur=cur->next;
    }while(cur!=poly);
    return result;
}


bool fnMatchTerm(POLYPTR p1,POLYPTR p2)
{
    bool bmatches=true;
    if(p1->pow_x!=p2->pow_x)
       bmatches=false;
    if(p1->pow_y!=p2->pow_y)
       bmatches=false;
    if(p1->pow_z!=p2->pow_z)
       bmatches=false;
    return bmatches;   
}


POLYPTR fnAddPolynomials(POLYPTR poly1,POLYPTR poly2,POLYPTR polysum)
{
    POLYPTR cur1=poly1->next;
    POLYPTR cur2=poly2->next;

    do
    {
        polysum=fnInsertTerm(polysum,cur1->coefficient,cur1->pow_x,cur1->pow_y,cur1->pow_z);
        cur1=cur1->next;
    }while(cur1!=poly1);

    do
    {
        cur1=polysum->next;
        bool bMatchFound=false;
        do
        {
            if(fnMatchTerm(cur1,cur2))
            {
                cur1->coefficient+=cur2->coefficient;
                bMatchFound=true;
                break;
            }
            cur1=cur1->next;
        }while(cur1!=polysum);

        if(!bMatchFound)
        {
            polysum=fnInsertTerm(polysum,cur2->coefficient,cur2->pow_x,cur2->pow_y,cur2->pow_z);
        }
        cur2=cur2->next;
    }while(cur2!=poly2);
    return polysum;
}

int main()
{
    POLYPTR poly1=(struct polyterm *)malloc(sizeof(struct polyterm));
    poly1->next=poly1;
    POLYPTR poly2=(struct polyterm *)malloc(sizeof(struct polyterm));
    poly2->next=poly2;
    POLYPTR polysum=(struct polyterm *)malloc(sizeof(struct polyterm));
    polysum->next=polysum;

    poly1=fnInsertTerm(poly1,6,2,2,1);
    poly1=fnInsertTerm(poly1,-4,0,1,5);
    poly1=fnInsertTerm(poly1,3,3,1,1);
    poly1=fnInsertTerm(poly1,2,1,5,1);
    poly1=fnInsertTerm(poly1,-2,1,1,3);
    printf("\nPOLY1(x,y,z)=");
    fnDispPolynomial(poly1);

    poly2=fnInsertTerm(poly2,1,1,1,1);
    poly2=fnInsertTerm(poly2,4,3,1,1);

    printf("POLY2(x,y,z)=");
    fnDispPolynomial(poly2);

    polysum=fnAddPolynomials(poly1,poly2,polysum);
    printf("\nPOLYSUM(x,y,z)=");
    fnDispPolynomial(polysum);

    int x=1,y=1,z=1;
    int iRes=fnEvaluatePOLYnomial(poly1,x,y,z);
    printf("\nresult of ploysum(%d,%d,%d):%d",x,y,z,iRes);
    return 0;

}
