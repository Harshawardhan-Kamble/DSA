#include<iostream>
using namespace std;
void print(int);
int main(){
  int n;
  cout<<"enter n";
  cin>>n;
  print(n);
  return 0;
}
void print(int n){

  if(n<2)return;
  if (n%2!=0){
    n=n-1;
  }
  print(n-2);
  cout<<n;
}
