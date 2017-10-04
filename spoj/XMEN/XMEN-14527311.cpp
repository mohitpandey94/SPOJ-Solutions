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
int dp[2][100005];
void lcslen (string a, string b, int n, int m) {
	//init
	//repu(i,0,n+1,1) dp[i][0] = 0;
	repu(j,0,m+1,1) dp[0][j] = dp[1][j] = 0;
    int turn = 1;
	repu(i,1,n+1,1) {
		repu(j,1,m+1,1) {
			if (a[i-1] == b[j-1]) {
				dp[turn&1][j] = dp[(turn&1)^1][j-1]+1;
			}
			else {
				dp[turn&1][j] = max(dp[(turn&1)^1][j],dp[turn&1][j-1]);
			}
		}
		turn++;
		//if (i < n)
            //repu(k,0,m+1,1) dp[0][k] = dp[1][k];
	}
	printf("%d\n",dp[(turn&1)^1][m]);
}
/*
int lcslen (string a, string b) {
	vector <vector <string> > taken;
	int n  = a.length();
	int	m = b.length();
	int dp[n+1][m+1];
	taken.resize(n+1);
	repu(i,0,n+1,1) taken[i].resize(m+1);

	//init
	repu(i,0,n+1,1) dp[i][0] = 0;
	repu(j,0,m+1,1) dp[0][j] = 0;

	repu(i,1,n+1,1) {
		repu(j,1,m+1,1) {
			if (a[i-1] == b[j-1]) {
				dp[i][j] = dp[i-1][j-1]+1;
				taken[i][j] = "iless+jless";
			}
			else {
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
				if (dp[i-1][j] > dp[i][j-1]) taken[i][j] = "ilessonly";
				else taken[i][j] = "jlessonly";
			}
		}
	}
	cout<<dp[n][m]<<"\n";
	//lcsprint(a,b,taken);
}
*/
int a[100005];
struct val {
    int x;
    int id;
};
struct val  b[100005];
int finb[100005];
bool cmp (struct val x, struct val y) {
    return (x.x < y.x ? 1 : (x.x==y.x?(x.id<y.id?1:0):0));
}
int bs (struct val a[], int val, int n) {
    int mid,l=0,h=n-1;
    //cout<<val<<":";
    while (l<=h) {
        mid = (l+h)/2;
        //cout<<a[mid].x<<",";
        if (a[mid].x > val) h=mid-1;
        else if (a[mid].x < val) l = mid+1;
        else return a[mid].id;
    }
}
int main() {
    int t,n,x;
    scanf("%d",&t);

    while (t--) {
        //string a,b;
        scanf("%d",&n);
        for (int i=0;i<n;i++) {
            scanf("%d",&a[i]);
           // a += (x+'0');
        }
        for (int i=0;i<n;i++) {
            scanf("%d",&b[i].x);
            b[i].id=i;
           // b[i].found = -1;
            //b += (x+'0');
        }
        sort(b,b+n,cmp);
        //repu(i,0,n,1) cout<<b[i].x<<" ";
        //lcslen(a,b,n,n);
        repu(i,0,n,1) {
            finb[i] = bs(b,a[i],n);
            //cout<<"\n";
        }
        vector <int> ans(n+1,INT_MAX);
        repu(i,0,n,1) *lower_bound(ans.begin(),ans.end(),finb[i]) = finb[i];
        repu(i,0,n+1,1) {
            //cout<<ans[i]<<" ";
            if (ans[i] == INT_MAX) {
                cout<<i<<"\n";
                break;
            }
        }
        //cout<<"\n";
    }
	//string a,b;
	//cin>>a>>b;
	return 0;
}

