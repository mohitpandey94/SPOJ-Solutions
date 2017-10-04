#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
vector <int>g[10005];
int dist[10005];
int bfs(int node, int n) {
    queue<int> kju;
    
    memset(dist, -1, sizeof dist);
    dist[node] = 0;
    kju.push(node);
    
    int limit;
    while (!kju.empty()) {
        int cur_node = kju.front(); kju.pop();
        //cout<<cur_node<<" : ";
        limit = g[cur_node].size();
        for (int i = 0; i < limit; ++i) {
            if (dist[g[cur_node][i]] == -1) {
                kju.push(g[cur_node][i]);
                dist[g[cur_node][i]] = dist[cur_node]+1;
                //cout<<  dist[g[cur_node][i]] <<" ";
            }
        }
    }
    
    int maks = dist[node];
    //cout<<node<<" "<<dist[node];
    int maks_node = node;
   // cout<<n<<" ;";
    for (int i = 0; i < n; ++i) {
        //cout<<dist[i]<<" ";
        if (dist[i] > maks) { maks = dist[i]; maks_node = i; }
    }
    //cout<<node<<" "<<dist[node];
    
    return maks_node;
}


int main()
{
    int x,y,n;
    cin>>n;
    for (int i=0;i<n;i++) {
        cin>>x>>y;
        x;y;
        g[x-1].push_back(y-1);
        g[y-1].push_back(x-1);
    }
   int node = bfs(0,n);
   node=bfs(node,n);
   cout<<dist[node]<<endl;
   return 0;
}
