#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
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
ll c,x[100005],n;
int check (ll pos) {
        ll placed = 1;
        ll upto = x[0],i;
        repu(i,1,n,1) {
                if (x[i] - upto >= pos) {
                        placed++;
                        if (placed == c) return 1;
                        upto = x[i];
                }
        }
        return 0;
}
ll bin() {
        ll start = 0, end = x[n - 1],mid;
        while (start < end) {
                mid = (start+end)/2;
                if (check(mid) == 1) {
                        start = mid + 1;
                }
                else end = mid;
                //cout<<start<<" "<<end<<" "<<check(mid)<<" "<<mid<<"\n";
        }
        return (start-1);
}
int main() {
	int t;
	t=readi();
	while (t--) {
        ll i;
        n = readl(); c = readl();
        repu(i,0,n,1) x[i] = readl();
        sort(x,x+n);
        pl(bin());
        nl();
        }
return 0;
}

