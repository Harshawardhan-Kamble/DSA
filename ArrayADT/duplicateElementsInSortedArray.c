#include<stdio.h>
void duplicateElements(int [],int);
int main(){
  int arr[10]={3,6,8,8,10,12,15,15,15,20};
  duplicateElements(arr,10);
  return 0;
}
void duplicateElements( int a[],int n){
  int lastElement=-1;
  for(int i=0;i<n-1;i++){
    if(a[i]==a[i+1] && lastElement!=a[i]){
      printf(" duplicate Element is %d\n",a[i]);
      lastElement=a[i];
    }
  }
}
