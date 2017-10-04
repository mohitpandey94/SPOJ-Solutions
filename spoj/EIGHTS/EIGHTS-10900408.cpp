#include <stdio.h>
int main()
{
	unsigned long long int a = 0;
	int t = 0;
	unsigned long long int num = 0;
	scanf("%d", &t);
	while (t--) {
		num=0;
		scanf("%llu", &a);
		num = ((a-1)*250) + 192;
		printf("%llu\n", num);
	}
	
	return 0;
}


