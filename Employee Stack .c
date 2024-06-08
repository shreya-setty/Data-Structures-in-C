#include<stdio.h>
#include<stdlib.h>
struct emp 
{
    int id;
    char name[21];
    int salary;
};
typedef struct emp ST;
void push (ST*, int*, int*);
void display(ST*, int,int);
int main()
{
    int n, top=-1;
    ST* a = (ST*)malloc(sizeof(ST));
    printf("Enter number of employees\n");
    scanf("%d",&n);
    push(a,&top,&n);
    display(a, top, n);
    
}
void push (ST* a, int* top, int* n)
{
    if ((*top)==(*n)-1)
    {
        printf("stack overflow, increasing size\n ");
        a=(ST*)realloc(a,sizeof(*n)*2);
    }
    (*top)++;
    printf("Enter details\n");
    scanf("%d",&(a[*top].id));
    scanf("%s",a[*top].name);
    scanf("%d",&(a[*top].salary));
    return;
}
void display(ST* a, int top, int n)
{
    if (top==-1)
    {
        printf("stack underflow");
        return;
    }
    for(;top>=0;top--)
    {
        printf("id: %d\nname: %s\nsalary: %d\n", a[top].id, a[top].name, a[top].salary);
    }
    return;
}
