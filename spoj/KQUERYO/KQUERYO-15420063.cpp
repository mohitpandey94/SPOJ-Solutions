#include <bits/stdc++.h>
#define si(x) scanf("%d",&x)
using namespace std;

#define gc getchar_unlocked

void readi(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}




int n;
int a[30005];
vector <int> tree[4*30000];
void build (int curnode, int l, int r) {
    if (l > r) return ;
     //out<<l<<" "<<r<<" "<<curnode<<"\n";
    if (l == r) {
        tree[curnode].push_back(a[l]);
        return ;
    }
    int mid = (l+r)/2;
    build (2*curnode, l, mid);
    build (2*curnode+1, mid+1, r);
    merge(tree[2*curnode].begin(), tree[2*curnode].end(), tree[2*curnode+1].begin(), tree[2*curnode+1].end(), back_inserter(tree[curnode]));
	//cout<<tree[curnode].size()<<" "<<curnode<<"\n";
    return ;
}
int query (int ql, int qr, int val, int curnode, int l, int r) {
    if (ql > r || qr < l) return 0;
    if (l >= ql && r <= qr) {
        int temp;
        //cout<<l<<" "<<r<<" "<<" "<<curnode<<" "<<tree[curnode].size()<<" ";
        temp = tree[curnode].size() - (upper_bound(tree[curnode].begin(), tree[curnode].end(), val) - tree[curnode].begin());
        //cout<<temp<<"<-\n";
        return temp;
    }
     int mid = (l+r)/2;
     int left,right;
     left = query(ql, qr, val, 2*curnode, l, mid);
     right= query (ql, qr, val, 2*curnode+1, mid+1, r);
     //cout<<l<<" "<<r<<" "<<(left+right)<<"\n";
     return (left+right);
} 
int main() {
    readi(n);
    for (int i=0; i < n; i++) readi(a[i]);
    build (1, 0, n-1);
    int q,l,r,k,ans;
    readi(q);
    ans = 0;
    while (q--) {
        readi(l), readi(r), readi(k);
        
        l ^= ans;
        r ^= ans;
        k ^= ans;
        l--; r--;
        //cout<<"Query:"<<l<<" "<<r<<" "<<k<<"\n";
        ans = query(l,r,k,1,0,n-1);
        printf("%d\n", ans);
    }
}