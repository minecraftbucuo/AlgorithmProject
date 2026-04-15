#include <bits/stdc++.h>
#include <fstream>
using namespace std;

struct node {
	string a, b;
};

signed main() {
	int T = 6;
	for (int i = 1; i <= T; i++) {
		string in_name = "./test_data/" + to_string(i) + ".in";
		string out_name = "./test_data/" + to_string(i) + ".out";
		ifstream in(in_name);
		ofstream out(out_name);
		int n;
		in >> n;
		vector<node> a(n);
		unordered_map<string, int> mpa = {{"High", 2}, {"Medium", 1}, {"Low", 0}};
		unordered_map<string, int> mpb = {{"Military", 3}, {"Livelihood", 2}, {"Governance", 1}, {"PersonalCultivation", 0}};
		for (int i = 0; i < n; i++) {
			in >> a[i].a >> a[i].b;
		}
		sort(a.begin(), a.end(), [&](node& x, node& y) {
			if (mpa[x.a] != mpa[y.a]) return mpa[x.a] > mpa[y.a];
			return mpb[x.b] > mpb[y.b];
		});
		for (int i = 0; i < n; i++) {
			out << a[i].a << ' ' << a[i].b << endl;
		}
	}
	return 0;
}
