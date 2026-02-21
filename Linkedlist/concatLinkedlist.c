#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *next;
};

void createNode(struct node **head){
  struct node *newnode,*temp;
  int choice=1;
  while(choice){
  newnode=(struct node *)malloc(sizeof(struct node));
  if(newnode==NULL){
     printf("failed to allocate memory");
    return;
  }
    printf("Enter data ");
    scanf("%d",&newnode->data);
    newnode->next=0;
  if(*head==NULL){
    *head=temp=newnode;
  }
  else{
    temp->next=newnode;
    temp=newnode;
  }
  do {
    printf("Enter 1 to create node or 0 to exit ");
    scanf("%d",&choice);
  } while (choice!=0 && choice!=1);
  }
}
void concat(struct node **head1,struct node **head2){
if (*head1 == NULL) {
        *head1 = *head2;   // agar first empty hai toh result is second list
        return;
    }
  struct node *temp=*head1;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  temp->next=*head2;
}

void display(struct node *head){
  struct node *temp=head;
  while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->next;
  }
}

int main(){
  struct node *head1=NULL;
  struct node *head2=NULL;
  createNode(&head1);
  createNode(&head2);
  concat(&head1,&head2);
  display(head1);
  return 0;
}
