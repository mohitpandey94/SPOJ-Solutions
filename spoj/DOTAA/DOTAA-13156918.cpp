#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#ifndef ONLINE_JUDGE
#define gc getchar
#else
#define gc getchar_unlocked
#endif
#define ll long long
#define nl() printf ("\n")
#define pi(x) printf ("%d",x)
#define pl(x) printf ("%lld",x)
#define pc(x) printf ("%c",x)
#define ps(x) printf ("%s",x)
#define pb(x) push_back(x)
#define repu(i,n,step) for (;i<n;i+=step)
#define repd(i,n) for (;i>=0;i--)
using namespace std;
int readi () {
	int n=0;
	char c=gc();
	while (c<48) c=gc();
	while (c>47) {
		n=n*10+c-'0';
		c=gc();
	}
	return n;
}
ll readl () {
	ll n=0;
	char c=gc();
	while (c<48) c=gc();
	while (c>47) {
		n=n*10+c-'0';
		c=gc();
	}
	return n;
}

int main() {
        int t,n,m,d,i;
        t=readi();
        while (t--) {
                n=readi();m=readi();d=readi();
                int h[n];
                i=0;
                repu(i,n,1) {
                        h[i]=readi();
                        while (h[i]>d) {
                                h[i] -= d;
                                m--;
                        }
                }

                if (m<=0) ps("YES\n");
                else ps("NO\n");
        }
return 0;
}
