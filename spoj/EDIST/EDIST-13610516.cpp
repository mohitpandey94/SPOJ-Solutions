#include <iostream>
#include <cstdio>
using namespace std;
int dp[2100][2100];
int main() {
	ios_base::sync_with_stdio(0);
	int tt,len1,len2,i,j;
	string s,t;
	cin>>tt;
	while (tt--) {
		cin>>s>>t;
		len1 = s.length();
		len2 = t.length();
		for (i=0;i<=len2;i++) dp[0][i] = i;
		for (j=0;j<=len1;j++) dp[j][0] = j;
		for (i=1;i<=len1;i++) {
			for (j=1;j<=len2;j++) {
				if (s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1];
				else {
					dp[i][j] = min ((dp[i-1][j]+1),min((dp[i][j-1]+1),(dp[i-1][j-1]+1)));
				}
			}
		}
		cout<<(dp[len1][len2])<<"\n";
	}
	return 0;
} 
