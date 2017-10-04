#include <bits/stdc++.h>
#include <iostream>
#define gc getchar_unlocked
using namespace std;
 int readi() {
	 char c=gc();
	 int n=0;
	 while (c < '0' && c > '9') c=gc();
	 while (c >= '0' && c <= '9') {
		 n = n *10 + c-'0';
		 c=gc();
	 }
 	return n;
 }
 int n;
 void update(int bit[], int idx, int val) {
 	while (idx <= n) {
 		bit[idx] += val;
 		idx = idx + (idx & -idx);
 	}
 }
 void print(int bit[]) {
 	for (int i=1;i<=n;i++) cout<<bit[i]<<" ";
 	cout<<"\n";
 }
 int getval(int bit[], int idx) {
 	int val=0;
 	while (idx > 0) {
 		val += bit[idx];
 		idx = idx - (idx & -idx);
 	}
 	return val;
 }
int main() {
	cout.tie(0);
	// your code goes here
	int t,u,x,y,z;
	t=readi();
	while (t--) {
		n=readi(); u=readi();
		int a[n+1],bit[n+1];
		int v=0;
		fill(bit,bit+n+1,0);
		while (u--) {
			x=readi();y=readi();z=readi();
			x++;y++;
			update(bit,x,z); 
			//cout<<"x="<<x<<":";
			//print(bit);
			update(bit,y+1,-z);
			//cout<<"y+1="<<y+1<<":";
			//print(bit);
		}
			int q=readi();
			while (q--) {
				x=readi();
				x++;
				cout<<getval(bit,x)<<"\n";
			}
		}
		//print(bit);
	return 0;
}