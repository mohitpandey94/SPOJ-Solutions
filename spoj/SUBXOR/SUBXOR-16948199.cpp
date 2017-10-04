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
struct node {
	node* childs[2];
	int c1,c0;
} *root;
struct node* newnode() {
	struct node* temp = new node;
	temp->c1=temp->c0=0;
	temp->childs[0] = temp->childs[1] = NULL;
	return temp;
}
void insert (int n) {
	struct node* temp = root;
	int bit = 0;
	fd(i,20,0) {
		bit = ((n>>i)&1);
		// cout<<bit<<" ";
		if (!(temp->childs[bit])) {
			temp->childs[bit] = newnode();
		}
		temp->c1 += (bit==1?1:0);
		temp->c0 += (bit==0?1:0);
		temp = temp->childs[bit];
	}
	return ;
}
ll search (int n, int k) {
	struct node* temp = root;
	int bit1,bit2;
	ll ans = 0;
	fd(i,20,0) {
		bit1 = ((n>>i)&1);
		bit2 = ((k>>i)&1);
		if (bit2) {
			if (bit1) {
				ans += temp->c1;
				if (!(temp->childs[0])) {
					return ans;
				}
				temp = temp->childs[0];
			}
			else {
				ans += temp->c0;
				if (!(temp->childs[1])) {
					return ans;
				}
				temp = temp->childs[1];
			}
		}
		else {
			if (bit1) {
				if (!(temp->childs[1])) return ans;
				temp = temp->childs[1];
 			}
 			else {
 				if (!(temp->childs[0])) return ans;
 				temp = temp->childs[0];
 			}
		} 
	}
	return ans;
}
int main () {
	#ifndef ONLINE_JUDGE
    freopen("/home/sherlock/input.txt", "r", stdin);
    #endif
    int t,n,k;
    t=readi();
    while (t--) {
    	root = newnode();
    	n=readi(), k =readi();
    	insert(0);
    	// int a[n+1];
    	ll ans=0;
    	int prev=0,cur=0,x;
    	rep(i,n) {
    		x = readi();
    		cur = prev^x;
    		ans += search(cur,k);
    		// cout<<a[i]<<" ";
    		insert(cur);
    		prev = cur;
    	}
    	printf("%lld\n",ans);
    }
    return 0;
}