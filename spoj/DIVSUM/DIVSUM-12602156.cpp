#include<iostream>
#include<math.h>
using namespace std;
int main(){
long long int n,m;
cin >> n;
while(n--){
    cin >> m;
    long long int sum =0;
    if (m==1) {
    	cout<<sum<<endl;
    	continue;
    }
    for(int i = 2;i <= sqrt(m);i++){
        if (m%i==0) {
        	if (i==m/i) sum += i;
        	else sum += i+m/i;
        }
    }
    sum++;
    cout << sum<<endl;
}
}