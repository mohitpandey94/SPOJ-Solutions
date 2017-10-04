#include <stdio.h>
#include <math.h>
int main()
{
   long long int a,t,i,count = 0;
   scanf("%lld", &t);
   while(t) {
        count = 0;
    scanf("%lld", &a);
    for (i = 1; 5 * i <= a; i *= 5) {
        count += (a / (5 * i));
    }
    printf("%lld\n", count);
    t--;
    }

   return 0;
}
