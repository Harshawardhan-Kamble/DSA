#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
  };

void createNode(struct node **ptr){
  struct node *temp,*newnode;
  int choice=1;
  while(choice){
  newnode=(struct node *)malloc(sizeof (struct node));
    if(newnode==NULL){
      printf("failed to allocate memory");
      return;
    }
  printf("Enter data ");
  scanf("%d",&newnode->data);
  newnode->next=0;
  if(*ptr==NULL){
      *ptr=temp=newnode;
      }
  else{
    temp->next=newnode;
    temp=newnode;
    }
  do {
 printf("Enter 1 to insert new node or 0 to exit ");
  scanf("%d",&choice);
if (choice != 0 && choice != 1) {
                printf("Invalid input! Only 0 or 1 allowed.\n");
            }
  } while(choice!=0 && choice!=1);
}
}

void insertNode(struct node **ptr,int index,int number){
struct node *newnode,*temp;
 int count=0;
temp=*ptr;
  while(temp!=NULL){
    count++;
    temp=temp->next;
  }
  if(index < 0 || index >count){
    printf("Invalid index\n");
    return;
  }
  newnode=(struct node *)malloc(sizeof (struct node));
if (newnode == NULL) {
    printf("Memory allocation failed\n");
    return;
}
  newnode->data=number;
  newnode->next=0;
  if(index==0){
    newnode->next=*ptr;
    *ptr=newnode;
    return;
  }
  temp=*ptr;
  for(int i=0;i<index-1;i++){
   temp=temp->next;
  }
  newnode->next=temp->next;
  temp->next=newnode;
}

void deleteNode(struct node **ptr,int index){
  struct node *temp,*x;
  int count=0;

if (*ptr == NULL) {
    printf("List is empty\n");
    return;
}
  temp=*ptr;
  while(temp!=NULL){
    count++;
    temp=temp->next;
  }
  if(index<0 || index>=count){
    printf("Invalid Index \n");
    return;
  }
temp=*ptr;
  if(index==0){
    *ptr=temp->next;
    free(temp);
    return;
  }
  for(int i=0;i<index-1;i++){
    temp=temp->next;
  }
  x=temp->next;
 if (x == NULL) {
        printf("Invalid Index\n");
        return;
    }

    temp->next = x->next;
  free(x);
  x=NULL;
}

void getLength(struct node *ptr){
  struct node *temp;
  int count=0;
  temp=ptr;
  if(temp==NULL){
 printf("Length of list is empty \n" );

  }
  while(temp!=NULL){
    ++count;
    temp=temp->next;
  }
  printf("Length of list is %d \n",count );
}

void reverseLinkedlist(struct node **ptr){
  struct node *prevNode=NULL,*currentNode,*nextNode;
  currentNode=nextNode=*ptr;
 while(nextNode!=NULL){
    nextNode=nextNode->next;
    currentNode->next=prevNode;
    prevNode=currentNode;
    currentNode=nextNode;
  }
  *ptr=prevNode;
}

void display(struct node *ptr){
  while(ptr!=NULL){
    printf("%d ",ptr->data);
    ptr=ptr->next;
    }
 printf("\n");
  }

void freeList(struct node **ptr){
  struct node *temp;
  while(*ptr!=NULL){
    temp=*ptr;
    *ptr=(*ptr)->next;
    free(temp);
  }
}
int main(){
struct node *head;
  head=NULL;
  createNode(&head);
 //insertNode(&head,4,35);
  getLength(head);
 //deleteNode(&head,5);
  reverseLinkedlist(&head);
  display(head);
  freeList(&head);
  return 0;
}

