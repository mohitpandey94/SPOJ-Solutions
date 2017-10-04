#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;
main() {
    int ld[10][4]={{0,0,0,0},{1,1,1,1},{2,4,8,6},{3,9,7,1},{4,6,4,6},{5,5,5,5},{6,6,6,6},{7,9,3,1},{8,4,2,6},{9,1,9,1}},t;
    char n[1005];
    unsigned long long int pw;
    cin>>t;
    while (t--) {
        cin>>n>>pw;
        if (pw==0) {
            cout<<"1\n";
            continue;
        }
        long long int num=(n[strlen(n)-1]-'0');
        pw=pw%4;
        pw=(pw==0)?3:(pw-1);
        cout<<ld[num][pw]<<endl;
    }
}