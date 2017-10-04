#include <iostream>
#include <cstring>
#include <climits>
#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <cstdio>
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define gc getchar_unlocked
#define ll long long
using namespace std;
int readi() {
	int n=0;
	char c=gc();
	while (c<'0') c=gc();
	while (c>='0' && c<='9') {
		n=n*10+c-'0';
		c=gc();
	}
	return n;
}
ll readl() {
	ll n=0;
	char c=gc();
	while (c<'0') c=gc();
	while (c>='0' && c<='9') {
		n=n*10+c-'0';
		c=gc();
	}
	return n;
}
vector <vector <pair<int,ll> > > graph;

struct cmp {
	bool operator () (pair <int,ll> &a, pair <int,ll> &b){
		return a.second > b.second;
	}
};

void dijks (int src, int n, int target) {
	priority_queue <pair<int,ll>, vector <pair<int,ll> > , cmp> pq;
	vector <ll> dist (n+1,LONG_LONG_MAX);
	vector <bool> taken (n+1, false); 
	int u,v,i;
	ll w;

	dist[src] = 0;
	pq.push(make_pair(src,dist[src]));
	while (!pq.empty()) {
		u = pq.top().first;
		pq.pop();
		if (u == target) {
			printf("%lld\n",dist[u]);
			break;
		}
		if (taken[u]) continue;
		taken[u] = 1;
		for (i = 0; i < graph[u].size(); i++) {
			v = graph[u][i].first;
			w = graph[u][i].second;
         if (!taken[v] && dist[u]+w < dist[v]) {
            dist[v] = dist[u] + w;
            pq.push(make_pair(v,dist[v]));
		}
		}

	}
}
map <string,int> mapper;
//graph printer
void print(int n) {
	for (int i=1;i<=n;i++) {
		for (int j=0;j<graph[i].size(); j++)
			cout<<i<<" "<<graph[i][j].first<<" wt="<<graph[i][j].second<<"\n";
	}
}
int main() {
	int t,n,a,b,u;
	ll v;
	string s,s2;
	t=readi();
	while (t--) {
		n=readi();
		graph.resize(n+5);
		for (int i=0;i<n; i++) {
			cin>>s;a=readi();
			mapper[s] = i+1;
			while (a--) {
				u=readi();v=readl();
				graph[i+1].push_back(make_pair(u,v));
			}
		}
		//print(n);
		b=readi();
		while (b--) {
			cin>>s>>s2;
			dijks(mapper[s],n,mapper[s2]);
		}
		graph.clear();
		mapper.clear();
	}
	return 0;
} 