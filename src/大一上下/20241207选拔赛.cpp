//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	cout << "DBACCCACCA";
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int t, n;
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		if (n == 1) {
//			cout << "wdddd,zdhkk!" << endl;
//		} else if (n == 2) {
//			cout << "h!wcbpn!" << endl;
//		} else if (n == 3) {
//			cout << "wzcydd!" << endl;
//		} else if (n == 4) {
//			cout << "wo,hlhy!" << endl;
//		}
//	}
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//#define int long long
//
//bool cmp(int a, int b) {
//	return a > b;
//}
//
//signed main() {
//	int t, n;
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		n *= 2;
//		vector<int> a(n);
//		int sum = 0;
//		for (int i = 0; i < n; i++) {
//			cin >> a[i];
//			sum += a[i];
//		}
//		sort(a.begin(), a.end(), cmp);
//
//		int nai = a[0];
//		for (int i = 3; i <= n - 3; i += 4) {
//			nai += a[i] + a[i + 1];
//		}
//		if ((n / 2) % 2 == 0) {
//			nai += a.back();
//		}
//
//		cout << nai << endl;
//		if (2 * nai >= sum) {
//			cout << "YES" << endl;
//		} else {
//			cout << "NO" << endl;
//		}
//	}
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//#define int long long
//
//signed main() {
//	int n, q, l, r;
//	cin >> n >> q;
//	vector<int> a(n + 1);
//	vector<int> b(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		b[i] = b[i - 1] ^ a[i];
//	}
//	while (q--) {
//		cin >> l >> r;
//		int ans = b[r] ^ b[l - 1];
//		cout << ans << endl;
//	}
//
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//#define int long long
//
//bool is_prime(int x) {
//	if (x == 1) return false;
//	for (int i = 2; i * i <= x; i++) {
//		if (x % i == 0) return false;
//	}
//	return true;
//}
//
//signed main() {
//	int l, r;
//	cin >> l >> r;
//	int ans = 0;
//	for (int i = l; i <= r; i++) {
//		if (is_prime(i)) ans++;
//	}
//	cout << ans << endl;
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//#define int long long
//
//signed main() {
//	int n, q, l, r;
//	cin >> n >> q;
//	vector<int> a(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	while (q--) {
//		cin >> l >> r;
//		int ans = 0;
//		for (int i = l; i <= r; i++) {
//			ans = gcd(ans, a[i]);
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int t, n;
//	string s;
//	cin >> t;
//	while (t--) {
//		cin >> n >> s;
//		int a_count = 0;
//		int b_count = 0;
//		int ans = 0;
//		for (int i = 0; i < n; i++) {
//			if (s[i] == 'A') {
//				a_count++;
//				ans++;
//			} else {
//				if (a_count >= 1) {
//					a_count--;
//					ans--;
//				} else if (b_count >= 1) {
//					b_count--;
//					ans--;
//				} else if (a_count == 0 && b_count == 0) {
//					b_count++;
//					ans++;
//				}
//			}
//		}
//		cout << ans << endl;
//	}
//
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//using ll = long long;
//
//int main() {
//	ll n;
//	cin >> n;
//	if (n == 1) {
//		cout << "4.5" << endl;
//		return 0;
//	} else if (n == 2) {
//		cout << "7.0" << endl;
//		return 0;
//	} else if (n == 3) {
//		cout << "10.0" << endl;
//		return 0;
//	}
//	if (n % 3 == 0) {
//		ll ans = n / 3 * 10;
//		cout << ans << ".0" << endl;
//	} else if (n % 3 == 1) {
//		ll x = n / 3 - 1;
//		ll ans = x * 10 + 14;
//		cout << ans << ".0" << endl;
//	} else {
//		ll ans = n / 3 * 10 + 7;
//		cout << ans << ".0" << endl;
//	}
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int t, n, l;
//	cin >> t;
//	while (t--) {
//		cin >> n >> l;
//		vector<int> a(n);
//		for (int i = 0; i < n; i++) cin >> a[i];
//
//		int left = 0, right = 1e5;
//		while (left <= right) {
//			int mid = (left + right) >> 1;
//			int l_t = l;
//			int h = 0;
//
//			for (int i = 0; i < n; i++) {
//				if (a[i] >= mid) h++;
//				else if (a[i] + 1 >= mid && l_t > 0) {
//					h++;
//					l_t--;
//				}
//			}
//
//			if (h >= mid) {
//				left = mid + 1;
//			} else {
//				right = mid - 1;
//			}
//		}
//
//		cout << left - 1 << endl;
//	}
//	return 0;
//}


// 有问题
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		int ans1 = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] < 0) ans1 += a[i];
			else ans1 = abs(ans1 + a[i]);
		}

		cout << abs(ans1) << endl;
	}

	return 0;
}


//#include <bits/stdc++.h>
//using namespace std;
//
//int dx[] = {0, 0, 1, -1};
//int dy[] = {1, -1, 0, 0};
//
//struct pair_ {
//	int x;
//	int y;
//	int cen;
//};
//
//signed main() {
//	int n, m, a, b;
//	cin >> n >> m >> a >> b;
//	queue<pair_> q;
//	vector<vector<int>> vis(n + 1, vector<int>(m + 1, -1));
//	int is_gan = 0;
//	for (int i = 0; i < a; i++) {
//		int x, y;
//		cin >> x >> y;
//		vis[x][y] = 0;
//		q.push({x, y, 0});
//		is_gan++;
//	}
//	for (int i = 0; i < b; i++) {
//		int x, y;
//		cin >> x >> y;
//		vis[x][y] = 1;
//	}
//
//	int miao = 0;
//
//	while (!q.empty()) {
//		pair_ pos = q.front();
//		q.pop();
//		for (int i = 0; i < 4; i++) {
//			int x = pos.x + dx[i];
//			int y = pos.y + dy[i];
//
//			if (x < 1 || x > n || y < 1 || y > m) continue;
//
//			if (vis[x][y] == 1 || vis[x][y] == 0) continue;
//
//			int cen = pos.cen + 1;
//			miao = max(miao, cen);
//			vis[x][y] = 0;
//			q.push({x, y, cen});
//			is_gan++;
//		}
//	}
//
//	if (is_gan + b != n * m) cout << "ku ku (T_T)" << endl;
//	else {
//		cout << miao << endl;
//	}
//	return 0;
//}
