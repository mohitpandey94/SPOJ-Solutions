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
void strrev(char s[],char ss[], int len) {
    repd(i,len,0,1) {
        ss[i] = s[len-i-1];
    }
}
int dp[2][5002];
int main() {
    ios::sync_with_stdio(0);
    int t;
    char s[5002];
    char ss[5002];
    cin>>t;
    {
        cin>>s;
        int len = strlen(s);
        strrev(s,ss,len);
        //cout<<s<<" "<<ss;
        memset(dp,0,sizeof(dp));
        repu(i,1,len+1,1) {
            repu(j,1,len+1,1) {
                if (s[i-1] == ss[j-1]) {
                    dp[1][j] = dp[0][j-1]+1;
                }
                else {
                    dp[1][j] = max (dp[0][j],dp[1][j-1]);
                }
            }
            repu(k,0,len+1,1) {
                //cout<<dp[0][k]<<" "<<dp[1][k]<<"\n";
                dp[0][k] = dp[1][k];
            }
        }
        cout<<len-dp[0][len]<<"\n";
        //memset(dp,0,sizeof(dp));
    }
return 0;
}
