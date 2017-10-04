#include <iostream>
#include <cstdio>
using namespace std;
long long gcd(long long a, long long b) {
	if (a%b == 0) return b;
	return gcd(b,a%b);
}
int main() {
	//cout<<gcd(4,2)<<" "<<gcd(9,3)<<" "<<gcd(5,3)<<" "<<gcd(9,1)<<"\n";
	int t;
	long long a,b,x,y,pro,lcm;
	scanf("%d",&t);
	while (t--) {
		scanf("%lld %lld",&a,&b);
		pro = a*b;
		x = a;
		y = b;
		if (b>a) {
			a = a+b;
			b = a-b;
			a = a-b;
		}
		lcm = gcd(a,b);
		lcm = pro/lcm;
		printf("%lld %lld\n",(lcm/x),(lcm/y));
	}
	return 0;
}