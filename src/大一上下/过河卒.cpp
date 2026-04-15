#include <iostream>
#include <vector>
using namespace std;

// 2024 10 8

bool is_safe(int x, int y, int c, int d) {
	if (x == c && y == d) {
		return false;
	}
	if (x == c - 1 || x == c + 1) {
		if (y == d + 2 || y == d - 2) {
			return false;
		}
	} else if (x == c - 2 || x == c + 2) {
		if (y == d + 1 || y == d - 1) {
			return false;
		}
	}

	return true;
}

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	vector<vector<long long>> vec(b + 1, vector<long long>(a + 1));
	vec[0][0] = 1;
	for (int i = 1; i < a + 1; i++) {
		if (is_safe(i, 0, c, d))
			vec[0][i] = vec[0][i - 1];
		else
			vec[0][i] = 0;
	}
	for (int i = 1; i < b + 1; i++) {
		if (is_safe(0, i, c, d))
			vec[i][0] = vec[i - 1][0];
		else
			vec[i][0] = 0;
	}

	for (int y = 1; y < b + 1; y++) {
		for (int x = 1; x < a + 1; x++) {
			if (is_safe(x, y, c, d))
				vec[y][x] = vec[y][x - 1] + vec[y - 1][x];
			else
				vec[y][x] = 0;
		}
	}

	cout << vec[b][a];

	return 0;
}
