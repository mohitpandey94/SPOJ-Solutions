#include <bits/stdc++.h>
#define fu(i, a, n) for (int i = a; i < n; i++)
#define fd(i, n, a) for (int i = n; i >= a; i--)
#define rep(i,n) fu(i,0,n)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define sl(x) scanf("%lld", &x); //sl(x) is for long long int.
#define si(x) scanf("%d", &x);
#define pl(x) printf("%lld", x);  //pl(x) is for long long int.
#define pi(x) printf("%d", x);
#define gc getchar_unlocked
#define ll long long
#define ff first
#define ss second
using namespace std;
int readi() {int n=0,sign=false;char c = gc();
	while (c < '0' || c > '9') { if (c == '-') sign=true; c=gc();}
	while (c>='0' && c<='9') {n=n*10+c-'0';c=gc();}
	if (sign) return -n; return n;
}
ll readl() {ll n=0,sign=false;char c = gc();
	while (c < '0' || c > '9') { if (c == '-') sign=true; c=gc();}
	while (c>='0' && c<='9') {n=n*10+c-'0';c=gc();}
	if (sign) return -n; return n;
}
bool isprime[1000005];
void seive () {
	isprime[0]=isprime[1] = true;
	for (int i=2; i*i<1000005;i++) {
		if (!isprime[i]) {
			for (int j=i+i; j < 1000005; j+=i) {
				isprime[j]=true;
			}
		}
	}
}
struct treenode{
	int cnt;
};
struct treenode tree[4*10005];
int a[10005],lazy[4*10005];
struct treenode combine (struct treenode l ,struct treenode r) {
	struct treenode res;
	res.cnt = l.cnt+r.cnt;
	return res;
}
void build (int cn, int ss, int es) {
	if (ss > es) return ;
	if (ss==es) {
		tree[cn].cnt = a[ss];
		return;
	}
	int mid = (ss+es)/2;
	build (2*cn,ss,mid);
	build (2*cn+1,mid+1,es);
	tree[cn]=combine(tree[2*cn],tree[2*cn+1]);
}
void update (int cn, int ss, int es,int i,int j, int val) {
	if (lazy[cn] != -1) {
		if (ss==es) {
			tree[cn].cnt = lazy[cn];
		}
		else {
			tree[cn].cnt = lazy[cn]*(es-ss+1);
			lazy[2*cn] = lazy[cn];
			lazy[2*cn+1] = lazy[cn];
		}
		lazy[cn] = -1;
	}
	if (ss>es || i>es || j<ss) return ;
	if (i<=ss && es<=j) {
		if (ss==es) {
			tree[cn].cnt = !isprime[val];
		}
		else {
			tree[cn].cnt = !isprime[val]*(es-ss+1);
			lazy[2*cn] = !isprime[val];
			lazy[2*cn+1] = !isprime[val];
		}
		// tree[cn].cnt = !isprime[val];
		return ;
	}
	int mid=(ss+es)/2;
	update (2*cn,ss,mid,i,j,val);
	update (2*cn+1,mid+1,es,i,j,val);
	tree[cn] = combine(tree[2*cn],tree[2*cn+1]);
}
int query (int cn, int ss, int es, int i, int j) {
	if (ss>es||i>es||j<ss) return 0;
	if (lazy[cn] != -1) {
		if (ss==es) {
			tree[cn].cnt = lazy[cn];
		}
		else {
			tree[cn].cnt = lazy[cn]*(es-ss+1);
			lazy[2*cn] = lazy[cn];
			lazy[2*cn+1] = lazy[cn];
		}
		lazy[cn] = -1;
	}
	if (i<=ss && es<=j) {
		return tree[cn].cnt;
	}
	int mid=(ss+es)/2;
	int l = query(2*cn,ss,mid,i,j);
	int r = query(2*cn+1,mid+1,es,i,j);
	return (l+r);
}
int main () {
	seive();
	#ifndef ONLINE_JUDGE
    freopen("/home/sherlock/input.txt", "r", stdin);
    #endif
    int t,n,q;
    t=readi();
    fu(tc,1,t+1) {
    	n=readi(), q=readi();
    	rep(i,n) {
    		a[i]=readi();
    		a[i] = !isprime[a[i]];
    	}
    	build(1,0,n-1);
    	memset(lazy,-1,sizeof(lazy));
    	// return 0;
    	printf("Case %d:\n",tc);
    	int type,x,y,v;
    	while (q--) {
    		type=readi();
    		x=readi(), y=readi();
    		x--; y--;
    		if (type == 0) {
    			v=readi();
    			update(1,0,n-1,x,y,v);
    		}
    		else {
    			printf("%d\n",query(1,0,n-1,x,y));
    		}
    	}
    }
    return 0;
}