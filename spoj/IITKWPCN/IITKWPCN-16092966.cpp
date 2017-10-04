#include <bits/stdc++.h>
using namespace std;
int main() {
    int t,w,b;
    cin>>t;
    while (t--) {
	cin>>w>>b;
	if(b&1) {
	    printf("%.6lf\n",1.0);
	}    
	else printf("%.6lf\n",0.0);

}
    return 0;
}
