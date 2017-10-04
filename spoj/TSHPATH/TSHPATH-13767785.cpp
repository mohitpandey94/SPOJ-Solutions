#include <iostream>
#include <cstring>
#include <climits>
#include <vector>
#include <map>
#include <cstdio>
#define si(x) scanf("%d",&x);
#define gc getchar_unlocked
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
int graph[10005][10005];
int pick(int dist[], int taken[], int n) {
   int min = INT_MAX, min_index;
   for (int v = 1; v < n+1; v++)
     if (taken[v] == 0 && dist[v] <= min)
         min = dist[v], min_index = v;
 
   return min_index;
}
void dijks (int src, int n, int target) {
	int dist[n+1];
	int taken[n+1],u;
	for (int i=0;i<n+1;i++) {
		dist[i] = INT_MAX;
		taken[i] = 0;
	}
	dist[src] = 0;
	
	for (int i=0;i<n;i++) {
		u = pick(dist,taken,n);
		taken[u] = 1;
		if (u == target) {
			cout<<dist[u]<<"\n";break;}
		for (int v = 1; v < n+1; v++)
         if (!taken[v] && graph[u][v] && dist[u] != INT_MAX 
                                       && dist[u]+graph[u][v] < dist[v]) {
            dist[v] = dist[u] + graph[u][v];
		}
	}
	//cout<<dist[target]<<"\n";
}
map <string,int> mapper;
int main() {
	int t,n,a,b,u,v;
	//memset(graph,0, sizeof(graph));
	string s,s2;
	t=readi();
	while (t--) {
		n=readi();
		//graph.resize(n+5);
		for (int i=0;i<n; i++) {
			//graph[i].resize(n+5);
			cin>>s;a=readi();
			mapper[s] = i+1;
			while (a--) {
				u=readi();v=readi();
				graph[i+1][u]=v;
			}
		}
		si(b);
		while (b--) {
			cin>>s>>s2;
			dijks(mapper[s],n,mapper[s2]);
		}
		//cout<<"nab"<<a<<" "<<n<<" "<<b<<"\n";
		memset(graph,0, sizeof(graph));
		//graph.clear();
		mapper.clear();
	}
	return 0;
} 