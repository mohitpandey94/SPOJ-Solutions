#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
#include <climits>
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
#define repd(i,a,n,step) for (int i = a - 1; i >= n; i += step)
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

ll counter = 0;
void merge(int a[], int low, int pivot, int high) {
        int i,j;
        ll n1 = pivot - low + 2;
        ll n2 = high - pivot + 1;
        ll l[n1],r[n2];
        for (i = 0; i < n1; i++) {
                l[i] = a[low+i];
        }
        for (j = 0; j < n2; j++) {
                r[j] = a[pivot + j+1];
        }
        l[n1-1] = INT_MAX;
        r[n2-1] = INT_MAX;
        i=0;j=0;
        for (int k = low; k <= high; k++) {
                if (l[i] <= r[j]) {
                        a[k] = l[i];
                        i++;
                }
                else {
                        a[k] = r[j];
                        counter += (n1-i-1);
                        j++;
                }
        }
}

void mergesort(int a[], int low, int high) {

        if (low < high) {
                int p = (low+high)/2;
                mergesort(a,low,p);
                mergesort(a,p+1,high);
                merge(a,low,p,high);
        }
}
int main() {
        cout.tie(0);
        cin.tie(0);
        int t;
        cin>>t;
        while (t--) {
       	map <string,int> mp;
        int n;
        cin>>n;
        int a[n];
        string s;
        repu(i,0,n,1) {
        	cin>>s;
        	mp[s] = i;
        	//cout<<mp[s]<<" ";
        }
        //cout<<"<";
        repu(i,0,n,1) {
        	cin>>s;
        	a[i]=mp[s];
        	//cout<< mp[s]<<" ";
        }
        mergesort(a,0,n-1);
        cout<<counter<<"\n";
        counter=0;
        }
return 0;
}
