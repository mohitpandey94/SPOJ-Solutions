#include <iostream>
#include <map>
using namespace std;
long long int a[500001];
map<int,int>occ;
void pre() {
    a[0]=0;
    occ[a[0]]=1;
    for (long long int i=1;i<=500000;i++) {
        if (!occ[a[i-1]-i] && (a[i-1]-i)>0)
        a[i] = a[i-1]-i;
        //if (occ[a[i]] && (a[i])<0)
         else
         a[i]=a[i-1]+i;
        occ[a[i]]=1;
    }
}
int main()
{
    pre();
  long long int k;
  cin>>k;
  while (k!=-1) {
      cout<<a[k]<<endl;
      cin>>k;
  }
   return 0;
}
