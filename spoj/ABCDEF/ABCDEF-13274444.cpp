#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
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
long int e1[1000000];
long int e2[1000000];
int binarysearch(int low, int high, long int val) {
        int mid,temp,tot=high,s2=0;
        while (low<=high) {
                mid = (high+low)/2;
                if (e2[mid]==val) {
                        temp=mid-1;
                        while (mid<tot && e2[mid]==val) {
                                s2++;mid++;
                        }
                        while (temp>=0 && e2[temp]==val) {
                                s2++;
                                temp--;
                        }
                        return s2;
                }
                else if (e2[mid] > val) {
                        high=mid-1;
                }
                else low = mid+1;
        }
        return 0;
}
int main() {
        int n;
        n = readi();
        int a[n];
        int i=0,j,k,x=0,y=0,cnt=0,s1=0,s2=0;
        repu(i,0,n,1) a[i]=readi();

        repu(i,0,n,1) {
                repu(j,0,n,1) {
                        repu(k,0,n,1) {
                                e1[x] = (a[i]*a[j])+a[k];
                                if (a[k]!=0) {
                                	e2[y] = (a[i]+a[j])*a[k];
                                	y++;
                                }
                                x++;

                        }
                }
        }

        sort(e1,e1+x);
        sort(e2,e2+y);
        e1[x] = e2[y] = INT_MAX;
        repu(i,0,x,1) {
                s1=1;s2=0;
                s2 = binarysearch(0,y,e1[i]);
                while (e1[i] == e1[i+1]) {
                        s1++;
                        i++;
                }
                cnt += (s1*s2);
                //cout<<s1<<" "<<s2<<"\n";

        }
        pi(cnt); nl();
return 0;
}


