#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
   int t;
   long long int n,m;
   cin>>t;
   while (t--) {
       cin>>n>>m;
       if( (n>m) && (m%2==1) )
    	{
			printf("D\n");
		}
		else if(n>m)
		{
			printf("U\n");
		}
		else if( (n<m) && (n%2==1) )
		{
			printf("R\n");
		}
		else if(n<m)
		{
			printf("L\n");
		}
		else if( (n==m) && (n%2==1) )
		{
			printf("R\n");
		}
		else
		{
			printf("L\n");
		}
   }
   return 0;
}
