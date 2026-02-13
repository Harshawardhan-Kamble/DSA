#include<iostream>
using namespace std;
int digitalRoot(int);
int main(){
  int n,result;
cin>>n;
result=digitalRoot(n);
cout<<result;
  return 0;
}
int digitalRoot(int n){
  int sum=0;
  if(n==0)return 0;
  while(n>0){
    sum+=n%10;
    n=n/10;
  }
  return digitalRoot(sum);
}
