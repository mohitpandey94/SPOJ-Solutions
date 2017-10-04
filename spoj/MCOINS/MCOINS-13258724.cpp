#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <bitset>
#include <algorithm>
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
#define repu(i,a,n,step) for (i = a; i < n; i += step)
#define repd(i,a,n,step) for (i = a - 1; i >= n; i += step)
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
double power(double x, int y)
{
    double temp;
    if( y == 0)
       return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return temp*temp;
    else
    {
        if(y > 0)
            return x*temp*temp;
        else
            return (temp*temp)/x;
    }
}
int ans[1000002];
int main() {
        ll i=0,n;
        ans[0]=0; ans[1]=1;
        int k,l,m;
        k=readi(); l=readi(); m= readi();
        repu(i,2,1000002,1) {
                if (ans[i-1] == 0) ans[i]=1;
                else if (i-k >= 0 && ans[i-k] == 0) ans[i]=1;
                else if (i - l >= 0 && ans[i-l] == 0) ans[i]=1;
        }
        while (m--) {
                n = readl();
                if (ans[n] == 1) ps("A");
                else ps("B");
        }
        nl();
return 0;
}
