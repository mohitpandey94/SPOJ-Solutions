#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#ifndef ONLINE_JUDGE
#define gc getchar
#else
#define gc getchar_unlocked
#endif
#define ll long long
#define nl() printf ("\n")
#define pi(x) printf ("%d",x)
#define pl(x) printf ("%lld",x)
#define pc(x) printf ("%c",x)
#define ps(x) printf ("%s",x)
#define pb(x) push_back(x)
#define repu(i,n,step) for (;i<n;i+=step)
#define repd(i,n) for (;i>=0;i--)
using namespace std;
int readi () {int n=0,sign=0;char c=gc();
while (c<48) {if (c==45) sign=1;c=gc();}
while (c>47) {n=n*10+c-'0';c=gc();}
if (sign) return (-n);	return n;
}
ll readl () {
	ll n=0;
	char c=gc();
	while (c<48) c=gc();
	while (c>47) {
		n=n*10+c-'0';
		c=gc();
	}
	return n;
}
int maxi (int a, int b, int c) {
    return (a > b? (a>c ? a:c): (b>c?b:c));
}
struct node {
    int fin,pre,suf,tot;
};
node tree [50000*4+5];
int n;
node init (int val) {
    node newnode;
    newnode.fin = newnode.tot=newnode.pre=newnode.suf =val;

    return newnode;
}
node merger (node l, node r) {
    node newnode;

    newnode.tot = l.tot+r.tot;
    newnode.pre = max(l.pre,l.tot+r.pre);
    newnode.suf = max(r.suf,r.tot+l.suf);
    newnode.fin = maxi(l.fin,r.fin,l.suf+r.pre);

    return newnode;
}
void construct (int a[], int se, int es, int ci) {
    if (se == es) tree[ci] = init(a[se]);
    else {
        construct(a,se,(se+es)/2,2*ci);
        construct(a,(se+es)/2+1,es,2*ci+1);
        tree[ci] = merger(tree[ci*2],tree[ci*2+1]);
    }
}
node query (int se, int es, int ci, int qs, int qe) {
    if (se >= qs && es <= qe) return tree[ci];
    if (qe <= (se+es)/2) return query(se,(se+es)/2,2*ci,qs,qe);
    if (qs > (se+es)/2) return query ((se+es)/2+1,es,2*ci+1,qs,qe);

    node l = query(se,(se+es)/2,2*ci,qs,qe);
    node r = query((se+es)/2+1,es,2*ci+1,qs,qe);

    return merger(l,r);
}
void pointupdate (int a[], int se, int es, int ci, int ui, int val) {
    if (se == es) tree[ci] = init(val);
    else {
        int mid = (se+es)/2;

        if (ui <= mid)
            pointupdate(a,se,mid,2*ci,ui,val);
        else
            pointupdate(a,mid+1,es,2*ci+1,ui,val);

        tree[ci] = merger(tree[2*ci],tree[2*ci+1]);
    }
}
int main() {
    //ios::sync_with_stdio(0);
    n=readi();
    int a[n+1];
    for (int i=1;i<=n;i++) a[i]=readi();
    construct(a,1,n,1);

    int m,x,y,qtype;
    m=readi();
    while(m--) {
        qtype = readi();
        x=readi();y=readi();
        if (qtype)
            cout<<query(1,n,1,x,y).fin<<"\n";
        else {
            pointupdate(a,1,n,1,x,y);
        }
    }
return 0;
}
