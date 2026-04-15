#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, x, ans = 0;
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		int num = i;
		while (num != 0) {
			if (num % 10 == x) ans++;
			num /= 10;
		}
	}

	cout << ans;
	return 0;
}
