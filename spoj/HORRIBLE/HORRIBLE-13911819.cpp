#include <bits/stdc++.h>
#define ll long long
#define si(x) scanf("%lld",&x)
using namespace std;
ll bit1[100002],bit2[100002];
 
void update(ll bit[], ll idx, ll val){
    for(ll x = idx;x <= 100001;x += x & -x)
        bit[x] += val;
}
 
ll query(ll bit[], ll idx){
    long long ret = 0;
 
    for(ll x = idx;x > 0;x -= x & -x)
        ret += bit[x];
 
    return ret;
}
int main() {
	ll t,n,c,type,x,y,z;
	si(t);
	while (t--) {
		si(n);si(c);
		while (c--) {
		si(type);
		if (type == 0) {
			si(x);si(y);si(z);
			//cout<<x<<" "<<y<<" "<<z<<"\n";
			update(bit1,x,z);
			update(bit1,y+1,-z);
			update(bit2,x,z*(x-1));
			update(bit2,y+1,-z*y);
		}
		else {
			si(x);si(y);
			//cout<<x<<" "<<y<<"\n";
			printf("%lld\n",(query(bit1,y)*y-query(bit1,x-1)*(x-1))-(query(bit2,y)-query(bit2,(x-1))));
		}
		}
		fill(bit1,bit1+100002,0);
		fill(bit2,bit2+100002,0);
	}
	return 0;
}