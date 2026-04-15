#include <bits/stdc++.h>
using namespace std;

signed main() {
	int a, b, n;
	cin >> a >> b >> n;

	cout << 2 * ceil(((n - b) * 1.0 / (b - a))) + 1;
	return 0;
}
