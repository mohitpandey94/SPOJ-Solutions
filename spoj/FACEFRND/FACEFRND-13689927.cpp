#include <bits/stdc++.h>

using namespace std;
set <int> s;

int main() {
	int n,id,m;
	scanf("%d",&n);
	int ids[n];
	for (int i=0; i < n; i++) {
		scanf("%d",&ids[i]);
		scanf("%d",&m);
		for (int j=0;j<m;j++) {
			scanf("%d",&id);
			s.insert(id);
		}
	}
	for (int i=0; i < n; i++) {
		s.erase(ids[i]);
	}
	printf("%d\n",s.size());
	return 0;
}