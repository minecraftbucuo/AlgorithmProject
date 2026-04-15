#include <iostream>
using namespace std;

// 2024 10 9 13:37

int ans[12][12][12][12];
int num[12][12];
int n, x, y, z;

int main() {
	cin >> n >> x >> y >> z;
	while (x != 0 || y != 0 || z != 0) {
		num[x][y] = z;
		cin >> x >> y >> z;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				for (int l = 1; l <= n; l++) {
					ans[i][j][k][l] = max(max(ans[i - 1][j][k - 1][l], ans[i - 1][j][k][l - 1]), max(ans[i][j - 1][k - 1][l], ans[i][j - 1][k][l - 1])) + num[i][j] + num[k][l];
					if (i == k && j == l) {
						ans[i][j][k][l] -= num[i][j];
					}
				}
			}
		}
	}

	cout << ans[n][n][n][n];
	return 0;
}
