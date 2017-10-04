#include <stdio.h>
int main()
{
    int t;
   long long int n,sum =0;
    scanf("%d", &t);
    while (t--) {
        sum =0 ;
        scanf("%lld", &n);
        sum = n *2 + (3*n*(n-1)/2);
        sum = (sum%1000007);
        printf("%lld\n", sum);
    }
    
    return 0;
}



