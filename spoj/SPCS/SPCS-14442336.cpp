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
bool checkPalin (string s) {
    int len = s.length();

    repu(i,0,len/2,1) {
        if (s[i] != s[len-i-1]) return false;
    }
    return true;
}
int main() {
    int t,len;
    t = readi();
    while (t--) {
        string s,ans;
        cin>>s;
        len = s.length();
        ans += s[0];
        repu(i,1,len,1) {
            if (s[i] != s[i-1]) {
                ans += s[i];
            }
        }
        //cout<<ans<<" ";
        if (checkPalin(ans)) {
            cout<<"YES\n";
        }
        else {
            cout<<"NO\n";
        }
    }
return 0;
}
