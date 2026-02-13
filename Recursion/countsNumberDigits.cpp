#include<iostream>
using namespace std;
int countDigits(int n);
int main(){
  int n,count;
  cin>>n;
  count=countDigits(n);
  cout<<count;
  return 0 ;
}
int countDigits(int  n){
  int r;
 static int count=0;
 if(n<0)return -1;
  r=n%10;
  n=n/10;
  ++count;
  countDigits(n/10);
  return count;
}
