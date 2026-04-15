#include <iostream>
using namespace std;
const int N = 10;

int n, a[N], vis[N];

void dfs(int deep) {
	if (deep == n) {
		for (int i = 0; i < n; i++) cout << a[i] << ' ';
		cout << endl;
		return;
	}
	for (int i = n; i >= 1; i--) {
		if (!vis[i]) {
			vis[i] = 1;
			a[deep] = i;
			dfs(deep + 1);
			vis[i] = 0;
		}
	}
}

int main() {
	cin >> n;
	dfs(0);
	return 0;
}
