#include<iostream>
using namespace std;
void reverseDigits(int n);
int main(){
  int n;
  cin>>n;
  reverseDigits(n);
  return 0;
}
void reverseDigits(int n){
  int r;
  if(n==0)return;
  r=n%10;
  cout<<r;
  reverseDigits(n/10);
}
