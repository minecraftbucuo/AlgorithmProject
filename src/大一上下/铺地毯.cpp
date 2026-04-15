#include <iostream>
#include <vector>
using namespace std;

//2024 10 9 19:24

bool is_in(int x, int y, vector<int> vec) {
	if (vec[0] <= x && x <= vec[0] + vec[2]) {
		if (vec[1] <= y && y <= vec[1] + vec[3]) {
			return true;
		}
	}
	return false;
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> vec(n, vector<int>(4));
	for (int i = 0; i < n; i++) {
		cin >> vec[i][0] >> vec[i][1] >> vec[i][2] >> vec[i][3];
	}
	int x, y;
	cin >> x >> y;

	bool have_ans = false;
	for (int i = n - 1; i >= 0; i--) {
		if (is_in(x, y, vec[i])) {
			cout << i + 1;
			have_ans = true;
			break;
		}
	}

	if (!have_ans) {
		cout << -1;
	}
	return 0;
}
