#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define N 100002
string str; //input
int rankk[N], pos[N]; //output
int cnt[N], nextt[N]; //internal
bool bh[N], b2h[N];
 
// Compares two suffixes according to their first characters
bool smaller_first_char(int a, int b){
  return str[a] < str[b];
}
 
void suffixSort(int n){
  //sort suffixes according to their first characters
  for (int i=0; i<n; ++i){
    pos[i] = i;
  }
  sort(pos, pos + n, smaller_first_char);
  //{pos contains the list of suffixes sorted by their first character}
 
  for (int i=0; i<n; ++i){
    bh[i] = i == 0 || str[pos[i]] != str[pos[i-1]];
    b2h[i] = false;
  }
 
  for (int h = 1; h < n; h <<= 1){
    //{bh[i] == false if the first h characters of pos[i-1] == the first h characters of pos[i]}
    int buckets = 0;
    for (int i=0, j; i < n; i = j){
      j = i + 1;
      while (j < n && !bh[j]) j++;
      nextt[i] = j;
      buckets++;
    }
    if (buckets == n) break; // We are done! Lucky bastards!
    //{suffixes are separted in buckets containing strings starting with the same h characters}
 
    for (int i = 0; i < n; i = nextt[i]){
      cnt[i] = 0;
      for (int j = i; j < nextt[i]; ++j){
        rankk[pos[j]] = i;
      }
    }
 
    cnt[rankk[n - h]]++;
    b2h[rankk[n - h]] = true;
    for (int i = 0; i < n; i = nextt[i]){
      for (int j = i; j < nextt[i]; ++j){
        int s = pos[j] - h;
        if (s >= 0){
          int head = rankk[s];
          rankk[s] = head + cnt[head]++;
          b2h[rankk[s]] = true;
        }
      }
      for (int j = i; j < nextt[i]; ++j){
        int s = pos[j] - h;
        if (s >= 0 && b2h[rankk[s]]){
          for (int k = rankk[s]+1; !bh[k] && b2h[k]; k++) b2h[k] = false;
        }
      }
    }
    for (int i=0; i<n; ++i){
      pos[rankk[i]] = i;
      bh[i] |= b2h[i];
    }
  }
  for (int i=0; i<n; ++i){
    rankk[pos[i]] = i;
  }
}
int main() {
	//string s;
	cin>>str;
	suffixSort(str.length());
	for (int i = 0; i < str.length(); i++) cout<<pos[i]<<"\n";
	// your code goes here
	return 0;
}