//Descartes theorem
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    double r1,r2,r3,k1,k2,k3,k4,r4;
    cin>>t;
    while (t--) {
	cin>>r1>>r2>>r3;
	k1 = 1.0/r1; k2=1.0/r2; k3 = 1.0/r3;
	k4 = k1+k2+k3+2.0*sqrt(k1*k2+k2*k3+k1*k3);
	
	printf("%.6lf\n",1.0/k4);

}
    return 0;
}
