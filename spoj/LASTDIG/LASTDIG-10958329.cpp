    #include<stdio.h>
    #include<math.h>
    int main()
    {
    int a,mod,t;
    unsigned long b;
    scanf("%d",&t);
    while (t--){
    scanf("%d %lu",&a,&b);
    if(b==0&&a!=0) {
        printf("1\n");
        continue;
    }
    if(!a){
        printf("0\n");
        continue;
    }
    else{
    mod=a%10;
    if(mod==2||mod==3||mod==7||mod==8){
    mod = pow(mod,(((b%4) == 0)?4:(b%4)));
    mod %= 10;
    printf("%d\n", mod);
    }
    else if(mod==4||mod==9){
    mod = pow(mod,(((b%2) == 0)?2:(b%2)));
    mod %= 10;
    printf("%d\n", mod);
    }
    else printf("%d\n", mod);
    }
    }
    return 0;
    }
