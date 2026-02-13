#include<stdio.h>
#include<stdlib.h>
struct array{
    int *A;
    int size;
    int length;
};
void displayArray(struct array *p){
  for(int i=0;i<p->length;i++){
  printf("%d",p->A[i]);
  };
}
int insertElement(struct array *p,int index,int number){
  if(index<0 || index>p->length){
    return -1;
  }
  if(p->length>=p->size){
    return -1;
  }
  for(int i=p->length;i>index;i--){
    p->A[i]=p->A[i-1];
  }
  p->A[index]=number;
  p->length++;
  return 0;
}
int deleteElement(struct array *p,int index){
   if(index<0 || index>=p->length){
    return -1;
  }
  for(int i=index;i<p->length-1;i++){
    p->A[i]=p->A[i+1];
  }
  p->length--;
  return 0;
}
void reverseArray(struct array *r){
  int i=0;
  int j=(*r).length-1;
  int temp;
  while(j-i>0){
    temp=r->A[i];
    r->A[i]=r->A[j];
    r->A[j]=temp;
    i++;
    j--;
  }
}
void leftShiftArray(struct array *p){
for(int i=0;i<p->length-1;i++){
    p->A[i]=p->A[i+1];
  }
  p->A[p->length-1]=0;
}
void insertInSortedArray(struct array *p,int number){
  // check if space available in array;
if(p->size<p->length+1)return;
  int i=p->length-1;
  while(i>=0 && p->A[i]>number){
    p->A[i+1]=p->A[i];
    i--;
  }
  p->A[i+1]=number;
  p->length++;
}
bool checkSortedArray(struct array *p){
  for(int i=0;i<=p->length-2;i++){
    if(p->A[i]>p->A[i+1])return false;
  }
  return true;
}
/*void rightShiftArray(struct array *p){
for(int i=p->length;i>0;i--){
    p->A[i]=p->A[i-1];
  }
  p->A[0]=0;
  deleteElement(p,p->length);
}*/
/*void negativeLeft(struct array *p){
  int i=0; int j=p->length-1;
  int temp;
  while(i<j){
      if(p->A[i]>=0 &&p->A[j]<=0) {

      temp=p->A[j];
      p->A[j]=p->A[i];
      p->A[i]=temp;
    }
    else{ 
      i++;
      j--;

    }
    
  }
}*/
void negativeLeft(struct array *p){
int i=0;int temp;int j=p->length-1;
while(i<j){
    while(p->A[i]<0)i++;
    while(p->A[j]>0)j--;
    if(i<j){
      temp=p->A[i];
      p->A[i]=p->A[j];
      p->A[j]=temp;
    }
}
}
void mergeArray(struct array *p,struct array *q,struct array *r){
  int i,j,k;
  i=j=k=0;
  while(i<p->length && j<q->length){
    if(p->A[i]<q->A[j]){
      r->A[k]=p->A[i];
      i++;
      k++;
    }
    else{
      r->A[k]=q->A[j];
      j++;
      k++;
    }
   }
  while( j<q->length){
      r->A[k]=q->A[j];
      j++;
      k++;
  }
  while(i<p->length){
       r->A[k]=p->A[i];
      i++;
      k++
    }
  }
void unionOfArray(struct array *p,struct array *q,struct array *r){
  int k=0;
  for(int i=0;i<p->length;i++){
    r->A[k]=p->A[i];
    ++k;
  }
  for(int j=0;j<q->length;j++){
    int count=0;
    for(int m=0;m<k;m++){
      if(q->A[j]==r->A[m]){
        ++count;
        break;
      }
    }
    if(count==0){
      r->A[k]=q->A[j];
      k++;
    }
  }
  r->length=k;
}
int main(){
  struct array arr;
  printf("Enter size");
  scanf("%d",&arr.size);
  arr.A=(int *)malloc(arr.size*sizeof(int));
  printf("Enter length of array");
  scanf("%d",&arr.length);
  if(arr.length>arr.size){
  return -1;
}
  printf("enter elements of array");
  for (int i=0;i<arr.length;i++) {
  scanf("%d",&arr.A[i]);
  };
  struct array  arr1,arr2;
  arr1.size=arr.size;
  arr1.length=arr.length;
  arr2.size=arr.size+arr1.size;
  arr2.length=arr.length+arr1.length;
  arr1.A=(int*) malloc(arr1.size * sizeof(int));
   printf("enter elements of array 1");
  for (int i=0;i<arr1.length;i++) {
  scanf("%d",&arr1.A[i]);
  };
  arr2.A=(int*) malloc(arr2.size * sizeof(int));
  unionOfArray(&arr,&arr1,&arr2);
  //negativeLeft(&arr);
  /*insertElement(&arr,3,35);
  deleteElement(&arr,3);
  leftShiftArray(&arr);
  rightShiftArray(&arr);
  checkSortedArray(&arr);
  insertInSortedArray(&arr,35);*/
  mergeArray(&arr,&arr1,&arr2);
  displayArray(&arr);
  reverseArray(&arr);
  free(arr.A);
  arr.A=NULL;
  free(arr1.A);
  arr1.A=NULL; 
  free(arr2.A);
  arr2.A=NULL; 
  return 0;
}

