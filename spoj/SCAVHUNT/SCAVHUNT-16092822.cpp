#include <bits/stdc++.h>
using namespace std;
stack <int> st;
void dfs (vector <int> graph[], bool vis[], int n, int node) {
    vis[node] = true;
    //cout<<node<<"->";
    for (int i = 0; i < graph[node].size(); i++) {
        if (!vis[graph[node][i]]) {
            dfs(graph,vis,n,graph[node][i]);
        }
    }
    st.push(node);

    return ;
}
map <string, bool> ci;
vector<string> ss;
vector<int> graph[500];
int main() {
	int t,s;
	cin>>t;
	string x,y;
	for (int tc=1; tc<=t;tc++) {
		cin>>s;
		int id=0;
		ss.resize(s);
		for (int i=0; i < s-1; i++) {
			cin>>x>>y;
			int id1,id2;
			id1=id2=id;
			if (!ci[x]) id1=id, ci[x] = true, ss[id1] = x,id++;
			else id1 = find(ss.begin(),ss.end(),x)-ss.begin();
			if (!ci[y]) id2=id, ci[y] = true, ss[id2] = y,id++;
			else id2 = find(ss.begin(),ss.end(),y)-ss.begin();
			
			graph[id1].push_back(id2); 
			//graph[id2].push_back(id1); 
		}
		//cout<<id<<":";
		/*
		for (int i=0; i < id; i++) {
			cout<<i<<":";
			for (int j=0;j < graph[id].size(); j++) {
				cout<<graph[i][j]<<" ";
			}
			cout<<"\n";
		}
		*/
		bool vis[2*s+1];
		memset(vis,false, sizeof(vis));
		while (!st.empty()) st.pop();
		for (int i=0; i < id; i++)
			if(!vis[i])
				dfs (graph,vis,s,i);
		//cout<<st.size()<<"::";
		int temp;
		cout<<"Scenario #"<<tc<<":\n";
		while (!st.empty()) {
			temp = st.top(); st.pop();
			cout<<ss[temp]<<"\n";
			graph[temp].clear();
		}
		ss.clear(); ci.clear();
	}
	return 0;
	
	
}
