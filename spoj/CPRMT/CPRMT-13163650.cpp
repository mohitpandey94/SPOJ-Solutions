#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
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
char s1[1010],s2[1010];
int main() {

        int i,len1,len2,j;

        while (scanf("%s %s",&s1,&s2)!=EOF) {
                i=0;
                int count[26]={0};
                //cout<<s1<<endl<<s2;

                len1=strlen(s1);
                repu(i,len1,1) count[s1[i]-'a']++;
                len2  =strlen(s2);
                sort(s2,s2+len2);
                i=0;
                repu(i,len2,1) {
                        if (count[s2[i]-'a']) {
                                cout<<s2[i];
                                count[s2[i]-'a']--;
                        }
                }
                cout<<endl;
        }

return 0;
}
