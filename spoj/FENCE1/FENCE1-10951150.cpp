#include <stdio.h>
#define pi 3.14159292
int main()
{
    unsigned long int  l;
    
    while (1) {
        scanf("%d", &l);
        if (l == 0) {
            return 0;
        }
        printf("%.2f\n", ((l*l)/(2*pi)));
    }
    
    return 0;
}

