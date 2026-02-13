#include<iostream>
using namespace std;
int digitRoot(int);
int main(){
  int n,result;
  cout<<"Enter n";
  cin>>n;
  result=digitRoot(n);
    cout<<result;
  return 0;
}
int digitRoot(int n){
  static int sum=0;
  if(n==0){
    if(sum<10){
      return sum;
    }
    else{
      n=sum;
      sum=0;
    }
  };
  sum+=(n%10);
  return digitRoot(n/10);
}
 
