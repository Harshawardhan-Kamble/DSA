#include<stdio.h>
void pairWithSumk(int *,int ,int );
void pairWithSumkOptimum(int *,int ,int );
int main(){
  int arr[10]={6,3,8,10,16,7,5,2,9,14};
  pairWithSumk(arr,10,10);
  pairWithSumkOptimum(arr,10,10);
  return 0;
}
//bruteforce
void pairWithSumk(int *p,int n,int k){
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        if(p[i]+p[j]==k){
          printf("pairs are %d and %d\n", p[i],p[j]);
        }
    }
  }
}
//
void pairWithSumkOptimum(int *p,int n,int k ){
  int H[16]={};
  for(int i=0;i<n;i++){
    H[p[i]]++;
  }
  for(int i=1;i<k/2;i++){
    if(H[i]>0 && H[k-i]>0){
      printf("pairs are %d %d\n",i,k-i);
    }
  }
}
