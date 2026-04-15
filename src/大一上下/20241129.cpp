//教

//#include <bits/stdc++.h>
//using namespace std;
//
//int fen(int i, int j) {
//	if (i == 1 || i == 10 || j == 1 || j == 10) return 1;
//	if (i == 2 || i == 9 || j == 2 || j == 9) return 2;
//	if (i == 3 || i == 8 || j == 3 || j == 8) return 3;
//	if (i == 4 || i == 7 || j == 4 || j == 7) return 4;
//	if (i == 5 || i == 6 || j == 5 || j == 6) return 5;
//
//	return 0;
//}
//
//int main() {
//	int t;
//	cin >> t;
//	vector<string> s(15);
//	while (t--) {
//		for (int i = 0; i < 10; i++) {
//			cin >> s[i];
//		}
//
//		int ans = 0;
//		for (int i = 0; i < 10; i++) {
//			for (int j = 0; j < 10; j++) {
//				if (s[i][j] == 'X') {
//					ans += fen(i + 1, j + 1);
//				}
//			}
//		}
//
//		cout << ans << endl;
//	}
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int t, n, k;
//	string s;
//	cin >> t;
//	while (t--) {
//		cin >> n >> k;
//		cin >> s;
//		int ans = 0;
//		for (int i = 0; i < (int)s.length(); i++) {
//			if (s[i] == 'B') {
//				ans++;
//				i += k - 1;
//			}
//		}
//
//		cout << ans << endl;
//	}
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//
//bool is_prime(int x) {
//	for (int i = 2; i * i <= x; i++) {
//		if (x % i == 0) return false;
//	}
//	return true;
//}
//
//int main() {
//	int t, l, r;
//	cin >> t;
//	while (t--) {
//		cin >> l >> r;
//		if (l == r) {
//			if (is_prime(r)) {
//				cout << -1 << endl;
//			} else {
//				int i;
//				for (i = 2; i <= r - 1; i++) {
//					if (r % i == 0) break;
//				}
//				int j = r / i;
//
//				cout << j << ' ' << (i - 1) * j << endl;
//			}
//		} else {
//			if (r <= 3) {
//				cout << -1 << endl;
//				continue;
//			}
//
//			if (r % 2 == 0) { // r为偶数
//				cout << r / 2 << ' ' << r / 2 << endl;
//			} else { // r - 1 是偶数
//				cout << (r - 1) / 2 << ' ' << (r - 1) / 2 << endl;
//			}
//		}
//	}
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int t, n, m;
//	string s1, s2;
//	cin >> t;
//	while (t--) {
//		cin >> n >> m;
//		cin >> s1 >> s2;
//		if (s1 == s2) {
//			cout << 0 << endl;
//			continue;
//		}
//
//		if (n >= m) {
//			if (s1.find(s2) != string::npos) {
//				cout << 0 << endl;
//				continue;
//			}
//
//			s1 += s1;
//			if (s1.find(s2) != string::npos) {
//				cout << 1 << endl;
//			} else {
//				cout << -1 << endl;
//			}
//		} else {
//			int ans = 0;
//			while (s1.length() < s2.length()) {
//				s1 += s1;
//				ans++;
//			}
//			if (s1.find(s2) != string::npos) {
//				cout << ans << endl;
//			} else {
//				s1 += s1;
//				ans++;
//				if (s1.find(s2) != string::npos) {
//					cout << ans << endl;
//				} else {
//					cout << -1 << endl;
//				}
//			}
//		}
//	}
//	return 0;
//}


//P1003 [NOIP2011 提高组] 铺地毯
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<vector<int>> a(n + 1, vector<int>(4));
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
//	}
//
//	int x, y;
//	cin >> x >> y;
//	int i;
//	for (i = n; i >= 1; i--) {
//		if (x >= a[i][0] && x <= a[i][0] + a[i][2] && y >= a[i][1] && y <= a[i][1] + a[i][3]) {
//			cout << i << endl;
//			break;
//		}
//	}
//	if (i == 0) {
//		cout << -1 << endl;
//	}
//
//	return 0;
//}

