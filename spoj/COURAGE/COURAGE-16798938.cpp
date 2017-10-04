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
#define MAXN 100000
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
int n,q;
struct  treenode {
	ll sum,min;
};
struct treenode tree[4*MAXN+5],nullnode;
ll a[MAXN+5];
// ll lazy[4*MAXN+5];
struct treenode makenode(ll x, ll y) {
	struct treenode res;
	res.sum = x;
	res.min = y;
	return res;
} 
struct treenode combine (struct treenode l, struct treenode r) {
	struct treenode res;
	res.sum = l.sum+r.sum;
	res.min = min (l.min, r.min);
	return res;
}
void build (int cn, int ss, int es) {
	if (ss>es) return ;
	if (ss==es) {
		tree[cn] = makenode(a[ss],a[ss]);
		return ;
	} 
	int mid = (ss+es)/2;
	build (2*cn, ss, mid);
	build (2*cn+1,mid+1,es);
	tree[cn] = combine(tree[2*cn], tree[2*cn+1]);
}
void update (int cn, int ss, int es, int pt, int val) {
	if (ss > es || pt < ss || pt > es) return ;
	if (ss==es) {
		if (ss==pt) {
			tree[cn].sum += val;
			tree[cn].min += val;
			return ;
		}
		else
			return ;
	}
	int mid = (ss+es)/2;
	if (pt <= mid)
		update (2*cn, ss, mid,pt,val);
	else
		update (2*cn+1,mid+1,es,pt,val);
	tree[cn] = combine (tree[2*cn], tree[2*cn+1]);
}
struct treenode query (int cn, int ss, int es, int i, int j) {
	if (ss > es || i > es || j < ss) return nullnode;
	if (i<=ss && es <= j) {
		return tree[cn];
	}
	int mid = (ss+es)/2;
	struct treenode l = query (2*cn,ss,mid,i,j);
	struct treenode r = query (2*cn+1,mid+1,es,i,j);
	return combine(l,r);
}
int main () {
	nullnode.sum = 0;
	nullnode.min = LONG_LONG_MAX;
	#ifndef ONLINE_JUDGE
    freopen("/home/sherlock/input.txt", "r", stdin);
    #endif
    n=readi();
    rep(i,n)
    	a[i] =readl();
    build(1,0,n-1);
    q=readi();
    string s;
    ll x, y;
    struct treenode res;
    while (q--) {
    	cin>>s;
    	x=readl(), y=readl();
    	if (s[0]=='C') {
    		// x--; y--;
    		res = query (1,0,n-1,x,y);
    		printf("%lld\n", res.sum-res.min);
    	}
    	else if (s[0]=='E') {
    		update (1,0,n-1,y,-x);
    	}
    	else
    		update(1,0,n-1,y,x);
    }
    return 0;
}