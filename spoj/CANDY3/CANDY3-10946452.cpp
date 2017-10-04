#include <stdio.h>
#include <string.h>

int main()
{
long long int t,n,tot,a,temp = 0;
  scanf("%lld", &t);
  while (t--) {
      tot = 0;
      getchar();
      scanf("%lld", &n);
      temp = n;
      while (n--) {
          scanf("%lld", &a);
          tot = (tot+a)%temp;
      }
      if (tot == 0) {
          printf("YES\n");
      }
      else {
          printf("NO\n");
      }
  }

  return 0;
}