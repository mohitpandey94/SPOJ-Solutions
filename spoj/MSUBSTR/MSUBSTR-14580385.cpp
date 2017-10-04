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
int readi () {int n=0,sign=0;char c=gc();
while (c<48) {if (c==45) sign=1;c=gc();}
while (c>47) {n=n*10+c-'0';c=gc();}
if (sign) return (-n);	return n;
}
ll readl () {ll n=0;int sign=0;char c=gc();
while (c<48) {if (c==45) sign=1;c=gc();}
while (c>47) {n=n*10+c-'0';c=gc();}
if (sign) return (-n);	return n;
}
//
string change (string s, int len) {
    if (len == 0) return "^$";
    string ret = "^";
    repu(i,0,len,1) {
        ret = ret+"#"+s.substr(i,1);
    }
    ret += "#$";

    return ret;
}
int manacher (string s, int len) {
    int p[len+1],c=0,r=0,idash;
    memset(p,0,sizeof p);

    repu(i,1,len-1,1) {
        idash = 2*c-i;
        p[i] = (r>i)?min(r-i,p[idash]):0;

        while (s[i+1+p[i]] == s[i-1-p[i]]) p[i]++;

        if (i+p[i]>r) {
            c=i;
            r=p[i]+i;
        }
    }
    int maxi=-1,times=0;
    repu(i,1,len-1,1) {
        if (maxi==p[i]) times++;
        else if (maxi<p[i]) maxi=p[i],times=1;
        //maxi = max(p[i],maxi);
    }
    cout<<maxi<<" ";
    return times;
}
int main() {
    ios::sync_with_stdio(false);
    int t,len;
    cin>>t;
    while (t--) {
        string s,s2;
        cin>>s;
        len = s.length();
        s2 = change(s,len);
        len = s2.length();
        //cout<<s2<<" " ;
        len = manacher(s2,len);
        cout<<len<<"\n";
    }
return 0;
}
