#include<stdio.h>
#include<stdlib.h>
void missingElement(int *,int);
int main(){
  int *p;
  int n;
  printf("enter size of array ");
  scanf("%d",&n);
  p=(int*) malloc(n*sizeof(int));
  for(int i=0;i<n;i++){
    scanf("%d",&p[i]);
  }
  missingElement(p,n);
  free(p);
  p=NULL;
  return 0;
}
void missingElement(int *p,int n){
  int l=0;
  int h=n-1;
  int diff=*p-l;
  printf("%d",diff);
  for(int i=0;i<n;i++){
    if(p[i]-i!=diff){
      printf("missingElement is %d",i+diff);
      diff++;
    }
  }

}
