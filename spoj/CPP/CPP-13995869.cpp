    #include<iostream>
    #include<algorithm>
    #include<math.h>
    #include<climits>
    #include<iomanip>
    using namespace std;
    struct point{
    long long int x, y;
    };
    bool xcompare(point lhs, point rhs){
    return (lhs.x < rhs.x);
    }
    bool ycompare(point lhs, point rhs){
    return(lhs.y < rhs.x);
    }
    long double dis(point a, point b){
    long double x = (((b.x - a.x)* (b.x - a.x))*1.0) + (((b.y - a.y) * (b.y - a.y))*1.0);
    x = sqrt(x);
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
    long double mini = INT_MAX;
    for(i = 0; i < n; i++){
    for( j = i+1; j < n; j++){
    if(dis(px[i], px[j]) < mini)
    mini = dis(px[i], px[j]);
    }
    }
    return mini;
    }
    long double small(point *px, point *py, long long int n){
    long double k = 0;
    if(n <= 3){
    k = bruteforce(px, n);
    return k;
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
    k = min(d, strip_small(strip, j, d));
    return k;
    }
    void display(point *p, int n){
    int i;
    for(i = 0; i < n; i++){
    cout<<p[i].x<<" "<<p[i].y<<" ";
    }
    }
    long double closest_pair(point *p, long long int n ){
    point px[n];
    point py[n];
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
    point p[303];
    long long int n, i, x, y;
    cin>>n;
    for(i = 0; i < n; i++){
    cin>>x>>y;
    p[i].x = x;
    p[i].y = y;
    }
    long double j = closest_pair(p, n);
    std::cout << std::fixed << std::setprecision(6)<<j;
    return 0;
    }
     