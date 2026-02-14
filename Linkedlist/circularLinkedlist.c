#include<stdio.h>
#include<stdlib.h>
struct node {
  int data;
  struct node *next;
};

void createNode(struct node **tail){
struct node *newNode;
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
  if(*tail==NULL){
    *tail=newNode;
    (*tail)->next=newNode;
  }
  else{
  newNode->next=(*tail)->next;
  (*tail)->next=newNode;
  *tail=newNode;
  }
    do {
      printf("Enter 1 to insert node  or  0 to exit\n");
      scanf("%d",&choice);
    } while (choice!=0 && choice!=1);
}
}

void displayNode(struct node *tail){
 if(tail==NULL) {
    printf("list is empty");
    return;
  }
  struct node *temp=tail->next;

  do {
    printf("%d ",temp->data);
    temp=temp->next;
  } while (temp!=tail->next);
}

int main(){
  struct node *tail=NULL;
  createNode(&tail);
  displayNode(tail);
  return 0;
}
