#include <bits/stdc++.h>
using namespace std;
vector <int> g[110];
bool vis[110];
int ind[110];

priority_queue<int, vector<int> > pq;

void f () {
	int top;
	while (!pq.empty()) {
		top = pq.top();
		pq.pop();
		top = -top;
		cout<<top<<" ";
		vis[top] = true;
		for (int i=0; i<g[top].size(); i++) {
			ind[g[top][i]]--;
			if (!ind[g[top][i]]) pq.push(-g[top][i]);
		}
	}
}
int main() {
	int n,m;
	cin>>n>>m;
	int x,y,k;
	for (int i=0; i < m; i++) {
		cin>>x>>k;
		ind[x] += k;
		while (k--) {
			cin>>y;
			g[y].push_back(x);
		}
	}
	for (int i=1 ; i <= n; i++) {
		if (!ind[i]) pq.push(-i);
	}
	f();
	return 0;
}