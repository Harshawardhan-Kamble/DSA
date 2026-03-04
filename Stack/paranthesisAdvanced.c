#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define n 20
struct stack{
  char *arr;
  int top;
  int size;
};
void push(struct stack *s,char element){
  if(s->top==s->size-1){
    printf("Overflow condition");
    return;
  }
  s->top++;
  s->arr[s->top]=element;
}
void pop(struct stack *s){
  if(s->top==-1){
     printf("underflow condition");
    return;
  }
  else{
    s->top--;
  }
}
bool isEmpty(struct stack *s){
  if(s->top==-1) return true;
  else return false;
}
bool isBalanced(struct stack *s,char *exp){
  for(int i=0;exp[i]!='\0';i++){
  if(exp[i]=='('|| exp[i]=='{'|| exp[i]=='['){
    push(s,exp[i]);
  }
  else if (exp[i]==')'|| exp[i]=='}'|| exp[i]==']'){
      if(isEmpty(s)){
        printf("Unbalanced");
        return false;
      };
      if(exp[i]==')' && (s->arr[s->top]=='(')){
        pop(s);
      }
      else if (exp[i]==']' && (s->arr[s->top]=='[')) {
        pop(s);
      }
      else if (exp[i]=='}' && (s->arr[s->top]=='{')) {
        pop(s);
      }
      else return false;
  }
}
  if(isEmpty(s)){
    return true;
  }
  else return false;
}
int main(){
  struct stack S;
  S.size=n;
  S.arr=(char *)malloc(n*sizeof(char));
  S.top=-1;
  char expression[]="{([a+b]*[c-d]/e}";
  if(isBalanced(&S,expression)) printf("is Balanced");
  else  printf("Not Balanced");
    free(S.arr);
  return 0; 
}
