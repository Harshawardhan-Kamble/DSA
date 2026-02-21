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
void insertNode(struct node **tail,int index,int number){
  struct node *newNode,*temp;
  int count=0;
   if(*tail==NULL){
    if(index==1){
      newNode=(struct node *)malloc(sizeof (struct node)); 
      if(newNode==NULL){
      printf("failed to allocate memory");
      return;
      }
      newNode->data=number;
     *tail=newNode;
     newNode->next=*tail;
      return;
    }
    else{
    printf("Invalid index \n");
    return;
  }
  }
  // here we will count nodes 
  temp=(*tail)->next;
  do {
    count++;
    temp=temp->next;
  } while (temp!=(*tail)->next);
  if(index<1 || index>count+1){
    printf("Invalid index \n");
    return;
  }
  index--;
      newNode=(struct node *)malloc(sizeof (struct node));
      
      if(newNode==NULL){
      printf("failed to allocate memory");
      return;
      }
newNode->data=number;
   if(index==0){
    newNode->next=(*tail)->next;
    (*tail)->next=newNode;
    return;
  }
  temp=(*tail)->next;
  for(int i=0;i<index-1;i++){
    temp=temp->next;
  }
  //this is insertion at specific position;
  newNode->next=temp->next;
  temp->next=newNode;
  if(temp==*tail){
    *tail=newNode;
  }
}
/*
| Operation            | Time |
| -------------------- | ---- |
| Count nodes          | O(n) |
| Traverse to position | O(n) |
| Insert               | O(1) |
Total worst case: O(n)
also insert at index is O(n)
*/

void deleteNode(struct node **tail,int index){
  int count=0;
  struct node *temp,*prev;
  index--;
  // check if empty first;
  if(*tail==NULL){
    printf("List is empty already. Can't perform delete on empty list");
    return;
  }

  // for delete head;
  if(index==0){
    //two cases 
    //this is for single node
    if(*tail==(*tail)->next){
      free(*tail);
      *tail=NULL;
      return;
    }
    //2. multiple nodes
    else{
       temp=(*tail)->next;    
      (*tail)->next=temp->next;
      free(temp);
      return;
    }
  }
 temp=(*tail)->next;
  // for deleting for specific position
  for(int i=0;i<index-1&&temp!=*tail;i++){
    prev=temp;
    temp=temp->next;
    ++count;
  }

  if(count<index){
    printf("Invalid index");
    return;
  }
  prev->next=temp->next;
  free(temp->next);
// delete at end;
  if(temp==*tail){
    prev->next=(*tail)->next;
    free(*tail);
    *tail=prev;
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
  insertNode(&tail,6,60);
  deleteNode(&tail,8);
  displayNode(tail);
  return 0;
}
