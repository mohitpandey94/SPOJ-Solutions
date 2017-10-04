#include <bits/stdc++.h>
#include <cstring>
#ifndef ONLINE_JUDGE
#define gc getchar
#else
#define gc getchar_unlocked
#endif
#define ll long long
#define nl() printf ("\n")
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define pl(x) printf ("%lld",x)
#define pc(x) printf ("%c",x)
#define ps(x) printf ("%s",x)
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define repu(i,a,n,step) for (int i = a; i < n; i += step)
#define repd(i,a,n,step) for (int i = a - 1; i >= n; i -= step)
using namespace std;

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
ll readl () {
	ll n=0;int sign=0;
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
typedef pair<ll,ll> pi;

// helper functions

//used by sort
bool cmpx(pair<ll,ll> a, pair<ll,ll> b) {
        if (a.first < b.first) return true;
        else if(a.first == b.first) {
                return (a.second < b.second);
        }
        else return false;
}
//used by sort
bool cmpy (pair<ll,ll> a , pair<ll,ll> b) {
        if (a.second < b.second) return true;
        else if (a.second == b.second) {
                return (a.first < b.first);
        }
        else return false;
}
long double Distance (pi a, pi b) {
        ll x1 = a.first;
        ll y1 = a.second;
        ll x2 = b.first;
        ll y2 = b.second;

        long double dis = (long double)((x2-x1)*(x2-x1)*1.0) + (double)((y2-y1)*(y2-y1)*1.0);
        dis = (long double)sqrt((long double)(dis*1.0));

        return dis;
}
//to print the points
void print(pair<ll,ll> p[], int n) {
        int i=0;
        repu(i,0,n,1) {
                cout<<p[i].first<<" "<<p[i].second<<"\n";
        }
        cout<<"\n";
}
//end of helpers
pi anspair[2];

struct ans {
    pi a,b;
    long double dist;
};
//min distance in the strip
struct ans stripCheck (pi strip[], int size, long double minDistTillNow) {
        long double finalMinDist = minDistTillNow; // if there is no possible distance in the strip less than prev calc distance
        struct ans cp;
        int j=0;
        cp.dist = finalMinDist;
        repu(i,0,size,1) {
                //will run only 6 times for each i, so complexity is : O(n*6) ~ O(n)
                for (j = i+1; j < size && (strip[j].second - strip[i].second) < finalMinDist; j++) {
                        long double dis = Distance(strip[i],strip[j]);
                        if (dis < finalMinDist) {
                                cp.a = strip[i];
                                cp.b = strip[j];
                                cp.dist = dis;
                                finalMinDist = dis;
                        }
                }
        }
        return cp;
}
// the bruteforce method
struct ans calc (pi ptx[], int n) {
        long double minDis = LDBL_MAX;
        struct ans cp;
        long double dis;
        repu(i,0,n,1) {
                repu(j,i+1,n,1) {
                     dis = Distance(ptx[i],ptx[j]);
                     if (dis < minDis) {
                        cp.a = ptx[i];
                        cp.b = ptx[j];
                        cp.dist = dis;
                        minDis = dis;
                     }
                }
        }
        return cp;
}


struct ans closestpair(pi ptx[], pi pty[], int n) {
        //cout<<"hre"<<n<<" ";
        if (n <= 3) return calc(ptx,n);
        struct ans cl,cr,cp;
        int mid = n/2;
        pi lineGoesThroughPt = ptx[mid]; //line to divide the space into two parts

        pi PtsLeftOfLine[mid+5]; // the pdf
        pi PtsRightOfLine[n-mid+5]; // the pdf

        int i,j,k;
        j = k = 0;

        repu(i,0,n,1) {
                if (pty[i].first <= lineGoesThroughPt.first) PtsLeftOfLine[j++] = pty[i]; // point lies on left side of line
                else PtsRightOfLine[k++] = pty[i]; // point lies on the right side of line
        }

        cl = closestpair(ptx,PtsLeftOfLine,mid);
        cr = closestpair(ptx+mid,PtsRightOfLine,n-mid);

        cp = (cl.dist < cr.dist) ? cl : cr;
        long double overallMinDist = cp.dist;
        // the strip part,
        pi strip[n+5];
        //cout<<cl.a.first<<" "<<cl.a.second<<","<<cl.b.first<<" "cl.b.second<<"||"<<cr.a.first<<" "cr.a.second<<","<<cr.b.first<<" "<<cr.b.second<<"||"<<cp.a.first<<" "<<cp.a.second<<","<<cp.b.first<<" "<<cp.b.second<<"\n";
        //cout<<cl.dist<<" "<<cr.dist<<" ";
        j = 0;

        repu(i,0,n,1) {
                if (abs(pty[i].first - lineGoesThroughPt.first) < overallMinDist) {
                        strip[j++] = pty[i];
                }
        }
        struct ans temp = stripCheck(strip,j,overallMinDist);
        //cout<<temp.dist<<"\n";
        return (temp.dist < cp.dist ? temp : cp) ;
}
map <pi,int> mapper;
pi pts[50005];
pi ptx[50005]; //sorted by x
pi pty[50005];
int main() {
        int n; ll x,y;// num of pts, x coord, y coord

        n=readi();
        //all the points unsorted

        //input
        repu(i,0,n,1) {
                x=readl();y=readl();
                pts[i] = (make_pair(x,y));
                mapper[pts[i]] = i;
        }

        //print(pts,n); //check

         // sorted by y
        copy(pts,pts+n,ptx);
        copy(pts,pts+n,pty);
        sort(ptx,ptx+n,cmpx); //sort for x
        sort(pty,pty+n,cmpy); // sort for y

        //print(ptx,n); // check
        //print(pty,n); //check
        //cout<<"hre";
        struct ans mindist = closestpair(ptx,pty,n);
        int ind1,ind2;
        //printf("%d %d %.6lf\n",mapper[anspair[0]],mapper[anspair[1]],mindist);
        ind1 = mapper[mindist.a];
        ind2 = mapper[mindist.b];
        if (ind1 > ind2) {
            swap(ind1,ind2);
        }
        cout<<ind1<<" "<<ind2<<" "<<setprecision(6)<<fixed<<mindist.dist<<"\n";
        //cout<<anspair[0].first<<" "<<anspair[0].second<<":"<<anspair[1].first<<" "<<anspair[1].second<<"\n";
return 0;
}
/*
Input:
6
2 3
12 30
40 50
5 1
12 10
3 4
*/
