#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
   int k;
   string s,w;
   int dp[1002][1002],smt[1002][1002],n,m;
   cin>>k;
   while (k) {
       cin>>s>>w;
       n=s.length();
       m=w.length();
       for (int i=0;i<=n;i++) smt[i][0]=dp[i][0]=0;
       for (int i=0;i<=m;i++) smt[0][i]=dp[0][i]=0;
       for (int i=1;i<=n;i++) {
           for (int j=1;j<=m;j++) {
               smt[i][j]=0;
               dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
               if (s[i-1] == w[j-1]) {
                    smt[i][j] = smt[i - 1][j - 1] + 1;
                    if (smt[i][j] >= k) {
                        for(int p = k; p <= smt[i][j]; p++) {
                            dp[i][j] = max(dp[i][j], dp[i - p][j - p] + p);
                        }
                    }
                }
           }
       }
       cout<<dp[n][m]<<endl;
       cin>>k;
   }
   return 0;
}
