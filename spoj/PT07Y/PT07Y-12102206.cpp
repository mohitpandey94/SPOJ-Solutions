#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool bfs (vector<int> graph[],int s, int n) {
    bool v[n+1];
    for (int i=0;i<=n;i++) v[i]=false;
    int count=0,t;
    queue <int>q;
    q.push(s);
    while (!q.empty()) {
        t=q.front();
        v[t]=true;
        q.pop();
        for (int i=0;i<graph[t].size();i++) {
            int temp = graph[t][i];
            if (v[temp]) return false;
            else q.push(temp);
        }
        count++;
    }
    if (count==n) return true;
    else return false;
}
main() {
    int n,m,u,v;
    cin>>n>>m;
    vector <int>gr[n+1];
    for (int i=0;i<m;i++) {
        cin>>u>>v;
        gr[u].push_back(v);
    }
    if (bfs(gr,1,n)) cout<<"YES\n";
    else cout<<"NO\n";
}