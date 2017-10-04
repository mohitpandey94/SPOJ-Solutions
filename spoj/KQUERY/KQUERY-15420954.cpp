#include <bits/stdc++.h>
#define si(x) scanf("%d",&x)
using namespace std;
struct node {
    int l, r, val, ind;
};
typedef struct node treenode;
bool operator < (treenode a, treenode b) {
    if (a.val == b.val) {
        return a.r > b.r;
    }
    return a.val > b.val;
}

int n;
int tree[300005];
treenode a[3000005];
int result[3000005];
void update (int idx, int val) {
    while (idx <= n) {
    	tree[idx] += val;
    	idx += (idx & (-idx));
    }
}
int read (int idx) {
    int ans = 0;
    while (idx > 0) {
    	ans += tree[idx];
    	idx -= (idx&(-idx));
    }
    return ans;
}
int main() {
    si(n);
    for (int i=0; i < n; i++) {
        si(a[i].val);
        a[i].r  = -1;
        a[i].l = i+1;
    }
    int q;

    si(q);

    for (int i = 0; i < q; i++) {
        si(a[i+n].l), si(a[i+n].r), si(a[i+n].val);
        a[i+n].ind = i;
    }
    sort(a, a+n+q);
    for (int i=0; i < n+q; i++) {
        if (a[i].r == -1) {
            update(a[i].l, 1);
        }
        else {
            int ans = read(a[i].r) - read(a[i].l-1);
            result[a[i].ind] = ans;
        }
    }
    for (int i=0; i < q; i++) 
        printf("%d\n", result[i]);
}