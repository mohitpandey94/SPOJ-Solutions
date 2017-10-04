#include <iostream>
#include <vector>
#include <numeric>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
   int t,n,m,k;
   scanf("%d",&t);
   while (t--) {
   		
       scanf(" %d %d %d",&n,&m,&k );
      int cnt[100]={0};
      char s[m+1];
      for (int i=0;i<n;i++) {
          scanf("%s",&s);
          for (int j=0;j<m;j++) {
              if (s[j]=='*')
              cnt[i]++;
          }
      }
      while (k--) {
          sort(cnt,cnt+n);
          cnt[0]=m-cnt[0];
          //cout<<"i";
      }
     // cout<<"j";
      m=0;
      //for (int i=0;i<n;i++) m+=cnt[i];
      m=accumulate(cnt,cnt+n,0);
      
      cout<<(m)<<endl;
   }
   return 0;
}
