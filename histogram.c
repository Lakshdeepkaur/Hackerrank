typedef struct node
{
    int data;
    struct node * next; 
}node;

void push(int value,node ** head)
{
    node * newnode=(node *)malloc(sizeof(node));
    newnode->next=(*head);
    newnode->data=value;
    (*head)=newnode;
}

int poll(node **head)
{
    node * current=(*head);
    int res=(*head)->data;
    (*head)=(*head)->next;
    free(current);
    return res;
}

int top(node ** head)
{
    
    return (*head)->data;
}

int largestRectangleArea(int* A, int n1) {
    node * head=NULL;
    int i=0,ele=0,res=0,count=0;
    for(i=0;i<n1;i++)
    {
        if(count==0)
        {
            push(i,&head);
            count++;
        }
        else
        {
            
            if(A[top(&head)]<=A[i])
            {
                push(i,&head);
                count++;
            }
            else
            {
                
               while(count>0 && A[top(&head)]>A[i])
               {
                   
                    int temp=0;
                    ele=poll(&head);
                    count--;
                    if(count==0)temp=A[ele]*i;
                    else
                    temp=A[ele]*(i-1-top(&head));
                    res= res>temp ? res : temp;
                }
                push(i,&head);
                count++;
            }
        }
    }
    while(count>0)
    {
        int temp=0;
        ele=poll(&head);
        count--;
        if(count==0)temp=A[ele]*i;
        else
        temp=A[ele]*(i-1-top(&head));
        res= res>temp ? res : temp;
    }
    return res;
    
}