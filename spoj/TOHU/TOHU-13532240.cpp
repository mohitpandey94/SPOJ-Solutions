#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

int main() {
	int t;
	long double n;
	cin>>t;
	while (t--) {
		scanf("%llf",&n);
		double sum = (9.00/12.00) - (1.00/(2.00*(n+1.00)*(n+2.00)));
		printf("%.11f\n",sum);
	} 
	return 0;
}