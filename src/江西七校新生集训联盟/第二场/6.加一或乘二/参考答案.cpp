#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

signed main() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	int ans = 2;
	for (int i = 2; i <= n; i++) {
		if (a[i] > a[i - 1]) ans = 2 * ans % mod;
		else ans = (ans + 1) % mod;
	}
	cout << ans << endl;
	return 0;
}
