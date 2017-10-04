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
class cmp {
public:
    bool operator () (pair<int,int> &a, pair <int,int> &b) {
        if (a.second > b.second) return true;
        else return false;
    }
};
int dijkstra (vector <pair<int,int> > graph[], int src, int n, int target) {
    priority_queue <pair <int,int>, vector <pair<int,int> >, cmp> pq;
    bool vis[n+1];
    int dist[n+1];

    fill(vis,vis+n+1,false);
    fill (dist,dist+n+1,INT_MAX);

    dist[src] = 0;
    vis[src] = true;
    pq.push(mp(src,dist[src]));
    int temp = src,node,nodewt;

    while (!pq.empty()) {
        temp = pq.top().first;

        if (temp == target) break;
        vis[temp] = true;
        pq.pop();
        repu(i,0,graph[temp].size(),1) {
            node = graph[temp][i].first;
            nodewt = graph[temp][i].second;

            if (!vis[node] && nodewt + dist[temp] < dist[node]) {
                dist[node] = dist[temp] + nodewt;
                pq.push(mp(node,dist[node]));
            }
        }
    }

    return dist[target];
}
int main() {
    int t,n,m,x,y,w,cost,trg,src;
    t = readi();
    repu(tc,1,t+1,1) {
        n = readi(); m = readi();
        vector <pair <int,int> > graph[n+1];
        while (m--) {
            x= readi(); y = readi(); w = readi();
            graph[x].pb(mp(y,w));
            //graph[y].pb(mp(x,w));
        }
        cin>>src>>trg;
        cost = dijkstra(graph, src, n, trg);

        if (cost != INT_MAX) {
            cout<<cost<<"\n";
        }
        else {
            cout<<"NO\n";
        }
    }
return 0;
}
