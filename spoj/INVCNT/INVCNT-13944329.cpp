#include<cstdio>
#include<climits>
#include <iostream>
#define ll long long
using namespace std;

ll merge_sort(ll a[], int n, int p, int mid, int q){
	int l = mid-p+2;
	int r = q-mid+2;
	ll l_temp[l];
	ll r_temp[r];
	int x = 0;
	for(int i = p; i <= mid; i++){
		l_temp[x++] = a[i];
	}
	l_temp[x] = LONG_LONG_MAX;
	x = 0;
	for(int i = mid+1; i <= q; i++){
		r_temp[x++] = a[i];
	}
	r_temp[x] = LONG_LONG_MAX;
	int i = 0;
	int j = 0;
	ll c = 0;
	while(p <= q){
		if(l_temp[i] < r_temp[j]){
			a[p++] = l_temp[i++];
		}else{
			a[p++] = r_temp[j++];
			c +=(l - 1 - i);
		}
	}
	return c;
}

ll merge(ll a[], int n, int p, int q){
	if(p < q){
		int mid = (p+q)/2;
		ll left = merge(a, n, p, mid);
		ll right = merge(a, n, mid+1, q);
		return left+right+merge_sort(a, n, p, mid , q);
	}else{
		return 0;
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ll a[n];
		for(int i = 0; i < n; i++){
			cin>>a[i];
		}
		cout<<(merge(a, n, 0, n-1))<<"\n";
	}
}
