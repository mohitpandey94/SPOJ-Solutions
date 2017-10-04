#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t,n,x;
	cin>>t;
	while (t--) {
		cin>>n;
		int sum=0;
		for(int i=0; i < n; i++) {
			cin>>x;
			if (i&1) sum -= x;
			else sum += x;
		}
		if (sum ==0) cout<<"YES\n";
		else cout<<"NO\n";
	} 
	return 0;
}