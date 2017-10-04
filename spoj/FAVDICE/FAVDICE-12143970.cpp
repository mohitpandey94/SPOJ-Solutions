#include <iostream>
#include <cstdio>
using namespace std;
main() {
	int t,n;
	double sum=0;
	cin>>t;
	while (t--) {
		sum=1;
		cin>>n;
		for (double i=1;i<=n-1;i++) {
			sum = sum + (n/(n-i));
		}
		printf("%.2f\n",sum);
	}
}