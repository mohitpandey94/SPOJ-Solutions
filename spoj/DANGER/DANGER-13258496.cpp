#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
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
/*ll joseph(ll n ,ll d) {
        if (n==1) return 1;
        else return (joseph(n - 1, d) + d-1) % n + 1;
}*/
ll joseph(ll n, ll d) {
        ll w=0,i;
        repu(i,2,n+1,1) {
                w = (w+d)%i;
        }
        return (w+1);
}
int main() {
        ll n,d,w;
        string s;
        cin>>s;
        while (s != "00e0") {
                n = (s[0]-'0')*10+(s[1]-'0');
                d = s[3]-'0';
                n *= pow(10,d);
                ll w=0,i=0;
                while ((1<<i)<=n) i++;
                i--;
                d = 1<<i;
                pl(1+(n-d)*2);
                nl();
                cin>>s;
        }
return 0;
}

