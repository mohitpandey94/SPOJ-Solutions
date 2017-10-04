#include <bits/stdc++.h>
using namespace std;
int main() {
  int t,k,x;
  t=1;
  while (t--) {
    cin>>x>>k;
    vector<int> v;
    vector<bool> ans;
    v.resize(k);
    ans.resize(x+1);
    for (int i=0; i < k; i++) {
      cin>>v[i];
    }
    for (int i=1; i < k; i++) 
      v[i] += v[i-1];
    ans[0] = true;
    for (int i=0; i < k; i++) {
      for (int j = v[i]; j <= x; j++) {
        ans[j] = ans[j] | ans[j-v[i]];
      }
    }
    if (ans[x] == true) 
      cout<<"YES\n";
    else
      cout<<"NO\n";
  }
  return 0;
}
