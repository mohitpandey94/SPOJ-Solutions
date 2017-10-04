#include <iostream>
#include <string.h>
#include <stdio.h>
 using namespace std;
 struct st {
     char a[10000];
      long int top;
      long int index[10000];
};

 void push (struct st *s, char val, int i) {
    s->a[++(s->top)]=val;
    s->index[s->top]=i ;
 }
 long int pop (struct st *s) { long int item=s->index[s->top]; --(s->top); return item; }
 int main() {
        int t,i; struct st s;
        char p[2005],next;
        long int cnt=0,len,k,j=0,temp; t=0;

       while (scanf("%s",&p)) {
                if (p[0]=='-') break;
                t++;
                s.top=-1; cnt=j=0;k=0;
                len=strlen(p);
                for (i=0; i < len; i++) {
                        if (p[i] == '{')
                                push (&s, p[i],i);
                        else if (p[i]=='}') {
                                if (s.top==-1) {
                                        cnt++;
                                        push(&s,'{',i);
                                }
                                else {
                                        temp=pop(&s); p[i]=p[temp]='!';
                                }
                        }
                }
                i=0;
                for (i=0;i<len;i++) {
                        if (p[i]!='!') {
                                k++;
                        }
                }
                if (s.top!=-1) {
                        cnt += k/2;
                }

                printf("%d. %ld\n",t,cnt);
        }

    return 0;
}
