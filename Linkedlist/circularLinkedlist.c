#include<stdio.h>
#include<stdlib.h>
struct node {
  int data;
  struct node *next;
};
void createNode(struct node **head){
struct node *newNode,*temp;
  int choice=1;
 while (choice) {
  newNode=(struct node *)malloc(sizeof (struct node));
  if(newNode==NULL){
    printf("Failed to allocate Memory");
    return;
  }
 
  printf("Enter data \n");
  scanf("%d",&newNode->data);
  newNode->next=NULL;
  if(*head==NULL){
    *head=temp=newNode;
  }
  else{
    temp->next=newNode;
    temp=newNode;
  }
    do {
      printf("Enter 1 to insert node  or  0 to exit\n");
      scanf("%d",&choice);
    } while (choice!=0 && choice!=1);
}
  if (*head != NULL) {
    temp->next=*head;
  }
}

void displayNode(struct node *head){
  struct node *temp;
  temp=head;
  if(head==NULL) {
    printf("list is empty");
    return;
  }
  do {
    printf("%d ",temp->data);
    temp=temp->next;
  } while (temp!=head);
}

int main(){
  struct node *head;
  head=NULL;
  createNode(&head);
  displayNode(head);
  return 0;
}
