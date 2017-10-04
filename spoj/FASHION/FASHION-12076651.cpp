#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
   int t,n,m[1000],f[1000],sum=0;
   scanf("%d",&t);
   while (t--) {
       scanf("%d",&n);
       sum=0;
       for (int i=0;i<n;i++) scanf("%d",&m[i]);
       for (int i=0;i<n;i++) scanf("%d",&f[i]);
       sort(&m[0],&m[n]);
       sort(&f[0],&f[n]);
       for (int i=0;i<n;i++) {
           sum += (m[i]*f[i]);
       }
       printf("%d\n",sum);
   }
   
   return 0;
}
