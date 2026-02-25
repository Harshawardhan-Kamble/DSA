#include<stdio.h>
#define N 5
int stack[N];
int top=-1;
void push(int data){
  if(top==N-1){
    printf("Overflow \n");
    return;
  }
  else{
    top++;
    stack[top]=data;
  }
}
void pop(){
  if(top==-1){
    printf("Underflow \n");
    return;
  }
  else{
    top--;
  }
}
void peek(){
  if(top==-1){
    printf("Empty list");
    return;
  }
  printf("Peek is %d",stack[top]);
}
bool isEmpty(){
if(top==-1)return true;
  else
    return false;
}
bool isFull(){
  if(top==N-1)return true;
  else
    return false;
}

void display(){
  for (int i=top;i>=0;i--){
    printf("%d ",stack[i]);
  }
}
int main(){
printf("%s \n", isEmpty() ? "true" : "false");
  push(10);
  push(20);
  pop();
  push(25);
push(30);
push(35);
push(40);
printf("%s \n", isFull() ? "true" : "false");
  display();
  return 0;
}

