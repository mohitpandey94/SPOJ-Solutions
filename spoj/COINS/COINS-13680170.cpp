#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
map <long long , long long> h;
long long maxv (long long n) {
	if (n <= 0) return 0;
	long long p = h[n];
	if (p == 0) {
		p = (max(n,maxv(n/2) + maxv(n/3)+ maxv(n/4)));
		h[n] = p;
	}
	return p;
}
int main() {
	long long n;
	while (scanf("%lld",&n) != EOF)
		printf("%lld\n",maxv(n));
	return 0;
}