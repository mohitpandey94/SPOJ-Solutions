#include <stdio.h>
int main()
{
    int i;
    for (; scanf("%d", &i) && (i != 42); printf("%d\n", i) );
    
    return 0;
}


