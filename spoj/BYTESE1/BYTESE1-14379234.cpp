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
int place[105][105];
const int dx[] = {-1,1};
const int dy[] = {-1,1};
struct pos {
    int x;
    int y;
    int cost;
};
typedef struct pos p;

class cmp {
public:
    bool operator () (struct pos &a, struct pos &b) {
        if (a.cost > b.cost) return true;
        else return false;
    }
};
int dijkstra (int r, int c, int tgx, int tgy) {
    priority_queue <pos, vector <pos>, cmp> pq;
    int cost[r+1][c+1];
    bool vis[r+1][c+1];
    repu(i,0,r+1,1) {
        repu(j,0,c+1,1) {
            cost[i][j] = 999;
            vis[i][j] = false;
        }
    }
    cost[1][1] = place[1][1];
    vis[1][1] = true;
    p temp,node;
    temp.x = 1; temp.y = 1; temp.cost = 0;

    pq.push(temp);
    while (!pq.empty()) {
        temp = pq.top();
        vis[temp.x][temp.y] = true;
        //cout<<"\n"<<temp.x<<" "<<temp.y<<" " <<temp.cost<<"\n";
        if (temp.x == tgx && temp.y == tgy) break;
        //cout<<pq.size()<< "sz ";
        pq.pop();
        //cout<<pq.size()<<"sz ";

        repu(ind,0,2,1) {
        //    cout<<"Pushed:";
            if ((temp.x+dx[ind] >= 1 && temp.x+dx[ind] <= r) && !vis[temp.x+dx[ind]][temp.y]) {
                if (cost[temp.x][temp.y] + place[temp.x+dx[ind]][temp.y] < cost[temp.x+dx[ind]][temp.y]) {
                    cost[temp.x+dx[ind]][temp.y] = cost[temp.x][temp.y] + place[temp.x+dx[ind]][temp.y];
                    node.x = temp.x+dx[ind]; node.y = temp.y; node.cost = cost[temp.x+dx[ind]][temp.y];
                    pq.push(node);
                //    cout<<"("<<node.x<<","<<node.y<<"),"<<node.cost<<",";
                }
            }
            if ((temp.y+dy[ind] >= 1 && temp.y+dy[ind] <= c) && !vis[temp.x][dy[ind] + temp.y]) {
                if (cost[temp.x][temp.y] + place[temp.x][dy[ind]+temp.y] < cost[temp.x][dy[ind]+temp.y]) {
                    cost[temp.x][dy[ind]+temp.y] = cost[temp.x][temp.y] + place[temp.x][dx[ind]+temp.y];
                    node.x = temp.x; node.y = temp.y + dy[ind]; node.cost = cost[temp.x][dy[ind]+temp.y];
                    pq.push(node);
                //    cout<<"("<<node.x<<","<<node.y<<"),"<<node.cost<<",";
                }
            }
        }
    //    cout<<pq.size()<<"sz \n";
    }

    return cost[tgx][tgy];
}
int main() {
    int t,r,c,tgx,tgy,time,ttaken;
    t = readi();
    while (t--) {
        r = readi();c = readi();
        repu(i,1,r+1,1) {
            repu(j,1,c+1,1) {
                place[i][j] = readi();
            }
        }
        tgx = readi(); tgy = readi(); time = readi();
        nl();
        ttaken = dijkstra (r,c,tgx,tgy);
        if (time-ttaken >= 0) {
            ps("YES\n");
            pi(time-ttaken); nl();
        }
        else {
            ps("NO\n"); nl();
        }

    }
return 0;
}
