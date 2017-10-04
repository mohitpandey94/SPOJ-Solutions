#include<iostream>
using namespace std;
#include<vector>
 
/* This function calculates (a^b)%MOD */
long long pow(long long a, long long b, long long MOD)
{
    long long x=1,y=a; 
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD; 
        b /= 2;
    }
    return x;
}
 
/*  Modular Multiplicative Inverse
    Using Euler's Theorem
    a^(phi(m)) = 1 (mod m)
    a^(-1) = a^(m-2) (mod m)
	when m is prime.
*/
long long InverseEuler(long long n, long long MOD)
{
    return pow(n,9988439LL,MOD);
}
 
long long C(long long n, long long r, long long MOD)
{
    vector<long long> f(n + 1,1);
    for (int i=2; i<=n;i++)
        f[i]= (f[i-1]*i) % MOD;
    return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD;
}
 
int main() {
	// your code goes here
	long long n,r,ans;
	cin>>n>>r;
	if (n-1 < r-1) ans=-1;
	else {
		ans=C(n-1,r-1,10000007LL);
		//if (ans < 0) ans += MOD;
		//if (ans >= MOD) ans %= MOD;
	}
	cout<<ans<<"\n";
	return 0;
}