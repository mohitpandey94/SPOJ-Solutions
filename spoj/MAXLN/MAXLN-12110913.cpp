#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
   int t;
   long long int r;
   double s;
   cin>>t;
   for (int i=1;i<=t;i++) {
       cin>>r;
       //cout<<"Case "<<i<<": "<<(double)(4*r*r + 0.25)<<endl;
       s = (double)(4*r*r)+0.25;
        printf("Case %d: %.2f\n",i,s);
   }
   return 0;
}
