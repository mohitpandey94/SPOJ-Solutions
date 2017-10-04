#include <stdio.h>
#include <math.h>
int main()
{
    double t, a, b;
    double e = 0;
    scanf("%lf", &t);
    while (t--) {
        scanf("%lf %lf", &a,&b);
        e = sqrt(1-(b*b)/(a*a));
        e = 2*a*e;
        printf("%.3f\n", e);
    }
    return 0;
}
