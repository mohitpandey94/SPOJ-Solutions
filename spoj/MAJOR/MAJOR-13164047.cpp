#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
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
vector<int>a;
int main() {
        int t,n,x,threshold,flag,i,count;
        t=readi();
        while (t--) {
                n=readi();
                flag=0;
                threshold = (n/2) +1;
                //cout<<threshold<<endl;
                i=0;
                repu(i,n,1) {
                        x=readi();
                        a.pb(x);
                }

                i=0;
                sort(a.begin(),a.end());
                //repu(i,n,1) cout<<a[i]<<" ";
                //cout<<endl;
                i=1;
                count=1;
                repu(i,n,1) {
                       // cout<<a[i]<<" "<<a[i-1]<<endl;
                        if (a[i]==a[i-1]) count++;
                        if (count >= threshold) {
                                ps("YES ");
                                pi(a[i]);
                                nl();
                                flag=1;
                                break;
                        }
                        if (a[i] != a[i-1]) count=1;
                        //cout<<count<<" "<<a[i]<<"\t";
                }


                if (flag==0)
                        ps("NO\n");
                a.clear();

        }
return 0;
}
