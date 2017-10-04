#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <limits.h>
#include <algorithm>
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
#define repu(i,a,n,step) for (i = a; i < n; i += step)
#define repd(i,a,n,step) for (i = a - 1; i >= n; i += step)

using namespace std;
int readi () {
	int n=0;
	char c=gc();
	while (c<48) c=gc();
	while (c>47) {
		n=n*10+c-'0';
		c=gc();
	}
	return n;
}
ll readl () {
	ll n=0;
	char c=gc();
	while (c<48) c=gc();
	while (c>47) {
		n=n*10+c-'0';
		c=gc();
	}
	return n;
}
double power(double x, int y)
{
    double temp;
    if( y == 0)
       return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return temp*temp;
    else
    {
        if(y > 0)
            return x*temp*temp;
        else
            return (temp*temp)/x;
    }
}

int main() {
        int t,n,m,i,j,k,tot=0,dist=0;
        char x;
        t=readi();
        while (t--) {

                n=readi();m=readi();
                int indices[33124][2];
		int grid[183][183];
                tot=0;
                repu(i,0,n,1) {
                        repu(j,0,m,1) {
                                cin>>x;
                                if (x=='0')
                                	grid[i][j] = INT_MAX;
                                else {
                                        grid[i][j]=0;
                                        indices[tot][0]=i;
                                        indices[tot][1]=j;
                                        tot++;
                                }
                        }
                }
                k=0;
                while (k<tot) {
                        repu(i,0,n,1) {
                                repu(j,0,m,1) {
                                        dist = (indices[k][0] - i)>0 ?(indices[k][0] - i) : (indices[k][0] - i)*(-1);
                                        dist += ((indices[k][1] - j)>0 ?(indices[k][1] - j) : (indices[k][1] - j)*(-1));
                                        if (dist < grid[i][j])
                                                grid[i][j] = dist;
                                        
                                }
                        }
                        k++;
                }
                repu(i,0,n,1) {
                        repu(j,0,m,1) {
                                pi(grid[i][j]); ps(" ");
                        }
                        nl();
                }


        }
return 0;
}



