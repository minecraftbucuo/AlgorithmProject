#include<bits/stdc++.h>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	vector<int> ans;
	if (a < 2) {
		ans.push_back(2);
	}
	while (ans.size() != b) {
		for (int i = 2; i < a; i++) {
			if (a % i == 0) {
				break;
			}

			if (i == a - 1) {
				ans.push_back(a);
			}
		}

		a++;
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	return 0;
}
