#include <bits/stdc++.h>
using namespace std;

int main() {
	int l, n;
	cin >> l >> n;
	if (n == 0) {
		cout << "0 0";
		return 0;
	}
	vector<int> data(n);
	for (int i = 0; i < n; i++) {
		cin >> data[i];
	}
	sort(data.begin(), data.end());
	int min_ans = 0, max_ans = 0;
	for (int i = 0; i < n; i++) {
		min_ans = max(min_ans, min(data[i], l + 1 - data[i]));
	}
	max_ans = max(l + 1 - data[0], data[n - 1]);

	cout << min_ans << " " << max_ans;
	return 0;
}
