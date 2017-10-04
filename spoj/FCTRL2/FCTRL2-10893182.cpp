#include <stdio.h>
int main()
{
	int t,i = 0,temp,x,num,j = 0,l,index = 0;
	int a[200];
	scanf("%d", &t);
	while (t) {
		scanf("%d", &x);
		num = x;
		while (x > 0) {
			a[++i] = x % 10;
			x /= 10;
		}
		temp = 0;
		x=0;
		for(l = 1; l < num; ++l) {
			for (index = 1;index <=i; ++index) {
                x = l * a[index] + temp;
                a[index] = x % 10;
                temp = x / 10;
			}
            while (temp > 0) {
                a[++i] = temp % 10;
                temp = temp/10;
            }
		}
		while (i>0) {
            printf("%d", a[i]);
            a[i]=0;
            i--;

		}
		t--;
		printf("\n");
	}

	return 0;
}
