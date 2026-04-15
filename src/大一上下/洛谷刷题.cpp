//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int a, b, c;
//	cin >> a >> b >> c;
//	printf("%8d %8d %8d", a, b, c);
//	return 0;
//}

// 2024 10 16
//P1304 哥德巴赫猜想
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int> p = {2};
//	for (int i = 3; i < n; i++) {
//		for (int j = 0; j < (int)p.size(); j++) {
//			if (i % p[j] == 0) {
//				break;
//			}
//			if (j == (int)p.size() - 1) {
//				p.push_back(i);
//			}
//		}
//	}
//
//	unordered_map<int, int> p_map;
//	for (int num : p) {
//		p_map[num]++;
//	}
//
//	for (int i = 4; i <= n; i += 2) {
//		for (int j = 0; j < (int)p.size(); j++) {
//			if (p_map[i - p[j]]) {
//				cout << i << '=' << p[j] << '+' << i - p[j] << endl;
//				break;
//			}
//		}
//	}
//	return 0;
//}

// 2024 10 16
//P1152 欢乐的跳
//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//
//	unordered_map<int, int> map;
//	for (int i = 0; i < n - 1; i++) {
//		map[abs(a[i] - a[i + 1])]++;
//	}
//	for (int i = 1; i < n; i++) {
//		if (!map[i]) {
//			cout << "Not jolly" << endl;
//			break;
//		}
//
//		if (i == n - 1) {
//			cout << "Jolly" << endl;
//		}
//	}
//
//	return 0;
//}


// 2024 10 16
//P1307 [NOIP2011 普及组] 数字反转

//#include<bits/stdc++.h>
//using namespace std;
//
//int ans(int n) {
//	if (n < 0) {
//		return -ans(-n);
//	} else {
//		int x = 0;
//		while (n != 0) {
//			int ge = n % 10;
//			n /= 10;
//			x = x * 10 + ge;
//		}
//
//		return x;
//	}
//}
//
//int main() {
//	int n;
//	cin >> n;
//	cout << ans(n) << endl;
//	return 0;
//}


//2024 10 16
//P1420 最长连号
//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++) cin >> a[i];
//	if (n == 1) {
//		cout << 1 << endl;
//	} else {
//		int left = 0, right = 1;
//		int ans = 1;
//		while (right < n) {
//			if (a[right] - a[right - 1] != 1) {
//				left = right;
//			}
//			right++;
//			ans = max(ans, right - left);
//		}
//
//		cout << ans << endl;
//	}
//	return 0;
//}

//2024 10 18
//P1085 [NOIP2004 普及组] 不高兴的津津 答案貌似有问题
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	vector<int> a(14);
//	for (int i = 0; i < 14; i++) {
//		cin >> a[i];
//	}
//
//	vector<int> sum(7);
//	for (int i = 0; i < 7; i++) {
//		sum[i] = a[2 * i] + a[2 * i + 1];
//	}
//
//	int ans = 0;
//	int max_day = sum[0];
//	for (int i = 1; i < 7; i++) {
//		if (max_day < sum[i]) {
//			max_day = sum[i];
//			ans = i;
//		}
//	}
//
//	cout << ans + 1 << endl;
//	return 0;
//}

//2024 10 19 P1179 [NOIP2010 普及组] 数字统计
//#include <bits/stdc++.h>
//using namespace std;
//
//int tongji(int x) {
//	int ans = 0;
//	while (x != 0) {
//		if (x % 10 == 2) {
//			ans++;
//		}
//		x /= 10;
//	}
//	return ans;
//}
//
//int main() {
//	int l, r;
//	cin >> l >> r;
//	int ans = 0;
//	for (int i = l; i <= r; i++) {
//		ans += tongji(i);
//	}
//
//	cout << ans << endl;
//	return 0;
//}

//2024 10 20 P1427 小鱼的数字游戏
//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	vector<int> a;
//	int num;
//	while (scanf("%d", &num) != EOF) {
//		if (num == 0) {
//			break;
//		} else {
//			a.push_back(num);
//		}
//	}
//
//	for (int i = a.size() - 1; i >= 0; i--) {
//		cout << a[i] << ' ';
//	}
//	return 0;
//}

// 2024 10 20 P1739 表达式括号匹配
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	stack<char> a;
//	char c;
//	bool ans = true;
//	while (scanf("%c", &c) != EOF) {
//		if (c == '@') break;
//		if (c == '(') {
//			a.push(c);
//		} else if (c == ')') {
//			if (a.empty() || a.top() != '(') {
//				ans = false;
//				break;
//			} else {
//				a.pop();
//			}
//		}
//	}
//	if (!a.empty()) {
//		ans = false;
//	}
//	if (ans) {
//		cout << "YES" << endl;
//	} else {
//		cout << "NO" << endl;
//	}
//	return 0;
//}

//2024 10 20 B2034 计算 2 的幂 采用快速降幂法
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	int ans = 1;
//	int x = 2;
//	while (n != 0) {
//		if (n & 1) {
//			ans *= x;
//		}
//		n >>= 1;
//		x *= x;
//	}
//	cout << ans << endl;
//	return 0;
//}


//2024 11 9 P1102 A-B 数对
//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n, c;
//	cin >> n >> c;
//	vector<int> a(n);
//	unordered_map<int, int> mp;
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//		mp[a[i]]++;
//	}
//
//	long long ans = 0;
//	for (int i = 0; i < n; i++) {
//		ans += mp[a[i] - c];
//	}
//
//	cout << ans << endl;
//	return 0;
//}


//P1012 [NOIP1998 提高组] 拼数 2024 11 9
//#include <bits/stdc++.h>
//using namespace std;
//
//bool cmp(string& s1, string& s2) {
//	return s1 + s2 > s2 + s1;
//}
//
//
//int main() {
//	int n;
//	cin >> n;
//	vector<string> a(n);
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//
//	sort(a.begin(), a.end(), cmp);
//
//	for (string s : a) cout << s;
//	cout << endl;
//
//	return 0;
//}


//P1019 [NOIP2000 提高组] 单词接龙 2024 11 9-10
//#include<bits/stdc++.h>
//using namespace std;
//
//int n;
//vector<string> a(45);
//bool vis[45];
//string res;
//string ans = "";
//
//int check(string s) {
//	int s_len = s.size();
//	int r_len = res.size();
//
//	int x = min(s_len, r_len);
//
//	for (int j = 1; j <= x; j++) {
//		string s1(res.end() - j, res.end());
//		string s2(s.begin(), s.begin() + j);
//		if (s1 == s2) return j;
//	}
//
//	return 0;
//}
//
//void dfs(int step) {
//	if (ans.size() < res.size()) ans = res;
//	if (step > n) return;
//
//	for (int i = 0; i < n; i++) {
//		int idx = check(a[i]);
//		if (idx && vis[i] == 0) {
//			string temp(a[i].begin() + idx, a[i].end());
//			string res_ = res;
//			res += temp;
//			vis[i] = 1;
//			dfs(step + 1);
//			vis[i] = 0;
//			res = res_;
//		}
//	}
//}
//
//int main() {
//
//	cin >> n;
//	n *= 2;
//
//	for (int i = 0; i < n / 2; i++) {
//		cin >> a[2 * i];
//		a[2 * i + 1] = a[2 * i];
//	}
//	cin >> res;
//	dfs(0);
//	cout << ans.size() << endl;
//	return 0;
//}


//P1022 [NOIP2000 普及组] 计算器的改良 2024 11 10
//做了好久，终于没问题了
//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	string s;
//	cin >> s;
//	int idx;
//	char zimu;
//	for (int i = 0; i < (int)s.size(); i++) {
//		if (s[i] == '=') {
//			idx = i;
//			break;
//		}
//	}
//
//	for (int i = 0; i < (int)s.size(); i++) {
//		if (s[i] >= 'a' && s[i] <= 'z') {
//			zimu = s[i];
//			break;
//		}
//	}
//
//	vector<string> x;
//	int left = 0, right = 0;
//	while (right < idx) {
//
//		if (s[right] == '+' || s[right] == '-') {
//			if (right == 0) {
//				right++;
//				continue;
//			}
//			x.push_back(string(s.begin() + left, s.begin() + right));
//			left = right;
//		}
//		right++;
//	}
//	x.push_back(string(s.begin() + left, s.begin() + right));
//	if (x.front()[0] != '-') {
//		x.front() = '+' + x.front();
//	}
//
//	left = right = idx + 1;
//	while (right < (int)s.size()) {
//		if (s[right] == '+' || s[right] == '-') {
//			if (right == idx + 1) {
//				right++;
//				continue;
//			}
//			x.push_back(string(s.begin() + left, s.begin() + right));
//			if (x.back()[0] == '-') {
//				x.back() = '+' + string(x.back().begin() + 1, x.back().end());
//			} else if (x.back()[0] == '+') {
//				x.back() = '-' + string(x.back().begin() + 1, x.back().end());
//			} else {
//				x.back() = '-' + x.back();
//			}
//			left = right;
//		}
//		right++;
//	}
//
//	x.push_back(string(s.begin() + left, s.begin() + right));
//	if (x.back()[0] == '-') {
//		x.back() = '+' + string(x.back().begin() + 1, x.back().end());
//	} else if (x.back()[0] == '+') {
//		x.back() = '-' + string(x.back().begin() + 1, x.back().end());
//	} else {
//		x.back() = '-' + x.back();
//	}
//
//	int weizhi_xishu = 0;
//	int changshu = 0;
//
//	for (auto s : x) {
//		if (s.back() >= '0' && s.back() <= '9') {
//			if (s.front() == '+') {
//				changshu -= stoi(string(s.begin() + 1, s.end()));
//			} else {
//				changshu += stoi(string(s.begin() + 1, s.end()));
//			}
//		} else {
//			int xishu = s.size() == 2 ? 1 : stoi(string(s.begin() + 1, s.end() - 1));
//			if (s.front() == '+') {
//				weizhi_xishu += xishu;
//			} else {
//				weizhi_xishu -= xishu;
//			}
//		}
//	}
//
//	double ans = changshu == 0 ? 0 : changshu / (weizhi_xishu * 1.0);
//	printf("%c=%.3lf", zimu, ans);
//	return 0;
//}


//P1601 A+B Problem（高精）2024 11 11
//注意数组不要越界！！！
//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	string s1, s2;
//	cin >> s1 >> s2;
//	int wei = max(s1.size(), s2.size()) + 2;
//	vector<int> a1(wei), a2(wei);
//	for (int i = 0; i < (int)s1.size(); i++) {
//		a1[i] = s1[s1.size() - i - 1] - '0';
//	}
//	for (int i = 0; i < (int)s2.size(); i++) {
//		a2[i] = s2[s2.size() - i - 1] - '0';
//	}
//
//	vector<int> ans(wei);
//	for (int i = 0; i < wei - 1; i++) {
//		ans[i] += a1[i] + a2[i];
//		ans[i + 1] += ans[i] / 10;
//		ans[i] %= 10;
//	}
//
//	while (ans.back() == 0 && ans.size() > 1) ans.pop_back();
//
//	for (int i = ans.size() - 1; i >= 0; i--) {
//		cout << ans[i];
//	}
//	return 0;
//}


//P2142 高精度减法 2024 11 11
//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	string a, b;
//	cin >> a >> b;
//	bool is_fu;
//	bool have_ans = false;
//	if (a.length() > b.length()) is_fu = false;
//	else if (a.length() < b.length()) {
//		string temp = a;
//		a = b;
//		b = temp;
//		is_fu = true;
//	}
//	else {
//		int i;
//		for (i = 0; i < (int)a.length(); i++) {
//			if (a[i] > b[i]) {
//				is_fu = false;
//				break;
//			}
//			else if (a[i] < b[i]) {
//				string temp = a;
//				a = b;
//				b = temp;
//				is_fu = true;
//				break;
//			}
//		}
//
//		if (i == (int)a.length()) {
//			have_ans = true;
//		}
//	}
//
//	if (have_ans) {
//		cout << 0 << endl;
//	} else {
//		int wei = max(a.size(), b.size()) + 1;
//		vector<int> num1(wei), num2(wei), ans(wei);
//		for (int i = 0; i < (int)a.size(); i++) {
//			num1[i] = a[a.size() - i - 1] - '0';
//		}
//
//		for (int i = 0; i < (int)b.size(); i++) {
//			num2[i] = b[b.size() - i - 1] - '0';
//		}
//
//		for (int i = 0; i < wei - 1; i++) {
//			ans[i] += num1[i] - num2[i];
//			if (ans[i] < 0) {
//				ans[i] += 10;
//				ans[i + 1]--;
//			}
//		}
//
//		while (ans.back() == 0 && ans.size() > 1) ans.pop_back();
//
//		if (is_fu)  {
//			cout << '-';
//		}
//		for (int i = ans.size() - 1; i >= 0; i--) {
//			cout << ans[i];
//		}
//	}
//	return 0;
//}


//P1303 A*B Problem  2024 11 11
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	string s1, s2;
//	cin >> s1 >> s2;
//	int wei = s1.length() + s2.length() + 1;
//	vector<int> ans(wei);
//	vector<int> a(s1.size());
//	vector<int> b(s2.size());
//
//	for (int i = 0; i < (int)s1.size(); i++) {
//		a[i] = s1[s1.size() - i - 1] - '0';
//	}
//	for (int i = 0; i < (int)s2.size(); i++) {
//		b[i] = s2[s2.size() - i - 1] - '0';
//	}
//
//	for (int i = 0; i < (int)a.size(); i++) {
//		for (int j = 0; j < (int)b.size(); j++) {
//			ans[i + j] += a[i] * b[j];
//			ans[i + j + 1] += ans[i + j] / 10;
//			ans[i + j] %= 10;
//		}
//	}
//
//	while (ans.back() == 0 && ans.size() > 1) ans.pop_back();
//
//	for (int i = ans.size() - 1; i >= 0; i--) {
//		cout << ans[i];
//	}
//
//	return 0;
//}


//P1480 A/B Problem  2024 11 11
//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	string A;
//	int b;
//	cin >> A >> b;
//	vector<int> a(A.size());
//	vector<int> ans(A.size());
//	long long x = 0;
//
//	for (int i = 0; i < (int)a.size(); i++) {
//		a[i] = A[i] - '0';
//	}
//
//	for (int i = 0; i < (int)a.size(); i++) {
//		ans[i] = (x * 10 + a[i]) / b;
//		x = (x * 10 + a[i]) % b;
//	}
//
//	int tou = 0;
//	while (ans[tou] == 0 && tou <= (int)a.size() - 2) tou++;
//
//	for (int i = tou; i < (int)a.size(); i++) {
//		cout << ans[i];
//	}
//	return 0;
//}


//P1020 [NOIP1999 提高组] 导弹拦截 题解 2024 11 13 会超时，时间复杂度O(n^2)
//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	vector<int> a;
//	while (cin >> n) {
//		a.push_back(n);
//	}
//
//	vector<int> dp(a.size(), 1);
//	for (int i = 1; i < (int)a.size(); i++) {
//		for (int j = 0; j < i; j++) {
//			if (a[j] >= a[i]) {
//				dp[i] = max(dp[i], dp[j] + 1);
//			}
//		}
//	}
//
//	vector<int> dp2(a.size(), 1);
//	for (int i = 1; i < (int)a.size(); i++) {
//		for (int j = 0; j < i; j++) {
//			if (a[j] < a[i]) {
//				dp2[i] = max(dp2[i], dp2[j] + 1);
//			}
//		}
//	}
//
//	cout << *max_element(dp.begin(), dp.end()) << endl;
//	cout << *max_element(dp2.begin(), dp2.end()) << endl;
//	return 0;
//}


//同上题 算法时间复杂度改善为O(nlogn)
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	vector<int> x, y;
//	while (cin >> n) {
//		if (x.empty()) x.push_back(n);
//		else {
//			int left = 0, right = x.size();
//			while (left < right) {
//				int mid = (left + right) >> 1;
//				if (x[mid] >= n) {
//					left = mid + 1;
//				} else {
//					right = mid;
//				}
//			}
//
//			if (right == (int)x.size()) {
//				x.push_back(n);
//			} else {
//				x[right] = n;
//			}
//		}
//
//		if (y.empty()) y.push_back(n);
//		else {
//			int left = 0, right = y.size();
//			while (left < right) {
//				int mid = (left + right) >> 1;
//				if (y[mid] < n) {
//					left = mid + 1;
//				} else {
//					right = mid;
//				}
//			}
//
//			if (right == (int)y.size()) {
//				y.push_back(n);
//			} else {
//				y[right] = n;
//			}
//		}
//	}
//	cout << x.size() << endl;
//	cout << y.size() << endl;
//	return 0;
//}


//P1025 [NOIP2001 提高组] 数的划分 2024 11 14
//#include<bits/stdc++.h>
//using namespace std;
//
//int ans;
//
//void dfs(int deep, int k, int n, int sum, int pre) {
//	if (deep == k) {
//		if (sum == n) {
//			ans++;
//		}
//	} else {
//		for (int i = pre; i <= n; i++) {
//			if (sum + i > n) break;
//			else {
//				dfs(deep + 1, k, n, sum + i, i);
//			}
//		}
//	}
//}
//
//int main() {
//	int n, k;
//	cin >> n >> k;
//	dfs(0, k, n, 0, 1);
//	cout << ans << endl;
//	return 0;
//}


//P1037 [NOIP2002 普及组] 产生数
//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	string s;
//	int k;
//	cin >> s >> k;
//	vector<vector<bool>> guize(11, vector<bool>(11, false));
//	int x, y;
//	while (k--) {
//		cin >> x >> y;
//		guize[x][y] = true;
//	}
//	for (int i = 0; i <= 9; i++) guize[i][i] = true;
//
////	for (int k = 1; k <= 9; k++)
////		for (int i = 0; i <= 9; i++)
////			for (int j = 1; j <= 9; j++)
////				if (guize[i][k] && guize[k][j]) guize[i][j] = 1;
//
////  先把所有能通过k间接转化的数字求出，所以k在最外层，但k的枚举顺序并不重要
//	for (int k = 9; k >= 1; k--)
//		for (int j = 1; j <= 9; j++)
//			for (int i = 0; i <= 9; i++)
//				if (guize[i][k] && guize[k][j]) guize[i][j] = 1;
//
//
//	vector<int> cishu(11);
//	for (int i = 0; i <= 9; i++) {
//		for (int j = 0; j <= 9; j++) {
//			if (guize[i][j]) {
//				cishu[i]++;
//			}
//		}
//	}
//
//	vector<int> ans(40);
//	ans[0] = 1;
//	for (int i = 0; i < (int)s.size(); i++) {
//		int shu = s[i] - '0';
//		int x = 0;
//		for (int j = 0; j < (int)ans.size(); j++) {
//			ans[j] = ans[j] * cishu[shu] + x;
//			x = ans[j] / 10;
//			ans[j] %= 10;
//		}
//	}
//
//	while (ans.back() == 0 && ans.size() > 1) ans.pop_back();
//	for (int i = ans.size() - 1; i >= 0; i--) {
//		cout << ans[i];
//	}
//	cout << endl;
//	return 0;
//}


//P2392 kkksc03考前临时抱佛脚
//#include <bits/stdc++.h>
//using namespace std;
//
//void work(int p, vector<int>& a, int& ans, int l, int r) {
//	if (p == (int)a.size()) {
//		ans = min(ans, max(l, r));
//	} else {
//		if (l >= ans || r >= ans) return;
//		work(p + 1, a, ans, l + a[p], r);
//		work(p + 1, a, ans, l, r + a[p]);
//	}
//}
//
//int main() {
//	vector<int> num(4);
//	int ans = 0;
//	for (int i = 0; i < 4; i++) {
//		cin >> num[i];
//	}
//	for (int i = 0; i < 4; i++) {
//		vector<int> a(num[i]);
//		for (int j = 0; j < num[i]; j++) cin >> a[j];
//		int jubu_ans = 1e9, l = 0, r = 0;
//		work(0, a, jubu_ans, l, r);
//		ans += jubu_ans;
//	}
//
//	cout << ans << endl;
//	return 0;
//}


//B3837 [GESP202303 二级] 画三角形
//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	char x = 'A';
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < i + 1; j++) {
//			cout << x;
//			x++;
//			if (x == 'Z' + 1) x = 'A';
//		}
//		cout << endl;
//	}
//	return 0;
//}


//P1294 高手去散步 DFS
//#include<bits/stdc++.h>
//using namespace std;
//
//int n, m, x, y, z, ans, ans_;
//
//void dfs(int i, const vector<vector<int>>& a, vector<bool> &vis) {
//	for (int j = 1; j <= n; j++) {
//		if (j == i) continue;
//		if (!vis[j] && a[i][j]) {
//			vis[j] = 1;
//			ans += a[i][j];
//			dfs(j, a, vis);
//			ans -= a[i][j];
//			vis[j] = 0;
//		}
//	}
//
//	ans_ = max(ans, ans_);
//}
//
//int main() {
//	cin >> n >> m;
//	vector<vector<int>> a(n + 1, vector<int>(n + 1));
//	for (int i = 0; i < m; i++) {
//		cin >> x >> y >> z;
//		a[x][y] = z;
//		a[y][x] = z;
//	}
//
//	for (int i = 1; i <= n; i++) {
//		vector<bool> vis(n + 1);
//		vis[i] = 1;
//		dfs(i, a, vis);
//	}
//
//	cout << ans_ << endl;
//
//	return 0;
//}


//P1443 马的遍历 BFS
//#include<bits/stdc++.h>
//using namespace std;
//
//int n, m, x, y;
//int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
//int dy[] = {1, -1, 2, -2, 2, -2, 1, -1};
//
//int main() {
//	cin >> n >> m >> x >> y;
//	vector<vector<bool>> vis(n + 2, vector<bool>(m + 2));
//	vector<vector<int>> ans(n + 2, vector<int>(m + 2, -1));
//	queue<pair<int, int>> q;
//	ans[x][y] = 0;
//	vis[x][y] = 1;
//	q.push(make_pair(x, y));
//	while (!q.empty()) {
//		int xx = q.front().first, yy = q.front().second;
//		q.pop();
//		for (int i = 0; i < 8; i++) {
//			int x_ = xx + dx[i];
//			int y_ = yy + dy[i];
//			if (x_ < 1 || x_ > n || y_ < 1 || y_ > m || vis[x_][y_]) continue;
//			vis[x_][y_] = 1;
//			ans[x_][y_] = ans[xx][yy] + 1;
//			q.push(make_pair(x_, y_));
//		}
//	}
//
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			printf("%-5d", ans[i][j]);
//		}
//		cout << endl;
//	}
//
//	return 0;
//}


//P3367 【模板】并查集
//#include<bits/stdc++.h>
//using namespace std;
//
//int find(vector<int>& a, int x) {
//	if (a[x] != x) {
//		a[x] = find(a, a[x]);
//	}
//	return a[x];
//}
//
//void add(vector<int>& a, int x, int y) {
//	int x_fa = find(a, x);
//	int y_fa = find(a, y);
//	if (x_fa != y_fa) {
//		a[x_fa] = y_fa;
//	}
//}
//
//int main() {
//	int n, m, z, x, y;
//	cin >> n >> m;
//	vector<int> bin(n + 1);
//	for (int i = 1; i <= n; i++) {
//		bin[i] = i;
//	}
//	while (m--) {
//		cin >> z >> x >> y;
//		if (z == 1) {
//			add(bin, x, y);
//		} else {
//			if (find(bin, x) == find(bin, y)) {
//				cout << "Y" << endl;
//			} else {
//				cout << "N" << endl;
//			}
//		}
//	}
//	return 0;
//}



//P1096 [NOIP2007 普及组] Hanoi 双塔问题 高精度罢了
//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int> ans(300);
//	ans[0] = 2;
//	for (int i = 0; i < n; i++) {
//		int jin = 0;
//		for (int j = 0; j < 300; j++) {
//			ans[j] = jin + 2 * ans[j];
//			jin = ans[j] / 10;
//			ans[j] %= 10;
//		}
//	}
//
//	for (int i = 0; i < 300; i++) {
//		if (i == 0) {
//			ans[i] -= 2;
//			if (ans[i] < 0) {
//				ans[i + 1]--;
//				ans[i] += 10;
//			}
//		} else {
//			if (ans[i] < 0) {
//				ans[i + 1]--;
//				ans[i] += 10;
//			}
//		}
//	}
//
//	while (ans.back() == 0 && ans.size() > 1) ans.pop_back();
//
//	for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i];
//	cout << endl;
//	return 0;
//}


//P1182 数列分段 Section II 题解
//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	vector<int> a(n);
//	int r = 0;
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//		r += a[i];
//	}
//	int l = *max_element(a.begin(), a.end());
//	int ans;
//	while (l <= r) {
//		int mid = (l + r) >> 1;
//		int temp = 0, cnt = 1;
//		for (int i = 0; i < n; i++) {
//			if (a[i] + temp <= mid) {
//				temp += a[i];
//			} else {
//				temp = a[i];
//				cnt++;
//			}
//		}
//
//		if (cnt <= m) {
//			ans = mid;
//			r = mid - 1;
//		} else {
//			l = mid + 1;
//		}
//	}
//	cout << ans << endl;
//
//	return 0;
//}


//P1314 [NOIP2011 提高组] 聪明的质监员
//#include <bits/stdc++.h>
//using namespace std;
//
//using ll = long long;
//
//int main() {
//	int n, m;
//	ll s;
//	cin >> n >> m >> s;
//	vector<int> w(n + 1), v(n + 1), l(m + 1), r(m + 1);
//	int left = INT32_MAX, right = 0;
//	for (int i = 1; i <= n; i++) {
//		cin >> w[i] >> v[i];
//		left = min(left, w[i]);
//		right = max(right, w[i]);
//	}
//
//	left--;
//	right++;
//
//	for (int i = 1; i <= m; i++) {
//		cin >> l[i] >> r[i];
//	}
//
//	ll ans = LONG_LONG_MAX;
//
//	while (left <= right) {
//		ll Y = 0, temp;
//		int mid = (left + right) >> 1;
//		vector<ll> pre_w(n + 1), pre_v(n + 1);
//		for (int i = 1; i <= n; i++) {
//			if (mid <= w[i]) {
//				pre_w[i] = pre_w[i - 1] + 1;  //有病啊，搞了半天才发现是+1不是+w[i]
//				pre_v[i] = pre_v[i - 1] + v[i];
//			} else {
//				pre_w[i] = pre_w[i - 1];
//				pre_v[i] = pre_v[i - 1];
//			}
//		}
//
//		for (int i = 1; i <= m; i++) {
//			Y += (pre_w[r[i]] - pre_w[l[i] - 1]) * (pre_v[r[i]] - pre_v[l[i] - 1]);
//		}
//
//		temp = llabs(Y - s);
//		ans = min(ans, temp);
//
//		if (Y > s) {
//			left = mid + 1;
//		} else {
//			right = mid - 1;
//		}
//	}
//
//	cout << ans << endl;
//	return 0;
//}


//P1083 [NOIP2012 提高组] 借教室
//一个数组越界问题看了半天，3个小时绝对有，妈的
//#include<bits/stdc++.h>
//using namespace std;
//
//using ll = long long;
//
//bool is_ok(int x, int n, vector<vector<ll>>& b, vector<ll>& a) {
//	vector<ll> diff(n + 2);
//	for (int i = 1; i <= x; i++) {
//		diff[b[i][1]] += b[i][0];
//		diff[b[i][2] + 1] -= b[i][0];
//	}
//
//	vector<ll> need(n + 2);
//	for (int i = 1; i <= n; i++) {
//		need[i] = need[i - 1] + diff[i];
//		if (need[i] > a[i]) return false;
//	}
//	return true;
//}
//
//signed main() {
//	int n, m;
//	cin >> n >> m;
//	vector<ll> a(n + 1);
//	vector<vector<ll>> b(m + 1, vector<ll>(3));
//	for (int i = 1; i <= n; i++) cin >> a[i];
//	for (int i = 1; i <= m; i++) cin >> b[i][0] >> b[i][1] >> b[i][2];
//
//	if (is_ok(m, n, b, a)) cout << 0 << endl;
//	else {
//		int left = 1, right = m;
//		int ans = 0;
//		while (left <= right) {
//			int mid = (right + left) >> 1;
//			if (is_ok(mid, n, b, a)) {
//				left = mid + 1;
//			} else {
//				right = mid - 1;
//				ans = mid;
//			}
//		}
//
//		cout << -1 << endl;
//		cout << ans << endl;
//	}
//
//	return 0;
//}


//P1138 第 k 小整数
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n, k;
//	cin >> n >> k;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//
//	sort(a.begin(), a.end());
//	int left = 0, right = 1;
//	while (right < n) {
//		if (a[right] != a[right - 1]) {
//			a[++left] = a[right];
//		}
//		right++;
//	}
//
//	if (k - 1 <= left) {
//		cout << a[k - 1] << endl;
//	} else {
//		cout << "NO RESULT" << endl;
//	}
//	return 0;
//}


//P2367 语文成绩 (差分)
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n, p;
//	cin >> n >> p;
//	vector<int> a(n + 1);
//	vector<int> x(p + 1);
//	vector<int> y(p + 1);
//	vector<int> z(p + 1);
//	vector<int> cha(n + 2);
//	for (int i = 1; i <= n; i++) cin >> a[i];
//	for (int i = 1; i <= p; i++) cin >> x[i] >> y[i] >> z[i];
//
//	for (int i = 1; i <= p; i++) {
//		cha[x[i]] += z[i];
//		cha[y[i] + 1] -= z[i];
//	}
//
//	vector<int> temp(n + 2);
//	for (int i = 1; i <= n; i++) {
//		temp[i] = temp[i - 1] + cha[i];
//		a[i] += temp[i];
//	}
//
//	cout << *min_element(a.begin() + 1, a.end());
//	return 0;
//}


//P1097 [NOIP2007 提高组] 统计数字
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	unordered_map<int, int> mp;
//	set<int> a;
//	int n, x;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> x;
//		a.insert(x);
//		mp[x]++;
//	}
//
//	for (auto i = a.begin(); i != a.end(); i++) {
//		cout << *i << ' ' <<  mp[*i] << endl;
//	}
//
//	return 0;
//}



//P5739 【深基7.例7】计算阶乘
//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	int ans = 1;
//	while (n >= 2) {
//		ans *= n;
//		n--;
//	}
//	cout << ans << endl;
//	return 0;
//}


//P1059 [NOIP2006 普及组] 明明的随机数
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n, x;
//	cin >> n;
//	set<int> a;
//	while (n--) {
//		cin >> x;
//		a.insert(x);
//	}
//
//	cout << a.size() << endl;
//	for (int i : a) {
//		cout << i << ' ';
//	}
//	return 0;
//}


//[NOIP2007 普及组] 奖学金
//#include <bits/stdc++.h>
//using namespace std;
//
//bool cmp(vector<int>& a, vector<int>& b) {
//	int suma = a[1] + a[2] + a[3];
//	int sumb = b[1] + b[2] + b[3];
//	if (suma > sumb) return true;
//	else if (suma < sumb) return false;
//	else {
//		if (a[1] > b[1]) return true;
//		else if (a[1] < b[1]) return false;
//
//		return a[0] < b[0];
//	}
//}
//
//int main() {
//	int n;
//	cin >> n;
//	vector<vector<int>> a(n + 1, vector<int>(4));
//	for (int i = 1; i <= n; i++) {
//		a[i][0] = i;
//		cin >> a[i][1] >> a[i][2] >> a[i][3];
//	}
//
//	sort(a.begin() + 1, a.end(), cmp);
//
//	for (int i = 1; i <= 5; i++) {
//		cout << a[i][0] << ' ' << a[i][1] + a[i][2] + a[i][3] << endl;
//	}
//	return 0;
//}


//P2404 自然数的拆分问题 dfs
//#include<bits/stdc++.h>
//using namespace std;
//
//int n, sum;
//
//void dfs(int a, vector<int>& x) {
//	if (sum == n) {
//		for (int i = 0; i < (int)x.size(); i++) {
//			cout << x[i] << "+\n"[i == (int)x.size() - 1];
//		}
//	}
//	for (int i = a; i < n; i++) {
//		if (sum > n) return;
//		sum += i;
//		x.push_back(i);
//		dfs(i, x);
//		x.pop_back();
//		sum -= i;
//	}
//}
//
//int main() {
//	cin >> n;
//	vector<int> x;
//	dfs(1, x);
//}


//P1036 [NOIP2002 普及组] 选数
//#include <bits/stdc++.h>
//using namespace std;
//
//bool is_prime(int n) {
//	for (int i = 2; i * i <= n; i++) {
//		if (n % i == 0) return false;
//	}
//	return true;
//}
//
//void getAns(vector<int>& a, int deep, int k, int sum, int & ans, int start) {
//	if (deep == k) {
//		if (is_prime(sum)) ans++;
//	} else {
//		for (int i = start; i < (int)a.size(); i++) {
//			getAns(a, deep + 1, k, sum + a[i], ans, i + 1);
//		}
//	}
//}
//
//int main() {
//	int n, k;
//	cin >> n >> k;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++) cin >> a[i];
//	int ans = 0;
//	getAns(a, 0, k, 0, ans, 0);
//	cout << ans << endl;
//	return 0;
//}


//P1271 【深基9.例1】选举学生会
//#include <bits/stdc++.h>
//using namespace std;
//
//int a[1000];
//
//int main() {
//	int n, m, x;
//	cin >> n >> m;
//	for (int i = 1; i <= m; i++) {
//		cin >> x;
//		a[x]++;
//	}
//
//	for (int i = 1; i <= 999; i++) {
//		for (int j = 0; j < a[i]; j++) {
//			cout << i << ' ';
//		}
//	}
//}


//P3078 [USACO13MAR] Poker Hands S
//#include <bits/stdc++.h>
//using namespace std;
//
//using ll = long long;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<ll> a(n);
//	for (int i = 0; i < n; i++) cin >> a[i];
//	ll ans = a[0];
//	for (int i = 1; i < n; i++) {
//		if (a[i] > a[i - 1]) ans += a[i] - a[i - 1];
//	}
//
//	cout << ans << endl;
//	return 0;
//}


//P1018 [NOIP2000 提高组] 乘积最大 低精度 而且代码有问题
//#include <bits/stdc++.h>
//using namespace std;
//
//long long shu(string s, int l, int r) {
//	string s2(s.begin() + l, s.begin() + r + 1);
//	return stoll(s2);
//}
//
//int main() {
//	int n, k;
//	string s;
//	cin >> n >> k >> s;
//	s = ' ' + s;
//	vector<vector<long long>> a(n + 1, vector<long long>(n + 1));
//	for (int i = 1; i <= n; i++) {
//		a[i][0] = s[i] - '0';
//	}
//
//	for (int i = 2; i <= n; i++) {
//		for (int j = 1; j <= i - 1; j++) {
//			for (int k = 1; k <= i - 1; k++) {
//				a[i][j] = max(a[i - k][j - 1] * shu(s, i - k + 1, i), a[i][j]);
//			}
//		}
//	}
//
//	cout << a[n][k] << endl;
//	return 0;
//}


//P1141 01迷宫  搞了好久，不知道自己方法到底哪里出问题了，这是借鉴别人的方法
//#include <bits/stdc++.h>
//using namespace std;
//
//int dx[] = {0, 0, -1, 1};
//int dy[] = {1, -1, 0, 0};
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	vector<string> s(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> s[i];
//		s[i] = ' ' + s[i];
//	}
//	vector<vector<bool>> vis(n + 1, vector<bool>(n + 1));
//	vector<vector<int>> ans(n + 1, vector<int>(n + 1, 0));
//
//	int x, y;
//	for (int i = 0; i < m; i++) {
//		cin >> x >> y;
//		if (ans[x][y] != 0) {
//			cout << ans[x][y] << endl;
//		} else {
//			queue<pair<int, int>> q;
//			vector<pair<int, int>> pos;
//			pos.push_back(make_pair(x, y));
//			q.push(make_pair(x, y));
//			vis[x][y] = 1;
//			int ans_t = 1;
//			while (!q.empty()) {
//				pair<int, int> dangqian = q.front();
//				q.pop();
//				for (int j = 0; j < 4; j++) {
//					int x_ = dangqian.first + dx[j];
//					int y_ = dangqian.second + dy[j];
//					if (x_ <= 0 || x_ > n || y_ <= 0 || y_ > n || vis[x_][y_])
//						continue;
//					else {
//						if (s[x_][y_] == s[dangqian.first][dangqian.second])
//							continue;
//					}
//					ans_t++;
//					vis[x_][y_] = 1;
//					q.push(make_pair(x_, y_));
//					pos.push_back(make_pair(x_, y_));
//				}
//			}
//
//			for (auto i : pos) {
//				ans[i.first][i.second] = ans_t;
//			}
//
//			cout << ans_t << endl;
//		}
//	}
//
//	return 0;
//}


//P7771 【模板】欧拉路径 会MLE，下面考虑邻接表优化
//#include <bits/stdc++.h>
//using namespace std;
//
//void find_way(vector<vector<int>>& a, int i, vector<int>& ans, int n) {
//	for (int j = 1; j <= n; j++) {
//		if (a[i][j] > 0) {
//			a[i][j]--;
//			find_way(a, j, ans, n);
//		}
//	}
//	ans.push_back(i);
//}
//
//int main() {
//	int n, m, u, v;
//	cin >> n >> m;
//	vector<vector<int>> a(n + 1, vector<int>(n + 1));
//	for (int i = 1; i <= m; i++) {
//		cin >> u >> v;
//		a[u][v]++;
//	}
//
//	vector<int> du(n + 1);
//	int ji = 0;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			if (a[i][j] > 0) {
//				du[i] += a[i][j];
//				du[j] -= a[i][j];
//			}
//		}
//	}
//
//	int ru = 0, chu = 0;
//	bool no_ans = false;
//
//	for (int i = 1; i <= n; i++) {
//		if (du[i] == 1) {
//			chu++;
//			ji = i;
//		} else if (du[i] == -1) ru++;
//		else if (du[i] != 0) {
//			no_ans = true;
//			break;
//		}
//	}
//
//	if (no_ans) cout << "No" << endl;
//	else {
//		if ((ru == 1 && chu == 1) || (ru == 0 && chu == 0)) {
//			vector<int> ans;
//			if (ji) {
//				find_way(a, ji, ans, n);
//			} else {
//				find_way(a, 1, ans, n);
//			}
//
//			for (int i = ans.size() - 1; i >= 0; i--) {
//				cout << ans[i] << ' ';
//			}
//		} else {
//			cout << "No" << endl;
//		}
//	}
//	return 0;
//}


//P7771 【模板】欧拉路径 英雄哥：过啦！
//#include<bits/stdc++.h>
//using namespace std;
//
//void get_way(const vector<vector<int>>& G, int start, vector<int>& start_at, vector<int>& ans) {
//	for (int i = start_at[start]; i < (int)G[start].size(); i = start_at[start]) {
//		start_at[start]++;
//		get_way(G, G[start][i], start_at, ans);
//	}
//	ans.push_back(start);
//}
//
//int main() {
//	int n, m, u, v;
//	cin >> n >> m;
//	vector<vector<int>> G(n + 1, vector<int>());
//	vector<int> du(n + 1);
//	for (int i = 1; i <= m; i++) {
//		cin >> u >> v;
//		G[u].push_back(v);
//		du[u]++;
//		du[v]--;
//	}
//
//	for (int i = 1; i <= n; i++) {
//		sort(G[i].begin(), G[i].end());
//	}
//
//	int chu = 0, ru = 0;
//	bool no_ans = false;
//	int qi = 0;
//	for (int i = 1; i <= n; i++) {
//		if (du[i] == 1) {
//			qi = i;
//			chu++;
//		} else if (du[i] == -1) ru++;
//		else if (du[i] != 0) {
//			no_ans = true;
//			break;
//		}
//	}
//
//	if (no_ans) cout << "No" << endl;
//	else {
//		if ((chu == 0 && ru == 0) || (chu == 1 && ru == 1)) {
//			vector<int> ans;
//			vector<int> start_at(n + 1);
//			if (qi) {
//				get_way(G, qi, start_at, ans);
//			} else {
//				get_way(G, 1, start_at, ans);
//			}
//
//			for (int i = ans.size() - 1; i >= 0; i--) {
//				cout << ans[i] << ' ';
//			}
//		} else {
//			cout << "No" << endl;
//		}
//	}
//
//	return 0;
//}


// P1341 无序字母对
//#include<bits/stdc++.h>
//using namespace std;
//
//const int N = 'z' + 2;
//
//void get_way(vector<vector<int>>& g, int start, vector<int>& ans) {
//	for (int i = 0; i < N; i++) {
//		if (g[start][i] > 0) {
//			g[start][i]--;
//			g[i][start]--;
//			get_way(g, i, ans);
//		}
//	}
//	ans.push_back(start);
//}
//
//int main() {
//	int n;
//	string s;
//	cin >> n;
//	vector<vector<int>> g(N, vector<int>(N));
//	vector<int> du(N);
//	for (int i = 0; i < n; i++) {
//		cin >> s;
//		g[s[0]][s[1]]++;
//		g[s[1]][s[0]]++;
//		du[s[0]]++;
//		du[s[1]]++;
//	}
//
//	int cnt = 0;
//	int start = 0;
//	for (int i = 0; i < N; i++) {
//		if (du[i] & 1) {
//			cnt++;
//			if (!start) {
//				start = i;
//			}
//		}
//	}
//
//	if (cnt != 0 && cnt != 2) cout << "No Solution" << endl;
//	else {
//		if (!start) {
//			for (int i = 0; i < N; i++) {
//				if (du[i] > 0) {
//					start = i;
//					break;
//				}
//			}
//		}
//
//		vector<int> ans;
//		get_way(g, start, ans);
//
//		for (int i = ans.size() - 1; i >= 0; i--) {
//			cout << (char)ans[i];
//		}
//	}
//	return 0;
//}


//P1018 [NOIP2000 提高组] 乘积最大  再次挑战  2024 11 30
//挑战成功！坚持就是胜利！做了至少也有一个半小时吧（肯定不止），但我坚持下来了！！！
//#include <bits/stdc++.h>
//using namespace std;
//
//string maxs(string s1, string s2) {
//	if (s1 == s2) return s1;
//	if (s1.size() > s2.size()) return s1;
//	else if (s1.size() < s2.size()) return s2;
//	else {
//		for (int i = 0; i < (int)s1.size(); i++) {
//			if (s1[i] > s2[i]) return s1;
//			else if (s1[i] < s2[i]) return s2;
//		}
//	}
//	return "";
//}
//
//string operator*(string s1, string s2) {
//	if (s1 == "0" || s2 == "0") return "0";
//	reverse(s1.begin(), s1.end());
//	reverse(s2.begin(), s2.end());
//	string ans(s1.size() + s2.size() + 2, '0');
//	for (int i = 0; i < (int)s1.size(); i++) {
//		for (int j = 0; j < (int)s2.size(); j++) {
//			int a = s1[i] - '0';
//			int b = s2[j] - '0';
//			int c = ans[i + j] - '0' + a * b;
//			int d = ans[i + j + 1] - '0' + c / 10;
//			c %= 10;
//
//			ans[i + j] = (char)('0' + c);
//			ans[i + j + 1] = (char)('0' + d);
//		}
//	}
//	while (ans.back() == '0' && ans.size() > 1) ans.pop_back();
//	reverse(ans.begin(), ans.end());
//	return ans;
//}
//
//int main() {
//	int n, k;
//	string s;
//	cin >> n >> k >> s;
//	s = ' ' + s;
//	vector<vector<string>> ans(n + 1, vector<string>(n + 1, "0"));
//	for (int i = 1; i <= n; i++) {
//		ans[i][0] = s.substr(1, i);
//	}
//	for (int j = 1; j <= k; j++) {
//		for (int i = 2; i <= n; i++) {
//			for (int k = 1; k <= i - 1; k++) {
//				ans[i][j] = maxs(ans[k][j - 1] * s.substr(k + 1, i - (k + 1) + 1), ans[i][j]);
//			}
//		}
//	}
//
//	cout << ans[n][k];
//
//	return 0;
//}


//P1029 [NOIP2001 普及组] 最大公约数和最小公倍数问题
//数学 数论
//#include <bits/stdc++.h>
//using namespace std;
//
//#define int long long
//
//signed main() {
//	int x, y;
//	cin >> x >> y;
//	int ans = 0;
//	if (x == y) ans--;
//	y *= x;
//	for (int i = 1; i * i <= y; i++) {
//		if (y % i == 0 && gcd(y / i, i) == x) ans += 2;
//	}
//	cout << ans << endl;
//	return 0;
//}



//P1008 [NOIP1998 普及组] 三连击
//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	for (int i = 100; i <= 333; i++) {
//		vector<int> mp(10);
//		string a = to_string(i);
//		string b = to_string(2 * i);
//		string c = to_string(3 * i);
//		vector<string> s = {a, b, c};
//		for (int i = 0; i < 3; i++) {
//			for (int j = 0; j < 3; j++) {
//				mp[s[i][j] - '0']++;
//			}
//		}
//
//		bool is_ans = true;
//		for (int i = 1; i <= 9; i++) {
//			if (mp[i] != 1) {
//				is_ans = false;
//				break;
//			}
//		}
//
//		if (is_ans) {
//			cout << a << ' ' << b << ' ' << c << ' ' << endl;
//		}
//	}
//	return 0;
//}


//P1142 轰炸 较暴力
//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<pair<int, int>> pos(n);
//	for (int i = 0; i < n; i++) {
//		cin >> pos[i].first >> pos[i].second;
//	}
//
//	int ans = 0;
//	for (int i = 0; i < n - 1; i++) {
//		for (int j = i + 1; j < n; j++) {
//			int cnt = 2;
//			pair<int, int> v = make_pair(pos[i].first - pos[j].first, pos[i].second - pos[j].second);
//			for (int k = 0; k < n; k++) {
//				if (k == i || k == j) continue;
//				pair<int, int> v2 = make_pair(pos[k].first - pos[j].first, pos[k].second - pos[j].second);
//				if (v.first * v2.second == v.second * v2.first) {
//					cnt++;
//				}
//			}
//
//			ans = max(ans, cnt);
//		}
//	}
//
//	cout << ans << endl;
//	return 0;
//}


//P1031 [NOIP2002 提高组] 均分纸牌  看题解的答案，比较巧妙
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++) cin >> a[i];
//	int sum = 0;
//	for (int i = 0; i < n; i++) sum += a[i];
//	sum = sum / n;
//	int ans = 0;
//	for (int i = 0; i < n; i++) {
//		if (a[i] - sum) {
//			a[i + 1] += a[i] - sum;
//			ans++;
//		}
//	}
//
//	cout << ans << endl;
//
//	return 0;
//}



//P1042 [NOIP2003 普及组] 乒乓球
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	vector<char> s;
//	char c;
//	while (cin >> c) {
//		if (c == 'E') break;
//		s.push_back(c);
//	}
//
//	int a = 0, b = 0;
//	for (int i = 0; i < (int)s.size(); i++) {
//		if (s[i] == 'W') a++;
//		else b++;
//		// 注意先加分再判断是否赢
//		if ((a >= 11 || b >= 11) && abs(a - b) >= 2) {
//			cout << a << ':' << b << endl;
//			a = b = 0;
//		}
//	}
//
//	cout << a << ':' << b << endl << endl;
//
//	a = 0, b = 0;
//	for (int i = 0; i < (int)s.size(); i++) {
//		if ((a >= 21 || b >= 21) && abs(a - b) >= 2) {
//			cout << a << ':' << b << endl;
//			a = b = 0;
//		}
//		if (s[i] == 'W') a++;
//		else b++;
//	}
//
//	cout << a << ':' << b << endl;
//
//	return 0;
//}


//P1051 [NOIP2005 提高组] 谁拿了最多奖学金
//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n, sum = 0, first_qian = 0, sum_geren = 0;
//	string first_name, name;
//	int qimo, pinyi, lunwen;
//	char a, b;
//	cin >> n;
//	while (n--) {
//
//		cin >> name >> qimo >> pinyi >> a >> b >> lunwen;
//		if (qimo > 80 && lunwen >= 1) sum_geren += 8000;
//		if (qimo > 85 && pinyi > 80) sum_geren += 4000;
//		if (qimo > 90) sum_geren += 2000;
//		if (qimo > 85 && b == 'Y') sum_geren += 1000;
//		if (pinyi > 80 && a == 'Y') sum_geren += 850;
//      一开始写成 qimo > 80 了，找了半天，服了！
//
//		sum += sum_geren;
//
//		if (sum_geren > first_qian) {
//			first_name = name;
//			first_qian = sum_geren;
//		}
//
//		sum_geren = 0;
//	}
//
//	cout << first_name << endl << first_qian << endl << sum << endl;
//	return 0;
//}


//P1146 硬币翻转
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	cout << n << endl;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			if (i == j) cout << a[j];
//			else {
//				a[j] = a[j] == 0 ? 1 : 0;
//				cout << a[j];
//			}
//		}
//		cout << endl;
//	}
//	return 0;
//}


//P1145 约瑟夫
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	int ans = n + 1;
//
//	bool have_ans = false;
//	while (true) {
//		int mod = 2 * n;
//		int shan = 0;
//		for (int i = 1; i <= n; i++) {
//			shan = (shan + ans - 1) % mod;
//			mod -= 1;
//			if (shan < n) break;
//			if (i == n) have_ans = true;
//		}
//
//		if (have_ans) break;
//		ans++;
//	}
//
//	cout << ans << endl;
//	return 0;
//}


//B3637 最长上升子序列
//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++) cin >> a[i];
//	vector<int> dp(n, 1);
//
//	for (int i = 1; i < n; i++) {
//		for (int j = 0; j < i; j++) {
//			if (a[j] < a[i]) dp[i] = max(dp[j] + 1, dp[i]);
//		}
//	}
//
//	cout << *max_element(dp.begin(), dp.end()) << endl;
//
//	return 0;
//}


//P1048 [NOIP2005 普及组] 采药  01背包问题
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int t, m;
//	cin >> t >> m;
//	vector<pair<int, int>> a(m);
//	for (int i = 0; i < m; i++) {
//		cin >> a[i].first >> a[i].second;
//	}
//
//	vector<int> ans(t + 1);
//	for (int i = 0; i < m; i++) {
//		for (int j = t; j >= 1; j--) {
//			if (j >= a[i].first) ans[j] = max(ans[j - a[i].first] + a[i].second, ans[j]);
//		}
//	}
//
//	cout << ans[t] << endl;
//	return 0;
//}


//P1049 [NOIP2001 普及组] 装箱问题  换一种思维的01背包问题
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int v, n;
//	cin >> v >> n;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++) cin >> a[i];
//	vector<int> ans(v + 1);
//
//	for (int i = 0; i < n; i++) {
//		for (int j = v; j >= 1; j--) {
//			if (j >= a[i]) ans[j] = max(ans[j - a[i]] + a[i], ans[j]);
//		}
//	}
//
//	cout << v - ans[v] << endl;
//
//	return 0;
//}


//P1060 [NOIP2006 普及组] 开心的金明
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	vector<pair<int, int>> a(m);
//	for (int i = 0; i < m; i++) {
//		cin >> a[i].first >> a[i].second;
//		a[i].second *= a[i].first;
//	}
//
//	vector<int> ans(n + 1);
//	for (int i = 0; i < m; i++) {
//		for (int j = n; j >= 1; j--) {
//			if (j >= a[i].first) ans[j] = max(ans[j - a[i].first] + a[i].second, ans[j]);
//		}
//	}
//
//	cout << ans[n] << endl;
//	return 0;
//}


//P1064 [NOIP2006 提高组] 金明的预算方案  绿题
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	int a, b, c;
//
//	vector<pair<pair<int, int>, vector<pair<int, int>>>> p(m + 1);
//	vector<int> zhu;
//
//	for (int i = 0; i <= m; i++) {
//		p[i].second.resize(3);
//	}
//
//	for (int i = 1; i <= m; i++) {
//		cin >> a >> b >> c;
//		if (c != 0) {
//			p[c].second[0].first++;
//			p[c].second[p[c].second[0].first] = make_pair(a, a * b);
//		} else {
//			zhu.push_back(i);
//			p[i].first.first = a;
//			p[i].first.second = a * b;
//		}
//	}
//	vector<int> ans(n + 1);
//
//	for (int k = 0; k < (int)zhu.size(); k++) {
//		int i = zhu[k];
//		for (int j = n; j >= p[i].first.first; j--) {
//			ans[j] = max(ans[j - p[i].first.first] + p[i].first.second, ans[j]);
//
//			if (j >= p[i].first.first + p[i].second[1].first)
//				ans[j] = max(ans[j], ans[j - p[i].first.first - p[i].second[1].first] + p[i].first.second + p[i].second[1].second);
//
//			if (j >= p[i].first.first + p[i].second[2].first)
//				ans[j] = max(ans[j], ans[j - p[i].first.first - p[i].second[2].first] + p[i].first.second + p[i].second[2].second);
//
//			if (j >= p[i].first.first + p[i].second[1].first + p[i].second[2].first)
//				ans[j] = max(ans[j], ans[j - p[i].first.first - p[i].second[1].first - p[i].second[2].first] + p[i].first.second + p[i].second[1].second + p[i].second[2].second);
//
//		}
//	}
//
//	cout << ans[n] << endl;
//
//	return 0;
//}


// 同上一题，一开始自己的写法，一直有问题，才发现是把num写成n造成的，无语了，看了半天！
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	int a, b, c;
//
//	vector<pair<pair<int, int>, vector<pair<int, int>>>> p(m + 1);
//	vector<int> zhu;
//
//	for (int i = 1; i <= m; i++) {
//		cin >> a >> b >> c;
//		if (c != 0) {
//			p[c].second.push_back(make_pair(a, a * b));
//		} else {
//			zhu.push_back(i);
//			p[i].first.first = a;
//			p[i].first.second = a * b;
//		}
//	}
//	vector<int> ans(n + 1);
//
//	for (int k = 0; k < (int)zhu.size(); k++) {
//		int i = zhu[k];
//		for (int j = n; j >= 1; j--) {
//			if (j >= p[i].first.first) ans[j] = max(ans[j - p[i].first.first] + p[i].first.second, ans[j]);
//			int num = p[i].second.size();
//			if (num == 1) {
//				if (j >= p[i].first.first + p[i].second[0].first) {
//					ans[j] = max(ans[j], ans[j - p[i].first.first - p[i].second[0].first] + p[i].first.second + p[i].second[0].second);
//				}
//			} else if (num == 2) {
//				if (j >= p[i].first.first + p[i].second[0].first)
//					ans[j] = max(ans[j], ans[j - p[i].first.first - p[i].second[0].first] + p[i].first.second + p[i].second[0].second);
//
//				if (j >= p[i].first.first + p[i].second[1].first)
//					ans[j] = max(ans[j], ans[j - p[i].first.first - p[i].second[1].first] + p[i].first.second + p[i].second[1].second);
//
//				if (j >= p[i].first.first + p[i].second[0].first + p[i].second[1].first)
//					ans[j] = max(ans[j], ans[j - p[i].first.first - p[i].second[0].first - p[i].second[1].first] + p[i].first.second + p[i].second[0].second + p[i].second[1].second);
//			}
//		}
//	}
//
//	cout << ans[n] << endl;
//
//	return 0;
//}


//P2789 直线交点数  其实还是有点难理解，需要长期思考，领悟其中精髓
//#include <bits/stdc++.h>
//using namespace std;
//
//void dfs(int n, int sum, vector<bool>& ans) {
//	if (n == 0) {
//		ans[sum] = true;
//	} else {
//		for (int i = 1; i <= n; i++) {
//			dfs(n - i, sum + i * (n - i), ans);
//		}
//	}
//}
//
//int main() {
//	int n;
//	cin >> n;
//	vector<bool> a(n * n);
//
//	dfs(n, 0, a);
//
//	int ans = 0;
//	for (int i = 0; i < n * n; i++) {
//		if (a[i]) ans++;
//	}
//	cout << ans << endl;
//
//	return 0;
//}


//P2249 【深基13.例1】查找
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++) cin >> a[i];
//	int x;
//	while (m--) {
//		cin >> x;
//		int l = 0, r = n - 1;
//		while (l <= r) {
//			int mid = (l + r) >> 1;
//			if (a[mid] < x) {
//				l = mid + 1;
//			} else {
//				r = mid - 1;
//			}
//		}
//
//		if (a[r + 1] == x) cout << r + 2 << ' ';
//		else cout << -1 << ' ';
//	}
//	return 0;
//}


//P1873 [COCI 2011/2012 #5] EKO / 砍树
//#include <bits/stdc++.h>
//using namespace std;
//
//#define int long long
//
//signed main() {
//	int n, m;
//	cin >> n >> m;
//	vector<int> a(n);
//	int l = 0, r = -1;
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//		r = max(r, a[i]);
//	}
//
//	while (l <= r) {
//		int sum = 0;
//		int mid = (l + r) >> 1;
//		for (int i = 0; i < n; i++) {
//			sum += max(0LL, a[i] - mid);
//		}
//
//		if (sum >= m) {
//			l = mid + 1;
//		} else {
//			r = mid - 1;
//		}
//	}
//
//	cout << l - 1 << endl;
//
//	return 0;
//}


//P1895 数字序列
//#include <bits/stdc++.h>
//using namespace std;
//
//#define int long long
//
//signed main() {
//	int t;
//	cin >> t;
//	int x;
//
//	while (t--) {
//		cin >> x;
//		string s;
//		int len = 0;
//		for (int i = 1; ; i++) {
//			s += to_string(i);
//			len += s.size();
//			if (len >= x) {
//				len -= s.size();
//				cout << s[x - len - 1] << endl;
//				break;
//			}
//		}
//	}
//	return 0;
//}


//P8764 [蓝桥杯 2021 国 BC] 二进制问题
//#include <bits/stdc++.h>
//using namespace std;
//
//#define int long long
//
//// 组合数C n m
//int C(int n, int m) {
//	int res = 1;
//	for (int i = n, j = 1; j <= m; i--, j++) {
//		// 千万注意不能写 res *= i / j
//		res = res * i / j;
//	}
//	return res;
//}
//
//
//signed main() {
//	int n, k;
//	cin >> n >> k;
//	int cnt = 0, ans = 0;
//	for (int i = 62; i >= 0; i--) {
//		if ((1LL << i) & n) {
//			cnt++;
//			if (k - cnt + 1 == 0) {
//				ans++;
//				break;
//			}
//			ans += C(i, k - cnt + 1);
//		}
//	}
//
//	if (cnt == k) ans++;
//	cout << ans << endl;
//	return 0;
//}



//P3390 【模板】矩阵快速幂   几乎就是头歌复制粘贴，等下自己独立写一下
//#include<iostream>
//#include<stdio.h>
//using namespace std;
//#define maxn 110
//const long long mod = 1000000007;
//long long size_;
//struct Matrix {
//	long long a[maxn][maxn];
//	Matrix operator*(const Matrix &B) {
//		Matrix ret;
//		int i, j, k;
//		for (i = 0; i < size_; i++) {
//			for (j = 0; j < size_; j++) {
//				ret.a[i][j] = 0;
//				for (k = 0; k < size_; k++)
//					ret.a[i][j] += a[i][k] % mod * (B.a[k][j] % mod) % mod, ret.a[i][j] %= mod;
//			}
//		}
//		return ret;
//	}
//	void setE() {
//		for (int i = 0; i < size_; i++) {
//			a[i][i] = 1;
//		}
//	}
//	Matrix pow(long long n) {
//		Matrix t, A;
//		t.setE();
//		A = *this;
//		while (n > 0) {
//			if (n & 1) t = t * A;
//			A = A*A;
//			n >>= 1;
//		}
//		return t;
//	}
//	void pr() {
//		for (int i = 0; i < size_; i++) {
//			for (int j = 0; j < size_; j++) {
//				printf("%lld ", a[i][j] % mod);
//			}
//			printf("\n");
//		}
//	}
//} M;
//int main() {
//	long long k, i, j;
//	scanf("%lld%lld", &size_, &k);
//	for (i = 0; i < size_; i++) {
//		for (j = 0; j < size_; j++)
//			scanf("%lld", &M.a[i][j]);
//	}
//	Matrix t = M.pow(k);
//	t.pr();
//	return 0;
//}

// 同上题 自己写的，过了，但其实并不是那么顺利
//#include <bits/stdc++.h>
//using namespace std;
//
//#define int long long
//const int maxn = 110;
//const int mod = 1e9 + 7;
//
//int size_;
//
//struct Matrix {
//	int a[maxn][maxn];
//	void setE() {
//		for (int i = 0; i < size_; i++) {
//			a[i][i] = 1;
//		}
//	}
//
//	Matrix operator*(const Matrix& B) {
//		Matrix res;
//		for (int i = 0; i < size_; i++) {
//			for (int j = 0; j < size_; j++) {
//				res.a[i][j] = 0;
//				for (int k = 0; k < size_; k++) {
//					res.a[i][j] += a[i][k] % mod * (B.a[k][j] % mod) % mod;
//					res.a[i][j] %= mod;
//				}
//			}
//		}
//		return res;
//	}
//
//	Matrix pow(int k) {
//		Matrix t;
//		t.setE();
//		Matrix b = *this;
//		while (k > 0) {
//			if (k & 1) t = t * b;
//			b = b * b;
//			k >>= 1;
//		}
//		return t;
//	}
//
//	void pr() {
//		for (int i = 0; i < size_; i++) {
//			for (int j = 0; j < size_; j++) {
//				cout << a[i][j] << ' ';
//			}
//			cout << endl;
//		}
//	}
//};
//
//signed main() {
//	int n, k;
//	cin >> n >> k;
//	size_ = n;
//	Matrix t;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cin >> t.a[i][j];
//		}
//	}
//
//	Matrix x;
//	x = t.pow(k);
//	x.pr();
//	return 0;
//}


//B3836 [GESP202303 二级] 百鸡问题
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int x, y, z, n, m;
//	cin >> x >> y >> z >> n >> m;
//	int ans = 0;
//	for (int i = 0; i <= m; i++) {
//		for (int j = 0; j <= m - i; j++) {
//			if (x * i + y * j + (m - i - j) / z == n && (m - i - j) % z == 0) ans++;
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}


// P1165 日志分析
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	int a, b;
//	vector<int> d;
//	while (n--) {
//		cin >> a;
//		if (a == 0) {
//			cin >> b;
//			d.push_back(b);
//		} else if (a == 1) {
//			if (!d.empty()) d.pop_back();
//		} else {
//			if (!d.empty()) cout << *max_element(d.begin(), d.end()) << endl;
//			else cout << 0 << endl;
//		}
//	}
//	return 0;
//}


//P9738 [COCI2022-2023#2] Prijateljice
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	string s;
//	int s1_pos = 0, s2_pos = 0;
//	vector<string> s1(n);
//	vector<string> s2(m);
//	for (int i = 0; i < n; i++) cin >> s1[i];
//	for (int i = 0; i < m; i++) cin >> s2[i];
//	s = s1[s1_pos];
//	s1_pos++;
//	bool is_f = true;
//	while (true) {
//		if (is_f) {
//			int i;
//			for (i = s2_pos; i < m; i++) {
//				if (s2[i] > s && (s2[i][0] == s[0] || s2[i][0] == s[0] + 1)) {
//					s = s2[i];
//					s2_pos = i + 1;
//					is_f = false;
//					break;
//				}
//			}
//
//			if (i == m) {
//				cout << "Leona" << endl;
//				break;
//			}
//		} else {
//			int i;
//			for (i = s1_pos; i < n; i++) {
//				if (s1[i] > s && (s1[i][0] == s[0] || s1[i][0] == s[0] + 1)) {
//					s = s1[i];
//					s1_pos = i + 1;
//					is_f = true;
//					break;
//				}
//			}
//
//			if (i == n) {
//				cout << "Zoe" << endl;
//				break;
//			}
//		}
//
//	}
//	return 0;
//}


//P1032 [NOIP2002 提高组] 字串变换  几乎没看题解做出来的绿题
//#include <bits/stdc++.h>
//using namespace std;
//
//struct mess {
//	string s;
//	int step;
//};
//
//struct s_2 {
//	string s1;
//	string s2;
//};
//
//string tihuan(string s1, string s2, string s3, size_t pos) {
//	string res;
//	res += s1.substr(0, pos);
//	res += s3;
//	res += s1.substr(pos + s2.size(), s1.size() - (pos + s2.size()));
//	return res;
//}
//
//int main() {
//	string a, b;
//	cin >> a >> b;
//	vector<s_2> mp;
//	string s1, s2;
//	unordered_map<string, bool> vis;
//	while (cin >> s1 >> s2) {
//		mp.push_back({s1, s2});
//	}
//	queue<mess> q;
//	q.push({a, 0});
//	bool have_ans = false;
//	while (!q.empty()) {
//		mess mess_ = q.front();
//		q.pop();
//		if (mess_.s == b) {
//			cout << mess_.step << endl;
//			have_ans = true;
//			break;
//		}
//		if (mess_.step >= 11) {
//			cout << "NO ANSWER!" << endl;
//			have_ans = true;
//			break;
//		}
//		if (vis[mess_.s]) continue; //很关键的优化啊
//		vis[mess_.s] = true;
//		for (int i = 0; i < (int)mp.size(); i++) {
//			size_t pos = mess_.s.find(mp[i].s1);
//			while (pos != string::npos) {
//				string temp = tihuan(mess_.s, mp[i].s1, mp[i].s2, pos);
//				if (!vis[temp]) {
//					q.push({temp, mess_.step + 1});
//				}
//				pos = mess_.s.find(mp[i].s1, pos + 1);
//			}
//		}
//	}
//	if (!have_ans) cout << "NO ANSWER!" << endl;
//	return 0;
//}



//P1057 [NOIP2008 普及组] 传球游戏
//#include <bits/stdc++.h>
//using namespace std;
//
//vector<vector<int>> a(31, vector<int>(31));
////a[i][j] 从1走i步到达j的走法数
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	a[0][1] = 1;
//	for (int i = 1; i <= m; i++) {
//		for (int j = 1; j <= n; j++) {
//			if (j == 1) {
//				a[i][j] = a[i - 1][2] + a[i - 1][n];
//			} else if (j == n) {
//				a[i][j] = a[i - 1][1] + a[i - 1][n - 1];
//			} else {
//				a[i][j] = a[i - 1][j - 1] + a[i - 1][j + 1];
//			}
//		}
//	}
//	cout << a[m][1];
//	return 0;
//}


//P9532 [YsOI2023] 前缀和
//#include <bits/stdc++.h>
//using namespace std;
//
//#define int long long
//
//signed main() {
//	int t;
//	cin >> t;
//	int n, x;
//	while (t--) {
//		cin >> n >> x;
//		int i;
//		for (i = n - 2; i >= 0; i--) {
//			if (x % (int)pow(2, i) == 0) {
//				break;
//			}
//		}
//		int a = x / (int)pow(2, i);
//		cout << (int)pow(2, n - 2) * a << endl;
//	}
//
//	return 0;
//}


//P8772 [蓝桥杯 2022 省 A] 求和
//#include <bits/stdc++.h>
//using namespace std;
//
//#define int long long
//
//signed main() {
//	int n;
//	cin >> n;
//	vector<int> a(n + 1);
//	vector<int> sum(n + 1);
//
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		sum[i] = sum[i - 1] + a[i];
//	}
//
//	int sumn = 0;
//	for (int i = 1; i <= n - 1; i++) {
//		sumn += a[i] * (sum[n] - sum[i]);
//	}
//	cout << sumn << endl;
//	return 0;
//}


//P8604 [蓝桥杯 2013 国 C] 危险系数
//#include <bits/stdc++.h>
//using namespace std;
//
//vector<vector<int>> g(1010, vector<int>(1010));
//vector<bool> vis(1010);
//vector<int> cnt(1010);
//int a, b, sum;
//int n, m, u, v;
//
//void dfs(int start) {
//	if (start == b) {
//		sum++;
//		for (int i = 1; i <= n; i++) {
//			if (vis[i]) cnt[i]++;
//		}
//	} else {
//		for (int i = 1; i <= n; i++) {
//			if (g[start][i] && !vis[i]) {
//				vis[i] = true;
//				dfs(i);
//				vis[i] = false;
//			}
//		}
//	}
//}
//
//int main() {
//
//	cin >> n >> m;
//	for (int i = 0; i < m; i++) {
//		cin >> u >> v;
//		g[u][v] = 1;
//		g[v][u] = 1;
//	}
//
//	cin >> a >> b;
//	dfs(a);
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		if (sum == cnt[i]) ans++;
//	}
//	cout << ans - 1 << endl;
//	return 0;
//}


//P8606 [蓝桥杯 2013 国 B] 高僧斗法  进阶nim博弈：阶梯博弈
//#include <bits/stdc++.h>
//using namespace std;
//
//bool is_win(vector<int>& b) {  //当前石子数量为b数组情况下先手能赢则为ture
//	int sum = 0;
//	for (int i = 0; i < (int)b.size(); i += 2) { //只需算奇数层的异或和，所以i+=2
//		sum ^= b[i];
//	}
//	return sum != 0;
//}
//
//int main() {
//	int n;
//	vector<int> a;
//	while (cin >> n) {
//		a.push_back(n);
//	}
//	n = a.size();
//	vector<int> b(n - 1);
//	for (int i = 0; i < n - 1; i++) b[i] = a[i + 1] - a[i] - 1;
//	if (!is_win(b)) cout << -1 << endl; //先手不能赢则直接输出-1
//	else {
//		for (int i = 0; i < n - 1; i++) {
//			for (int j = 1; j <= a[i + 1] - a[i] - 1; j++) {
//				if (i & 1) {
//					b[i - 1] += j; //相当于当前阶梯石子移动j个到前一个阶梯
//					if (!is_win(b)) { //刚才的后手是现在的先手，他得输
//						cout << a[i] << ' ' << a[i] + j << endl;
//						return 0;
//					}
//					b[i - 1] -= j; //还原原来的状态，除非前面已经得出了答案
//				} else {
//					b[i] -= j;
//					if (!is_win(b)) {
//						cout << a[i] << ' ' << a[i] + j << endl;
//						return 0;
//					}
//					b[i] += j;
//				}
//			}
//		}
//	}
//
//	return 0;
//}


//P2197 【模板】Nim 游戏  这是个绿题。。。
//#include <bits/stdc++.h>
//using namespace std;
//
//#define int long long
//
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int n, x;
//		int sum = 0;
//		cin >> n;
//		while (n--) {
//			cin >> x;
//			sum ^= x;
//		}
//		if (sum == 0) cout << "No" << endl;
//		else cout << "Yes" << endl;
//	}
//	return 0;
//}



//P1077 [NOIP2012 普及组] 摆花  自底向上分析即可
//#include <bits/stdc++.h>
//using namespace std;
//
//int dp[105][105];
//int a[105];
//int mod = 1e6 + 7;
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) cin >> a[i];
//	for (int i = 0; i <= a[1]; i++) dp[1][i] = 1;
//	for (int i = 2; i <= n; i++) {
//		for (int j = 0; j <= m; j++) {
//			for (int k = 0; k <= j; k++) {
//				if (j - k <= a[i]) {
//					dp[i][j] += dp[i - 1][k] % mod;
//					dp[i][j] %= mod;
//				}
//			}
//		}
//	}
//
//	cout << dp[n][m] << endl;
//	return 0;
//}


//P1024 [NOIP2001 提高组] 一元三次方程求解
//#include <bits/stdc++.h>
//using namespace std;
//
//int cnt;
//double a, b, c, d;
//
//double f(double x) {
//	return a * pow(x, 3) + b * pow(x, 2) + c * x + d;
//}
//
//int main() {
//	cin >> a >> b >> c >> d;
//	for (double i = -100; i <= 100; i++) {
//		double x1 = f(i);
//		double x2 = f(i + 1);
//		if (!x1) {
//			printf("%.2lf ", i);
//			cnt++;
//			continue;
//		}
//
//		if (x1 * x2 < 0) {
//			double l = i, r = i + 1;
//			while (r - l >= 1e-5) {
//				double mid = (l + r) / 2;
//				if (f(l) * f(mid) < 0) {
//					r = mid;
//				} else {
//					l = mid;
//				}
//			}
//			printf("%.2lf ", r);
//			cnt++;
//		}
//
//		if (cnt == 3) break;
//
//	}
//
//	return 0;
//}


//P1147 连续自然数和
//#include <bits/stdc++.h>
//using namespace std;
//
//#define int long long
//
//signed main() {
//	int m;
//	cin >> m;
//	for (int a = 1; a <= m / 2; a++) {
//		int delta = 1 - 4 * (a - a*a - 2 * m);
//		if (delta <= 0) continue;
//		int b = (-1 + sqrtl(delta)) / 2;
//		if ((a + b) * (b - a + 1) / 2 == m) {
//			cout << a << ' ' << b << endl;
//		}
//	}
//	return 0;
//}


//B3624 猫粮规划
//#include <bits/stdc++.h>
//using namespace std;
//
//int n, l, r, ans;
//vector<int> a(50);
//
//void dfs(int deep, int sum) {
//	if (deep == n) {
//		if (l <= sum && sum <= r) {
//			ans++;
//		}
//	} else {
//		if (sum + a[deep] <= r)
//			dfs(deep + 1, sum + a[deep]);
//		dfs(deep + 1, sum);
//	}
//}
//
//int main() {
//	cin >> n >> l >> r;
//	for (int i = 0; i < n; i++) cin >> a[i];
//	dfs(0, 0);
//	cout << ans << endl;
//	return 0;
//}


//P4387 【深基15.习9】验证栈序列   别人的代码
//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	int q;
//	cin >> q;
//	while (q--) {
//		int n;
//		int a[100001], b[100001];
//		stack<int >st;
//		cin >> n;
//		for (int i = 1; i <= n; i++)
//			cin >> a[i];
//		for (int i = 1; i <= n; i++)
//			cin >> b[i];
//		int head = 1;
//		for (int i = 1; i <= n; i++) {
//			st.push(a[i]);
//			while (st.top() == b[head]) {
//				st.pop();
//				head++;
//				if (st.empty())
//					break;
//			}
//		}
//		if (st.empty())
//			cout << "Yes" << endl;
//		else
//			cout << "No" << endl;
//	}
//}


//P3865 【模板】ST 表 && RMQ 问题  数据太强过不了，答案都过不了哈哈哈哈
//#include <iostream>
//#include <cmath>
//using namespace std;
//
//inline int read() {
//	int x = 0, f = 1;
//	char ch = getchar();
//	while (ch < '0' || ch > '9') {
//		if (ch == '-') f = -1;
//		ch = getchar();
//	}
//	while (ch >= '0' && ch <= '9') {
//		x = x * 10 + ch - '0';
//		ch = getchar();
//	}
//	return x*f;
//}
//
//int main() {
//	int n, m;
//	n = read();
//	m = read();
//
//	int n2 = (int)log2(n);
//	int st[100010][30];
//
//	for (int i = 0; i < n; i++) st[i][0] = read();
//
//	for (int i = 1; i <= n2; i++) {
//		for (int j = 0; j + (1 << i) - 1 < n; j++) {
//			st[j][i] = max(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
//		}
//	}
//
//	while (m--) {
//		int l, r;
//		cin >> l >> r;
//		l--;
//		r--;
//		int x = (int)log2(r - l + 1);
//		cout << max(st[l][x], st[r - (1 << x) + 1][x]) << endl;
//	}
//	return 0;
//}


// B3716 分解质因子 3
//#include <bits/stdc++.h>
//using namespace std;
//
//void get_primes(vector<int>& res, vector<int>& not_prime, int maxn) {
//	not_prime.resize(maxn + 1);
//	for (int i = 2; i <= maxn; i++) {
//		if (!not_prime[i]) res.push_back(i);
//		for (int j = 0; res[j] <= maxn / i; j++) {
//			not_prime[i * res[j]] = res[j];
//			if (i % res[j] == 0) break;
//		}
//	}
//}
//
//int main() {
//	int t, n;
//	cin >> t;
//	vector<int> primes, not_prime;
//	get_primes(primes, not_prime, 1e8);
//	while (t--) {
//		cin >> n;
//		if (!not_prime[n]) {
//			cout << n << endl;
//		} else {
//			int ans = 0;
//
//			while (not_prime[n]) {
//				ans ^= not_prime[n];
//				n /= not_prime[n];
//			}
//			ans ^= n;
//			cout << ans << endl;
//		}
//	}
//	return 0;
//}


// P5736 【深基7.例2】质数筛
//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	vector<int> a;
//	vector<int> b(100010);
//	b[1] = 1;
//
//	for (int i = 2; i <= 100010; i++) {
//		if (!b[i]) a.push_back(i);
//		for (int j = 0; a[j] <= 100010 / i; j++) {
//			b[i * a[j]] = 1;
//			if (i % a[j] == 0) break;
//		}
//	}
//
//	int n;
//	cin >> n;
//	while (n--) {
//		int x;
//		cin >> x;
//		if (!b[x]) cout << x << ' ';
//	}
//
//	return 0;
//}

//P8842 [传智杯 #4 初赛] 小卡与质数 2
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 1e7 + 10;
//
//int main() {
//	vector<int> primes;
//	vector<int> vis(N);
//	vis[1] = 1;
//	vector<int> sum(N);
//	for (int i = 2; i <= N - 2; i++) {
//		if (!vis[i]) primes.push_back(i);
//		for (int j = 0; primes[j] <= (N - 2) / i; j++) {
//			vis[i * primes[j]] = 1;
//			if (i % primes[j] == 0) break;
//		}
//	}
//	for (int i = 1; i <= N - 2; i++) {
//		sum[i] = sum[i - 1] + (!vis[i]);
//	}
//	int t, x;
//	cin >> t;
//	while (t--) {
//		cin >> x;
//		int ans = 0;
//		for (int i = 0; i <= 30; i++) {
//			if (x & (1 << i)) {
//				ans += sum[(1 << (i + 1)) - 1] - sum[(1 << i) - 1];
//			}
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}



//P1449 后缀表达式
//#include <bits/stdc++.h>
//using namespace std;
//
//stack<int> num;
//
//void calc(char o) {
//	int b = num.top();
//	num.pop();
//	int a = num.top();
//	num.pop();
//	if (o == '+') num.push(a + b);
//	else if (o == '-') num.push(a - b);
//	else if (o == '*') num.push(a * b);
//	else num.push(a / b);
//}
//
//int main() {
//	string s;
//	cin >> s;
//	for (int i = 0; i < (int)s.size(); i++) {
//		if (s[i] == '.') continue;
//		if (s[i] == '@') break;
//		if (isdigit(s[i])) {
//			int j = i, x = 0;
//			while (j < (int)s.size() && s[j] != '.') {
//				x = 10 * x + s[j++] - '0';
//			}
//			num.push(x);
//			i = j;
//		} else {
//			calc(s[i]);
//		}
//	}
//
//	cout << num.top() << endl;
//	return 0;
//}


// P3375 【模板】KMP  2025.1.15
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	string s1, s2;
//	cin >> s1 >> s2;
//
//	int s1_s = s1.size();
//	int s2_s = s2.size();
//
//	s1 = ' ' + s1;
//	s2 = ' ' + s2;
//	vector<int> ne(s2_s + 1);
//	for (int i = 2, j = 0; i <= s2_s; i++) {
//		while (j && s2[i] != s2[j + 1]) j = ne[j];
//		if (s2[i] == s2[j + 1]) j++;
//		ne[i] = j;
//	}
//
//	for (int i = 1, j = 0; i <= s1_s; i++) {
//		while (j && s1[i] != s2[j + 1]) j = ne[j];
//		if (s1[i] == s2[j + 1]) j++;
//
//		if (j == s2_s) {
//			cout << i - s2_s + 1 << endl;
//			j = ne[j];
//		}
//	}
//
//	for (int i = 1; i <= s2_s; i++) cout << ne[i] << ' ';
//	return 0;
//}


// P1990 覆盖墙壁
//2025.1.16
//#include <bits/stdc++.h>
//using namespace std;
//
//const int mod = 10000;
//
//int main() {
//	int n;
//	cin >> n;
//	int a[n + 1];
//	int s[n + 1];
//	a[0] = 1;
//	a[1] = 1;
//	a[2] = 2;
//	a[3] = 5;
//	s[0] = 1;
//	s[1] = 2;
//	s[2] = 4;
//	s[3] = 9;
//
//	for (int i = 4; i <= n; i++) {
//		a[i] = (a[i - 1] + a[i - 2] + 2 * a[i - 3] + 2 * s[i - 4]) % mod;
//		s[i] = (s[i - 1] + a[i]) % mod;
//	}
//
//	cout << a[n] << endl;
//	return 0;
//}


//P8682 [蓝桥杯 2019 省 B] 等差数列
//2025.1.16
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++) cin >> a[i];
//	sort(a.begin(), a.end());
//	int cha = 0;
//	for (int i = 1; i < n; i++) {
//		cha = gcd(cha, a[i] - a[i - 1]);
//	}
//	if (cha == 0) cout << n << endl;
//	else cout << (a.back() - a[0]) / cha + 1;
//
//	return 0;
//}


// P2424 约数和
//2025.1.16
//#include <bits/stdc++.h>
//using namespace std;
//
//#define int long long
//
//int sum(int x) {
//	int l = 1, r;
//	int res = 0;
//	while (l <= x) {
//		r = x / (x / l);
//		res += (x / l) * (r + l) * (r - l + 1) / 2;
//		l = r + 1;
//	}
//	return res;
//}
//
//signed main() {
//	int x, y;
//	cin >> x >> y;
//	cout << sum(y) - sum(x - 1) << endl;
//	return 0;
//}


// P3392 涂条纹
//2025.1.18
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	vector<string> a(n);
//	for (int i = 0; i < n; i++) cin >> a[i];
//	for (int i = 0; i < n; i++) a[i] = ' ' + a[i];
//	int ans = 0;
//	for (int i = 1; i <= m; i++)
//		if (a[0][i] != 'W') ans++;
//	for (int i = 1; i <= m; i++)
//		if (a[n - 1][i] != 'R') ans++;
//
//	vector<int> R(n + 1), W(n + 1), B(n + 1);
//	for (int i = 1; i < n - 1; i++) {
//		int r = 0, b = 0, w = 0;
//		for (int j = 1; j <= m; j++) {
//			if (a[i][j] == 'R') r++;
//			else if (a[i][j] == 'B') b++;
//			else w++;
//		}
//
//		R[i] = R[i - 1] + r;
//		B[i] = B[i - 1] + b;
//		W[i] = W[i - 1] + w;
//	}
//	int ans2 = INT32_MAX / 2;
//	for (int i = 1; i <= n - 2; i++) {
//		for (int j = i; j < n - 1; j++) {
//			int bianran = R[j] - R[i - 1] + W[j] - W[i - 1];
//			int bianhong = B[n - 2] - B[j] + W[n - 2] - W[j];
//			int bianbai = B[i - 1] - B[0] + R[i - 1] - R[0];
//			ans2 = min(ans2, bianbai + bianhong + bianran);
//		}
//	}
//
//	cout << ans + ans2 << endl;
//	return 0;
//}



// P2024 [NOI2001] 食物链
// 2025.1.18 双倍快乐！！！
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 50010;
//int n, k, t, x, y, fa[N], d[N];
//
//int find(int u) {
//	if (fa[u] != u) {
//		int t_ = find(fa[u]);
//		d[u] += d[fa[u]];
//		fa[u] = t_;
//	}
//	return fa[u];
//}
//
//int main() {
//	cin >> n >> k;
//	for (int i = 1; i <= n; i++) fa[i] = i;
//	int ans = 0;
//	while (k--) {
//		cin >> t >> x >> y;
//		if (x > n || y > n) ans++;
//		else {
//			int f_x = find(x), f_y = find(y);
//			if (t == 1) {
//				if (f_x == f_y && (d[x] - d[y]) % 3) ans++;
//				else if (f_x != f_y) {
//					fa[f_x] = f_y;
//					d[f_x] = d[y] - d[x];
//				}
//			} else {
//				if (f_x == f_y) {
//					// if ((d[x] - d[y]) % 3 != 1) ans++;
//					// 灵异事件待解决
//					if ((d[x] - d[y] - 1) % 3) ans++;
//				} else if (f_x != f_y) {
//					fa[f_x] = f_y;
//					d[f_x] = d[y] - d[x] + 1;
//				}
//			}
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}


// P10471 最大异或对 The XOR Largest Pair
// 2025.1.18 双倍快乐！！！
// #include <bits/stdc++.h>
// using namespace std;
//
// const int N = 100010;
// int a[N], n, t[30 * N][2], idx;
//
// void insert(int x) {
//     int p = 0;
//     for (int i = 30; i >= 0; i--) {
//         if (!t[p][x >> i & 1]) t[p][x >> i & 1] = ++idx;
//         p = t[p][x >> i & 1];
//     }
// }
//
// int main() {
//     cin >> n;
//     for (int i = 0; i < n; i++) cin >> a[i];
//     for (int i = 0; i < n; i++) insert(a[i]);
//     int res = 0;
//     for (int i = 0; i < n; i++) {
//         int a2 = 0;
//         int p = 0;
//         for (int j = 30; j >= 0; j--) {
//             if (t[p][!(a[i] >> j & 1)]) {
//                 p = t[p][!(a[i] >> j & 1)];
//                 a2 = (!(a[i] >> j & 1)) + (a2 << 1);
//             } else {
//                 p = t[p][(a[i] >> j & 1)];
//                 a2 = (a[i] >> j & 1) + (a2 << 1);
//             }
//         }
//         res = max(res, a[i] ^ a2);
//     }
//     cout << res << endl;
//     return 0;
// }


// P5788 【模板】单调栈
// // 2025.1.18
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int> a(n + 1);
//	for (int i = 1; i <= n; i++) cin >> a[i];
//	stack<int> st;
//	stack<int> ans;
//	for (int i = n; i >= 1; i--) {
//		while (!st.empty() && a[st.top()] <= a[i]) st.pop();
//		if (st.empty()) ans.push(0);
//		else ans.push(st.top());
//		st.push(i);
//	}
//	while (!ans.empty()) {
//		cout << ans.top() << ' ';
//		ans.pop();
//	}
//	return 0;
//}


// P3383 【模板】线性筛素数
// 2025.1.19
//#include <cstdio>
//
//const int N = 1e8 + 10;
//bool vis[N];
//int p[N], n, q, k, cnt;
//
//void euler() {
//	for (int i = 2; i <= n; i++) {
//		if (!vis[i]) p[cnt++] = i;
//		for (int j = 0; j < cnt && p[j] <= n / i; j++) {
//			vis[i * p[j]] = 1;
//			if (i % p[j] == 0) break;
//		}
//	}
//}
//
//int main() {
//	scanf("%d%d", &n, &q);
//	euler();
//	while (q--) {
//		scanf("%d", &k);
//		printf("%d\n", p[--k]);
//	}
//	return 0;
//}


//P1908 逆序对
// 2025.1.19
//#include <iostream>
//using namespace std;
//#define int long long
//
//const int N = 500010;
//int n, a[N];
//
//int merge_sort(int l, int r) {
//	if (l >= r) return 0;
//	int mid = (l + r) >> 1;
//	int res = merge_sort(l, mid) + merge_sort(mid + 1, r);
//
//	int i = l, j = mid + 1, cnt = 0;
//	int temp[r - l + 1];
//	while (i <= mid && j <= r) {
//		if (a[i] <= a[j]) {
//			temp[cnt++] = a[i++];
//		} else {
//			temp[cnt++] = a[j++];
//			res += mid - i + 1;
//		}
//	}
//
//	while (i <= mid) temp[cnt++] = a[i++];
//	while (j <= r) temp[cnt++] = a[j++];
//
//	for (int i = 0, j = l; j <= r; i++, j++) a[j] = temp[i];
//	return res;
//}
//
//signed main() {
//	cin >> n;
//	for (int i = 0; i < n; i++) cin >> a[i];
//	cout << merge_sort(0, n - 1);
//	return 0;
//}


// P2043 质因子分解
// 2025.1.26
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	map<int, int> mp;
//	cin >> n;
//	for (int i = 2; i <= n; i++) {
//		int x = i;
//		for (int j = 2; j <= x; j++) {
//			while (x % j == 0) {
//				mp[j]++;
//				x /= j;
//			}
//		}
//	}
//
//	for (auto it : mp) {
//		cout << it.first << ' ' << it.second << endl;
//	}
//	return 0;
//}


// P1923 【深基9.例4】求第 k 小的数
// 2025.1.27
//#include <cstdio>
//#include <iostream>
//using namespace std;
//
//const int N = 5e6 + 2;
//int a[N];
//
//int quick_sort(int l, int r, int k) {
//	if (l == r) return a[l];
//	int x = a[(l + r) >> 1];
//	int i = l - 1, j = r + 1;
//	while (i < j) {
//		while (a[++i] < x);
//		while (a[--j] > x);
//		if (i < j) swap(a[i], a[j]);
//	}
//	int sl = j - l + 1;
//	if (sl >= k) return quick_sort(l, j, k);
//	else return quick_sort(j + 1, r, k - sl);
//}
//
//int main() {
//	int n, k;
//	cin >> n >> k;
//	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
//	cout << quick_sort(0, n - 1, k + 1) << endl;
//	return 0;
//}



// P3912 素数个数
// 2025.1.29
//#include <bits/stdc++.h>
//using namespace std;
//
//int n;
//const int N = 1e8 + 1;
//int p[N], cnt;
//bool vis[N];
//
//void euler() {
//	for (int i = 2; i <= n; i++) {
//		if (!vis[i]) p[cnt++] = i;
//		for (int j = 0; p[j] <= n / i; j++) {
//			vis[i * p[j]] = 1;
//			if (i % p[j] == 0) break;
//		}
//	}
//}
//
//int main() {
//	cin >> n;
//	euler();
//	cout << cnt << endl;
//	return 0;
//}



// P1075 [NOIP2012 普及组] 质因数分解
// 2025.1.30
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	int ans = 0;
//	for (int i = 2; i <= n / i; i++) {
//		while (n % i == 0) {
//			n /= i;
//			ans = i;
//		}
//	}
//	if (n > 1) ans = n;
//	cout << ans << endl;
//	return 0;
//}



// P1082 [NOIP 2012 提高组] 同余方程
// 2025.1.31 23：30
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//void ex_gcd(int a, int b, int a1, int a2, int b1, int b2, int& ans1, int& ans2) {
//	if (a == 0) {
//		ans1 = b1;
//		ans2 = b2;
//	} else {
//		int x = -(b / a);
//		int b1_ = b1, b2_ = b2;
//		b1 = a1;
//		b2 = a2;
//		a1 = x * a1 + b1_;
//		a2 = x * a2 + b2_;
//		ex_gcd(b % a, a, a1, a2, b1, b2, ans1, ans2);
//	}
//}
//
//
//signed main() {
//	int a, b;
//	cin >> a >> b;
//	int ans1, ans2;
//	ex_gcd(a, b, 1, 0, 0, 1, ans1, ans2);
//	ans1 = (ans1 % b + b) % b;
//	cout << ans1 << endl;
//	return 0;
//}

// 同上题，原来有问题但不知道哪里出了问题，所以改成
// 上面的写法，后来不甘心找了一下问题，于是成功了，少了个return ！
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//array<int, 2> ex_gcd(int a, int b, int a1, int a2, int b1, int b2) {
//	if (a == 0) {
//		return {b1, b2};
//	} else {
//		int x = -(b / a);
//		int b1_ = b1, b2_ = b2;
//		b1 = a1;
//		b2 = a2;
//		a1 = x * a1 + b1_;
//		a2 = x * a2 + b2_;
//		return ex_gcd(b % a, a, a1, a2, b1, b2);
//	}
//}
//
//
//signed main() {
//	int a, b;
//	cin >> a >> b;
//	array<int, 2> ans = ex_gcd(a, b, 1, 0, 0, 1);
//	ans[0] = (ans[0] % b + b) % b;
//	cout << ans[0] << endl;
//	return 0;
//}


// P4777 【模板】扩展中国剩余定理（EXCRT）
// 省选/NOI-，第一次紫题在我眼里那么简单    2025.2.5

// 会爆long long，最后一个测试点过不了。
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//
//int exgcd(int a, int b, int& x, int& y) {
//	if (a == 0) {
//		x = 0, y = 1;
//		return b;
//	} else {
//		int d = exgcd(b % a, a, x, y);
//		swap(x, y);
//		x -= b / a * y;
//		return d;
//	}
//}
//
//signed main() {
//	int n;
//	cin >> n;
//	int a1, m1, a2, m2;
//	cin >> a1 >> m1;
//	for (int i = 0; i < n - 1; i++) {
//		cin >> a2 >> m2;
//		int k1, k2;
//		int d = exgcd(a1, a2, k1, k2);
//		k1 *= (m2 - m1) / d;
//		int t = a2 / d;
//		k1 = (k1 % t + t) % t;
//		m1 = k1 * a1 + m1;
//		a1 = a1 / d * a2;
//	}
//	cout << m1 % a1 << endl;
//	return 0;
//}

// 同上题，用__int128解决了爆long long的问题。
//#include <bits/stdc++.h>
//using namespace std;
//
//__int128 read() {
//	__int128 X = 0, w = 1;
//	char ch;
//	ch = getchar();
//	while (ch < '0' || ch > '9') {
//		if (ch == '-') w = -1;
//		ch = getchar();
//	}
//	while (ch >= '0' && ch <= '9') {
//		X = (X << 3) + (X << 1) + ch - '0';
//		ch = getchar();
//	}
//	return w * X;
//}
//
//
//__int128 exgcd(__int128 a, __int128 b, __int128& x, __int128& y) {
//	if (a == 0) {
//		x = 0, y = 1;
//		return b;
//	} else {
//		__int128 d = exgcd(b % a, a, x, y);
//		swap(x, y);
//		x -= b / a * y;
//		return d;
//	}
//}
//
//void write_(__int128 a) {
//	if (a) {
//		write_(a / 10);
//		putchar(a % 10 + '0');
//	}
//}
//
//signed main() {
//	int n;
//	cin >> n;
//	__int128 a1, m1, a2, m2;
//	a1 = read(), m1 = read();
//	for (int i = 0; i < n - 1; i++) {
//		a2 = read(), m2 = read();
//		__int128 k1, k2;
//		__int128 d = exgcd(a1, a2, k1, k2);
//		k1 *= (m2 - m1) / d;
//		__int128 t = a2 / d;
//		k1 = (k1 % t + t) % t;
//		m1 = k1 * a1 + m1;
//		a1 = a1 / d * a2;
//	}
//	write_(m1 % a1);
//	return 0;
//}



// P1495 【模板】中国剩余定理（CRT）/ 曹冲养猪
// 2025.2.5 和上题一样的代码，双倍快乐！！！
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//
//int exgcd(int a, int b, int& x, int& y) {
//	if (a == 0) {
//		x = 0, y = 1;
//		return b;
//	} else {
//		int d = exgcd(b % a, a, x, y);
//		swap(x, y);
//		x -= b / a * y;
//		return d;
//	}
//}
//
//signed main() {
//	int n;
//	cin >> n;
//	int a1, m1, a2, m2;
//	cin >> a1 >> m1;
//	for (int i = 0; i < n - 1; i++) {
//		cin >> a2 >> m2;
//		int k1, k2;
//		int d = exgcd(a1, a2, k1, k2);
//		k1 *= (m2 - m1) / d;
//		int t = a2 / d;
//		k1 = (k1 % t + t) % t;
//		m1 = k1 * a1 + m1;
//		a1 = a1 / d * a2;
//	}
//	cout << m1 % a1 << endl;
//	return 0;
//}


// P1516 青蛙的约会
// 2025.2.5
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//int exgcd(int a, int b, int& x, int& y) {
//	if (a == 0) {
//		x = 0, y = 1;
//		return b;
//	} else {
//		int d = exgcd(b % a, a, y, x);
//		x -= b / a * y;
//		return d;
//	}
//}
//
//signed main() {
//	int x, y, m, n, l;
//	cin >> x >> y >> m >> n >> l;
//	int X, Y;
//	int d = exgcd(m - n, l, X, Y);
//	if ((y - x) % d == 0) {
//		int k = (y - x) / d;
//		X *= k;
//		int c = abs(l / d);
//		cout << (X % c + c) % c << endl;
//	} else {
//		cout << "Impossible" << endl;
//	}
//	return 0;
//}


// P3868 [TJOI2009] 猜数字
// 2025.2.5
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//int exgcd(int a, int b, int& x, int& y) {
//	if (a == 0) {
//		x = 0, y = 1;
//		return b;
//	} else {
//		int d = exgcd(b % a, a, y, x);
//		x -= b / a * y;
//		return d;
//	}
//}
//
//signed main() {
//	int k;
//	cin >> k;
//	vector<int> a(k), b(k);
//	for (int i = 0; i < k; i++) cin >> a[i];
//	for (int i = 0; i < k; i++) cin >> b[i];
//	int a1 = a[0], b1 = b[0];
//	for (int i = 1; i < k; i++) {
//		int a2 = a[i], b2 = b[i];
//		int k1, k2;
//		exgcd(b1, b2, k1, k2);
//		k1 *= a2 - a1;
//		k1 = (k1 % b2 + b2) % b2;
//		a1 = a1 + k1 * b1;
//		b1 = b1 * b2;
//	}
//
//	cout << a1 % b1 << endl;
//	return 0;
//}


// P2082 区间覆盖（加强版）
// 2025.2.9
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//	int n;
//	cin >> n;
//	vector<pair<int, int>> a(n);
//	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
//	sort(a.begin(), a.end());
//	int l = a[0].first, r = a[0].second;
//	vector<pair<int, int>> b;
//	for (int i = 1; i < n; i++) {
//		if (a[i].first > r) {
//			b.push_back({l, r});
//			l = a[i].first, r = a[i].second;
//		} else {
//			if (a[i].second > r) {
//				r = a[i].second;
//			}
//		}
//	}
//	b.push_back({l, r});
//	int ans = 0;
//	for (auto i : b) {
//		ans += i.second - i.first + 1;
//	}
//	cout << ans << endl;
//	return 0;
//}



// U59472 校门外的树plus
// 2025.2.9 和上一题几乎一样，双倍快乐！
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int L, m;
//	cin >> L >> m;
//	vector<pair<int, int>> a(m);
//	for (int i = 0; i < m; i++) cin >> a[i].first >> a[i].second;
//	sort(a.begin(), a.end());
//	int l = a[0].first, r = a[0].second;
//	int ans = 0;
//	for (int i = 1; i < m; i++) {
//		if (a[i].first > r) {
//			ans += r - l + 1;
//			l = a[i].first, r = a[i].second;
//		} else {
//			r = max(r, a[i].second);
//		}
//	}
//	ans += r - l + 1;
//	cout << L + 1 - ans << endl;
//	return 0;
//}



// P8649 [蓝桥杯 2017 省 B] k 倍区间
// 2025.2.11
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n, k;
//	cin >> n >> k;
//	vector<int> sum(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> sum[i];
//		sum[i] += sum[i - 1];
//		sum[i] %= k;
//	}
//	vector<int> cnt(100001);
//	long long ans = 0;
//	for (int i = 1; i <= n; i++) {
//		ans += cnt[sum[i]]++;
//	}
//	cout << ans + cnt[0] << endl;
//	return 0;
//}


// P6033 [NOIP 2004 提高组] 合并果子 加强版
// 20255.2.14
//#include <cstdio>
//#include <queue>
//using namespace std;
//using ll = long long;
//
//const int N = 100010;
//int cnt[N];
//queue<ll> q1, q2;
//
//ll read() {
//	ll f = 1, x = 0;
//	char c;
//	c = getchar();
//	while (c < '0' || c > '9') {
//		if (c == '-') f = -1;
//		c = getchar();
//	}
//	while ('0' <= c && c <= '9') {
//		x = 10 * x + c - '0';
//		c = getchar();
//	}
//	return f * x;
//}
//
//ll first() {
//	if (q2.empty()) {
//		ll x = q1.front();
//		q1.pop();
//		return x;
//	}
//	if (!q1.empty() && q1.front() < q2.front()) {
//		ll x = q1.front();
//		q1.pop();
//		return x;
//	} else {
//		ll x = q2.front();
//		q2.pop();
//		return x;
//	}
//}
//
//signed main() {
//	int n;
//	n = read();
//	for (int i = 0; i < n; i++) {
//		cnt[0] = read();
//		cnt[cnt[0]]++;
//	}
//	for (int i = 1; i <= 100000; i++) {
//		for (int j = 1; j <= cnt[i]; j++) {
//			q1.push(i);
//		}
//	}
//	n -= 1;
//	ll ans = 0;
//	while (n--) {
//		ll x, y;
//		x = first();
//		y = first();
//
//		ans += x + y;
//		q2.push(x + y);
//	}
//	printf("%lld", ans);
//	return 0;
//}


// P8597 [蓝桥杯 2013 省 B] 翻硬币
// 2025.2.15
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	string s1, s2;
//	cin >> s1 >> s2;
//	int ans = 0;
//	for (unsigned int i = 0; i < s1.size() - 1; i++) {
//		if (s1[i] != s2[i]) {
//			ans++;
//			s1[i + 1] = s1[i + 1] == 'o' ? '*' : 'o';
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}


// P8598 [蓝桥杯 2013 省 AB] 错误票据
// 2025.2.15
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int> a(100010);
//	while (cin >> n) a[n]++;
//	int ans1 = 0;
//	int ans2 = 0;
//	for (int i = 1; i <= 100000; i++) {
//		if (a[i - 1] == 1 && a[i + 1] == 1 && a[i] == 0) ans1 = i;
//		if (a[i] == 2) ans2 = i;
//	}
//	cout << ans1 << ' ' << ans2 << endl;
//	return 0;
//}


// P8880 无知时诋毁原神
// 2025.2.26
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++) cin >> a[i];
//	if (n & 1) {
//		vector<int> ans1(n), ans2(n);
//		for (int i = 0; i < n; i++) {
//			ans1[i] = (n - 1) - a[i];
//			ans2[i] = ((a[i] - ans1[i]) % n + n) % n;
//		}
//
//		for (int i = 0; i < n; i++) cout << ans1[i] << ' ';
//		cout << endl;
//		for (int i = 0; i < n; i++) cout << ans2[i] << ' ';
//	} else cout << -1 << endl;
//	return 0;
//}


// P10205 [JOI 2024 Final] 室温 / Room Temperature
// 2025.2.26
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//	int n, t;
//	cin >> n >> t;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++) cin >> a[i];
//	for (int i = 0; i < n; i++) {
//		a[i] %= t;
//	}
//	sort(a.begin(), a.end());
//	int z = (a[0] + a.back()) / 2;
//	int ans = max(abs(a[0] - z), abs(a.back() - z));
//	for (int i = 0; i < n - 1; i++) {
//		int maxn = a[i] + t;
//		int minn = a[i + 1];
//		z = (maxn + minn) / 2;
//		ans = min(ans, max(maxn - z, z - minn));
//	}
//	cout << ans << endl;
//	return 0;
//}


// P4089 [USACO17DEC] The Bovine Shuffle S
//2025.2.26 (未做出，该方法不太行，会超时)
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 100010;
//int n;
//vector<int> a(N);
//vector<bool> vis(N);
//map<int, bool> mp;
//
//void dfs(int start, int s, int& ans) {
//	if (start == a[s]) {
//		mp[start] = 1;
//		for (auto i : mp) {
//			ans++;
//			vis[i.first] = 1;
//		}
//		return;
//	} else {
//		if (!vis[a[s]] && !mp[a[s]]) {
//			mp[a[s]] = 1;
//			dfs(start, a[s], ans);
//		}
//	}
//}
//
//int main() {
//	cin >> n;
//	for (int i = 1; i <= n; i++) cin >> a[i];
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		if (!vis[i]) {
//			dfs(i, i, ans);
//			mp.clear();
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}


// P4549 【模板】裴蜀定理
// 2025.2.27
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++) cin >> a[i];
//	int ans = a[0];
//	for (int i = 1; i < n; i++) ans = gcd(ans, a[i]);
//	cout << ans << endl;
//	return 0;
//}



// P1725 琪露诺   没优化竟然过了
// 2025.3.3
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n, l, r;
//	cin >> n >> l >> r;
//	vector<int> a(n + 2);
//	for (int i = 0; i < n + 1; i++) cin >> a[i];
//	vector<int> dp(n + 2);
//	for (int i = 1; i <= n + 1; i++) {
//		int maxn = -1e9;
//		for (int j = l; j <= r; j++) {
//			if (i - j >= 0) {
//				maxn = max(maxn, dp[i - j]);
//			}
//		}
//		if (maxn == -1e9) {
//			dp[i] = -1e9;
//		} else {
//			dp[i] = maxn + a[i];
//		}
//	}
////	for (int i = 0; i <= n + 1; i++) cout << dp[i] << ' ';
////	cout << endl;
//	int ans = -1e9;
//	for (int i = n + 1 - r; i <= n; i++) ans = max(ans, dp[i]);
//	cout << ans;
//	return 0;
//}



// P1714 切蛋糕
// 2025.3.5
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	vector<int> a(n + 1);
//	for (int i = 1; i <= n; i++) cin >> a[i];
//	for (int i = 1; i <= n; i++) a[i] = a[i] + a[i - 1];
//	int ans = -1e9;
//	int hh = 0, tt = -1;
//	vector<int> b(n + 10);
//	b[++tt] = 0;
//	for (int i = 1; i <= n; i++) {
//		// 使用单调队列优化
//		if (hh <= tt && b[hh] <= i - m - 1) hh++;
//		while (hh <= tt && a[b[tt]] >= a[i]) tt--;
//		b[++tt] = i;
//		ans = max(ans, a[i] - a[b[hh]]);
//
//// 		没有优化代码
////		for (int j = 1; j <= m; j++) {
////			if (i - j < 0) break;
////			ans = max(ans, a[i] - a[i - j]);
////		}
//	}
//	cout << ans << endl;
//	return 0;
//}


// P1483 序列变换   绿题，这种做法肯定过不了啊
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	vector<int> a(n + 1);
//	for (int i = 1; i <= n; i++) cin >> a[i];
//	while (m--) {
//		int o;
//		cin >> o;
//		if (o == 1) {
//			int x, y;
//			cin >> x >> y;
//			for (int i = x; i <= n; i += x) {
//				a[i] += y;
//			}
//		} else {
//			int x;
//			cin >> x;
//			cout << a[x] << endl;
//		}
//	}
//	return 0;
//}


// 绿题真基本自己想出来的哈哈哈哈
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	vector<int> a(n + 1);
//	for (int i = 1; i <= n; i++) cin >> a[i];
//	unordered_map<int, int> mp;
//	while (m--) {
//		int o;
//		cin >> o;
//		if (o == 1) {
//			int x, y;
//			cin >> x >> y;
//			mp[x] += y;
//		} else {
//			int j;
//			cin >> j;
//			int x = a[j];
//			for (int i = 1; i <= j / i; i++) {
//				if (j % i == 0) {
//					x += mp[i];
//					if (i != j / i) x += mp[j / i];
//				}
//			}
//			cout << x << endl;
//		}
//	}
//	return 0;
//}


// P11042 [蓝桥杯 2024 省 Java B] 类斐波那契循环数
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
////	for (int i = 10000000; i >= 0; i--) {
////		string s = to_string(i);
////		vector<int> a;
////		int sum = 0;
////		for (unsigned j = 0; j < s.size(); j++) {
////			a.push_back(s[j] - '0');
////			sum += a[j];
////		}
////		int st = 0, ed = s.size();
////		a.push_back(sum);
////		while (a.back() < i) {
////			sum = sum - a[st++] + a[ed++];
////			a.push_back(sum);
////		}
////		if (a.back() == i) {
////			cout << i << endl;
////			break;
////		}
////	}
//	cout << 7913837 << endl;
//	return 0;
//}


// P9240 [蓝桥杯 2023 省 B] 冶炼金属
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	int maxn = 1e9;
//	int minn = -1e9;
//	while (n--) {
//		int a, b;
//		cin >> a >> b;
//		maxn = min(maxn, a / b);
//		minn = max(minn, a / (b + 1) + 1);
//	}
//	cout << minn << ' ' << maxn;
//	return 0;
//}


// P10999 [蓝桥杯 2024 省 Python B] 穿越时空之门
//#include<bits/stdc++.h>
//using namespace std;
//
//int f2(int x) {
//	int res = 0;
//	while (x) {
//		res += x % 2;
//		x /= 2;
//	}
//	return res;
//}
//
//
//int f4(int x) {
//	int res = 0;
//	while (x) {
//		res += x % 4;
//		x /= 4;
//	}
//	return res;
//}
//
//
//int main() {
//	int ans = 0;
//	for (int i = 1; i <= 2024; i++) {
//		if (f2(i) == f4(i)) ans++;
//	}
//	cout << ans << endl;
//	return 0;
//}


// P8809 [蓝桥杯 2022 国 C] 近似 GCD
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//	int n, g;
//	cin >> n >> g;
//	vector<int> a(n);
//	int ans = 0;
//	for (int i = 0; i < n; i++) cin >> a[i];
//	int zuo = -1, you = -1;
//	if (a[0] % g != 0) zuo = 0;
//	for (int i = 1; i < n; i++) {
//		if (a[i] % g == 0) {
//			if (zuo == -1 && you == -1) {
//				ans += i;
//			} else if (you == -1) {
//				ans += i;
//			} else {
//				ans += i - zuo - 1;
//			}
//		} else {
//			if (zuo == -1 && you == -1) {
//				ans += i;
//			} else if (you == -1) {
//				ans += i - zuo - 1;
//			} else {
//				ans += i - you - 1;
//			}
//			if (zuo == -1) zuo = i;
//			else if (you == -1) you = i;
//			else {
//				zuo = you;
//				you = i;
//			}
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}


// 2025.3.16
// P11701 [ROIR 2025] 平方差
//#include <iostream>
//using namespace std;
//#define int long long
//
//signed main() {
//	int l, r, d;
//	cin >> d >> l >> r;
//	int ans = 0;
//	for (int i = 1; i <= d / i; i++) {
//		if (d % i == 0) {
//			int a = d / i;
//			if ((a + i) % 2 == 0 && (a - i) % 2 == 0) {
//				int x = (a + i) / 2;
//				int y = (a - i) / 2;
//				if (l <= y * y && y < x && x * x <= r) {
//					ans++;
//				}
//			}
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}


// 2025.3.17
// P1441 砝码称重
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 25;
//int n, m, ans;
//vector<int> a(N);
//
//void dfs(int step, int start) {
//	if (step == m) {
//		unordered_map<int, bool> mp;
//		for (int i = 0; i < n; i++) {
//			if (a[i] != 0) {
//				vector<int> temp;
//				for (auto p : mp) {
//					temp.push_back(p.first + a[i]);
//				}
//				temp.push_back(a[i]);
//				for (int y : temp) mp[y] = 1;
//			}
//		}
//		ans = max(ans, (int)mp.size());
//	} else {
//		for (int i = start; i < n; i++) {
//			int x = a[i];
//			a[i] = 0;
//			dfs(step + 1, i + 1);
//			a[i] = x;
//		}
//	}
//}
//
//int main() {
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) cin >> a[i];
//	dfs(0, 0);
//	cout << ans << endl;
//	return 0;
//}

// 同上题， 用unordered_set 而不是 unordered_map
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 25;
//int n, m, ans;
//vector<int> a(N);
//
//void dfs(int step, int start) {
//	if (step == m) {
//		unordered_set<int> s;
//		for (int i = 0; i < n; i++) {
//			if (a[i] != 0) {
//				vector<int> temp;
//				for (auto p : s) {
//					temp.push_back(p + a[i]);
//				}
//				temp.push_back(a[i]);
//				for (int y : temp) s.insert(y);
//			}
//		}
//		ans = max(ans, (int)s.size());
//	} else {
//		for (int i = start; i < n; i++) {
//			int x = a[i];
//			a[i] = 0;
//			dfs(step + 1, i + 1);
//			a[i] = x;
//		}
//	}
//}
//
//int main() {
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) cin >> a[i];
//	dfs(0, 0);
//	cout << ans << endl;
//	return 0;
//}


// P1258 小车问题
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//double x(double s, double a, double b) {
//	return (b*b - a*a) * s / (b*b + 2 * a*b - 3 * a*a);
//}
//
//double t(double s, double a, double b) {
//	return x(s, a, b) / b + (s - x(s, a, b)) / a;
//}
//
//signed main() {
//	double s, a, b;
//	cin >> s >> a >> b;
//	printf("%.6lf", t(s, a, b));
//	return 0;
//}


// 2025.3.18
// Open the Lock
//#include <bits/stdc++.h>
//using namespace std;
//
//int quan[4], ans = 1e9;
//bool vis[4];
//string s1, s2;
//
//void dfs(int step) {
//	if (step == 4) {
//		int cnt1 = 0;
//		for (int i = 0; i < 3; i++) {
//			for (int j = i + 1; j < 4; j++) {
//				if (quan[i] > quan[j]) cnt1++;
//			}
//		}
//		string temp = s1;
//		for (int i = 0; i < 4; i++) {
//			s1[i] = temp[quan[i] - 1];
//		}
//		for (int i = 0; i < 4; i++) {
//			char maxc = max(s1[i], s2[i]);
//			char minc = min(s1[i], s2[i]);
//			cnt1 += min(maxc - minc, '9' - maxc + 1 + minc - '1');
//		}
//		ans = min(ans, cnt1);
//		s1 = temp;
//	} else {
//		for (int i = 1; i <= 4; i++) {
//			if (!vis[i]) {
//				quan[step] = i;
//				vis[i] = 1;
//				dfs(step + 1);
//				vis[i] = 0;
//			}
//		}
//	}
//}
//
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> s1 >> s2;
//		dfs(0);
//		cout << ans << endl;
//		ans = 1e9;
//	}
//	return 0;
//}


// 2025.3.18
// P2034 选择数字
//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//	int n, k;
//	cin >> n >> k;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++) cin >> a[i];
//	vector<int> ans(n);
//	vector<int> cnt(n);
//	ans[0] = a[0];
//	cnt[0] = 1;
//	for (int i = 1; i < n; i++) {
//		if (cnt[i - 1] < k) {
//			ans[i] = ans[i - 1] + a[i];
//			cnt[i] = cnt[i - 1] + 1;
//		} else {
//			int sum = 0;
//			ans[i] = ans[i - 1];
//			for (int j = i; j >= i - k; j--) {
//				int x1 = ans[i];
//				int x2 = sum + (j - 1 >= 0 ? ans[j - 1] : 0);
//				if (x1 < x2) {
//					ans[i] = x2;
//					cnt[i] = i - j;
//				}
//				sum += a[j];
//			}
//		}
//	}
////	for (int i = 0; i < n; i++) cout << ans[i] << ' ';
////	cout << endl;
//	cout << ans[n - 1];
//	return 0;
//}


// P10473 表达式计算4
//#include <bits/stdc++.h>
//using namespace std;
//
//stack<int> num;
//stack<char> op;
//unordered_map<char, int> mp = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3}};
//
//void calc() {
//	int b = num.top();
//	num.pop();
//	int a = num.top();
//	num.pop();
//	char o = op.top();
//	op.pop();
//	int c;
//	if (o == '+') {
//		c = a + b;
//	} else if (o == '-') {
//		c = a - b;
//	} else if (o == '*') {
//		c = a * b;
//	} else if (o == '/') {
//		c = a / b;
//	} else {
//		c = pow(a, b);
//	}
//	num.push(c);
//}
//
//int main() {
//	string t, s;
//	cin >> t;
//	s = t;
//	int n = t.size();
//	int cnt = 0;
//	for (int i = 0; i < n; i++) {
//		if (t[i] == '(') cnt++;
//		if (t[i] == ')') {
//			cnt--;
//			if (cnt < 0) {
//				s = '(' + s;
//				cnt = 0;
//			}
//		}
//	}
//	while (cnt > 0) {
//		s += ')';
//		cnt--;
//	}
//	n = s.size();
//	for (int i = 0; i < n; i++) {
//		if (isdigit(s[i])) {
//			int t = 0;
//			int j = i;
//			while (j < n && isdigit(s[j])) {
//				t = 10 * t + s[j] - '0';
//				j++;
//			}
//			i = j - 1;
//			num.push(t);
//		} else if (s[i] == '(') {
//			op.push(s[i]);
//		} else if (s[i] == ')') {
//			while (op.top() != '(') calc();
//			op.pop();
//		} else if (s[i] == '-' && (i == 0 || (!isdigit(s[i - 1]) && s[i - 1] != ')'))) {
//			num.push(-1);
//			op.push('*');
//		} else {
//			while (!op.empty() && mp[op.top()] >= mp[s[i]]) calc();
//			op.push(s[i]);
//		}
//	}
//	while (!op.empty()) calc();
//	cout << num.top() << endl;
//	return 0;
//}


// P1088 [NOIP 2004 普及组] 火星人
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 10005;
//int n, m, cnt;
//int a[N], ans[N];
//bool vis[N];
//
//void dfs(int deep, bool lock) {
//	if (cnt < m + 1) {
//		if (deep == n) {
//			cnt++;
//			if (cnt == m + 1) {
//				for (int i = 0; i < n; i++)
//					cout << ans[i] << ' ';
//			}
//		} else {
//			int st = a[deep];
//			if (!lock) st = 1;
//			for (int i = st; i <= n; i++) {
//				if (!vis[i]) {
//					vis[i] = 1;
//					ans[deep] = i;
//					if (ans[deep] > a[deep]) lock = false;
//					dfs(deep + 1, lock);
//					vis[i] = 0;
//				}
//			}
//		}
//	}
//}
//
//int main() {
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) cin >> a[i];
//	dfs(0, true);
//	return 0;
//}


// P8612 [蓝桥杯 2014 省 AB] 地宫取宝
//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//
//const int N = 55, mod = 1e9 + 7;
//int a[N][N];
//int vis[N][N][14][14];
//int n, m, k;
//
//int dfs(int x, int y, int maxn, int cnt) {
//	if (x > n || y > m) return 0;
//	if (vis[x][y][maxn + 1][cnt] != -1)
//		return vis[x][y][maxn + 1][cnt];
//
//	int res = 0;
//	res += dfs(x + 1, y, maxn, cnt);
//	res += dfs(x, y + 1, maxn, cnt);
//	if (a[x][y] > maxn) {
//		res += dfs(x + 1, y, a[x][y], cnt + 1);
//		res += dfs(x, y + 1, a[x][y], cnt + 1);
//	}
//	if (x == n && y == m) {
//		if (cnt == k || (cnt == k - 1 && a[n][m] > maxn)) {
//			res++;
//		}
//	}
//	vis[x][y][maxn + 1][cnt] = res % mod;
//	return vis[x][y][maxn + 1][cnt];
//}
//
//signed main() {
//	cin >> n >> m >> k;
//	memset(vis, -1, sizeof(vis));
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= m; j++)
//			cin >> a[i][j];
//
//	cout << dfs(1, 1, -1, 0);
//	return 0;
//}


// P8654 [蓝桥杯 2017 国 C] 合根植物
//#include <bits/stdc++.h>
//using namespace std;
//
//int find(int x, vector<int>& arr) {
//	if (x != arr[x]) {
//		arr[x] = find(arr[x], arr);
//	}
//	return arr[x];
//}
//
//int main() {
//	int m, n;
//	cin >> m >> n;
//	vector<int> a(m * n + 1);
//	for (int i = 1; i <= m * n; i++) a[i] = i;
//	int k;
//	cin >> k;
//	while (k--) {
//		int x, y;
//		cin >> x >> y;
//		int fa = find(x, a);
//		a[fa] = find(y, a);
//	}
//	unordered_set<int> s;
//	for (int i = 1; i <= m * n; i++) {
//		s.insert(find(i, a));
//	}
//	cout << s.size() << endl;
//	return 0;
//}


// P8620 [蓝桥杯 2014 国 A] 排列序数
//#include <bits/stdc++.h>
//using namespace std;
//
//string s;
//int ans, n, cnt;
//bool vis[11];
//string res;
//
//void dfs(int deep) {
//	if (deep == n) {
//		if (res == s)
//			ans = cnt;
//		cnt++;
//	} else {
//		for (int i = 1; i <= n; i++) {
//			if (!vis[i]) {
//				res[deep] = i - 1 + 'a';
//				vis[i] = 1;
//				dfs(deep + 1);
//				vis[i] = 0;
//			}
//		}
//	}
//}
//
//int main() {
//	cin >> s;
//	res = s;
//	n = s.size();
//	dfs(0);
//	cout << ans << endl;
//	return 0;
//}


// P8637 [蓝桥杯 2016 省 B] 交换瓶子
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int> a(n + 1);
//	for (int i = 1; i <= n; i++) cin >> a[i];
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		if (a[i] != i) {
//			int j;
//			for (j = i + 1; j <= n; j++) {
//				if (a[j] == i) break;
//			}
//			swap(a[i], a[j]);
//			ans++;
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}


// P10095 [ROIR 2023] 斐波那契乘积 (Day 1)
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//int fibo[100], n;
//unordered_map<string, int> mp;
//
//int dfs(int x, int fib) {
//	if (x == 1) return 1;
//	string hash_s = to_string(x) + '+' + to_string(fib);
//	if (mp.find(hash_s) != mp.end())
//		return mp[hash_s];
//	int res = 0;
//	int i = 0;
//	while (fibo[i] != fib) i++;
//	for (; fibo[i] <= x; i++) {
//		if (x % fibo[i] == 0) {
//			res += dfs(x / fibo[i], fibo[i]);
//		}
//	}
//	mp[hash_s] = res;
//	return res;
//}
//
//signed main() {
//	fibo[0] = 2;
//	fibo[1] = 3;
//	n = 1;
//	while (fibo[n] <= 1e18) {
//		fibo[n + 1] = fibo[n] + fibo[n - 1];
//		n++;
//	}
//	n--;
//	int t;
//	cin >> t;
//	while (t--) {
//		int a;
//		cin >> a;
//		cout << dfs(a, 2) << endl;
//	}
//	return 0;
//}


// P1908 逆序对 (自己想到的O(nlogn)方法，尝试一下哈哈哈)
// 后来才知道没软用呜呜呜，因为distance对于set的时间复杂度还是O(n)
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++) cin >> a[i];
//	set<int> s;
//	int ans = 0;
//	s.insert(a[0]);
//	for (int i = 1; i < n; i++) {
//		ans += distance(s.upper_bound(a[i]), s.end());
//		s.insert(a[i]);
//	}
//	cout << ans << endl;
//	return 0;
//}


// P1123 取数游戏
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 8;
//int a[N][N], t, n, m, ans;
//int vis[N][N];
//int dx[] = {-1, 0, 1, -1, 0, 1, -1, 1};
//int dy[] = {-1, -1, -1, 1, 1, 1, 0, 0};
//
//void dfs(int x, int y, int res) {
//	if (y == m + 1) {
//		dfs(x + 1, 1, res);
//		return;
//	}
//	if (x == n + 1) {
//		ans = max(res, ans);
//		return;
//	}
//	dfs(x, y + 1, res);
//
//	if (!vis[x][y]) {
//		for (int i = 0; i < 8; i++) {
//			int x_ = x + dx[i];
//			int y_ = y + dy[i];
//			vis[x_][y_]++;
//		}
//		dfs(x, y + 1, res + a[x][y]);
//		for (int i = 0; i < 8; i++) {
//			int x_ = x + dx[i];
//			int y_ = y + dy[i];
//			vis[x_][y_]--;
//		}
//	}
//}
//
//int main() {
//	cin >> t;
//	while (t--) {
//		cin >> n >> m;
//		for (int i = 1; i <= n; i++)
//			for (int j = 1; j <= m; j++)
//				cin >> a[i][j];
//		dfs(1, 1, 0);
//		cout << ans << endl;
//		ans = 0;
//	}
//	return 0;
//}


// P8599 [蓝桥杯 2013 省 B] 带分数
//#include <bits/stdc++.h>
//using namespace std;
//
//int ans, n;
//string s = "000000000";
//bool vis[10];
//
//void dfs(int deep) {
//	if (deep == 9) {
//		for (int i = 1; i < 7; i++) {
//			int mid = (8 + i) / 2;
//			for (int j = mid; j < 9; j++) {
//				int a = stoi(s.substr(0, i));
//				int b = stoi(s.substr(i, j - i));
//				int c = stoi(s.substr(j, 9 - j));
//				if (a + 1.0 * b / c == n) ans++;
//			}
//		}
//	} else {
//		for (int i = 1; i <= 9; i++) {
//			if (!vis[i]) {
//				vis[i] = 1;
//				s[deep] = i + '0';
//				dfs(deep + 1);
//				vis[i] = 0;
//			}
//		}
//	}
//}
//
//int main() {
//	cin >> n;
//	dfs(0);
//	cout << ans << endl;
//	return 0;
//}


// P8599 [蓝桥杯 2013 省 B] 带分数
//#include <bits/stdc++.h>
//using namespace std;
//
//int n, ans;
//
//bool ishe(int x) {
//	string s = to_string(x);
//	unordered_map<char, int> mp;
//	for (char c : s) {
//		mp[c]++;
//		if (mp[c] >= 2) return false;
//	}
//	return true;
//}
//
//bool ishe2(int a, int b, int c) {
//	string s = to_string(a) + to_string(b) + to_string(c);
//	if (s.length() != 9) return false;
//	unordered_map<char, int> mp;
//	for (char c : s) {
//		mp[c]++;
//		if (mp[c] >= 2 || c == '0') return false;
//	}
//	return true;
//}
//
//int main() {
//	cin >> n;
//	for (int i = 1; i < n; i++) {
//		if (ishe(i)) {
//			int cha = n - i;
//			int cha_len = to_string(i).size();
//			cha_len = 9 - cha_len;
//			int a = cha, b = 1;
//			string s = to_string(a) + to_string(b);
//			while ((int)s.length() <= cha_len) {
//				if (ishe2(a, b, i)) {
//					ans++;
//					cout << i << ' ' << a << ' ' << b << endl;
//				}
//				b++;
//				a = cha * b;
//				s = to_string(a) + to_string(b);
//			}
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}


// P10905 [蓝桥杯 2024 省 C] 回文字符串
//#include <bits/stdc++.h>
//using namespace std;
//
//bool is_hui(string s) {
//	for (unsigned i = 0; i < s.size() / 2; i++) {
//		if (s[i] != s[s.length() - i - 1])
//			return false;
//	}
//	return true;
//}
//
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		string s;
//		cin >> s;
//		if (is_hui(s)) {
//			cout << "Yes" << endl;
//			continue;
//		}
//		bool have_ans = false;
//		int qian = 0;
//		for (int i = 0; i < (int)s.size(); i++)
//			if (s[i] == 'l' || s[i] == 'q' || s[i] == 'b')
//				qian++;
//			else
//				break;
//		int cnt = 0;
//		for (unsigned i = s.size() - 1; i >= 0; i--) {
//			if (s[i] == 'l' || s[i] == 'q' || s[i] == 'b')
//				cnt++;
//			else
//				break;
//		}
//		int cnt2 = 0;
//		for (unsigned i = s.size() - 1; i >= 0; i--) {
//			if (s[i] == 'l' || s[i] == 'q' || s[i] == 'b') {
//				s.pop_back();
//				cnt2++;
//			} else break;
//			if (s.size() == 0) break;
//			if (cnt - cnt2 == qian && is_hui(s)) {
//				have_ans = true;
//				cout << "Yes" << endl;
//				break;
//			}
//		}
//		if (!have_ans) {
//			if (s.length() == 0 || is_hui(s)) cout << "Yes" << endl;
//			else cout << "No" << endl;
//		}
//	}
//	return 0;
//}


// P8715 [蓝桥杯 2020 省 AB2] 子串分值
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	string s;
//	cin >> s;
//	int n = s.length();
//	s = ' ' + s;
//	int ans = 0;
//	unordered_map<char, int> mp;
//	vector<int> pre(n + 1);
//	for (int i = 1; i <= n; i++) {
//		pre[i] = mp[s[i]];
//		mp[s[i]] = i;
//	}
//	mp.clear();
//	vector<int> ed(n + 1);
//	for (int i = n; i >= 1; i--) {
//		if (mp.find(s[i]) == mp.end())
//			ed[i] = n + 1;
//		else
//			ed[i] =  mp[s[i]];
//		mp[s[i]] = i;
//	}
//	for (int i = 1; i <= n; i++) {
//		ans += (i - pre[i]) * (ed[i] - i);
//	}
//	cout << ans << endl;
//	return 0;
//}


// P1775 石子合并（弱化版） 没学过区间dp也能自己想出来，不错哈哈哈
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//	int n;
//	cin >> n;
//	vector<int> a(n + 1);
//	for (int i = 1; i <= n; i++) cin >> a[i];
//	vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
//	vector<int> sum(n + 1);
//	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
//	for (int i = 1; i <= n; i++) dp[i][i] = 0;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; i + j <= n; j++) {
//			for (int k = j; k < i + j; k++) {
//				if (dp[j][i + j] == -1) dp[j][i + j] = 1e18;
//				dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + sum[i + j] - sum[j - 1]);
//			}
//		}
//	}
//	cout << dp[1][n] << endl;
//	return 0;
//}


// P8671 [蓝桥杯 2018 国 AC] 约瑟夫环
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n, k;
//	cin >> n >> k;
//	int ans = 0;
//	for (int i = 2; i <= n; i++) {
//		ans = (ans + k) % i;
//	}
//	cout << ans + 1 << endl;
//	return 0;
//}


// P8801 [蓝桥杯 2022 国 B] 最大数字
//#include <bits/stdc++.h>
//using namespace std;
//
//string n, ans;
//int a, b;
//
//void dfs(int deep, string res) {
//	ans = max(ans, res);
//	if (deep >= (int)n.size()) return;
//	if (a == 0 && b == 0) return;
//	if (res[deep] == '9') {
//		dfs(deep + 1, res);
//		return;
//	}
//	if (res[deep] + a >= '9') {
//		a -= '9' - res[deep];
//		char temp = res[deep];
//		res[deep] = '9';
//		dfs(deep + 1, res);
//		res[deep] = temp;
//		a += '9' - res[deep];
//	}
//	if (res[deep] - b < '0') {
//		b -= res[deep] - '0' + 1;
//		char temp = res[deep];
//		res[deep] = '9';
//		dfs(deep + 1, res);
//		res[deep] = temp;
//		b += res[deep] - '0' + 1;
//	}
//
//	if (!(res[deep] + a >= '9') && !(res[deep] - b < '0')) {
//		int t = a;
//		a = 0;
//		res[deep] += t;
//		dfs(deep + 1, res);
//		res[deep] -= t;
//		a = t;
//	}
//}
//
//int main() {
//	cin >> n >> a >> b;
//	ans = n;
//	dfs(0, n);
//	cout << ans << endl;
//	return 0;
//}


// P8650 [蓝桥杯 2017 省 A] 正则问题
// 太妙了真的，编程之美，不逊于数学之美
//#include <bits/stdc++.h>
//using namespace std;
//
//string s;
//
//int res(int& deep, int ans) {
//	if (deep >= (int)s.size()) return ans;
//	while (deep < (int)s.size()) {
//		if (s[deep] == 'x') {
//			ans++;
//			deep++;
//		}
//		if (s[deep] == '(') {
//			deep += 1;
//			ans += res(deep, 0);
//		}
//		if (s[deep] == ')') {
//			deep++;
//			return ans;
//		}
//		if (s[deep] == '|') {
//			deep++;
//			return max(ans, res(deep, 0));
//		}
//	}
//	return ans;
//}
//
//int main() {
//	cin >> s;
//	int deep = 0;
//	cout << res(deep, 0);
//	return 0;
//}


// P8783 [蓝桥杯 2022 省 B] 统计子矩阵
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//const int N = 505;
//int a[N][N], n, m, k, sum[N][N];
//
//int get(int x1, int y1, int x2, int y2) {
//	return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
//}
//
//signed main() {
//	cin >> n >> m >> k;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			cin >> a[i][j];
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			sum[i][j] = a[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
//		}
//	}
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		for (int j = i; j <= n; j++) {
//			int l = 1, r = 1;
//			for (; r <= m; r++) {
//				int s = get(i, l, j, r);
//				if (s <= k) ans += r - l + 1;
//				else {
//					l++;
//					r--;
//				}
//			}
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}


// P4387 【深基15.习9】验证栈序列
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int q;
//	cin >> q;
//	while (q--) {
//		int n;
//		cin >> n;
//		vector<int> a(n), b(n);
//		for (int i = 0; i < n; i++) cin >> a[i];
//		for (int i = 0; i < n; i++) cin >> b[i];
//		stack<int> s;
//		int idx = 0;
//		for (int i = 0; i < n; i++) {
//			s.push(a[i]);
//			while (!s.empty() && idx < n && s.top() == b[idx]) {
//				s.pop();
//				idx++;
//			}
//		}
//		if (s.empty()) cout << "Yes" << endl;
//		else cout << "No" << endl;
//	}
//	return 0;
//}


// P8786 [蓝桥杯 2022 省 B] 李白打酒加强版
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 105, mod = 1e9 + 7;
//int f[2 * N][N][2 * N];
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	f[0][0][2] = 1;
//	for (int i = 0; i < n + m; i++) {
//		for (int j = 0; j <= n; j++) {
//			for (int k = 1; k <= m; k++) {
//				if (f[i][j][k]) {
//					f[i + 1][j][k - 1] = (f[i + 1][j][k - 1] + f[i][j][k]) % mod;
//					f[i + 1][j + 1][2 * k] = (f[i + 1][j + 1][2 * k] + f[i][j][k]) % mod;
//				}
//			}
//		}
//	}
//	cout << f[n + m - 1][n][1];
//	return 0;
//}


// P8647 [蓝桥杯 2017 省 AB] 分巧克力
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 100005;
//vector<pair<int, int>> a(N);
//int n, k;
//
//bool manzu(int x) {
//	int cnt = 0;
//	for (int i = 0; i < n; i++) {
//		cnt += (a[i].first / x) * (a[i].second / x);
//	}
//	if (cnt >= k) return true;
//	return false;
//}
//
//int main() {
//	cin >> n >> k;
//	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
//	int l = 1, r = N;
//	int ans = -1;
//	while (l <= r) {
//		int mid = (l + r) / 2;
//		if (manzu(mid)) {
//			ans = mid;
//			l = mid + 1;
//		} else {
//			r = mid - 1;
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}


// P10909 [蓝桥杯 2024 国 B] 立定跳远
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 100005;
//int a[N], n, m;
//
//bool manzu(int x) {
//	int cnt = 0;
//	if (x == 0) return false;
//	if (a[0] % x == 0) cnt += max(0, a[0] / x - 1);
//	else cnt += a[0] / x;
//	for (int i = 1; i < n; i++) {
//		if ((a[i] - a[i - 1]) % x == 0) cnt += max(0, (a[i] - a[i - 1]) / x - 1);
//		else cnt += (a[i] - a[i - 1]) / x;
//	}
//	if (cnt <= m + 1) return true;
//	return false;
//}
//
//int main() {
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) cin >> a[i];
//	int l = 0, r = 1e8;
//	int ans = -1;
//	while (l <= r) {
//		int mid = (l + r) / 2;
//		if (manzu(mid)) {
//			ans = mid;
//			r = mid - 1;
//		} else
//			l = mid + 1;
//	}
//	cout << ans << endl;
//	return 0;
//}


// P8725 [蓝桥杯 2020 省 AB3] 画中漂流
//#include <bits/stdc++.h>
//using namespace std;
//
//const int mod = 1e9 + 7, N = 3030;
//int dp[N][N];
//
//int main() {
//	int d, t, m;
//	cin >> d >> t >> m;
//	dp[0][m] = 1;
//	for (int i = 1; i <= t; i++) {
//		for (int j = 0; j <= m; j++) {
//			int len = d + m - j - (i - m + j);
//			if (len > 0) {
//				dp[i][j] = (dp[i - 1][j] + dp[i - 1][j + 1]) % mod;
//			}
//		}
//	}
//	cout << dp[t][0];
//	return 0;
//}


// P8667 [蓝桥杯 2018 省 B] 递增三元组
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//const int N = 100010;
//vector<int> a(N), b(N), c(N);
//
//signed main() {
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++) cin >> a[i];
//	for (int i = 0; i < n; i++) cin >> b[i];
//	for (int i = 0; i < n; i++) cin >> c[i];
//	sort(a.begin(), a.begin() + n);
//	sort(c.begin(), c.begin() + n);
//	int ans = 0;
//	for (int i = 0; i < n; i++) {
//		int x = lower_bound(a.begin(), a.begin() + n, b[i]) - a.begin();
//		int y = c.begin() + n - upper_bound(c.begin(), c.begin() + n, b[i]);
//		ans += x * y;
//	}
//	cout << ans << endl;
//	return 0;
//}


// P8686 [蓝桥杯 2019 省 A] 修改数组
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++) cin >> a[i];
//	unordered_map<int, int> mp;
//	set<int> s;
//	for (int i = 1; i <= 1e6; i++) s.insert(i);
//	mp[a[0]]++;
//	s.erase(s.find(a[0]));
//	for (int i = 1; i < n; i++) {
//		if (mp[a[i]]) {
//			if (s.find(a[i]) != s.end())
//				s.erase(s.find(a[i]));
//			a[i] = *s.lower_bound(a[i]);
//		}
//		mp[a[i]]++;
//		if (s.find(a[i]) != s.end())
//			s.erase(s.find(a[i]));
//	}
//	for (int i = 0; i < n; i++) cout << a[i] << ' ';
//	return 0;
//}


// P1579 哥德巴赫猜想（升级版）
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 20010;
//int primes[N], cnt;
//bool not_prime[N];
//
//void euler() {
//	not_prime[1] = 1;
//	for (int i = 2; i < N; i++) {
//		if (!not_prime[i]) primes[cnt++] = i;
//		for (int j = 0; primes[j] * i < N; j++) {
//			not_prime[primes[j] * i] = 1;
//			if (i % primes[j] == 0) break;
//		}
//	}
//}
//
//int main() {
//	int n;
//	cin >> n;
//	euler();
//	bool have_ans = false;
//	for (int i = 0; i < cnt; i++) {
//		for (int j = i; j < cnt; j++) {
//			int x = n - primes[i] - primes[j];
//			if (x > 0 && !not_prime[x]) {
//				cout << primes[i] << ' ' << primes[j] << ' ' << x;
//				have_ans = true;
//				break;
//			}
//		}
//		if (have_ans) break;
//	}
//	return 0;
//}


// P10589 楼兰图腾(树状数组)
//#include <cstdio>
//#include <cstring>
//using namespace std;
//
//const int N = 200010;
//int tr[N], dayu[N], xiaoyu[N], n, a[N];
//
//int lowbit(int x) {
//	return x & -x;
//}
//
//int ask(int x) {
//	int sum = 0;
//	for (int i = x; i; i -= lowbit(i))
//		sum += tr[i];
//	return sum;
//}
//
//void add(int x, int c) {
//	for (int i = x; i <= n; i += lowbit(i))
//		tr[i] += c;
//}
//
//int main() {
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
//	for (int i = 1; i <= n; i++) {
//		int y = a[i];
//		dayu[i] = ask(n) - ask(y);
//		xiaoyu[i] = ask(y - 1);
//		add(y, 1);
//	}
//	long long res1 = 0, res2 = 0;
//	memset(tr, 0, sizeof tr);
//	for (int i = n; i >= 1; i--) {
//		int y = a[i];
//		res1 += (long long)dayu[i] * (ask(n) - ask(y));
//		res2 += (long long)xiaoyu[i] * ask(y - 1);
//		add(y, 1);
//	}
//	printf("%lld %lld", res1, res2);
//	return 0;
//}


// P3374 【模板】树状数组 1
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 5e5 + 10;
//int tr[N], n, m;
//
//void add(int x, int c) {
//	for (int i = x; i <= n; i += i & -i)
//		tr[i] += c;
//}
//
//int sum(int x) {
//	int res = 0;
//	for (int i = x; i > 0; i -= i & -i)
//		res += tr[i];
//	return res;
//}
//
//int main() {
//	int x;
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		cin >> x;
//		add(i, x);
//	}
//	int o, y;
//	while (m--) {
//		cin >> o >> x >> y;
//		if (o == 1) add(x, y);
//		else cout << sum(y) - sum(x - 1) << endl;
//	}
//	return 0;
//}


// P1908 逆序对 (再次挑战，用树状数组)
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 5e5+10;
//int tr[N], n;
//
//int sum(int x) {
//	int res = 0;
//	for (int i = x; i > 0; i -= i & -i)
//		res += tr[i];
//	return res;
//}
//
//void add(int x, int c) {
//	for (int i = x; i <= N - 1; i += i & -i)
//		tr[i] += c;
//}
//
//int main() {
//	cin >> n;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++) cin >> a[i];
//	vector<int> b(a.begin(), a.end());
//	sort(b.begin(), b.end());
//	b.erase(unique(b.begin(), b.end()), b.end());
//	long long ans = 0;
//	for (int i = 0; i < n; i++) {
//		int x = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
//		ans += sum(N - 1) - sum(x);
//		add(x, 1);
//	}
//	cout << ans << endl;
//	return 0;
//}


// P1637 三元上升子序列
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 1e5 + 10;
//int n, tr[N];
//
//void add(int x, int c) {
//	for (int i = x; i <= N - 1; i += i & -i)
//		tr[i] += c;
//}
//
//int ask(int x) {
//	int res = 0;
//	for (int i = x; i > 0; i -= i & -i)
//		res += tr[i];
//	return res;
//}
//
//int main() {
//	cin >> n;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++) cin >> a[i];
//	vector<int> xiao(n);
//	for (int i = 0; i < n; i++) {
//		int x = a[i];
//		xiao[i] = ask(x - 1);
//		add(x, 1);
//	}
//	long long res = 0;
//	memset(tr, 0, sizeof tr);
//	for (int i = n - 1; i >= 0; i--) {
//		res += (long long)xiao[i] * (ask(N - 1) - ask(a[i]));
//		add(a[i], 1);
//	}
//	cout << res << endl;
//	return 0;
//}


// P3368 【模板】树状数组 2
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 5e5 + 10;
//int tr[N];
//
//void add(int x, int c) {
//	for (int i = x; i < N; i += i & -i)
//		tr[i] += c;
//}
//
//void add(int l, int r, int c) {
//	add(l, c);
//	add(r + 1, -c);
//}
//
//int sum(int x) {
//	int res = 0;
//	for (int i = x; i > 0; i -= i & -i)
//		res += tr[i];
//	return res;
//}
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	int x;
//	for (int i = 1; i <= n; i++) {
//		cin >> x;
//		add(i, i, x);
//	}
//	while (m--) {
//		int o;
//		cin >> o;
//		if (o == 1) {
//			int y, k;
//			cin >> x >> y >> k;
//			add(x, y, k);
//		} else {
//			cin >> x;
//			cout << sum(x) << endl;
//		}
//	}
//	return 0;
//}


// P1168 中位数   非正解
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int> a;
//	int x;
//	cin >> x;
//	a.insert(a.begin(), x);
//	cout << x << endl;
//	for (int i = 1; i < n; i++) {
//		cin >> x;
//		a.insert(lower_bound(a.begin(), a.end(), x), x);
//		if (i % 2 == 0) {
//			cout << a[i / 2] << endl;
//		}
//	}
//	return 0;
//}


// P1168 中位数
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 100010;
//int tr[N];
//
//void add(int x, int c) {
//	for (int i = x; i < N; i += i & -i)
//		tr[i] += c;
//}
//
//int sum(int x) {
//	int res = 0;
//	for (int i = x; i > 0; i -= i & -i)
//		res += tr[i];
//	return res;
//}
//
//int find(int x) {
//	int l = 1, r = N - 1;
//	int ans = -1;
//	while (l <= r) {
//		int mid = (l + r) / 2;
//		if (sum(mid) >= x) {
//			r = mid - 1;
//			ans = mid;
//		} else l = mid + 1;
//	}
//	return ans;
//}
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++) cin >> a[i];
//	vector<int> b = a;
//	sort(b.begin(), b.end());
//	b.erase(unique(b.begin(), b.end()), b.end());
//	for (int i = 0; i < n; i++) {
//		int x = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
//		add(x, 1);
//		if (i % 2 == 0) {
//			int y = find(i / 2 + 1);
//			cout << b[y - 1] << endl;
//		}
//	}
//	return 0;
//}


// P8613 [蓝桥杯 2014 省 B] 小朋友排队
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 1000010;
//int tr[N];
//
//int ask(int x) {
//	int res = 0;
//	for (int i = x; i > 0; i -= i & -i)
//		res += tr[i];
//	return res;
//}
//
//void add(int x, int c) {
//	for (int i = x; i < N; i += i & -i)
//		tr[i] += c;
//}
//
//long long f(long long x) {
//	return (x + 1) * x / 2;
//}
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	long long ans = 0;
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//		a[i]++;
//	}
//	vector<int> da(n);
//	for (int i = 0; i < n; i++) {
//		int x = a[i];
//		da[i] = ask(N - 1) - ask(x);
//		add(x, 1);
//	}
//	memset(tr, 0, sizeof tr);
//	for (int i = n - 1; i >= 0; i--) {
//		ans += f(da[i] + ask(a[i] - 1));
//		add(a[i], 1);
//	}
//	cout << ans << endl;
//	return 0;
//}


// P1774 最接近神的人
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 500010;
//int tr[N];
//
//int sum(int x) {
//	int res = 0;
//	for (int i = x; i > 0; i -= i & -i)
//		res += tr[i];
//	return res;
//}
//
//void add(int x, int c) {
//	for (int i = x; i < N; i += i & -i)
//		tr[i] += c;
//}
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++) cin >> a[i];
//	vector<int> b = a;
//	sort(b.begin(), b.end());
//	b.erase(unique(b.begin(), b.end()), b.end());
//	long long res = 0;
//	for (int i = 0; i < n; i++) {
//		int x = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
//		res += sum(b.size()) - sum(x);
//		add(x, 1);
//	}
//	cout << res;
//	return 0;
//}


// P8787 [蓝桥杯 2022 省 B] 砍竹子
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++) cin >> a[i];
//	int ans = 0;
//	unordered_map<int, bool> mp_last, mp_now;
//	for (int i = 0; i < n; i++) {
//		if (i == 0) {
//			int x = a[i];
//			while (x != 1) {
//				ans++;
//				mp_last[x] = 1;
//				x = (int)sqrtl((x / 2) + 1);
//			}
//			mp_last[1] = 1;
//		} else {
//			int x = a[i];
//			while (x != 1) {
//				mp_now[x] = 1;
//				x = (int)sqrtl((x / 2) + 1);
//			}
//			mp_last[1] = 1;
//			int k = 0;
//			x = a[i];
//			while (mp_last[x] == 0) {
//				k++;
//				x = (int)sqrtl((x / 2) + 1);
//			}
//			ans += k;
//			mp_last = mp_now;
//			mp_now.clear();
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}


// P8708 [蓝桥杯 2020 省 A1] 整数小拼接
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//int n, k;
//string s;
//
//int get_max(int x) {
//	string s_x = to_string(x);
//	if (s.size() <= s_x.size()) return 0;
//	string temp = s.substr(0, s_x.size());
//	int k = s.size() - s_x.size();
//	if (temp > s_x)
//		return (int)(powl(10, k) - 1);
//	else if (temp < s_x) {
//		return (int)(powl(10, k - 1) - 1);
//	} else {
//		return stoll(s.substr(s_x.size(), k));
//	}
//}
//
//signed main() {
//	cin >> n >> k;
//	s = to_string(k);
//	vector<int> a(n);
//	for (int i = 0; i < n; i++) cin >> a[i];
//	sort(a.begin(), a.end());
//	int ans = 0;
//	for (int i = 0; i < n; i++) {
//		int maxn = get_max(a[i]);
//		int x = upper_bound(a.begin(), a.end(), maxn) - a.begin();
//		if (x > i) x--;
//		ans += x;
//	}
//	cout << ans << endl;
//	return 0;
//}


// P9234 [蓝桥杯 2023 省 A] 买瓜
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 35;
//int a[N], n, m, ans = INT32_MAX;
//unordered_map<int, int> mp;
//
//void dfs1(int s, int cnt, int sum) {
//	if (s > n / 2) {
//		if (mp.find(sum) == mp.end())
//			mp[sum] = cnt;
//		else
//			mp[sum] = min(cnt, mp[sum]);
//		return;
//	}
//	if (cnt >= ans || sum > m) return;
//	dfs1(s + 1, cnt + 1, sum + a[s] / 2);
//	dfs1(s + 1, cnt, sum + a[s]);
//	dfs1(s + 1, cnt, sum);
//}
//
//void dfs2(int s, int cnt, int sum) {
//	if (mp.find(m - sum) != mp.end()) {
//		ans = min(ans, mp[m - sum] + cnt);
//		return;
//	}
//	if (s > n) {
//		return;
//	}
//	if (cnt >= ans || sum > m) return;
//	dfs2(s + 1, cnt + 1, sum + a[s] / 2);
//	dfs2(s + 1, cnt, sum + a[s]);
//	dfs2(s + 1, cnt, sum);
//}
//
//int main() {
//	cin >> n >> m;
//	m *= 2;
//	for (int i = 1; i <= n; i++) cin >> a[i], a[i] *= 2;
//	sort(a + 1, a + n + 1);
//	dfs1(1, 0, 0);
//	dfs2(n / 2 + 1, 0, 0);
//	if (ans == INT32_MAX) ans = -1;
//	cout << ans << endl;
//	return 0;
//}


// P5142 区间方差   学线段树第一题，还好不用区间修改，因为这个还没学
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//const int N = 1e5 + 3, mod = 1e9 + 7;
//int pinjun[4 * N], pinfang[4 * N], a[N], n, m;
//
//int ni(int x, int p) {
//	x %= p;
//	int res = 1;
//	int y = p - 2;
//	while (y) {
//		if (y & 1) res = res * x % p;
//		y >>= 1;
//		x = x * x % p;
//	}
//	return res;
//}
//
//void build(int l, int r, int i) {
//	if (l == r) {
//		pinjun[i] = a[l] % mod;
//		pinfang[i] = a[l] * a[l] % mod;
//	} else {
//		int mid = (l + r) >> 1;
//		build(l, mid, i << 1);
//		build(mid + 1, r, i << 1 | 1);
//		pinjun[i] = (pinjun[i << 1] + pinjun[i << 1 | 1]) % mod;
//		pinfang[i] = (pinfang[i << 1] + pinfang[i << 1 | 1]) % mod;
//	}
//}
//
//int query(int jobl, int jobr, int l, int r, int i, int arr[]) {
//	if (jobl <= l && r <= jobr)
//		return arr[i];
//	int res = 0;
//	int mid = (l + r) >> 1;
//	if (jobl <= mid) {
//		res += query(jobl, jobr, l, mid, i * 2, arr);
//	}
//	if (jobr > mid) {
//		res += query(jobl, jobr, mid + 1, r, i * 2 + 1, arr);
//	}
//	return res;
//}
//
//void change(int x, int y, int l, int r, int i) {
//	if (l == r) {
//		pinjun[i] = y;
//		pinfang[i] = y * y % mod;
//		return;
//	}
//	int mid = (l + r) >> 1;
//	if (mid < x) {
//		change(x, y, mid + 1, r, i << 1 | 1);
//	} else {
//		change(x, y, l, mid, i << 1);
//	}
//	pinfang[i] = pinfang[i << 1] + pinfang[i << 1 | 1];
//	pinjun[i] = pinjun[i << 1] + pinjun[i << 1 | 1];
//}
//
//signed main() {
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) cin >> a[i];
//	build(1, n, 1);
//	while (m--) {
//		int c, x, y;
//		cin >> c >> x >> y;
//		if (c == 1) change(x, y, 1, n, 1);
//		else {
//			int niyuan = ni(y - x + 1, mod);
//			int pin = query(x, y, 1, n, 1, pinjun) % mod * niyuan % mod;
//			int ans = ((query(x, y, 1, n, 1, pinfang) % mod * niyuan % mod) - pin % mod * pin % mod);
//			cout << (ans % mod + mod) % mod << endl;
//		}
//	}
//	return 0;
//}


/// P1471 方差   转战其他
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 1e5 + 3;
//int n, m;
//double a[N], pingjun[4 * N], pingfang[4 * N], add_pingjun[4 * N], add_pingfang[4 * N];
//
//void build(int l, int r, int i) {
//	if (l == r) {
//		pingfang[i] = a[l] * a[l];
//		pingjun[i] = a[l];
//	} else {
//		int mid = (l + r) >> 1;
//		build(l, mid, i << 1);
//		build(mid + 1, r, i << 1 | 1);
//		pingfang[i] = pingfang[i << 1] + pingfang[i << 1 | 1];
//		pingjun[i] = pingjun[i << 1] + pingjun[i << 1 | 1];
//	}
//}
//
//double query(int jobl, int jobr, int l, int r, int i, double arr[]) {
//	if (jobl <= l && r <= jobr) {
//		return arr[i];
//	}
//	double res = 0;
//	int mid = (l + r) >> 1;
//	if (jobl <= mid) {
//		res += query(jobl, jobr, l, mid, i << 1, arr);
//	}
//	if (mid < jobr) {
//		res += query(jobl, jobr, mid + 1, r, i << 1 | 1, arr);
//	}
//	return res;
//}
//
//void change(int jobl, int jobr, int jobk, int l, int r, int i) {
//
//}
//
//int main() {
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) cin >> a[i];
//	build(1, n, 1);
//
//	return 0;
//}


// P1876 开灯
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	long long n;
//	cin >> n;
//	int x = 1;
//	while (x * x <= n) {
//		cout << x * x << ' ';
//		x++;
//	}
//	return 0;
//}


// P1067 [NOIP 2009 普及组] 多项式输出
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	bool first = true;
//	for (int i = n; i >= 0; i--) {
//		int x;
//		cin >> x;
//		if (x) {
//			if (x > 0) {
//				if (x == 1) {
//					if (!first) cout << '+';
//					if (i == 0) cout << 1;
//				} else {
//					if (first) cout << x;
//					else cout << '+' << x;
//				}
//			} else {
//				if (x == -1) {
//					cout << '-';
//					if (i == 0) cout << 1;
//				} else {
//					cout << x;
//				}
//			}
//			first = false;
//			if (i != 0) {
//				cout << 'x';
//				if (i != 1) {
//					cout << '^' << i;
//				}
//			}
//		}
//	}
//	return 0;
//}


// P1157 组合的输出
//#include <bits/stdc++.h>
//using namespace std;
//
//int n, m, a[25];
//void dfs(int deep, int start) {
//	if (deep == m) {
//		for (int i = 0; i < m; i++)
//			cout << setw(3) << a[i];
//		cout << endl;
//	} else {
//		for (int i = start; i <= n; i++) {
//			a[deep] = i;
//			dfs(deep + 1, i + 1);
//		}
//	}
//}
//
//int main() {
//	cin >> n >> m;
//	dfs(0, 1);
//	return 0;
//}


// P1387 最大正方形
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	vector<vector<int>> a(n + 1, vector<int>(m + 1));
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			int x;
//			cin >> x;
//			if (x == 1) {
//				a[i][j] = min(a[i - 1][j], min(a[i - 1][j - 1], a[i][j - 1])) + 1;
//				ans = max(ans, a[i][j]);
//			}
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}


// P8732 [蓝桥杯 2020 国 ABC] 答疑
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//struct t {
//	int s;
//	int a;
//	int e;
//};
//
//bool cmp(t x, t y) {
//	int sumx = x.a + x.s + x.e;
//	int sumy = y.a + y.s + y.e;
//	if (sumx == sumy) {
//		return x.a + x.s < y.a + y.s;
//	} else return sumx < sumy;
//}
//
//signed main() {
//	int n;
//	cin >> n;
//	vector<t> a(n);
//	for (int i = 0; i < n; i++) cin >> a[i].s >> a[i].a >> a[i].e;
//	sort(a.begin(), a.end(), cmp);
//	int ans = 0;
//	int now = 0;
//	for (int i = 0; i < n; i++) {
//		ans += now + a[i].a + a[i].s;
//		now += a[i].a + a[i].s + a[i].e;
//	}
//	cout << ans << endl;
//	return 0;
//}


// P10903 [蓝桥杯 2024 省 C] 商品库存管理
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	vector<int> a(n + 2);
//	vector<pair<int, int>> caozuo(m);
//	for (int i = 0; i < m; i++) cin >> caozuo[i].first >> caozuo[i].second;
//	for (int i = 0; i < m; i++) {
//		int x, y;
//		x = caozuo[i].first;
//		y = caozuo[i].second;
//		a[x] += 1;
//		a[y + 1] -= 1;
//	}
//	for (int i = 1; i <= n; i++) a[i] = a[i - 1] + a[i];
//	int ling = 0;
//	for (int i = 1; i <= n; i++) if (a[i] == 0) ling++;
//	for (int i = 0; i < m; i++) {
//		int ans = ling;
//		int x, y;
//		x = caozuo[i].first;
//		y = caozuo[i].second;
//		for (int j = x; j <= y; j++)
//			if (a[j] == 1) ans++;
//		cout << ans << endl;
//	}
//	return 0;
//}



// P8800 [蓝桥杯 2022 国 B] 卡牌
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//struct pai {
//	int a;
//	int b;
//};
//
//const int N = 2e5 + 10;
//int n, m;
//pai x[N];
//
//bool fuhe(int mid) {
//	int cnt = 0;
//	int m_ = m;
//	for (int i = 0; i < n; i++) {
//		if (x[i].a >= mid) cnt++;
//		else {
//			int cha = mid - x[i].a;
//			if (x[i].b >= cha && m_ >= cha) {
//				cnt++;
//				m_ -= cha;
//			}
//		}
//	}
//	if (cnt == n) return true;
//	return false;
//}
//
//signed main() {
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) cin >> x[i].a;
//	for (int i = 0; i < n; i++) cin >> x[i].b;
//	int l = 0, r = 1e18;
//	int ans = -1;
//	while (l <= r) {
//		int mid = (l + r) >> 1;
//		if (fuhe(mid)) {
//			ans = mid;
//			l = mid + 1;
//		} else {
//			r = mid - 1;
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}



// P10908 [蓝桥杯 2024 国 B] 选数概率
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
////	int x = 10455;
////	int x_ = x;
////	int bei = 2;
////	bool found = false;
////	int a = 1, b = 2;
////	while (!found) {
////		while (a * b <= x) {
////			if (a * b == x && (a * b) % 2091 == 0) {
////				found = true;
////				break;
////			}
////			a++;
////			b++;
////		}
////		if (found) break;
////		x = x_ * bei;
////		bei++;
////		a = 1, b = 2;
////	}
////	cout << a << ' ' << b << ' ' << a * b << endl;
//	cout << "55,94,56" << endl;
//	return 0;
//}



// P9422 [蓝桥杯 2023 国 B] 合并数列
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	vector<int> a(n), b(m);
//	for (int i = 0; i < n; i++) cin >> a[i];
//	for (int i = 0; i < m; i++) cin >> b[i];
//	int ans = 0;
//	int i = 0, j = 0;
//	int a_ = 0, b_ = 0;
//	while (i < n && j < m) {
//		a_ = a[i], b_ = b[j];
//		while (a_ != b_) {
//			if (a_ < b_) {
//				i++;
//				a_ += a[i];
//				ans++;
//			} else {
//				j++;
//				b_ += b[j];
//				ans++;
//			}
//		}
//		i++, j++;
//	}
//	cout << ans << endl;
//	return 0;
//}



// P8775 [蓝桥杯 2022 省 A] 青蛙过河
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	m <<= 1;
//	vector<int> a(n + 1);
//	for (int i = 1; i < n; i++) cin >> a[i];
//	int ans = 0;
//	int sum = 0;
//	for (int l = 1, r = 1; l < n; l++) {
//		while (r <= n && sum < m) {
//			sum += a[r++];
//		}
//		ans = max(ans, r - l);
//		sum -= a[l];
//	}
//	cout << ans << endl;
//	return 0;
//}


// P9241 [蓝桥杯 2023 省 B] 飞机降落
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 15;
//
//struct plane {
//	int t;
//	int d;
//	int l;
//};
//
//plane a[N];
//bool vis[N], is_true;
//int n;
//
//void dfs(int deep, int t) {
//	if (deep == n) {
//		is_true = true;
//	} else {
//		for (int i = 0; i < n; i++) {
//			if (!vis[i] && t <= a[i].t + a[i].d) {
//				vis[i] = 1;
//				if (t < a[i].t)
//					dfs(deep + 1, a[i].t + a[i].l);
//				else
//					dfs(deep + 1, t + a[i].l);
//				vis[i] = 0;
//			}
//		}
//	}
//}
//
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		for (int i = 0; i < n; i++) cin >> a[i].t >> a[i].d >> a[i].l;
//		dfs(0, 0);
//		if (is_true) cout << "YES" << endl;
//		else cout << "NO" << endl;
//		is_true = false;
//		memset(vis, 0, sizeof vis);
//	}
//	return 0;
//}



// P1678 烦恼的高考志愿
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//	int n, m;
//	cin >> n >> m;
//	vector<int> a(n), b(m);
//	for (int i = 0; i < n; i++) cin >> a[i];
//	for (int i = 0; i < m; i++) cin >> b[i];
//	sort(a.begin(), a.end());
//	int ans = 0;
//	for (int i = 0; i < m; i++) {
//		int x = b[i];
//		int idx = lower_bound(a.begin(), a.end(), x) - a.begin();
//		if (idx == 0) ans += abs(x - a[idx]);
//		else if (idx == n) ans += abs(x - a[n - 1]);
//		else ans += min(abs(x - a[idx]), abs(x - a[idx - 1]));
//	}
//	cout << ans << endl;
//	return 0;
//}



// P8218 【深进1.例1】求区间和
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int> a(n + 1);
//	for (int i = 1; i <= n; i++) cin >> a[i];
//	vector<int> sum(n + 1);
//	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
//	int t;
//	cin >> t;
//	while (t--) {
//		int l, r;
//		cin >> l >> r;
//		cout << sum[r] - sum[l - 1] << endl;
//	}
//	return 0;
//}



// P1593 因子和
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//unordered_map<int, int> mp;
//const int mod = 9901;
//
//int mi(int a, int b) {
//	int res = 1;
//	a %= mod;
//	while (b) {
//		if (b & 1) res = res * a % mod;
//		b >>= 1;
//		a = a * a % mod;
//	}
//	return res;
//}
//
//int he(int a, int b) {
//	if (b == 0) return 1;
//	if (b == 1) return 1 + a;
//	if (b & 1) {
//		return (1 + mi(a, (b + 1) / 2)) % mod * he(a, b / 2) % mod;
//	} else {
//		return (1 + a * (he(a, b - 1))) % mod;
//	}
//}
//
//signed main() {
//	int a, b;
//	cin >> a >> b;
//	for (int i = 2; a != 1; i++) {
//		while (a % i == 0) {
//			a /= i;
//			mp[i]++;
//		}
//	}
//	for (unordered_map<int, int>::iterator p = mp.begin(); p != mp.end(); p++) {
//		p->second = b * p->second;
//	}
//	int ans = 1;
//	for (unordered_map<int, int>::iterator p = mp.begin(); p != mp.end(); p++) {
//		ans = ans * he(p->first, p->second) % mod;
//	}
//	cout << ans << endl;
//	return 0;
//}



// P1835 素数密度
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//const int N = 50000;
//int primes[N], cnt;
//bool vis[N * 20 + 10];
//
//void euler() {
//	for (int i = 2; i < N; i++) {
//		if (!vis[i]) primes[cnt++] = i;
//		for (int j = 0; primes[j] * i < N; j++) {
//			vis[i * primes[j]] = 1;
//			if (i % primes[j] == 0) break;
//		}
//	}
//}
//
//signed main() {
//	euler();
//	memset(vis, 0, sizeof vis);
//	int l, r;
//	cin >> l >> r;
//	if (l == 1) l++;
//	for (int i = 0; i < cnt; i++) {
//		int p = primes[i];
//		int start = (l + p - 1) / p * p;
//		if (start == p) start = 2 * p;
//		for (int j = start; j <= r; j += p) vis[j - l] = 1;
//	}
//	int ans = 0;
//	for (int i = 0; i <= r - l; i++)
//		if (!vis[i]) ans++;
//	cout << ans << endl;
//	return 0;
//}



// P1403 [AHOI2005] 约数研究
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		ans += n / i;
//	}
//	cout << ans << endl;
//	return 0;
//}



// P2660 zzc 种田
//#include <bits/stdc++.h>
//using namespace std;
//
//long long ans(long long x, long long y) {
//	if (x == 0 || y == 0) return 0;
//	if (x == y) return 4 * x;
//	if (x > y) return ans(y, x);
//	long long res = 0;
//	long long ge = y / x;
//	res += ge * 4 * x;
//	res += ans(y % x, x);
//	return res;
//}
//
//int main() {
//	long long x, y;
//	cin >> x >> y;
//	cout << ans(x, y) << endl;
//	return 0;
//}



// P3811 【模板】模意义下的乘法逆元
//#include <cstdio>
//using namespace std;
//#define int long long
//
//const int N = 3e6 + 5;
//int inv[N];
//
//signed main() {
//	inv[1] = 1;
//	int n, p;
//	scanf("%lld%lld", &n, &p);
//	printf("1\n");
//	for (int i = 2; i <= n; i++) {
//		inv[i] = ((-(p / i) * inv[p % i]) % p + p) % p;
//		printf("%lld\n", inv[i]);
//	}
//	return 0;
//}



// P1115 最大子段和
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int> a(n + 1);
//	for (int i = 1; i <= n; i++) cin >> a[i];
//	vector<int> dp(n + 1);
//	dp[1] = a[1];
//	int ans = a[1];
//	for (int i = 2; i <= n; i++) {
//		dp[i] = max(dp[i - 1] + a[i], a[i]);
//		ans = max(ans, dp[i]);
//	}
//	cout << ans << endl;
//	return 0;
//}



// P1216 [IOI 1994] 数字三角形 Number Triangles
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<vector<int>> a(n + 1, vector<int>(n + 1));
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= i; j++)
//			cin >> a[i][j];
//	vector<vector<int>> dp(n + 1, vector<int>(n + 1));
//	dp[1][1] = a[1][1];
//	int ans = a[1][1];
//	for (int i = 2; i <= n; i++) {
//		for (int j = 1; j <= i; j++) {
//			dp[i][j] = max(a[i][j] + dp[i - 1][j], a[i][j] + dp[i - 1][j - 1]);
//			ans = max(ans, dp[i][j]);
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}



// P3378 【模板】堆
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int t;
//	cin >> t;
//	priority_queue<int, vector<int>, greater<int>> q;
//	while (t--) {
//		int op;
//		cin >> op;
//		if (op == 1) {
//			int x;
//			cin >> x;
//			q.push(x);
//		} else if (op == 2) {
//			cout << q.top() << endl;
//		} else {
//			q.pop();
//		}
//	}
//	return 0;
//}



// P1996 约瑟夫问题
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	vector<int> a(n + 1);
//	for (int i = 1; i <= n; i++) a[i] = i;
//	int idx = m;
//	int si = n;
//	while (si) {
//		cout << a[idx] << ' ';
//		si--;
//		if (si == 0) break;
//		a.erase(a.begin() + idx);
//		idx = (idx + m - 1) % si;
//		if (idx == 0) idx = si;
//	}
//	return 0;
//}



// P1631 序列合并
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int> a(n), b(n);
//	for (int i = 0; i < n; i++) cin >> a[i];
//	for (int i = 0; i < n; i++) cin >> b[i];
//	vector<int> ans;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; (j + 1) * (i + 1) <= n; j++) {
//			ans.push_back(a[i] + b[j]);
//		}
//	}
//	sort(ans.begin(), ans.end());
//	for (int i = 0; i < n; i++) cout << ans[i] << ' ';
//	return 0;
//}



// P1801 黑匣子
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 200010;
//int tr[N];
//
//void add(int x, int c) {
//	for (int i = x; i < N; i += i & -i)
//		tr[i] += c;
//}
//
//int sum(int x) {
//	int res = 0;
//	for (int i = x; i > 0; i -= i & -i)
//		res += tr[i];
//	return res;
//}
//
//int get_num(int k) {
//	int l = 1, r = N - 10;
//	while (l <= r) {
//		int mid = (l + r) >> 1;
//		if (sum(mid) >= k) r = mid - 1;
//		else l = mid + 1;
//	}
//	return r;
//}
//
//int main() {
//	int m, n;
//	cin >> m >> n;
//	vector<int> a(m);
//	for (int i = 0; i < m; i++) cin >> a[i];
//	vector<int> b(a.begin(), a.end());
//	sort(b.begin(), b.end());
//	b.erase(unique(b.begin(), b.end()), b.end());
//	vector<int> c(n);
//	for (int i = 0; i < n; i++) cin >> c[i];
//	int cnt = 0;
//	for (int i = 0; i < n; i++) {
//		int x = c[i];
//		for (; cnt < x; cnt++) {
//			int weizhi = lower_bound(b.begin(), b.end(), a[cnt]) - b.begin() + 1;
//			add(weizhi, 1);
//		}
//		cout << b[get_num(i + 1)] << endl;
//	}
//	return 0;
//}



// P1135 奇怪的电梯
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n, a, b;
//	cin >> n >> a >> b;
//	vector<int> lou(n + 1);
//	for (int i = 1; i <= n; i++) cin >> lou[i];
//	vector<bool> vis(n + 1);
//	queue<pair<int, int>> q;
//	int ans = -1;
//	q.push({a, 0});
//	vis[a] = 1;
//	while (!q.empty()) {
//		pair<int, int> cen = q.front();
//		q.pop();
//		if (cen.first == b) {
//			ans = cen.second;
//			break;
//		}
//		if (cen.first + lou[cen.first] >= 1 && cen.first + lou[cen.first] <= n) {
//			if (!vis[cen.first + lou[cen.first]]) {
//				vis[cen.first + lou[cen.first]] = 1;
//				q.push({cen.first + lou[cen.first], cen.second + 1});
//			}
//		}
//		if (cen.first - lou[cen.first] >= 1 && cen.first - lou[cen.first] <= n) {
//			if (!vis[cen.first - lou[cen.first]]) {
//				vis[cen.first - lou[cen.first]] = 1;
//				q.push({cen.first - lou[cen.first], cen.second + 1});
//			}
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}



// P1126 机器人搬重物
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 55;
//vector<vector<int>> a(N, vector<int>(N));
//int n, m;
//
//struct pos {
//	int x;
//	int y;
//	int t;
//	char f;
//};
//
//string status(pos p) {
//	return to_string(p.x) + '+' + to_string(p.y) + '+' + p.f;
//}
//
//bool he(int x, int y) {
//	if (x >= n || y >= m) return false;
//	if (x <= 0 || y <= 0) return false;
//	int sum = a[x][y] + a[x][y + 1] + a[x + 1][y] + a[x + 1][y + 1];
//	if (sum == 0) return true;
//	return false;
//}
//
//int main() {
//	cin >> n >> m;
//	unordered_map<string, bool> vis;
//	unordered_map<char, array<int, 2>> fang = {
//		{'E', {0, 1}},
//		{'N', {-1, 0}},
//		{'S', {1, 0}},
//		{'W', {0, -1}}
//	};
//	unordered_map<char, char> nextl = {
//		{'E', 'N'},
//		{'N', 'W'},
//		{'S', 'E'},
//		{'W', 'S'}
//	};
//	unordered_map<char, char> nextr = {
//		{'E', 'S'},
//		{'N', 'E'},
//		{'S', 'W'},
//		{'W', 'N'}
//	};
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= m; j++)
//			cin >> a[i][j];
//	queue<pos> q;
//	int x1, y1, x2, y2;
//	char f;
//	cin >> x1 >> y1 >> x2 >> y2 >> f;
//	q.push({x1, y1, 0, f});
//	vis[status(q.front())] = 1;
//	int ans = -1;
//	while (!q.empty()) {
//		pos p = q.front();
//		q.pop();
//		if (p.x == x2 && p.y == y2) {
//			ans = p.t;
//			break;
//		}
//		pos ne = {p.x, p.y, p.t + 1, nextl[p.f]};
//		if (!vis[status(ne)] && he(ne.x, ne.y)) {
//			vis[status(ne)] = 1;
//			q.push(ne);
//		}
//		ne = {p.x, p.y, p.t + 1, nextr[p.f]};
//		if (!vis[status(ne)] && he(ne.x, ne.y)) {
//			vis[status(ne)] = 1;
//			q.push(ne);
//		}
//		for (int i = 1; i <= 3; i++) {
//			array<int, 2> fv = fang[p.f];
//			ne = {p.x + fv[0] * i, p.y + fv[1] * i, p.t + 1, p.f};
//			bool is_he = true;
//			for (int j = 1; j <= i; j++) {
//				int x_ = p.x + fv[0] * j;
//				int y_ = p.y + fv[1] * j;
//				is_he = (is_he && he(x_, y_));
//			}
//			if (!vis[status(ne)] && is_he) {
//				vis[status(ne)] = 1;
//				q.push(ne);
//			}
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}



// P8784 [蓝桥杯 2022 省 B] 积木画
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//const int mod = 1e9 + 7, N = 1e7 + 2;
//int f[N];
//
//signed main() {
//	f[0] = 1;
//	f[1] = 1;
//	f[2] = 2;
//	int n;
//	cin >> n;
//	int sum = 1;
//	for (int i = 3; i <= n; i++) {
//		f[i] = (f[i - 1] + f[i - 2] + 2 * sum) % mod;
//		sum = (sum + f[i - 2]) % mod;
//	}
//	cout << f[n];
//	return 0;
//}



// P1433 吃奶酪
// 90分，超时，该方法无法再优化了
// 不！只是我太菜不会优化罢了
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 27;
//vector<pair<double, double>> a(N);
//int n, vis[N];
//double ans = (double)INT32_MAX;
//
//double d(pair<double, double> a, pair<double, double> b) {
//	double x = a.first - b.first;
//	double y = a.second - b.second;
//	return sqrt(x * x + y * y);
//}
//
//void dfs(int deep, double sum, pair<double, double> pos) {
//	if (deep == n) {
//		ans = min(ans, sum);
//	} else {
//		if (sum >= ans) return;
//		for (int i = 1; i <= n; i++) {
//			if (!vis[i]) {
//				vis[i] = 1;
//				dfs(deep + 1, sum + d(pos, a[i]), a[i]);
//				vis[i] = 0;
//			}
//		}
//	}
//}
//
//int main() {
//	cin >> n;
//	for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
//	dfs(0, 0, {0, 0});
//	printf("%.2lf", ans);
//	return 0;
//}
// 大佬的dfs解法，也有状压dp思想
//#include <bits/stdc++.h>
//using namespace std;
//
//int n;
//long double a[30][2], lt[30][30], zt[(1 << 15) + 15][18]; //记录状态，第一维记录走过的点，第二维记录所在的点
//long double cc1, cc2, answ;
//int bj[30], i, j;
//
//void dfs(int y, int ww, int x, long double ans) { //深搜
//	if (x == n + 1) if (answ == 0 || answ > ans) {
//			answ = ans;
//			return;
//		}
//	for (int g = 1; g <= n; g++) {
//		if (!bj[g]) {
//			int xb = ww + (1 << (g - 1)); //xb表示当前已走过的点，有标记数组挡着不用怕二进制数会进位
//			if (zt[xb][g] != 0)
//				if (zt[xb][g] <= ans + lt[y][g]) continue; //如果生成的路径长度比之前的还要长就不对该点继续dfs
//			bj[g] = 1; //标记
//			zt[xb][g] = ans + lt[y][g]; //记录状态
//			dfs(g, xb, x + 1, zt[xb][g]); //继续往下搜
//			bj[g] = 0; //回溯
//		}
//	}
//	return;
//}
//
//int main() {
//	cin >> n;
//	a[0][0] = 0;
//	a[0][1] = 0;
//	for (i = 1; i <= n; i++) {
//		scanf("%Lf %Lf", &a[i][0], &a[i][1]);
//		for (j = 0; j < i; j++) { //对两点距离初始化
//			cc1 = a[i][0] - a[j][0];
//			cc2 = a[i][1] - a[j][1];
//			lt[j][i] = sqrt(cc1*cc1 + cc2*cc2); //记录两点距离
//			lt[i][j] = lt[j][i];
//		}
//	}
//	dfs(0, 0, 1, 0);
//	printf("%.2Lf", answ);
//	return 0;
//}
// 自己实现一遍
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 18;
//int n;
//double ans = (double)INT32_MAX;
//vector<pair<double, double>> a(N);
//double status[(1 << 15) + 10][N];
//bool vis[N];
//double juli[N][N];
//
//double d(pair<double, double> a, pair<double, double> b) {
//	double x = a.first - b.first;
//	double y = a.second - b.second;
//	return sqrt(x * x + y * y);
//}
//
//void dfs(int deep, int statu, int pos, double sum) {
//	if (deep == n) {
//		ans = min(ans, sum);
//	} else {
//		if (sum >= ans) return;
//		for (int i = 1; i <= n; i++) {
//			if (!vis[i]) {
//				int statu_ = (statu | (1 << (i - 1)));
//				if (status[statu_][i] != 0 && status[statu_][i] <= sum + d(a[pos], a[i])) continue;
//				status[statu_][i] = sum + juli[pos][i];
//				vis[i] = 1;
//				dfs(deep + 1, statu_, i, sum + juli[pos][i]);
//				vis[i] = 0;
//			}
//		}
//	}
//}
//
//int main() {
//	cin >> n;
//	a[0] = {0, 0};
//	for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
//	for (int i = 0; i <= n; i++) {
//		for (int j = i + 1; j <= n; j++) {
//			juli[i][j] = d(a[i], a[j]);
//			juli[j][i] = juli[i][j];
//		}
//	}
//	dfs(0, 0, 0, 0);
//	printf("%.2lf", ans);
//	return 0;
//}



// CF743C Vladik and fractions
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	if (n == 1) cout << -1 << endl;
//	else cout << n << ' ' << n + 1 << ' ' << (n + 1) * n;
//	return 0;
//}



// P1551 亲戚
//#include <bits/stdc++.h>
//using namespace std;
//
//vector<int> a(5010);
//
//int find(int x) {
//	if (a[x] != x) a[x] = find(a[x]);
//	return a[x];
//}
//
//int main() {
//	int n, m, p;
//	cin >> n >> m >> p;
//
//	for (int i = 1; i <= n; i++) a[i] = i;
//	while (m--) {
//		int x, y;
//		cin >> x >> y;
//		a[find(x)] = find(y);
//	}
//	while (p--) {
//		int x, y;
//		cin >> x >> y;
//		if (find(x) == find(y)) cout << "Yes" << endl;
//		else cout << "No" << endl;
//	}
//	return 0;
//}



// P1134 [USACO3.2] 阶乘问题
//#include <bits/stdc++.h>
//using namespace std;
//
//int two;
//
//int qiu(int k) {
//	while (k % 2 == 0) {
//		k /= 2;
//		two++;
//	}
//	while (k % 5 == 0) {
//		k /= 5;
//		two--;
//	}
//	return k;
//}
//
//int main() {
//	int n;
//	cin >> n;
//	int ans = 1;
//	for (int i = 2; i <= n; i++) ans = (ans * qiu(i)) % 10;
//	for (int i = 1; i <= two; i++) ans = ans * 2 % 10;
//	cout << ans << endl;
//	return 0;
//}



// P1226 【模板】快速幂
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//int qmi(int a, int b, int p) {
//	int res = 1;
//	a %= p;
//	while (b) {
//		if (b & 1) res = res * a % p;
//		b >>= 1;
//		a = a * a % p;
//	}
//	return res;
//}
//
//signed main() {
//	int a, b, p;
//	cin >> a >> b >> p;
//	printf("%lld^%lld mod %lld=%lld", a, b, p, qmi(a, b, p));
//	return 0;
//}



// P1292 倒酒
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//int exgcd(int a, int b, int& x, int& y) {
//	if (a == 0) {
//		x = 0, y = 1;
//		return b;
//	} else {
//		int d = exgcd(b % a, a, x, y);
//		swap(x, y);
//		x -= b / a * y;
//		return d;
//	}
//}
//
//signed main() {
//	int a, b;
//	cin >> a >> b;
//	int x, y;
//	int ans = exgcd(a, b, x, y);
//	cout << ans << endl;
//	int k = b / ans;
//	x = (x % k + k) % k;
//	if (x != 0) x -= k;
//	y = (ans - a * x) / b;
//	x = -x;
//	cout << x << ' ' << y;
//	return 0;
//}



// P1227 [JSOI2008] 完美的对称
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 20010;
//vector<pair<double, double>> a(N);
//
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
//	double sumx = 0, sumy = 0;
//	for (int i = 0; i < n; i++) {
//		sumx += a[i].first;
//		sumy += a[i].second;
//	}
//	unordered_map<string, int> mp;
//	for (int i = 0; i < n; i++) {
//		string s = to_string((int)a[i].first) + '+' + to_string((int)a[i].second);
//		mp[s]++;
//	}
//	sumx /= n;
//	sumy /= n;
//	bool he = true;
//	for (int i = 0; i < n; i++) {
//		int x2 = 2 * sumx - a[i].first;
//		int y2 = 2 * sumy - a[i].second;
//		string s = to_string(x2) + '+' + to_string(y2);
//		if (mp[s] == 0) {
//			he = false;
//			break;
//		}
//	}
//	if (he) {
//		printf("V.I.P. should stay at (%.1lf,%.1lf).", sumx, sumy);
//	} else {
//		cout << "This is a dangerous situation!" << endl;
//	}
//	return 0;
//}



// P1100 高低位交换
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	unsigned int n;
//	cin >> n;
//	unsigned int a = 0, b = 0;
//	for (int i = 31; i >= 16; i--) {
//		a = (a << 1) + ((n >> i) & 1);
//	}
//	for (int i = 15; i >= 0; i--) {
//		b = (b << 1) + ((n >> i) & 1);
//	}
//	cout << ((b << 16) + a) << endl;
//	return 0;
//}



// P12133 [蓝桥杯 2025 省 B] 产值调整
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int a, b, c, k;
//		cin >> a >> b >> c >> k;
//		int ap, bp, cp;
//		while (k--) {
//			ap = (b + c) / 2;
//			bp = (a + c) / 2;
//			cp = (a + b) / 2;
//			a = ap;
//			b = bp;
//			c = cp;
//			if (a == b && b == c) break;
//		}
//		cout << a << ' ' << b << ' ' << c << endl;
//	}
//	return 0;
//}


// P12134 [蓝桥杯 2025 省 B] 画展布置
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//	int n, m;
//	cin >> n >> m;
//	vector<int> a(n + 1);
//	for (int i = 1; i <= n; i++) cin >> a[i];
//	sort(a.begin(), a.end());
//	vector<int> sum(n);
//	for (int i = 1; i < n; i++) {
//		sum[i] = abs(a[i] * a[i] - a[i + 1] * a[i + 1]);
//	}
//	for (int i = 1; i < n; i++) sum[i] += sum[i - 1];
//	int ans = 1e18;
//	for (int i = m - 1; i < n; i++) {
//		ans = min(ans, sum[i] - sum[i - m + 1]);
//	}
//	cout << ans << endl;
//	return 0;
//}



// P12135 [蓝桥杯 2025 省 B] 水质检测
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//	string s1, s2;
//	cin >> s1 >> s2;
//	int n = s1.size();
//	string qian = "..";
//	int yi = 0;
//	while (yi < n && qian == "..") {
//		qian[0] = s1[yi];
//		qian[1] = s2[yi];
//		yi++;
//	}
//	yi--;
//	int ans = 0;
//	string hou = "..";
//	for (int i = yi + 1; i < n; i++) {
//		hou[0] = s1[i];
//		hou[1] = s2[i];
//		if (hou == "..") continue;
//		if (hou == "##") {
//			ans += i - yi - 1;
//			qian = hou;
//			yi = i;
//		} else if (hou == ".#") {
//			if (qian == "##") {
//				ans += i - yi - 1;
//				qian = hou;
//				yi = i;
//			} else if (qian == ".#") {
//				ans += i - yi - 1;
//				qian = hou;
//				yi = i;
//			} else if (qian == "#.") {
//				ans += i - yi;
//				qian = "##";
//				yi = i;
//			}
//		} else if (hou == "#.") {
//			if (qian == "##") {
//				ans += i - yi - 1;
//				qian = hou;
//				yi = i;
//			} else if (qian == ".#") {
//				ans += i - yi;
//				qian = "##";
//				yi = i;
//			} else if (qian == "#.") {
//				ans += i - yi - 1;
//				qian = hou;
//				yi = i;
//			}
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}



// P12132 [蓝桥杯 2025 省 B] 可分解的正整数
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++) cin >> a[i];
//	int ans = 0;
//	for (int i = 0; i < n; i++) {
//		if (a[i] != 1) ans++;
//	}
//	cout << ans;
//	return 0;
//}



// P12136 [蓝桥杯 2025 省 B] 生产车间
// 错了呜呜呜，亏我写了那么久，唉
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 1010;
//int w[N], n, ans;
//vector<vector<int>> a(N, vector<int>());
//vector<set<int>> b(N);
//
//void dfs(int u, int fa) {
//	if (a[u].size() == 0) {
//		vector<int> temp;
//		for (auto p : b[fa]) {
//			if (p + w[u] <= w[fa]) temp.push_back(p + w[u]);
//		}
//		for (int i : temp) b[fa].insert(i);
//	} else {
//		for (int i : a[u]) {
//			dfs(i, u);
//		}
//		if (u != 1) {
//			vector<int> temp;
//			for (auto i : b[fa]) {
//				for (auto j : b[u]) {
//					if (i + j <= w[fa]) temp.push_back(i + j);
//					else break;
//				}
//			}
//
//			for (int i : temp) b[fa].insert(i);
//		}
//	}
//}
//
//signed main() {
//	cin >> n;
//	for (int i = 1; i <= n; i++) cin >> w[i];
//	for (int i = 1; i < n; i++) {
//		int u, v;
//		cin >> u >> v;
//		a[u].push_back(v);
//	}
//	for (int i = 1; i <= n; i++) b[i].insert(0);
//	dfs(1, 1);
//	for (auto i : b[1]) ans = max(ans, i);
//
//	cout << ans << endl;
//	return 0;
//}

// 牛逼过了，AI辅助！！！建树建错了，我真的服了，唉！！！
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 1010;
//int w[N], n;
//vector<vector<int>> a(N, vector<int>());
//vector<set<int>> b(N);
//
//void dfs(int u, int fa) {
//	if (a[u].size() == 1 && a[u][0] == fa) {
//		vector<int> temp;
//		for (auto p : b[fa]) {
//			if (p + w[u] <= w[fa]) temp.push_back(p + w[u]);
//		}
//		for (int i : temp) b[fa].insert(i);
//	} else {
//		for (int i : a[u]) {
//			if (i != fa)
//				dfs(i, u);
//		}
//		if (u != 1) {
//			vector<int> temp;
//			for (auto i : b[fa]) {
//				for (auto j : b[u]) {
//					if (i + j <= w[fa]) temp.push_back(i + j);
//					else break;
//				}
//			}
//
//			for (int i : temp) b[fa].insert(i);
//		}
//	}
//}
//
//signed main() {
//	cin >> n;
//	for (int i = 1; i <= n; i++) cin >> w[i];
//	for (int i = 1; i < n; i++) {
//		int u, v;
//		cin >> u >> v;
//		a[u].push_back(v);
//		a[v].push_back(u);
//	}
//	for (int i = 1; i <= n; i++) b[i].insert(0);
//	dfs(1, 1);
//
//	cout << *b[1].rbegin() << endl;
//	return 0;
//}



// P12131 [蓝桥杯 2025 省 B] 客流量上限
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//const int mod = 1e9 + 7;
//
//signed main() {
//	int ans = 1;
//	for (int i = 1; i <= 1012; i++) {
//		ans *= 2;
//		ans %= mod;
//	}
//	cout << ans << endl;
//	return 0;
//}




// P3372 【模板】线段树 1
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//const int N = 100010;
//struct Node {
//	int l, r;
//	int sum, add;
//} tr[4 * N];
//
//int n, m, w[N];
//
//void pushup(int u) {
//	tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
//}
//
//void pushdown(int u) {
//	Node& root = tr[u], & left = tr[u << 1], & right = tr[u << 1 | 1];
//	if (root.add) {
//		left.add += root.add;
//		left.sum += (left.r - left.l + 1) * root.add;
//		right.add += root.add;
//		right.sum += (right.r - right.l + 1) * root.add;
//		root.add = 0;
//	}
//}
//
//void build(int u, int l, int r) {
//	if (l == r) tr[u] = {l, r, w[l], 0};
//	else {
//		int mid = (l + r) >> 1;
//		tr[u] = {l, r};
//		build(u << 1, l, mid);
//		build(u << 1 | 1, mid + 1, r);
//		pushup(u);
//	}
//}
//
//int query(int u, int l, int r) {
//	if (l <= tr[u].l && tr[u].r <= r) return tr[u].sum;
//	else {
//		pushdown(u);
//		int mid = (tr[u].l + tr[u].r) >> 1;
//		int res = 0;
//		if (l <= mid) res += query(u << 1, l, r);
//		if (mid < r) res += query(u << 1 | 1, l, r);
//		return res;
//	}
//}
//
//void modify(int u, int l, int r, int v) {
//	if (l <= tr[u].l && tr[u].r <= r) {
//		tr[u].add += v;
//		tr[u].sum += (tr[u].r - tr[u].l + 1) * v;
//	} else {
//		pushdown(u);
//		int mid = (tr[u].r + tr[u].l) >> 1;
//		if (l <= mid) modify(u << 1, l, r, v);
//		if (mid < r) modify(u << 1 | 1, l, r, v);
//		pushup(u);
//	}
//}
//
//signed main() {
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) cin >> w[i];
//	build(1, 1, n);
//	int o, x, y, k;
//	while (m--) {
//		cin >> o >> x >> y;
//		if (o == 1) {
//			cin >> k;
//			modify(1, x, y, k);
//		} else {
//			cout << query(1, x, y) << endl;
//		}
//	}
//	return 0;
//}



// P3870 [TJOI2009] 开关
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 100010;
//int n, m;
//
//struct Node {
//	int l, r;
//	int sum, add;
//} tr[4 * N];
//
//void pushup(int u) {
//	tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
//}
//
//void pushdown(int u) {
//	Node& root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
//	if (root.add) {
//		left.add = (left.add + root.add) % 2;
//		left.sum = (left.r - left.l + 1) - left.sum;
//		right.add = (right.add + root.add) % 2;
//		right.sum = (right.r - right.l + 1) - right.sum;
//		root.add = 0;
//	}
//}
//
//void build(int u, int l, int r) {
//	if (l == r) tr[u] = {l, r, 0, 0};
//	else {
//		tr[u] = {l, r};
//		int mid = (l + r) >> 1;
//		build(u << 1, l, mid);
//		build(u << 1 | 1, mid + 1, r);
//		pushup(u);
//	}
//}
//
//int query(int u, int l, int r) {
//	if (l <= tr[u].l && tr[u].r <= r) return tr[u].sum;
//	pushdown(u);
//	int mid = (tr[u].l + tr[u].r) >> 1;
//	int res = 0;
//	if (l <= mid) res += query(u << 1, l, r);
//	if (mid < r) res += query(u << 1 | 1, l, r);
//	return res;
//}
//
//void modify(int u, int l, int r) {
//	if (l <= tr[u].l && tr[u].r <= r) {
//		tr[u].add = (tr[u].add + 1) % 2;
//		tr[u].sum = (tr[u].r - tr[u].l + 1) - tr[u].sum;
//	} else {
//		pushdown(u);
//		int mid = (tr[u].l + tr[u].r) >> 1;
//		if (l <= mid) modify(u << 1, l, r);
//		if (mid < r) modify(u << 1 | 1, l, r);
//		pushup(u);
//	}
//}
//
//int main() {
//	cin >> n >> m;
//	build(1, 1, n);
//	int c, a, b;
//	while (m--) {
//		cin >> c >> a >> b;
//		if (c == 0) {
//			modify(1, a, b);
//		} else {
//			cout << query(1, a, b) << endl;
//		}
//	}
//	return 0;
//}



// P1816 忠诚
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 100010;
//int n, m, w[N];
//
//struct Node {
//	int l, r;
//	int sum;
//} tr[4 * N];
//
//void pushup(int u) {
//	tr[u].sum = min(tr[u << 1].sum, tr[u << 1 | 1].sum);
//}
//
//void build(int u, int l, int r) {
//	if (l == r) tr[u] = {l, r, w[l]};
//	else {
//		tr[u] = {l, r};
//		int mid = (l + r) >> 1;
//		build(u << 1, l, mid);
//		build(u << 1 | 1, mid + 1, r);
//		pushup(u);
//	}
//}
//
//int query(int u, int l, int r) {
//	if (l <= tr[u].l && tr[u].r <= r) return tr[u].sum;
//	int res = 1e9;
//	int mid = (tr[u].l + tr[u].r) >> 1;
//	if (l <= mid) res = min(res, query(u << 1, l, r));
//	if (mid < r) res = min(res, query(u << 1 | 1, l, r));
//	return res;
//}
//
//int main() {
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) cin >> w[i];
//	build(1, 1, n);
//	int l, r;
//	while (m--) {
//		cin >> l >> r;
//		cout << query(1, l, r) << " ";
//	}
//	return 0;
//}



// P2568 GCD
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//const int N = 1e7 + 10;
//int primes[N], phi[N], n, cnt, sum[N];
//bool vis[N];
//
//void init() {
//	phi[1] = 1;
//	for (int i = 2; i <= n; i++) {
//		if (!vis[i]) {
//			primes[cnt++] = i;
//			phi[i] = i - 1;
//		}
//		for (int j = 0; i * primes[j] <= n; j++) {
//			vis[i * primes[j]] = 1;
//			if (i % primes[j] == 0) {
//				phi[i * primes[j]] = phi[i] * primes[j];
//				break;
//			} else {
//				phi[i * primes[j]] = phi[primes[j]] * phi[i];
//			}
//		}
//	}
//}
//
//signed main() {
//	cin >> n;
//	init();
//	int ans = 0;
//	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + phi[i];
//	for (int i = 0; i < cnt && primes[i] <= n; i++) {
//		ans += sum[n / primes[i]] * 2 - 1;
//	}
//	cout << ans << endl;
//	return 0;
//}



// B3614 【模板】栈
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	std::cin.tie(0);
//	std::ios::sync_with_stdio(false);
//	int t;
//	cin >> t;
//	while (t--) {
//		int m;
//		stack<unsigned long long> a;
//		cin >> m;
//		while (m--) {
//			string op;
//			cin >> op;
//			if (op == "push") {
//				unsigned long long x;
//				cin >> x;
//				a.push(x);
//			} else if (op == "query") {
//				if (a.empty()) cout << "Anguei!" << endl;
//				else cout << a.top() << endl;
//			} else if (op == "pop") {
//				if (a.empty()) cout << "Empty" << endl;
//				else a.pop();
//			} else {
//				cout << a.size() << endl;
//			}
//		}
//	}
//	return 0;
//}



// P5367 【模板】康托展开
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//const int N = 1e6 + 10, mod = 998244353;
//int tr[N], fact[N], a[N], A[N];
//
//void init() {
//	fact[0] = fact[1] = 1;
//	for (int i = 2; i < N; i++) {
//		fact[i] = i * fact[i - 1] % mod;
//	}
//}
//
//void add(int x) {
//	for (int i = x; i < N; i += i & -i)
//		tr[i] += 1;
//}
//
//int sum(int x) {
//	int res = 0;
//	for (int i = x; i; i -= i & -i)
//		res += tr[i];
//	return res;
//}
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	init();
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++) cin >> a[i];
//	for (int i = n; i >= 1; i--) {
//		A[i] = sum(a[i]);
//		add(a[i]);
//	}
//	int ans = 1;
//	for (int i = 1; i <= n; i++) {
//		ans += A[i] * fact[n - i] % mod;
//		ans %= mod;
//	}
//	cout << ans << endl;
//	return 0;
//}



// P10446 64位整数乘法
//#include <bits/stdc++.h>
//using namespace std;
//
//void write(__int128 x) {
//	if (x > 9) write(x / 10);
//	putchar(x % 10 + '0');
//}
//
//int main() {
//	long long a, b, p;
//	cin >> a >> b >> p;
//	write((__int128)a * b % p);
//	return 0;
//}




// P10447 最短 Hamilton 路径
// 超时了，n <= 15 应该能用此方法，n <= 20 的话乖乖状压dp吧。
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 25;
//int a[N][N], n, ans = 1e8;
//int mp[(1 << 20) + 10][N];
//
//void dfs(int u, int s, int sum) {
//	if (u == n - 1 && s == (1 << n) - 1) {
//		ans = min(ans, sum);
//	} else {
//		if (sum >= ans || ((s >> (n - 1)) & 1) == 1) return;
//		for (int i = 1; i < n; i++) {
//			if (((s >> i) & 1) == 0) {
//				int status = s | (1 << i);
//				if (mp[status][i] != 0 && mp[status][i] <= sum + a[u][i]) {
//					continue;
//				} else {
//					mp[status][i] = sum + a[u][i];
//					dfs(i, status, sum + a[u][i]);
//				}
//			}
//		}
//	}
//}
//
//signed main() {
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			cin >> a[i][j];
//	dfs(0, 1, 0);
//	cout << ans << endl;
//	return 0;
//}



// P1044 [NOIP 2003 普及组] 栈
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//
//signed main() {
//	int n;
//	cin >> n;
//	vector<int> a(n + 1);
//	a[0] = 1, a[1] = 1;
//	for (int i = 2; i <= n; i++) {
//		for (int j = 0; j <= i - 1; j++) {
//			a[i] += a[j] * a[i - 1 - j];
//		}
//	}
//	cout << a[n];
//	return 0;
//}



// P10495 阶乘分解
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 1e6 + 2;
//int primes[N], cnt;
//bool vis[N];
//
//void euler() {
//	for (int i = 2; i < N; i++) {
//		if (!vis[i]) primes[cnt++] = i;
//		for (int j = 0; primes[j] * i < N; j++) {
//			vis[i * primes[j]] = 1;
//			if (i % primes[j] == 0)
//				break;
//		}
//	}
//}
//
//int main() {
//	int n;
//	cin >> n;
//	euler();
//	for (int i = 0; i < cnt && primes[i] <= n; i++) {
//		int cnt = 0;
//		for (int j = 1; pow(primes[i], j) <= n; j++)
//			cnt += n / (int)pow(primes[i], j);
//		cout << primes[i] << ' ' << cnt << endl;
//	}
//	return 0;
//}



// P1379 八数码难题
//#include <bits/stdc++.h>
//using namespace std;
//
//string target = "123804765";
//int dx[] = {0, 0, 1, -1};
//int dy[] = {1, -1, 0, 0};
//
//struct mes {
//	string s;
//	int x;
//	int y;
//	int step;
//};
//
//int main() {
//	char x;
//	string s;
//	int j = 0;
//	for (int i = 0; i < 9; i++) {
//		cin >> x;
//		if (x == '0') j = i;
//		s += x;
//	}
//	unordered_map<string, bool> vis;
//	vis[s] = 1;
//	queue<mes> q;
//	q.push({s, j / 3, j % 3, 0});
//	int ans = -1;
//	bool have_ans = false;
//	if (s == target) {
//		ans = 0;
//		have_ans = true;
//	}
//	while (!q.empty() && !have_ans) {
//		mes m = q.front();
//		q.pop();
//		for (int i = 0; i < 4; i++) {
//			int x = m.x + dx[i];
//			int y = m.y + dy[i];
//			if (x >= 0 && x <= 2 && y >= 0 && y <= 2) {
//				string s1 = m.s;
//				swap(s1[3 * x + y], s1[3 * m.x + m.y]);
//				if (!vis[s1]) {
//					vis[s1] = 1;
//					if (s1 == target) {
//						ans = m.step + 1;
//						have_ans = true;
//						break;
//					}
//					q.push({s1, x, y, m.step + 1});
//				}
//			}
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}



// P2415 集合求和
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//	int sum = 0;
//	int cnt = 0;
//	int x;
//	while (cin >> x) {
//		cnt++;
//		sum += x;
//	}
//	cout << (1 << (cnt - 1)) * sum;
//	return 0;
//}




// P1228 地毯填补问题
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//void solve(int k, int x, int y, int dx, int dy) {
//	if (k >= 1) {
//		int hang = (x >> (k - 1)) & 1;
//		int lie = (y >> (k - 1)) & 1;
//		if (hang == 0 && lie == 0) {
//			int tx = (1 << (k - 1)), ty = (1 << (k - 1));
//			cout << tx + dx + 1 << " " << ty + dy + 1 << " " << 1 << endl;
//			solve(k - 1, x, y, dx, dy);
//			solve(k - 1, tx - 1, 0, dx, dy + ty);
//			solve(k - 1, 0, ty - 1, dx + tx, dy);
//			solve(k - 1, 0, 0, dx + ty, dy + tx);
//		} else if (hang == 0 && lie == 1) {
//			int tx = (1 << (k - 1)), ty = (1 << (k - 1)) - 1;
//			cout << tx + dx + 1 << " " << ty + dy + 1 << " " << 2 << endl;
//			solve(k - 1, tx - 1, ty, dx, dy);
//			solve(k - 1, x, y - ty - 1, dx, dy + ty + 1);
//			solve(k - 1, 0, ty, dx + tx, dy);
//			solve(k - 1, 0, 0, dx + tx, dy + ty + 1);
//		} else if (hang == 1 && lie == 0) {
//			int tx = (1 << (k - 1)) - 1, ty = (1 << (k - 1));
//			cout << tx + dx + 1 << " " << ty + dy + 1 << " " << 3 << endl;
//			solve(k - 1, tx, ty - 1, dx, dy);
//			solve(k - 1, tx, 0, dx, dy + ty);
//			solve(k - 1, x - tx - 1, y, dx + tx + 1, dy);
//			solve(k - 1, 0, 0, dx + tx + 1, dy + ty);
//		} else if (hang == 1 && lie == 1) {
//			int tx = (1 << (k - 1)) - 1, ty = (1 << (k - 1)) - 1;
//			cout << tx + dx + 1 << " " << ty + dy + 1 << " " << 4 << endl;
//			solve(k - 1, tx, ty, dx, dy);
//			solve(k - 1, tx, 0, dx, dy + ty + 1);
//			solve(k - 1, 0, ty, dx + tx + 1, dy);
//			solve(k - 1, x - tx - 1, y - ty - 1, dx + tx + 1, dy + ty + 1);
//		}
//	}
//}
//
//signed main() {
//	int k, x, y;
//	cin >> k >> x >> y;
//	solve(k, x - 1, y - 1, 0, 0);
//	return 0;
//}



// P9423 [蓝桥杯 2023 国 B] 数三角
//#include <bits/stdc++.h>
//using namespace std;
//using ll = long long;
//
//const int N = 2010;
//int x[N], y[N];
//unordered_map<ll, int> mp[N];
//unordered_map<int, unordered_map<int, int>> pos;
//
//ll d(int i, int j) {
//	return ((ll)(x[i] - x[j]) * (x[i] - x[j]) + (ll)(y[i] - y[j]) * (y[i] - y[j]));
//}
//
//int main(int argc, char** argv) {
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++) cin >> x[i] >> y[i], pos[x[i]][y[i]] = 1;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			if (i == j) continue;
//			ll juli = d(i, j);
//			mp[i][juli]++;
//		}
//	}
//	ll ans = 0;
//	for (int i = 0; i < n; i++) {
//		for (auto p : mp[i]) {
//			ans += p.second * (p.second - 1) / 2;
//		}
//	}
//	for (int i = 1; i < n; i++) {
//		for (int j = 0; j < i; j++) {
//			if ((x[i] + x[j]) % 2 == 0 && (y[i] + y[j]) % 2 == 0) {
//				ans -= pos[(x[i] + x[j]) / 2][(y[i] + y[j]) / 2];
//			}
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}



// P9425 [蓝桥杯 2023 国 B] AB 路线
//#include <bits/stdc++.h>
//using namespace std;
//
//int dx[] = {-1, 1, 0, 0};
//int dy[] = {0, 0, 1, -1};
//bool vis[1002][1002][16];
//
//struct node {
//	int x, y;
//	int cnt;
//};
//
//int main() {
//	string s = "AB";
//	int n, m, k;
//	cin >> n >> m >> k;
//	vector<string> a(n);
//	for (int i = 0; i < n; i++) cin >> a[i];
//	queue<node> q;
//	q.push({0, 0, 0});
//	vis[0][0][0] = 1;
//	int ans = -1;
//	while (!q.empty()) {
//		node now = q.front();
//		q.pop();
//		int x = now.x, y = now.y;
//		if (x == n - 1 && y == m - 1) {
//			ans = now.cnt;
//			break;
//		}
//		for (int i = 0; i < 4; i++) {
//			int x_ = x + dx[i];
//			int y_ = y + dy[i];
//			if (x_ < 0 || x_ >= n || y_ < 0 || y_ >= m) continue;
//			char yin = s[((now.cnt + 1) / k) & 1];
//			if (a[x_][y_] == yin) {
//				if (!vis[x_][y_][(now.cnt + 1) % k]) {
//					q.push({x_, y_, now.cnt + 1});
//					vis[x_][y_][(now.cnt + 1) % k] = 1;
//				}
//			}
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}



// P9426 [蓝桥杯 2023 国 B] 抓娃娃
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 2e6 + 10;
//int tr[N];
//
//void add(int x, int c) {
//	for (int i = x; i < N; i += i & -i)
//		tr[i] += c;
//}
//
//int sum(int x) {
//	int res = 0;
//	for (int i = x; i; i -= i & -i)
//		res += tr[i];
//	return res;
//}
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	int l, r;
//	while (n--) {
//		cin >> l >> r;
//		l <<= 1, r <<= 1;
//		int mid = (l + r) >> 1;
//		add(mid, 1);
//	}
//	while (m--) {
//		cin >> l >> r;
//		l <<= 1, r <<= 1;
//		int ans = sum(r) - sum(l - 1);
//		cout << ans << endl;
//	}
//	return 0;
//}



// P1404 平均数
//#include <bits/stdc++.h>
//using namespace std;
//using ll = long long;
//
//bool manzu(int mid, const vector<ll>& a, int m) {
//	int n = a.size() - 1;
//	ll minn = 1e18;
//	vector<ll> sum(n + 1);
//	for (int i = 1; i <= n; i++) {
//		sum[i] = sum[i - 1] + (a[i] - mid);
//		if (i >= m) {
//			minn = min(minn, sum[i - m]);
//			if (sum[i] >= minn) return true;
//		}
//	}
//	return false;
//}
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	vector<ll> a(n + 1);
//	for (int i = 1; i <= n; i++) cin >> a[i], a[i] *= 10000;
//	int l = 0, r = 20000000;
//	while (l <= r) {
//		int mid = (l + r) >> 1;
//		if (manzu(mid, a, m)) l = mid + 1;
//		else r = mid - 1;
//	}
//	cout << (l - 1) / 10 << endl;
//	return 0;
//}




// P10912 [蓝桥杯 2024 国 B] 数星星
//#include <bits/stdc++.h>
//using namespace std;
//using ll = long long;
//
//const int N = 1e5 + 10;
//const int mod = 1e9 + 7;
//
//int du[N], fact[N], infact[N];
//
//int qmi(int a, int k, int p) {
//	int res = 1;
//	a %= p;
//	while (k) {
//		if (k & 1) res = (ll)res * a % p;
//		k >>= 1;
//		a = (ll)a * a % p;
//	}
//	return res;
//}
//
//void init() {
//	infact[0] = fact[0] = 1;
//	for (int i = 1; i < N; i++) {
//		fact[i] = (ll)fact[i - 1] * i % mod;
//		infact[i] = (ll)infact[i - 1] * qmi(i, mod - 2, mod) % mod;
//	}
//}
//
//ll C(int n, int m) {
//	return ((ll)fact[n] * infact[n - m] % mod) * infact[m] % mod;
//}
//
//signed main() {
//	init();
//	int n, l, r;
//	cin >> n;
//	for (int i = 1; i < n; i++) {
//		int a, b;
//		cin >> a >> b;
//		du[a]++;
//		du[b]++;
//	}
//	cin >> l >> r;
//	l--, r--;
//	ll ans = 0;
//	for (int i = 1; i <= n; i++) {
//		for (int j = l; j <= r && j <= du[i]; j++) {
//			ans = (ans + C(du[i], j)) % mod;
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}



// B3621 枚举元组
//#include <bits/stdc++.h>
//using namespace std;
//
//int n, k;
//int a[6];
//
//void dfs(int deep) {
//	if (deep == n) {
//		for (int i = 0; i < n; i++) cout << a[i] << ' ';
//		cout << endl;
//	} else {
//		for (int i = 1; i <= k; i++) {
//			a[deep] = i;
//			dfs(deep + 1);
//		}
//	}
//}
//
//int main() {
//	cin >> n >> k;
//	dfs(0);
//	return 0;
//}




// P10417 [蓝桥杯 2023 国 A] 第 K 小的和
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//const int N = 1e5 + 10;
//int n, m, k;
//int a[N], b[N];
//
//bool manzu(int mid) {
//	int cnt = 0;
//	for (int i = 0; i < n; i++) {
//		cnt += upper_bound(b, b + m, mid - a[i]) - b;
//	}
//	return cnt >= k;
//}
//
//signed main() {
//	cin >> n >> m >> k;
//	for (int i = 0; i < n; i++) cin >> a[i];
//	for (int i = 0; i < m; i++) cin >> b[i];
//	sort(a, a + n);
//	sort(b, b + m);
//	int l = a[0] + b[0];
//	int r = a[n - 1] + b[m - 1];
//	while (l <= r) {
//		int mid = (l + r) >> 1;
//		if (manzu(mid)) r = mid - 1;
//		else l = mid + 1;
//	}
//	cout << r + 1 << endl;
//	return 0;
//}




// P10416 [蓝桥杯 2023 国 A] XYZ
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//	int t;
//	cin >> t;
//	int l, r;
//	while (t--) {
//		cin >> l >> r;
//		int x = r - 2 * l + 1;
//		if (x < 1) cout << 0 << endl;
//		else cout << (1 + x) * x / 2 << endl;
//	}
//	return 0;
//}




//P10910 [蓝桥杯 2024 国 B] 最小字符串
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	string s1, s2;
//	cin >> s1 >> s2;
//	string ans = "";
//	sort(s2.begin(), s2.end());
//	int i = 0, j = 0;
//	while (i < n && j < m) {
//		if (s1[i] <= s2[j]) ans += s1[i++];
//		else ans += s2[j++];
//	}
//	while (i < n) ans += s1[i++];
//	while (j < m) ans += s2[j++];
//	cout << ans << endl;
//	return 0;
//}




// P10580 [蓝桥杯 2024 国 A] gcd 与 lcm
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//const int mod = 998244353;
//
//int qmi(int a, int k, int p) {
//	int res = 1;
//	a %= p;
//	while (k) {
//		if (k & 1) res = res * a % p;
//		a = a * a % mod;
//		k >>= 1;
//	}
//	return res;
//}
//
//vector<int> fen(int x) {
//	vector<int> res;
//	for (int i = 2; i * i <= x; i++) {
//		if (x % i == 0) {
//			res.push_back(0);
//			while (x % i == 0) {
//				x /= i;
//				res.back()++;
//			}
//		}
//	}
//	if (x > 1) res.push_back(1);
//	return res;
//}
//
//signed main() {
//	int t, x, y, n;
//	cin >> t;
//	while (t--) {
//		cin >> x >> y >> n;
//		vector<int> res = fen(y / x);
//		int ans = 1;
//		for (int i : res) {
//			int temp = qmi(i + 1, n, mod);
//			temp = (temp - 2 * qmi(i, n, mod)) % mod;
//			temp = (temp + qmi(i - 1, n, mod)) % mod;
//			ans = ans * temp % mod;
//		}
//		cout << (ans % mod + mod) % mod << endl;
//	}
//	return 0;
//}




// P10915 [蓝桥杯 2024 国 B] 最长回文前后缀
//#include <bits/stdc++.h>
//using namespace std;
//using ull = unsigned long long;
//
//const int N = 500000 + 10, P = 131;
//ull zuo[N], you[N], p[N];
//
//void Hash(string s) {
//	p[0] = 1, zuo[0] = s[0], you[0] = s.back();
//	for (int i = 1; i <= (int)s.size(); i++)
//		p[i] = P * p[i - 1];
//	for (int i = 1; i < (int)s.size(); i++)
//		zuo[i] = zuo[i - 1] * P + s[i];
//	for (int i = s.size() - 2, j = 1; i >= 0; i--, j++)
//		you[j] = you[j - 1] * P + s[i];
//}
//
//ull get(int l, int r, ull a[]) {
//	if (l == 0) return a[r];
//	return a[r] - a[l - 1] * p[r - l + 1];
//}
//
//bool check(int mid, int i, int mode) {
//	if (mid == 0) return true;
//	if (mode) return get(i, i + mid - 1, you) == get(0, mid - 1, zuo);
//	else return get(i, i + mid - 1, zuo) == get(0, mid - 1, you);
//}
//
//signed main() {
//	string s;
//	cin >> s;
//	int ans = 0;
//	while (s.size() >= 2 && s.front() == s.back()) {
//		ans++;
//		s.erase(s.begin());
//		s.erase(s.end() - 1);
//	}
//	Hash(s);
//	int maxn = 0;
//	for (int i = 1; i <= (int)s.size() - 1; i++) {
//		int l = 0, r = (s.size() - i) / 2;
//		while (l <= r) {
//			int mid = (l + r) >> 1;
//			if (check(mid, i, 0)) l = mid + 1;
//			else r = mid - 1;
//		}
//		maxn = max(maxn, l - 1);
//	}
//	for (int i = 1; i < (int)s.size() - 1; i++) {
//		int l = 0, r = (s.size() - i) / 2;
//		while (l <= r) {
//			int mid = (l + r) >> 1;
//			if (check(mid, i, 1)) l = mid + 1;
//			else r = mid - 1;
//		}
//		maxn = max(maxn, l - 1);
//	}
//	cout << ans + maxn << endl;
//	return 0;
//}




// P8791 [蓝桥杯 2022 国 AC] 内存空间
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//	int t;
//	cin >> t;
//	getchar();
//	string s;
//	int ans = 0;
//	while (t--) {
//		getline(cin, s);
//		int sz = 0;
//		if (s[0] == 'l') sz = 8;
//		else if (s[0] == 'i') sz = 4;
//		bool is_zu = false;
//		bool is_s = false;
//		int dou_cnt = 0;
//		int zu_cnt = 0;
//		int char_cnt = 0;
//		for (unsigned i = 0; i < s.size(); i++) {
//			if (s[i] == ';') break;
//			if (s[i] == '[') {
//				is_zu = true;
//				int temp = 0;
//				int j = i + 1;
//				while (s[j] != ']') {
//					temp = temp * 10 + s[j] - '0';
//					j++;
//				}
//				i = j;
//				zu_cnt += temp;
//			}
//			if (s[i] == ',') dou_cnt++;
//			if (s[i] == '"') {
//				is_s = true;
//				int temp = 0;
//				int j = i + 1;
//				while (s[j] != '"') {
//					j++;
//					temp++;
//				}
//				i = j;
//				char_cnt += temp;
//			}
//		}
//
//		if (is_s) ans += char_cnt;
//		else if (is_zu) ans += sz * zu_cnt;
//		else ans += (dou_cnt + 1) * sz;
//	}
//	int GB = 1024 * 1024 * 1024;
//	int MB = 1024 * 1024;
//	int KB = 1024;
//	if (ans >= GB) {
//		cout << ans / GB << "GB";
//		ans = ans % GB;
//	}
//	if (ans >= MB) {
//		cout << ans / MB << "MB";
//		ans = ans % MB;
//	}
//	if (ans >= KB) {
//		cout << ans / KB << "KB";
//		ans = ans % KB;
//	}
//	if (ans > 0) {
//		cout << ans << "B";
//	}
//	return 0;
//}




// 	[蓝桥杯 2025 国 B] 新型锁
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//const int mod = 1e9 + 7, N = 2030;
//int dp[N][2];
//
//signed main() {
//	dp[1][0] = 4, dp[1][1] = 1;
//	for (int i = 2; i <= 2025; i++) {
//		dp[i][0] = 4 * dp[i - 1][1] % mod;
//		dp[i][1] = (dp[i - 1][1] + dp[i - 1][0]) % mod;
//	}
//	int ans1 = (dp[2025][0] + dp[2025][1]) % mod;
//	dp[1][0] = 2, dp[1][1] = 1;
//	for (int i = 2; i <= 2025; i++) {
//		dp[i][0] = 2 * dp[i - 1][1] % mod;
//		dp[i][1] = (dp[i - 1][1] + dp[i - 1][0]) % mod;
//	}
//	int ans2 = (dp[2025][0] + dp[2025][1]) % mod;
//	int ans = ans1 * ans2 % mod;
//	cout << ans << endl;
//	return 0;
//}



// P12833 [蓝桥杯 2025 国 B] 斐波那契字符串
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//const int mod = 1e9 + 7;
//const int N = 1e5 + 10;
//
//int ans[N];
//
//void init() {
//	ans[4] = 1;
//	int qq1 = 1, qq0 = 1;
//	int q1 = 2, q0 = 1;
//	for (int i = 5; i < N; i++) {
//		ans[i] = ((ans[i - 1] + ans[i - 2]) % mod + (qq1 * q0) % mod) % mod;
//		int d0 = (qq0 + q0) % mod;
//		int d1 = (qq1 + q1) % mod;
//		qq1 = q1, qq0 = q0;
//		q1 = d1, q0 = d0;
//	}
//}
//
//signed main() {
//	int t;
//	cin >> t;
//	init();
//	while (t--) {
//		int n;
//		cin >> n;
//		cout << ans[n] << endl;
//	}
//	return 0;
//}



// P6492 [COCI 2010/2011 #6] STEP
// 手敲一遍过，没办法就是强
//#include <bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 10;
//
//struct node {
//	int l, r;
//	int zuo, you, maxn;
//};
//
//node tr[4 * N];
//string s;
//
//void pushup(node& root, node& left, node& right) {
//	int maxn = -1;
//	if (s[left.r] != s[right.l]) {
//		maxn = left.you + right.zuo;
//	}
//	maxn = max(maxn, left.maxn);
//	maxn = max(maxn, right.maxn);
//	root.maxn = maxn;
//	root.zuo = left.zuo;
//	root.you = right.you;
//	if (left.zuo == left.r - left.l + 1 && s[left.r] != s[right.l]) {
//		root.zuo = left.zuo + right.zuo;
//	}
//	if (right.you == right.r - right.l + 1 && s[right.l] != s[left.r]) {
//		root.you = right.you + left.you;
//	}
//}
//
//void build(int u, int l, int r) {
//	if (l == r) {
//		tr[u] = {l, r, 1, 1, 1};
//	} else {
//		tr[u] = {l, r};
//		int mid = (l + r) >> 1;
//		build(u << 1, l, mid);
//		build(u << 1 | 1, mid + 1, r);
//		pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
//	}
//}
//
//void modify(int u, int x) {
//	if (x == tr[u].l && x == tr[u].r) {
//		if (s[x] == 'L') s[x] = 'R';
//		else s[x] = 'L';
//	} else {
//		int mid = (tr[u].l + tr[u].r) >> 1;
//		if (x <= mid) {
//			modify(u << 1, x);
//			pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
//		} else if (x > mid) {
//			modify(u << 1 | 1, x);
//			pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
//		}
//	}
//}
//
//node query(int u, int l, int r) {
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
//int main() {
//	int n, q;
//	cin >> n >> q;
//	s = " ";
//	for (int i = 1; i <= n; i++) s += 'L';
//	build(1, 1, n);
//	while (q--) {
//		int x;
//		cin >> x;
//		modify(1, x);
//		cout << query(1, 1, n).maxn << endl;
//	}
//	return 0;
//}



// https://www.luogu.com.cn/problem/P3152
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//	int n;
//	cin >> n;
//	auto dfs = [&](auto&& self, int x) {
//		if (x <= 2) return x;
//		return 1 + self(self, x / 2);
//	};
//	cout << dfs(dfs, n) << endl;
//	return 0;
//}



// https://www.luogu.com.cn/problem/P1898
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//	string s;
//	int t;
//	cin >> s >> t;
//	string s1 = "";
//	for (char c : s) s1 += to_string(c - 'A' + t);
//	string s2;
//	while (s1.size() > 2) {
//		s2 = "";
//		for (int i = 0; i < (int)s1.size() - 1; i++) {
//			s2 += (s1[i] - '0' + s1[i + 1] - '0') % 10 + '0';
//		}
//		s1 = s2;
//		if (s1 == "100") break;
//	}
//	cout << stoi(s1) << endl;
//	return 0;
//}


// https://www.luogu.com.cn/problem/P11231
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//	int n;
//	cin >> n;
//	vector<int> a(n + 1);
//	for (int i = 1; i <= n; i++) cin >> a[i];
//	sort(a.begin() + 1, a.end());
//	int l = 1, r = 2;
//	for (; r <= n; r++) {
//		if (a[r] > a[l]) l++;
//	}
//	cout << r - l << endl;
//	return 0;
//}


// https://www.luogu.com.cn/problem/P1011
//#include <bits/stdc++.h>
//using namespace std;
//
//struct node {
//	int a, x;
//	node operator+(const node& t) {
//		return {this->a + t.a, this->x + t.x};
//	}
//	node operator-(const node& t) {
//		return {this->a - t.a, this->x - t.x};
//	}
//};
//
//signed main() {
//	int a, n, m, x;
//	cin >> a >> n >> m >> x;
//	vector<node> shang(n + 10), xia(n + 10), ren(n + 10);
//	shang[1] = {1, 0}, shang[2] = {0, 1};
//	xia[1] = {0, 0}, xia[2] = {0, x};
//	ren[1] = ren[2] = {1, 0};
//	for (int i = 3; i < n; i++) {
//		shang[i] = shang[i - 1] + shang[i - 2];
//		xia[i] = shang[i - 1];
//		ren[i] = ren[i - 1] + shang[i] - xia[i];
//	}
//	int x_ = ren[n - 1].x ? (m - ren[n - 1].a * a) / ren[n - 1].x : 0;
//	cout << x_ * ren[x].x + a * ren[x].a << endl;
//	return 0;
//}










