#include <iostream>
#include <math.h>
using namespace std;

int main()
{
   int t,n,i;
   cin>>t;
   while (t--) {
       cin>>n;
       cin>>i;
       if (i==0) {
           cout<<"Airborne wins.\n";
       }
       else cout<<"Pagfloyd wins.\n";
   }
   return 0;
}
