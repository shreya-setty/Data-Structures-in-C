#include <stdio.h>
#include<stdlib.h>
struct node 
{
    struct node* llink, *rlink;
    int data;
};
typedef struct node nd;
void insert_front(nd* h)
{
    nd* t=(nd*)malloc(sizeof(nd));
    t->llink=t->rlink=NULL;
    printf("enter\n");
    scanf("%d",&(t->data));
    if (h->rlink==NULL)
    {
        h->rlink=t;
        return;
    }
    t->rlink=h->rlink;
    (h->rlink)->llink=t;
    h->rlink=t;
    return;
}
void display(nd*h)
{
    nd *t;
    if (h->rlink==NULL)
    {
        printf("DLL is empty");
        return;
    }
    printf("first to last\n");
    for (t=h->rlink;t->rlink!=NULL;t=t->rlink)
    printf("%d",t->data);
    printf("%d\n",t->data);
    printf("last to first\n");
    for (;t!=NULL;t=t->llink)
    printf("%d",t->data);
    return;
}
void insert_rear(nd* h)
{
    nd* t=(nd*)malloc(sizeof(nd));
    printf("enter\n");
    scanf("%d",&(t->data));
    t->rlink=t->llink=NULL;
    if(h->rlink==NULL)
    {
        h->rlink=t;
        return;
    }
    for(nd* l=h->rlink;l->rlink!=NULL;l=l->rlink);
    l->rlink=t;
    t->llink=l;
}
int main() 
{
    nd header= {.rlink=NULL};
    insert_front(&header);
    insert_front(&header);
    insert_front(&header);
    insert_rear(&header);
    display(&header);
    return(0);
}
