#include <bits/stdc++.h>
using namespace std;

int a[12];
bitset<12> bit;

void dfs(int dep, int n) {
	if (dep == n + 1) {
		for (int i = 1; i <= n; i++) {
			printf("%5d", a[i]);
		}
		printf("\n");
		return;
	}

	else {
		for (int i = 1; i <= n; i++) {
			if (bit[i]) continue;
			bit[i] = true;
			a[dep] = i;
			dfs(dep + 1, n);
			bit[i] = false;
		}
	}
}

int main() {
	int n;
	cin >> n;
	dfs(1, n);
	return 0;
}
