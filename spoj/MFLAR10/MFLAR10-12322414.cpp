#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
   string s;
   char c;
   int flag=1;
   getline (cin,s);
   //cout<<s<<endl;
   c=s[0];
   //cout<<c<<" ";
   while (s[0] != '*') {
   		transform (s.begin(),s.end(),s.begin(),::tolower);
   		int k=1;
   		c=s[0];
   		while (c==' ') c=s[k++];
       flag=1;
       //cout<<s<<endl;
       for (int i=k;i<(s).length();i++) {
           if (s[i-1]==(char)(32)) {
           //cout<<i<<" ";
               if (s[i] != c) {
               		//cout<<"here"<<s[i+1]<<i<<" "<<(i+1)<<" "<<c<<endl;
                   cout<<"N\n";
                   flag=0;
                   break;
               }
           }
       }
       if (flag) cout<<"Y\n";
       getline(cin,s);
       if (s.length()==0) getline(cin,s);
   }
   return 0;
}
