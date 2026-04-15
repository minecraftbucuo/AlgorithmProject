// P8599 [蓝桥杯 2013 省 B] 带分数
// 2025.2.15
//#include <bits/stdc++.h>
//using namespace std;
//
//bool is_he(int x) {
//	unordered_map<int, int> mp;
//	while (x) {
//		mp[x % 10]++;
//		if (mp[x % 10] >= 2) return false;
//		x /= 10;
//	}
//	return true;
//}
//
//bool is_he_s(int a, int b, int c) {
//	string s = to_string(a) + to_string(b) + to_string(c);
//	if (s.size() != 9) return false;
//	unordered_map<char, int> mp;
//	for (unsigned i = 0; i < s.size(); i++) {
//		mp[s[i]]++;
//		if (mp[s[i]] >= 2 || s[i] == '0') return false;
//	}
//	return true;
//}
//
//int main() {
//	int n;
//	cin >> n;
//	int ans = 0;
//	for (int i = 1; i < n; i++) {
//		if (is_he(i)) {
//			int len_i = to_string(i).size();
//			int len = to_string(n - i).size();
//			int cha = 9 - len_i;
//			int wei = (cha - len + 1) / 2;
//			int j = pow(10, wei - 1);
//			for (; to_string(j).size() + to_string(j * (n - i)).size() <= cha; j++) {
//				if (is_he_s(i, j, j * (n - i))) {
//					ans++;
////					printf("%d %d %d\n", i, j, j * (n - i));
//				}
//			}
//		}
//	}
//	cout << ans << endl;
//	return 0;
//} 



// P10904 [蓝桥杯 2024 省 C] 挖矿
// 2025.2.16
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n, m, x;
//	cin >> n >> m;
//	vector<int> zhen, fu;
//	int have_zero = 0;
//	for (int i = 0; i < n; i++) {
//		cin >> x;
//		if (x > 0) zhen.push_back(x);
//		else if (x < 0) fu.push_back(x);
//		else have_zero++;
//	}
//	sort(zhen.begin(), zhen.end());
//	sort(fu.begin(), fu.end());
//	int ans = 0;
//	for (int i = 0; i <= m; i++) {
//		int zuo = fu.size() - (lower_bound(fu.begin(), fu.end(), -i) - fu.begin());
//		int you = upper_bound(zhen.begin(), zhen.end(), m - 2 * i) - zhen.begin();
//		ans = max(ans, zuo + you); 
//	}
//	for (int i = 0; i <= m; i++) {
//		int zuo = fu.size() - (lower_bound(fu.begin(), fu.end(), 2 * i - m) - fu.begin());
//		int you = upper_bound(zhen.begin(), zhen.end(), i) - zhen.begin();
//		ans = max(ans, zuo + you); 
//	}
//	cout << ans + have_zero << endl;
//	
//	return 0;
//} 



// P10914 [蓝桥杯 2024 国 B] 跳石头
// 2025.2.18
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 40010;
//int n, a[N], ans;
//unordered_set<int> b[N];
//
//void dfs(int s) {
//	if (s > n) return;
//	else {
//		b[s].insert(a[s]);
//		if (2 * s <= n) {
//			if (!b[2 * s].size()) dfs(2 * s);
//			for (auto x : b[2 * s]) b[s].insert(x);
//		} 
//		if (s + a[s] <= n) {
//			if (!b[s + a[s]].size()) dfs(s + a[s]);
//			for (auto x : b[s + a[s]]) b[s].insert(x);
//		}
//	}
//}
//
//int main() {
//	cin >> n;
//	for (int i = 1; i <= n; i++) cin >> a[i];
//	for (int i = 1; i <= n; i++) {
//		if (!b[i].size())
//			dfs(i);
//	}
//	
//	for (int i = 1; i <= n; i++) {
//		ans = max(ans, (int)b[i].size());
//	}
//	cout << ans << endl;
//	return 0;
//}


// P8599 [蓝桥杯 2013 省 B] 带分数 （新解法） 
// 2025.3.12
//#include <bits/stdc++.h>
//using namespace std;
//
//int n, ans;
//string s = "000000000";
//vector<bool> vis(10);
//
//void dfs(int step) {
//	if (step == 9) {
//		for (int i = 1; i < 7; i++) {
//			int mid = (9 - i) / 2;
//			for (int j = i + mid; j < 9; j++) {
//				int a = stoi(s.substr(0, i));
//				int b = stoi(s.substr(i, j - i));
//				int c = stoi(s.substr(j, 9 - j));
//				if (a + 1.0 * b / c == n) {
//					ans++;
//				}
//			}
//		}
//		
//	} else {
//		for (int i = 1; i <= 9; i++) {
//			if (!vis[i]) {
//				vis[i] = 1;
//				s[step] = i + '0';
//				dfs(step + 1);
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












