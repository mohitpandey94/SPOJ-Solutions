#include <iostream>
#include <math.h>
#include <cstdio>
using namespace std;
main() {
    int t;
    double a,b,c,d,s,area;
    cin>>t;
    while (t--) {
        cin>>a>>b>>c>>d;
        s=(a+b+c+d)/2;
        area = sqrt ((s-a)*(s-b)*(s-c)*(s-d));
        printf("%.2f\n",area);
    }
    return 0;
}