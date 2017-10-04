#include <bits/stdc++.h>

using namespace std;
bool compare (int i, int j) {
	return (i > j) ? 1 : 0;
}
int main() {
	int s,i,j,count=0;
	long long a[100005],b[100005];
	scanf("%d",&s);
	for (int i=0;i<s;i++) scanf("%lld",&a[i]);
	sort(a,a+s);
	for (int i=0;i<s;i++) scanf("%lld",&b[i]);
	sort(b,b+s);
	//for (j=0;j<s;j++) cout<<b[j]<<" ";
	//cout<<"\n";
	for (i=0,j=0; i < s && j < s;) {
		if (a[i] < b[j]) {
			i++;
			j++;
			count++;
		}
		else if (a[i] >= b[j]) {
			j++;
		}
	}
	printf("%d\n",count);
	return 0;
}