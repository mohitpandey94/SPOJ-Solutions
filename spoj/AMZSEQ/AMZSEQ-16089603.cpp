#include <bits/stdc++.h>
using namespace std;
vector<int> s;
int n, memo[24][24];
int rec (int str, int pos) {
  if (pos == n) return 1;
  //cout<<str[0]<<" "<<str[1]<<" "<<str[2]<< ","<<pos<<"\n";
  if (memo[str][pos] != -1) return memo[str][pos];
  int ans = 0;
  for (int i=0; i < s.size(); i++) {
    if (pos == 0) {
      //str =s[i];
      ans += rec (s[i], pos+1);
    }
    else if (abs(str-s[i]) <= 1) {
        //str = s[i];
        ans += rec (s[i], pos+1);
    }
  }
  memo[str][pos] = ans;
  return ans;
}
int main() {
  int t,m;
  //int *str = NULL;
  //cin>>t;
  t=1;
  s.push_back(0);s.push_back(1);s.push_back(2);
  m=3;
  for (int tc=1; tc<=t; tc++) {
    cin>>n;
    
    memset (memo, -1, sizeof (memo));
    //str = new int[n];
    //for (int i=0; i < m; i++) cin>>s[i];
    int ans = rec (0, 0); 
    cout<<ans<<"\n";
    //delete str;
  }/*
  int str[3];
  str[0] = str[1] = str[2] = INT_MAX;
  cout<<rec(str,0);
  */
  return 0;
}