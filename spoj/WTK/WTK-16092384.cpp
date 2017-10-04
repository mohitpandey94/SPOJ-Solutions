#include <iostream>
using namespace std;
int jos(int n, int k) {
    //if(n < 0) n = n+k;
    if (n==1)
	return 1;
    return (jos(n-1,k+1)+k-1)%n+1;
}
int main() {
    // your code goes here
    int t,n;
    cin>>t;
    while (t--) {
	cin>>n;
	cout<<jos(n,1)<<"\n";
    }
    return 0;
}
