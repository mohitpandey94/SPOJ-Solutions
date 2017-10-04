#include <iostream>
#include <math.h>
using namespace std;

int main()
{
   int n,c1=0,c3=0,c4=0,x,cf=0;
   char in;
   cin>>n;
   for (int i=0;i<n;i++) {
       cin>>in;
       if (in=='3') {
           c3++;
           cin>>in;
           cin>>in;
       }
       else if (in=='1') {
           cin>>in;
           cin>>in;
           if (in == '2') c1++;
           else c4++;
       }
   }
   //cout<<c1<<" "<<c3<<" "<<c4<<endl;
   if (c3<=c4) {
       cf+=c3;
       c4-=c3;
      c3=0;
      
   }
   else if (c4<=c3) {
       c3-=c4;
       cf+=c4;
       cf+=c3;
       c4=c3=0;
   }
   //cout<<c1<<" ";
   c1*=2;
   c1+=c4;
   //cout<<c1<<" ";
   cf += ceil(double((double)c1/4));
   cout<<++cf<<endl;
   return 0;
}
