#include <stdio.h>
int main()
{
    long long int t;
    long long int a, temp = 0, s = 0;
    scanf("%lld", &t);

    while (t) {
    	a = 0;
        scanf("%lld", &a);
        temp = 0;
        while (1) {
        temp = a;
        s = 0;
        while (temp > 0) {
            s += (temp % 10);
            temp /= 10;
        }
        if (a % s == 0) {
        printf("%lld\n", a);
        break;
        }
        else
        a++;
        }
        t--;
    }
    
    return 0;
}




