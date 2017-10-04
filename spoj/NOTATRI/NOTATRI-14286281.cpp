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
int bins (int a[], int val, int low, int high, int n) {
    int count = 0, mid;
    while (high -low > 1) {
        mid = (low+high)/2;
        if (a[mid] > val)
            high = mid;
        else
            low = mid;
    }
    if (a[low] > val) return low;
    else return high;
}
int main() {
    //ios::sync_with_stdio(false);
    int n;
    n = readi();
    int a[2005]; int count = 0;
    while (n) {
        repu(i,0,n,1) {
            a[i] = readi();
        }
        sort(a,a+n);

        repu(i,0,n-1,1) {
            repu(j,i+1,n,1) {
                if (a[j]+a[i] < a[n-1]) {
                    //cout<<a[i]<<" "<<a[j]<<" "<<bins(a,a[i]+a[j],j,n-1, n)<<"\n";
                    count += (n-bins(a,a[i]+a[j],j,n-1, n));
                }
            }
        }

        pi(count);nl();
        count = 0;
        n = readi();
    }
return 0;
}
