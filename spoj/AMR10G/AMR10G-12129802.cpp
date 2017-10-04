#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define gc getchar_unlocked
long long int read() {
    long long int n=0;
    char c=gc();
    while (c<48) c=gc();
    while (c>47) {
        n = n*10+c-'0';
        c=gc();
    }
    return n;
}
int main()
{
   long long int h[20000],t,n,k,mini=999999999;
   t=read();
   while (t--) {
       n=read();
       k=read();
       for (int i=0;i<n;i++) h[i]=read();
       mini=999999999;
       //for (int i=0;i<n;i++) cout<<h[i]<<" ";
       //cout<<endl;
       sort(&h[0],&h[n]);
      // for (int i=0;i<n;i++) cout<<h[i]<<" ";
       //cout<<endl;
       //cout<<h[0]<<" "<<h[k-1]<<" "<<h[n-1]<<" ";
       for (int i=0;i<=n-k;i++) {
           if (h[i+k-1]-h[i]<mini) mini=h[i+k-1]-h[i];
       }
      // cout<<(min(h[k-1]-h[0],h[n-1]-h[n-k]))<<endl;
      cout<<mini<<endl;
   }
   return 0;
}
