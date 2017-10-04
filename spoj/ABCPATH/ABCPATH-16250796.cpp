#include <bits/stdc++.h>
#define fu(i, a, n) for (int i = a; i < n; i++)
#define fd(i, n, a) for (int i = n; i >= a; i--)
#define rep(i,n) fu(i,0,n)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pii>
#define sl(x) scanf("%lld", &x); //sl(x) is for long long int.
#define si(x) scanf("%d", &x);
#define pl(x) printf("%lld", x);  //pl(x) is for long long int.
#define pln(x) printf("%lld\n", x);  //..n(x) is for printing with New Line.
#define ps(x) printf("%lld ", x);  //..s(x) is for printing with Space.
#define pi(x) printf("%d", x);
#define pin(x) printf("%d\n", x);
#define pis(x) printf("%d ", x);
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
const int dx[] = {0,1,-1};
const int dy[] = {0,1,-1};

int n,m,a[52][52],maxl[52][52];
vpii start;
bool check (int x, int y) {
	if (x >= n || y >= m || x < 0 || y < 0) return false;
	return true; 
}
int dfs (int x, int y) {
	//cout<<x<<" "<<y<<"\n";
	if (maxl[x][y] != -1) return maxl[x][y];
	int ans =0;
	for (int i=0; i < 3; i++) {
		for (int j=0; j < 3; j++) {
			//if (check(x+dx[i],y+dy[j])) {
			if (!check(x+dx[i], y+dy[j])) continue;
			int newx = x+dx[i], newy = dy[j]+y;
			if (a[newx][newy] == a[x][y]+1) {
				//cout<<x<<" "<<y<<"->"<<newx<<" "<<newy<<"\n";
 				ans = max(ans,dfs (x+dx[i],y+dy[j])+1);
 			}
		}
			//} 
	}  
	return maxl[x][y]=ans;
}
int main() {
	#ifndef ONLINE_JUDGE
    freopen("/home/placements/input.txt", "r", stdin);
    #endif
    cin>>n>>m;
    char c;
    int tc=1;
    while (n && m) {
    	for (int i=0; i < n; i++) {
    		for (int j=0; j < m; j++) {
    			cin>>c;
    			a[i][j] = c-'A';
    			if (c=='A') {
    				start.pb(mp(i,j));
    			}
    		}
    	}
    	memset(maxl,-1,sizeof(maxl));
    	int ans=0;
    	rep(i,start.size()) {
    		int x=start[i].ff;
    		int y = start[i].ss;//memset(maxl,-1,sizeof(maxl));
    		ans = max (ans,dfs (x,y)+1);
    		//cout<<ans+1<<"\n";
    	}
    	cout<<"Case "<<tc<<": "<<ans<<"\n";
    	cin>>n>>m;
    	start.clear();
    	tc++;

    } 
    return 0;
}