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
int a[10005],b[10005];
int suma[10005],sumb[10005];
int intersections[10005],diff1,diff2;
map<int,int> hasher;
ll anssum;
int main() {
    int n,m,intersect;
    n = readi();
    while (n) {
        repu(i,0,n,1) {
            a[i] = readi();
            if (i == 0) suma[0] = a[0];
            else suma[i] = suma[i-1] + a[i];
            hasher[a[i]] = i+1;
        }
        intersect = 0;
        m = readi();
        repu(i,0,m,1){
            b[i] = readi();
            if (i == 0) sumb[0] = b[0];
            else sumb[i] = sumb[i-1] + b[i];
            if (hasher[b[i]]) {
                //cout<<"here";
                intersections[++intersect] = i;
                diff1 = (suma[hasher[b[intersections[intersect]]]-1]-suma[hasher[b[intersections[intersect-1]]]-1]);
                diff2 = (sumb[intersections[intersect]]-sumb[intersections[intersect-1]]);
                if (intersect == 1) {
                    diff1 = suma[hasher[b[intersections[intersect]]]-1];
                    diff2 = sumb[intersections[intersect]];
                }
                anssum += (diff1 > diff2 ? diff1 : diff2);
                //cout<<"hrer"<<diff1<<" "<<diff2<<" "<<anssum<<"\n";
            }
            if (i == m-1) {
                diff1 = suma[n-1] - suma[hasher[b[intersections[intersect]]]-1];
                diff2 = sumb[m-1] - sumb[intersections[intersect]];
                anssum += (diff1 > diff2 ? diff1 : diff2);
                //cout<<"here"<<anssum<<"\n";
            }
            //cout<<b[i]<<" ans="<<anssum<<"\n";
        }
        if (intersect == 0) anssum = (suma[n-1] > sumb[m-1] ? suma[n-1] : sumb[m-1]);
        cout<<anssum<<"\n";
        memset(suma,0,sizeof suma);
        memset(sumb,0,sizeof sumb);
        memset(intersections,0,sizeof intersections);
        hasher.clear();
        anssum = 0;
        n = readi();
    }
return 0;
}
