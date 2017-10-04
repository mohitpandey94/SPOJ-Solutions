#include<string.h>
#include<stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>
#define si(x) scanf("%d",&x)
#define pi(x) printf("%d",x)
#define ps(x) printf("%s",x)

bool vis[52][52][52];
char a[52][52];
int s[52][52][52],r,c,i, j,k,val,t;
/*
int max (int a, int b, int c) {
	if (a > b) {
		if (a > c) return a;
		return c;
	}
	else {
		if (b > c) return b;
		return c;
	}
}
*/
int maxo (int a, int b){
	return (a > b ? a : b);
}
int abss (int a) {
	return (a < 0? -a : a);
}
/*
int valid(int i, int j, int y){
	if(y >= r)
		return false;
	else if(i < 0 || j < 0 || i == j) return false;
	else if (i >= c || j >= c) return false;
	else if ( a[y][i] == '#' || a[y][j] == '#') return false;
	return true;
}
*/
int func(int i, int j ,int y){
	if(y == r)
		return 0;
	else if(i < 0 || j < 0 || i == j) return INT_MIN;
	else if (i >= c || j >= c) return INT_MIN;
	else if ( a[y][i] == '#' || a[y][j] == '#') return INT_MIN;
	if(vis[y][i][j])
		return s[y][i][j];
	vis[y][i][j] = true;
		/*
		s[y][i][j] = max(max (func(i,j,y+1)+(abss(j-i)==1), func (i,j-1,y+1)+(abss(j-i)==1), func (i,j+1,y+1)+(abss(j-i)==1)),
						 max (func(i+1,j,y+1)+(abss(j-i)==1), func (i+1,j-1,y+1)+(abss(j-i)==1), func (i+1,j+1,y+1)+(abss(j-i)==1)),
						 max (func(i-1,j,y+1)+(abss(j-i)==1), func (i-1,j-1,y+1)+(abss(j-i)==1), func (i-1,j+1,y+1)+(abss(j-i)==1))
						);
						
		*/
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
	/*
		s[y][i][j]=	max(func(i, j,  y+1, r, c) + count, 
					max(func(i, j-1,  y+1, r, c) + count,
	 				max(func(i, j+1, y+1, r, c) + count,
	  				max(func(i+1,j,  y+1, r, c ) + count, 
	  				max(func(i+1, j-1, y+1, r, c) + count, 
	  				max(func(i+1, j+1,  y+1, r, c) + count,
	  				max(func(i-1, j,  y+1, r, c) + count,
	  				max(func(i-1, j-1,  y+1, r, c) + count,
	  				func(i-1, j+1,  y+1, r, c) + count))))))));
	  */
}
int main(){
	
	si(t);
	while(t--){
		si(r);si(c);
		for(i = 0; i < r; i++){
			scanf("%s",a[i]);
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
