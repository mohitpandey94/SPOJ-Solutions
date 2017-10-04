#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int main() {
	long long n;
	scanf("%lld",&n);
	while (n) {
		long long c[n],p[n],sum=0;
		for (int i=0;i<n;i++) scanf("%lld",&c[i]);
		for (int i=0;i<n;i++) scanf("%lld",&p[i]);
		sort(c,c+n);
		sort(p,p+n);
		for (int i=0,j=n-1;i<n;i++,j--) {
			sum += c[i]*p[j];
		}
		printf("%lld\n",sum);
		scanf("%lld",&n);
	}
	return 0;
}