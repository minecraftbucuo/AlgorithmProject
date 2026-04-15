#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
//2024 10 9 0:27完成
int main() {
	int k, n;
	cin >> k >> n;
	vector<int> vec;
	while (n != 0) {
		vec.push_back(n % 2);
		n /= 2;
	}
	long long ans = 0;
	for (int i = 0; i < vec.size(); i++) {
		ans += vec[i] * (long long)pow(k, i);
	}
	cout << ans;

	return 0;
}
