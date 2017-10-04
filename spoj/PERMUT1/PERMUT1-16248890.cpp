#include <bits/stdc++.h>
#define fu(i, a, n) for (int i = a; i < n; i++)
#define fd(i, n, a) for (int i = n; i >= a; i--)
#define rep(i,n) fu(i,0,n)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pii>
#define sl(x) scanf("%lld", &x); //sl(x) is for long long int.
#define si(x) scanf("%d", &x);
#define pl(x) printf("%lld", x);  //pl(x) is for long long int.
#define pln(x) printf("%lld\n", x);  //..n(x) is for printing with New Line.
#define ps(x) printf("%lld ", x);  //..s(x) is for printing with Space.
#define pi(x) printf("%d", x);
#define pin(x) printf("%d\n", x);
#define pis(x) printf("%d ", x);
#define gc getchar_unlocked
#define ll long long
using namespace std;
int readi() {int n=0,sign=false;char c = gc();
    while (c < '0' || c > '9') { if (c == '-') sign=true; c=gc();}
    while (c>='0' && c<='9') {n=n*10+c-'0';c=gc();}
    if (sign) return -n; return n;
}
ll readl() {ll n=0,sign=false;char c = gc();
    while (c < '0' || c > '9') { if (c == '-') sign=true; c=gc();}
    while (c>='0' && c<='9') {n=n*10+c-'0';c=gc();}
    if (sign) return -n; return n;
}
ll count (ll x) {
    if (x<0) return 0;
    return ((x*(x+1))/2);
}
int memo[13][100];
int rec (int n, int k) {
	if (n == 1) {
		if (k > 0) return 0;
		return 1;
	}
	if (memo[n][k] != -1) return memo[n][k];
	int ans=0;
	for (int j=0; j < n && k-j >= 0; j++) {
		ans += rec (n-1,k-j);
	}
	return memo[n][k] = ans;
}
int main() {
	#ifndef ONLINE_JUDGE
    freopen("/home/placements/input.txt", "r", stdin);
    #endif
    int t,n,k;
    cin>>t;
    while (t--) {
    	cin>>n>>k;
    	memset(memo,-1,sizeof(memo));
    	cout<<rec (n,k)<<"\n";

    }
    return 0;
}