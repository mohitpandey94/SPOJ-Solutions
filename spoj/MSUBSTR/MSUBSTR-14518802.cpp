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
int length,ans;
char s[3002];
void longest(char s[], int n) {
    int l,r,tlen,tlen2;
    repu(i,0,n,1) {
        //odd length palindrome
        l = i; r = i;
        while (l >= 0 && r <= n-1 && s[l] == s[r]) {
            l--;r++;
        }
        tlen = r-l-1;
        //cout<<"odd:"<<r<< " "<<l<<"\n";
        //even length palindrome
        l = i; r = i+1;
        while (l >= 0 && r <= n-1 && s[l] == s[r]) l--,r++;
        tlen2 = r-l-1;
        //cout<<"even"<<r<<" "<<l<<"\n";
        tlen2 = max(tlen,tlen2);
        if (length == tlen2) ans++;
        else if (length < tlen2) {
            length =  tlen2;
            ans = 1;
        }
    }

    return ;
}
int main() {
    int t,len;
    t = readi();
    while (t--) {
        scanf("%s",&s);
        len = 0;
        while (s[++len] != '\0') ;
        longest(s,len);
        printf("%d %d\n",length,ans);
        length = ans = 0;
    }
return 0;
}
