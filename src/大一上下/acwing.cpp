// https://www.acwing.com/problem/content/description/91/
//2025.1.11
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int a, b, p;
//	cin >> a >> b >> p;
//
//	int ans = 1 % p;
//	while (b) {
//		if (b & 1) ans = 1LL * a * ans % p;
//
//		a = 1LL * a * a % p;
//		b >>= 1;
//	}
//	cout << ans << endl;
//	return 0;
//}


// https://www.acwing.com/problem/content/92/
//2025.1.12
//#include <bits/stdc++.h>
//using namespace std;
//
//#define int long long
//
//signed main() {
//	int a, b, p;
//	cin >> a >> b >> p;
//	int ans = 0;
//	while (b) {
//		if (b & 1) ans = (ans + a) % p;
//		a = 2 * a % p;
//		b >>= 1;
//	}
//	cout << ans << endl;
//	return 0;
//}


// https://www.acwing.com/problem/content/93/
//91. 最短Hamilton路径 二进制 状态压缩DP
//2025.1.12
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<vector<int>> weight(n, vector<int>(n));
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			cin >> weight[i][j];
//
//	vector<vector<int>> f((1 << n) + 1, vector<int>(n + 1, INT32_MAX / 2));
//	f[1][0] = 0;
//
//	for (int i = 1; i < 1 << n; i++) {
//		for (int j = 0; j < n; j++) {
//			if (i >> j & 1) {
//				for (int k = 0; k < n; k++) {
//					if ((i - (1 << j)) >> k & 1) {
//						f[i][j] = min(f[i][j], f[i - (1 << j)][k] + weight[k][j]);
//					}
//				}
//			}
//		}
//	}
//
//	cout << f[(1 << n) - 1][n - 1] << endl;
//
//	return 0;
//}


//AcWing 92. 递归实现指数型枚举
//2025.1.13
//#include <bits/stdc++.h>
//using namespace std;
//
//void get_ans(int shu, int deep, int n, int start, vector<int>& ans) {
//	if (deep == shu) {
//		for (int i = 0; i < deep; i++) cout << ans[i] << ' ';
//		cout << endl;
//	} else {
//		if (n - start + 1 < shu - deep) return;
//		for (int i = start; i <= n; i++) {
//			ans[deep] = i;
//			get_ans(shu, deep + 1, n, i + 1, ans);
//		}
//	}
//}
//
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 0; i <= n; i++) {
//		vector<int> a(i + 1);
//		get_ans(i, 0, n, 1, a);
//	}
//	return 0;
//}

//yxc做法 我只能说特别牛逼
//#include <bits/stdc++.h>
//using namespace std;
//
//int n;
//
//void dfs(int u, int state) {
//	if (u == n) {
//		for (int i = 0; i < n; i++) {
//			if (state >> i & 1)
//				cout << i + 1 << ' ';
//		}
//		cout << endl;
//	} else {
//		dfs(u + 1, state);
//		dfs(u + 1, state | (1 << u));
//	}
//}
//
//int main() {
//	cin >> n;
//	dfs(0, 0);
//	return 0;
//}


//AcWing 93. 递归实现组合型枚举
//2025.1.15
//#include <bits/stdc++.h>
//using namespace std;
//
//int n, m;
//int ans[20];
//
//void dfs(int start, int deep) {
//	if (deep == m) {
//		for (int i = 0; i < m; i++) cout << ans[i] << ' ';
//		cout << endl;
//	} else {
//		for (int i = start; i <= n; i++) {
//			ans[deep] = i;
//			dfs(i + 1, deep + 1);
//		}
//	}
//}
//
//int main() {
//	cin >> n >> m;
//	dfs(1, 0);
//	return 0;
//}


// 94. 递归实现排列型枚举
//2025.1.15
//#include <bits/stdc++.h>
//using namespace std;
//
//int n;
//int a[10];
//bool vis[10];
//
//void dfs(int deep) {
//	if (deep == n) {
//		for (int i = 0; i < n; i++) cout << a[i] << ' ';
//		cout << endl;
//	} else {
//		for (int i = 1; i <= n; i++) {
//			if (!vis[i]) {
//				a[deep] = i;
//				vis[i] = 1;
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
//	return 0;
//}



// AcWing 95. 费解的开关
//2025.1.15
//#include <bits/stdc++.h>
//using namespace std;
//
//vector<string> a(5);
//int n;
//
//int dx[] = {0, 1, -1, 0, 0};
//int dy[] = {0, 0, 0, 1, -1};
//
//void turn(int i, int j) {
//	int xx, yy;
//	for (int k = 0; k < 5; k++) {
//		xx = i + dx[k];
//		yy = j + dy[k];
//		if (xx >= 0 && xx <= 4 && yy >= 0 && yy <= 4) a[xx][yy] ^= 1;
//	}
//}
//
//void work() {
//	vector<string> a_c(a.begin(), a.end());
//	int ans = 100000;
//	for (int i = 0; i < 1 << 5; i++) {
//		int res = 0;
//		for (int j = 0; j < 5; j++) {
//			if ((i >> j) & 1) {
//				turn(0, j);
//				res++;
//			}
//		}
//
//		for (int j = 1; j < 5; j++) {
//			for (int k = 0; k < 5; k++) {
//				if (a[j - 1][k] == '0') {
//					turn(j, k);
//					res++;
//				}
//			}
//		}
//
//		bool is_true = true;
//		for (int j = 0; j < 5; j++) {
//			if (a[4][j] == '0') {
//				is_true = false;
//				break;
//			}
//		}
//
//		if (is_true) {
//			ans = min(ans, res);
//		}
//
//		a.assign(a_c.begin(), a_c.end());
//	}
//
//	if (ans > 6) cout << -1 << endl;
//	else cout << ans << endl;
//}
//
//int main() {
//	cin >> n;
//	while (n--) {
//		for (int i = 0; i < 5; i++) cin >> a[i];
//		work();
//	}
//	return 0;
//}


// 96. 奇怪的汉诺塔
// 2025.1.16
//#include <bits/stdc++.h>
//using namespace std;
//
//#define int long long
//
//int a[13];
//
//signed main() {
//	a[1] = 1;
//	a[2] = 3;
//	a[3] = 5;
//	for (int i = 4; i <= 12; i++) a[i] = LONG_LONG_MAX;
//	for (int i = 4; i <= 12; i++) {
//		for (int j = 0; j < i; j++) {
//			a[i] = min(a[i], 2 * a[j] + (1 << (i - j)) - 1);
//		}
//	}
//
//	for (int i = 1; i <= 12; i++) {
//		cout << a[i] << endl;
//	}
//	return 0;
//}


//97. 约数之和
//2025.1.16
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//unordered_map<int, int> mp;
//const int mod = 9901;
//int a, b;
//
//void qiuyinzi(int c) {
//	for (int i = 2; c != 1 && i <= c; i++) {
//		while (c % i == 0) {
//			mp[i]++;
//			c /= i;
//		}
//	}
//}
//
//int po(int x, int k) {
//	int res = 1;
//	x %= mod;
//	while (k) {
//		if (k & 1) res = res * x % mod;
//		k >>= 1;
//		x = x * x % mod;
//	}
//	return res;
//}
//
//int m(int p, int x) {
//	if (x == 0) return 1;
//	if (x & 1) {
//		return (1 + po(p, x / 2 + 1)) * m(p, x / 2) % mod;
//	} else {
//		return (p % mod * m(p, x - 1) + 1) % mod;
//	}
//}
//
//int tans() {
//	if (a == 0) return 0;
//	int ans = 1;
//	for (auto pai : mp) {
//		ans = ans * m(pai.first, pai.second * b) % mod;
//	}
//	return ans;
//}
//
//signed main() {
//	cin >> a >> b;
//	qiuyinzi(a);
//	cout << tans() << endl;
//	return 0;
//}


// AcWing 98. 分形之城 太难不会


// 99. 激光炸弹
// 2025.1.26
//#include <bits/stdc++.h>
//using namespace std;
//
//const int M = 5011;
//
//int n, r;
//int s[M][M];
//
//int main() {
//	cin >> n >> r;
//	while (n--) {
//		int x, y, w;
//		cin >> x >> y >> w;
//		s[++x][++y] += w;
//	}
//
//	for (int i = 1; i <= M - 10; i++) {
//		for (int j = 1; j <= M - 10; j++) {
//			s[i][j] = s[i - 1][j] + s[i][j - 1] + s[i][j] - s[i - 1][j - 1];
//		}
//	}
//	r = min(r, M - 10);
//	int ans = 0;
//	for (int i = r; i <= M - 10; i++) {
//		for (int j = r; j <= M - 10; j++) {
//			int res = s[i][j] - s[i - r][j] - s[i][j - r] + s[i - r][j - r];
//			ans = max(ans, res);
//		}
//	}
//
//	cout << ans << endl;
//	return 0;
//}


// 100. 增减序列
// 2025.1.27
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 100010;
//int a[N], n;
//
//int main() {
//	cin >> n;
//	for (int i = 1; i <= n; i++) cin >> a[i];
//	for (int i = n; i >= 2; i--) a[i] = a[i] - a[i - 1];
//
//	long long zhen = 0, fu = 0;
//	for (int i = 2; i <= n; i++) {
//		if (a[i] > 0) zhen += a[i];
//		else fu -= a[i];
//	}
//
//	cout << min(zhen, fu) + abs(zhen - fu) << endl;
//	cout << abs(zhen - fu) + 1 << endl;
//	return 0;
//}



// 101. 最高的牛
// 2025.1.27
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n, p, h, m;
//	cin >> n >> p >> h >> m;
//	vector<int> a(n + 1);
//	unordered_map<string, bool> vis;
//	while (m --) {
//		int x, y;
//		cin >> x >> y;
//		int x_ = x;
//		int y_ = y;
//		x = min(x_, y_);
//		y = max(x_, y_);
//		string s = to_string(x) + to_string(y);
//		if (!vis[s]) {
//			a[x + 1] -= 1;
//			a[y] += 1;
//			vis[s] = true;
//		}
//	}
//	for (int i = 1; i <= n; i++) a[i] = a[i - 1] + a[i];
//	for (int i = 1; i <= n; i++) {
//		cout << a[i] + h << endl;
//	}
//	return 0;
//}



// 102. 最佳牛围栏
// 2025.1.27
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 100010;
//double sum[N];
//int a[N];
//
//int n, f;
//
//bool check(double mid) {
//	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i] - mid;
//	double minx = 0;
//	for (int i = 0, j = f; j <= n; j++, i++) {
//		minx = min(minx, sum[i]);
//		if (sum[j] - minx >= 0) return true;
//	}
//	return false;
//}
//
//int main() {
//
//	cin >> n >> f;
//	for (int i = 1; i <= n; i++) cin >> a[i];
//	double l = 1, r = 2000;
//	while (r - l > 1e-5) {
//		double mid = (l + r) / 2;
//		if (check(mid)) l = mid;
//		else r = mid;
//	}
//	cout << int(r * 1000) << endl;
//	return 0;
//}



// 104. 货仓选址  中位数定理秒了！
// 2025.1.27
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++) cin >> a[i];
//	sort(a.begin(), a.end());
//	int x = a[n / 2];
//	int ans = 0;
//	for (int i = 0; i < n; i++) ans += abs(x - a[i]);
//	cout << ans << endl;
//	return 0;
//}



// 1055. 股票买卖 II
// 2025.2.2
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int> a(n + 3);
//	a[0] = INT32_MAX;
//	for (int i = 1; i <= n; i++) cin >> a[i];
//	int sum = 0;
//	for (int i = 0; i <= n; i++) {
//		if (a[i - 1] >= a[i] && a[i] < a[i + 1]) {
//			for (int j = i + 1; j <= n; j++) {
//				if (a[j - 1] <= a[j] && a[j] > a[j + 1]) {
//					sum += a[j] - a[i];
//					i = j;
//					break;
//				}
//			}
//		}
//	}
//	cout << sum << endl;
//	return 0;
//}

// 同上题，用y总的方法
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++) cin >> a[i];
//	int res = 0;
//	for (int i = 0; i < n - 1; i++) res += max(0, a[i + 1] - a[i]);
//	cout << res << endl;
//	return 0;
//}



// AcWing 110. 防晒
// 2025.2.24
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 1010;
//
//int main() {
//	int c, l;
//	cin >> c >> l;
//	vector<pair<int, int>> a(c);
//	for (int i = 0; i < c; i++) cin >> a[i].second >> a[i].first;
//	sort(a.begin(), a.end());
//	vector<int> b(N);
//	for (int i = 0; i < l; i++) {
//		int x, y;
//		cin >> x >> y;
//		b[x] += y;
//	}
//	int ans = 0;
//	for (int i = 0; i < c; i++) {
//		for (int j = a[i].second; j <= a[i].first; j++) {
//			if (b[j] > 0) {
//				ans++;
//				b[j]--;
//				break;
//			}
//		}
//	}
//
//	cout << ans << endl;
//	return 0;
//}


// 111. 畜栏预定
// 2025.2.27
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<array<int, 3>> a(n);
//	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
//	for (int i = 0; i < n; i++) {
//		cin >> a[i][0] >> a[i][1];
//		a[i][2] = i;
//	}
//	sort(a.begin(), a.end());
//	int ans = 0;
//	vector<int> idx_a(n);
//	int idx = 1;
//	for (int i = 0; i < n; i++) {
//		if (q.empty()) {
//			q.push({a[i][1], idx});
//			idx_a[a[i][2]] = idx++;
//			ans++;
//		} else {
//			if (q.top().first < a[i][0]) {
//				int temp = q.top().second;
//				q.pop();
//				q.push({a[i][1], temp});
//				idx_a[a[i][2]] = temp;
//			} else {
//				q.push({a[i][1], idx});
//				idx_a[a[i][2]] = idx++;
//				ans++;
//			}
//		}
//	}
//	cout << ans << endl;
//	for (int i = 0; i < n; i++) cout << idx_a[i] << endl;
//	return 0;
//}



// 112. 雷达设备
//2025.2.27
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n, d;
//	cin >> n >> d;
//	vector<pair<int, int>> a(n);
//	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
//	vector<pair<double, double>> b(n);
//	for (int i = 0; i < n; i++) {
//		if (a[i].second > d) {
//			cout << -1;
//			return 0;
//		}
//		b[i].second = a[i].first - sqrt(d * d - a[i].second * a[i].second);
//		b[i].first = a[i].first + sqrt(d * d - a[i].second * a[i].second);
//	}
//	int ans = 1;
//	sort(b.begin(), b.end());
//	double ed = b[0].first;
//	for (int i = 1; i < n; i++) {
//		if (b[i].second > ed) {
//			ans++;
//			ed = b[i].first;
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}



// 114. 国王游戏
// 2025.2.28
#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
	return a.first * a.second < b.first * b.second;
}

vector<int> max_(vector<int> a, vector<int> b) {
	if (a.size() > b.size()) return a;
	if (a.size() < b.size()) return b;
	if (vector<int>(a.rbegin(), a.rend()) < vector<int>(b.rbegin(), b.rend()))
		return b;
	return a;
}


vector<int> div(vector<int> a, int b) {
	vector<int> c;
	bool is_first = false;
	int t = 0;
	for (int i = a.size() - 1; i >= 0; i--) {
		t = 10 * t + a[i];
		if (t / b || is_first) {
			is_first = true;
			c.push_back(t / b);
		}
		t %= b;
	}
	return vector<int>(c.rbegin(), c.rend());
}


vector<int> mul(vector<int> a, int b) {
	vector<int> c;
	int t = 0;
	for (unsigned int i = 0; i < a.size(); i++) {
		t += a[i] * b;
		c.push_back(t % 10);
		t /= 10;
	}
	while (t) {
		c.push_back(t % 10);
		t /= 10;
	}
	return c;
}

void output(vector<int>& a) {
	for (int i = a.size() - 1; i >= 0; i--) cout << a[i];
	cout << endl;
}


int main() {
	int n, x, y;
	cin >> n >> x >> y;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	sort(a.begin(), a.end(), cmp);
	vector<int> ans(1, 0);
	vector<int> ji;
	while (x) {
		ji.push_back(x % 10);
		x /= 10;
	}
	for (int i = 0; i < n; i++) {
		ans = max_(ans, div(ji, a[i].second));
		ji = mul(ji, a[i].first);
	}
	output(ans);
	return 0;
}
