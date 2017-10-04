#include <stdio.h>
int main()
{
    int a,b,c,d,i;
    while (1) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 0 && b == 0 && c == 0) {
            break;
        }
        if ((b - a) == (c - b)) {
            d = (b - a);
            printf("AP %d\n", (c + d));
        }
        else if ((b / a) == (c / b)) {
            d = (b / a);
            printf("GP %d\n", (c * d));
        }

    }

    return 0;
}

