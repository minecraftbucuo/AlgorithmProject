// 数据加强后将被卡
#include <cstdio>
#include <unordered_map>

signed main() {
	std::unordered_map<long long, int> mp;
	int n;
	long long x;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &x);
		mp[x]++;
	}
	for (auto p : mp) {
		if (p.second & 1) {
			printf("%lld", p.first);
			break;
		}
	}
	return 0;
}
