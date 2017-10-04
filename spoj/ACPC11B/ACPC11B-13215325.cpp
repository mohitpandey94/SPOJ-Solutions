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
int readi () {
	int n=0;
	char c=gc();
	while (c<48) c=gc();
	while (c>47) {
		n=n*10+c-'0';
		c=gc();
	}
	return n;
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

int main() {
        int t,n1,n2,a[1000],b[1000],i=0,j=0,min1,min2,min;
        t=readi();
        while (t--) {
                i=0;
                n1=readi();
                repu(i,n1,1) a[i]=readi();
                //sort(a,a+n1);
                i=0;
                n2=readi();
                repu(i,n2,1) b[i]=readi();
                //sort(b,b+n2);
                i=0;
                min = 1000001;
                repu(i,n1,1) {
                        j=0;
                        while (j<n2) {
                                min1 = ((a[i]-b[j])>0)?(a[i]-b[j]):((a[i]-b[j])*-1);

                                if (min1<min) min=min1;
                                j++;
                        }

                }
                cout<<min<<endl;
        }
return 0;
}
