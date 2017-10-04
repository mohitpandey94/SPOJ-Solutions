#include <iostream>
#include<stdio.h>
#define gc getchar_unlocked
using namespace std;
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
int main() {
 int n,k,j,cnt=0;
 scanint(n);
 scanint(k);
 while (n--) {
 	scanint(j);
 	if (j%k==0) cnt++;
 }
 printf("%d\n",cnt);
	return 0;
}