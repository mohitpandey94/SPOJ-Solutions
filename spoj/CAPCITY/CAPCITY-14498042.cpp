#include <iostream>
#include <stack>
#include <stack>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <cstdio>
#define si(x) scanf("%d",&x)
#define pi(x) printf("%d ",x)
#define nl() printf("\n")
#define pb push_back
using namespace std;

vector <int> graph[100001];
vector <int> graphT[100001];
bool vis[100001];
int indeg[100001];
int contains[100001];
vector <int> sccs[100001];
stack <int> s;

void dfs (vector <int> graph[], bool vis[], int src, stack <int> &s) {
    vis[src] = true;

    for (int i = 0; i < graph[src].size(); i++) {
        if (!vis[graph[src][i]]) {
            dfs (graph,vis,graph[src][i],s);
        }
    }
    s.push(src);
}

void dfs (vector <int> graph[], bool vis[], int src,int contains[], int inscc) {
    contains[src] = inscc;
    vis[src] = false;

    for (int i = 0; i < graph[src].size(); i++) {
        if (vis[graph[src][i]]) {
            dfs(graph,vis,graph[src][i],contains,inscc);
        }
    }
}
void reset (int n) {
    for (int i =1;i<=n;i++) {
        graph[i].clear();graphT[i].clear();
        vis[i]=false;
        indeg[i]=0;
        contains[i]=-1;
    }
    while (!s.empty()) s.pop();
}
void input (vector <int> graph[], vector <int> graphT[], int en) {
    int x,y;
    for (int i =0 ;i<en;i++) {
        si(x);si(y);
        graph[x].pb(y);
        graphT[y].pb(x);
    }
}
int main() {
    int t=1,vn,en,x,y,temp,scccount=0;
    si(vn);
    while (t--) {
        si(en);

        reset(vn);
        input(graph,graphT,en);

        for (int i = 1; i <= vn; i++) {
            if (!vis[i]) {
                dfs (graph,vis,i,s);
            }
        }
        scccount=0;
        while (!s.empty()) {
            temp = s.top();
            s.pop();
            if (vis[temp]) {
                dfs(graphT,vis,temp,contains,scccount);
                scccount++;
            }
        }

        for (int i = 1; i <= vn; i++) {
            for (int j = 0; j < graphT[i].size(); j++) {
                if (contains[graphT[i][j]] != contains[i]) {
                    indeg[contains[graphT[i][j]]]++;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < scccount; i++) {
            if (!indeg[i]) ans++;
        }
        if (ans > 1) pi(0);
        else {
            ans = 0;
            for (int i=1;i<=vn;i++) {
                if (!indeg[contains[i]]) {
                    ans++;
                }
            }
            pi(ans);
            nl();
            for (int i=1;i<=vn;i++) {
                if (!indeg[contains[i]]) {
                    pi(i);
                }
            }
        }
        nl();
    }
}
