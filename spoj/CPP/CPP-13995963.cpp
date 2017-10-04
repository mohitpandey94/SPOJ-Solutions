    #include<iostream>
    #include<algorithm>
    #include<math.h>
    #include<climits>
    #include <float.h>
    #include<iomanip>
    using namespace std;
    struct point{
    long long int x, y;
    };
    bool xcompare(point lhs, point rhs){
    if (lhs.x < rhs.x) return true;
    else if (lhs.x == rhs.x) {
    	return lhs.y < rhs.y;
    }
    else return false;
    }
    bool ycompare(point lhs, point rhs){
    	if (lhs.y < rhs.y) return true;
    	else if (lhs.y == rhs.y) {
    		return lhs.x < rhs.x;
    	}
    	else return false;
    }
    long double dis(point a, point b){
    long double x = (long double)(((b.x - a.x)* (b.x - a.x))*1.0) + (long double)(((b.y - a.y) * (b.y - a.y))*1.0);
    x = (long double)sqrt((long double)(x*1.0));
    return x;
    }
    long double strip_small(point *strip, int n, long double d){
    long double mini = d;
    int i,j;
    for(i = 0; i < n; i++){
    for(j = i+1; j < n && abs(strip[i].y - strip[j].y) < mini; j++){
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
    long double small(point *px, point *py,int n){
    if(n <= 3){
    return bruteforce(px, n);
    }
    long long int mid = n/2;
    point midpoint = px[mid];
    point pyl[mid + 1];
    point pyr[n-mid+1];
    long long int i, li = 0, ri = 0;
    for(i = 0; i < n; i++){
    if(py[i].x <= midpoint.x){
    pyl[li++] = py[i];
    }else{
    pyr[ri++] = py[i];
    }
    }
    long double dr = small(px, pyl, mid);
    long double dl = small(px+mid, pyr, n-mid);
    long double d = min(dl, dr);
    point strip[n];long long int j = 0;
    for(i = 0; i < n; i++){
    if(abs(py[i].x - midpoint.x) < d){
    strip[j] = py[i];
    j++;
    }
    }
    return min(d, strip_small(strip, j, d));
    }
    void display(point *p, int n){
    int i;
    for(i = 0; i < n; i++){
    cout<<p[i].x<<" "<<p[i].y<<" ";
    }
    }
    long double closest_pair(point *p, long long int n ){
    point px[n+5];
    point py[n+5];
    int i ;
    for(i = 0; i < n; i++){
    px[i] = p[i];
    py[i] = p[i];
    }
    sort(px, px+n, xcompare);
    sort(py, py+n, ycompare);
    long double k = small(px, py, n);
    return k;
    }
    int main(){
    point p[30005];
    int n, i; long long x, y;
    cin>>n;
    for(i = 0; i < n; i++){
    cin>>x>>y;
    p[i].x = x;
    p[i].y = y;
    }
    long double j = closest_pair(p, n);
    std::cout << std::fixed << std::setprecision(6)<<j<<"\n";
    return 0;
    }
     