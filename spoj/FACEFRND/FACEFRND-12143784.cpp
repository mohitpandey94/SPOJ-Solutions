#include <iostream>
#include <algorithm>
using namespace std;
main() {
    int n,m,num[10000]={0},temp,count=0;;
	cin>>n;
	while (n--) {
		cin>>temp;
	    num[temp]=-1;
        if (num[temp]) num[temp]=-1;
		cin>>m;
		while (m--) {
			cin>>temp;
            if (!num[temp])
			   num[temp]=1;
		}
	}
	sort(&num[0],&num[10000]);
	for (int i=9999;i>=1000;i--) {
		if (num[i]==1) {
		count++;
		//cout<<i<<" "<<num[i]<<endl;
		}
	}
	cout<<count<<endl;
}