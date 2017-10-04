#include <iostream>
#include <limits.h>
using namespace std;

int main()
{
   int t,h,w,a[102][102],m[102][102],max,mmax;
   cin>>t;
   while (t--) {
       mmax=0;
       cin>>h>>w;
       for (int i=1;i<=h;i++) {
           for (int j=1;j<=w;j++) cin>>a[i][j];
       }
       for (int i=0;i<=h;i++) m[i][0]=0;
       for (int j=0;j<=w;j++) m[0][j]=0;
       for (int i=0;i<=h;i++) m[i][w+1]=0;
       for (int i=1;i<=h;i++) {
           for (int j=1;j<=w;j++) {
               max = 0;
               if (m[i-1][j-1]+a[i][j]>max)
                    max = m[i-1][j-1]+a[i][j];
                if (m[i-1][j]+a[i][j]>max) 
                    max = m[i-1][j]+a[i][j];
                if (m[i-1][j+1]+a[i][j]>max)
                    max= m[i-1][j+1]+a[i][j];
                m[i][j]=max;
                if (i==h && max>mmax) mmax=max;
           }
       }
       cout<<mmax<<endl;
   }
   return 0;
}
