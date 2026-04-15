#include <cstdio>
using namespace std;

signed main() {
	int n;
	scanf("%d", &n);
	long long ans = 0, x;
	while (n--) {
		scanf("%lld", &x);
		ans ^= x;
	}
	printf("%lld", ans);
	return 0;
}
