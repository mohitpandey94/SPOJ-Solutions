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
        //cout<<low<<" "<<high<<" "<<val<< "--->";
        while (low<=high) {
                mid = (high+low)/2;
                if (v2[mid]==val) {
                        //cout<<"Found"<<"\t";
                        sze=0;
                        temp=mid-1;
                        //cout<<temp<<" "<<mid<<v2[temp]<<" "<<v2[mid]<<"\n";
                        while (mid<tot && v2[mid]==val) {
                                //cout<<sze<<" "<<mid<<"->";
                                sze++;
                                mid++;
                        }
                        //cout<<"\n";
                        while (temp>=0 && v2[temp]==val) {
                                //cout<<sze<<" "<<temp<<"->";
                                sze++;
                                temp--;
                        }
                        //cout<<"\t";
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
        int a[n],b[n],c[n],d[n],check,cnt=0,s1,s2,e,k=0;
        int i=0;
        repu(i,0,n,1) {
                a[i]=readl();b[i]=readl();c[i]=readl();d[i]=readl();
        }
        v1.clear();v2.clear();
        int j;
        repu(i,0,n,1) {
                repu(j,0,n,1) {
                        v1.pb((a[i]+b[j]));
                        v2.pb((c[i]+d[j]));
			k++;
                        //cout<<(a[i]+b[j])<<" "<<sum1[a[i]+b[j]]<<"\n";
                }
        }
        //j=n-1;
        //cout<<v1.size()<<" "<<v2.size()<<"\n";
        sort(v1.begin(),v1.end());
        sort (v2.begin(),v2.end());
    	v1[k]=v2[k]=INT_MAX;
        //cout<<v2[0]<<" "<<v2[1]<<" "<<v2[v2.size()-1]<<" "<<v2[v2.size()-2]<<"\t";
        //reverse(v2.begin(),v2.end());
        //e = v2.size();
        //cout<<e<<"\n";
        //p--;
        //cout<<v2[v2.size() - 1]<<" "<<v2[v2.size() - 2]<<" "<<v2[0]<<" "<<v2[1];
        //vector <int> :: iterator p = v2.begin();
        //p--;
        int val;
        for (vector<int> :: iterator q=v1.begin();q<v1.end();q++) {
                //cout<<(*q)<<" "<<(1<<29);
                s1=1;
                s2=binarysearch(0,v2.size(),-(*q));
                //cout<<(*q)<<" ";
                while (*q == *(q+1) && q<v1.end()) {
                        s1++;q++;
                }
                //cout<<count(v1.begin(),v1.end(),val)<<" "<<count(v2.begin(),v2.end(),-(val))<<"\n";
                cnt += (s1*s2);
                //cout<<s1<<" "<<s2<<"\n";

        }
        pi(cnt); nl();
return 0;
}




