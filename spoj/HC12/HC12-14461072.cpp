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
ll cr[10001][10001],a[10001],fact[10001];
/*
ll nCr (ll n, ll r) {
    if (n == r) return cr[n][r] = 1;
    if (r == 0) return cr[n][r] = 1;
    if (r == 1) return cr[n][r] = n;
    if (cr[n][r]) return cr[n][r];
    return (cr[n][r] = nCr(n-1,r)%MOD + nCr(n-1,r-1)%MOD);
}
*/
/*
void pascaltriangle () {
    int i,j;
    cr[0][0] = cr[1][0] = cr[1][1] = 1;

    repu(i,2,10001,1) {
        cr[i][0]=cr[i][i]=1;
        repu(j,1,i,1) {
            cr[i][j] = (cr[i-1][j-1] + cr[i-1][j]);
            while (cr[i][j] >= MOD) cr[i][j] -= MOD;
            if (cr[i][j] < 0) cr[i][j] += MOD;
        }
    }
}
*/
ll power (ll x, ll y) {
    //cout<<"ent pow";
    ll res = 1;
    while (y > 0) {
        if (y%2 == 1) {
            res = (res*x) > MOD ? (res*x)%MOD : (res*x);
        }
        x = (x*x) > MOD ? (x*x)%MOD : (x*x);
        y /= 2;
    }
    if (res > MOD) {
        res %= MOD;
    }
    //cout<<"ret pow";
    return res;
}
ll Inverse (ll x) {
    //cout<<"inverse";
    return (power(x,MOD-2));
}
ll calc (ll n, ll r) {
    //cout<<"calc";
    return (fact[n]*((Inverse(fact[r])*Inverse(fact[n-r]))%MOD)%MOD);
}
int main() {
    fact[0]=fact[1] = 1;
    repu(i,2,10001,1) {
        fact[i] = fact[i-1]*i;
        while (fact[i] >= MOD) fact[i] -= MOD;
        if (fact[i] < 0) fact[i] += MOD;
    }
    /*for (int k = 1; k <= 10000; k++) {
        for (int i = k-1; i <= 10000; i++) {
            nCr(i,k-1);
        }
    }*/
    //pascaltriangle();
    int t,n,k;
    ll sum = 0;
    t = readi();
    repu(tc,1,t+1,1) {
        n = readi(); k = readi();
        sum=0;
        repu(i,0,n,1) a[i] = readl();
        sort(a,a+n);
        for (ll i = n-1; i >= k-1; i--) {
            //cout<<Inverse(fact[k-1])<<" "<<Inverse(fact[i-k+1])<<" "<<Inverse(fact[k-1])*Inverse(fact[i-k+1])<<" "<<calc(i,k-1)<<" ";
            sum = sum + (a[i]*calc(i,k-1))%MOD;
            //cout<<sum<<"\n";
            while (sum >= MOD) sum -= MOD;
            if (sum < 0) sum += MOD;
        }
        //cout<<"Case #"<<tc<<": "<<sum<<"\n";
        printf("Case #%d: %lld\n",tc,sum);
    }
return 0;
}
