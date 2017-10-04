#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
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
#define MAXN 100010

using namespace std;
int readi () {
	int n=0,neg=0;
	char c=gc();
	while (c<48 && c>57 && c!='-'){
                c=gc();
	}
	if (c=='-') {
                neg=1;
                c=gc();
	}
	while (c>47) {
		n=n*10+c-'0';
		c=gc();
	}
	if (neg) n*=-1;
	return n;
}
ll readl () {
	ll n=0;
	int neg=0;
	char c=gc();
	while (c<48 && c>57 && c!='-') c=gc();
	if (c=='-') {
                neg=1;
                c=gc();
	}
	while (c>47) {
		n=n*10+c-'0';
		c=gc();
	}
	if (neg==1) n*=-1;
	return n;
}
ll M[MAXN][50];
ll a[MAXN];
void precomp(ll n) {
        ll i=0,j=1;
        repu(i,MAXN,1) M[i][0]=i;
        for (j=1;1<<j <= n;j++) {
                for (i=0;i+(1<<j) -1 < n;i++) {
                        if (a[M[i][j-1]]<a[M[i+(1<<(j-1))][j-1]]) M[i][j] = M[i][j-1];
                        else M[i][j] = M[i+(1<<(j-1))][j-1];
                }
        }
}
int main() {
        int t,c=1;
        ll n,q,k,i=0,j;;
        t=readi();
        repu(c,t+1,1) {
                n=readi();
                q=readi();
                i=0;
                repu(i,n,1) a[i]=readi();
                //repu(i,n,1) pi(a[i]);
                //nl();

                precomp(n);
                printf("Scenario #%d:\n",c);;
                //nl();nl();
                while (q--) {
                        i=readi();
                        i--;
                        j=readi();
                        j--;
                        k = log2(j-i+1);
                        //cout<<k<<":"<<a[M[i][k]]<<" "<<M[i][k]<<"\t"<<a[M[j-(1<<k)+1][k]]<<" "<<M[j-(1<<k)+1][k]<<"\n";
                        if (a[M[i][k]] <= a[M[j-(1<<k)+1][k]]) pi(a[M[i][k]]);
                        else pi(a[M[j-(1<<k)+1][k]]);
                        nl();

                }
        }

return 0;
}
/* 10 5
2 4 3 1 6 7 8 9 1 7
2 7
1 7
0 7
0 1
1 2*/

