#include <stdio.h>
int main()
{
    int t;
	unsigned long long int p= 0,n=0;
	scanf("%d", &t);
	while (t--) {
		scanf("%llu", &n);
		if (n%2==0) {
		p = (n*(n+2)*(2*n+1))/8;
		}
		else {
		    p =	((n*(n+2)*(2*n+1)) - 1)/8;
		}
		
		printf("%llu\n", p);
	}
	
	return 0;
}	




