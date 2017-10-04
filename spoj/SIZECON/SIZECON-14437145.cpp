int main() {
    int t,x;
    long long ans=0;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&x);
        ans += (x>0?x:0);
    }
    printf("%lld\n",ans);
    return 0;
}
