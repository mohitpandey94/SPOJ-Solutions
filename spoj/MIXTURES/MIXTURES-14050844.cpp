#include<iostream>
#include<cfloat>
#include <cstdio>
using namespace std;
	int p[200];
long long int mod(int *p, int x, int y){
	long long int i, k =0;
	for(i = x; i <= y; i++){
		k = (k+p[i]) % 100;
	}
	return k;
}
long double smoke(int *p, int n){
	long long int i, g, k, j, l;
	long double d[n+5][n+5];
	for(i = 0; i <= n; i++){
		d[i][i] = 0;
	}
	for(l = 2; l <= n+1; l++){
		for(i = 0; i <= (n-l+1); i++){
			j = i+l-1;
			d[i][j] = LDBL_MAX;
			for(k = i; k < j; k++){
				g = d[i][k] + d[k+1][j] + mod(p, i, k) * mod(p, k+1, j);
				if(g < d[i][j]){
					d[i][j] = g;
				}
			}
		}
	}
	return (d[0][n]);
}
void clear(int *p, int n){
	int i;
	for(i = 0; i < n; i++){
		p[i] = 0;
	}
}
int main(){

	int n,i, x,j, t;
	long long int k;
	while (cin>>n){
		for(i =0; i < n; i++){
			cin>>x;
			p[i] = x;
		}
		x = smoke(p, n-1);
		cout<<x<<endl;
	}
/*	while(cin>>n){
      while(n--){
         cin>>x;
         p[n] = x;
      }
      cout<<smoke(p, n);
      clear(p, n);
   }*/
	return 0;
}