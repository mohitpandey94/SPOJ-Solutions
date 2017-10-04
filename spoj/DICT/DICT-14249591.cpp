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
struct trie {
    bool isLeaf;
    trie* childs[26];
    vector <int> id;
} *root;
struct trie* newNode() {
    trie* newnode = new trie;
    newnode->isLeaf = false;
    repu(i,0,26,1) newnode->childs[i] = NULL;

    return newnode;
}
void inserter (string s) {
    trie* temp = root;
    int len = s.size();
    bool flag = false;
    repu(i,0,len,1) {
        if (!(temp->childs[s[i]-'a'])) {
            temp->childs[s[i]-'a'] = newNode();
            flag = true;
        }

        temp = temp->childs[s[i]-'a'];
        flag = false;
    }
    temp->isLeaf = true;

    return;
}
void dfs (char s[], int len, trie *root) {
    if (root->isLeaf) {
        cout<<s<<"\n";
    }
    repu(i,0,26,1) {
        if (root->childs[i]) {
            s[len] = (char)(i+'a');
            s[len+1] = '\0';
            dfs(s,len+1,root->childs[i]);
        }
    }
}
bool searcher(string s) {
    trie *temp = root;
    char v[30];
    repu(i,0,s.size(),1) {
        if (!temp->childs[s[i]-'a']) {
            return false;
        }
        else {
            temp = temp->childs[s[i]-'a'];
            v[i] = s[i];
        }
    }
    bool flag = false;
    repu(i,0,26,1) {
        if (temp->childs[i]) {
            //cout<<v<<" "<<s.size()<<"\n";
            v[s.size()] = (char)(i+'a');
            v[s.size()+1] = '\0';
            //cout<<v<<" "<<(char)(i+'a');
            dfs(v,s.size()+1,temp->childs[i]);
            flag = true;
        }
    }
    return flag;
}
int main() {
    root = newNode();
    int n,k;
    string s;
    cin>>n;
    while (n--) {
        cin>>s;
        inserter(s);
    }
    //dfs(root,0);
    cin>>k;
    //cout<<k;
    bool a;
    int i = 1;
    while (k--) {
        cin>>s;
        cout<<"Case #"<<i<<":\n";
        a = searcher(s);
        if (!a) {
            ps("No match.\n");
        }
        i++;
    }

return 0;
}
