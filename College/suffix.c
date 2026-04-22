#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

 float compute(char symbol,float op1,float op2)
 {
    int n1,n2;
    switch(symbol)
    {
        case '+':
            return op1+op2;
            break;

        case '-':
            return op1-op2;
            break;

        case '*':
            return op1*op2;
            break;

        case '/':
            return op1/op2;
            break;

        case '^':
        case '$':
            return pow(op1,op2);
            break;

        case '%':
            n1=op1,n2=op2;
            return n1%n2;
            break;
    }
 }

 int main()
 {
    float res,s[20],op1,op2;
    int top,i;
    char symbol,postfix[20];
    printf("\nEnter the postfix expression:");
    scanf("%s",postfix);
    top=-1;
    for(i=0;i<strlen(postfix);i++)
    {
        symbol=postfix[i];
        if(isdigit(symbol))
           s[++top]=symbol-'0';
        else
        {
            op2=s[top--];
            op1=s[top--];
            res=compute(symbol,op1,op2);
            s[++top]=res;
        }
    }
    res=s[top--];
    printf("\nThe result is %f",res);
 }