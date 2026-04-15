// https://codeforces.com/problemset/problem/2047/A?csrf_token=061ab56460a7ac8598586bb094006ce9

// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//	int t, n;
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		vector<int> a(n);
//		for (int i = 0; i < n; i++) cin >> a[i];
//		int ans = 0;
//		int sum = 0;
//		for (int i = 0; i < n; i++) {
//			sum += a[i];
//			int sq = (int)sqrt(sum);
//			if (sq * sq == sum && sq % 2 == 1) ans++;
//		}
//		cout << ans << endl;
//	}
//	return 0;
// }

// https://codeforces.com/problemset/problem/2050/C
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//	int t;
//	cin >> t;
//	string s;
//	while (t--) {
//		cin >> s;
//		int sum = 0, two_cnt = 0, three_cnt = 0;
//		for (int i = 0; i < (int)s.size(); i++) {
//			sum += s[i] - '0';
//			if (s[i] == '2') two_cnt++;
//			if (s[i] == '3') three_cnt++;
//		}
//		bool is_yes = false;
//		for (int i = 0; i <= 8 && i <= two_cnt; i++) {
//			for (int j = 0; j <= 8 && j <= three_cnt; j++) {
//				if ((sum + i * 2 + 6 * j) % 9 == 0) {
//					is_yes = true;
//					break;
//				}
//			}
//		}
//
//		if (is_yes) cout << "YES" << endl;
//		else cout << "NO" << endl;
//	}
//	return 0;
// }

// https://codeforces.com/problemset/problem/2045/B 未通过（20241228）
// 现在是20241229 1：30 我经过深入思考最终通过了！感谢能给出测试集！
// #include <bits/stdc++.h>
// using namespace std;
//
// #define int long long
//
// signed main() {
//	int n, d, s;
//	cin >> n >> d >> s;
//	n = n / s;
//	d = d / s;
//	int ans = min(2 * d, n);
//	if (ans & 1) {
//		bool have_ans = false;
//		for (int i = 1; i * i <= ans; i++) {
//			if (ans % i == 0 && ans - ans / i <= d && ans / i - 1 <= d) {
//				cout << s * ans << endl;
//				have_ans = true;
//				break;
//			}
//		}
//		if (!have_ans) {
//			cout << s * (ans - 1) << endl;
//		}
//	} else cout << max(s * ans, s) << endl;
//	return 0;
// }

// https://codeforces.com/problemset/problem/2050/D
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//	int t;
//	cin >> t;
//	string s;
//	while (t--) {
//		cin >> s;
//		int l = 0;
//		while (l < (int)s.size()) {
//			if (s[l + 1] == '0') {
//				l++;
//				continue;
//			}
//			if (s[l + 1] - 1 > s[l]) {
//				s[l + 1]--;
//				swap(s[l + 1], s[l]);
//				l = max(0, l - 1);
//			} else l++;
//		}
//		cout << s << endl;
//	}
//	return 0;
// }

// https://codeforces.com/problemset/problem/2044/E
// #include <bits/stdc++.h>
// using namespace std;
//
// #define int long long
//
// signed main() {
//	int t, k, l1, r1, l2, r2;
//	cin >> t;
//	while (t--) {
//		cin >> k >> l1 >> r1 >> l2 >> r2;
//		int kn = 1;
//		int ans = 0;
//		for (; r2 / kn >= l1; ) {
//			ans += max(0LL, min(r2 / kn, r1) - max((l2 + kn - 1) / kn, l1) + 1);
//			kn *= k;
//		}
//		cout << ans << endl;
//	}
//	return 0;
// }

// https://codeforces.com/problemset/problem/1999/A
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//	int t, n;
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		cout << n % 10 + n / 10 << endl;
//	}
//	return 0;
// }

// https://codeforces.com/problemset/problem/2041/E
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//	int a, b;
//	cin >> a >> b;
//	cout << 3 << endl;
//	cout << -10000 << ' ' << b << ' ' << 3 * a + 10000 - b << endl;
//	return 0;
// }

// https://codeforces.com/problemset/problem/2046/B
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//	int t, n;
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		vector<int> a(n);
//		for (int i = 0; i < n; i++) cin >> a[i];
//		vector<int> b(a.begin(), a.end());
//		sort(b.begin(), b.end());
//		int start = 0;
//		int left = 0, right = 0;
//		int end_i = 0;
//		vector<int> temp;
//		while (right < n) {
//			if (a[right] == b[left]) {
//				cout << a[right] << ' ';
//				left++;
//				for (int i = start; i < right; i++) {
//					temp.push_back(a[i] + 1);
//				}
//				end_i = right;
//
//				start = right + 1;
//			}
//			right++;
//		}
//
//		if (left >= n - 1) {
//			if (temp.empty()) {
//				cout << endl;
//				continue;
//			}
//			sort(temp.begin(), temp.end());
//			for (int i : temp) {
//				cout << i << ' ';
//			}
//			cout << endl;
//			continue;
//		}
//
//		int min_ele = *min_element(temp.begin(), temp.end());
//
//		for (int i = end_i + 1; i < n; i++) {
//			if (a[i] <= min_ele) {
//				cout << a[i] << ' ';
//			} else {
//				temp.push_back(a[i] + 1);
//			}
//		}
//
//		sort(temp.begin(), temp.end());
//		for (int i : temp) {
//			cout << i << ' ';
//		}
//		cout << endl;
//
//	}
//	return 0;
// }

// https://codeforces.com/problemset/problem/2050/E   20250108 动态规划
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//	int t;
//	string a, b, c;
//	cin >> t;
//	while (t--) {
//		cin >> a >> b >> c;
//		int a_s = a.size(), b_s = b.size();
//		vector<vector<int>> dp(a_s + 1, vector<int>(b_s + 1, INT32_MAX));
//		dp[0][0] = 0;
//		for (int i = 1; i <= a_s; i++) {
//			dp[i][0] = dp[i - 1][0] + (c[i - 1] != a[i - 1]);
//		}
//
//		for (int i = 1; i <= b_s; i++) {
//			dp[0][i] = dp[0][i - 1] + (c[i - 1] != b[i - 1]);
//		}
//
//		for (int i = 1; i <= a_s; i++) {
//			for (int j = 1; j <= b_s; j++) {
//				dp[i][j] = min(dp[i - 1][j] + (a[i - 1] != c[i + j - 1]), dp[i][j - 1] + (b[j - 1] != c[i + j - 1]));
//			}
//		}
//
//		cout << dp[a_s][b_s] << endl;
//	}
//	return 0;
// }

// https://codeforces.com/contest/2050/problem/A
// #include<bits/stdc++.h>
// using namespace std;
//
// int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int n, m;
//		cin >> n >> m;
//		string s;
//		int sum = 0, ans = 0;
//		while (n--) {
//			cin >> s;
//			sum += s.size();
//			if (sum <= m) ans++;
//		}
//		cout << ans << endl;
//	}
//	return 0;
// }

// https://codeforces.com/contest/2050/problem/B
// #include <bits/stdc++.h>
// using namespace std;
//
// #define int long long
//
// signed main() {
//	int t, n;
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		vector<int> a(n);
//		for (int i = 0; i < n; i++) cin >> a[i];
//		int sum = 0;
//		for (int i : a) sum += i;
//		if (sum % n != 0) {
//			cout << "NO" << endl;
//			continue;
//		}
//		sum /= n;
//		for (int i = 1; i <= n - 2; i++) {
//			a[i + 1] += a[i - 1] - sum;
//		}
//
//		if (a[n - 2] == a[n - 1] && a[n - 1] == sum) {
//			cout << "YES" << endl;
//		} else cout << "NO" << endl;
//	}
//	return 0;
// }

// https://codeforces.com/contest/2050/problem/F   ST表
// #include <bits/stdc++.h>
// using namespace std;
//
// int Log2(int a) {
//	return (int)log2(a);
// }
//
// int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int n, q;
//		cin >> n >> q;
//		vector<int> a(n + 1);
//		for (int i = 1; i <= n; i++) cin >> a[i];
//		int log2n = Log2(n);
//		vector<vector<int>> st(n + 1, vector<int>(log2n + 1));
//		for (int i = 1; i < n; i++) st[i][0] = abs(a[i] - a[i + 1]);
//		n--;
//		for (int i = 1; i <= log2n; i++) {
//			for (int j = 1; j + (1 << i) - 1 <= n; j++) {
//				st[j][i] = gcd(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
//			}
//		}
//		while (q--) {
//			int l, r;
//			cin >> l >> r;
//			if (l == r) {
//				cout << 0 << ' ';
//				continue;
//			}
//			r--;
//			int q_ = Log2(r - l + 1);
//			cout << gcd(st[l][q_], st[r - (1 << q_) + 1][q_]) << ' ';
//		}
//		cout << endl;
//	}
//	return 0;
// }

// https://codeforces.com/problemset/problem/2031/C
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//	int t, n;
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		if (n & 1) {
//			if (n <= 25) cout << -1 << endl;
//			else {
//				vector<int> a(n + 10);
//				a[1] = 1;
//				a[10] = 1;
//				a[26] = 1;
//				int i, j;
//				for (j = 2, i = 27; i - 16 <= 25 && i <= n; i++, j++) {
//					a[i] = j;
//					a[i - 16] = j;
//				}
//				for (int k = 2; k <= n - 1; k++) {
//					if (a[k] == 0) {
//						a[k] = j;
//						a[k + 1] = j;
//						j++;
//					}
//				}
//
//				for (int p = 1; p <= n; p++) cout << a[p] << ' ';
//				cout << endl;
//			}
//		} else {
//			for (int i = 1; i <= n / 2; i++) {
//				cout << i << ' ' << i << ' ';
//			}
//			cout << endl;
//		}
//	}
//	return 0;
// }

// https://codeforces.com/contest/2000/problem/E
//  你妈的，做了半天！
// #include <bits/stdc++.h>
// using namespace std;
//
// #define int long long
//
// int min(int a, int b, int c) {
//	return min(a, min(b, c));
// }
//
// signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int n, m, k, w;
//		cin >> n >> m >> k >> w;
//		vector<int> a(w);
//		for (int i = 0; i < w; i++) cin >> a[i];
//		sort(a.begin(), a.end());
//		vector<int> b;
//		vector<vector<int>> ma(n + 1, vector<int>(m + 1));
//
//		int hen_min = m - k + 1;
//		int lie_min = n - k + 1;
//
//		for (int i = 1, tian = 1; i <= (n + 1) / 2; i++) {
//			for (int j = 1; j <= (m + 1) / 2; j++) {
//				if (i == 1) {
//					ma[i][j] = min(tian, k, hen_min);
//					ma[i][m + 1 - j] = min(tian, k, hen_min);
//					ma[n + 1 - i][j] = min(tian, k, hen_min);
//					ma[n + 1 - i][m + 1 - j] = min(tian, k, hen_min);
//					tian++;
//				} else {
//					tian = min(min(i, lie_min) * ma[1][j], ma[1][j] * k, min(i, k) * k);
//					ma[i][j] = tian;
//					ma[i][m + 1 - j] = tian;
//					ma[n + 1 - i][j] = tian;
//					ma[n + 1 - i][m + 1 - j] = tian;
//				}
//			}
//		}
//
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= m; j++) {
//				b.push_back(ma[i][j]);
//			}
//		}
//
////		for (int i = 1; i <= n; i++) {
////			for (int j = 1; j <= m; j++) {
////				cout << ma[i][j] << ' ';
////			}
////			cout << endl;
////		}
//
//		sort(b.begin(), b.end());
//
//		int ans = 0;
//		for (int i = w - 1; i >= 0; i--) {
//			ans += a[i] * b.back();
//			b.pop_back();
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}

// 重写上一题
// #include<bits/stdc++.h>
// using namespace std;
//
// #define int long long
// int n, m, k, w;
//
// int shu(int i, int j) {
//	return (min(n, min(i, n - k + 1)) - max(1LL, i - k + 1) + 1) * (min(m, min(j, m - k + 1)) - max(1LL, j - k + 1) + 1);
// }
//
// signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> n >> m >> k >> w;
//		vector<int> a(w);
//		for (int i = 0; i < w; i++) cin >> a[i];
//		sort(a.begin(), a.end());
//		vector<int> fen;
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= m; j++) {
//				fen.push_back(shu(i, j));
//			}
//		}
//		sort(fen.begin(), fen.end());
//		int ans = 0;
//		for (int i = w - 1; i >= 0; i--) {
//			ans += fen.back() * a[i];
//			fen.pop_back();
//		}
//
//		cout << ans << endl;
//	}
//	return 0;
// }

// https://codeforces.com/contest/545/problem/C
// #include <bits/stdc++.h>
// using namespace std;
//
// struct tree {
//	int x;
//	int h;
// };
//
// struct dp {
//	int fen;
//	int weizhi;
// };
//
// int main() {
//	int n;
//	cin >> n;
//	vector<tree> a(n);
//	for (int i = 0; i < n; i++) {
//		cin >> a[i].x >> a[i].h;
//	}
//	vector<dp> ans(n);
//	ans[0] = {1, a[0].x};
//
//	for (int i = 1; i < n; i++) {
//		if (a[i].x - a[i].h > ans[i - 1].weizhi) {
//			ans[i] = {ans[i - 1].fen + 1, a[i].x};
//		} else {
//			if (i == n - 1)
//				ans[i] = {ans[i - 1].fen + 1, a[i].x + a[i].h};
//			else {
//				if (a[i].x + a[i].h >= a[i + 1].x) {
//					ans[i] = {ans[i - 1].fen, a[i].x};
//				} else {
//					ans[i] = {ans[i - 1].fen + 1, a[i].x + a[i].h};
//				}
//			}
//		}
//	}
//
//	cout << ans[n - 1].fen << endl;
//
//	return 0;
// }

// https://codeforces.com/problemset/problem/1575/J
// #include <bits/stdc++.h>
// using namespace std;
//
// struct pos {
//	int x;
//	int y;
// };
//
// int main() {
//	int n, m, k;
//	cin >> n >> m >> k;
//	vector<vector<int>> a(n + 1, vector<int> (m + 1));
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			cin >> a[i][j];
//		}
//	}
//	int c;
//	while (k--) {
//		cin >> c;
//		pos posc = {1, c};
//		while (posc.x <= n) {
//			if (a[posc.x][posc.y] == 1) {
//				a[posc.x][posc.y] = 2;
//				posc = {posc.x, posc.y + 1};
//			} else if (a[posc.x][posc.y] == 2) {
//				a[posc.x][posc.y] = 2;
//				posc = {posc.x + 1, posc.y};
//			} else {
//				a[posc.x][posc.y] = 2;
//				posc = {posc.x, posc.y - 1};
//			}
//		}
//
//		cout << posc.y << ' ';
//	}
//	return 0;
// }

// https://codeforces.com/problemset/problem/2049/C
// 2025.1.12
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int n, x, y;
//		cin >> n >> x >> y;
//		x--;
//		y--;
//		vector<int> a(n);
//		if (n & 1) {
//			a[0] = 2;
//			a[1] = 0;
//			a[2] = 1;
//			for (int i = 3; i < n; i++) a[i] = (i + 1) % 2;
//		} else {
//			for (int i = 0; i < n; i++) a[i] = i % 2;
//		}
//
//		int y_ = max(x, y);
//
//		if (a[x] != a[y]) {
//			for (int i = 0; i < n; i++) {
//				cout << a[i] << ' ';
//			}
//			cout << endl;
//		} else {
//			a[y_] = 2;
//			if (n & 1 && y_ == n - 2) {
//				a[0] = 0;
//				a[1] = 2;
//				if (min(x, y) == 1) a[y_] = 0;
//			}
//			if (n & 1 && y_ == n - 1) {
//				a[0] = 0;
//				a[1] = 1;
//				a[2] = 2;
//				if (min(x, y) == 2) a[y_] = 1;
//			}
//			for (int i = 0; i < n; i++) {
//				cout << a[i] << ' ';
//			}
//			cout << endl;
//		}
//	}
//	return 0;
// }

// https://codeforces.com/problemset/problem/2057/B
// 2025.1.12
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int n, k;
//		cin >> n >> k;
//		vector<int> a(n);
//		for (int i = 0; i < n; i++) cin >> a[i];
//		sort(a.begin(), a.end());
//
//		if (k >= n - 1) {
//			cout << 1 << endl;
//			continue;
//		}
//
//		vector<int> cnt = {1};
//		for (int i = 1; i < n; i++) {
//			if (a[i] == a[i - 1]) cnt.back()++;
//			else cnt.emplace_back(1);
//		}
//		sort(cnt.begin(), cnt.end());
//
//		int jian = 0;
//		for (int i = 0; i < (int)cnt.size(); i++) {
//			k -= cnt[i];
//			if (k >= 0) jian++;
//			else break;
//		}
//
//		cout << max(1, (int)cnt.size() - jian) << endl;
//	}
//	return 0;
// }

// https://codeforces.com/contest/2057/problem/A
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//	int t, n, m;
//	cin >> t;
//	while (t--) {
//		cin >> n >> m;
//		cout << 1 + max(n, m) << endl;
//	}
//	return 0;
// }

// https://codeforces.com/contest/2057/problem/C
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//	int t, l, r;
//	cin >> t;
//	while (t--) {
//		cin >> l >> r;
//		int a = l | ((1 << (int)(log2(l ^ r))) - 1);
//		int b = a + 1;
//		int c = (b == r ? l : r);
//		cout << a << ' ' << b << ' ' << c << endl;
//	}
//	return 0;
// }

// https://codeforces.com/problemset/problem/2049/B
// 2025.1.16
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//	int t, n;
//	string s;
//	cin >> t;
//	while (t--) {
//		cin >> n >> s;
//		// 检查是否有p..s
//		bool have_ps = false;
//		for (int i = 0; i < n; i++) {
//			if (s[i] == 'p') {
//				for (int j = i + 1; j < n; j++) {
//					if (s[j] == 's') {
//						have_ps = true;
//						break;
//					}
//				}
//				break;
//			}
//		}
//		if (have_ps) {
//			cout << "NO" << endl;
//			continue;
//		}
//
//		unordered_map<char, int> mp;
//		for (int i = 0; i < n; i++) {
//			if (s[i] != '.') {
//				mp[s[i]]++;
//			}
//		}
//
//		if (mp['p'] > 1 && mp['s'] > 1) {
//			cout << "NO" << endl;
//			continue;
//		}
//
//		if (n >= 4 && s[0] == s.back() && s.back() == '.' && mp['s'] >= 1 && mp['p'] >= 1) {
//			cout << "NO" << endl;
//			continue;
//		}
//
//		if (mp['s'] >= 2 && mp['p'] >= 1 && s.back() != 'p') {
//			cout << "NO" << endl;
//			continue;
//		}
//
//		if (mp['s'] >= 1 && mp['p'] >= 2 && s[0] != 's') {
//			cout << "NO" << endl;
//			continue;
//		}
//
//		cout << "YES" << endl;
//	}
//	return 0;
// }

// https://codeforces.com/problemset/problem/2053/C
// 2025.1.16
// #include <bits/stdc++.h>
// using namespace std;
//
// #define int long long
//
// int t, n, k;
//
// pair<int, int> ans(int l, int r, int k) {
//	if (r - l + 1 < k) return {0, 0};
//	int m = (l + r) >> 1;
//	int res = 0;
//	int cnt = 0;
//	if ((r - l + 1) & 1) {
//		pair<int, int> p = ans(l, m - 1, k);
//		cnt = 1 + 2 * p.second;
//		res = m + 2 * p.first + p.second * m;
//	} else {
//		pair<int, int> p = ans(l, m, k);
//		cnt = 2 * p.second;
//		res = 2 * p.first + m * p.second;
//	}
//	return {res, cnt};
//}
//
// signed main() {
//	cin >> t;
//	while (t--) {
//		cin >> n >> k;
//		cout << ans(1, n, k).first <<  endl;
//	}
//	return 0;
//}

// https://codeforces.com/problemset/problem/1989/C
// 2025.1.18
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int n;
//		cin >> n;
//		vector<int> a(n), b(n);
//		for (int i = 0; i < n; i++) cin >> a[i];
//		for (int i = 0; i < n; i++) cin >> b[i];
//		int fu = 0, a1 = 0, a2 = 0, zhen = 0;
//		for (int i = 0; i < n; i++) {
//			if (a[i] == b[i] && a[i] == -1) fu--;
//			else if (a[i] == b[i] && a[i] == 1) zhen++;
//			else if (a[i] > b[i]) {
//				a1 += a[i];
//			} else if (a[i] < b[i]) {
//				a2 += b[i];
//			}
//		}
//		while (fu != 0) {
//			if (a1 >= a2) {
//				a1--;
//				fu++;
//			} else {
//				a2--;
//				fu++;
//			}
//		}
//
//		while (zhen != 0) {
//			if (a1 >= a2) {
//				a2++;
//				zhen--;
//			} else {
//				a1++;
//				zhen--;
//			}
//		}
//		cout << min(a1, a2) << endl;
//	}
//	return 0;
// }

// https://codeforces.com/problemset/problem/2051/D
// 2025.1.19
// #include <bits/stdc++.h>
// using namespace std;
//
// #define int long long
// const int N = 200010;
// int t, n, x, y, a[N];
//
// int binary1(int l, int x) {
//	int r = n - 1;
//	while (l <= r) {
//		int mid = (l + r) >> 1;
//		if (a[mid] >= x) {
//			r = mid - 1;
//		} else {
//			l = mid + 1;
//		}
//	}
//	return r + 1;
//}
//
// int binary2(int l, int x) {
//	int r = n - 1;
//	while (l <= r) {
//		int mid = (l + r) >> 1;
//		if (a[mid] <= x) {
//			l = mid + 1;
//		} else {
//			r = mid - 1;
//		}
//	}
//	return l - 1;
//}
//
// signed main() {
//	cin >> t;
//	while (t--) {
//		cin >> n >> x >> y;
//		int sum = 0;
//		for (int i = 0; i < n; i++) {
//			cin >> a[i];
//			sum += a[i];
//		}
//		sort(a, a + n);
//		int ans = 0;
//		for (int i = 0; i < n; i++) {
//			int xia = binary1(i + 1, sum - a[i] - y);
//			int shang = binary2(i + 1, sum - a[i] - x);
//			ans += shang - xia + 1;
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}

// https://codeforces.com/contest/2090/problem/C
// #include <bits/stdc++.h>
// using namespace std;
//
// const int N = 50010;
// vector<pair<int, int>> pos;
// vector<int> vis(N);
//
// int cen(int idx) {
//	int l = 0, r = N / 2;
//	int res = 0;
//	while (l <= r) {
//		int mid = (l + r) >> 1;
//		int k = (mid + 1) * mid / 2;
//		if (k >= idx) {
//			r = mid - 1;
//			res = mid;
//		} else l = mid + 1;
//	}
//	return res;
//}
//
// pair<int, int> trans(int idx, int cnt) {
//	pair<int, int> res = pos[idx];
//	res.first = (res.first - 1) * 3 + 1;
//	res.second = (res.second - 1) * 3 + 1;
//	if (cnt == 1) {
//		res.second++;
//	} else if (cnt == 2) {
//		res.first++;
//	} else if (cnt == 3) {
//		res.first++;
//		res.second++;
//	}
//	return res;
//}
//
// void print(pair<int, int> pos) {
//	cout << pos.first << ' ' << pos.second << endl;
//}
//
// int main() {
//	pos.push_back({0, 0});
//	for (int i = 2; pos.size() < N - 5; i++) {
//		for (int j = 1; j <= i - 1; j++) {
//			pos.push_back({j, i - j});
//		}
//	}
//	int t;
//	cin >> t;
//	while (t--) {
//		int n;
//		cin >> n;
//		vector<int> a(n);
//		for (int i = 0; i < n; i++) cin >> a[i];
//		int kong = 1;
//		for (int i = 0; i < n; i++) {
//			if (a[i] == 0) {
//				while (vis[kong] != 0) kong++;
//				print(trans(kong, vis[kong]));
//				vis[kong]++;
//			} else {
//				for (int j = 1; ; j++) {
//					if (vis[j] <= 3) {
//						if (vis[j] <= 2) {
//							int ce = cen(j);
//							int to1 = (ce + 1) * ce / 2;
//							bool is_found = false;
//							for (int k = j; k <= to1 && !is_found; k++) {
//								if (vis[k] == 0) {
//									print(trans(k, vis[k]));
//									vis[k]++;
//									is_found = true;
//								}
//							}
//							if (!is_found) {
//								print(trans(j, vis[j]));
//								vis[j]++;
//							}
//						} else {
//							int x_j = trans(j, vis[j]).first;
//							int ce = cen(j);
//							int to1 = (ce + 1) * ce / 2;
//							int to2 = to1 + ce + 1;
//							bool is_found = false;
//							for (int k = j + 1; k <= to1 && !is_found; k++) {
//								if (vis[k] <= 2) {
//									is_found = true;
//									print(trans(k, vis[k]));
//									vis[k]++;
//								}
//							}
//							for (int k = to1 + 1; k <= to2 && !is_found; k++) {
//								if (vis[k] == 0) {
//									is_found = true;
//									print(trans(k, vis[k]));
//									vis[k]++;
//								}
//							}
//
//							for (int k = to1 + 1; k <= to2 && !is_found; k++) {
//								if (vis[k] <= 2) {
//									int x = trans(k, vis[k]).first;
//									if (x < x_j) {
//										is_found = true;
//										print(trans(k, vis[k]));
//										vis[k]++;
//									}
//								}
//							}
//
//							if (!is_found) {
//								print(trans(j, vis[j]));
//								vis[j]++;
//							}
//						}
//						break;
//					}
//				}
//			}
//		}
//		vis.assign(N, 0);
//	}
//	return 0;
//}

// Codeforces Round 1013 (Div. 3) vp
// 2025.4.8   比赛开始

// A
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int n;
//		cin >> n;
//		string s = "01032025";
//		unordered_map<char, int> mp;
//		for (int i = 0; i < (int)s.size(); i++) mp[s[i]]++;
//		vector<char> a(n + 1);
//		for (int i = 1; i <= n; i++) cin >> a[i];
//		bool have_ans = false;
//		for (int i = 1; i <= n; i++) {
//			if (mp.find(a[i]) != mp.end()) {
//				mp[a[i]]--;
//				int j;
//				for (j = 0; j < (int)s.size(); j++) {
//					if (mp[s[j]] > 0) {
//						break;
//					}
//				}
//				if (j == (int)s.size()) {
//					cout << i << endl;
//					have_ans = true;
//					break;
//				}
//			}
//		}
//		if (!have_ans) cout << 0 << endl;
//	}
//	return 0;
//}

// B
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int n, x;
//		cin >> n >> x;
//		vector<int> a(n);
//		for (int i = 0; i < n; i++) cin >> a[i];
//		int ans = 0;
//		sort(a.begin(), a.end());
//		for (int i = n - 1; i >= 0; i--) {
//			int j = i;
//			int minn = a[i];
//			while (j >= 0 && minn * (i - j + 1) < x) {
//				j--;
//				minn = min(minn, a[j]);
//			}
//			if (j != -1) ans++;
//			i = j;
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}

// C
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int n;
//		cin >> n;
//		if (n & 1) {
//			vector<int> ans(n + 1);
//			int ji = 1;
//			int ou = 2;
//			for (int i = 1; i <= n; i++) {
//				if (ji != n + 2) {
//					ans[i] = ji;
//					ji += 2;
//				} else {
//					ans[i] = ou;
//					ou += 2;
//				}
//			}
//			for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
//			cout << endl;
//		} else {
//			cout << -1 << endl;
//		}
//	}
//	return 0;
//}

// D
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// int n, m, k;
//
// bool manzu(int mid) {
//	int cnt = 0;
//	int hang_max = ((m - mid) / (1 + mid) + 1) * mid + max((m - mid) % (1 + mid) - 1, 0LL);
//	cnt = hang_max * n;
//	if (cnt >= k) return true;
//	return false;
//}
//
// signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> n >> m >> k;
//		int l = 1, r = m;
//		while (l <= r) {
//			int mid = (l + r) >> 1;
//			if (manzu(mid)) r = mid - 1;
//			else l = mid + 1;
//		}
//		cout << r + 1 << endl;
//	}
//	return 0;
//}

// E
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// const int N = 1e7 + 10;
// int vis[N], primes[N], cnt, sum[N];
//
// void euler() {
//	vis[0] = 1;
//	vis[1] = 1;
//	for (int i = 2; i < N; i++) {
//		if (!vis[i]) primes[cnt++] = i;
//		for (int j = 0; primes[j] * i <= N; j++) {
//			vis[i * primes[j]] = 1;
//			if (i % primes[j] == 0) break;
//		}
//	}
//
//	for (int i = 1; i < N; i++) {
//		sum[i] = sum[i - 1] + (vis[i] == 0);
//	}
//}
//
// signed main() {
//	int t;
//	cin >> t;
//	euler();
//	while (t--) {
//		int n;
//		cin >> n;
//		int ans = 0;
//		for (int i = 1; i <= n; i++) {
//			int maxn = n / i;
//			ans += sum[maxn];
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}
// 比赛结束，A了5道，再接再厉！！！

// D. Skibidi Table
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int n;
//		cin >> n;
//		int q;
//		cin >> q;
//		while (q--) {
//			string op;
//			cin >> op;
//			int x, y, d;
//			if (op == "->") {
//				cin >> x >> y;
//				x--, y--;
//				int d = 0;
//				for (int i = n - 1; i >= 0; i--) {
//					int o1 = (x >> i) & 1;
//					int o2 = (y >> i) & 1;
//					if (o1 == 0 && o2 == 0) {
//						if (i == 0) d++;
//					} else if (o1 == 0 && o2 == 1) {
//						d += 3 * (int)pow(2, 2 * i);
//						if (i == 0) d++;
//					} else if (o1 == 1 && o2 == 0) {
//						d += 2 * (int)pow(2, 2 * i);
//						if (i == 0) d++;
//					} else if (o1 == 1 && o2 == 1) {
//						d += (int)pow(2, 2 * i);
//						if (i == 0) d++;
//					}
//				}
//				cout << d << endl;
//			} else {
//				cin >> d;
//				d--;
//				int x = 0, y = 0;
//				for (int i = n - 1; i >= 0; i--) {
//					int f = d / (int)pow(2, 2 * i);
//					if (f == 0) {
//
//					} else if (f == 1) {
//						x += (int)pow(2, i);
//						y += (int)pow(2, i);
//						d = d - (int)pow(2, 2 * i);
//					} else if (f == 2) {
//						x += (int)pow(2, i);
//						d = d - 2 * (int)pow(2, 2 * i);
//					} else if (f == 3) {
//						y += (int)pow(2, i);
//						d = d - 3 * (int)pow(2, 2 * i);
//					}
//				}
//				cout << x + 1 << ' ' << y + 1 << endl;
//			}
//		}
//	}
//	return 0;
//}

// https://codeforces.com/problemset/problem/2103/C
// #include <iostream>
// #include <cstring>
// using namespace std;
// const int N = 2e5 + 5;
// int a[N], suml[N], sumr[N];
//
// int main() {
//	int T;
//	cin >> T;
//	while (T--) {
//		int n, x;
//		cin >> n >> x;
//		for (int i = 1; i <= n; i++) {
//			int t;
//			cin >> t;
//			if (t <= x) a[i] = 1;
//			else a[i] = -1;
//		}
//		for (int i = 1; i <= n; i++) suml[i] = suml[i - 1] + a[i];
//		for (int i = n; i >= 1; i--) sumr[i] = sumr[i + 1] + a[i];
//		bool is_yes1 = false;
//		for (int i = 1; i <= n - 1; i++) {
//			bool b = 0;
//			if (suml[i] >= 0) {
//				b = 1;
//				int j = i + 1;
//				int zuo = suml[i];
//				for (; j <= n - 1; j++) {
//					if (suml[j] - zuo >= 0) {
//						is_yes1 = true;
//						break;
//					}
//					if (suml[j] >= 0) zuo = min(suml[j], zuo);
//				}
//			}
//			if (b) break;
//		}
//
//		bool is_yes2 = false;
//		for (int i = n; i >= 2; i--) {
//			bool b = 0;
//			if (sumr[i] >= 0) {
//				b = 1;
//				int j = i - 1;
//				int zuo = sumr[i];
//				for (; j >= 2; j--) {
//					if (sumr[j] - zuo >= 0) {
//						is_yes2 = true;
//						break;
//					}
//					if (sumr[j] >= 0) zuo = min(sumr[j], zuo);
//				}
//			}
//			if (b) break;
//		}
//		bool is_yes3 = false;
//		int i;
//		for (i = 1; i <= n; i++) {
//			if (suml[i] >= 0) break;
//		}
//		int j;
//		for (j = n; j >= 1; j--) {
//			if (sumr[j] >= 0) break;
//		}
//
//		if (j - i >= 2) is_yes3 = true;
//
//		if (is_yes1 || is_yes2 || is_yes3) cout << "Yes" << endl;
//		else cout << "No" << endl;
//
//		memset(suml, 0, sizeof(int) * (n + 3));
//		memset(sumr, 0, sizeof(int) * (n + 3));
//	}
//	return 0;
//}

// G. Shorten the Array
// https://codeforces.com/problemset/problem/2093/G
// #include <bits/stdc++.h>
// using namespace std;
// #define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
//
// const int N = 2e5 + 10;
// struct Node {
//	int cnt = 0;
//	int c0 = -1;
//	int c1 = -1;
//};
// int a[N];
// vector<Node> tr(1);
//
// void add(int x) {
//	int p = 0;
//	for (int i = 29; i >= 0; i--) {
//		int bi = (x >> i) & 1;
//		if (bi == 0) {
//			if (tr[p].c0 == -1) {
//				tr[p].c0 = tr.size();
//				p = tr.size();
//				tr.push_back(Node());
//			} else {
//				p = tr[p].c0;
//			}
//		} else {
//			if (tr[p].c1 == -1) {
//				tr[p].c1 = tr.size();
//				p = tr.size();
//				tr.push_back(Node());
//			} else {
//				p = tr[p].c1;
//			}
//		}
//		tr[p].cnt++;
//	}
//}
//
// void del(int x) {
//	int p = 0;
//	for (int i = 29; i >= 0; i--) {
//		int bi = (x >> i) & 1;
//		if (bi == 0) p = tr[p].c0;
//		else p = tr[p].c1;
//		tr[p].cnt--;
//	}
//}
//
// int the_max(int x) {
//	int res = 0;
//	int p = 0;
//	for (int i = 29; i >= 0; i--) {
//		int x_bit = (x >> i) & 1;
//		if (x_bit == 1) {
//			if (tr[p].c0 != -1 && tr[tr[p].c0].cnt > 0) {
//				res = (res << 1) + 1;
//				p = tr[p].c0;
//			} else {
//				res = (res << 1);
//				p = tr[p].c1;
//			}
//		} else {
//			if (tr[p].c1 != -1 && tr[tr[p].c1].cnt > 0) {
//				res = (res << 1) + 1;
//				p = tr[p].c1;
//			} else {
//				res = (res << 1);
//				p = tr[p].c0;
//			}
//		}
//	}
//	return res;
//}
//
// signed main() {
//	IOS;
//	int t;
//	cin >> t;
//	while (t--) {
//		int n, k;
//		cin >> n >> k;
//		for (int i = 1; i <= n; i++) cin >> a[i];
//		int l = 1, r = 1;
//		int ans = n + 1;
//		add(a[r]);
//		while (l <= r && r <= n) {
//			int maxn = the_max(a[r]);
//			if (maxn >= k) {
//				ans = min(ans, r - l + 1);
//				del(a[l]);
//				l++;
//			} else {
//				r++;
//				add(a[r]);
//			}
//		}
//		if (ans == n + 1) cout << -1 << endl;
//		else cout << ans << endl;
//		tr.assign(1, Node());
//	}
//	return 0;
//}

// https://codeforces.com/contest/2093/problem/A
// #include <iostream>
// using namespace std;
//
// int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int n;
//		cin >> n;
//		if (n & 1) cout << "YES" << endl;
//		else cout << "NO" << endl;
//	}
//	return 0;
//}

// https://codeforces.com/contest/2093/problem/B
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		string s;
//		cin >> s;
//		int ans = 0;
//		for (int i = (int)s.size() - 1; i >= 0; i--) {
//			if (s[i] == '0') {
//				ans++;
//				s.pop_back();
//			} else break;
//		}
//		while (s.size() != 1) {
//			if (*s.begin() == '0') {
//				s.erase(s.begin());
//			} else {
//				ans++;
//				s.erase(s.begin());
//			}
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}

// https://codeforces.com/contest/2093/problem/C
// #include <bits/stdc++.h>
// using namespace std;
//
// bool is_prime(int x) {
//	if (x == 1) return false;
//	for (int i = 2; i <= x / i; i++)
//		if (x % i == 0) return false;
//	return true;
//}
//
// signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int x, k;
//		cin >> x >> k;
//		if (k == 1) {
//			if (is_prime(x)) cout << "YES" << endl;
//			else cout << "NO" << endl;
//		} else if (k == 2) {
//			if (x == 1) cout << "YES" << endl;
//			else cout << "NO" << endl;
//		} else {
//			cout << "NO" << endl;
//		}
//	}
//	return 0;
//}

// https://codeforces.com/contest/2093/problem/E
// #include <bits/stdc++.h>
// using namespace std;
//
// const int N = 2e5 + 10;
// int a[N], n, k;
// int vis[N];
//
// bool he(int mid) {
//	if (mid == 0) return true;
//	int cnt = 0;
//	int the_cnt = 0;
//	int l = 0;
//	for (int i = 0; i < n; i++) {
//		if (a[i] <= 2e5)
//			vis[a[i]] += 1;
//		if (a[i] < mid && vis[a[i]] == 1) the_cnt++;
//		if (the_cnt >= mid) {
//			cnt++;
//			the_cnt = 0;
//			for (int j = l; j <= i; j++)
//				if (a[j] <= 2e5)
//					vis[a[j]] = 0;
//			l = i + 1;
//		}
//	}
//	for (int i = l; i < n; i++)
//		if (a[i] <= 2e5)
//			vis[a[i]] = 0;
//	return cnt >= k;
//}
//
// int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> n >> k;
//		for (int i = 0; i < n; i++) cin >> a[i];
//		int r = 2e5;
//		int l = 0;
//		while (l <= r) {
//			int mid = (l + r) >> 1;
//			if (he(mid)) l = mid + 1;
//			else r = mid - 1;
//		}
//		cout << l - 1 << endl;
//	}
//	return 0;
//}

// https://codeforces.com/contest/2106/problem/A
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int n;
//		string s;
//		cin >> n >> s;
//		int zero_cnt = 0, one_cnt = 0;
//		for (int i = 0; i < n; i++) {
//			if (s[i] == '0') zero_cnt++;
//			else one_cnt++;
//		}
//		cout << n * one_cnt - one_cnt + zero_cnt << endl;
//	}
//	return 0;
//}

// https://codeforces.com/contest/2106/problem/B
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int n, x;
//		cin >> n >> x;
//		vector<int> ans(n);
//		for (int i = 0; i < x; i++) {
//			ans[i] = i;
//		}
//		for (int i = x; i < n - 1; i++) {
//			ans[i] = i + 1;
//		}
//		ans[n - 1] = min(x, n - 1);
//		for (int i = 0; i < n; i++) cout << ans[i] << ' ';
//		cout << endl;
//	}
//	return 0;
//}

// https://codeforces.com/contest/2106/problem/C
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int n, k;
//		cin >> n >> k;
//		vector<int> a(n), b(n);
//		for (int i = 0; i < n; i++) cin >> a[i];
//		for (int i = 0; i < n; i++) cin >> b[i];
//		int ding = -1;
//		int is_zero = false;
//		for (int i = 0; i < n; i++) {
//			if (a[i] != -1 && b[i] != -1) {
//				if (ding == -1) ding = a[i] + b[i];
//				else {
//					if (a[i] + b[i] != ding) {
//						is_zero =true;
//						break;
//					}
//				}
//			}
//		}
//		if (is_zero) {
//			cout << 0 << endl;
//			continue;
//		}
//		if (ding == -1) {
//			int minn = 1e9;
//			int maxn = -1e9;
//			for (int i = 0; i < n; i++) {
//				if (a[i] != -1) {
//					minn = min(minn, a[i]);
//					maxn = max(maxn, a[i]);
//				}
//				if (b[i] != -1)  {
//					minn = min(minn, b[i]);
//					maxn = max(maxn, b[i]);
//				}
//			}
//			cout << k + minn - maxn + 1 << endl;
//		} else {
//			int ans = 1;
//			for (int i = 0; i < n; i++) {
//				if (a[i] == -1 && b[i] == -1) {
//					ans *= k + 1;
//				} else if (a[i] == -1) {
//					int ai = ding - b[i];
//					if (!(0 <= ai && ai <= k)) {
//						is_zero = true;
//						break;
//					}
//				} else if (b[i] == -1) {
//					int bi = ding - a[i];
//					if (!(0 <= bi && bi <= k)) {
//						is_zero = true;
//						break;
//					}
//				}
//			}
//			if (is_zero) cout << 0 << endl;
//			else cout << ans << endl;
//		}
//	}
//	return 0;
//}

// https://codeforces.com/contest/2106/problem/D
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int n, m;
//		cin >> n >> m;
//		vector<int> a(n), b(m);
//		for (int i = 0; i < n; i++) cin >> a[i];
//		for (int i = 0; i < m; i++) cin >> b[i];
//		vector<int> qian(m), hou(m);
//		int j = 0;
//		for (int i = 0; i < m; i++) {
//			while (j < n && a[j] < b[i]) j++;
//			qian[i] = j++;
//		}
//		j = n - 1;
//		for (int i = m - 1; i >= 0; i--) {
//			while (j >= 0 && a[j] < b[i]) j--;
//			hou[i] = j--;
//		}
//		if (qian[m - 1] < n) {
//			cout << 0 << endl;
//			continue;
//		}
//		int ans = 2e9;
//		for (int i = 0; i < m; i++) {
//			int pre = (i == 0 ? -1 : qian[i - 1]);
//			int en = (i == m - 1 ? n : hou[i + 1]);
//			if (pre < en) ans = min(ans, b[i]);
//		}
//		cout << (ans == 2e9 ? -1 : ans) << endl;
//	}
//	return 0;
//}

// https://codeforces.com/problemset/problem/2094/H
// TLE
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define endl '\n'
//
// signed main() {
//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t;
//	cin >> t;
//	while (t--) {
//		int n, q;
//		cin >> n >> q;
//		int a[n + 1];
//		unordered_map<int, vector<int>> pos;
//		for (int i = 1; i <= n; i++) {
//			cin >> a[i];
//			pos[a[i]].push_back(i);
//		}
//		while (q--) {
//			int k, l, r;
//			cin >> k >> l >> r;
//			vector<int> b;
//			if (pos.find(k) != pos.end()) {
//				int x = lower_bound(pos[k].begin(), pos[k].end(), l) - pos[k].begin();
//				if (x >= 0 && x < (int)pos[k].size() && pos[k][x] <= r) b.push_back(pos[k][x]);
//			}
//			for (int i = 2; i * i <= k; i++) {
//				if (k % i == 0) {
//					if (pos.find(k / i) != pos.end()) {
//						int x = lower_bound(pos[k / i].begin(), pos[k / i].end(), l) - pos[k / i].begin();
//						if (x >= 0 && x < (int)pos[k / i].size() && pos[k / i][x] <= r) b.push_back(pos[k / i][x]);
//					}
//					if (i != k / i) {
//						if (pos.find(i) != pos.end()) {
//							int x = lower_bound(pos[i].begin(), pos[i].end(), l) - pos[i].begin();
//							if (x >= 0 && x < (int)pos[i].size() && pos[i][x] <= r) b.push_back(pos[i][x]);
//						}
//					}
//				}
//			}
//			sort(b.begin(), b.end());
//			int ans = 0;
//			int fi = l;
//			for (int i : b) {
//				if (k % a[i] == 0) {
//					ans += (i - fi) * k;
//					while (k % a[i] == 0) k /= a[i];
//					fi = i;
//				}
//			}
//			ans += (r + 1 - fi) * k;
//			cout << ans << endl;
//		}
//	}
//	return 0;
//}

// https://codeforces.com/contest/380/problem/C
// AI哥一发入魂
// #include <bits/stdc++.h>
// using namespace std;
//
// const int N = 1e6 + 10;
// string s;
//
// struct node {
//	int l, r;
//	int a, zuo, you;
//} tr[4 * N];
//
// void pushup(node& root, node& left, node& right) {
//	int t = min(left.zuo, right.you);
//	root.a = left.a + right.a + t;
//	root.zuo = left.zuo + right.zuo - t;
//	root.you = left.you + right.you - t;
//}
//
// void build(int u, int l, int r) {
//	if (l == r) {
//		if (s[l] == '(') tr[u] = {l, r, 0, 1, 0};
//		else tr[u] = {l, r, 0, 0, 1};
//	} else {
//		int mid = (l + r) >> 1;
//		tr[u].l = l, tr[u].r = r;
//		build(u << 1, l, mid);
//		build(u << 1 | 1, mid + 1, r);
//		pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
//	}
//}
//
// node query(int u, int l, int r) {
//	if (l <= tr[u].l && tr[u].r <= r) {
//		return tr[u];
//	} else {
//		int mid = (tr[u].l + tr[u].r) >> 1;
//		if (r <= mid) {
//			return query(u << 1, l, r);
//		} else if (l > mid) {
//			return query(u << 1 | 1, l, r);
//		} else {
//			node zuo = query(u << 1, l, mid);
//			node you = query(u << 1 | 1, mid + 1, r);
//			node res;
//			pushup(res, zuo, you);
//			return res;
//		}
//	}
//}
//
// int main() {
//	cin >> s;
//	s = ' ' + s;
//	int n = s.size();
//	build(1, 1, n);
//	int m, l, r;
//	cin >> m;
//	while (m--) {
//		cin >> l >> r;
//		cout << query(1, l, r).a * 2 << endl;
//	}
//	return 0;
//}

// B. Gellyfish and Baby's Breath
// https://codeforces.com/problemset/problem/2116/B
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// const int N = 1e5 + 10, mod = 998244353;
// int mi[N];
//
// void init() {
//	mi[0] = 1;
//	for (int i = 1; i < N; i++) mi[i] = mi[i - 1] * 2 % mod;
//}
//
// signed main() {
//	int t;
//	cin >> t;
//	init();
//	while (t--) {
//		int n;
//		cin >> n;
//		vector<int> a(n), b(n);
//		unordered_map<int, int> mpa, mpb;
//		for (int i = 0; i < n; i++) cin >> a[i], mpa[a[i]] = i;
//		for (int i = 0; i < n; i++) cin >> b[i], mpb[b[i]] = i;
//		int maxn = a[0];
//		for (int i = 0; i < n; i++) {
//			maxn = max(a[i], maxn);
//			maxn = max(b[i], maxn);
//			if (mpa[maxn] <= i) {
//				if (mpb[maxn] <= i) {
//					if (b[i - mpa[maxn]] > a[i - mpb[maxn]]) {
//						cout << (mi[maxn] + mi[b[i - mpa[maxn]]]) % mod << ' ';
//					} else {
//						cout << (mi[maxn] + mi[a[i - mpb[maxn]]]) % mod << ' ';
//					}
//				} else {
//					cout << (mi[maxn] + mi[b[i - mpa[maxn]]]) % mod << ' ';
//				}
//			} else {
//				cout << (mi[maxn] + mi[a[i - mpb[maxn]]]) % mod << ' ';
//			}
//		}
//		cout << endl;
//	}
//	return 0;
//}

// A. Gellyfish and Tricolor Pansy
// https://codeforces.com/problemset/problem/2116/A
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int a, b, c, d;
//		cin >> a >> c >> b >> d;
//		a = min(a, b);
//		c = min(c, d);
//		if (a < c) cout << "Flower" << endl;
//		else cout << "Gellyfish" << endl;
//	}
//	return 0;
//}

// https://codeforces.com/problemset/problem/2114/F
// 2000 AC
// #include <bits/stdc++.h>
// using namespace std;
// #define endl '\n'
//
// void fenjie(vector<pair<int, int>>& mp, int x) {
//	if (x == 1) mp.push_back({1, 1});
//	for (int i = 2; i * i <= x; i++) {
//		if (x % i == 0) {
//			int cnt = 0;
//			while (x % i == 0) {
//				x /= i;
//				cnt++;
//			}
//			mp.push_back({i, cnt});
//		}
//	}
//	if (x > 1) mp.push_back({x, 1});
//}
//
// int min_num(int x, int k) {
//	if (x == 1) return 0;
//	if (x <= k) return 1;
//	map<int, int> dp;
//	vector<int> yinzi;
//	for (int i = 1; i * i <= x; i++) {
//		if (x % i == 0) {
//			if (i <= k && i != 1) dp[i] = 1;
//			else if (i > k && i != 1) dp[i] = 1e9;
//			if (i != 1) yinzi.push_back(i);
//			int t = x / i;
//			if (i != t) {
//				if (t <= k) dp[t] = 1;
//				else dp[t] = 1e9;
//				yinzi.push_back(t);
//			}
//		}
//	}
//	sort(yinzi.begin(), yinzi.end());
//	int idx = upper_bound(yinzi.begin(), yinzi.end(), k) - yinzi.begin();
//	for (unsigned i = idx; i < yinzi.size(); i++) {
//		for (unsigned j = 0; j < yinzi.size() && yinzi[j] * yinzi[j] <= yinzi[i]; j++) {
//			if (yinzi[i] % yinzi[j] == 0) {
//				dp[yinzi[i]] = min(dp[yinzi[i]], dp[yinzi[i] / yinzi[j]] + dp[yinzi[j]]);
//			}
//		}
//	}
//	return dp[x];
//}
//
// int main() {
//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t;
//	cin >> t;
//	while (t--) {
//		int x, y, k;
//		cin >> x >> y >> k;
//		int d = __gcd(x, y);
//		x = x / d, y = y / d;
//		vector<pair<int, int>> x_fen, y_fen;
//		fenjie(x_fen, x), fenjie(y_fen, y);
//		if (k < x_fen.back().first || k < y_fen.back().first) cout << -1 << endl;
//		else {
//			cout << min_num(x, k) + min_num(y, k) << endl;
//		}
//	}
//	return 0;
//}

// https://codeforces.com/contest/2114/problem/A
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		string s;
//		cin >> s;
//		int a = stoi(s);
//		if (a == 0) {
//			cout << 0 << ' ' << 0 << endl;
//			continue;
//		}
//		if ((int)sqrt(a) * (int)sqrt(a) == a) {
//			cout << 1 << ' ' << (int)sqrt(a) - 1 << endl;
//		} else cout << -1 << endl;
//	}
//	return 0;
//}

// https://codeforces.com/contest/2114/problem/B
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int n, k;
//		cin >> n >> k;
//		string s;
//		cin >> s;
//		int cnt0 = 0;
//		for (char c : s) cnt0 += (c == '0');
//		int cnt1 = n - cnt0;
//		if (2 * cnt0 >= n - 2 * k && 2 * cnt1 >= n - 2 * k) {
//			if ((cnt0 - (n - 2 * k) / 2) % 2 == 0 && (cnt1 - (n - 2 * k) / 2) % 2 == 0)
//				cout << "YES" << endl;
//			else cout << "NO" << endl;
//		} else cout << "NO" << endl;
//	}
//	return 0;
// }

// https://codeforces.com/contest/2114/problem/C
// #include <bits/stdc++.h>
// using namespace std;
// #define endl '\n';
//
// int main() {
//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t;
//	cin >> t;
//	while (t--) {
//		int n;
//		cin >> n;
//		vector<int> a(n);
//		for (int i = 0; i < n; i++) cin >> a[i];
//		int ans = 1;
//		int temp = a[0];
//		for (int i = 1; i < n; i++) {
//			if (temp + 1 < a[i]) {
//				ans++;
//				temp = a[i];
//			}
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}

// https://codeforces.com/contest/2114/problem/D
// 调试了非常久，脑子太蠢了
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define endl '\n'
//
// struct pos {
//	int x, y;
//	int id;
//};
//
// bool cmpx(const pos& a, const pos& b) {
//	if (a.x != b.x)
//		return a.x < b.x;
//	return a.y < b.y;
//}
//
// bool cmpy(const pos& a, const pos& b) {
//	if (a.y != b.y)
//		return a.y < b.y;
//	return a.x < b.x;
//}
//
// signed main() {
//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int t;
//	cin >> t;
//	while (t--) {
//		int n;
//		cin >> n;
//		vector<pos> a(n);
//		for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y, a[i].id = i;
//		if (n == 1) {
//			cout << 1 << endl;
//		} else if (n == 2) {
//			cout << 2 << endl;
//		} else {
//			vector<pos> b(a.begin(), a.end());
//			sort(a.begin(), a.end(), cmpx);
//			sort(b.begin(), b.end(), cmpy);
//			int ans = 1e18;
//			for (int i = 0; i < n; i++) {
//				int x1, x2, y1, y2;
//				int j = 0;
//				while (a[j].id == i) j++;
//				x1 = a[j].x;
//				j = n - 1;
//				while (a[j].id == i) j--;
//				x2 = a[j].x;
//				j = 0;
//				while (b[j].id == i) j++;
//				y1 = b[j].y;
//				j = n - 1;
//				while (b[j].id == i) j--;
//				y2 = b[j].y;
//				int temp = (x2 - x1 + 1) * (y2 - y1 + 1);
//				if (temp < n) temp += min(x2 - x1 + 1, y2 - y1 + 1);
////				cout << x1 << ' ' << x2 << ' ' << y1 << ' ' << y2 << ' ' << temp << endl;
//				ans = min(ans, temp);
//			}
//			cout << ans << endl;
//		}
//	}
//	return 0;
//}



// https://codeforces.com/problemset/problem/2060/B
//#include <bits/stdc++.h>
//using namespace std;
//#define endl '\n'
//
//signed main() {
//	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
//	int T;
//	cin >> T;
//	while (T--) {
//		int n, m;
//		cin >> n >> m;
//		vector<vector<int>> a(n + 1, vector<int>(m + 1));
//		for (int i = 1; i <= n; i++)
//			for (int j = 1; j <= m; j++)
//				cin >> a[i][j];
//
//		for (int i = 1; i <= n; i++) sort(a[i].begin() + 1, a[i].end());
//		vector<int> ans(n + 1);
//		iota(ans.begin(), ans.end(), 0);
//		sort(ans.begin() + 1, ans.end(), [&](int x, int y) {
//			return a[x] < a[y];
//		});
//		vector<int> tmp;
//		for (int i = 1; i <= m; i++) {
//			for (int j = 1; j <= n; j++) {
//				tmp.emplace_back(a[ans[j]][i]);
//			}
//		}
//		auto he = [&]() {
//			for (int i = 1; i < (int)tmp.size(); i++)
//				if (tmp[i] <= tmp[i - 1]) return false;
//			return true;
//		};
//		if (he()) {
//			for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
//			cout << endl;
//		} else {
//			cout << -1 << endl;
//		}
//	}
//	return 0;
//}


// https://codeforces.com/problemset/problem/2147/A
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//	int T;
//	cin >> T;
//	while (T--) {
//		int x, y;
//		cin >> x >> y;
//		if (x < y) cout << 2 << endl;
//		else {
//			if (x - 1 > y && 1 < y) cout << 3 << endl;
//			else cout << -1 << endl;
//		}
//	}
//	return 0;
//}













