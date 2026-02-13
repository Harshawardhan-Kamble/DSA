#include<stdio.h>
void maxNmin(int [],int );
int main(){
  int arr[10]={5,8,3,9,6,2,10,7,-1,4};
  maxNmin(arr,10);
  return 0;
}
void maxNmin(int arr[],int n){
    if(n <= 0){
        printf("Invalid array size\n");
        return;
    }
  int max=arr[0];
  int min=arr[0];
  for(int i=1;i<n;i++){
    if(arr[i]>max){
      max=arr[i];
    }
    if(arr[i]<min){
      min=arr[i];
    }
  }
  printf("Max is %d and Min is %d",max,min);
}
