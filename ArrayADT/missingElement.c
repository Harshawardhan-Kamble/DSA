#include<stdio.h>
#include<stdlib.h>
int main(){
  int A[11]={1,2,3,4,5,6,8,9,10,11,12};
  int sum1=0;
  int sum2=0;
  int missingElement;
  sum1=(12*(12+1))/2;
for(int i=0;i<11;i++){
    sum2+=A[i];
  }
    missingElement=sum1-sum2;
    printf("%d",missingElement);
  return  0;
}


