#include <iostream>
#include <vector>
using namespace std;
const int mod = 1e9 + 7;

signed main() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	a[0] = 1, a[1] = 2, a[2] = 4;
	for (int i = 3; i <= n; i++) a[i] = ((a[i - 1] + a[i - 2]) % mod + a[i - 3]) % mod;
	cout << a[n] << endl;
	return 0;
}
