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
#define repu(i,a,n,step) for (i = a; i < n; i += step)
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
int maxx(int a, int b){
    return (a > b ? a : b);
}
int knapsack[2][2000001];
int val[501];
int weights[501];
int main() {
    int k,n,i,j,a,b,x,y,cur,prev;
    k = readi(); n = readi();
    repu(i,0,n,1) {
        val[i] = readi();
        weights[i] = readi();
    }
    repu(i,1,n+1,1) {
        x = weights[i-1];
        y = val[i-1];
        repu(j,1,k+1,1) {
            if (x <= j) {
                a = knapsack[0][j-x] + y;
                if (knapsack[1][j] < a) {
                    knapsack[1][j] = a;
                }
            }
        }
        if (i < n)
            repu(j,1,k+1,1) {
                knapsack[0][j] = knapsack[1][j];
            }
    }
    printf("%d\n",knapsack[1][k]);
return 0;
}
