#include <bits/stdc++.h>
using namespace std;
bool prime[100005];
void seive () {
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;
	for (int i=2; i < 100005; i++) {
		if (prime[i]) {
			for (int j = i+i; j < 100005; j += i) {
				prime[j] = false;
			}
		}
	}
}
int main() {
	// your code goes here
	seive();
	int countp[100005], cnt = 0;
	for (int i=1; i < 100005; i++) {
		if (prime[i]) {
			cnt++;
		}
		countp[i] = cnt;
	}
	long long t,n,k;
	cin>>t;
	while (t--) {
		cin>>n>>k;
		if (n < 4) {
			cout<<0 <<" "<<0<<endl;
			 continue;
		}
		int ans1 = (int) sqrt((double) n);
		ans1 = countp[ans1];
		int ans2 =(int) sqrt((double) k);
		ans2 = ans1 - countp[ans2];
		if (k > n) ans2=0;
		cout<<ans1 <<" "<<ans2<<endl;
	}
	return 0;
}