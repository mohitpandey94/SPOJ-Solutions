#include <iostream>
#include <string.h>
using namespace std;
char exp[400];
int top = -1;
void push(char c) {
    if (top == -1)
        top = 0;
    if (top == 400) {
        return ;
    }
    exp[++top] = c;
}
void pop ()
{
    if (top == -1) {
        return ;
    }
    cout<<exp[top];
    top--;


}
int main() {
    int t,i;
    char s[400];
    cin>>t;
    while (t--) {
        cin>>s;
        for (i=0;i<strlen(s);i++) {
            if (s[i] == '(') {
                    continue;
                }
            else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^') {
                push(s[i]);
            }
            else if (s[i] ==')' ) {
                pop();
            }
            else {
                cout<<s[i];
            }
        }
        cout<<"\n";
    }

    return 0;
}
