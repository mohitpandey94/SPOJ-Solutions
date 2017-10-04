#include<iostream>
#include<algorithm>
#include <string.h>
using namespace std;
int d[2][5005];
void strrev(char s[],char ss[], int len) {
    for (int i = len-1;i>=0;i--) {
        ss[i] = s[len-i-1];
    }
}
int main(){
	ios::sync_with_stdio(false);
	int t, i, n, j, k;
	char a[5005];
	char b[5005];
	cin>>n;
//	for(k = 0; k < t; k++){
		cin>>a;
		strrev(a,b,n);
	//	n = a.length();
	//	j = 0;
		memset(d,0,sizeof d);
		for(i = 1; i <= n; i++){
			for(j = 1; j <= n; j++){
				if(a[i-1] == b[j-1]){
					d[1][j] = d[0][j-1] + 1;
				}else{
					d[1][j] = max(d[0][j], d[1][j-1]);
				}
				//d[0][j] = d[1][j];
			}
			for(j = 1; j <= n; j++){
			//	cout<<d[1][j];
				d[0][j] = d[1][j];
			}
		//	cout<<endl;
		}
		cout<<n-d[1][n]<<endl;
//	}
	return 0;
}