#include <bits/stdc++.h>
#include <cstring>
#ifndef ONLINE_JUDGE
#define gc getchar
#else
#define gc getchar_unlocked
#endif
#define ll long long
#define nl() printf ("\n")
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define pi(x) printf ("%d",x)
#define pl(x) printf ("%lld",x)
#define pc(x) printf ("%c",x)
#define ps(x) printf ("%s",x)
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define repu(i,a,n,step) for (int i = a; i < n; i += step)
#define repd(i,a,n,step) for (int i = a - 1; i >= n; i -= step)
using namespace std;
int readi () {
	int n=0,sign=0;
	char c=gc();
	while (c<48) {
		if (c==45) sign=1;
		c=gc();
	}
	while (c>47) {
		n=n*10+c-'0';
		c=gc();
	}
	if (sign) return (-n);
	return n;
}
ll readl () {
	ll n=0;int sign=0;
	char c=gc();
	while (c<48) {
		if (c==45) sign=1;
		c=gc();
	}
	while (c>47) {
		n=n*10+c-'0';
		c=gc();
	}
	if (sign) return (-n);
	return n;
}
int splits[100][100];
void print_order (int splits[100][100], int i, int j) {
	if (i > j) return ;
	if (i == j) {
		cout<<"M"<<i;
		return ;
	}
	else {
		cout<<"(";
		print_order(splits,i,splits[i][j]);
		print_order(splits,splits[i][j]+1,j);
		cout<<")";
		return ;
	}
}
int value (int dims[], int i, int k) {
	int sum = 0;
	repu(j,i,k+1,1) {
		sum = (sum + dims[j])%100;
	}
	return sum;
}
int optimalValueOfScalarMultiplications (int dims[], int n) {
	int mults[n+5][n+5],q;
	repu(i,0,n+1,1) mults[i][i] = 0; //only 1 matrix is there
	
	repu(l,2,n+2,1) { //chain length
		repu(i,0,n-l+2,1) { 
			int j = i + l -1;
			mults[i][j] = INT_MAX; //cost of multiplying Ai to Aj
			repu(k,i,j,1) { //check all the possible splits
			//cout<<value(dims,i,k)<<" "<<value(dims,k+1,j)<<": :";
				q = mults[i][k] + mults[k+1][j] + value(dims,i,k)*value(dims,k+1,j);
				if (q < mults[i][j]) {
					mults[i][j] = q;
					//splits[i][j] = k;
				}
			}
		}
	}
	return mults[0][n];
	//print_order(splits,1,n-1);
}
int main() {
	int n; // no of entries, no of matrices = n-1
	while (cin>>n) {
		//cout<<n<<":";
		int dims[n+5]; //dimensions, ith matrix has dimesions dims[i-1]xdims[i]
		repu(i,0,n,1) {
			cin>>dims[i];
		}
		cout<<optimalValueOfScalarMultiplications(dims,n-1)<<"\n";
	}
	/*
	cout<<"Optimal Order: ";
	print_order(splits,1,n-1);
	*/
	return 0;
}
