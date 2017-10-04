#include <bits/stdc++.h>
using namespace std;
int main() {
    double r,b;
    cin>>r>>b;
    double x,y;
    x = (r+4.0)+sqrt((r+4.0)*(r+4.0)-4*2.0*2.0*(b+r));
    x /= 4.0;
    y = (b+r)/x;
    cout<<max(x,y)<<" "<<min(x,y)<<"\n";
    return 0;
}
