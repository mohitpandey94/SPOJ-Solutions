#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll fib[46];
void pre() {
	fib[0] = 1; fib[1] = 2;
	for (int i=2; i<=45; i++) {
		fib[i] = fib[i-1]+fib[i-2];
	}
	return ;
}
int main() {
	// your code goes here
	pre();
	int t,n;
	cin>>t;
	while (t--) {
		cin>>n;
		cout<<fib[n]<<"\n";
	}
	return 0;
}