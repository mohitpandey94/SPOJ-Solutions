#include <iostream>

using namespace std;
int n,d[2010][2010],a[2010];
int calc (int s,int e, int age) {
    if (s>e) return 0;
    if (d[s][e]!=0) return d[s][e];
    d[s][e] = max(age*a[s]+ calc(s+1,e,age+1), age*a[e]+ calc(s,e-1,age+1));
    return d[s][e];
}
int main()
{
    cin>>n;
    for (int i=0;i<n;i++) cin>>a[i];
    //int d[n][n];
    for (int i=0;i<n;i++) {
        d[i][i] = a[i]*n;
    }
    cout<<calc(0,n-1,1);
   return 0;
}
