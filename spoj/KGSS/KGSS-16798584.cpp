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
struct  treenode{
	ll fmax, smax;
};
struct treenode tree[4*MAXN+5], nullnode;
ll a[MAXN+5];
struct treenode makenode (ll fmax, ll smax) {
	struct treenode res;
	res.fmax = fmax;
	res.smax = smax;
	return res;
}
struct treenode combine (struct treenode l, struct treenode r) {
	struct treenode res;
	res.fmax = max (l.fmax, r.fmax);
	if (res.fmax == l.fmax) {
		res.smax = max (r.fmax,l.smax);
	}
	else {
		res.smax = max (l.fmax,r.smax);
	}
	return res;
}
void build (int cn, int ss, int es) {
	if (ss>es) return ;
	if (ss==es) {
		tree[cn] = makenode(a[ss],0);
		return;
	}
	int mid = (ss+es)/2;
	build (2*cn,ss,mid);
	build (2*cn+1,mid+1,es);
	tree[cn] = combine (tree[2*cn], tree[2*cn+1]);
}
void update (int cn, int ss, int es, int pt) {
	if (ss > es) return ;
	if (ss==es && ss==pt) {
		tree[cn] = makenode(a[ss],0);
		return ;
	}
	int mid = (ss+es)/2;
	if (pt <= mid) 
		update (2*cn, ss,mid,pt);
	else
		update (2*cn+1, mid+1,es,pt);
	tree[cn] = combine (tree[2*cn], tree[2*cn+1]);
}
struct treenode query (int cn, int ss, int es, int i, int j) {
	if (ss > es || i > es || j < ss) return nullnode;
	if (i<=ss && es <= j) {
		return tree[cn];
	}
	int mid = (ss+es)/2;
	// if (mid<=j)
	struct treenode l = query (2*cn, ss, mid, i, j);
	// else
	struct treenode r = query (2*cn+1, mid+1,es, i,j);
	return combine (l, r);
}
int main () {
	nullnode.fmax = nullnode.smax = -1;
	#ifndef ONLINE_JUDGE
    freopen("/home/sherlock/input.txt", "r", stdin);
    #endif
    int n,q;
    n=readi();
    rep(i,n) 
    	a[i]=readl();
    build (1,0,n-1);
 //    cout<<tree[4].fmax<<" "<<tree[4].smax<<"::\n";
 //    struct treenode res = query (1,0,n-1,1,2);
 //    		printf("%lld %lld: ",res.fmax, res.smax);
	// return 0;    
    q=readi();
    char c; ll x,y;
    while(q--) {
    	cin>>c;
    	x=readl(), y=readl();
    	if (c=='U') {
    		x--;
    		a[x] = y;
    		update (1,0,n-1,x);
 			// cout<<tree[1].fmax<<" "<<tree[1].smax<<"::\n";

    	}
    	else {
    		x--; y--;
    		struct treenode res = query (1,0,n-1,x,y);
    		// printf("%lld %lld: ",res.fmax, res.smax);
    		printf("%lld\n",res.fmax+res.smax);
    	}
    }
    return 0;
}