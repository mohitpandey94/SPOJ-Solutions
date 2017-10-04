#include <stdio.h>
int main()
{
    int t = 0, a[10000], count = 0, i = 0, sum = 0,temp = 0, j = 0, nop = 0;

    while (1) {
        count  = 0;
        sum = 0;
        scanf("%d", &t);
        if (t == -1) {
            break;
        }

        else {
            temp = t;
            i = 0;
            while (t--) {
                scanf("%d", &a[i]);
                sum += a[i];
                i++;
            }
        }
        j = (sum / temp);
        if (sum % temp != 0) {
            printf("-1\n");
            continue;
        }
        else {
                for (i = 0; i < temp; i++) {
                         if (j > a[i]) {
                            count += j - a[i];
                        }
                }
        }
        printf("%d\n", count);

    }

    return 0;
}
