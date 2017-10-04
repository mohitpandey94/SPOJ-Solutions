#include <bits/stdc++.h>
using namespace std;
int main() {
    int t,n;
    cin>>t;
    while (t--) {
	cin>>n;
	int tb[n+1][3];
	int dp[n+1][3];
	memset(dp,0,sizeof(dp));
	for (int i=0; i < n; i++) 
	    for (int j=0; j < 3; j++)
		cin>>tb[i][j];
	dp[0][0] = tb[0][0];
	dp[0][1] = tb[0][1];
	dp[0][2] = tb[0][2];
	for (int i=1; i < n; i++) {
	    dp[i][0] += min (dp[i-1][1],dp[i-1][2])+tb[i][0];
	    dp[i][1] += min(dp[i-1][0],dp[i-1][2])+tb[i][1];
	    dp[i][2] += min (dp[i-1][1],dp[i-1][0])+tb[i][2];
	}
	int ans = min (dp[n-1][0],min(dp[n-1][1],dp[n-1][2]));
	cout<<ans<<"\n";
    }
}
