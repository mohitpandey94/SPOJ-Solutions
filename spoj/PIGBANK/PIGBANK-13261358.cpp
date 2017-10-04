#include<iostream>
#include <limits.h>
using namespace std;

int main () {
    long long best [10005]; int p [505], w [505],e,f,i,j,n;

	int t;
	cin >> t;
	while(t--){
		cin>>e>>f;
		cin>>n;
		f -= e;
		for(i = 0; i < n; i++)
			cin>>p[i]>>w[i];
		best [0] = 0;
		for(j = 1; j <= f; j++){
			best [j] = INT_MAX;
			for(i = 0; i < n; i++){
				if(w [i] <= j){
					if(best [j - w [i]] + p [i] < best [j]){
						best [j] = best [j - w [i]] + p [i];
					}
				}
			}

		}
        if(best[f]<INT_MAX)
        cout<<"The minimum amount of money in the piggy-bank is "<<best[f]<<".\n";
        else {
            cout<<"This is impossible.\n";
        }
	}

	return 0;
}
