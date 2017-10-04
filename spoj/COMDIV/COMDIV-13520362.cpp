#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int t,a,b;
	scanf("%d",&t);
	while (t--) {
		scanf("%d %d",&a,&b);
		a = __gcd(a,b);
		int count=0;
		for (int i=1; i <= sqrt(a);i++) {
			if (a%i==0) {
				count+=2;
				if (i == a/i) count--;
			}
		}
		printf("%d\n",count);
	}
	
	return 0;
}