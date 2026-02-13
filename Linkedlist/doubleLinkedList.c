#include<stdio.h>
#include<stdlib.h>
struct node {
  int data;
  struct node *prev;
  struct node *next;
}*tail;

void createNode(struct node **head){
  struct node *newNode;
  int choice=1;
  while(choice){
    newNode=(struct node *)malloc(sizeof(struct node));
    if(newNode==NULL){
      printf("Failed to allocate Memory");
      return;
    }
    newNode->prev=NULL;
    printf("Enter data ");
    scanf("%d",&newNode->data);
    newNode->next=0;
    if(*head==NULL){
      *head=tail=newNode;
    }
    else{
      tail->next=newNode;
      newNode->prev=tail;
      tail=newNode;
    }
    do {
      printf("Enter 1 to insert data or 0 to exit \n" );
      scanf("%d",&choice);
    } while (choice!=0 && choice!=1);
  }

}

void insertion(struct node **ptr,int index,int num){
  struct node *newNode,*temp;
  int count=0;
  temp=*ptr;
  index=index-1;
  //reason because we are internally using 0 based indexing and for user facing it will be 1 based 
 while(temp!=NULL){
    ++count;
    temp=temp->next;
  }
  if(index<0 || index>count){
    printf("Invalid index \n");
    return;
  }
  newNode=(struct node *)malloc(sizeof (struct node));
 if(newNode==NULL){
      printf("Failed to allocate Memory");
      return;
  }
  newNode->prev=NULL;
  newNode->next=NULL;
  newNode->data=num;
  temp=*ptr;
  if(index==0){
    newNode->next=*ptr;
    if(*ptr!=NULL)(*ptr)->prev=newNode;
    *ptr=newNode;
    return;
  }
  for(int i=0;i<index-1;i++){
    temp=temp->next;
  }
  // this is for insertion at end
  if(temp->next==NULL){
    temp->next=newNode;
    newNode->prev = temp;
   tail = newNode; 
    return ;
  }
  newNode->next=temp->next;
  newNode->prev=temp;
  temp->next=newNode;
  newNode->next->prev=newNode;
}

void deleteNode(struct node **ptr,int index){
  struct node *before,*after,*temp;
  int count=0;
  index--;// user centric 1 based . Internally 0 basedl
  temp=*ptr;
  while(temp!=NULL){
    ++count;
    temp=temp->next;
  }
  if(index<0 || index>=count){
    printf("Invalid index \n");
    return;
  }
  temp=*ptr;
  //what if list is empty
  if(*ptr==NULL){
    printf("List is empty \n");
    return ;
  }
  if(index==0){
    *ptr=(*ptr)->next;
    if(*ptr!=NULL)(*ptr)->prev=NULL;
    //because if *ptr was null then *ptr->prev will not exist so check first;
    else tail=NULL;
    free(temp);
    return;
  }
  for(int i=0;i<index;i++){
    temp=temp->next;
  }
  before=temp->prev;
  after=temp->next;
  if(temp->next==NULL){
    before->next=NULL;
    tail=before;
    free(temp);
    return;
  }
  before->next=after;
  after->prev=before;
  free(temp);
}

void reverseLinkedlist(struct node **ptr){
  struct node *temp,*previous;
  temp=*ptr;
tail = temp;
  previous=NULL;
  while(temp!=NULL){
    previous=temp->prev;
    temp->prev=temp->next;
    temp->next=previous;
    temp=temp->prev;
  }
  //checking whether if there is no list i.e empty list and one node;
  if(previous!=NULL) *ptr=previous->prev;
}

void displayNode(struct node *ptr){
  struct node *temp;
  temp=ptr;

  if (temp == NULL)
    return;
  if(temp->next==NULL){
    while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->prev;
    }
    return;
  }
  while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->next;
  }
}

int main(){
  struct node *head=NULL;
  createNode(&head);
  insertion(&head,5,50);
  //deleteNode(&head,6);
  reverseLinkedlist(&head);
  displayNode(head);

  return 0;
}
