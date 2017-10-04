#include <bits/stdc++.h>
using namespace std;
#define si(x) scanf("%d",&x)
string s;
struct treenode {
    int tot, open, close;
    treenode () {
        tot = 0;
        open = 0;
        close =0;
    }
    treenode (int a, int b, int c) {
        tot = a;
        open = b;
        close = c;
    }
    
};
typedef treenode node;
node nodee[4*30000];
void build (int cur, int l, int r) {
    if (l > r) return ;
    if (l == r) {
        if (s[l] == '(') nodee[cur].open++;
        else nodee[cur].close++;
        return ;
    }
    int mid = (l+r)/2;
    build (2*cur, l, mid);
    build (2*cur+1, mid+1, r);
    int temp = min(nodee[2*cur].open, nodee[2*cur+1].close);
    nodee[cur].tot = nodee[2*cur].tot + nodee[2*cur+1].tot + temp;
    nodee[cur].open = nodee[2*cur].open + nodee[2*cur+1].open - temp;
    nodee[cur].close = nodee[2*cur].close + nodee[2*cur+1].close - temp;
    return;
}
void update (int cur, int ul, int ur, int l, int r) {
	if (l > ur || r < ul) return;
	if (l == r) {
		if (s[l] == '(') {
			s[l] = ')';
			nodee[cur].close++;
			nodee[cur].open--;
		}
		else {
			s[l] = '(';
			nodee[cur].close--;
			nodee[cur].open++;
		}
			return;
	}
	int mid = (l+r)/2;
    update (2*cur, ul, ur, l, mid);
    update (2*cur+1, ul, ur, mid+1, r);
    int temp = min(nodee[2*cur].open, nodee[2*cur+1].close);
    nodee[cur].tot = nodee[2*cur].tot + nodee[2*cur+1].tot + temp;
    nodee[cur].open = nodee[2*cur].open + nodee[2*cur+1].open - temp;
    nodee[cur].close = nodee[2*cur].close + nodee[2*cur+1].close - temp;
    //cout<<nodee[cur].tot<<" "<<l<<" "<<r<<"\n";
    return ;
}
node query (int cur, int ql, int qr, int l, int r) {
    if (l > qr || r < ql) return node(0,0,0);
    else if (ql <= l  && qr >= r ) {
        return nodee[cur];
    }
    int mid = (l+r)/2;
    node left = query (2*cur, ql, qr, l, mid);
    node right = query (2*cur+1, ql, qr, mid+1, r);
    int temp = min(left.open, right.close);
    node ans;
    ans.tot = (left.tot + right.tot + temp);
    ans.open = left.open + right.open - temp;
    ans.close = left.close + right.close - temp;
    return ans;
}
int main() {
	int l;
	for (int i=1; i <= 10; i++) {
		memset(nodee, 0, sizeof nodee);
		cout<<"Test"<<" "<<i<<":\n";
		cin>>l;
	    cin>>s;
	    build (1, 0, s.length()-1);
	    int q,l,r;
	    si(q);
	    node ans;
	    while (q--) {
	        si(l);
	        if (l == 0) {
	        	r = s.length()-1;
	        	ans = query(1,l,r,0,s.length()-1);
	        	if (ans.tot*2 == r-l+1) cout<<"YES\n";
	        	else cout<<"NO\n";
	    	}
	    	else {
	    		l--;
	    		update (1, l, l, 0, s.length()-1);
	    	}
	        //cout<<ans.tot*2<<"\n";
	    }
	}
	return 0;
}