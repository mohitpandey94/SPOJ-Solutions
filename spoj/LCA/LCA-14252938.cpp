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

void findparent (int u, int v, int parent[]) {
    int vis[1010] = {0};
    vis[u] = 1;
    while (u != parent[u]) {
        vis[u] = 1;
        u = parent[u];
    }
    vis[u] = 1;
    while (vis[v] != 1) {
        v = parent[v];
    }
    cout<<v<<"\n";
    return ;
}
int main() {
    int node,curnode;
    int t,n,m,q,u,v;
    t = readi();
    repu(i,1,t+1,1) {
        n = readi();
        int parent[1010];
        curnode = 1;
        repu(j,1,n+1,1)
            parent[j] = j;
        while (n--) {
            m = readi();
            while (m--) {
                node = readi();
                parent[node] = curnode;
            }
            curnode++;
        }
        q = readi();
        cout<<"Case "<<i<<":\n";
        while (q--) {
            u = readi();
            v = readi();
            findparent(u,v,parent);
        }
        //parent.clear();
    }
return 0;
}
/*
13
3 2 3 4
0
3 5 6 7
0
0
2 8 9
2 10 11
0
0
2 12 13
0
0
0

*/
