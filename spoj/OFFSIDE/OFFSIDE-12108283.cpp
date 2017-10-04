#include <iostream>
#include <math.h>
using namespace std;

int main()
{
   int a,d,temp,min,count;
   cin>>a>>d;
   while (a!=0 && d!=0) {
       count=0;
       min=99999;
       for (int i=0;i<a;i++) {
           cin>>temp;
           if (min>temp) min=temp;
           //sum1+=temp;
       }
       //cout<<min<<" ";
      // sum1/=a;
       for (int i=0;i<d;i++) {
           cin>>temp;
           if (temp<=min) count++;
           //sum2+=temp;
       }
       //sum2/=d;
       if (count>=2) {
           cout<<"N\n";
       }
       else cout<<"Y\n";
       cin>>a>>d;
   }
   return 0;
}
