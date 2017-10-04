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
int main() {
    string a,b;
    cin>>a;
    int count1=0,count2=0;
    while (!cin.eof()) {
        int len = a.length();
        b=a;
        repu(i,0,len,1) {
            if (!(i&1) && (a[i] >= 'a' && a[i] <= 'z')) {
                a[i] = a[i]-'a' + 'A';
                count1++;;
            }
            else if (i&1 && (a[i] >= 'A' && a[i] <= 'Z')) {
                a[i] = a[i]-'A' + 'a';
                count1++;
            }
        }
        repu(i,0,len,1) {
            //cout<<b[i]<<" ";
            if (!(i&1) && (b[i] >= 'A' && b[i] <= 'Z')) {
                b[i] = b[i]-'A' + 'a';
                //cout<<b[i]<<" ";
                count2++;;
            }
            else if (i&1 && (b[i] >= 'a' && b[i] <= 'z')) {
                b[i] = b[i]-'a' + 'A';
                count2++;
            }
        }
        //cout<<count1<<" "<<count2<<"\n";
        cout<<min(count1,count2)<<"\n";
        count1=count2=0;
        cin>>a;
    }
return 0;
}
