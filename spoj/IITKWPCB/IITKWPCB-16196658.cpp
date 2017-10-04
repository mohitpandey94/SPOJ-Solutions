#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	long long n,hlf;
	cin>>t;
	while (t--) {
		cin>>n;
		hlf = floor (n/2);
		if (!(n&1)) {
			hlf--;
			if (!(hlf&1))
				hlf = hlf-1;
		}
		cout<<hlf<<"\n";
	}
	
	return 0;
}