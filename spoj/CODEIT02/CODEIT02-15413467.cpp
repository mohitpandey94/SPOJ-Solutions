#include <bits/stdc++.h>
#define si(x) scanf("%d", &x)
using namespace std;
int x[21];
/*
int bitmasks (int n, int k) {
	int maxxor = -1;
	int curxor = 0;
	int nn = 1<<n;
	int choose = 0,i,j;
	for (i=0; i < nn; i++) {
		choose = 0;
		curxor = 0;
		for (j=0; j < n &&  choose <= k; j++) {
			if (i&(1<<j)) {
				choose++;
				curxor ^= x[j];
			}
		}
		if (choose != k) continue;
		maxxor = max  (maxxor, curxor);
	}
	return maxxor;
}	
*/
int secondmethod (int n, int k) {
	char s[n+1];
	int maxxor, curxor;
	maxxor = -1;
	for (int i=0; i < n-k; i++) s[i] = '0';
	for (int i=n-k; i < n; i++) s[i] = '1';
	s[n] = '\0';
	//cout<<s<<"\n";
	
	do {
		//cout<<s<<" ";
		curxor = 0;
		for (int i=0; i < n; i++) {
			if (s[i] == '1') {
				curxor ^= x[i];
			}
		}
		maxxor = max (maxxor, curxor);
	} while (next_permutation(s, s+n));
	
	return maxxor;
}
int main() {
	int t,n,k,ans;
	si(t);
	while (t--) {
		si(n), si(k);
		
		for (int i=0; i < n; i++) si(x[i]);
		//ans = bitmasks(n, k);
		ans = secondmethod(n, k);
		printf("%d\n", ans);
	}
}