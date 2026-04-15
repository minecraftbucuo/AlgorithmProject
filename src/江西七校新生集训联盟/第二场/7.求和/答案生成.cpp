#include <bits/stdc++.h>
#include <fstream>
#define int long long
using namespace std;

int f(int x) {
	return x * (x + 1) / 2;
}

signed main() {
	int T = 12;
	for (int i = 1; i <= T; i++) {
		string in_name = "./test_data/" + to_string(i) + ".in";
		string out_name = "./test_data/" + to_string(i) + ".out";
		ifstream in(in_name);
		ofstream out(out_name);
		int n, m;
		in >> n >> m;
		int sum = f(n);
		int ans = 0;
		for (int j = m; j <= n; j *= m) {
			int he = sum - n / j * f(j - 1) - f(n % j);
			ans += he / j;
		}
		out << ans << endl;
	}
	return 0;
}
