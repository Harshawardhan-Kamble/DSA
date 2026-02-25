#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *next;
};
void createNode(struct node **head){
  int choice=1;
  while(choice){
  struct node *newNode;
  newNode=(struct node *) malloc(sizeof (struct node));
    if(!newNode){
      printf("Overflow");
      return;
    }
    printf("Enter data ");
    scanf("%d",&newNode->data);
    newNode->next=0;
    if(*head==NULL){
      *head=newNode;
    }
    else{
      newNode->next=*head;
      *head=newNode;
    }
    do {
      printf("enter 1 to create node or 0 to delete \n");
      scanf("%d",&choice);
    } while (choice!=0 && choice!=1);
  }
}
bool isEmpty(struct node *head){
  (head==NULL)?true:false;
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
void peek(struct node  *head){
printf("Top is %d",(head)->data);
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
  isEmpty(head);
  createNode(&head);
  push(&head,60);
  push(&head,70);
  push(&head,80);
  push(&head,90);
  pop(&head);
  peek(head);
  display(head);
  return 0; 
}
