#include <iostream>
using namespace std;

int main() {
	long long n;
	cin>>n;
	while (n) {
		cout<<((3*(n+1)*(n+1)-(n+1))/2)<<"\n";
		cin>>n;
	}
	return 0;
}