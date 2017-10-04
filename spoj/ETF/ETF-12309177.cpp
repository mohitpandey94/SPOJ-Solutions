#include <iostream>

using namespace std;

int main()
{
   int t,n,result;
   cin>>t;
   while (t--) {
       cin>>n;
       result=n;
       for (int i=2;i*i<=n;i++) {
           if (!(n%i)) result-=result/i;
           while (n%i==0) n/=i;
       }
       if (n>1) result-=result/n;
       cout<<result<<endl;
       
   }
   return 0;
}
