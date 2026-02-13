#include<stdio.h>
#include<stdlib.h>
int main(){
  int A[11]={6,7,8,9,10,11,13,14,15,16,17};
  int l=A[0];
  int h=A[10];
  int diff=l-0;
  for(int i=0;i<11;i++){
    if(A[i]-i!=diff){
      printf("Missing Number is :- %d",i+diff);
      break;
    }
  }
  return  0;
}

