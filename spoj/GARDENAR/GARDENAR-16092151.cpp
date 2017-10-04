#include <bits/stdc++.h>
using namespace std;
#define root 1.7320508075688772935274463415059
int main() {
    int t;
    double d,e,f;
    cin>>t;
    while (t--) {
	cin>>d>>e>>f;
	double s = (d+e+f)/2.0;
	s = 0.5* (((d*d+e*e+f*f)*root)/4.0) + 0.5*3*sqrt(s*(s-d)*(s-e)*(s-f));
	printf("%.2lf\n",s);
    }
    return 0;
}
