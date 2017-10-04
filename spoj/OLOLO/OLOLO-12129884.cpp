#include <cstdio>
#define gc getchar_unlocked
long long int read() {
    long long int n=0;
    char c=gc();
    while (c<48) c=gc();
    while (c>47) {
        n = n*10+c-'0';
        c=gc();
    }
    return n;
}
main() {
    long long int n,temp,ans=0;
    n=read();
    while (n--) {
        temp=read();
        ans ^= temp;
    }
    printf("%lld\n",ans);
    return 0;
}