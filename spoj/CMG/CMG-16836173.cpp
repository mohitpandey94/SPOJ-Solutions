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
int main () {
	#ifndef ONLINE_JUDGE
    freopen("/home/sherlock/input.txt", "r", stdin);
    #endif
    int t,x,q;
    t=readi();
    fu(tc,1,t+1) {
    	q=readi();
    	char type;
    	int maxx=-1;
    	stack<pair<int,int> > st;
    	printf("Case %d:\n",tc);
    	while (q--) {
    		scanf(" %c",&type);
    		// cin>>type;
    		if (type=='A') {
    			x=readi();
    			maxx = max(x,maxx);
    			st.push(mp(x,maxx));
    		}
    		else if (type=='R') {
    			if (st.size()) {
    				st.pop();
    			}
    			if (!st.size()) {
    				maxx = -1;
    			}
    			else {
    				maxx = st.top().second;
    			}
    		}
    		else {
    			if (st.size())
    				printf("%d\n",st.top().second);
    			else
    				printf("Empty\n");
    		}
    	}
    }
    return 0;
}