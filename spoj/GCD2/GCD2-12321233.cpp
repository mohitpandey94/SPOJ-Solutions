#include <iostream>
#include <cstring>
using namespace std;
int gcd (int a,int b) {
//	cout<<a<<" "<<b<<endl;
	if (b==0) {
	//cout<<a<<endl;
	return a;
	}
	else return gcd(b,a%b);
}
main() {
	int a,num,t,i;
	string s;
	cin>>t;
	while (t--) {
		cin>>a>>s;
		if (a==0) cout<<s<<endl;
		else if (s[0]=='0') cout<<a<<endl;
		else {
			i=num=0;
			while (s[i]) {
				num = num*10+(s[i]-'0');
				num %= a;
				i++;
				//cout<<num<<" ";
			}
			//cout<<num<<" "<<a<<endl;
			cout<<gcd (a,num)<<endl;
		}
	}
}