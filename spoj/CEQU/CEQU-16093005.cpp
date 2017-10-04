#include <bits/stdc++.h>
using namespace std;
int main() {
    int t,a,b,c;
    cin>>t;
    for (int tc=1; tc<=t; tc++) {
	cin>>a>>b>>c;
	cout<<"Case "<<tc<<": ";
	if (c%__gcd(a,b) == 0) cout<<"Yes\n";
	else cout<<"No\n";
}
    return 0;
}
