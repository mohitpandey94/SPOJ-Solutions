#include <iostream>
#include <math.h>
using namespace std;

int main()
{
   long long int t,x,res;
   char c=' ';
   cin>>t;
   while (t--) {
       c=' ';
       cin>>x;
       res=x;
       while (1) {
           cin>>c;
           if (c=='=') break;
           //res=x;
           //cin>>c;
           //cout<<"c"<<c<<"f ";
           cin>>x;
          //cout<<"x"<<x<<"op"<<c<<"res"<<res<<endl;;
           if (c=='+') res += x;
           else if (c=='-') res-=x;
           else if (c=='*') res*=x;
           else if (c=='/') res/=x;
            //cout<<"x"<<x<<"op"<<c<<"res"<<res<<endl;;
           //cin>>c;
           //cin>>c;
           
       }
       cout<<res<<endl;
   }
   return 0;
}
