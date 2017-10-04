#include<string.h>
#include<stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>
#define si(x) scanf("%d",&x)
#define pi(x) printf("%d",x)
#define ps(x) printf("%s",x)
#define gc getchar_unlocked
bool vis[52][52][52];
char a[52][52];
int s[52][52][52],r,c,i, j,k,val,t;
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
int maxo (int a, int b){
	return (a > b ? a : b);
}
int abss (int a) {
	return (a < 0? -a : a);
}

int func(int i, int j ,int y){
	if(y == r)
		return 0;
	else if(i < 0 || j < 0 || i == j) return INT_MIN;
	else if (i >= c || j >= c) return INT_MIN;
	else if ( a[y][i] == '#' || a[y][j] == '#') return INT_MIN;
	if(vis[y][i][j])
		return s[y][i][j];
	vis[y][i][j] = true;

		int ans = INT_MIN;
		ans = maxo (ans,(abss(j-i)==1)+func(i,j,y+1));
		ans = maxo (ans,(abss(j-i)==1)+func(i,j-1,y+1));
		ans = maxo (ans,(abss(j-i)==1)+func(i,j+1,y+1));
		
		ans = maxo (ans,(abss(j-i)==1)+func(i+1,j,y+1));
		ans = maxo (ans,(abss(j-i)==1)+func(i+1,j-1,y+1));
		ans = maxo (ans,(abss(j-i)==1)+func(i+1,j+1,y+1));
		
		ans = maxo (ans,(abss(j-i)==1)+func(i-1,j,y+1));
		ans = maxo (ans,(abss(j-i)==1)+func(i-1,j-1,y+1));
		ans = maxo (ans,(abss(j-i)==1)+func(i-1,j+1,y+1));
		
		s[y][i][j] = ans;
		
		return ans;
}
int main(){
	char ch;
	si(t);
	while(t--){
		si(r);si(c);
		//r=readi();c=readi();
		ch=gc();
		//printf("%d%d%c",r,c,ch);
		for(i = 0; i < r; i++){
			ch=gc();
			j=0;
			while (ch == '.' || ch=='#') {
				//printf("%c",ch);
				a[i][j++] = ch;
				ch= gc();

			}
		}
		
		val = INT_MIN;
		for(i = 0; i < c; i++){
			for(j = i+1; j < c; j++){
				val = maxo(func(i, j, 0),val);
			//	cout<<val<<endl;
			//	cout<<"max "<<max<<endl;
			}
		}
		if(val >= 0)
			pi(val);
		else
			ps("Detour");
		ps("\n");
		for (i=0;i<r;i++) for (j=0;j<c;j++) for (k=0;k<c;k++) vis[i][j][k]=false;
	}
	return 0;
}
