#include <iostream>
#include <cstdio>
#include <limits.h>
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
ll knapsack[505][10005];
int main() {

        /*repu(i,0,items+1,1) {
                knapsack[i][0]=0;
                repu(j,0,capacity+1,1) {
                        if (i==0) knapsack[i][j] = INT_MAX;
                        else if (weights[i-1]>j) knapsack[i][j] = INT_MAX;
                        else if (weights[i-1] <= j)
                        knapsack[i][j] = min (knapsack[i-1][j-weights[i-1]] + val[i-1], knapsack[i-1][j]);
                        else knapsack[i][j]= knapsack[i-1][j];
                }
        }*/
        //For PIGGYBANK spoj:
        int t;int capacity, items;int i;int j,e,f;
        t=readi();
        while (t--) {
                e = readi(),f=readi();
                capacity=f-e;
                items = readi();
                int weights[items+1],val[items+1];
                repu(i,1,items+1,1) {
                        val[i]=readi(); weights[i] = readi();
                }
                knapsack[0][0]=0;
                repu(i,1,items+1,1)
                        knapsack[i][0] = 0;
                repu(i,1,items+1,1) {
                        repu(j,1,capacity+1,1) {
                                if (i == 1 && j < weights[i])
                                        knapsack[i][j] = INT_MAX;
                                else if (i == 1)
                                        knapsack[i][j] = val[i] + knapsack[i][j - weights[i]];
                                else if (j < weights[i])
                                        knapsack[i][j] = knapsack[i - 1][j];
                                else
                                        knapsack[i][j] = min(knapsack[i - 1][j],val[i] + knapsack[i][j - weights[i]]);
                        }
                }
                if (knapsack[items][capacity]<INT_MAX) {
                        ps("The minimum amount of money in the piggy-bank is ");pl(knapsack[items][capacity]);ps(".");nl();
                }
                else ps("This is impossible.\n");
        }
return 0;
}
