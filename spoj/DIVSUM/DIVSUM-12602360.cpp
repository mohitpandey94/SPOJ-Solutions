#include<iostream>
#include<math.h>
using namespace std;
int main(){
int n,m;
cin >> n;
while(n--){
    cin >> m;
    int sum =0;
     if (m==1) {
    	cout<<sum<<endl;
    	continue;
 }
    for(int i = 1;i <= sqrt(m);i++){
        if((i == 1) || i == sqrt(m)){
            sum = sum + i;
        }
        else if(m % i == 0){
            sum = sum + i + m/i;
        }
    }
    cout << sum<<endl;
}
}