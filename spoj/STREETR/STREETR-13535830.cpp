#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
	long long n,x,y,gcd=0,maxm=0;
	long long ans=0;
	scanf("%lld",&n);
	long long diff[n],diff2,diffsum=0;
	scanf("%lld",&diff[0]);
	maxm=diff[0];
	for (int i=1;i<n;i++) {
		scanf("%lld",&diff[i]);
		maxm = max(diff[i],maxm);
		diff2 = diff[i]-diff[i-1];
		//if (diff2<0) diff2*=-1;
		diffsum += diff2;
		gcd = __gcd(gcd,diff2);
		//cout<<"gcd="<<gcd<<" ";
	}
	/*for (int i=1;i<n;i++) {
		diff2 = diff[i]-diff[i-1];
		ans += (diff2/gcd) -1;
	}*/
	ans = diffsum/gcd - n+1;
	//cout<<gcd<<" "<<maxm<<" "<<n<<" ";
	// = ceil((double)(maxm*1.0/gcd)) - n;
	printf("%lld\n",ans);
	
	return 0;
}