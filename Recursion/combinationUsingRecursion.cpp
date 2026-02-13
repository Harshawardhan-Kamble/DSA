#include<iostream>
using namespace std;
int combination(int ,int );
int main(){
  int n, r,result;
  cout<<"enter n";
  cin>>n;
  cout<<"enter r";
  cin>>r;
result =combination(n,r);
cout<<result;
    return 0;
  }
int combination(int n,int r){
  if(n<r)return 0;
    if(n==0 || r==0){
      return 1;
    }
    return combination(n-1,r-1)+combination(n-1,r);
}
