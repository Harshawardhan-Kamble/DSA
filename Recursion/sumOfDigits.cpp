#include<iostream>
using namespace std;
int sumOfDigits(int);
int main(){
  int n,result;
  /*cout<<"enter n";
  cin>>n;
*/
for(int i=0;i<2;i++){
  cout<< "enter n"<<endl;
  cin>>n;
  result =sumOfDigits(n);
  cout<<result<<endl;
}
 // result=sumOfDigits(n);
 // cout<<result;
    return 0;
  }
  int sumOfDigits(int n){
    static int sum=0;
    if(n==0)return 0;
    sum+=n%10;
    sumOfDigits(n/10);
    return sum;
  }

