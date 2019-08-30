#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
typedef struct node
{
  int data;
  struct node *next;
}node;
int top(struct node **head)
{
    return (*head)->data;
}
void push(struct node **head,int val)
{
    node *newnode=(node *)malloc(sizeof(node));
    newnode->data=val;
    newnode->next=(*head);
    (*head)=newnode;
}
void pop(struct node **head)
{
    node * current=(*head);
    int res=(*head)->data;
    (*head)=(*head)->next;
    free(current);
    
}
int empty(node *head)
{
    if(head==NULL)
    return 1;
    else 
    return 0;
}
void list_sort(int *arr1,int *arr2)
{
    node *head=NULL;
int n1=0,n2=0;
while(n1<3&&n2<3)
{
if(arr1[n1]<arr2[n2])
{
    push(&head,arr1[n1]);
    n1++;
}
else  
{
    push(&head,arr2[n2]);
    n2++;
}
}
while(n1<3)
{
    push(&head,arr1[n1]);
    n1++;
}
while(n2<3)
{
        push(&head,arr2[n2]);
        n2++;

}
while(empty(head)==0)
{
    int n=top(&head);
    printf("%d",n);
    printf(" ");
    pop(&head);
}
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int arr2[3];
    int i;
    int arr1[3];
    for(i=0;i<3;i++)
    {
        scanf("%d",&arr1[i]);
    }
    for(i=0;i<3;i++)
    {
        scanf("%d",&arr2[i]);
    }
    /*for(i=0;i<3;i++)
    {
        printf("%d",arr1[i]);
    }*/
    list_sort(arr1,arr2);
    return 0;
}

