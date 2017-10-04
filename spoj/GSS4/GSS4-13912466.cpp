#include <bits/stdc++.h>
#include <string.h>
#define ll long long
#define si(x) scanf("%lld",&x)
#define gc getchar_unlocked
using namespace std;
ll readl() {
	ll n=0;
	char c=gc();
	while (c < '0') c=gc();
	while (c>='0' && c<='9') {
		n=n*10+c-'0';
		c=gc();
	}
	return n;
}
int readi() {
	int n=0;
	char c=gc();
	while (c < '0') c=gc();
	while (c>='0' && c<='9') {
		n=n*10+c-'0';
		c=gc();
	}
	return n;
}

ll bit1[100002];//,bit2[100002];
ll a[100002];
int root[100002];
void update(ll bit[], int idx, ll val, int n){
    for(int x = idx;x <= n;x += x & -x)
        bit[x] += val;
}
 
ll query(ll bit[], int idx){
    long long ret = 0;
 
    for(int x = idx;x > 0;x -= x & -x)
        ret += bit[x];
 
    return ret;
}
int find(int u) {
	if(u != root[u]) root[u] = find(root[u]);
	return root[u];
}
int main() {
	int type,x,y,c,t,n,i;
	//si(t);
	for (t=1; scanf("%d",&n) == 1;t++) {
		//cout<<n<<":\n";
		for (i=1;i<=n;i++) {
			a[i]=readl();
			update(bit1,i,a[i],n);
			root[i]=i;
		}
		c=readi();
		printf("Case #%d:\n",t);
		while (c--) {
		type=readi();x=readi();y=readi();
		if (x > y) swap(x,y);
		if (type == 0) {
			i=find(x);
			while (x <=i && i <= y) {
				if (a[i] != 1) {
					update(bit1,i,-a[i],n);
					a[i] = sqrt(a[i]);
					update(bit1,i,a[i],n);
					if (a[i] == 1) root[i] = i+1;
				}
				i=find(i+1);
			}
		}
		else {
			printf("%lld\n",query(bit1,y)-query(bit1,x-1));
		}
		}
		printf("\n");
		memset(bit1,0,sizeof bit1);
	}
	return 0;
}