#include <iostream>

using namespace std;

int main()
{
   int t,n,i,j;
   long long int val[10001],dp[10001],sum1,sum2;
   cin>>t;
   for (j=1;j<=t;j++) {
       cin>>n;
       sum1=sum2=0;
       for (i=0;i<n;i++) {
           cin>>val[i];
       }
       dp[0]=val[0];
       dp[1]=max(val[1],dp[0]);
       for (i=2;i<n;i++) {
           dp[i] = max(dp[i-1],val[i]+dp[i-2]);
       }
       cout<<"Case "<<j<<": "<<(dp[n-1])<<endl;
   }
   
   return 0;
}
