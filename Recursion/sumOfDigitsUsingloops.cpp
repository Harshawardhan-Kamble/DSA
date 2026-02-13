#include<iostream>
int main(){
  int sum=0; int n;
  std::cin>>n;
  if(n==0)return 0;
  while (n>0){
    sum+=n%10;
    n=n/10;
  }
  std::cout<<sum;
  return 0;
}
