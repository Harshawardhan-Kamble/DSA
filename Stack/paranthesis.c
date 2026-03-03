#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#define n 20
struct stack {
  int size;
  char *arr;
  int top;
};
void push(struct stack *s ,char element){
  if(s->top==s->size-1){
    printf("Overflow");
    return;
  }
  s->top++;
  s->arr[s->top]=element;
}
void pop(struct stack *s){
  if(s->top==-1){
    printf("empty stack");
  }
  else s->top--;
}
bool isEmpty(struct stack *s){
  if(s->top==-1) return true;
  else return false;
}
bool isBalance(struct stack *s ,char *a){
  for(int i=0;a[i]!='\0';i++){
    if(a[i]=='('){
      push(s,a[i]);
    }
    else if(a[i]==')'){
      if(isEmpty(s)){
        return false;
      }
      pop(s);
    }
  }
  if(isEmpty(s)){
    return true;
  }
  else return false;
}
int main(){
  struct stack s;
  s.size=n;
  s.arr=(char *)malloc(n*sizeof(char ));
  s.top=-1;
  char a[]="(((a+b)+(b+a))))(1+2)";
  if(isBalance(&s,a)){
    printf("balanced");
  }
  else printf("unbalanced");
free(s.arr);
   return 0;
}
