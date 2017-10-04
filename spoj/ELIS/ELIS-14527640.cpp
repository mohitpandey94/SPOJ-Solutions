#include <bits/stdc++.h>
using namespace std;
#define Sz 100005
int s[Sz],k;
void binarysearch (int val) {
    if (k == 0) {
        s[k++] = val;
    }
    else if (s[k-1] < val) {
        s[k++] = val;
    }
    else {
        int l = 0,h=k,mid;
        while (l<h) {
            mid = (l+h)/2;
            if (s[mid] > val) {
                while (s[--mid] >= val) ;
                s[mid+1] = val;
                break;
            }
            else l = mid+1;
        }
    }
    return;
}
int main() {
    int n,a[Sz];
    cin>>n;
    for (int i =0;i<n;i++) {
        cin>>a[i];
    }
    for (int i=0;i<n;i++) {
        binarysearch(a[i]);
    }
    cout<<k<<"\n";
}
