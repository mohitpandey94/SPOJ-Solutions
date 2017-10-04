#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
vector <long long int>v(32000,1);
vector <long long int>f;
vector <long long int>primes;
long long int len,k=0;
void seive () {
    long long int i,j;
    v[0]=v[1]=0;
    for (i=2;i<32000;i++) {
        if (v[i]) {
            primes.push_back(i);
            k++;
            for (j=i+i;j<32000;j += i) v[j]=0;
        }
    }
}
bool pch (long long int n) {
    //long long int x=sqrt(n);
    //cout<<x<<" ";
    for (int i=0;primes[i]*primes[i]<=n && i<k;i++) {
        if (!(n%primes[i])) {
          //cout<<"\nk"<<primes[i]<<"k\n";
          return 0;
        }
    }
    return 1;
}
int main () {
    seive();
    //cout<<k<<endl;
    int t;
    long long int m,n;
    scanf("%d",&t);
    while (t--) {
        scanf("%lld %lld",&m,&n);

        if (m==1) m=2;
        //cout<<n<<" "<<m<<endl;;
            for (long long int i=m;i<=n;i++) {
                if (pch(i)) printf("%lld\n",i);
            }
    }
    return 0;
}

