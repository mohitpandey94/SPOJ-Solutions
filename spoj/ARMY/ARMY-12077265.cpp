#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    int t,n,m,*arn,*arm,flag=0,i;
    scanf("%d",&t);
    char c;
    while (t--) {
        scanf("%c",&c);
        scanf("%d %d",&n,&m);
        arn = new int[n];
        arm=new int [m];
        for (i=0;i<n;i++) scanf ("%d",&arn[i]);
        for (i=0;i<m;i++) {
            scanf ("%d",&arm[i]);
        }
        sort (&arn[0],&arn[n]);
        sort (&arm[0],&arm[m]);
        if (arn[n-1]>=arm[m-1])
         cout<<"Godzilla\n";
        else cout<<"MechaGodzilla\n";
        flag=0;
    }
   return 0;
}
