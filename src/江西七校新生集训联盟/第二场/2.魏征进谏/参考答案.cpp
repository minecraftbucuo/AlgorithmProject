#include <bits/stdc++.h>
using namespace std;

struct node {
	string a, b;
};

signed main() {
	int n;
	cin >> n;
	vector<node> a(n);
	unordered_map<string, int> mpa = {{"High", 2}, {"Medium", 1}, {"Low", 0}};
	unordered_map<string, int> mpb = {{"Military", 3}, {"Livelihood", 2}, {"Governance", 1}, {"PersonalCultivation", 0}};
	for (int i = 0; i < n; i++) {
		cin >> a[i].a >> a[i].b;
	}
	sort(a.begin(), a.end(), [&](node& x, node& y) {
		if (mpa[x.a] != mpa[y.a]) return mpa[x.a] > mpa[y.a];
		return mpb[x.b] > mpb[y.b];
	});
	for (int i = 0; i < n; i++) {
		cout << a[i].a << ' ' << a[i].b << endl;
	}
	return 0;
}
