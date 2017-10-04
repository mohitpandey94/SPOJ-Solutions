#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
main ()
{   int t,asc[26]={0},max=0,index,i,flag=0,temp;
    char ch;
    char s[10000];
    cin>>t;
    while (t--) {
        index=max=flag=0;
        scanf("%c",&ch);
        scanf("%[^\n]s",&s);
        for (i=0;i<strlen(s);i++) {
            if (s[i]!=' ') {
                asc[s[i]-'A']++;
                if (asc[s[i]-'A']>max) {
                    max=asc[s[i]-'A'];
                    index=i;
                    temp=s[i]-'A';
                }
            }
        }
        
        for (i=0;i<26;i++) {
            if (asc[i]==max && i!=temp) {
                cout<<"NOT POSSIBLE\n";
                flag=1;
                break;
            }
        }
        if (!flag) {
            max=s[index]-'E';
            if (max<0) {
        	max+=26;
        	}
            for (i=0;i<strlen(s);i++) {
                if (s[i]!=' ')
                if (s[i]-max>='A') {
                    s[i]=s[i]-max;
                }
                else {
                    s[i]='Z' - (max-(s[i]-'A')-1);
                }
            }
            cout<<max<<" "<<s<<endl;;
        }
        for (i=0;i<26;i++) asc[i]=0;
    }
}
