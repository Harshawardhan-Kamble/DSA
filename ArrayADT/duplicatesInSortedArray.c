#include<stdio.h>
int main(){
  int A[10]={3,6,8,8,1,12,15,15,15,20};
  int lastElement=-1;
  for(int i=0;i<9;i++){
    if(A[i]==A[i+1] && lastElement!=A[i]){
      printf("%d \n",A[i]);
      lastElement=A[i];
    }
  }
  return 0;
}
