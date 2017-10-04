#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int timer[1001][1500];
long long maxv (int h, int a) {
	if (h <= 0 || a <= 0) return -1;
	if (timer[h][a] == -1)
		 timer[h][a] = max (maxv(h-2,a-8)+2,maxv(h-17,a+7)+2);
	return timer[h][a];
}
int main() {
	
	int t,h,a;
	scanf("%d",&t);
	while (t--) {
		scanf("%d %d",&h,&a);
		memset(timer,-1,sizeof(timer));
		//cout<<maxv(h,a)<<endl;;
		printf("%lld\n",maxv(h,a));
	}
		//printf("%lld\n",maxv(n));
	return 0;
}