#include <iostream>
#include <cmath>
using namespace std;

int main() {
	// your code goes here
	int t,n;
	cin>>t;
	while (t--) {
		cin>>n;
		int ans = ceil(log2(n));
		ans++;
		cout<<ans<<"\n";
	}
	return 0;
}