#include <iostream>
#include <cmath>

using namespace std;
//(log(2πn)/2+n(logn−loge))/log10]+1
int main() {
	std::ios::sync_with_stdio(false);
	int t;
	double pi = 2*acos(0);
	long long int l;
	double n;
	cin>>t;
	while (t--) {
		cin>>n;
		//cout<<log10(2.0*pi*n)/2.0<<" "<<(n*log10(n)-n)<<" ";
		if (n > 3)
		l = ((((log(2.0*pi*n)/2.0) + n*(log(n) - 1)))/log(10.0)) +1;
		else l = 1;
		cout<<l<<"\n";
	}
	return 0;
}
