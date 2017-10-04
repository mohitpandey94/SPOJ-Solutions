#include<iostream>
using namespace std;
#include<vector>
#include <algorithm>
#include <stack>
#define ll long long

int main() {
	char mapper[] = {'-','m','a','n','k','u'};
	int t;
	cin>>t;
	while (t--) {
		stack <char> st;
		ll x,rem,quo;
		cin>>x;
		//cout<<x<<" ";
		while (x>0) {
			rem = x%5;
			x /= 5;
			if (!rem) {
				rem += 5;
				st.push(mapper[rem]);
				x -= 1;
			}
			else {
				st.push(mapper[rem]);
			}
		}
		char temp;
		//cout<<t<<" ";
		while (!st.empty()) {
			temp = st.top();
			st.pop();
			cout<<temp;
		}
		cout<<"\n";
	}
	return 0;
}