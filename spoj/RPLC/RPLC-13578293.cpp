#include <iostream>
#include <cstdio>
using namespace std;
long long gcd(long long a, long long b) {
	if (a%b == 0) return b;
	return gcd(b,a%b);
}
int main() {
	//cout<<gcd(4,2)<<" "<<gcd(9,3)<<" "<<gcd(5,3)<<" "<<gcd(9,1)<<"\n";
	long long a,minsum,sum,t,n,i;
	scanf("%lld",&t);
	for (i=1;i<=t;i++) {
		scanf("%lld",&n);
		sum=0;
		minsum = 10000005;
		while (n--) {
			scanf("%lld",&a);
			sum += a;
			if (sum < minsum) minsum = sum;
		}
		if (minsum < 0) {
			minsum *= -1;
			printf("Scenario #%lld: %lld\n",i,(minsum+1));
		}
		else printf("Scenario #%lld: 1\n",i);
	}
	return 0;
}