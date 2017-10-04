#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <iterator>
using namespace std;
 
int main() {
	ios::sync_with_stdio(0);
	string x;
	int t,flag;
	cin>>t;
	while (t--) {
	    cin>>x;
	    int i,j;
	    flag=1;
	    int len = x.length();
	    for (i=0,j=len-1;i<len/2;i++,j--) {
	    	if (x[i]!=x[j]) {
	    		flag = 0;
	    		break;
	    	}
	    }
 		if (!flag) cout<<"NO\n";
 		else cout<<"YES\n";
	    //cout<<s.size()<<endl;
	    //s.clear();
	}
	
	return 0;
}
 