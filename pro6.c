#include <stdio.h>
#include <stdlib.h>
struct node
{
    int co,po;
    struct node *addr;
};
typedef struct node *NODE;
NODE insertend(NODE start, int co,int po)
{
    NODE temp,cur;
    temp=(NODE)malloc(sizeof(struct node));
    temp->co=co;
    temp->po=po;
    temp->addr=NULL;
    if(start==NULL)
        return temp;
    cur=start;
    while(cur->addr!=NULL)
        cur=cur->addr;
    cur->addr=temp;
    return start;
}
void display(NODE start)
{
    NODE temp;
    if(start==NULL)
        printf("Polynomial is empty");
    else
    {
        temp=start;
        while(temp->addr!=NULL)
        {
            printf("%d*x^%d+", temp->co,temp->po);
            temp=temp->addr;
        }
        printf("%d*x^%d+", temp->co,temp->po);
    }
}
int main()
{
    NODE poly1=NULL,poly2=NULL, poly;
    int n,i,co,po;
    printf("\n read no of terms of first polynomial:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
         printf("\n read co and po of %d term:",i);
         scanf("%d%d", &co,&po);
         poly1=insertend(poly1,co,po);

    }
    printf("first polynomial is:\n");
    display(poly1);
     printf("\n read no of terms of second  polynomial:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
         printf("\n read co and po of %d term:",i);
         scanf("%d%d", &co,&po);
         poly2=insertend(poly2,co,po);

    }
    printf("second polynomial is:\n");
    display(poly2);
    return 0;
}
