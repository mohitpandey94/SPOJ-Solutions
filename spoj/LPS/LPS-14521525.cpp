#include <bits/stdc++.h>
using namespace std;
#define N 100005*2
// Begins Suffix Arrays implementation
// O(n log n) - Manber and Myers algorithm
// Refer to "Suffix arrays: A new method for on-line string searches",
// by Udi Manber and Gene Myers

//Usage:
// Fill str with the characters of the string.
// Call SuffixSort(n), where n is the length of the string stored in str.
// That's it!

//Output:
// pos = The suffix array. Contains the n suffixes of str sorted in lexicographical order.
//       Each suffix is represented as a single integer (the position of str where it starts).
// invpos = The inverse of the suffix array. invpos[i] = the index of the suffix str[i..n)
//        in the pos array. (In other words, pos[i] = k <==> invpos[k] = i)
//        With this array, you can compare two suffixes in O(1): Suffix str[i..n) is smaller
//        than str[j..n) if and only if invpos[i] < invpos[j]

string str; //input
int invpos[N], pos[N]; //output
int cnt[N], nextt[N]; //internal
bool bh[N], b2h[N];

// Compares two suffixes according to their first characters
void printarr (int pos[], int n) {
    for (int i =0;i<n;i++) {
        if (i%5 == 4) cout<<"\n";
        cout<<pos[i]<<" ";
    }
    cout<<"\n";
}
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

    //printarr(pos,n);

  for (int i=0; i<n; ++i){
    bh[i] = i == 0 || str[pos[i]] != str[pos[i-1]];
    b2h[i] = false;
  }

  for (int h = 1; h < n; h <<= 1){
    //{bh[i] == false if the first h characters of pos[i-1] == the first h characters of pos[i]}
    int buckets = 0;
    for (int i=0, j; i < n; i = j){
      j = i + 1;
      while (j < n && !bh[j]) j++;//checks for how many suffixes can go into the same bucket, based on the first h characters
      nextt[i] = j;
      buckets++;
    }
    //printarr(nextt,n);
    if (buckets == n) {
        //cout<<"here";
        break;
    } //if all of the first h characters of the string are now distinct,
      //so it'll break in the very time if all the characters of the string are distinct
      // We are done! Lucky bastards!
      //{suffixes are separated in buckets containing strings starting with the same h characters}

    for (int i = 0; i < n; i = nextt[i]){
      cnt[i] = 0;
      for (int j = i; j < nextt[i]; ++j){
        invpos[pos[j]] = i;
      }
    }

    cnt[invpos[n - h]]++;
    b2h[invpos[n - h]] = true;
    for (int i = 0; i < n; i = nextt[i]){
      for (int j = i; j < nextt[i]; ++j){
        int s = pos[j] - h;
        if (s >= 0){
          int head = invpos[s];
          invpos[s] = head + cnt[head]++;
          b2h[invpos[s]] = true;
        }
      }
      for (int j = i; j < nextt[i]; ++j){
        int s = pos[j] - h;
        if (s >= 0 && b2h[invpos[s]]){
          for (int k = invpos[s]+1; !bh[k] && b2h[k]; k++) b2h[k] = false;
        }
      }
    }
    for (int i=0; i<n; ++i){
      pos[invpos[i]] = i;
      bh[i] |= b2h[i];
    }
  }
  for (int i=0; i<n; ++i){
    invpos[pos[i]] = i;
  }
}
int height[N];
// height[i] = length of the longest common prefix of suffix pos[i] and suffix pos[i-1]
// height[0] = 0
void getHeight(int n){
  for (int i=0; i<n; ++i) invpos[pos[i]] = i;
  height[0] = 0;
  for (int i=0, h=0; i<n; ++i){
    if (invpos[i] > 0){
      int j = pos[invpos[i]-1];
      while (i + h < n && j + h < n && str[i+h] == str[j+h]) h++;
      height[invpos[i]] = h;
      if (h > 0) h--;
    }
  }
}
string rev (string s) {
    string ans;
    int len = s.length()-1;
    for (int i = 0; i < len; i++) {
        ans += s[len-i-1];
    }

    return ans;
}
int main() {
    //cout<<(char)('z'+1);
    int t,len,len1;
    //cin>>t;
    t=1;
    while (t--) {
    cin>>len1;
    cin>>str;
    //len1 = str.length();
    str += "#";
    str += rev(str);
    suffixSort(2*len1+1);
    getHeight(2*len1+1);

        int maxl = 0,ans=0;
        for (int i = 0; i < 2*len1+1;i++) {
            //cout<<i<<" "<<str.substr(i,len)<<" "<<pos[i]<<"\n";
            //cout<<height[2*len1+1-i-1]<<" "<<pos[2*len1+1-i-1]<<" "<<height[i]<<" "<<pos[i]<<"\n";
            //else if (height[i] == maxl) ans++;
            if (height[i] > maxl) {
                if ((pos[i] > len1 && pos[i-1] < len1) || (pos[i] < len1 && pos[i-1] > len1)) {
                    maxl = height[i];
                    //ans = 1;
                }
            }
            /*
            else if (height[i] == maxl) {
                if (pos[i] > len1 && pos[i-1] < len1 || pos[i] < len1 && pos[i-1] > len1) {
                    ans++;
                }
            }
            */
        }
        cout<<maxl<<"\n";
        //cout<<tot<<"\n";
    }
    //printarr(pos,str.length());
}
