#include <bits/stdc++.h>
using namespace std;

int determinant(int n, vector<vector<int>>& det) {
	if (n == 1) {
		return det[0][0];
	}
	vector<vector<int>> vec(n - 1, vector<int>(n - 1));
	int sign = 1;
	int sum = 0;
	for (int i = 0; i < n; i++, sign *= -1) {
		int x_ = 0;
		for (int x = 0; x < n; x++) {
			if (x == i) continue;
			int y_ = 0;
			for (int y = 1; y < n; y++) {
				vec[y_][x_] = det[y][x];
				y_++;
			}
			x_++;
		}
		sum += sign * det[0][i] * determinant(n - 1, vec);
	}

	return sum;

}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> vec(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> vec[i][j];
		}
	}

	cout << determinant(n, vec) << endl;

	return 0;
}
