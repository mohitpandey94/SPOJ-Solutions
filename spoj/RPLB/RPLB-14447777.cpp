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
int knapsack[1005][1005];
int val[1005];
int weights[1005];
int main() {
    int t,k,m,a,b;
    t = readi();
    repu(tc,1,t+1,1) {
        m = readi(); k = readi();
        repu(i,0,m,1) {
            val[i] = weights[i] = readi();
            //val[i] = readi();
        }
        memset(knapsack,0,sizeof knapsack);
        repu(j,0,k+1,1) {
            if (j >= weights[0]) {
                knapsack[1][j] = weights[0];
            }
        }
        repu(i,2,m+1,1) {
            knapsack[i][0] = 0;
            repu(j,0,k+1,1) {
                if (i==0) knapsack[i][j] = 0;
                else if (weights[i-1]>j)
                    knapsack[i][j] = knapsack[i-1][j];
                else if (weights[i-1] <= j)
                    knapsack[i][j] = max (knapsack[i-2][j-weights[i-1]] + val[i-1], knapsack[i-1][j]);
                //else knapsack[i][j]= knapsack[i-1][j];
            }
        }
        cout<<"Scenario #"<<tc<<": "<<knapsack[m][k]<<"\n";
    }
return 0;
}
/*
6
7 100
10 20 30 40 50 60 70 
7 5
10 20 30 40 50 60 70
5 5
2 4 3 2 1 
5 5
2 4 3 2 1
5 5
2 4 3 2 1
5 5
1 8 3 7 6
*/
