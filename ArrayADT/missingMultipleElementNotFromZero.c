#include<stdio.h>
#include<stdlib.h>
int main(){
  int A[11]={6,7,8,9,11,12,15,16,17,18,19};
  int l=A[0];
  int h=A[10];
  int diff=l-0;
  for(int i=0;i<11;i++){
    if(A[i]-i!=diff){
      while(diff<A[i]-i){
      printf("Missing Number is :- %d \n",i+diff);
      ++diff;
      }
    }
  }
  return  0;
}
