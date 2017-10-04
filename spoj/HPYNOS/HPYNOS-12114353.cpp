#include <iostream>

using namespace std;

int main()
{
  long long int n,x,ans=0,count=0,flag=1;
  int arr[1005]={0},rem;
  cin>>n;
  while (1) {
      while (n>0) {
          rem=n%10;
          ans +=rem*rem;
          n/=10;
      }
      if (arr[ans]==0) {
          arr[ans]=1;
          count++;
      }
      else {
          flag=0;
          break;
      }
      if (ans==1) {
          flag=1;
          break;
      }
      n=ans;
      ans=0;
  }
  if (flag) {
      cout<<count<<endl;
  }
  else cout<<"-1";
   return 0;
}
