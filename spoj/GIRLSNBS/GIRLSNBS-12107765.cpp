#include <iostream>
#include <math.h>
using namespace std;

int main()
{
   int g,b,min,max;
   cin>>g>>b;
   while (g!=-1 && b!=-1) {
      min=g<b?g:b;
      max=g>b?g:b;
      cout<<((ceil)((double)(max/(double)(min+1))))<<endl;
      cin>>g>>b;
   }
   return 0;
}
