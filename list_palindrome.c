#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

typedef struct ListNode listnode;

listnode* listnode_new(int val) {
	listnode* node = (listnode *) malloc(sizeof(listnode));
	node->val = val;
	node->next = NULL;
	return node;
}

void addNode(listnode* A, int i){
	listnode* temp = listnode_new(i);
	listnode* t = A;
	while(t->next != NULL){
		t = t->next;
	}
	t->next = temp;
}


 int checkPalindrome(listnode *A,listnode *B)
 {
     while(A!=NULL && B!=NULL)
     {
         if(A->val != B->val)
         return 0;
         else
         {
             A=A->next;
             B=B->next;
         }
     }
     return 1;
 }
 listnode* reverse_list(listnode *first)
 {
     listnode *second=NULL;
     second =first->next;
     if(first->next==NULL)
     return first;
     else
     {
         listnode *B=reverse_list(first->next);
         first->next=second->next;
         second->next=first;
         return B;
     }

 }
int isPalin(listnode* A){
listnode *B=reverse_list(A);
return checkPalindrome(A,B);

}    
int main(){