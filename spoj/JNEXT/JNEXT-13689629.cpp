#include <bits/stdc++.h>

using namespace std;
int a[1000005];
bool compare (int i, int j) {
	if (i > j) return 1;
	else return 0;
}
int main() {
	int t,n,index;
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&n);
		for (int i=0; i < n; i++) {
			scanf("%d",&a[i]);
		}
		for (int i = n-1; i > 0; i--) {
			if (a[i] > a[i-1]) {
				index = i;
				break;
			}
		}
		
		if (index != -1) {
			int smallest= INT_MAX,smind=-1;
		//sort(a+index,a+n,compare);
			for (int i=index; i<n; i++) {
				if (a[index-1] < a[i] && a[i] < smallest) smallest = a[i],smind=i ;
			}
			swap(a[index-1],a[smind]);
			sort(a+index,a+n);
			for (int i=0; i<n; i++) {
				printf("%d",a[i]);
			}
		}
		else printf("-1");
		printf("\n");
		index=-1;
	}
	return 0;
}