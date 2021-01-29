#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int e;
    struct node*left;
    struct node * right;
};
struct que
{
    struct node *a[20];
    int f;
    int r;
    
};

struct que enqueu(struct que q, struct node *ele)
{
    q.r++;
    q.a[q.r]=ele;
    return q;
}
int isempty(struct que *q)
{
    if(q->f==q->r)
        return 1;
    else
        return 0;
}
struct node *dequeu(struct que *q)
{
    if(q->f==q->r)
        return NULL;
    else
    {
            q->f++;
            return q->a[q->f];
    }
}
void print(struct node * root)
{
        struct node *temp1;
        struct que q;
        //q=(struct que*)malloc(sizeof(struct que));
        q.r=-1;
        q.f=-1;
        q=enqueu(q,root);
        while(!isempty(&q))
        {
            temp1=dequeu(&q);
            printf("%d",temp1->e);
            if(temp1->left!=NULL)
            {
                q=enqueu(q,temp1->left);
            }
            if(temp1->right!=NULL)
            {
                q=enqueu(q,temp1->right);
            }
        }
}
struct node * insert(struct node*root, int ele)
{
    if (root==NULL)
    {
        root= (struct node*)malloc(sizeof(struct node));
        root->e=ele;
        root->left=NULL;
        root->right=NULL;
    }
    else
    {
        struct node * temp, *temp1;
        temp=(struct node *)malloc(sizeof(struct node));
        temp->e=ele;
        temp->left=NULL;
        temp->right=NULL;
        struct que q;
        //q=(struct que*)malloc(sizeof(struct que));
        q.r=-1;
        q.f=-1;
        q=enqueu(q,root);
        while(!isempty(&q))
        {
            temp1=dequeu(&q);
            if(temp1->left!=NULL)
            {
                q=enqueu(q,temp1->left);
            }
            else
            {
                temp1->left=temp;        
                break;
            }
            if(temp1->right!=NULL)
            {
                q=enqueu(q,temp1->right);
            }
            else
            {
                temp1->right=temp;
                break;
            }
                
        }
    }
    return root;
}
void main()
{
    int op,ele;
    struct node * root=NULL;
    do{
    printf("enter yor option 1.insert, 2.print, 3.exit");
    scanf("%d",&op);
    switch(op)
    {
        case 1:
                printf("please enter the element that you want to insert");
                scanf("%d",&ele);
                root=insert(root, ele);
                break;
        case 2:
                print(root);
                break;
        case 3:
                break;
        default:
                printf("invalid oprion please try again");
    }
    }while(op!=3);
}
