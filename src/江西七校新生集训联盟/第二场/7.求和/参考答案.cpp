#include <bits/stdc++.h>
#define int long long
using namespace std;

int f(int x) {
	return x * (x + 1) / 2;
}

signed main() {
	int n, m;
	cin >> n >> m;
	int sum = f(n);
	int ans = 0;
	for (int j = m; j <= n; j *= m) {
		int he = sum - n / j * f(j - 1) - f(n % j);
		ans += he / j;
	}
	cout << ans << endl;
	return 0;
}
