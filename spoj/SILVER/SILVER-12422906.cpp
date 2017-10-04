#include <iostream>
#include <cmath>
using namespace std;

int main()
{
   int n,count=1,i=0;
   cin>>n;
   while (n) {
       for (i=1;pow(2,i)<=n;i++) {
       }
       cout<<(i-1)<<endl;
       cin>>n;
   }
   return 0;
}
