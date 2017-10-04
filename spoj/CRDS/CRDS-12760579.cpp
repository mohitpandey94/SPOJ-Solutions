#include<iostream>
using namespace std;
main(){
int n;
long long int x;
cin>>n;
cout << endl;
while(n--){
    cin >> x;
    cout << ((3 * ((x * (x + 1))/2) -x )%1000007) << endl;
}
}