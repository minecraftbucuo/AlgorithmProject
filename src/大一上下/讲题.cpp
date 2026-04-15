//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int ans = 0;
//	for (int i = 1; i <= 50; i++) {
//		if (i <= 7) ans += 43;
//		else ans += 50 - i;
//	}
//	cout << ans << endl;
//	return 0;
//}



//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//	int x = 15;
//	int y = 17;
//	while (x % (2 * 343720) != 0 || y % (2 * 233333) != 0) {
//		x += 15;
//		y += 17;
//	}
//	printf("%.2Lf", sqrtl(x*x + y*y));
//	return 0;
//}



//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++) cin >> a[i];
//	map<int, int> mp;
//	for (int i = 0; i < n; i++) {
//		for (int j = 1; j <= a[i] / j; j++) {
//			if (a[i] % j == 0) {
//				mp[j]++;
//				if (j != a[i] / j) mp[a[i] / j]++;
//			}
//		}
//	}
//	int x = -1;
//	for (auto i = mp.end()--; i != mp.begin()--; i--) {
//		if (i->second >= 3) {
//			x = i->first;
//			break;
//		}
//	}
//	int cnt = 0;
//	sort(a.begin(), a.end());
//	for (int i : a) {
//		if (i % x == 0) {
//			cout << i << ' ';
//			cnt++;
//			if (cnt >= 3) break;
//		}
//	}
//	return 0;
//}



//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//	int n;
//	cin >> n;
//	vector<int> a(n + 1);
//	for (int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i - 1];
//	int ans = 1e17;
//	for (int i = 1; i < n; i++) {
//		for (int j = i + 1; j <= n; j++) {
//			int l = i, r = j;
//			while (l >= 1 && r <= n) {
//				ans = min(ans, abs(a[i] - a[l - 1] - (a[r] - a[j - 1])));
//				if (a[i] - a[l - 1] > a[r] - a[j - 1]) r++;
//				else l--;
//			}
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//int n, ans;
//string s = "000000000";
//bool vis[10];
//
//void dfs(int deep) {
//	if (deep == 9) {
//		for (int i = 1; i < 7; i++) {
//			for (int j = i + 1; j < 9; j++) {
//				int a = stoi(s.substr(0, i));
//				int b = stoi(s.substr(i, j - i));
//				int c = stoi(s.substr(j, 9 - j));
//				if (n == a + 1.0 * b / c) ans++;
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


//#include <bits/stdc++.h>
//using namespace std;
//
//bool is_he(int x) {
//	string s = to_string(x);
//	unordered_map<char, int> mp;
//	for (char c : s) {
//		mp[c]++;
//		if (mp[c] >= 2 || c == '0') return false;
//	}
//	return true;
//}
//
//bool is_he2(int a, int b, int c) {
//	string s = to_string(a) + to_string(b) + to_string(c);
//	if (s.size() != 9) return false;
//	unordered_map<char, int> mp;
//	for (char c : s) {
//		mp[c]++;
//		if (mp[c] >= 2 || c == '0') return false;
//	}
//	return true;
//}
//
//int main() {
//	int n, ans = 0;
//	cin >> n;
//	for (int i = 1; i < n; i++) {
//		if (is_he(i)) {
//			int cha = n - i;
//			int i_len = to_string(i).size();
//			i_len = 9 - i_len;
//			int a = cha, b = 1;
//			string ab = to_string(a) + to_string(b);
//			while ((int)ab.length() <= i_len) {
//				if (is_he2(a, b, i)) ans++;
//				b++;
//				a = cha * b;
//				ab = to_string(a) + to_string(b);
//			}
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//vector<int> pre;
//
//int root(int x) {
//	if (x != pre[x]) pre[x] = root(pre[x]);
//	return pre[x];
//}
//
//void merge(int x, int y) {
//	x = root(x), y = root(y);
//	if (x == y) return;
//	pre[x] = y;
//}
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	n = n * m;
//	pre.resize(n + 1);
//	for (int i = 1; i <= n; i++) pre[i] = i;
//	int t;
//	cin >> t;
//	while (t --) {
//		int x, y;
//		cin >> x >> y;
//		merge(x, y);
//	}
//	int ans = 0;
//	for (int i = 1; i <= n; i++) if (i == pre[i]) ans++;
//	cout << ans << endl;
//}


// P8599 [蓝桥杯 2013 省 B] 带分数
#include <bits/stdc++.h>
using namespace std;

bool ishe(int x) {
	string s = to_string(x);
	unordered_map<char, int> mp;
	for (char c : s) {
		mp[c]++;
		if (mp[c] >= 2) return false;
	}
	return true;
}

bool ishe2(int a, int b, int c) {
	string s = to_string(a) + to_string(b) + to_string(c);
	if (s.length() != 9) return false;
	unordered_map<char, int> mp;
	for (char c : s) {
		mp[c]++;
		if (mp[c] >= 2 || c == '0') return false;
	}
	return true;
}

int get(int n) {
	int ans = 0;
	for (int i = 1; i < n; i++) {
		if (ishe(i)) {
			int cha = n - i;
			int cha_len = to_string(i).size();
			cha_len = 9 - cha_len;
			int a = cha, b = 1;
			string s = to_string(a) + to_string(b);
			while ((int)s.length() <= cha_len) {
				if (ishe2(a, b, i)) {
					ans++;
				}
				b++;
				a = cha * b;
				s = to_string(a) + to_string(b);
			}
		}
	}
	return ans;
}

int main() {
	int maxn = 0;
	for (int i = 1; i <= 1000000; i++) {
		cout << i << endl;
		maxn = max(maxn, get(i));
	}
	cout << maxn;
	return 0;
}
