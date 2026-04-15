// 2025.4.21   The 2022 ICPC Asia Xian Regional Contest
// C Clone Ranran  AC
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//	int t;
//	cin >> t;
//	int a, b, c;
//	while (t--) {
//		int ans = 1e18;
//		cin >> a >> b >> c;
//		int ren = 1;
//		for (int i = 0; ren <= c * 2; i++) {
//			ans = min((c + ren - 1) / ren * b + i * a, ans);
//			ren *= 2;
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}



// D Contests   不会
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//
//	}
//	return 0;
//}


// G Perfect Word    AC
//#include <bits/stdc++.h>
//using namespace std;
//
//bool cmp(string& s1, string& s2) {
//	if (s1.size() == s2.size()) {
//		return s1 < s2;
//	} else {
//		return s1.size() < s2.size();
//	}
//}
//
//int main() {
//	int n;
//	cin >> n;
//	vector<string> a(n);
//	for (int i = 0; i < n; i++) cin >> a[i];
//	sort(a.begin(), a.end(), cmp);
//	unordered_map<string, bool> mp;
//	int ans = 0;
//	for (int i = 0; i < n; i++) {
//		if (a[i].length() == 1) {
//			mp[a[i]] = 1;
//			ans = max(ans, (int)a[i].length());
//		} else {
//			int n = a[i].size();
//			if (mp[a[i].substr(0, n - 1)] && mp[a[i].substr(1, n - 1)]) {
//				mp[a[i]] = 1;
//				ans = max(ans, n);
//			}
//		}
//	}
//	cout << ans;
//	return 0;
//}



// E. Find Maximum   WA
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//int f(int x) {
//	if (x == 0) return 1;
//	if (x % 3 == 0) return f(x / 3) + 1;
//	else return f(x - 1) + 1;
//}
//
//__int128 a(int n) {
//	return ((__int128)pow(3, n) + 1) / 2;
//}
//
//signed main() {
//	int n;
//	cin >> n;
//	int l, r;
//	while (n--) {
//		cin >> l >> r;
//		if (r <= 2) {
//			int ans = 0;
//			for (int i = l; i <= r; i++) {
//				ans = max(ans, f(r));
//			}
//			cout << ans << endl;
//		} else {
//			int i;
//			for (i = 2; a(i) <= r; i++) {}
////			int x = a(i - 1);
//			int shang = 2 * i;
//			int ans = 0;
//			bool is_found = false;
//			for (int i = l; i <= r; i++) {
//				int fi = f(i);
//				if (fi == shang) {
//					cout << shang << endl;
//					is_found = true;
//					break;
//				} else {
//					ans = max(ans, fi);
//				}
//			}
//			if (!is_found) {
//				cout << ans << endl;
//			}
//		}
//	}
//	return 0;
//}



// 2025.4.22 补题
// E. Find Maximum
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//int sum[100];
//
//void init() {
//	sum[0] = 1;
//	for (int i = 1; i; i++) {
//		sum[i] = 3 * sum[i - 1];
//		if (sum[i] > 1e18) break;
//	}
//}
//
//int get(int len, int r) {
//	int res = 1;
//	int L = sum[len - 1];
//	for (int i = 0; i <= len; i++) {
//		int to = 2 - L / sum[i] % 3;
//		for (int j = 1; j <= to; j++) {
//			if (L + sum[i] <= r) {
//				L += sum[i];
//				res++;
//			}
//		}
//	}
//	return res;
//}
//
//signed main() {
//	init();
//	int t;
//	cin >> t;
//	int l, r;
//	while (t--) {
//		cin >> l >> r;
//		int len = 0, ans = 0, cnt = 0;
//		int L = l;
//		while (L) {
//			cnt += L % 3;
//			L /= 3;
//			len++;
//		}
//		len = max(len, 1LL);
//		ans = max(ans, cnt + len);
//		L = l;
//		for (int i = 0; i < len; i++) {
//			int to = 2 - L / sum[i] % 3;
//			for (int j = 1; j <= to; j++) {
//				if (L + sum[i] <= r) {
//					L += sum[i];
//					ans++;
//				}
//			}
//		}
//
//		for (int i = len + 1; i; i++) {
//			if (sum[i - 1] > r || sum[i - 1] == 0) break;
//			ans = max(ans, get(i, r) + i);
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}



// Tree
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 1e6 + 10;
//int du[N], fa[N];
//
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int n;
//		cin >> n;
//		du[1] = 1;
//		for (int i = 2; i <= n; i++) {
//			int p;
//			cin >> p;
//			du[i]++;
//			du[p]++;
//			fa[i] = p;
//		}
//		queue<int> q;
//		for (int i = 1; i <= n; i++) {
//			if (du[i] == 1) {
//				q.push(i);
//			}
//		}
//		int ans = q.size();
//		int cnt = 1;
//		while (!q.empty()) {
//			int s = q.size();
//			for (int i = 1; i <= s; i++) {
//				int the = q.front();
//				q.pop();
//				du[fa[the]]--;
//				if (du[fa[the]] == 1) {
//					q.push(fa[the]);
//				}
//			}
//			ans = min(ans, cnt + (int)q.size());
//			cnt++;
//		}
//		cout << ans << endl;
//		memset(du, 0, sizeof(int) * (n + 1));
//	}
//	return 0;
//}



// 2025.5.7 牛客小白月赛115
// A
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	string a, b, c;
//	cin >> a >> b >> c;
//	string s = a + b + c;
//	if (s == "-101" || s == "010" || s == "10-1" || s == "0-10") {
//		cout << "YES" << endl;
//	} else {
//		cout << "NO" << endl;
//	}
//	return 0;
//}


// B
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	vector<int> a(n);
//	unordered_map<int, int> mp;
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//		mp[a[i]]++;
//	}
//	sort(a.begin(), a.end());
//	int ans = 0;
//	for (int i = 0; i < n;) {
//		if (n - (i + mp[a[i]]) >= m - mp[a[i]]) {
//			ans = min(m, max(ans, mp[a[i]]));
//		}
//		i += mp[a[i]];
//	}
//	cout << ans << endl;
//	return 0;
//}



// C
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 120;
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
//	int n;
//	cin >> n;
//	vector<int> a(n + 1);
//	for (int i = 1; i <= n; i++) cin >> a[i];
//	vector<int> b(n + 1);
//	for (int i = n; i >= 1; i--) {
//		b[i] = sum(100) - sum(a[i]);
//		add(a[i], 1);
//	}
//	int q, v;
//	cin >> q >> v;
//	int ans = 1e9;
//	int cnt = 0;
//	for (int i = 1; i <= n; i++) {
//		ans = min(ans, cnt + b[i]);
//		if (a[i] > v) cnt++;
//	}
//	cout << ans << endl;
//	return 0;
//}



// D  WA
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
//		unordered_map<int, int> mp;
//		for (int i = 0; i < n; i++) {
//			cin >> a[i];
//			mp[a[i]]++;
//		}
//		bool is_yes = true;
//		sort(a.begin(), a.end());
//		for (int i = 0; i < n; i++) {
//			if (mp[a[i]] >= 3 || mp[a[i]] + mp[a[i] + 1] + mp[a[i] + 2] >= 6) {
//				is_yes = false;
//				break;
//			}
//		}
//		if (is_yes) {
//			for (int i = 0; i < n; i++) {
//				if (a[i] - 2 * i == 1) {
//					if (mp[a[i] + 1] != 0) {
//						is_yes = false;
//						break;
//					}
//				} else if (a[i] - 2 * i < 1) {
//					is_yes = false;
//					break;
//				} else if (a[i] - 2 * i > 1) {
//
//				}
//			}
//
//			if (is_yes) cout << "YES" << endl;
//			else cout << "NO" << endl;
//		} else {
//			cout << "NO" << endl;
//		}
//
//	}
//	return 0;
//}

// 2025.5.8补题
// D
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<string> a(n);
//	for (int i = 0; i < n; i++) cin >> a[i];
//	int len = 0;
//	for (int i = 0; i < n; i++) len = __gcd(len, (int)a[i].size());
//	vector<unordered_map<char, int>> mp(len);
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < (int)a[i].size(); j++) {
//			mp[j % len][a[i][j]]++;
//		}
//	}
//	int ans = 0;
//	for (int i = 0; i < len; i++) {
//		int sum = 0, mx = 0;
//		for (int j = 0; j < 26; j++) {
//			sum += mp[i][j + 'a'];
//			mx = max(mx, mp[i][j + 'a']);
//		}
//		ans += sum - mx;
//	}
//	cout << ans << endl;
//	return 0;
//}


// E
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
//		map<int, bool> vis;
//		sort(a.begin(), a.end());
//		bool is_yes = true;
//		for (int i = n - 1; i >= 0; i--) {
//			if (vis.find(a[i] + 1) == vis.end()) vis[a[i] + 1] = 1;
//			else if (vis.find(a[i] - 1) == vis.end()) vis[a[i] - 1] = 1;
//			else {
//				is_yes = false;
//				break;
//			}
//		}
//		if (is_yes) {
//			int sum = 0, now = 0;
//			for (auto p : vis) {
//				sum += p.first - now;
//				now = p.first;
//				sum -= 2;
//				if (sum < 0) {
//					is_yes = false;
//					break;
//				}
//			}
//			if (is_yes) cout << "YES" << endl;
//			else cout << "NO" << endl;
//		} else {
//			cout << "NO" << endl;
//		}
//	}
//	return 0;
//}



// 2025.5.10
// 牛客练习赛137
// A
//#include <bits/stdc++.h>
//using namespace std;
//
//int n;
//vector<int> a(6);
//vector<bool> vis(6);
//
//void dfs(int deep) {
//	if (deep == n) {
//		for (int i = 0; i < n; i++) {
//			cout << (char)(a[i] + 'A') << "+ "[i == n - 1];
//		}
//		cout << "Problem" << endl;
//	} else {
//		for (int i = 0; i < n; i++) {
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


// B  不会了
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 1e5 + 10;
//int n, m;
//vector<int> g[N];
//bool x[N];
//
//void dfs(int u, int fa) {
//	if (x[u]) cout << u << ' ' << fa << endl;
//	for (int i : g[u])
//		if (i != fa)
//			dfs(i, u);
//}
//
//signed main() {
//	cin >> n >> m;
//	for (int i = 0; i < n - 1; i++) {
//		int u, v;
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}
//	int y;
//	for (int i = 0; i < m; i++) {
//		cin >> y;
//		x[y] = 1;
//	}
//	x[y] = 0;
//	cout << m - 1 << endl;
//	dfs(y, -1);
//	return 0;
//}




// 2024 (ICPC) Jiangxi Provincial Contest -- Official Contest
// 2025.5.16
// A
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//	int a, b, c;
//	cin >> a >> b >> c;
//	cout << a + b + c << endl;
//	return 0;
//}



// G
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int n;
//		cin >> n;
//		int sum = 0;
//		while (n--) {
//			int a;
//			cin >> a;
//			char b;
//			cin >> b;
//			if (b == 'A') {
//				sum = (10 * a + sum) % 5;
//			} else {
//				int c = b - '0';
//				sum = (c * a + sum) % 5;
//			}
//		}
//		if (sum == 0) cout << "Yes" << endl;
//		else cout << "No" << endl;
//	}
//	return 0;
//}



// C
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n, s;
//	cin >> n >> s;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++) cin >> a[i];
//	int sum = 0;
//	for (int i = 0; i < n; i++) sum += a[i];
//	if (sum == s) cout << n << endl;
//	else cout << n - 1 << endl;
//	return 0;
//}



// J
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int t;
//	cin >> t;
//	string the = "1s9s1p9p1m9m1z2z3z4z5z6z7z";
//	while (t--) {
//		string s;
//		cin >> s;
//		unordered_map<string, int> mp;
//		for (int i = 0; i < (int)s.size(); i += 2) mp[s.substr(i, 2)]++;
//		bool is_h = true;
//		for (int i = 0; i < (int)the.size(); i += 2) {
//			string temp = the.substr(i, 2);
//			if (!(mp[temp] == 1 || mp[temp] == 2)) {
//				is_h = false;
//				break;
//			}
//		}
//		if (is_h) cout << "Thirteen Orphans" << endl;
//		else {
//			bool is_p = true;
//			for (int i = 0; i < (int)s.size(); i += 2) {
//				string temp = s.substr(i, 2);
//				if (mp[temp] != 2) {
//					is_p = false;
//					break;
//				}
//			}
//			if (is_p) cout << "7 Pairs" << endl;
//			else cout << "Otherwise" << endl;
//		}
//	}
//	return 0;
//}




// H
//#include <bits/stdc++.h>
//using namespace std;
//#define endl '\n'
//#define int long long
//
//int su(int i, int j, int x, int y, const vector<vector<int>>& sum) {
//	return sum[x][y] - sum[i - 1][y] - sum[x][j - 1] + sum[i - 1][j - 1];
//}
//
//signed main() {
//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	int n, m, k, l;
//	cin >> n >> m >> k >> l;
//	vector<vector<int>> a(n + 1, vector<int>(m + 1));
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= m; j++)
//			cin >> a[i][j];
//	vector<vector<int>> sum(n + 1, vector<int>(m + 1));
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			sum[i][j] = a[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
//		}
//	}
//
//	int ans = 0;
//	for (int i = 1; i <= k; i++) {
//		for (int j = 1; j <= l; j++) {
//			ans += abs(su(i, j, i + n - k, j + m - l, sum));
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}




// 2025.5.28
// 百度之星

// https://www.matiji.net/exam/brushquestion/1/4498/F16DA07A4D99E21DFFEF46BD18FF68AD
//#include<bits/stdc++.h>
//using namespace std;
//
//int main( ) {
//	int n, b;
//	cin >> n >> b;
//	vector<pair<int, int>> a(n);
//	for (int i = 0; i < n; i++) {
//		cin >> a[i].first >> a[i].second;
//		a[i].first += a[i].second;
//	}
//	sort(a.begin(), a.end());
//	int max_ = -1;
//	int ans = 0;
//	bool isyong = false;
//	for (int i = 0; i < n; i++) {
//		if (b >= a[i].first) {
//			b -= a[i].first;
//			max_ = max(max_, a[i].first - a[i].second);
//			ans++;
//		} else {
//			if (!isyong) {
//				isyong = true;
//				if ((a[i].first - a[i].second) / 2 > max_ / 2) {
//					b += (a[i].first - a[i].second) / 2;
//					if (b >= a[i].first) {
//						ans++;
//						b -= a[i].first;
//					}
//				} else {
//					b += max_ / 2;
//					if (b >= a[i].first) {
//						ans++;
//						b -= a[i].first;
//					}
//				}
//			}
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}


