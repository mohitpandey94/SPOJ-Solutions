#include <iostream>
#include <stdio.h>
#define gc getchar_unlocked
using namespace std;
int read() {
    int n=0;
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
   int n,m,a[300000+5],sum=0,max=0,pl=0,pr=0;
   n=read();
   m=read();
   for (int i=0;i<n;i++) a[i]=read();
   //sum += a[pr];
   while (pr<n) {
        
     if (sum==m) break;
        else sum += a[pr++];
        if (sum>m) {
            while (sum>m && pl<pr)
                sum -= a[pl++];
           // cout<<pl<<" ";
        }
        if (sum>max && sum<=m) max = sum;
       // cout<<pl<<"\t"<<pr<<"\n";
    }
    sum=0;
    while (pl<pr) {
        sum += a[pl++];
    }
    max = max>sum?max:sum;
    cout<<endl<<max<<endl;
   return 0;
}
