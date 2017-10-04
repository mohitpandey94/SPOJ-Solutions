#include <iostream>

using namespace std;

int main()
{
  int n,m,k[101][101],dp[101][101],min,mmin=1000;
  cin>>n>>m;
  for (int i=1;i<=n;i++) {
      for (int j=1;j<=m;j++) cin>>k[i][j];
  }
  for (int i=0;i<=m;i++) dp[0][i]=0;
  for (int i=0;i<=n;i++) dp[i][0]=0;
  for (int i=0;i<=n;i++) dp[i][m+1]=999;
  for (int i=1;i<=n;i++) {
      for (int j=1;j<=m;j++) {
          min=999;
          if (j>1)
          if (dp[i-1][j-1]+k[i][j]<min) min=dp[i-1][j-1]+k[i][j];
          if (dp[i-1][j]+k[i][j]<min) min=dp[i-1][j]+k[i][j];
          if (i<=m)
          if (dp[i-1][j+1]+k[i][j]<min) min=dp[i-1][j+1]+k[i][j];
          dp[i][j]=min;
          if (i==n && min<mmin) mmin=min;
          //cout<<dp[i][j]<<" ";
      }
      //cout<<endl;
  }
  /*for (int i=0;i<=n;i++) {
      for (int j=0;j<=m;j++) cout<<dp[i][j]<<" ";
      cout<<endl;
  }*/
  cout<<mmin<<endl;
   return 0;
}
