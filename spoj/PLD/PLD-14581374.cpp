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
int p1[30055],p2[30055],k;
string s;
/*
void change (string &s, int len) {
    //if (len == 0) return "^$";
    string ret = "^";
    repu(i,0,len,1) {
        ret = ret+"#"+s[i];
    }
    ret += "#$";
    //cout<<ret<<" ";
    s=ret;
    //return ret;
}
int manacher (string s, int len) {
    /*
    int c=0,r=0,idash,times=0;
    //memset(p,0,sizeof p);

    repu(i,1,len-1,1) {
        idash = 2*c-i;
        p[i] = (r>i)?((r-i) < p[idash]?(r-i):p[idash]):0;

        while (s[i+1+p[i]] == s[i-1-p[i]]) p[i]++;

        if (i+p[i]>r) {
            c=i;
            r=p[i]+i;
        }
        //if ((p[i]>=k) && !((p[i]^k)&1)) times++;
        if ((p[i] >= k) && ((p[i]&1 && k&1) || (!(p[i]&1) && !(k&1)))) times++;
    }

    //int times=0;
    //repu(i,1,len-1,1) {

        //if (maxi==p[i]) times++;
        //else if (maxi<p[i]) maxi=p[i],times=1;
        //maxi = max(p[i],maxi);
    //}
    //cout<<maxi<<" ";


    int times1=0,times2=0;
    //cout<<k<<" ";

    //cout<<"\n";

    //cout<<"\n";
    cout<<times1<<" "<<times2<<"\n";
    return max(times1,times2);
}
*/
int manacherodd (string s, int len) {
    int k2,l=0,r=-1;
    repu(i,0,len,1) {
        k2=(i>r?0:min(p1[l+r-i],r-i))+1;
        while (i+k2 < len && i-k2 >= 0 && s[i+k2] == s[i-k2]) ++k2;
        p1[i]=--k2;
        if (i+k2>r) l=i-k2,r=i+k2;
    }
    int times=0;
    repu(i,0,len,1) {
        //cout<<s[i]<<":"<<p1[i]<<"\n";
        if ((p1[i]*2+1 >= k)) times++;
    }

    return times;
}
int manachereven (string s, int len) {
    int k2,l=0,r=-1;
    repu(i,0,len,1) {
        k2=(i>r?0:min(p2[l+r-i+1],r-i+1))+1;
        while (i+k2-1<len && i-k2>=0 && s[i+k2-1] == s[i-k2]) ++k2;
        p2[i] = --k2;
        if (i+k2-1>r) l=i-k2,r=i+k2-1;
    }
    int times=0;
    repu(i,0,len,1) {
        //cout<<p2[i]<<" ";
        if ((p2[i]*2 >= k)) times++;
    }

    return times;
}
int main() {
    ios::sync_with_stdio(false);
    //int i=1;
    //cout<<(++i)<<" "<<i;
    //cout<<" "<<++i;
    int t,len;
    /*
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
    */
    cin>>k;
    cin>>s;
    len = s.length();
    //change(s,len);
    //len = 2*len+3;
    if (k&1)
        len = manacherodd(s,len);
    else len = manachereven(s,len);
    cout<<len<<"\n";
return 0;
}
