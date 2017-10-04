#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int t;
	long long n,pro;
	cin>>t;
	while (t--) {
		cin>>n;
		double ans = ((double)(n*1.0)/(double)((n+1)*1.0));
		cout<<setprecision(8)<<fixed<<ans<<"\n";
	}
	return 0;
}