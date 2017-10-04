#include <stdio.h>
int main()
{
    int t = 0;
    scanf("%d", &t);
    int x = 0, y = 0;
    while (t) {
        scanf("%d %d", &x, &y);
        if ((x % 2 == 0) && ((y == x - 2) || (y == x))) {
            printf("%d\n", (x + y));
        }
        else if (x % 2 != 0 && ((y == x - 2) || (y == x)))
            printf("%d\n", (x + y - 1));
        else
            printf("No Number\n");
        t--;
    }

    return 0;
}

