#include <bits/stdc++.h>
#define si(x) scanf("%d",&x)
#define gc getchar_unlocked
using namespace std;
#define BLOCK 555
int readint() {
    char c = gc();
    int n = 0;
    while (c < '0' || c > '9') c=gc();
    while (c >= '0' and c <= '9') {
        n = n*10 + c-'0';
        c = gc();
    }
    return n;
}
int a[311111], counti[1100002], ans[311111], maxx = 0;
struct querynode {
    int l,r,idx;
};
struct querynode query[200005];
bool cmp (struct querynode a, struct querynode b) {
    if (a.l/BLOCK != b.l/BLOCK) return a.l/BLOCK < b.l/BLOCK;
    return a.r < b.r;
}
void add (int pos) {
    counti[a[pos]]++;
    if (counti[a[pos]] == 1) maxx++;
}
void del (int pos) {
    counti[a[pos]]--;
    if (counti[a[pos]] == 0) maxx--;
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("C:\\Users\\Mohit Kumar Pandey\\Desktop\\IP_ass\\input.txt","r",stdin);
    #endif
    int t,n,c,q;
    t=1;
    for (int tc=1;tc<=t;tc++) {
        //cout<<"Case "<<tc<<":"<<endl;
        n=readint();
        //cout<<n<<" "<<c<<" "<<q<<endl;
        for (int i=0;i<n;i++) {
            a[i] = readint();
            //a[i]--;
        }
        q = readint();
        for (int i=0;i<q;i++) {
            query[i].l = readint(),query[i].r = readint();
            query[i].l--; query[i].r--;
            query[i].idx = i;
        }
        sort(query,query+q, cmp);
        int cl,cr;
        cl=cr=0;
        //memset(counti,0,sizeof(counti));
        for (int i=0; i < q; i++) {
            int l=query[i].l, r=query[i].r;
            //cout<<i<<" "<<l<<" "<<r<<endl;
            while (cl < l) {
                counti[a[cl]]--;
                if (counti[a[cl]] == 0) maxx--;
                cl++;
            }
            while (cl > l) {
                counti[a[cl-1]]++;
                if (counti[a[cl-1]] == 1) maxx++;
                cl--;
            }
            while (cr <= r) {
                counti[a[cr]]++;
                if (counti[a[cr]] == 1) maxx++;
                cr++;
            }
            while (cr > r+1) {
                counti[a[cr-1]]--;
                if (counti[a[cr-1]] == 0) maxx--;
                cr--;
            }
            //cout<<maxx<<" ";
            ans[query[i].idx] = maxx;
        }
        for (int i=0; i < q; i++) {
            //cout<<ans[i]<<endl;
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}
