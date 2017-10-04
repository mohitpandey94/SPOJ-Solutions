#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    int i;
   float x,y=0;
   cin>>x;
   while (x!=0.00) {
      
      y=0;
   for (i=1;y<=x;i++) {
       y += (1/(float)(i+1));
   }
   cout<<(i-1)<<" card(s)"<<endl;
   cin>>x;
   }
   
   return 0;
}
