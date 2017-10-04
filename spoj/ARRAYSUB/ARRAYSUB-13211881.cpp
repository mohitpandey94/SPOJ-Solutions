#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#ifndef ONLINE_JUDGE
#define gc getchar
#else
#define gc getchar_unlocked
#endif
#define ll long long
#define nl() printf ("\n")
#define pi(x) printf ("%d",x)
#define pl(x) printf ("%lld",x)
#define pc(x) printf ("%c",x)
#define ps(x) printf ("%s",x)
#define pb(x) push_back(x)
#define repu(i,n,step) for (;i<n;i+=step)
#define repd(i,n) for (;i>=0;i--)
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
void construct(int a[], int tree[], int startofsegment, int endofsegment, int currentindex) {
        //cout<<startofsegment<<" "<<endofsegment<<" "<<currentindex<<"\n";
        if (startofsegment>endofsegment) return;
        if (startofsegment==endofsegment) {
                tree[currentindex] = startofsegment;
        }
        else {
                construct(a,tree,startofsegment,(endofsegment+startofsegment)/2,2*currentindex);
                construct(a,tree,(startofsegment+endofsegment)/2+1,endofsegment,2*currentindex+1);
                if (a[tree[currentindex*2]]<=a[tree[currentindex*2+1]])
                        tree[currentindex]=tree[currentindex*2+1];
                else tree[currentindex]=tree[currentindex*2];
        }

}
int query(int a[],int tree[],int startofsegment, int endofsegment,int currentindex, int querystart, int queryend) {
        int p1,p2;
        //cout<<startofsegment<<" "<<endofsegment<<" "<<currentindex<<"\n";
        if (querystart > endofsegment || queryend < startofsegment) return -1;

        if (startofsegment >= querystart && endofsegment <= queryend) return tree[currentindex];

        p1=( query(a,tree,startofsegment,(startofsegment+endofsegment)/2,2*currentindex,querystart,queryend));
        p2=(query(a,tree,(startofsegment+endofsegment)/2+1,endofsegment,2*currentindex+1,querystart,queryend));
        if (p1==-1) return p2;
        if (p2==-1) return p1;
        if (a[p1]<=a[p2]) return p2;
        else return p1;


}
int main() {
        int n,height,sizeoftree,q,x,y;
        int *a,i=0;
        n=readi();
        a = new int[n];
        repu(i,n,1) a[i]=readi();
        height = (int)(ceil) (log2(n));
        //cout<<"Height of tree is:"<<height<<endl;
        sizeoftree = 2*(int)pow(2,height) -1;
        int *tree = new int[sizeoftree];
        construct(a,tree,0,n-1,1);
        q=readi();
        q--;
        x=0;y=q;
        while (y<n) {
        //cout<<"\n\n";
        pi(a[query(a,tree,0,n-1,1,x,y)]);ps(" ");
        x++;y++;
        }
        nl();

return 0;
}
