#include <iostream>
#include <cstdio>
#include <list>
#include <vector>
#include <queue>

using namespace std;

vector <int> v[2005];
vector <int> temp;
vector <int>::iterator p;
int color[2005];
int n, m;

bool find() {
	int i;
	int x;
	queue<int> q;
	for (i = 0; i <= n; i++) {
		color[i] = -1;
	}

	for (i = 1; i <= n; i++) {
		if (color[i] == -1) {
			color[i] = 1;

			q.push(i);

			while (!q.empty()) {
				x = q.front();
				q.pop();
				
				p = v[x].begin();

				for ( ;p != v[x].end(); ++p) {
					if (color[*p] == -1) {
						color[*p] = 1 - color[x];
						q.push(*p);
					}	
					else if (color[*p] == color[x]) {
						return false;
					}
				}
				
			}
		}
	}
	return true;
}
void print(){
	cout <<endl;
	for(int i = 0; i <= n; i++){
		cout << i  << endl;
		for(int j = 0; j < v[i].size(); j++)
			cout << v[i][j] << " ";
		cout << endl;
	}
}
int main () {
	int t, i, a, b, r = 1;
	cin >> t;
	while (t--) {
		for(i = 0; i < 2005; i++)
			v[i].clear();
		scanf("%d%d", &n, &m);
		for (i = 0; i < m; i++) {
			scanf("%d%d", &a, &b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
//		print();
		printf("Scenario #%d:\n", r);
		r++;

		if (find() == false) {
			printf("Suspicious bugs found!\n");
		} else {
			printf("No suspicious bugs found!\n");
		}
	}
}
