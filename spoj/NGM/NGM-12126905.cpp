#include <iostream>

using namespace std;

int main()
{
   long long int n;
   cin>>n;
   if (!(n%10)) cout<<"2\n";
   else {
       cout<<"1\n";
       cout<<(n%10)<<"\n";
   }
   
   return 0;
}
