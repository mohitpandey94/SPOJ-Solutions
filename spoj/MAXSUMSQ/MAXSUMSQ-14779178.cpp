#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define gc getchar
#else
#define gc getchar_unlocked
#endif
using namespace std;
int readi () {
	int n=0,sign=0;
	char c=gc();
	while (c<48) {
		if (c==45) sign=1;
		c=gc();
	}
	while (c>47) {
		n=n*10+c-'0';
		c=gc();
	}
	if (sign) return (-n);
	return n;
}
int a[100005];
int main() {
	// your code goes here
	int t,n;
	t = readi();
	long long sum,rmx,min,mincount,maxcount;
	while (t--) {
		n = readi();
		
		rmx = LONG_LONG_MIN; min = 0; mincount = 1;
		for (int i=0;i<n;i++) a[i] = readi();
		int i;

		for(i=sum=0;i<n;i++) {
			sum += a[i];
			if( sum - min > rmx) rmx = sum-min ,  maxcount = mincount;
			else if( sum - min == rmx ) maxcount += mincount;
		 
			if( sum < min ) min = sum ,  mincount = 1;
			else if( sum == min ) mincount++;
		}
		//cout<<rmx<<" "<<maxcount<<"\n";
		printf("%lld %lld\n",rmx,maxcount);
	}
	return 0;
}