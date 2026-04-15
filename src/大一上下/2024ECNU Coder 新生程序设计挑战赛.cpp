//2024ECNU Coder 新生程序设计挑战赛 2024 12 22


//小花狮的众数 过了
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n, x, a;
//	cin >> n >> x;
//	vector<int> mp(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> a;
//		if (a != x) mp[a]++;
//	}
//
//	int maxx = 1;
//	for (int i = 2; i <= n; i++) {
//		if (mp[maxx] < mp[i]) maxx = i;
//	}
//	cout << maxx << endl;
//	return 0;
//}


//小花狮与数字卡片 2024 12 22 没过, 拼尽全力却无法战胜。
//小花狮与数字卡片 2024 12 24 过了! 拼尽全力终能够战胜！
//#include <bits/stdc++.h>
//using namespace std;
//
//void get_ans(string& s, vector<int>& a, vector<int>& ans, bool& is_max, int step, int start) {
//	if (step < 0) {
//		ans[0] = -1;
//		return;
//	}
//	if (step == (int)s.size() - 1) {
//		for (int i = 0; i < (int)s.size() - 1; i++) cout << ans[i];
//	} else {
//		int i;
//		if (!is_max && step == (int)s.size() - 2) start--;
//		for (i = start; i >= 1; i--) {
//			if (a[i] >= 1) {
//				ans[step] = i;
//				a[i]--;
//				int be = 0;
//				if (step != (int)s.size() - 2)
//					be = s[step + 2] - '0';
//				if (i != start || is_max) {
//					be = 9;
//					if (!is_max) is_max = true;
//				}
//				get_ans(s, a, ans, is_max, step + 1, be);
//				break;
//			}
//		}
//		if (i == 0) {
//			int x = ans[step - 1];
//			a[x]++;
//			is_max = true;
//			get_ans(s, a, ans, is_max, step - 1, x - 1);
////			20250104一次偶然的机会让我找到了这个错误，测试集太水了导致以前没发现
////			if (x >= 2)
////				get_ans(s, a, ans, is_max, step - 1, x - 1);
////			else
////				ans[0] = -1;
//		}
//	}
//}
//
//int main() {
//	int n;
//	string s;
//	cin >> n >> s;
//	s = ' ' + s;
//	vector<int> a(10);
//	int sum = 0;
//	for (int i = 1; i <= 9; i++) {
//		cin >> a[i];
//		sum += a[i];
//	}
//	if (sum < n) cout << -1 << endl;
//	else {
////		 版本 1
////		string mins = " ";
////		int len = 0;
////		for (int i = 1; i <= 9 && len != n; i++) {
////			for (int j = 1; j <= a[i] && len != n; j++) {
////				mins += (char)('0' + i);
////				len++;
////			}
////		}
////		if (mins >= s) cout << -1 << endl;
////		else {
////			vector<int> ans(n + 2);
////			bool is_max = false;
////			get_ans(s, a, ans, is_max, 0, s[1] - '0');
////		}
//
////       版本 2
//		vector<int> ans(n + 2);
//		bool is_max = false;
//		get_ans(s, a, ans, is_max, 0, s[1] - '0');
//		if (ans[0] == -1) cout << -1 << endl;
//	}
//
//	return 0;
//}


//小花狮逃离异世界 过了
//#include <bits/stdc++.h>
//using namespace std;
//
//int dx[] = {1, -1, 0, 0};
//int dy[] = {0, 0, 1, -1};
//
//int main() {
//	int x, y, n, m;
//	cin >> n >> m;
//	vector<vector<char>> a(n, vector<char>(m));
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cin >> a[i][j];
//			if (a[i][j] == 'P') {
//				x = i;
//				y = j;
//			}
//		}
//	}
//	vector<vector<bool>> istao(n, vector<bool>(m));
//	vector<vector<bool>> vis(n, vector<bool>(m));
//	istao[x][y] = true;
//	vis[x][y] = true;
//	queue<pair<int, int>> q;
//	q.push(make_pair(x, y));
//	while (!q.empty()) {
//		pair<int, int> pos = q.front();
//		q.pop();
//
//		for (int i = 0; i < 4; i++) {
//			int x_ = pos.first + dx[i];
//			int y_ = pos.second + dy[i];
//
//			if (x_ < 0 || x_ >= n || y_ < 0 || y_ >= m) continue;
////			if (vis[x_][y_]) continue;
//			if (istao[x_][y_]) continue;
//
//			vis[x_][y_] = true;
//			if (a[x_][y_] == '.') {
//				istao[x_][y_] = true;
//				q.push(make_pair(x_, y_));
//			} else if (a[x_][y_] == 'U') {
//				if (x_ - 1 < 0) continue;
//				if (istao[x_ - 1][y_]) {
//					istao[x_][y_] = 1;
//					q.push(make_pair(x_, y_));
//				}
//			} else if (a[x_][y_] == 'D') {
//				if (x_ + 1 >= n) continue;
//				if (istao[x_ + 1][y_]) {
//					istao[x_][y_] = 1;
//					q.push(make_pair(x_, y_));
//				}
//			} else if (a[x_][y_] == 'L') {
//				if (y_ - 1 < 0) continue;
//				if (istao[x_][y_ - 1]) {
//					istao[x_][y_] = 1;
//					q.push(make_pair(x_, y_));
//				}
//			} else if (a[x_][y_] == 'R') {
//				if (y_ + 1 >= m) continue;
//				if (istao[x_][y_ + 1]) {
//					istao[x_][y_] = 1;
//					q.push(make_pair(x_, y_));
//				}
//			} else {
//				continue;
//			}
//		}
//	}
//
//	int ans = 0;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			if (istao[i][j] && a[i][j] == '.') ans++;
//		}
//	}
//
//	cout << ans << endl;
//
//	return 0;
//}


//小花狮与传说 过了
//#include <bits/stdc++.h>
//using namespace std;
//
//#define int long long
//
//signed main() {
//	int a, b, c, d;
//	cin >> a >> b >> c >> d;
//	int a_si = (b + c - 1) / c;
//	int b_si = (d + a - 1) / a;
//	if (a_si <= b_si) cout << a_si << endl;
//	else {
//		int step1 = d / a;
//		b -= step1 * c;
//		d -= step1 * a;
//
//		int x = min(c, d);
//		int max_gong = (x * (2 * c - x + 1)) / 2;
//		if (max_gong <= b) {
//			if (d >= c) {
//				cout << step1 + c << endl;
//			} else {
//				cout << step1 + d << endl;
//			}
//		} else {
//			int l = 0, r = min(c, d);
//			while (l <= r) {
//				int mid = (l + r) >> 1;
//				int gong = (mid * (2 * c - mid + 1)) / 2;
//
//				if (gong >= b) {
//					r = mid - 1;
//				} else {
//					l = mid + 1;
//				}
//			}
//
//			cout << step1 + r + 1 << endl;
//		}
//	}
//	return 0;
//}


// 忘记叫啥了 没过
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//	int n, m;
//	cin >> n >> m;
//	string s1 = " ", s2 = " ";
//	int x;
//	vector<vector<int>> mp(m + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> x;
//		mp[x].push_back(i);
//		s1 += (char)('0' + x);
//	}
//	for (int i = 0; i < n; i++) {
//		cin >> x;
//		s2 += (char)('0' + x);
//	}
//
//	string s1_c = s1;
//	string s2_c = s2;
//	sort(s1_c.begin(), s1_c.end());
//	sort(s2_c.begin(), s2_c.end());
//	if (s1_c != s2_c) cout << "NO" << endl;
//	else {
//		int ans = 0;
//		for (int i = 1; i <= n; i++) {
//			vector<int> cha;
//			int ji = 1;
//			for (int num : mp[s2[i] - '0']) {
//				ji *= (abs(i - num));
//			}
//			ans = gcd(ans, ji);
//
//
//		}
//
//		if (ans == 0) {
//			cout << "YES" << endl;
//			cout << n - 1 << endl;
//		} else {
//			cout << "YES" << endl;
//			cout << ans << endl;
//		}
//	}
//	return 0;
//}
