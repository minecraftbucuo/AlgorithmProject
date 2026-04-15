#include <fstream>
#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long

int randint(int l, int r) {
	if (r < l) return 0;
	return (rand() * rand() % (r - l + 1)) + l;
}

signed main() {
	srand(time(0));
	int cnt = 5;
	for (int t = 1; t <= cnt; t++) {
		int n = randint(1e5, 1e7);
		if (!(n & 1)) n--;
		string name = to_string(t) + ".in";
		string ans_name = to_string(t) + ".ans";
		ofstream out(name);
		ofstream ans_out(ans_name);
		out << n << endl;
		vector<int> a(n + 1);
		int ans = randint(1, 1e9) * randint(1, 1e9);
		ans_out << ans;
		int ans_cnt = randint(1, n);
		if (!(ans_cnt & 1)) ans_cnt++;
		for (int i = 1; i <= ans_cnt; i++) a[i] = ans;
		int idx = ans_cnt + 1;
		int n_ = n;
		n -= ans_cnt;
		while (n != 0) {
			int cnt_ = randint(1, n);
			int x = randint(1, 1e9) * randint(1, 1e9);
			if (cnt_ == 0) break;
			if (cnt_ & 1) cnt_++;
			n -= cnt_;
			for (int i = 1; i <= cnt_; i++) a[idx++] = x;
		}
		sort(a.begin() + 1, a.end(), [&](int x, int y) {
			return randint(0, 1);
		});
		for (int i = 1; i <= n_; i++) out << a[i] << ' ';
		out.close();
		ans_out.close();
	}
	return 0;
}
