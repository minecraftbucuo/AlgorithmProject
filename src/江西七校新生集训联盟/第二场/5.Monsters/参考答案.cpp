#include <bits/stdc++.h>
using namespace std;

signed main() {
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			a[i] %= k;
			if (a[i] == 0) a[i] = k;
		}
		vector<int> ans(n + 1);
		iota(ans.begin(), ans.end(), 0);
		sort(ans.begin() + 1, ans.end(), [&](int x, int y) {
			if (a[x] != a[y]) return a[x] > a[y];
			return x < y;
		});
		for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
		cout << endl;
	}
	return 0;
}
