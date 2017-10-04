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
string reverse (string a) {
    int len = a.length();
    string temp;
    for (int i = 0;i < len; i++) {
        temp += a[len-i-1];
    }
    //cout<<temp<<"<\n";
    return temp;
}
void lcsprint(string a, string b, string taken[105][105]) {

	int i = (a).length(), j = (b).length();
    string temp;
	while (i && j) {
		if (taken[i][j] == "iless+jless") {
			temp += a[i-1];
			i--;j--;
		}
		else if (taken[i][j] == "ilessonly") {
			i--;
		}
		else {
			j--;
		}
	}
    i = a.length()-1,j = b.length()-1;
    string ans;
    int ind = 0,upto = temp.length();
    while (i >= 0 || j >= 0) {
        if (ind < upto) {
            while (i>=0 && a[i] != temp[ind]) {
                ans += a[i];
                i--;
            }
            while (j >= 0 && b[j] != temp[ind]) {
                ans += b[j];
                j--;
            }
            ans += temp[ind];
            ind++; i--; j--;
        }
        else {
            while (i >= 0) {
                ans += a[i];
                i--;
            }
            while (j >= 0) {
                ans += b[j];
                j--;
            }
        }
    }
    ans = reverse(ans);
    cout<<ans<<"\n";

}
int dp[105][105];
string taken[105][105];
int lcslen (string a, string b) {
	int n  = a.length();
	int	m = (b).length();

	//init
	repu(i,0,n+1,1) dp[i][0] = 0;
	repu(j,0,m+1,1) dp[0][j] = 0;

	repu(i,1,n+1,1) {
		repu(j,1,m+1,1) {
			if (a[i-1] == b[j-1]) {
				dp[i][j] = dp[i-1][j-1]+1;
				taken[i][j] = "iless+jless";
			}
			else {
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
				if (dp[i-1][j] > dp[i][j-1]) taken[i][j] = "ilessonly";
				else taken[i][j] = "jlessonly";
			}
		}
	}
	lcsprint(a,b,taken);
}
int main() {
    //char s[105],ss[105];
    string s,ss;
    while (!cin.eof()) {
        //scanf("%s",&ss)
        cin>>s>>ss;
        lcslen(s,ss);
    }
return 0;
}
