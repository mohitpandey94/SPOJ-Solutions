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
struct suffix {
    int pr,nr,pos;
} L[1010];
int pos[20][1010];
int cmp (struct suffix a, struct suffix b) {
    return a.pr==b.pr ? (a.nr < b.nr ? 1:0) : (a.pr < b.pr ? 1:0);
}
void suffix_cal (string s) {
    int len = s.length(),cnt = 0, step = 0;
    repu(i,0,len,1) pos[step][i] = s[i]-'A';

    for (step = 1,cnt = 1; cnt < len; step++, cnt *=2) {
        repu(i,0,len,1) {
            L[i].pr = pos[step-1][i];
            L[i].nr = (i+cnt < len) ? pos[step-1][i+cnt] : -1;
            L[i].pos = i;
        }

        sort(L,L+len,cmp);
        pos[step][L[0].pos] = 0;
        repu(i,1,len,1) {
            pos[step][L[i].pos] = i;
            if (L[i].pr == L[i-1].pr) {
                if (L[i].nr == L[i-1].nr) {
                    pos[step][L[i].pos] = pos[step][L[i-1].pos];
                }
            }
        }

    }
    return ;
}
int lcpp (int x, int y, int n) {
    int k,ret=0;
    if (x == y) return (n-x);
    int step = ceil(log2(n));
    for (k=step-1;k>=0 && x < n && y < n; k--)
        if (pos[k][x] == pos[k][y])
            x += 1<<k, y += 1<<k, ret += 1<<k;

    return ret;
}
void print (int st, int e, string s) {
    repu(i,st,e,1) cout<<s[i];
}
int main() {
    string s;
    int t;
    t = readi();
    while (t--) {
        cin>>s;
        suffix_cal(s);

        int len = s.length();
        /*
        repu(i,0,len,1) {
            cout<<L[i].pos<<":";
            print(L[i].pos,len,s);
            nl();
        }
        */
        int sum=0;
        //lcp[0][0]=0;
        //lcp[1][0] = 0;
        repu(i,1,len,1) {
            //lcp[L[i].pos][L[i-1].pos] = ;
            //cout<<lcp[L[i].pos][L[i-1].pos]<<"\n";
            sum += lcpp(L[i].pos,L[i-1].pos,len);
        }
        cout<<(((len*(len+1))/2)-sum)<<"\n";
    }
return 0;
}
