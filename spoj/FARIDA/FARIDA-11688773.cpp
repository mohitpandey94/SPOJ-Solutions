#include <stdio.h>
long long int max (long long int a, long long int b) {
    return ((a>b)?a:b);
}
int main()
{
   int t,n,i,j;
   long long int val[10001],dp[10001];
   scanf("%d",&t);
   for (j=1;j<=t;j++) {
       scanf("%d",&n);
       for (i=0;i<n;i++) {
           scanf("%lld",&val[i]);
       }
       dp[0]=val[0];
       dp[1]=max(val[1],dp[0]);
       for (i=2;i<n;i++) {
           dp[i] = max(dp[i-1],val[i]+dp[i-2]);
       }
       printf("Case %d: %lld\n",j,dp[n-1]);
   }
   
   return 0;
}
