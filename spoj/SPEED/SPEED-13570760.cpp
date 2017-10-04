#include <iostream>
#include <cmath>

using namespace std;
long long __gcd(long long a, long long b) {
	if (a%b == 0) return b;
	return __gcd(b,a%b);
}
int main() {
	long long t,s1,s2;
//	cout<<__gcd(4,2)<<" "<<__gcd(5,1)<<" "<<__gcd(17,4)<<"\n";
	cin>>t;
	while (t--) {
		cin>>s1>>s2;
		if (s2 > s1) {
			long long temp = s2;
			s2 = s1;
			s1 = temp;
		}
		cout<<((s1-s2)/__gcd(abs(s1),abs(s2)))<<"\n";
	}
	return 0;
}