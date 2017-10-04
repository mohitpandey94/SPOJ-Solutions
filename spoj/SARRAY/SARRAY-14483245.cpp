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
} L[50005];
int pos[17][50005],step;
char s[50005];
int cmp (struct suffix a, struct suffix b) {
    return a.pr==b.pr ? (a.nr < b.nr ? 1:0) : (a.pr < b.pr ? 1:0);
}
void suffix_cal (char s[] , int len) {
    int cnt = 0;
    step = 0;
    repu(i,0,len,1) pos[step][i] = s[i]-'0';

    for (step = 1,cnt = 1; cnt < len; step++, cnt <<=1) {
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
/*
int logarithm2 (int n) {
    int ans = 0;
    while (n) {
        n /= 2;
        ans++;
    }
    return ans;
}
*/
/*
int lcpp (int x, int y, int n) {
    int k,ret=0;
    if (x == y) return (n-x);
    for (k=step-1;k>=0 && x < n && y < n; k--)
        if (pos[k][x] == pos[k][y])
            x += 1<<k, y += 1<<k, ret += 1<<k;

    return ret;
}

void print (int st, int e, string s) {
    repu(i,st,e,1) cout<<s[i];
}
*/
int main() {
    int t;
    t = 1;
    while (t--) {
        scanf("%s",&s);
        int len = 0;
        while (s[len] != '\0') len++;
        //cout<<len<<" ";
        suffix_cal(s,len);

        repu(i,0,len,1) {
            pi(L[i].pos);
            //print(L[i].pos,len,s);
            nl();
        }

        /*
        int sum=0;
        //lcp[0][0]=0;
        //lcp[1][0] = 0;
        repu(i,1,len,1) {
            //lcp[L[i].pos][L[i-1].pos] = ;
            //cout<<lcp[L[i].pos][L[i-1].pos]<<"\n";
            sum += lcpp(L[i].pos,L[i-1].pos,len);
        }
        pi(((ll)((len*1LL)*((len+1LL)*1LL)))/2LL-sum);
        nl();
        */
    }
return 0;
}
