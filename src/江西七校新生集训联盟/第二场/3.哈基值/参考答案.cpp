#include <bits/stdc++.h>
using namespace std;

signed main() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	int mx = a[n];
	long long ans = a[n];
	for (int i = n - 1; i >= 1; i--) {
		ans += a[i] * (mx > a[i] ? -1 : 1);
		mx = max(mx, a[i]);
	}
	cout << ans << endl;
	return 0;
}
