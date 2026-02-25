#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
  int data;
  struct node *next;
};

bool isEmpty(struct node *head){
  return(head==NULL)?true:false;
}
void push(struct node **head,int data ){
  struct node *newNode =(struct node *)malloc(sizeof (struct node));
  if(!newNode){
    printf("Overflow");
    return;
  }
  newNode->data=data;
  newNode->next=*head;
  *head=newNode;
}
void pop(struct node **head){
 if (*head == NULL) {
        printf("Underflow\n");
        return;
    }
  struct node *temp=*head;
  *head=(*head)->next;
  free(temp);
  temp=NULL;
}
int peek(struct node  *head){
  if(head==NULL){
   
    return -1 ;
  }
return head->data;
}
void display(struct node *head){
  struct node *temp=head;
  while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->next;
  }
}
int main(){
  struct node *head=NULL;
if (isEmpty(head)) {
    printf("Stack is empty\n");
}
  push(&head,60);
  push(&head,70);
  push(&head,80);
  push(&head,90);
  pop(&head);
  int value=peek(head);
  if(value==-1){
 printf("Stack is empty\n");
  }
  else{
  printf(" top is %d \n",value);
  }
  display(head);
  return 0; 
}
