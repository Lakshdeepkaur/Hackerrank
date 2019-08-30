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
int streetParade(int *arr,int n)
{
    node *head=NULL;
    int check=1;
    int curr=1,i,k=0;
    int aux[n];
    for(i=0;i<n;i++)
    {
        if(arr[i]==curr)
        {
            aux[k++]=arr[i];
            curr++;
        }
        else if(empty(head)==0)
        {
         int d=top(&head);
         if(d==curr)
         {
             aux[k]=d;
             k++;
             pop(&head);
             curr++;
             i--;
         }
         else  
        {
          push(&head,arr[i]);
        }
        }
        else  
        {
          push(&head,arr[i]);
        }
    }
    while(empty(head)!=1)
    {
        
        int d=top(&head);
         if(d==curr)
         {
             aux[k]=d;
             k++;
             pop(&head);
             curr++;
         }
         else 
        {
            check=0;
            break;
        }

    }
    if(check==0)
    return 0;
    else  
    return 1;
}

int main() {
    node *head=NULL;
    int i,n,ans;
    scanf("%d",&n);
    while(n!=0)
    {
        int arr[n];
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        int ans=streetParade(arr,n);
        if(ans==1)
        printf("yes");
        else 
        printf("no");
        printf("\n");
        scanf("%d",&n);
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

