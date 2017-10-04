#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define si(x) scanf("%lld",&x)
ll phi[1000005], ans[1000005];
void pre() {
  ll n = 1000000;
  for (ll i=1; i <= n; i++) phi[i] = i;
  for (ll i=2; i <= n; i++) {
    if (phi[i] == i) { //phi(prime) = prime-1;
      for (ll j = i; j<=n; j += i) {
        phi[j] /= i;
        phi[j] *= i-1;
      }
    }
  }
  for (ll i = 1; i<=n; i++) {
    for (ll j = i; j<=n; j+=i) {
      ans[j] += (i*phi[i]);
    }
  }
  return ;
}
int main() {
  pre();
  //ios::sync_with_stdio(0);
  ll t,n;
  si(t);
  while (t--) {
    si(n);
    //cout<<phi[n]<<" "<<ans[n]<<"\n";
    ll ans1 = ans[n]+1;
    ans1 = ans1*n;
    ans1 /= 2;
    printf("%lld\n", ans1);
  }
  return 0;
}
