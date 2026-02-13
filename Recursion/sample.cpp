int sum(int );
int main() {
  int n=10;
  int sums=0;
  sums=sum(10);
    return sums;
}
int sum(int n){
  if(n<0){
    return 0;
  }
  return sum(n-1)+n;
}
