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

void update(int tree[],int idx, int val, int n) {
        while (idx <= n) {
                tree[idx] += val;
                idx += (idx & -idx);
        }
}
ll read(int idx, int tree[]) {
        ll sum = 0;
        while (idx >= 1) {
                sum += tree[idx];
                idx -= (idx & -idx);
        }
        return sum;
}
void print (int x[], int n) {
        repu(i,1,n+1,1) cout<<x[i]<<" ";
        nl();
}
ll counter (int a[], int n, int tree[]) {
        ll inversions = 0,x;
        repd(i,n+1,1,1) {
                x = read(a[i]-1,tree);
                //cout<<x<<" ";
                inversions += x;
                update(tree,a[i],1,n);
        }
        return inversions;
}
int main() {
        cout.tie(0);
        cin.tie(0);
        int t;
        cin>>t;
        while (t--) {
                map <string,int> mp;
                int n;
                cin>>n;
                int a[n+1],tree[n+1];
                memset(tree,0,sizeof tree);
                string s;
                repu(i,1,n+1,1) {
                        cin>>s;
                        mp[s] = i;
                }

                repu(i,1,n+1,1) {
                        cin>>s;
                        a[i]=mp[s];
                }
                //print(a,n);
                cout<<counter(a,n,tree)<<"\n";
        }
return 0;
}
