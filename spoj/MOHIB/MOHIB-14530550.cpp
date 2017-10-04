#include <iostream>
using namespace std;

int main() {
	int t,x,avg,n,sum;
	cin>>t;
	while (t--) {
		cin>>x>>avg;
		n = avg-x+1;
		sum = n*avg-x;
		if (n-2 < 0) cout<<sum<<"\n";
		else {
			cout<<(sum - ((n-1)*(n-2))/2)<<"\n";
		}
	}
	return 0;
}