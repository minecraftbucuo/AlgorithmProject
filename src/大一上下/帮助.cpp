//#include <cstdio>
//using namespace std;
////入门题帮别人写的
//
//int main() {
//	int h[10];
//	int a, cnt = 0;
//	for (int i = 0; i < 10; i++) {
//		scanf("%d", &h[i]);
//	}
//	scanf("%d", &a);
//	a += 30;
//
//	int i = 0;
//	while (i <= 9) {
//		if (h[i] <= a) cnt++;
//		i++;
//	}
//
//	printf("%d", cnt);
//
//	return 0;
//}

//#include<stdio.h>
//int main() {
//	int n, k, x, t;
//	scanf ("%d", &t);
//	for (int i = 0; i < t; i++) {
//		scanf ("%d %d %d", &n, &k, &x);
//		if ((k - 1) > n || (k - 1) > x) printf("-1\n");
//		else {
//			int sum = 0;
//			for (int i = 0; i <= k - 1; i++) {
//				sum += i;
//			}
//			for (int i = k; i < n; i++) {
//				if (x != k)
//					sum += x;
//				else
//					sum += k - 1;
//			}
//			printf ("%d\n", sum);
//		}
//	}
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//
//string operator*(string s, int n) {
//	if (n != 0) {
//		string s_t = s;
//		for (int i = 0; i < n - 1; i++) {
//			s += s_t;
//		}
//		return s;
//	} else {
//		return string("");
//	}
//}
//
//int main() {
//	int x = 1;
//	for (int i = 0; i < 4; i++) {
//		string s;
//		for (int j = 0; j < i + 1; j++) {
//			if (x < 10)
//				s = s + '0' + to_string(x);
//			else {
//				s = s + to_string(x);
//			}
//			x++;
//		}
//		s = string(" ") * (8 - s.size()) + s;
//		cout << s;
//		cout << endl;
//	}
//	return 0;
//}


//#include<stdio.h>
//
//int main() {
//	char s[4];
//	int t;
//	scanf("%d", &t);
//	while (t--) {
//		scanf("%s", s);
//		if (s[0] == 'a' || s[1] == 'b' || s[2] == 'c') {
//			printf("YES\n");
//		} else {
//			printf("NO\n");
//		}
//	}
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int t, x, y, k;
//	cin >> t;
//	while (t--) {
//		cin >> x >> y >> k;
//		int m = min(x, y);
//		cout << "0 0" << ' ' << m << ' ' << m << endl;
//		cout << "0 " << m << ' ' << m << ' ' << '0' << endl;
//	}
//	return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int x;
//	cin >> x;
//	int a, b, c, d;
//	if (x % 2 == 0 && (4 < x && x <= 12)) {
//		a = 1;
//	} else {
//		a = 0;
//	}
//
//	if (x % 2 == 0 || (4 < x && x <= 12)) {
//		b = 1;
//	} else {
//		b = 0;
//	}
//
//	if ((!(x % 2 == 0) && (4 < x && x <= 12)) || ((x % 2 == 0) && !(4 < x && x <= 12))) {
//		c = 1;
//	} else {
//		c = 0;
//	}
//
//	if (!(x % 2 == 0) && !(4 < x && x <= 12)) {
//		d = 1;
//	} else {
//		d = 0;
//	}
//
//	cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
//
//	return 0;
//}


//#include<bits/stdc++.h>
//#define ll long long
//#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//using namespace std;
//ll n, h;
//bool  check( vector<ll> &a, ll k) {
//	ll sum = 0;
//	for (int i = 1; i <= n - 1; i++) {
//		if (a[i] + k <= a[i + 1]) sum += k;
//		else sum += a[i + 1] - a[i];
//	}
//	sum += k;
//	if (sum >= h) return true;
//	else return false;
//}
//
//int main() {
//	IOS;
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> n >> h;
//		vector<ll> a(n + 1);
//		for (int i = 1; i <= n; ++i) {
//			cin >> a[i];
//		}
//
//		ll ans = 0;
//		ll l = 0, r = h + 1;
//		while (l <= r) {
//			ll mid = (l + r) >> 1;
//			if (check(a, mid)) {
//				ans = mid;
//				r = mid - 1;
//			} else {
//				l = mid + 1;
//			}
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int t;
//	string s1, s2;
//	cin >> t;
//	while (t--) {
//		cin >> s1 >> s2;
//		bool have_ans = false;
//		for (int i = 0; i < (int)s1.size() - 1; i++) {
//			if (s1[i] == '0' && s2[i] == '0' && s1[i + 1] == '1' && s2[i + 1] == '1') {
//				cout << "YES" << endl;
//				have_ans = true;
//				break;
//			}
//		}
//
//		if (!have_ans) cout << "NO" << endl;
//	}
//	return 0;
//}


// 2023选拔赛的一道题目，帮助我自己
//#include <bits/stdc++.h>
//using namespace std;
//
//void dfs(int start, int step, vector<int>& ans, vector<int>& vis, vector<vector<int>>& g) {
//	ans[start] = step;
//	vis[start] = 1;
//	for (int i = 0; i < (int)g[start].size(); i++) {
//		if (!vis[g[start][i]])
//			dfs(g[start][i], step + 1, ans, vis, g);
//	}
//}
//
//int main() {
//	int n, a, b;
//	cin >> n;
//	vector<vector<int>> g(n + 1, vector<int>());
//	for (int i = 1; i < n; i++) {
//		cin >> a >> b;
//		g[a].push_back(b);
//		g[b].push_back(a);
//	}
//	vector<int> vis(n + 1);
//	vector<int> ans(n + 1);
//	dfs(1, 0, ans, vis, g);
//
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> a >> b;
//		if (abs(ans[a] - ans[b]) % 2 == 0) cout << "YES" << endl;
//		else cout << "NO" << endl;
//	}
//
//	return 0;
//}



//第114514个素数  垃圾的算法
//#include <bits/stdc++.h>
//using namespace std;
//
//#define int long long
//
//signed main() {
//	vector<int> a = {2};
//	while ((int)a.size() != 114514) {
//		for (int i = a.back() + 1; ; i += 1) {
//			int j;
//			for (j = 0; j < (int)a.size(); j++) {
//				if (i % a[j] == 0) break;
//			}
//			if (j == (int)a.size()) {
//				a.push_back(i);
//				break;
//			}
//		}
//		cout << a.back() << endl;
//	}
//
//	return 0;
//}


//欧拉筛
//#include <bits/stdc++.h>
//using namespace std;
//
//const int MAXN = 1e7;
//bool isprime[MAXN]; // isprime[i]表示i是不是素数
//int prime[MAXN]; // 现在已经筛出的素数列表
//int n; // 上限，即筛出<=n的素数
//int cnt; // 已经筛出的素数个数
//
//void euler() {
//	memset(isprime, true, sizeof(isprime)); // 先全部标记为素数
//	isprime[1] = false; // 1不是素数
//	for (int i = 2; i <= n; ++i) { // i从2循环到n（外层循环）
//		if (cnt == 114514) return;
//		if (isprime[i]) prime[++cnt] = i;
//		// 如果i没有被前面的数筛掉，则i是素数
//		for (int j = 1; j <= cnt && i * prime[j] <= n; ++j)
//			// 筛掉i的素数倍，即i的prime[j]倍
//			// j循环枚举现在已经筛出的素数（内层循环）
//		{
//			isprime[i * prime[j]] = false;
//			// 倍数标记为合数，也就是i用prime[j]把i * prime[j]筛掉了
//			if (i % prime[j] == 0) break;
//			// 最神奇的一句话，如果i整除prime[j]，退出循环
//			// 这样可以保证线性的时间复杂度
//		}
//	}
//}
//
//int main() {
//	n = 10000000;
//	euler();
//	cout << prime[114514] << endl;
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//
//ll n, d, s;
//ll dd, nn, ans;
//
//int main() {
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	cin >> n >> d >> s;
//
//	if (d < s) {
//		cout << s;
//		return 0;
//	}
//
//	dd = d / s;
//	nn = n / s;
//
//	ans = min(2 * d / s, nn);
//
//	if (ans % 2 == 0 || ans == 1) {
//		cout << ans * s;
//		return 0;
//	} else {
//		ll judge = 0;
//		for (ll i = 1; i * i <= ans; i += 2) {
//			if (ans % i == 0) {
//				if (ans - i <= dd && i - 1 <= dd) {
//					judge = 1;
//				}
//			}
//		}
//		if (judge == 1) {
//			cout << ans * s;
//			return 0;
//		} else {
//			cout << (ans - 1) * s;
//			return 0;
//		}
//	}
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int a[6] = {3, 7, 6, 1, 2, 4};
//	// 先默认最小值的下标为0
//	int min_idx = 0;
//	for (int i = 1; i < 6; i++) {
//		if (a[min_idx] > a[i]) {
//			min_idx = i;
//		}
//	}
//	// 交换两个数
//	swap(a[0], a[min_idx]);
//
////  交换也可以这样写
////	int t = a[0];
////	a[0] = a[min_idx];
////	a[min_idx] = t;
//
//
//	for (int i = 0; i < 6; i++) {
//		cout << a[i] << ' ';
//	}
//
//	return 0;
//}


// 线性筛质数 2025.1.10
// 自带质因数分解
//#include <bits/stdc++.h>
//using namespace std;
//
//void write(int x) {
//	if (x < 0)
//		putchar('-'), x = -x;
//	if (x > 9)
//		write(x / 10);
//	putchar(x % 10 + '0');
//	return;
//}
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
//void print_fenjie(vector<int>& min_yinzi, int n) {
//	while (min_yinzi[n] != 0) {
//		cout << min_yinzi[n] << 'x';
//		n /= min_yinzi[n];
//	}
//	cout << n;
//}
//
//void print_fenjie_q(vector<int>& min_yinzi, int n) {
//	while (min_yinzi[n] != 0) {
//		write(min_yinzi[n]), putchar('x');
//		n /= min_yinzi[n];
//	}
//	write(n);
//}
//
//int main() {
//	vector<int> primes;
//	vector<int> min_yinzi;
//	get_primes(primes, min_yinzi, 1e8);
////	for (int i = 2; i <= 100000; i++) {
////		write(i), putchar('=');
////		print_fenjie_q(min_yinzi, i);
////		putchar('\n');
////	}
//
//	print_fenjie(min_yinzi, 233333);
//	cout << endl;
//	print_fenjie(min_yinzi, 343720);
//	return 0;
//}



//#include<iostream>
//#include<stdio.h>
//using namespace std;
//
//int main(void) {
//	int n, m, i, j, minn = 11, maxn = -1, sum = 0;
//	double ave, s = 0.0;
//	int a[10000];
//	cin >> n >> m;
//	for (i = 1; i <= n; i++) {
////		for(j=1;j<=m;j++)
////			cin>>a[j];
////		sum+=a[j];
////		minn=min(minn,a[j]);
////		maxn=max(maxn,a[j]);
//
//		// 上面应该这样写：
//		for (j = 1; j <= m; j++) {
//			cin >> a[j];
//			sum += a[j];
//			minn = min(minn, a[j]);
//			maxn = max(maxn, a[j]);
//		}
//		sum = sum - maxn - minn;
////		ave = 0.1 * sum / (m - 2);
//		ave = 1.0 * sum / (m - 2);
//		if (ave > s)
//			s = ave;
//		ave = 0;
//		sum = 0;
//
//		// 恍然大悟少了这两句！
//		minn = 11;
//		maxn = -1;
//	}
//	printf("%.2lf", s);
//}



//#include<iostream>
//using namespace std;
//
//int main(void) {
//	int a[1001], b[1001], c[1001], sum[1001];
//	string name[1001];
//	int i, j, N;
//	cin >> N;
//	for (i = 1; i <= N; i++) {
//		cin >> name[i] >> a[i] >> b[i] >> c[i];
//		sum[i] = a[i] + b[i] + c[i];
//	}
//
//	for (i = 1; i <= N - 1; i++) {
//		for (j = i + 1; j <= N; j++) {
//			if (abs(a[i] - a[j]) <= 5 && abs(b[i] - b[j]) <= 5 && abs(c[i] - c[j]) <= 5 && abs(sum[i] - sum[j]) <= 10) {
//				cout << name[i] << " " << name[j] << "\n";
//			}
//		}
//	}
//}



//#include <iostream>
//using namespace std;
//
//long long f(int n) {
//	if (n == 1 || n == 0) return 1;
//	else return f(n - 1) * n;
//}
//
//int main() {
//	double s = 0;
//	for (int i = 0; i <= 10; i++) {
//		s += 1.0 / f(i);
//	}
//	cout << s << endl;
//	return 0;
//}



//#include <bits/stdc++.h>
//using namespace std;
//
//static int pinyear[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//static int runyear[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//
//class Date {
//public:
//	string date;
//	string day;
//	string mon;
//	string year;
//	Date(string date) {
//		this->date = date;
//		this->day = date.substr(8, 2);
//		this->mon = date.substr(5, 2);
//		this->year = date.substr(0, 4);
//	}
//
//	string returndate() {
//		return year + '-' + mon + '-' + day;
//	}
//
//	void add_day() {
//		int day = stoi(this->day);
//		int mon = stoi(this->mon);
//		int year = stoi(this->year);
//		if (year % 4 == 0) {
//			day += 1;
//			if (day > runyear[mon]) {
//				day = 1;
//				mon++;
//				if (mon == 13) {
//					mon = 1;
//					year++;
//				}
//			}
//		} else {
//			day += 1;
//			if (day > pinyear[mon]) {
//				day = 1;
//				mon++;
//				if (mon == 13) {
//					mon = 1;
//					year++;
//				}
//			}
//		}
//
//		this->year = to_string(year);
//		this->day = to_string(day);
//		if (this->day.size() <= 1) this->day = "0" + this->day;
//		this->mon = to_string(mon);
//		if (this->mon.size() <= 1) this->mon = "0" + this->mon;
//	}
//};
//
//int main() {
//
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//
//class Mat {
//public:
//	vector<vector<int>> M;
//	Mat(int a, int b, int c, int d) {
//		M.assign(3, vector<int>(3));
//		M[1][1] = a;
//		M[1][2] = b;
//		M[2][1] = c;
//		M[2][2] = d;
//	}
//
//	Mat operator*(Mat& a) {
//		Mat res(0, 0, 0, 0);
//		for (int i = 1; i <= 2; i++) {
//			for (int j = 1; j <= 2; j++) {
//				for (int k = 1; k <= 2; k++) {
//					res.M[i][j] += this->M[i][k] * a.M[k][j];
//				}
//			}
//		}
//		return res;
//	}
//
//	void print() {
//		for (int i = 1; i <= 2; i++) {
//			for (int j = 1; j <= 2; j++) {
//				cout << this->M[i][j] << ' ';
//			}
//			cout << endl;
//		}
//		cout << endl;
//	}
//
//};
//
//signed main() {
//	int x, y, n;
//	cin >> x >> y >> n;
//	Mat m(0, x, 1, y);
//	Mat b(0, 1, 1, 1);
//	Mat e(1, 0, 0, 1);
//	n--;
//	while (n) {
//		if (n & 1) {
//			e = b * e;
//		}
//		b = b * b;
//		n >>= 1;
//	}
//	m = e * m;
//	cout << m.M[1][2] << endl;
//	return 0;
//}



//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 52;
//vector<vector<int>> a(3, vector<int>(N));
//
//int main() {
//	string s;
//	cin >> s;
//	s = ' ' + s;
//	for (int i = 1; i < (int)s.size(); i++) {
//		int x = s[i] - '0';
//		x %= 3;
//		for (int j = 0; j <= 2; j++) {
//			a[j][i] = a[j][i - 1] + (j == x);
//		}
//		for (int j = 0; j <= 2; j++) {
//			a[(j + x) % 3][i] += a[j][i - 1];
//		}
//	}
//
//
//
//	cout << a[0][s.size() - 1];
//	return 0;
//}



//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n, k;
//	cin >> n >> k;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++) cin >> a[i];
//	map<int, int> mp;
//	for (int i = 0; i < k; i++) {
//		mp[a[i]]++;
//	}
//	vector<int> maxn;
//	cout << (*mp.begin()).first << ' ';
//	maxn.push_back((*mp.rbegin()).first);
//	for (int i = k; i < n; i++) {
//		mp[a[i - k]]--;
//		if (mp[a[i - k]] <= 0) mp.erase(a[i - k]);
//		mp[a[i]]++;
//		cout << (*mp.begin()).first << ' ';
//		maxn.push_back((*mp.rbegin()).first);
//	}
//	cout << endl;
//	for (int i : maxn) cout << i << ' ';
//	return 0;
//}


//#include <iostream>
//using namespace std;
//
//const int N = 1e8;
//int primes[N];
//bool vis[N];
//int cnt;
//
//
//void eular() {
//	vis[1] = 1;
//	for (int i = 2; i < N; i++) {
//		if (!vis[i]) primes[cnt++] = i;
//		for (int j = 0; primes[j] * i < N; j++) {
//			vis[i * primes[j]] = 1;
//			if (i % primes[j] == 0) break;
//		}
//	}
//}
//
//
//void aishi() {
//	vis[1] = 1;
//	for (int i = 2; i < N; i++) {
//		if (!vis[i]) {
//			primes[cnt++] = i;
//			for (int j = i + i; j < N; j += i) {
//				vis[j] = 1;
//			}
//		}
//	}
//}
//
//
//int main() {
//	eular();
////	aishi();
//	return 0;
//}


// P370 分段异或和
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//	int n, k;
//	cin >> n >> k;
//	vector<int> a(n + 1);
//	for (int i = 1; i <= n; i++) cin >> a[i];
//	vector<int> sum(n + 1);
//	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] ^ a[i];
//	vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
//	dp[1][1] = a[1];
//	for (int i = 2; i <= n; i++) {
//		for (int j = 1; j <= k; j++) {
//			if (j == 1) {
//				dp[i][j] = sum[i];
//			} else {
//				for (int x = i - 1; x >= 0; x--) {
//					if (dp[x][j - 1] == -1) break;
//					dp[i][j] = max(dp[i][j], (sum[i] ^ sum[x]) + dp[x][j - 1]);
//				}
//			}
//		}
//	}
//	cout << dp[n][k] << endl;
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//string s;
//int deep;
//
//int res(int ans) {
//	if (deep > (int)s.size()) return ans;
//	while (deep < (int)s.size()) {
//		if (isdigit(s[deep])) {
//			int j = deep;
//			int t = 0;
//			while (j < (int)s.size() && isdigit(s[j])) {
//				t = t * 10 + s[j] - '0';
//				j++;
//			}
//			ans += t;
//			deep = j;
//			continue;
//		}
//		if (s[deep] == '+') {
//			deep++;
//			return ans + res(0);
//		}
//		if (s[deep] == '-') {
//			deep++;
//			return ans - res(0);
//		}
//		if (s[deep] == '*') {
//			deep++;
//			return ans * res(0);
//		}
//		if (s[deep] == '/') {
//			deep++;
//			return ans / res(0);
//		}
//		if (s[deep] == '(') {
//			deep++;
//			ans += res(0);
//		}
//		if (s[deep] == ')') {
//			deep++;
//			return ans;
//		}
//	}
//	return ans;
//}
//
//int main() {
//	cin >> s;
//	cout << res(0);
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	string s;
//	while (cin >> s) {
//		if (s == "0") break;
//		s = s.substr(0, s.size() - 3);
//		int ans_mu = 1e9, ans_zi = 1e9;
//		for (unsigned i = 2; i < s.size(); i++) {
//			int x1 = (int)pow(10, i - 2);
//			int x2 = (int)pow(10, (int)s.size() - 2);
//			int mu = x2 - x1;
//			int y1;
//			if (i - 2 == 0) y1 = 0;
//			else y1 = stoi(s.substr(2, i - 2));
//			int y2 = stoi(s.substr(2, s.size() - 2));
//			int zi = y2 - y1;
//			int g = gcd(zi, mu);
//			mu /= g;
//			zi /= g;
////			cout << zi << ' ' << mu << endl;
//			if (mu < ans_mu) {
//				ans_zi = zi;
//				ans_mu = mu;
//			}
//		}
//		cout << ans_zi << '/' << ans_mu << endl;
//	}
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e6+5;
//int a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//int suan(int l, int r) {
//	int num = 0;
//	for (int i = l; i <= r; i++) {
//		num = num * 10 + a[i];
//	}
//	return num;
//}
//int main() {
//	int n, cnt = 0;
//	cin >> n;
//	do {
//		for (int i = 1; i < 8; i++) {
//			int a, b, c;
//			a = suan(0, i - 1);
//			for (int j = i + 1; j < 9; j++) {
//				b = suan(i, j - 1);
//				c = suan(j, 8);
//				if (!(b % c) && (n == a + b / c)) {
//					cnt++;
//				}
//			}
//		}
//	} while (next_permutation(a, a + 9));
//	cout << cnt << endl;
//	return 0;
//}




//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int n;
//		cin >> n;
//		string s;
//		cin >> s;
//		unordered_map<char, int> mp;
//		for (char c : s) mp[c]++;
//		if (mp.size() == 1) {
//			cout << 1 << endl;
//		} else {
//			int a = -1, b;
//			char a_c, b_c;
//			for (auto p : mp) {
//				if (a == -1) {
//					a = p.second;
//					a_c = p.first;
//				} else {
//					b = p.second;
//					b_c = p.first;
//				}
//			}
//			if (a == 1 && s[0] == a_c) {
//				cout << min((int)s.size(), 4) << endl;
//			} else if (b == 1 && s[0] == b_c) {
//				cout << min((int)s.size(), 4) << endl;
//			} else {
//				int x = mp[s[0]];
//				char c;
//				for (int i = 0; i < n; i++) {
//					if (s[0] == s[i]) x--;
//					else {
//						c = s[i];
//						break;
//					}
//				}
//				if (x == 0) {
//					cout << 1 + min(3, mp[c]) << endl;
//				} else {
//					cout << 2 << endl;
//				}
//			}
//		}
//	}
//	return 0;
//}


// 2025.5.27 数据结构上机实验报告代码
//#include <string>
//#include <cstring>
//#include <iostream>
//using namespace std;
//
//#define MAX_VERTEX 10
//struct MGraph {
//	int edges[MAX_VERTEX][MAX_VERTEX]; // 邻接矩阵
//	string vexs[MAX_VERTEX];          // 顶点信息
//	int vexNum, edgeNum;              // 顶点数、边数
//};
//void CreateMGraph(MGraph &G) {
//	G.vexNum = 7; // 顶点0-6
//	G.edgeNum = 12;
//	// 初始化边权矩阵
//	memset(G.edges, 0, sizeof(G.edges));
//	// 添加带权边（示例部分边）
//	G.edges[0][1] = 1;
//	G.edges[0][2] = 1;
//	G.edges[0][3] = 1;
//	G.edges[1][4] = 1;
//	G.edges[2][4] = 1;
//	G.edges[2][5] = 1;
//	G.edges[3][5] = 1;
//	G.edges[5][6] = 1;
//}
//
//void DFS(MGraph G, int v, bool visited[]) {
//	visited[v] = true;
//	cout << "访问顶点：" << v << endl;
//	for (int w = 0; w < G.vexNum; w++) {
//		if (G.edges[v][w] > 0 && !visited[w])
//			DFS(G, w, visited);
//	}
//}
//
//void GetDegree(MGraph G) {
//	for (int i = 0; i < G.vexNum; i++) {
//		int degree = 0;
//		for (int j = 0; j < G.vexNum; j++)
//			if (G.edges[i][j] > 0) degree++;
//		cout << "顶点" << i << "的度：" << degree << endl;
//	}
//}
//
//
//signed main() {
//	cout << "姓名：刘意" << endl;
//	MGraph g;
//	CreateMGraph(g);
//	bool vis[MAX_VERTEX];
//	memset(vis, 0, sizeof vis);
//	DFS(g, 0, vis);
//	cout << endl;
//	GetDegree(g);
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <string>
//#include <limits>
//#include <algorithm>
//
//using namespace std;
//
//const int INF = numeric_limits<int>::max();
//
//class CampusNavigator {
//private:
//	vector<string> vertices;   // 顶点集合
//	vector<vector<int>> adjMatrix; // 邻接矩阵
//
//	// 获取顶点索引
//	int getVertexIndex(const string& name) {
//		for (int i = 0; i < (int)vertices.size(); ++i) {
//			if (vertices[i] == name) return i;
//		}
//		return -1;
//	}
//
//public:
//	// 添加景点
//	void addVertex(const string& name) {
//		vertices.emplace_back(name);
//		// 扩展邻接矩阵
//		for (auto& row : adjMatrix) row.push_back(INF);
//		adjMatrix.push_back(vector<int>(vertices.size(), INF));
//	}
//
//	// 添加路径
//	void addPath(const string& from, const string& to, int weight) {
//		int i = getVertexIndex(from);
//		int j = getVertexIndex(to);
//		if (i != -1 && j != -1) {
//			adjMatrix[i][j] = weight;
//			adjMatrix[j][i] = weight; // 无向图
//		}
//	}
//
//	// Dijkstra算法求最短路径
//	void shortestPath(const string& start) {
//		int n = vertices.size();
//		vector<int> dist(n, INF);
//		vector<int> prev(n, -1);
//		vector<bool> visited(n, false);
//
//		int startIdx = getVertexIndex(start);
//		if (startIdx == -1) return;
//
//		dist[startIdx] = 0;
//
//		for (int i = 0; i < n; ++i) {
//			int u = -1;
//			int minDist = INF;
//			// 找最小距离顶点
//			for (int j = 0; j < n; ++j) {
//				if (!visited[j] && dist[j] < minDist) {
//					minDist = dist[j];
//					u = j;
//				}
//			}
//			if (u == -1) break;
//			visited[u] = true;
//
//			// 更新相邻顶点距离
//			for (int v = 0; v < n; ++v) {
//				if (adjMatrix[u][v] != INF && !visited[v]) {
//					if (dist[v] > dist[u] + adjMatrix[u][v]) {
//						dist[v] = dist[u] + adjMatrix[u][v];
//						prev[v] = u;
//					}
//				}
//			}
//		}
//
//		// 输出结果
//		cout << "从[" << start << "]出发到各景点的最短路径：" << endl;
//		for (int i = 0; i < n; ++i) {
//			if (i == startIdx) continue;
//			cout << " 到 " << vertices[i] << " 的最短距离: "
//			     << (dist[i] == INF ? "不可达" : to_string(dist[i]) + "米")
//			     << "，路径：";
//			printPath(startIdx, i, prev);
//			cout << endl;
//		}
//	}
//
//	// 递归打印路径
//	void printPath(int start, int end, const vector<int>& prev) {
//		if (end == start) {
//			cout << vertices[start];
//			return;
//		}
//		if (prev[end] == -1) {
//			cout << "无路径";
//			return;
//		}
//		printPath(start, prev[end], prev);
//		cout << " → " << vertices[end];
//	}
//};
//
//int main() {
//	CampusNavigator campus;
//
//	// 添加校园景点
//	campus.addVertex("南大门");
//	campus.addVertex("图书馆");
//	campus.addVertex("教学主楼");
//	campus.addVertex("实验楼");
//	campus.addVertex("体育馆");
//	campus.addVertex("学生食堂");
//	campus.addVertex("宿舍区");
//	campus.addVertex("运动场");
//	campus.addVertex("校史馆");
//
//	// 添加路径
//	campus.addPath("南大门", "图书馆", 200);
//	campus.addPath("南大门", "教学主楼", 300);
//	campus.addPath("图书馆", "教学主楼", 150);
//	campus.addPath("图书馆", "实验楼", 250);
//	campus.addPath("教学主楼", "实验楼", 100);
//	campus.addPath("教学主楼", "体育馆", 180);
//	campus.addPath("实验楼", "学生食堂", 200);
//	campus.addPath("体育馆", "学生食堂", 150);
//	campus.addPath("体育馆", "运动场", 120);
//	campus.addPath("学生食堂", "宿舍区", 80);
//	campus.addPath("宿舍区", "运动场", 160);
//	campus.addPath("宿舍区", "校史馆", 90);
//	campus.addPath("校史馆", "南大门", 400);
//
//	// 测试最短路径
//	campus.shortestPath("南大门");
//
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <climits>
//using namespace std;
//
//#define V 7 // 顶点数量
//
//// Prim算法实现
//void primMST(int graph[V][V]) {
//	int parent[V];    // 存储MST结构
//	int key[V];       // 存储顶点到树的距离
//	bool mstSet[V];   // 标记顶点是否已加入MST
//
//	// 初始化数组
//	for (int i = 0; i < V; i++) {
//		key[i] = INT_MAX;
//		mstSet[i] = false;
//	}
//
//	key[0] = 0;       // 从顶点0开始构建
//	parent[0] = -1;   // 根节点无父节点
//
//	for (int count = 0; count < V - 1; count++) {
//		// 找当前最小key值顶点
//		int u, min = INT_MAX;
//		for (int v = 0; v < V; v++)
//			if (!mstSet[v] && key[v] < min) {
//				min = key[v];
//				u = v;
//			}
//
//		mstSet[u] = true; // 加入生成树
//
//		// 更新相邻顶点key值
//		for (int v = 0; v < V; v++)
//			if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
//				parent[v] = u;
//				key[v] = graph[u][v];
//			}
//	}
//
//	// 输出结果
//	cout << "最小生成树结构：" << endl;
//	cout << "边 \t权值" << endl;
//	int total = 0;
//	for (int i = 1; i < V; i++) {
//		cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
//		total += graph[i][parent[i]];
//	}
//	cout << "总权值：" << total << endl;
//}
//
//int main() {
//	// 根据题目图示构造邻接矩阵
//	int graph[V][V] = {
//		{0, 8, 2, 5, 0, 0, 0},
//		{8, 0, 0, 4, 3, 0, 0},
//		{2, 0, 0, 6, 0, 7, 0},
//		{5, 4, 6, 0, 1, 9, 0},
//		{0, 3, 0, 1, 0, 5, 7},
//		{0, 0, 7, 9, 5, 0, 3},
//		{0, 0, 0, 0, 7, 3, 0}
//	};
//
//	primMST(graph);
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define fz0(i,n) for(int i=0;i<n;i++)
//#define fz1(i,n) for(int i=1;i<=n;i++)
//#define fd0(i,n) for(int i=n-1;i>=0;i--)
//#define fd1(i,n) for(int i=n;i>0;i--)
//#define FOR(i,x,y) for(int i=x;i<=y;i++)
//#define endl '\n'
//#define fi first
//#define se second
//
//#define int __int128
//#define MAXN 1000
//
//// 重载 << 输出运算符
//std::ostream& operator<<(std::ostream& os, __int128 value) {
//	// 处理零的情况
//	if (value == 0) return os << "0";
//
//	// 处理负数
//	bool is_negative = false;
//	if (value < 0) {
//		is_negative = true;
//		value = -value; // 转换为正数处理
//	}
//
//	// 数字转字符串
//	char buffer[41]; // 最多39位数字 + 符号 + 空字符
//	char* ptr = buffer + sizeof(buffer) - 1;
//	*ptr = '\0';
//
//	while (value > 0) {
//		*--ptr = '0' + static_cast<char>(value % 10);
//		value /= 10;
//	}
//
//	if (is_negative) *--ptr = '-';
//
//	return os << ptr;
//}
//
//std::istream& operator>>(std::istream& is, __int128& value) {
//	value = 0;
//
//	std::string s;
//	is >> s; // 读取为字符串
//
//	// 处理符号和前缀空格
//	size_t start = 0;
//	bool is_negative = false;
//
//	if (s[0] == '-') {
//		is_negative = true;
//		start = 1;
//	} else if (s[0] == '+') {
//		start = 1;
//	}
//
//	// 验证字符串内容（只允许数字）
//	if (s.find_first_not_of("0123456789", start) != std::string::npos) {
//		is.setstate(std::ios::failbit);
//		return is;
//	}
//
//	// 字符串转数字
//	for (size_t i = start; i < s.size(); ++i) {
//		if (value > (std::numeric_limits<__int128>::max() / 10)) {
//			is.setstate(std::ios::failbit);
//			return is;
//		}
//
//		value *= 10;
//		value += s[i] - '0';
//	}
//
//	if (is_negative) value = -value;
//
//	return is;
//}
//
//
//int he(int l, int r) {
//	return (l + r) * (r - l + 1) / 2;
//}
//int sum(int x) {
//	return x*(x + 1) * (x + 2) / 6;
//}
//int ceng(int x) {
//	int l = 1, r = x;
//	while (l < r) {
//		double mid = (l + r) / 2;
//		int ans = he(1, mid);
//		if (ans < x) l = mid + 1;
//		else r = mid;
//	}
//	return l;
//}
//void solve() {
//	int l, r;
//	cin >> l >> r;
//	int cl = ceng(l), cr = ceng(r);
//	int suml = he((l - he(1, cl - 1)), cl);
//	int sumr = he(1, (r - he(1, cr - 1)));
//	if (cl != cr) cout << suml + sumr + sum(cr - 1) - sum(cl) << endl;
//	else cout << he((l - he(1, cl - 1)), (r - he(1, cr - 1))) << endl;
//}
//signed main() {
//	IOS;
//	int T;
//	cin >> T;
//	while (T--) solve();
//	return 0;
//}





// 牛客题
//#include <bits/stdc++.h>
//using namespace std;
//using ll = long long;
//
//const int N = 3e5 + 10;
//
//struct Node {
//	int l, r;
//	ll m;
//};
//
//Node tr1[4 * N], tr2[4 * N];
//int a[N], n;
//
//void pushup(Node& root, const Node& left, const Node& right) {
//	root.m = min(left.m, right.m);
//}
//
//void build(Node tr[], int u, int l, int r, int mode) {
//	if (l == r) {
//		if (mode == 1)
//			tr[u] = {l, r, (ll)a[l] * l};
//		else
//			tr[u] = {l, r, (ll)a[l] * (n - l + 1)};
//	} else {
//		tr[u].l = l, tr[u].r = r;
//		int mid = (l + r) >> 1;
//		build(tr, u << 1, l, mid, mode);
//		build(tr, u << 1 | 1, mid + 1, r, mode);
//		pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
//	}
//}
//
//Node query(Node tr[], int u, int l, int r) {
//	if (l <= tr[u].l && tr[u].r <= r) {
//		return tr[u];
//	} else {
//		int mid = (tr[u].l + tr[u].r) >> 1;
//		if (mid >= r) return query(tr, u << 1, l, r);
//		else if (l > mid) return query(tr, u << 1 | 1, l, r);
//		else {
//			Node left = query(tr, u << 1, l, mid);
//			Node right = query(tr, u << 1 | 1, mid + 1, r);
//			Node res;
//			pushup(res, left, right);
//			return res;
//		}
//	}
//}
//
//signed main() {
//	cin >> n;
//	for (int i = 1; i <= n; i++) cin >> a[i];
//	build(tr1, 1, 1, n, 1);
//	build(tr2, 1, 1, n, 2);
//	unordered_map<int, int> mp;
//	int l = 1, r = 1;
//	ll ans = 1e18;
//	while (r <= n) {
//		while (r <= n && mp[a[r]] == 0) {
//			mp[a[r]] = r;
//			r++;
//		}
//		ll zuo = (l == 1 ? 0 : query(tr1, 1, l - 1, r).m);
//		ll you = (r == n + 1 ? 0 : query(tr2, 1, l - 1, r).m);
//		ans = min(ans, zuo + you);
//		for (; l <= mp[a[r]]; l++) {
//			mp[a[l]] = 0;
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}



// Trie树模板
//#include <bits/stdc++.h>
//using namespace std;
//
//// Trie树节点结构
//struct TrieNode {
//	unordered_map<char, TrieNode*> child;  // 子节点映射表：字符 -> 子节点指针
//	bool is_end;                           // 标记当前节点是否为单词结尾
//
//	TrieNode() : is_end(false) {}          // 构造函数：默认不是单词结尾
//};
//
//// Trie树类
//class Trie {
//private:
//	TrieNode* root;  // 根节点指针
//
//	// 辅助函数：查找给定前缀对应的节点
//	TrieNode* searchPrefix(const string& prefix) {
//		TrieNode* node = root;
//		for (char c : prefix) {
//			// 如果字符不在当前节点的子节点映射中，返回空指针
//			if (node->child.find(c) == node->child.end()) {
//				return nullptr;
//			}
//			node = node->child[c];  // 继续向下一个字符对应的节点移动
//		}
//		return node;  // 返回前缀最后一个字符对应的节点
//	}
//
//public:
//	// 构造函数：创建新的根节点
//	Trie() {
//		root = new TrieNode();
//	}
//
//	// 向Trie树中插入单词
//	void insert(const string& word) {
//		TrieNode* node = root;
//		for (char c : word) {
//			// 如果字符不存在，创建新的节点
//			if (node->child.find(c) == node->child.end()) {
//				node->child[c] = new TrieNode();
//			}
//			node = node->child[c];  // 移动到子节点
//		}
//		node->is_end = true;  // 标记单词结束
//	}
//
//	// 搜索完整单词
//	bool search(const string& word) {
//		TrieNode* node = searchPrefix(word);  // 查找单词对应的节点
//		// 节点存在且是单词结尾才算找到
//		return node != nullptr && node->is_end;
//	}
//
//	// 检查前缀是否存在
//	bool startsWith(const string& prefix) {
//		// 只要前缀对应的节点存在即可
//		return searchPrefix(prefix) != nullptr;
//	}
//};
//
//int main() {
//
//	return 0;
//}



// 高精度模板
//#include <bits/stdc++.h>
//using namespace std;
//
//class BigInt {
//private:
//	std::vector<int> digits;  // 存储数字的容器（逆序存储）
//	bool isNegative;          // 符号标记
//
//	// 辅助函数：去除前导零
//	void trim() {
//		while (!digits.empty() && digits.back() == 0) {
//			digits.pop_back();
//		}
//		if (digits.empty()) {
//			isNegative = false;
//		}
//	}
//
//public:
//	// 构造函数
//	BigInt() : isNegative(false) {}
//
//	BigInt(const std::string& s) {
//		if (s.empty()) return;
//
//		int start = 0;
//		if (s[0] == '-') {
//			isNegative = true;
//			start = 1;
//		} else {
//			isNegative = false;
//		}
//
//		for (int i = s.length() - 1; i >= start; --i) {
//			if (!isdigit(s[i])) throw std::invalid_argument("Invalid number");
//			digits.push_back(s[i] - '0');
//		}
//		trim();
//	}
//
//	BigInt(long long num) {
//		if (num < 0) {
//			isNegative = true;
//			num = -num;
//		} else {
//			isNegative = false;
//		}
//
//		if (num == 0) digits.push_back(0);
//
//		while (num > 0) {
//			digits.push_back(num % 10);
//			num /= 10;
//		}
//	}
//
//	// 比较运算符重载
//	bool operator<(const BigInt& rhs) const {
//		if (isNegative != rhs.isNegative) return isNegative;
//		if (digits.size() != rhs.digits.size())
//			return isNegative ^ (digits.size() < rhs.digits.size());
//
//		for (int i = digits.size() - 1; i >= 0; --i) {
//			if (digits[i] != rhs.digits[i])
//				return isNegative ^ (digits[i] < rhs.digits[i]);
//		}
//		return false;
//	}
//
//	bool operator==(const BigInt& rhs) const {
//		return isNegative == rhs.isNegative && digits == rhs.digits;
//	}
//
//	// 算术运算符重载
//	BigInt operator+(const BigInt& rhs) const {
//		if (isNegative == rhs.isNegative) {
//			BigInt result = add(*this, rhs);
//			result.isNegative = isNegative;
//			return result;
//		}
//		if (absLess(*this, rhs)) {
//			BigInt result = subtract(rhs, *this);
//			result.isNegative = rhs.isNegative;
//			return result;
//		} else {
//			BigInt result = subtract(*this, rhs);
//			result.isNegative = isNegative;
//			return result;
//		}
//	}
//
//	BigInt operator-(const BigInt& rhs) const {
//		BigInt temp = rhs;
//		temp.isNegative = !temp.isNegative;
//		return *this + temp;
//	}
//
//	BigInt operator*(const BigInt& rhs) const {
//		BigInt result = multiply(*this, rhs);
//		result.isNegative = isNegative ^ rhs.isNegative;
//		result.trim();
//		return result;
//	}
//
//	BigInt operator/(const BigInt& rhs) const {
//		if (rhs == BigInt(0)) throw std::runtime_error("Division by zero");
//		BigInt result, remainder;
//		divide(*this, rhs, result, remainder);
//		result.isNegative = isNegative ^ rhs.isNegative;
//		result.trim();
//		return result;
//	}
//
//	BigInt operator%(const BigInt& rhs) const {
//		if (rhs == BigInt(0)) throw std::runtime_error("Modulo by zero");
//		BigInt result, remainder;
//		divide(*this, rhs, result, remainder);
//		remainder.isNegative = isNegative;
//		remainder.trim();
//		return remainder;
//	}
//
//private:
//	/* 以下为实现核心算法的私有方法 */
//
//	// 加法核心算法
//	static BigInt add(const BigInt& a, const BigInt& b) {
//		BigInt result;
//		size_t maxSize = std::max(a.digits.size(), b.digits.size());
//		int carry = 0;
//
//		for (size_t i = 0; i < maxSize || carry; ++i) {
//			int sum = carry;
//			if (i < a.digits.size()) sum += a.digits[i];
//			if (i < b.digits.size()) sum += b.digits[i];
//			result.digits.push_back(sum % 10);
//			carry = sum / 10;
//		}
//		return result;
//	}
//
//	// 比较绝对值大小
//	static bool absLess(const BigInt& a, const BigInt& b) {
//		if (a.digits.size() != b.digits.size())
//			return a.digits.size() < b.digits.size();
//		for (int i = a.digits.size() - 1; i >= 0; --i) {
//			if (a.digits[i] != b.digits[i])
//				return a.digits[i] < b.digits[i];
//		}
//		return false;
//	}
//
//	// 减法核心算法（a必须绝对值大于等于b）
//	static BigInt subtract(const BigInt& a, const BigInt& b) {
//		BigInt result;
//		int borrow = 0;
//
//		for (size_t i = 0; i < a.digits.size(); ++i) {
//			int diff = a.digits[i] - borrow;
//			if (i < b.digits.size()) diff -= b.digits[i];
//
//			if (diff < 0) {
//				diff += 10;
//				borrow = 1;
//			} else {
//				borrow = 0;
//			}
//			result.digits.push_back(diff);
//		}
//		result.trim();
//		return result;
//	}
//
//	// 乘法核心算法
//	static BigInt multiply(const BigInt& a, const BigInt& b) {
//		BigInt result;
//		result.digits.resize(a.digits.size() + b.digits.size(), 0);
//
//		for (size_t i = 0; i < a.digits.size(); ++i) {
//			int carry = 0;
//			for (size_t j = 0; j < b.digits.size() || carry; ++j) {
//				long long product = result.digits[i + j] + carry;
//				if (j < b.digits.size()) product += a.digits[i] * b.digits[j];
//				result.digits[i + j] = product % 10;
//				carry = product / 10;
//			}
//		}
//		result.trim();
//		return result;
//	}
//
//	// 除法核心算法（返回商和余数）
//	static void divide(const BigInt& dividend, const BigInt& divisor,
//		BigInt& quotient, BigInt& remainder) {
//			if (divisor == BigInt(0)) throw std::runtime_error("Division by zero");
//
//			BigInt absDividend = dividend;
//			absDividend.isNegative = false;
//			BigInt absDivisor = divisor;
//			absDivisor.isNegative = false;
//
//			quotient.digits.clear();
//			remainder = absDividend;
//
//			if (absLess(absDividend, absDivisor)) {
//				quotient = BigInt(0);
//				return;
//			}
//
//			BigInt current;
//			for (int i = absDividend.digits.size() - 1; i >= 0; --i) {
//				current.digits.insert(current.digits.begin(), absDividend.digits[i]);
//				current.trim();
//
//				int count = 0;
//				while (!absLess(current, absDivisor)) {
//					current = subtract(current, absDivisor);
//					++count;
//				}
//				quotient.digits.insert(quotient.digits.begin(), count);
//			}
//			remainder = current;
//			quotient.trim();
//		}
//
//public:
//	// 输出运算符重载
//	friend std::ostream& operator<<(std::ostream& os, const BigInt& num) {
//		if (num.isNegative && !num.digits.empty()) os << '-';
//		for (auto it = num.digits.rbegin(); it != num.digits.rend(); ++it) {
//			os << *it;
//		}
//		if (num.digits.empty()) os << '0';
//		return os;
//	}
//};
//
//
//int main() {
//	string a, b;
//	cin >> a >> b;
//	BigInt a_(a), b_(b);
//	cout << a_ + b_ << endl;
//	return 0;
//}



// 2025蓝桥杯国赛 TLE
//#include <bits/stdc++.h>
//using namespace std;
//
//struct node {
//	int l, r;
//	string s;
//};
//
//string s;
//vector<node> tr;
//
//void pushup(node& rt, node& left, node& right) {
//	unordered_map<char, bool> vis;
//	for (char c : left.s) {
//		if (!vis[c]) {
//			rt.s += c;
//			vis[c] = 1;
//		}
//	}
//	for (char c : right.s) {
//		if (!vis[c]) {
//			rt.s += c;
//			vis[c] = 1;
//		}
//	}
//}
//
//void build(int u, int l, int r) {
//	if (l == r) {
//		tr[u].l = l, tr[u].r = r;
//		tr[u].s = s[l];
//	} else {
//		tr[u].l = l, tr[u].r = r;
//		int mid = (l + r) >> 1;
//		build(u << 1, l, mid);
//		build(u << 1 | 1, mid + 1, r);
//		pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
//	}
//}
//
//node query(int u, int l, int r) {
//	if (l <= tr[u].l && tr[u].r <= r) {
//		return tr[u];
//	} else {
//		int mid = (tr[u].l + tr[u].r) >> 1;
//		if (r <= mid) return query(u << 1, l, r);
//		else if (l > mid) return query(u << 1 | 1, l, r);
//		else {
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
//	cin >> s;
//	s = ' ' + s;
//	int n = s.size() - 1;
//	tr.resize(4 * n + 4);
//	build(1, 1, n);
//	int m;
//	cin >> m;
//	while (m--) {
//		int l1, r1, l2, r2;
//		cin >> l1 >> r1 >> l2 >> r2;
//		string q1 = query(1, l1, r1).s;
//		string q2 = query(1, l2, r2).s;
//		int ans = abs((int)q1.size() - (int)q2.size());
//		int x = min((int)q1.size(), (int)q2.size());
//		for (int i = 0; i < x; i++) ans += (q1[i] != q2[i]);
//		cout << ans << endl;
//	}
//	return 0;
//}

//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//	int T;
//	cin >> T;
//	while (T--) {
//		int a[101];
//		memset(a, 0, sizeof a);
//		int n;
//		cin >> n;
//		for (int i = 1; i <= n; i++) {
//			int x;
//			cin >> x;
//			a[x]++;
//		}
//		bool is_yes = false;
//		for (int i = 2; i <= 100; i++) {
//			if (a[i] >= 2) {
//				is_yes = true;
//				break;
//			}
//		}
//		if (is_yes) cout << "YES" << endl;
//		else cout << "NO" << endl;
//	}
//	return 0;
//}



