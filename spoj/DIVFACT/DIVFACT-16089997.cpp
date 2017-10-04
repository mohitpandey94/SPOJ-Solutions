#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long primes[1000000];
bool isprime[1000000];
int k=0;
void seive () {
	memset(isprime,true,sizeof(isprime));
	isprime[0] = isprime[1] = false;
	for (int i=2; i*i<=1000000; i++) {
		if (isprime[i]) {
			for (int j = i*i; j<=1000000; j += i) {
				isprime[j] = false;
			}
			//primes[k++] = i;
		}
	}
	for (int i=0; i <= 1000000; i++) if (isprime[i]) primes[k++] = i;
	return ;
}
int main() {
	seive();
	//for (int i=0; i <= 10; i++) cout<<primes[i]<<" ";cout<<"\n";
	int t;
	cin>>t;
	while (t--) {
		long long n;
		cin>>n;
		long long x =2, pro=1;
		for (int i=0; primes[i] <= n; i++) {
		    x = n;
		    int expo = 0;
		    while (x) {
			expo = expo+(x/primes[i]);
			x /= primes[i];
		    }
		    pro = (pro*(expo+1))%MOD;
		    //powers[i] = expo;
		}
		//cout<<primes[last]<<" "<
		/*
		long long pro = 1LL;
		for (int j=0; j < k; j++) {
			if (powers[j]) {    
				pro = (pro * (powers[j]+1))%MOD;
				//present.push_back(make_pair(primes[j], powers[j]));
				//cout<<primes[j]<<"^"<<powers[j]<<" ";
			}
		}
		*/
		/*
		   cout<<present[0].first<<"^"<<present[0].second;
		   for (int i=1; i < present.size(); i++) 
		   cout<<" * "<<present[i].first<<"^"<<present[i].second;
		 */
		cout<<pro<<"\n";
	}
	return 0;
}
