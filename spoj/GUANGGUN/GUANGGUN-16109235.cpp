#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int main() {
    ull n,ans;

	cin>>n;
    while (!cin.eof()) {
	ans = (n/9)*81+(n%9)*(n%9);
	cout<<ans<<"\n";
	cin>>n;
    }

}
