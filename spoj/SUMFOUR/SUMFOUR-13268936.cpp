#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <limits.h>
#include <algorithm>
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
#define repu(i,a,n,step) for (i = a; i < n; i += step)
#define repd(i,a,n,step) for (i = a - 1; i >= n; i += step)
using namespace std;
int readi () {
	int n=0,sign=0;
	char c=gc();
	while (c<48) {
                if (c==45) sign = 1;
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
                if (c==45) sign = 1;
                c=gc();
	}
	while (c>47) {
		n=n*10+c-'0';
		c=gc();
	}
	if (sign) return (-n);
	return n;
}
double power(double x, int y)
{
    double temp;
    if( y == 0)
       return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return temp*temp;
    else
    {
        if(y > 0)
            return x*temp*temp;
        else
            return (temp*temp)/x;
    }
}
vector <int> v1;
vector <int> v2;

int binarysearch(int low, int high, int val) {
        int mid,temp,sze=0,tot=high;

        while (low<=high) {
                mid = (high+low)/2;
                if (v2[mid]==val) {
                        sze=0;
                        temp=mid-1;

                        while (mid<tot && v2[mid]==val) {
                                sze++;
                                mid++;
                        }

                        while (temp>=0 && v2[temp]==val) {
                                sze++;
                                temp--;
                        }
                        return sze;
                }
                else if (val > v2[mid]) {
                        low = mid+1;
                }
                else if (val < v2[mid]) high = mid-1;
        }
        return 0;
}
int main() {
        int n;
        n = readi();
        int a[n],b[n],c[n],d[n],check,cnt=0,s1,s2,k=0;
        int i=0,j;

        repu(i,0,n,1) {
                a[i]=readl();b[i]=readl();c[i]=readl();d[i]=readl();
        }

        repu(i,0,n,1) {
                repu(j,0,n,1) {
                        v1.pb((a[i]+b[j]));
                        v2.pb((c[i]+d[j]));
			k++;
                }
        }

        sort(v1.begin(),v1.end());
        sort (v2.begin(),v2.end());
    	v1[k]=v2[k]=INT_MAX;

        int val;
        for (vector<int> :: iterator q=v1.begin();q<v1.end();q++) {

                s1=1;
                s2=binarysearch(0,k,-(*q));

                while (*q == *(q+1) && q<v1.end()) {
                        s1++;q++;
                }

                cnt += (s1*s2);
                //cout<<s1<<" "<<s2<<"\n";

        }
        pi(cnt); nl();
return 0;
}





