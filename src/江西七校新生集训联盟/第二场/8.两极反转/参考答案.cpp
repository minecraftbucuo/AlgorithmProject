//#include <bits/stdc++.h>
//using namespace std;
//const int N = 2e5+5;
//#define int long long
//int ca[N];
//int cnt[N];
//int ans[N];
//int cal(int x) {
//	int res = 0;
//	for (int i = 0; i < 32; i++) {
//		int j = i;
//		while (j < 32 && (x >> i & 1) == (x >> j & 1))j++;
//		res++;
//		i = j - 1;
//	}
//	return res;
//}
//void solve() {
//	int n, q;
//	cin >> n >> q;
//
//	for (int i = 1; i <= n; i++)cin >> ca[i];
//	for (int i = 1; i <= n; i++)cnt[i] = cal(ca[i]);
//
//	for (int i = 2; i <= n; i++) {
//		ans[i] = ans[i - 1];
//		ans[i] += cnt[i] != cnt[i - 1];
//	}
//
//	while (q--) {
//		int l, r;
//		cin >> l >> r;
//		int res = ans[r] - ans[l];
//		if (res)cout << "No" << endl;
//		else cout << "Yes" << endl;
//	}
//}
//signed main() {
//	solve();
//	return 0;
//}

#include <bits/stdc++.h>
using namespace std;
#define int unsigned

signed main() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	vector<int> l(n + 1);
	l[1] = 1;
	auto keyi = [](int x, int y) -> bool {
		if (x >> 31 & 1) x = ~x;
		if (y >> 31 & 1) y = ~y;
		if ((x & 1) != (y & 1)) return false;
		vector<int> a, b;
		a.push_back(0), b.push_back(0);
		for (signed i = 31; i >= 0; i--) {
			if (a.back() != (x >> i & 1)) a.push_back(x >> i & 1);
			if (b.back() != (y >> i & 1)) b.push_back(y >> i & 1);
		}
		int ac = 0, bc = 0;
		for (int i : a) ac += i;
		for (int i : b) bc += i;
		return ac == bc;
	};
	for (int i = 2; i <= n; i++) {
		if (keyi(a[i], a[i - 1])) l[i] = l[i - 1];
		else l[i] = i;
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		if (x < l[y]) cout << "No" << endl;
		else cout << "Yes" << endl;
	}
	return 0;
}
