#include <iostream>
#include <vector>
using namespace std;

int main()
{
   long long int val;
   cin>>val;
   if (val!=0) {
        string s;
   while (val!=0) {
       int rem = val%-2;
       val /= -2;
       if (rem<0) {
           rem+=2;
           val+=1;
       }
       char c = (char)(rem+'0');
       //.insert(0,c);
       s.push_back(c);
   }
   std::string::reverse_iterator r;
   for (r=s.rbegin();r!=s.rend();++r)
    cout<<*r;
   }
   else cout<<'0'<<endl;
  // cout<<endl;
   return 0;
}
