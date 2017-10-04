#include <bits/stdc++.h>
#include <cstring>
#ifndef ONLINE_JUDGE
#define gc getchar
#else
#define gc getchar_unlocked
#endif
#define ll long long
#define nl() printf ("\n")
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define pi(x) printf ("%d",x)
#define pl(x) printf ("%lld",x)
#define pc(x) printf ("%c",x)
#define ps(x) printf ("%s",x)
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define repu(i,a,n,step) for (int i = a; i < n; i += step)
#define repd(i,a,n,step) for (int i = a - 1; i >= n; i -= step)
using namespace std;
int readi () {
	int n=0,sign=0;
	char c=gc();
	while (c<48) {
		if (c==45) sign=1;
		c=gc();
	}
	while (c>47) {
		n=n*10+c-'0';
		c=gc();
	}
	if (sign) return (-n);
	return n;
}
ll readl () {
	ll n=0;int sign=0;
	char c=gc();
	while (c<48) {
		if (c==45) sign=1;
		c=gc();
	}
	while (c>47) {
		n=n*10+c-'0';
		c=gc();
	}
	if (sign) return (-n);
	return n;
}
int dp[1001][22][82];
int oxy[1001], nitro[1001], wt[1001];
int main() {
    int c,t,a,n;
    c = readi();
    while (c--) {
        t = readi(); a = readi(); n = readi();
        repu(i,0,n,1) {
            oxy[i] = readi();
            nitro[i] = readi();
            wt[i] = readi();
        }
        repu(i,0,n+1,1) {
            repu(j,0,t+1,1) {
                repu(k,0,a+1,1) {
                        if (i == 0) {
                            dp[i][j][k] = 99999;
                            if (j == 0 && k == 0) dp[i][j][k] = 0;
                        }
                        else
                            dp[i][j][k] = min (dp[max(0,i-1)][max(0,j-oxy[i-1])][max(0,k-nitro[i-1])] + wt[max(0,i-1)], dp[max(0,i-1)][j][k]);
                }
            }
        }
        cout<<dp[n][t][a]<<"\n";
    }
return 0;
}
/*
1
5 60
5
3 36 120
10 25 129
5 50 250
1 45 130
4 20 119

*/
