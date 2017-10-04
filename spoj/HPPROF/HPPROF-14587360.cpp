#include <iostream>
#include <cstring>
using namespace std;
main() {
    char s[5010];
    cin>>s;
    int dp[5010],check;
    
    {
        dp[0]=dp[1]=1;
        for (int i=2;i<=strlen(s);i++) {
            dp[i]=0;
            int c1,c2;
            c1=s[i-1]-'0';
            c2=s[i-2]-'0';
            if (c2==2 && c1==0 || c2==1) {
                dp[i]+=dp[i-2];
            }
            dp[i]+=dp[i-1];
        }
        cout<<dp[strlen(s)]<<endl;
        //cin>>s;
    }
}