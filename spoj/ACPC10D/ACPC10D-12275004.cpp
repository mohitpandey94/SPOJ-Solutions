#include <iostream>

using namespace std;

int main()
{
  int n,r,k=0;
  cin>>n;
   while (n){
      int a[n+1][4];
      int b[n+2][4];
      for (int i=1;i<=n;i++) {
          for (int j=1;j<=3;j++) {
              cin>>a[i][j];
              b[i][j]=-1000001;
          }
      }
      //cout<<n<<" ";
      b[1][2]=a[1][2];
      for (int i=1;i<=n;i++) {
          for (int j=1;j<=3;j++) {
              if (b[i][j]!=-1000001) {
              if ((j+1)<=3) {
                  if (b[i][j+1]>b[i][j]+a[i][j+1] || b[i][j+1]==-1000001) b[i][j+1]=b[i][j]+a[i][j+1];
              }
              if ((j+1)<=3 && (i+1)<=n) {
                  if (b[i+1][j+1]>b[i][j]+a[i+1][j+1] || b[i+1][j+1]==-1000001) b[i+1][j+1]=b[i][j]+a[i+1][j+1];
              }
              if ((j-1)>0 && (i+1)<=n) {
                  if (b[i+1][j-1]>b[i][j]+a[i+1][j-1] || b[i+1][j-1]==-1000001) b[i+1][j-1]=b[i][j] + a[i+1][j-1];
              }
              if ((i+1)<=n) {
                  if (b[i+1][j]>b[i][j]+a[i+1][j] || b[i+1][j]==-1000001) b[i+1][j]=b[i][j] + a[i+1][j];
              }
              }
          }
      }
      k++;
      cout<<k<<". "<<b[n][2]<<endl;
      cin>>n;
  }
   return 0;
}
