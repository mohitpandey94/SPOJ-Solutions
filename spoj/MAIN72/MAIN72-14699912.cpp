#include <iostream>
#include <cstring>
using namespace std;
bool dp[100005][105];
int a[105];
int main() {
	ios_base::sync_with_stdio(false);
	// your code goes here
	int t,n,sum;
	cin>>t;
	while (t--) {
		cin>>n;
		sum=0;
		for (int i=0;i<n;i++) cin>>a[i], sum += a[i];
		memset(dp,false,sizeof dp);
		for (int i=0;i<=n;i++)
			dp[0][i] = true;
		for (int i=1;i<=sum;i++) dp[i][0] = false;
		for (int i=1;i<=sum;i++) {
			for (int j=1;j<=n;j++) {
				dp[i][j] = dp[i][j-1];
				if (i >= a[j-1]) {
					dp[i][j] = dp[i][j]|dp[i-a[j-1]][j-1];
					//cout<<i<<" "<<a[j-1]<<" "<<dp[i][j]<<"\n";
				}
			}
		}
		int ans=0;
		for (int i=0;i<=sum; i++) if (dp[i][n]) ans += i;
		/*
		for (int i=0;i<=sum;i++) {
			for (int j=1;j<=n;j++) if (dp[i][j]) cout<<i<<" "<<j<<",";
			cout<<"\n";
		}
		cout<<sum<<" "<<n;
		//if (dp[sum][n]) cout<<"true";
		*/
		cout<<ans<<"\n";
	}		
	return 0;
}