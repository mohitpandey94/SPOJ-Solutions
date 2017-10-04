#include<iostream>
using namespace std;
#include<vector>
#include <algorithm>
#define ll long long
int sim (int x, int y, int z) {
	int moves=0,a,b=0,transf;
	a=x;
	moves++;
	while (x != z && y != z) {
		transf = min(a,y-b);
		b += transf;
		a -= transf;
		moves++;
		
		if (a == z || b == z) break;
		if (!a) {
			a = x;
			moves++;
		}
		if (b == y) {
			b =0 ;
			moves++;
		}
	}
	
	return moves;
}
int main() {
	int t;
	cin>>t;
	while (t--) {
	ll x,y,z,ans=1;
	cin>>x>>y>>z;
	if (z > x && z>y) ans = -1;
	else {
		if (z%__gcd(x,y)) ans = -1;
		else ans = min(sim(x,y,z),sim(y,x,z));
	}
	cout<<ans<<"\n";
	}
	return 0;
}