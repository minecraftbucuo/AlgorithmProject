// 2024.10.5

#include<bits/stdc++.h>
using namespace std;

bool is_hui(int x, int jin) {
	int n = 0;
	int x_c = x;
	while (x_c != 0) {
		int ge = x_c % jin;
		x_c /= jin;
		n += ge;
		n *= jin;
	}
	n /= jin;

	return x == n;
}

int trans(int x, int jin) {
	int n = 0;
	int x_c = x;
	while (x_c != 0) {
		int ge = x_c % jin;
		x_c /= jin;
		n += ge;
		n *= jin;
	}
	n /= jin;

	return x + n;
}

int main() {
	int n, m;
	cin >> n >> m;
	int ans = 0;
	while (!is_hui(m, n)) {
		m = trans(m, n);
		ans++;
		if (ans >= 30) {
			cout << "Impossible!";
			return 0;
		}
	}
	cout << "STEP=" << ans;
	return 0;
}
