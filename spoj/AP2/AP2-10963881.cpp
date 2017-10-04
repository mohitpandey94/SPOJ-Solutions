#include <stdio.h>

int main()
{
    int t;
    long long int a,b,s,n,d,i,f;
    scanf("%d", &t);
    while (t--) {
            i = 0;
        scanf("%lld %lld %lld", &a,&b,&s);
        n = (s*2)/(a+b);
        printf("%lld\n", n);
        d = (b - a)/(n - 5);
        f = a - (2 * d);
        while (i < n) {
            printf("%lld ", (f + i * d));
            i++;
        }
        printf("\n");
    }
    return 0;
}
