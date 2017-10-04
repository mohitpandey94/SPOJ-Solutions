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
#define pi(x) printf ("%d",x)
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
typedef pair<int,int> pi;

// helper functions

//used by sort
bool cmpx(pair<int,int> a, pair<int,int> b) {
        if (a.first < b.first) return true;
        else if(a.first == b.first) {
                return (a.second < b.second);
        }
        else return false;
}
//used by sort
bool cmpy (pair<int,int> a , pair<int,int> b) {
        if (a.second < b.second) return true;
        else if (a.second == b.second) {
                return (a.first < b.first);
        }
        else return false;
}
double Distance (pi a, pi b) {
        int x1 = a.first;
        int y1 = a.second;
        int x2 = b.first;
        int y2 = b.second;

        double dis = (x2-x1)*(x2-x1)*1.0 + (y2-y1)*(y2-y1)*1.0;
        dis = (double)sqrt((double)dis);

        return dis;
}
//to print the points
void print(pair<int,int> p[], int n) {
        int i=0;
        repu(i,0,n,1) {
                cout<<p[i].first<<" "<<p[i].second<<"\n";
        }
        cout<<"\n";
}
//end of helpers

//min distance in the strip
double stripCheck (pi strip[], int size, int minDistTillNow) {
        double finalMinDist = minDistTillNow; // if there is no possible distance in the strip less than prev calc distance
        int j=0;
        repu(i,0,size,1) {
                //will run only 6 times for each i, so complexity is : O(n*6) ~ O(n)
                for (j = i+1; j < size && (strip[j].second - strip[i].second) < finalMinDist; j++) {
                        double dis = Distance(strip[i],strip[j]);
                        if (dis < finalMinDist) {
                                finalMinDist = dis;
                        }
                }
        }
        return finalMinDist;
}

// the bruteforce method
double calc (pi ptx[], int n) {
        double minDis = DBL_MAX;
        double dis;
        repu(i,0,n,1) {
                repu(j,i+1,n,1) {
                     dis = Distance(ptx[i],ptx[j]);
                     if (dis < minDis) {
                        minDis = dis;
                     }
                }
        }
        return minDis;
}


float closestpair(pi ptx[], pi pty[], int n) {
        if (n <= 3) return calc(ptx,n);

        int mid = n/2;
        pi lineGoesThroughPt = ptx[mid]; //line to divide the space into two parts

        pi PtsLeftOfLine[mid+1]; // the pdf
        pi PtsRightOfLine[n-mid+1]; // the pdf

        int i,j,k;
        j = k = 0;

        repu(i,0,n,1) {
                if (pty[i].first <= lineGoesThroughPt.first) PtsLeftOfLine[j++] = pty[i]; // point lies on left side of line
                else PtsRightOfLine[k++] = pty[i]; // point lies on the right side of line
        }

        double minDistLeft = closestpair(ptx,PtsLeftOfLine,mid);
        double minDistRight = closestpair(ptx,PtsRightOfLine,n-mid);

        double overallMinDist = min(minDistLeft, minDistRight);

        // the strip part,
        pi strip[n];

        j = 0;

        repu(i,0,n,1) {
                if (abs(pty[i].first - lineGoesThroughPt.first) < overallMinDist) {
                        strip[j++] = pty[i];
                }
        }
        return min(overallMinDist,stripCheck(strip,j,overallMinDist));
}

int main() {
        int n,x,y; // num of pts, x coord, y coord
        cin>>n;
        pi pts[n]; //all the points unsorted

        //input
        repu(i,0,n,1) {
                cin>>x>>y;
                pts[i] = (make_pair(x,y));
        }

        //print(pts,n); //check

        pi ptx[n]; //sorted by x
        pi pty[n]; // sorted by y
        copy(pts,pts+n,ptx);
        copy(pts,pts+n,pty);
        sort(ptx,ptx+n,cmpx); //sort for x
        sort(pty,pty+n,cmpy); // sort for y

        //print(ptx,n); // check
        //print(pty,n); //check

        double mindist = closestpair(ptx,pty,n);
        cout<<setprecision(7)<<mindist<<"\n";

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
