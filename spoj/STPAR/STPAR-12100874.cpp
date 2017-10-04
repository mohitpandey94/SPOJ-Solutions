#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
stack <int> s;
main() {
    int n,a[1000],b[1000],i,j,flag=1;
    cin>>n;
    while (n!=0) {
        j=0;
        for (i=0;i<n;i++) {
            cin>>a[i];
        }
        for (i=0;i<n;i++) {
            if (a[i]>a[i+1] || (!s.empty() && a[i]>s.top())) {
                while (!s.empty() && a[i]>s.top()) {
                    b[j++]=s.top();
                    s.pop();
                }
                s.push(a[i]);
               // cout<<"s"<<s.top()<<" ";
            }
            else {
                b[j++]=a[i];
                //cout<<"b"<<b[j-1]<<" ";
            }
        }
        while (!s.empty()) {
            b[j++]=s.top();
            //cout<<s.top()<<" ";
            s.pop();
        }
        //for (i=0;i<j;i++) cout<<b[i]<<" ";
        for (i=0;i<j-1;i++) {
            //cout<<i<<" ";
            if (b[i]>b[i+1]) {
                flag=0;
                //cout<<"h";
                //cout<<a[i]<<" "<<a[i+1];
                cout<<"no\n";
                break;
            }
        }
        //cout<<"h";
        if (flag) cout<<"yes\n";
        cin>>n;
        flag=1;
    }
}
