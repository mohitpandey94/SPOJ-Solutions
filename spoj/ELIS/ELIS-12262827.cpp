#include <iostream>
using namespace std;
main() {
    int n,a[21],lis[21],max=0;
    cin>>n;
    for (int i=0;i<n;i++) {
        cin>>a[i];
        lis[i]=1;
    }
    if (n>1)
    for (int i=1;i<n;i++) {
        //cout<<"\n"<<a[i]<<" : ";
        for (int j=0;j<i;j++) {
            if (a[i]>a[j] && lis[i]<lis[j]+1) {
                lis[i]=lis[j]+1;
                //cout<<a[j]<<" ";
            }
        }
       // cout<<lis[i]<<" ";
        if (max<lis[i]) {
            max=lis[i];
          // cout<<max<<" "<<endl;;
        }
    }
    else max=1;
    cout<<max<<endl;
 return 0;
}