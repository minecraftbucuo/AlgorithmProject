// 温故而知新
// P1007 独木桥
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int l, n;
//	cin >> l >> n;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++) cin >> a[i];
//	int minn = 0, maxn = 0;
//	for (int i = 0; i < n; i++) {
//		minn = max(minn, min(l + 1 - a[i], a[i]));
//		maxn = max(maxn, max(l + 1 - a[i], a[i]));
//	}
//	cout << minn << ' ' << maxn << endl;
//	return 0;
//}


// P1012 [NOIP 1998 提高组] 拼数
//#include <bits/stdc++.h>
//using namespace std;
//
//bool cmp(string& s1, string& s2) {
//	return s1 + s2 > s2 + s1;
//}
//
//int main() {
//	int n;
//	cin >> n;
//	vector<string> a(n);
//	for (int i = 0; i < n; i++) cin >> a[i];
//	sort(a.begin(), a.end(), cmp);
//	for (int i = 0; i < n; i++) cout << a[i];
//	return 0;
//}


// P1019 [NOIP 2000 提高组] 单词接龙
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 21;
//vector<string> a(N);
//vector<int> vis(N);
//int n, ans;
//
//string add(string s1, string s2) {
//	int idx = -1;
//	for (unsigned i = 0; i < s1.size(); i++) {
//		if (s1[i] == s2[0]) {
//			if (s1.size() - i > s2.size()) continue;
//			int j = i;
//			for (; j < (int)s1.size(); j++) {
//				if (s1[j] != s2[j - i]) break;
//			}
//			if (j == (int)s1.size()) {
//				idx = i;
//			}
//		}
//	}
//	if (idx == -1) return "-1";
//	return s1.substr(0, idx) + s2;
//
////	int s_len = s2.size();
////	int r_len = s1.size();
////
////	int x = min(s_len, r_len);
////
////	for (int j = 1; j <= x; j++) {
////		string s1_(s1.end() - j, s1.end());
////		string s2_(s2.begin(), s2.begin() + j);
////		if (s1_ == s2_) {
////			return s1.substr(0, (int)s1.size() - j) + s2;
////		}
////	}
////	return "-1";
//}
//
//void dfs(char c, int deep, string s) {
//	if (deep == -1) {
//		ans = max(ans, (int)s.size());
//	} else {
//		if (deep == 0) {
//			for (int i = 0; i < n; i++) {
//				if (a[i][0] == c) {
//					vis[i]++;
//					dfs(c, deep + 1, s + a[i]);
//					vis[i]--;
//				}
//			}
//		} else {
//			int shibai = 0;
//			for (int i = 0; i < n; i++) {
//				string res = add(s, a[i]);
//				if (vis[i] < 2 && res != "-1") {
//					vis[i]++;
//					dfs(c, deep + 1, res);
//					vis[i]--;
//				} else {
//					shibai++;
//				}
//			}
//			if (shibai == n) dfs(c, -1, s);
//		}
//	}
//}
//
//int main() {
//	cin >> n;
//	for (int i = 0; i < n; i++) cin >> a[i];
//	char c;
//	cin >> c;
//	dfs(c, 0, "");
//	cout << ans << endl;
//	return 0;
//}


// P1020 [NOIP 1999 提高组] 导弹拦截   n^2做法
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	vector<int> a;
//	int x;
//	while (cin >> x) a.push_back(x);
//	int n = a.size();
//	vector<int> ans1(n, 1);
//	ans1[0] = 1;
//	for (int i = 1; i < n; i++) {
//		for (int j = i - 1; j >= 0; j--) {
//			if (a[i] <= a[j]) {
//				ans1[i] = max(ans1[i], ans1[j] + 1);
//			}
//		}
//	}
//
//	vector<int> ans2(n, 1);
//	ans2[0] = 1;
//	for (int i = 1; i < n; i++) {
//		for (int j = i - 1; j >= 0; j--) {
//			if (a[i] > a[j]) {
//				ans2[i] = max(ans2[i], ans2[j] + 1);
//			}
//		}
//	}
//
//	cout << *max_element(ans1.begin(), ans1.end()) << endl << *max_element(ans2.begin(), ans2.end());
//	return 0;
//}


// P1020 [NOIP 1999 提高组] 导弹拦截   nlogn做法
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	vector<int> x, y;
//	int n;
//	while (cin >> n) {
//		if (x.size() == 0) x.push_back(n);
//		else {
//			int l = 0, r = x.size() - 1;
//			while (l <= r) {
//				int mid = (l + r) / 2;
//				if (x[mid] >= n) l = mid + 1;
//				else r = mid - 1;
//			}
//			if (l == (int)x.size()) x.push_back(n);
//			else x[l] = n;
//		}
//
//		if (y.size() == 0) y.push_back(n);
//		else {
//			int l = 0, r = y.size() - 1;
//			while (l <= r) {
//				int mid = (l + r) / 2;
//				if (y[mid] < n) l = mid + 1;
//				else r = mid - 1;
//			}
//			if (l == (int)y.size()) y.push_back(n);
//			else y[l] = n;
//		}
//	}
//	cout << x.size() << endl << y.size();
//	return 0;
//}


// P1022 [NOIP 2000 普及组] 计算器的改良
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	string s;
//	cin >> s;
//	s = ' ' + s + ' ';
//	int n = s.size() - 1;
//	int t = 1;
//	int a = 0;
//	int b = 0;
//	char x;
//	for (int i = 1; i < n; i++) {
//		if (isdigit(s[i])) {
//			int f = 1;
//			if (s[i - 1] == '-') f = -1;
//			int j = i;
//			int temp = 0;
//			while (j < n && isdigit(s[j])) {
//				temp = 10 * temp + s[j] - '0';
//				j++;
//			}
//			temp *= f;
//			if (j < n && (('a' <= s[j] && s[j] <= 'z') || ('A' <= s[j] && s[j] <= 'Z'))) {
//				x = s[j];
//				a += t * temp;
//				j++;
//			} else {
//				b += -t * temp;
//			}
//
//			i = j - 1;
//		} else if (s[i] == '=') {
//			t *= -1;
//		} else if (('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z')) {
//			x = s[i];
//			a += t;
//		}
//	}
//	printf("%c=%.3lf", x, 1.0 * b / a);
//	return 0;
//}


// P1025 [NOIP 2001 提高组] 数的划分
//#include <bits/stdc++.h>
//using namespace std;
//
//int n, k, ans;
//
//void dfs(int deep, int start, int res) {
//	if (deep == k) {
//		ans++;
//	} else {
//		for (int i = start; i <= n - res; i++) {
//			if (deep + 1 < k || (deep + 1 == k && res + i == n))
//				dfs(deep + 1, i, res + i);
//		}
//	}
//}
//
//int main() {
//	cin >> n >> k;
//	dfs(0, 1, 0);
//	cout << ans << endl;
//	return 0;
//}


// A. MEXanized Array
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int t, n, k, x;
//	cin >> t;
//	while (t--) {
//		cin >> n >> k >> x;
//		if (x < k - 1 || n < k) cout << -1 << endl;
//		else {
//			int ans = 0;
//			for (int i = 0; i < k; i++) {
//				ans += i;
//			}
//			if (x == k) x--;
//			ans += (n - k) * x;
//			cout << ans << endl;
//		}
//	}
//	return 0;
//}


// A. Short Sort
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		string s;
//		cin >> s;
//		if (s[0] == 'a' || s[1] == 'b' || s[2] == 'c')
//			cout << "YES" << endl;
//		else
//			cout << "NO" << endl;
//	}
//	return 0;
//}


// B. Good Kid
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int n;
//		cin >> n;
//		vector<int> a(n);
//		for (int i = 0; i < n; i++) cin >> a[i];
//		sort(a.begin(), a.end());
//		a[0]++;
//		int ans = 1;
//		for (int i = 0; i < n; i++) ans *= a[i];
//		cout << ans << endl;
//	}
//	return 0;
//}


// C. Target Practice
//#include <bits/stdc++.h>
//using namespace std;
//
//int f(int x, int y) {
//	if (x == 0 || x == 9 || y == 0 || y == 9) return 1;
//	if (x == 1 || x == 8 || y == 1 || y == 8) return 2;
//	if (x == 2 || x == 7 || y == 2 || y == 7) return 3;
//	if (x == 3 || x == 6 || y == 3 || y == 6) return 4;
//	if (x == 4 || x == 5 || y == 4 || y == 5) return 5;
//	return -1;
//}
//
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int ans = 0;
//		vector<string> a(10);
//		for (int i = 0; i < 10; i++) cin >> a[i];
//		for (int x = 0; x < 10; x++) {
//			for (int y = 0; y < 10; y++) {
//				if (a[x][y] == 'X') ans += f(x, y);
//			}
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}


// B. Two Binary Strings
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		string s1, s2;
//		cin >> s1 >> s2;
//		bool is_yes = false;
//		for (int i = 0; i < (int)s1.size() - 1; i++) {
//			if (s1[i] == s2[i] && s1[i] == '0') {
//				if (s1[i + 1] == s2[i + 1] && s1[i + 1] == '1') {
//					is_yes = true;
//					break;
//				}
//			}
//		}
//		if (is_yes) cout << "YES" << endl;
//		else cout << "NO" << endl;
//	}
//	return 0;
//}


// B. Friendly Arrays
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int n, m;
//		cin >> n >> m;
//		vector<int> a(n), b(m);
//		for (int i = 0; i < n; i++) cin >> a[i];
//		for (int i = 0; i < m; i++) cin >> b[i];
//		int maxn = 0;
//		for (int i = 0; i < n; i++) maxn ^= a[i];
//		int huo = b[0];
//		for (int i = 1; i < m; i++) huo |= b[i];
//		int minn = 0;
//		for (int i = 0; i < n; i++) minn ^= (huo | a[i]);
//		cout << min(minn, maxn) << ' ' << max(minn, maxn) << endl;
//	}
//	return 0;
//}

