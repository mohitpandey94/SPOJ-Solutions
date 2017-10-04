#include <bits/stdc++.h>
#define si(x) scanf("%d",&x)
#define pi(x) printf("%d\n",x)
#define pb push_back
using namespace std;
vector<int> graph[100005];
bool vis[100005]; 

void topo (vector<int> graph[], int src, bool vis[], stack<int> &st) {
    vis[src] = true;
    for (int i=0; i < graph[src].size(); i++) {
	if (!vis[graph[src][i]])
	    topo(graph,graph[src][i],vis,st);
    }
    st.push(src);
}

void dfs (vector<int> graph[], int src, bool vis[]) {
    vis[src] = false;
    for (int i=0; i < graph[src].size(); i++) {
	if (vis[graph[src][i]])
	    dfs (graph, graph[src][i], vis);
    }
}
int main() {
    int t,n,e,x,y;
    si(t);
    while (t--) {
	si(n);
	for (int i=0; i < n; i++) graph[i].clear();
	//graph.resize(n);
	si(e);
	for (int i=0; i < e; i++) {
	    si(x), si(y);
	    graph[x].pb(y);
	    graph[y].pb(x);    
	}
	memset (vis,false,sizeof(vis));
	stack<int> st;
	for (int i=0; i <n; i++)
	    if (!vis[i]) 
		topo(graph,i,vis,st);
			
	
	int temp=0, count=0;
	while (!st.empty()) {
	    temp = st.top();
	    st.pop();
	    if (vis[temp]) {
		count++;
		dfs (graph,temp,vis);
	    }
	}
	
	pi(count);
	//graph.clear();
    }
    return 0;
}
