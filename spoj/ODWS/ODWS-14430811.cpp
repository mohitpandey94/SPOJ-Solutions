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
#define MOD 1000000007
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
ll powers[101];
void calc () {
    ll result = 1, temp, mul = 26;
    repu(b,0,101,1) {
        temp = b;
        mul = 26, result = 1;
        while (temp) {
            if (temp&1) result *= mul;
            temp >>= 1;
            mul *= mul;
            if (mul >= MOD) mul %= MOD;
            if (result >= MOD) result %= MOD;
        }
        powers[b] = result;
    }
}
ll ways (string s) {
    ll ans =0 ;
    int n = s.length();
    for (int i = n-1; i >= 0; i--) {
        ans = ((s[i]-'a'+1)*powers[n-i-1] + ans )%MOD;
    }

    return ans;
}
int main() {
    calc();
    int tc,ans;
    string s, t;
    cin>>tc;
    repu(tcc,1,tc+1,1) {
        cin>>s>>t;
        int ls = s.length();
        //int lt = t.length();
        //if (ans <= 0) ans = 1;
        ans = (ways(t)-ways(s)-1);
        if (ans < 0) ans += MOD;
        cout<<"Case "<<tcc<<": "<<ans%MOD<<"\n";
    }
return 0;
}
/*
9
abcdefghijiklmn
xyoaredsfdfsfnm
caf
ecc
adf
cei
abcd
efgh
ach
ced
acf
cfb
ast
cfi
agh
bed
af
cc


*/
