#include <bits/stdc++.h>
using namespace std;
void bfs (int x[], int n) {
	queue <pair<int,int > > q;
	bool vis[n+1];
	fill (vis, vis+n+1, false);
	int temp, moves;
	q.push(make_pair(0,0));
	while (!q.empty()) {
		temp = q.front().first;
		moves = q.front().second;
		q.pop();
		if (vis[temp]) continue;
		//cout<<temp<<" "<<moves<<"\n";
		if (temp == n) {
			cout<<moves<<"\n";
			return ;
		}
		if (temp < 0) continue;
		if (temp > n) continue;
		vis[temp] = true;
		q.push(make_pair(temp+1, moves+1));
		q.push(make_pair(temp+x[temp], moves+1));
	}
	return ;
}
int main() {
	int t,n;
	cin>>t;
	while (t--) {
		cin>>n;
		int x[n+1];
		for (int i=0;i < n; i++) cin>>x[i];
		bfs(x, n);
	}
	return 0;
}