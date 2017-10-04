#include <iostream>
using namespace std;

int main() {
	int C,n,w[1001],v[1001],dp[1001][1001];
	cin>>C>>n;
	while (C!=0 && n!=0) {
		for (int i=0;i<n;i++) cin>>w[i]>>v[i];
		//cin>>C>>n;
		//continue;
		for (int i=0;i<=n;i++) dp[i][0]=0;
		for (int i=0;i<=n;i++) dp[0][i]=0;
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=C;j++) {
				if (w[i-1]<=j) {
					dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i-1]]+v[i-1]);
				}
				else {
					dp[i][j]=dp[i-1][j];
				}
			}
		}
		int i=C;
		while (dp[n][i-1] == dp[n][i]) i--;
		cout<<i<<" "<<dp[n][i]<<endl;
		cin>>C>>n;
	}
	return 0;
}