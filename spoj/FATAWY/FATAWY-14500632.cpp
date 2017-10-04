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

int lcs[510][510];
char s[510][25];
int tot,lengths[510];
int dp[510][510];
vector <int> graph[510];
int lcslen (char* a, char* b, int n, int m) {
	//init
	repu(i,0,n+1,1) dp[i][0] = 0;
	repu(j,0,m+1,1) dp[0][j] = 0;

	repu(i,1,n+1,1) {
		repu(j,1,m+1,1) {
			if (a[i-1] == b[j-1]) {
				dp[i][j] = dp[i-1][j-1]+1;
			}
			else {
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	return dp[n][m];
	//lcsprint(a,b,taken);
}
void bfs (vector <int> graph[], int src, bool vis[]) {
    queue <int> q;
    int temp,node;
    q.push(src);
    vis[src] = true;
    while (!q.empty()) {
        temp = q.front();
        //cout<<s[temp]<<" ";
        q.pop();
        //vis[temp] = true;
        repu(i,0,graph[temp].size(),1) {
            node = graph[temp][i];
            if (!vis[node]) {
                q.push(node);
                vis[node] = true;
            }
        }
    }
}
int main() {
    //ios::sync_with_stdio(false);
    int t,n,th,val;
    double temp1,temp2,Th;
    t = readi();
    repu(tc,1,t+1,1) {
        n = readi(); th = readi();
        //cin>>th;
        //Th = (double) (th*1.0/100.0);
        //cout<<Th<<" "<<th<<"\n";
        repu(i,0,n,1) {
            //cin>>s[i];
            scanf("%s",s[i]);
            lengths[i] = strlen(s[i]);
            graph[i].clear();
        }
        repu(i,0,n,1) {
            repu(j,i+1,n,1) {
                lcs[j][i] = lcs[i][j] = lcslen(s[i],s[j],lengths[i],lengths[j]);
            }
        }
        repu(i,0,n,1) {
            repu(j,i+1,n,1) {
                val = lcs[i][j];
                //temp1= (double) (val*1.0) / (double) (lengths[i]*1.0);
                //temp2= (double) (val*1.0) / (double) (lengths[j]*1.0);
                //cout<<s[i]<< " "<<s[j]<<" "<<((double) (val*100.0) / (double) (lengths[i]*1.0))<<" "<<((double) (val*100.0) / (double) (lengths[j]*1.0))<<"\n";
                if (((double) (val*100.0) / (double) (lengths[i]*1.0)) >= (double)(th*1.0) && ((double) (val*100.0) / (double) (lengths[j]*1.0)) >= (double)(th*1.0)) {
                    graph[i].pb(j);
                    graph[j].pb(i);
                }
            }
        }
        bool vis[n+1];
        fill(vis,vis+n+1,false);
        int ans = 0;
        repu(i,0,n,1) {
            if (!vis[i]) {
                bfs (graph,i,vis);
                ans++;
            }
        }
		printf("Case #%d:\n%d\n",tc,ans);
        //cout<<"Case #"<<tc<<":\n"<<ans<<"\n";
    }
return 0;
}
