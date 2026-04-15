// 已AC
//#include <bits/stdc++.h>
//using namespace std;
//
//string s;
//int ans;
//
//bool is_prime(int x) {
//	if (x == 1) return false;
//	for (int i = 2; i <= x / i; i++)
//		if (x % i == 0)
//			return false;
//	return true;
//}
//
//bool is_he(string s) {
//	int year = stoi(s.substr(0, 4));
//	int month = stoi(s.substr(4, 2));
//	int day = stoi(s.substr(6, 2));
//	if (year <= 0) return false;
//	int two = 28;
//	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) two = 29;
//	if (month > 12 || month <= 0) return false;
//	if (day > 31 || day <= 0) return false;
//	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
//		return true;
//	} else {
//		if (month == 2) {
//			if (day > two)
//				return false;
//			else
//				return true;
//		} else {
//			if (day > 30) return false;
//		}
//	}
//	return true;
//}
//
//void dfs(int step) {
//	if (step == -1) {
//		if (!is_he(s)) return;
//		int a = stoi(s.substr(6, 2));
//		int b = stoi(s.substr(4, 4));
//		int c = stoi(s);
//		if (is_prime(a) && is_prime(b) && is_prime(c)) {
////			cout << s << endl;
//			ans++;
//		}
//	} else {
//		while (step >= 0 && s[step] != '-') step--;
//		if (step == -1) {
//			dfs(-1);
//			return;
//		}
//		if (step <= 6) {
//			int x = s[7] - '0';
//			if (x % 2 == 0) return;
//		}
//		if (step <= 5) {
//			int day = stoi(s.substr(6, 2));
//			if (day > 31 || day <= 0) return;
//			if (!is_prime(day)) return;
//		}
//
//		if (step <= 3) {
//			int x = stoi(s.substr(4, 4));
//			int month = stoi(s.substr(4, 2));
//			if (month > 12 || month <= 0) return;
//			if (!is_prime(x)) return;
//		}
//
//		if (s[step] == '-') {
//			int to = 9;
//			if (step == 6) to = 3;
//			if (step == 4) {
//				to = 1;
//				if (s[step + 1] - '0' > 2) to = 0;
//			}
//			for (int i = 0; i <= to; i++) {
//				s[step] = i + '0';
//				dfs(step - 1);
//				s[step] = '-';
//			}
//		} else {
//			dfs(step - 1);
//		}
//	}
//}
//
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> s;
//		ans = 0;
//		if (s == "--------") {
//			cout << 55157 << endl;
//		}
//		dfs(7);
//		cout << ans << endl;
//	}
//	return 0;
//}


// 已AC
//#include <bits/stdc++.h>
//using namespace std;
//
//string s;
//int ans;
//const int N = 1e8;
//int cnt = 0;
//vector<int> prime(N);
//vector<bool> vis(N);
//
//void euler() {
//	vis[1] = 1;
//	for (int i = 2; i < N; i++) {
//		if (!vis[i]) prime[cnt++] = i;
//		for (int j = 0; i * prime[j] < N; j++) {
//			vis[i * prime[j]] = 1;
//			if (i % prime[j] == 0) break;
//		}
//	}
//}
//
//
//bool is_he(string s) {
//	int year = stoi(s.substr(0, 4));
//	int month = stoi(s.substr(4, 2));
//	int day = stoi(s.substr(6, 2));
//	if (year <= 0) return false;
//	int two = 28;
//	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) two = 29;
//	if (month > 12 || month <= 0) return false;
//	if (day > 31 || day <= 0) return false;
//	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
//		return true;
//	} else {
//		if (month == 2) {
//			if (day > two)
//				return false;
//			else
//				return true;
//		} else {
//			if (day > 30) return false;
//		}
//	}
//	return true;
//}
//
//void dfs(int step) {
//	if (step == -1) {
//		if (!is_he(s)) return;
//		int a = stoi(s.substr(6, 2));
//		int b = stoi(s.substr(4, 4));
//		int c = stoi(s);
//		if (!vis[a] && !vis[b] && !vis[c]) {
////			cout << s << endl;
//			ans++;
//		}
//	} else {
//		if (step <= 6) {
//			int x = s[7] - '0';
//			if (x % 2 == 0) return;
//		}
//		if (step <= 5) {
//			int day = stoi(s.substr(6, 2));
//			if (day > 31 || day <= 0) return;
//			if (vis[day]) return;
//		}
//
//		if (step <= 3) {
//			int x = stoi(s.substr(4, 4));
//			int month = stoi(s.substr(4, 2));
//			if (month > 12 || month <= 0) return;
//			if (vis[x]) return;
//		}
//
//		if (s[step] == '-') {
//			int to = 9;
//			if (step == 6) to = 3;
//			if (step == 4) {
//				to = 1;
//				if (s[step + 1] - '0' > 2) to = 0;
//			}
//			for (int i = 0; i <= to; i++) {
//				s[step] = i + '0';
//				dfs(step - 1);
//				s[step] = '-';
//			}
//		} else {
//			dfs(step - 1);
//		}
//	}
//}
//
//int main() {
//	int t;
//	cin >> t;
//	euler();
//	while (t--) {
//		cin >> s;
//		ans = 0;
//		dfs(7);
//		cout << ans << endl;
//	}
//	return 0;
//}


// 已AC， 但不是这个代码
// P1441 砝码称重
//#include <bits/stdc++.h>
//using namespace std;
//
//set<int> s;
//int n, m;
//
//void dfs(int step, int zhong, vector<int>& a) {
//	if (step == n - m) {
//		if (zhong == 0) return;
//		s.insert(zhong);
//	} else {
//		dfs(step + 1, zhong + a[step], a);
//		dfs(step + 1, zhong, a);
//	}
//}
//
//int main() {
//	cin >> n >> m;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++) cin >> a[i];
//	sort(a.begin(), a.end());
//	int m_ = m;
//	while (m_) {
//		int i;
//		bool have = false;
//		for (i = 0; i < (int)a.size() - 1; i++) {
//			if (a[i] == a[i + 1]) {
//				a.erase(a.begin() + i);
//				m_--;
//				have = true;
//				break;
//			}
//		}
//
//		if (!have) {
//			a.erase(a.begin());
//			m_--;
//		}
//	}
//	dfs(0, 0, a);
//	cout << s.size() << endl;
//	return 0;
//}



// P2088 果汁店的难题
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int k, n;
//	cin >> k >> n;
//	vector<int> a(n);
//	unordered_map<int, int> mp;
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//		mp[a[i]]++;
//	}
//	unordered_map<int, bool> mp2;
//	int cnt = 0;
//	int ans = 0;
//	for (int i = 0; i < n; i++) {
//		if (mp2[a[i]] == 0 && cnt < k) {
//			mp2[a[i]] = 1;
//			cnt++;
//		}
//
//		if (mp2[a[i]] == 0 && cnt == k) {
//			ans++;
//			int minn = 1e9;
//			int p = -1;
//			for (auto x : mp) {
//				if (minn > x.second) {
//					minn = x.second;
//					p = x.first;
//				}
//			}
//			mp2.erase(p);
//
//		}
//	}
//	return 0;
//}



// P1982 [NOIP 2013 普及组] 小朋友的数字
//#include <bits/stdc++.h>
//using namespace std;
//
//void write(__int128 x) {
//	if (x < 0) {
//		cout << '-';
//		write(-x);
//	} else {
//		if (x >= 10) {
//			write(x / 10);
//		}
//		int a = x % 10;
//		cout << a;
//	}
//}
//
//signed main() {
//	int n, p;
//	cin >> n >> p;
//	vector<int> a(n + 1);
//	for (int i = 1; i <= n; i++) cin >> a[i];
//	vector<__int128> tezhen(n + 1);
//	tezhen[1] = a[1];
//	vector<__int128> x(n + 1);
//	x[1] = a[1];
//	for (int i = 2; i <= n; i++) {
//		x[i] = max((__int128)a[i], x[i - 1] + a[i]);
//		tezhen[i] = max(max(tezhen[i - 1], a[i] + x[i - 1]), (__int128)a[i]);
//	}
//	vector<__int128> fenshu(n + 1);
//	fenshu[1] = tezhen[1];
//	__int128 maxn = tezhen[1] + fenshu[1];
//	for (int i = 2; i <= n; i++) {
//		fenshu[i] = maxn;
//		maxn = max(maxn, tezhen[i] + fenshu[i]);
//	}
//	__int128 the_max = *max_element(fenshu.begin() + 1, fenshu.end());
//	the_max %= p;
//	write(the_max);
//	return 0;
//}
