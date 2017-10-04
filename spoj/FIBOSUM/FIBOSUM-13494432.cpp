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
ll Z[2][2] = {{1,0},{0,1}};
ll gb[2][2] = {{1,1},{1,0}};
void multiply(ll F[2][2], ll M[2][2]) {
        //cout<<"In mult: "<<F[0][0]<<" "<<F[0][1]<<" "<<M[1][0]<<" "<<M[1][1]<<"\n";
        ll x = ((F[0][0]*M[0][0])%MOD + (F[1][0]*M[0][1])%MOD)%MOD;
        ll y = ((F[0][1]*M[0][0])%MOD + (F[1][1]*M[0][1])%MOD)%MOD;
        ll w= ((F[0][0]*M[1][0])%MOD + (F[1][0]*M[1][1])%MOD)%MOD;
        ll z = ((F[0][1]*M[1][0])%MOD + (F[1][1]*M[1][1])%MOD)%MOD;
        F[0][0] = x;
        F[0][1] = y;
        F[1][0] = w;
        F[1][1] = z;
        //cout<<F[0][0]<<" " ;
}
void powmat(ll F[2][2], ll n) {
        if (n == 0 || n == 1) {
                return;
        }
        else if (! (n & 1)){
                (powmat(F,n/2));
                multiply(F,F);
                //cout<<F[0][0]<<" "<<F[0][1]<< " "<<F[1][0]<<" "<<F[1][1]<<"\n";
        }
        else{
                powmat(F,(n-1)/2);
                multiply(F,F);
                multiply(F,gb);
        }
}

ll value (ll n) {

        ll M[2][2] = {{1,1},{1,0}};
        if (n == 0) return 0;
        if (n == 1) return 1;
        powmat(M,n-1);
        //cout<<M[0][0]<<" "<<M[0][1]<<"\n"<<M[1][0]<<" "<<M[1][1]<<"\n";
        ll ans = ((M[0][0])%MOD);
        return ans;
}


int main() {
        int t;
        ll n,m;
        t = readi();
        while (t--) {
                n = readl();
                m = readl();
                //cout<<value(m+2)<<" "<<value(n+2)<<endl;
                //if (!n) pl(value(m+2)-1);
                //else
                ll ans = (value(m+2) - value(n+2) + value(n))%MOD;
                if (ans < 0) ans += MOD;
                ans %= MOD;
                pl(ans);
                nl();
        }
return 0;
}
