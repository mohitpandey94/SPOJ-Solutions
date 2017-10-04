#include<iostream>
using namespace std;
#include<vector>
#include <algorithm>
#define ll long long
 
int main() {
	int t;
	cin>>t;
	while (t--) {
	ll x,y,z,ans=1;
	cin>>x>>y>>z;
	if (z > x && z>y) ans = -1;
	else {
		if (z%__gcd(x,y)) ans = -1;
	}
	if (ans==1) cout<<"YES\n";
	else cout<<"NO\n";
	}
	return 0;
}