#include <bits/stdc++.h>
#define gc getchar_unlocked
using namespace std;
int readint() {
    char c = gc();
    int n = 0;
    while (c < '0' || c > '9') c=gc();
    while (c >= '0' and c <= '9') {
        n = n*10 + c-'0';
        c = gc();
    }
    return n;
}
#define N 311111
#define A 1111111
#define BLOCK 555 // ~sqrt(N)

int cnt[A], a[N], ans[N], answer = 0;

struct node {
	int L, R, i;
}q[N];

bool cmp(node x, node y) {
	if(x.L/BLOCK != y.L/BLOCK) {
		// different blocks, so sort by block.
		return x.L/BLOCK < y.L/BLOCK;
	}
	// same block, so sort by R value
	return x.R < y.R;
}

void add(int position) {
	cnt[a[position]]++;
	if(cnt[a[position]] == 1) {
		answer++;
	}
}

void remove(int position) {
	cnt[a[position]]--;
	if(cnt[a[position]] == 0) {
		answer--;
	}
}

int main() {
	int n;
	// scanf("%d", &n);
	n = readint();
	for(int i=0; i<n; i++) a[i] = readint();
		// scanf("%d", &a[i]);

	int m;
	// scanf("%d", &m);
	m = readint();
	for(int i=0; i<m; i++) {
		// scanf("%d%d", &q[i].L, &q[i].R);
		q[i].L = readint(), q[i].R = readint();
		q[i].L--; q[i].R--;
		q[i].i = i;
	}

	sort(q, q + m, cmp);

	int currentL = 0, currentR = 0;
	for(int i=0; i<m; i++) {
		int L = q[i].L, R = q[i].R;
		while(currentL < L) {
			remove(currentL);
			currentL++;
		}
		while(currentL > L) {
			add(currentL-1);
			currentL--;
		}
		while(currentR <= R) {
			add(currentR);
			currentR++;
		}
		while(currentR > R+1) {
			remove(currentR-1);
			currentR--;
		}
		ans[q[i].i] = answer;
	}

	for(int i=0; i<m; i++)
		printf("%d\n", ans[i]);
}