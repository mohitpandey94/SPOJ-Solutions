#include <stdio.h>
int sum(long long int a){
int s = 0;
while(a > 0) {
    s += a % 10;
    a /= 10;
}
return s;
}

int main()
{
    long long int t;
    long long int a = 0, temp = 0, s = 0;
    scanf("%lld", &t);

    while (t) {
        scanf("%lld", &a);
        temp = 0;
        while (1) {
        temp = a;
        s = sum(temp);

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
