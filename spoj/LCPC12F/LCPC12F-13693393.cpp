#include <bits/stdc++.h>
#define gc getchar_unlocked
using namespace std;
int readint () {
	int n=0;
	char c = gc();
	while (c<'0') c=gc();
	while (c>='0' && c<='9') {
		n = n*10+c-'0';
		c=gc();
	}
	return n;
}

int main() {
	int t,x,n,a[100010],tc=1;
	long long count=0;
	t=readint();
	while (tc <= t) {
		x=readint();
		n=readint();
		//freq.resize(1010);
		for (int i=0;i<n;i++) {
			a[i]=readint();
			//freq[a[i]].push_back(i);
		}
		vector <int> freq(1010,0);
		for (int i=n-1;i>=0;i--) {
			if (x-a[i] >=0 && x-a[i]<=1000)
			count += freq[x-a[i]];
			freq[a[i]]++;
		}
		printf("%d. %lld\n",tc,count);
		tc++;
		count=0;
	}
	return 0;
}
