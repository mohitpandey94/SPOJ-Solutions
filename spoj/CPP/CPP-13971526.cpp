#include<iostream>
#include<algorithm>
#include<math.h>
#include <bits/stdc++.h>
#include<climits>
#include<iomanip>
#define ll long long
using namespace std;
struct point{
long long int x, y;
};
bool xcompare(point lhs, point rhs){
if (lhs.x < rhs.x) return true;
else if (lhs.x == rhs.x) {
	return lhs.y < lhs.y;
}
else return false;
}
bool ycompare(point lhs, point rhs){
if(lhs.y < rhs.y) return true;
else if (lhs.y == rhs.y) {
	return lhs.x < rhs.x;
}
else return false;
}
long double dis(point a, point b){
        ll x1 = a.x;
        ll y1 = a.y;
        ll x2 = b.x;
        ll y2 = b.y;

        long double x = (long double)((x2-x1)*(x2-x1)*1.0) + (long double)((y2-y1)*(y2-y1)*1.0);
        x = (long double)sqrt((long double)(x*1.0));

      return x;
}
long double strip_small(point *strip, int n, long double d){
long double mini = d;
int i,j;
for(i = 0; i < n; i++){
    for(j = i+1; j < n && (strip[i].y - strip[j].y) < mini; j++){
        if(dis(strip[i] , strip[j]) < d){
            mini = dis(strip[i], strip[j]);
        }
    }
}
return mini;
}
long double bruteforce(point *px, int n){
int i, j;
long double mini = LDBL_MAX;
for(i = 0; i < n; i++){
    for( j = i+1; j < n; j++){
        if(dis(px[i], px[j]) < mini)
            mini = dis(px[i], px[j]);
    }
}
return mini;
}
long double small(point *px, point *py, int n) {
    long double k = 0.0;
    if(n <= 3){
        k = bruteforce(px, n);
        return k;
    }
int mid = n/2;
point midpoint = px[mid];
point pyl[mid + 1];
point pyr[n-mid+1];
int i, li = 0, ri = 0;
for(i = 0; i < n; i++){
    if(py[i].x < midpoint.x){
        pyl[li++] = py[i];
    }else{
        pyr[ri++] = py[i];
    }
}
long double dr = small(px, py, mid);
long double dl = small(px+mid, py, n-mid);
long double d = min(dl, dr);
point strip[n];int j = 0;
for(i = 0; i < n; i++){
    if(abs(py[i].x - midpoint.x) < d){
        strip[j] = py[i];
        j++;
    }
}
k = min(d, strip_small(py, j, d));
return k;
}
void display(point *p, int n){
int i;
for(i = 0; i < n; i++){
    cout<<p[i].x<<" "<<p[i].y<<"    ";
}
}
long double closest_pair(point *p, int n ){
point px[n];
point py[n];
int i ;
for(i = 0; i < n; i++){
px[i] = p[i];
py[i] = p[i];
}
sort(px, px+n, xcompare);
sort(py, py+n, ycompare);
//display(px,n);
//cout<<"\n";
//display(py,n);
long double k = small(px, py, n);
return k;
}
int main(){

int n, i;
long long x,y;
cin>>n;
point p[n+5];
for(i = 0; i < n; i++){
cin>>x>>y;
p[i].x = x;
p[i].y = y;
}
long double j = closest_pair(p, n);
std::cout << std::fixed << std::setprecision(6)<<j<<"\n";
return 0;
}
