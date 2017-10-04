#include <iostream>

using namespace std;

int main()
{
   int p;
   long long n,k,f,t;
   cin>>p;
   while (p--) {
       cin>>n>>k>>t>>f;
       cout<<(f+((f-n)/(k-1)))<<endl;;
   }
   return 0;
}
