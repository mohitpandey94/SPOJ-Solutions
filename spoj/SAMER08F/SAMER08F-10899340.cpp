#include <stdio.h>
int main()
{
    int a,i = 0, sum = 0;

    while (1) {
        sum = 0;
        scanf("%d", &a);
        if (a == 0) {
            break;
        }
        i = a;
        while(i > 0) {
            sum += (i * i);
            i--;
        }
        printf("%d\n", sum);
    }

    return 0;
}
