#include <bits/stdc++.h>
#include <fstream>
using namespace std;

const int N = 10;

int n, a[N], vis[N];

void dfs(int deep, ofstream& out) {
	if (deep == n) {
		for (int i = 0; i < n; i++) out << a[i] << ' ';
		out << endl;
		return;
	}
	for (int i = n; i >= 1; i--) {
		if (!vis[i]) {
			vis[i] = 1;
			a[deep] = i;
			dfs(deep + 1, out);
			vis[i] = 0;
		}
	}
}

signed main() {
	int T = 8;
	for (int i = 1; i <= T; i++) {
		string in_name = "./test_data/" + to_string(i) + ".in";
		string out_name = "./test_data/" + to_string(i) + ".out";
		ifstream in(in_name);
		ofstream out(out_name);
		in >> n;
		dfs(0, out);
	}
	return 0;
}
