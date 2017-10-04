#include <bits/stdc++.h>
using namespace std;
const double g = 9.806;
const double pi = 2*acos(0.0);
int main() {
    int t;
    double v,r,angle;
    cin>>t;
    bool flag = true;
    for (int tc=1; tc<=t; tc++) {
	cin>>r>>v;
	flag = false;
	angle = ((r*g)/(v*v));
	//cout<<angle<<" ";
	if (angle > 1) flag = true;
	angle = asin(angle)/2.0;
	//cout<<angle<<" ";
	angle = (angle*180.0)/pi;
	//cout<<angle<<" ";
	if(flag) 
	    printf("Scenario #%d: %d\n",tc,-1);
	else
	    printf("Scenario #%d: %.2lf\n",tc,angle);
    }
}
