#include <bits/stdc++.h>
#define si(x) scanf("%lld",&x)
#define ll long long
using namespace std;
//int dp1[1<<17][18], dp2[1<<17][18];
vector <ll> suml, sumr;
ll a[20];
ll b[20];
ll n, l, r;
void print(vector<ll> v) {
  for (int i =0; i < v.size(); i++) cout<<v[i]<<" ";
  cout<<"\n";
}
int main() {
  si(n);
  si(l), si(r);
  
  for (int i=0; i < n/2; i++) si(a[i]);
  for (int i=0; i < (n-n/2); i++) si(b[i]);

  ll upto1 = n/2;
  ll upto2 = n-n/2;
  ll val = 0;
  ll k = 0, sz1, sz2;
  sz1 = sz2 = 0;
  bool flag = false;
  for (int i=0; i < 1<<upto1; i++) {
    flag = false;
    val = 0;
    for (int j = 0; j < upto1; j++) {
      if (i & (1<<j)) {
        val += a[j];
        flag = true;
      }
    }
    if (flag)
      suml.push_back(val); 
  }
  k = 0;
  for (int i=0; i < 1<<upto2; i++) {
    flag = false;
    val = 0;
    for (int j = 0; j < upto2; j++) {
      if (i & (1<<j)) {
        val += b[j];
        flag = true;
      }
  //    cout<<i<<" "<<val<<" "<<flag<<"\n";
    }
    if (flag)
      sumr.push_back(val); 
  }
  sz1 = suml.size();
  sz2 = sumr.size();
  sort(suml.begin(), suml.end());
  sort(sumr.begin(), sumr.end());
  /*
  cout<<"suml:";
  print(suml);
  cout<<"sumr:";
  print(sumr); 
  */
  ll temp,id1, id2, ans = (l <= 0LL && r >= 0LL ? 1LL : 0LL);
  
  for (int i=0; i < sz1; i++) 
    if (suml[i] >= l && suml[i] <= r)
      ans++;

  for (int i=0; i < sz2; i++) 
    if (sumr[i] >= l && sumr[i] <= r)
      ans++;
 
  for (int i = 0; i < sz1; i++) {
    temp = suml[i];
    //cout<<temp<<"\n";    
    id1 = lower_bound(sumr.begin(), sumr.end(), l-temp) - sumr.begin();
    id2 = upper_bound(sumr.begin(), sumr.end(), r-temp) - sumr.begin();
  
    //cout<<id1<< " "<<id2<< " "<<ans<<"\n";
    ans = ans + (id2-id1);
  }
printf("%lld\n", ans);
  return 0;
}
