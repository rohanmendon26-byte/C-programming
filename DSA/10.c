#include<stdio.h>
#include<stdlib.h>

struct BST
{
    int data;
    struct BST *rchild;
    struct BST *lchild;
};

typedef struct BST *NODE;

NODE create()
{
    NODE temp;
    temp=(struct BST *)malloc(sizeof(struct BST));
    printf("\nEnter the value:");
    scanf("%d",&temp->data);
    temp->rchild=NULL;
    temp->lchild=NULL;
    return temp;
}

void insert(NODE root,NODE newnode)
{
    if(newnode->data<root->data)
    {
        if(root->lchild==NULL)
           root->lchild=newnode;
        else 
           insert(root->lchild,newnode);
    }

    if(newnode->data>root->data)
    {
        if(root->rchild==NULL)
           root->rchild=newnode;
        else 
           insert(root->rchild,newnode);
    }
}

void search(NODE root)
{
    int key; 
    NODE cur;
    if(root==NULL)
    {
        printf("\nRoot is empty");
        return;
    }
    printf("\nEnter the key element to be searched:");
    scanf("%d",&key);
    while(cur!=NULL)
    {
        if(cur->data==key)
        {
            printf("\nThe key element is found");
            return;
        }
        if(key<cur->data)
           cur=cur->lchild;
        else
           cur=cur->rchild;
    }
    printf("\nKey element is not found in BST");
}

void preorder(NODE root)
{
    if(root!=NULL)
    {
        printf("%d",root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void inorder(NODE root)
{
    if(root!=NULL)
    {
        inorder(root->lchild);
        printf("%d",root->data);
        inorder(root->rchild);
    }
}

void postorder(NODE root)
{
    if(root!=NULL)
    {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d",root->data);
    }
}

void main()
{
    int ch,key,val,i,n;
    NODE root=NULL,newnode;
    while(1)
    {
        printf("\n1.create a BST\n2.BST traversals\n3.search\n4.exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
               printf("\nEnter the number of elements:");
               scanf("%d",&n);
               for(i=1;i<=n;i++)
               {
                newnode=create();
                if(root==NULL)
                  root=newnode;
                else
                  insert(root,newnode);
               }
               break;

            case 2:
               if(root==NULL)
                  printf("\nRoot is empty");
                else
                {
                    printf("\nPreorder display");
                    preorder(root);
                    printf("\ninorder display");
                    inorder(root);
                    printf("\nPostorder display");
                    postorder(root);
                }
                break;

            case 3:
               search(root);
               break;

            case 4:
               exit(0);
        }
    }
}