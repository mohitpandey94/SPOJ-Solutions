#include <stdio.h>
int main()
{
   int t;
   long long int n,k,r,res,i;
   scanf("%d",&t);
   while (t--) {
       scanf("%lld %lld",&n,&k);
       n-=1;
       k-=1;
       res=1;
       r = n-k;
       if (r>n/2) r= n-r;
       for (i=0;i<r;i++) {
           res *= (n-i);
           res /= (i+1);
       }
       printf ("%lld\n",res);
   }
   
   return 0;
}