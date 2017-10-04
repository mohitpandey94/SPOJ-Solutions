#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    int t,x,y,fri[1000],count=0;
    scanf("%d",&t);
    for (int j=1;j<=t;j++) {
        scanf("%d %d",&x,&y);
        for (int i=0;i<y;i++) scanf("%d",&fri[i]);
        sort (&fri[0],&fri[y]);
        count=0;
        for (int i =y-1;i>=0 && x>0;i--) {
            {
                x-=fri[i];
                //cout<<x<<" ";
                count++;
            }
        }
        if (x>0) {
            cout<<"Scenario #"<<j<<":\nimpossible\n";
            continue;
        }
        cout<<"Scenario #"<<j<<":\n"<<count<<endl;
    }
   return 0;
}
