#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll memo[1<<20+1];
int a[21][21],n;
ll rec (ll mask) {
  //cout<<ind<<" "<<mask<<"\n";
  if (__builtin_popcountll(mask) == n) {
    //cout<<mask<<"\n";
    return 1;
  }
  if (memo[mask]!=-1) return memo[mask];
  ll ans = 0;
  int ind = __builtin_popcountll(mask);
  //for (int j=ind; j < 3; j++)
  for (int i=0; i < n; i++) {
    if (a[ind][i] && !(mask&1<<i)) { 
      ans += rec (mask|1<<i);
     // mask ^= 1<<i;
    }
  }
  memo[mask] = ans;
  return ans;
}

int main() {
  int t;
  
  cin>>t;
  while (t--) {
    cin>>n;
    for (int i=0; i < n; i++)
      for (int j=0; j < n; j++)
        cin>>a[i][j];
    /*
    for (int i=0; i < n; i++)
      for (int j=0; j < n; j++)
        cout<<a[i][j]<<" ";
    cout<<"\n";
    */
    memset(memo, -1, sizeof (memo));
    cout<<rec (0LL)<<"\n";
  }
  
  /*
  for (int i=0; i < 3; i++)
    for (int j=0; j < 3; j++)
      a[i][j] = 1;
  cout<<rec (0,0LL);
  */
  return 0;
}