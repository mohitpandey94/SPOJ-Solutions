#include <iostream>
#include <math.h>
using namespace std;

int main()
{
   long long int n,a,i,sum;
   cin>>n;
   while (n--) {
       cin>>a;
       if (a%2) {
           cout<<a<<endl;
       }
       else {
           sum=0;
           while (a) {
               sum*=2;
               sum += a%2;
               a/=2;
           }
           cout<<sum<<endl;
       }
   }
   return 0;
}
