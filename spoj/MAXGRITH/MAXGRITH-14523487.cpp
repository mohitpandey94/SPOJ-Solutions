#include <iostream>
using namespace std;
#define MOD 1000000007
int main() {
	// your code goes here
	int t;
	long long n;
	cin>>t;
	while (t--) {
		cin>>n;
		cout<<((n+1)*2/3)%MOD<<"\n";
	}
	return 0;
}