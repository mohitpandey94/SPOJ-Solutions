#include <bits/stdc++.h>

using namespace std;

int main() {
	long long t,n;
	scanf("%lld",&t);
	while (t--) {
		scanf("%lld",&n);
		n = (n*(n+1))/6;
		printf("%lld\n",n);
	}
	return 0;
}