//#include <iostream>
//using namespace std;
// 算法没问题 但会TLE 2024 10 9 22:24
//int ans(int n) {
//	if (n == 1)
//		return 1;
//	else {
//		int sum = 0;
//		for (int i = 1; i <= n / 2; i++) {
//			sum += ans(i);
//		}
//		return sum + 1;
//	}
//}
//
//int main() {
//	int n;
//	cin >> n;
//	cout << ans(n);
//
//	return 0;
//}


// 2024 10 9 22:44 改进后没有TLE了
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> ans(n + 1);
	vector<int> sum(n + 1);
	ans[1] = 1;
	sum[1] = 1;
	for (int i = 2; i <= n; i++) {
		ans[i] = 1 + sum[i / 2];
		sum[i] = sum[i - 1] + ans[i];
	}

	cout << ans[n];
	return 0;
}
