#include <stdio.h>
int rev (int a) {
    int rem = 0;
    int sum = 0;
    while (a > 0) {
        rem = a % 10;
        sum = sum * 10 + rem;
        a /= 10;
    }
    return sum;
}

int main()
{
    int t,a,b,rev1,rev2,sum,rem,sumr = 0;
    scanf("%d", &t);
    while (t--) {
        sum = 0;
        sumr = 0;
        scanf("%d %d", &a, &b);
       rev1 = rev(a);
        rev2 = rev(b);
        
        sum = rev1 + rev2;
        sumr = rev(sum);
        printf("%d\n", sumr);
    }
    
	return 0;
}
