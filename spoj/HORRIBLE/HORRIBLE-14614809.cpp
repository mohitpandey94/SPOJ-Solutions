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
#define Sz 100005
using namespace std;
int readi () {int n=0,sign=0;char c=gc();
while (c<48) {if (c==45) sign=1;c=gc();}
while (c>47) {n=n*10+c-'0';c=gc();}
if (sign) return (-n);	return n;
}
ll readl () {ll n=0;int sign=0;char c=gc();
while (c<48) {if (c==45) sign=1;c=gc();}
while (c>47) {n=n*10+c-'0';c=gc();}
if (sign) return (-n);	return n;
}
//
ll tree[4*Sz], lazy[4*Sz];

void update (int ss, int es, int ci, int us, int ue, ll val) {
    //cout<<ss<<" "<<es<<" "<<ci<<",\n";
    if (lazy[ci] != 0) {
        if (ss == es)
            tree[ci] += lazy[ci];
        else {
            tree[ci] += lazy[ci]*(es-ss+1);
            lazy[2*ci] += lazy[ci];
            lazy[2*ci+1] += lazy[ci];
        }
        lazy[ci] = 0;
    }

    if (ss > ue || es < us || ss > es) {
        return ;
    }

    if (ss >= us && es <= ue) {
        if (ss == es)
            tree[ci] += val;
        else {
            tree[ci] += val*(es-ss+1);
            lazy[2*ci] += val;
            lazy[2*ci+1] += val;
        }
        return ;
    }

    update(ss,(ss+es)/2,2*ci,us,ue,val);
    update ((ss+es)/2+1,es,2*ci+1,us,ue,val);

    tree[ci] = tree[2*ci]+tree[2*ci+1];
}
ll query (int ss, int es, int ci, int qs, int qe) {
    if (qs > es || qe < ss || ss > es) return 0;
    if (lazy[ci] != 0) {
        if (ss == es)
            tree[ci] += lazy[ci];
        else {
            tree[ci] += lazy[ci]*(es-ss+1);
            lazy[2*ci] += lazy[ci];
            lazy[2*ci+1] += lazy[ci];
        }
        lazy[ci] = 0;
    }

    if (ss >= qs && es <= qe) {
        return tree[ci];
    }
    ll p1,p2;
    p1 = query(ss,(ss+es)/2,2*ci,qs,qe);
    p2 = query((ss+es)/2+1,es,2*ci+1,qs,qe);

    return (p1+p2);
}
void printtree(int tree[], int n) {
    repu(i,1,n+1,1) {
        cout<<i<<":p="<<tree[i]<<",l="<<tree[2*i]<<",r="<<tree[2*i+1]<<"\n";
    }
}
int main() {
    int t,n,m,k,l,r,type;
    ll c;
    t=readi();
    while (t--) {
        n=readi(); //k = readi();
        m = readi();

        repu(i,0,4*Sz,1) tree[i] = 0,lazy[i]=0;

        while (m--) {
            type = readi();
            if (type == 0) {
                l = readi();
                r=readi();
                c=readl();
                update(0,n-1,1,l-1,r-1,c);
            }
            else {
                l=readi();r=readi();
                cout<<query(0,n-1,1,l-1,r-1)<<"\n";
            }
        }
        /*
        nl();nl();
        printtree(tree,n);
        nl();
        printtree(lazy,n);
        nl();nl();
        repu(i,0,n,1) {
            cout<<i+1<<":"<<query(0,n-1,1,i,i)<<"\n";
        }
        */
    }
return 0;
}
/*
1
8 1
0 2 4 26

1
8 2
0 2 4 26
0 4 8 80

1
8 3
0 2 4 26
0 4 8 80
0 4 5 20

1
8 4
0 2 4 26
0 4 8 80
0 4 5 20
0 5 7 14
*/
