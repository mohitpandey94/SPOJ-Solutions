#include <bits/stdc++.h>
using namespace std;
int primes[10010];
bool isprime[10010];
int k=0;
void seive () {
	memset(isprime,true,sizeof(isprime));
	isprime[0] = isprime[1] = false;
	for (int i=2; i<=10009; i++) {
		if (isprime[i]) {
			for (int j = i+i; j<=10009; j += i) {
				isprime[j] = false;
			}
			primes[k++] = i;
		}
	}
	return ;
}
int powers[10009];
vector<pair<int,int> > present;
int main() {
    seive();
    //for (int i=0; i <= 10; i++) cout<<primes[i]<<" ";cout<<"\n";
    int n;
    cin>>n;
    for (int i=2; i<=n; i++) {
	int temp = i;
	for (int j=0; j < k && temp; j++) {
	    while (temp && temp%primes[j] == 0) {
		powers[j]++;    
		temp /= primes[j];
	    }
	} 
    }
    for (int j=0; j < k; j++) {
	if (powers[j]) {    
	    present.push_back(make_pair(primes[j], powers[j]));
	    //cout<<primes[j]<<"^"<<powers[j]<<" ";
	}
    }
    cout<<present[0].first<<"^"<<present[0].second;
    for (int i=1; i < present.size(); i++) 
	cout<<" * "<<present[i].first<<"^"<<present[i].second;
    cout<<"\n";
    return 0;
}
