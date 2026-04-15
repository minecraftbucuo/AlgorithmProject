#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	int cnt_t = 1;
	for (int t = 1; t <= cnt_t; t++) {
		string in_name = to_string(t) + ".in";
		string out_name = to_string(t) + ".out";
		ifstream in(in_name);
		ofstream out(out_name);
		int n;
		in >> n;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int x;
			in >> x;
			ans = ans ^ x;
		}
		out << ans << endl;
		out.close();
	}
	return 0;
}
