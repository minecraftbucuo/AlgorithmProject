// 2025.2.28
// 1
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	string s;
//	string ans = "";
//	while (cin >> s) {
//		if (s == "99999") break;
//		int a = s[0] - '0';
//		int b = s[1] - '0';
//		int c = a + b;
//		if (c % 2 == 0 && c != 0) {
//			ans = "right";
//			cout << ans << ' ' << s.substr(2, 3) << endl;
//		} else if (c % 2) {
//			ans = "left";
//			cout << ans << ' ' << s.substr(2, 3) << endl;
//		} else {
//			cout << ans << ' ' << s.substr(2, 3) << endl;
//		}
//	}
//	return 0;
//}


// 2
//#include <bits/stdc++.h>
//using namespace std;
//
//bool keyi(int x) {
//	string s_x = to_string(x);
//	string s_x_ = s_x;
//	sort(s_x_.begin(), s_x_.end());
//	if (s_x == s_x_) return true;
//	return false;
//}
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int> ans;
//	for (int i = 10; i <= n; i++) {
//		if (keyi(i)) ans.push_back(i);
//	}
//	if (ans.empty()) cout << -1 << endl;
//	else {
//		for (auto i : ans) cout << i << endl;
//	}
//	return 0;
//}



// 3
//#include <bits/stdc++.h>
//using namespace std;
//
//string yuan = "aeiou";
//
//bool is_yuan(char c) {
//	for (unsigned int i = 0; i < yuan.size(); i++) {
//		if (c == yuan[i]) return true;
//	}
//	return false;
//}
//
//int main() {
//	string s;
//	char c;
//	c = getchar();
//	while (c != '\n') {
//		s += c;
//		c = getchar();
//	}
//	string ans = "";
//	for (unsigned int i = 0; i < s.size(); i++) {
//		if (is_yuan(s[i])) {
//			ans += s[i];
//			i += 2;
//			continue;
//		}
//		ans += s[i];
//	}
//	cout << ans << endl;
//	return 0;
//}



// 4  不知道为啥过不了
// 好了知道为啥了
//#include <bits/stdc++.h>
//using namespace std;
//
//int qushu(int a, int idx) {
//	string s_a = to_string(a);
//	if ((int)s_a.size() < idx) return 0;
//	return s_a[idx - 1] - '0';
//}
//
//vector<int> div(int a, int b, int maxn) {
//	vector<int> c;
//	int t = 0;
//	int len = to_string(a).size();
//	for (int i = 1; i <= maxn; i++) {
//		t = 10 * t + qushu(a, i);
//		if (i >= len)
//			c.push_back(t / b);
//		t %= b;
//	}
//	return c;
//}
//
//
//signed main() {
//	int a, b;
//	cin >> a >> b;
//	vector<int> x(6);
//	int maxn = 10000;
//	for (int i = 0; i < 6; i++) {
//		cin >> x[i];
//		maxn = max(x[i], maxn);
//	}
//
//	vector<int> ans;
//	ans = div(a, b, maxn + 10);
//	for (int i = 0; i < 6; i++) cout << ans[x[i]];
////	for (int i = 0; i < maxn; i++) cout << ans[i];
//
//	return 0;
//}



// 5
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//
//	return 0;
//}



// 6
//#include <bits/stdc++.h>
//using namespace std;
//
//void tian(vector<vector<int>>& a, int x1, int y1, int x2, int y2) {
//	for (int i = x1; i <= x2; i++) {
//		for (int j = y1; j <= y2; j++) {
//			a[i][j]++;
//		}
//	}
//}
//
//int main() {
//	int n, m, x1, y1, x2, y2;
//	cin >> n >> m;
//	vector<vector<int>> a(n + 1, vector<int>(n + 1));
//	for (int i = 0; i < m; i++) {
//		cin >> x1 >> y1 >> x2 >> y2;
//		tian(a, x1, y1, x2, y2);
//	}
//
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			cout << a[i][j] << ' ';
//		}
//		cout << endl;
//	}
//	return 0;
//}


// 7
//#include <bits/stdc++.h>
//using namespace std;
//
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	vector<int> qian(n);
//	vector<int> wu(m);
//	for (int i = 0; i < n; i++) cin >> qian[i];
//	for (int i = 0; i < m; i++) cin >> wu[i];
//	sort(qian.begin(), qian.end());
//	sort(wu.begin(), wu.end());
//	int a = 0, b = 0;
//	int ans = 0;
//	while (a < (int)qian.size()) {
//		if (qian[a] >= wu[b]) {
//			a++;
//			b++;
//			ans++;
//		} else {
//			a++;
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}


// 8


// 9
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	string s;
//	cin >> s;
//	string ans = s;
//	for (unsigned int i = 0; i < s.size(); i++) {
//		if (s[i] == '1') {
//			for (unsigned int j = i + 2; j <= s.size(); j++) {
//				string temp = s;
//				reverse(temp.begin() + i, temp.begin() + j);
//				ans = min(ans, temp);
//			}
//			break;
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}



// 10  难写
//#include <bits/stdc++.h>
//using namespace std;
//
//stack<int> num;
//stack<char> op;
//
//int main() {
//	string s;
//	getline(cin, s);
//	for (unsigned int i = 0; i < s.size(); i++) {
//		if (s[i] == 'F') {
//			op.push('+');
//			i += 2;
//		} else if (s[i] == 'B') {
//
//		} else if (s[i] == 'R') {
//
//		} else if (s[i] >= '0' && s[i] <= '9') {
//
//		}
//	}
//	return 0;
//}



// 11  没过
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int q;
//	cin >> q;
//	string s;
//	cin >> s;
//	int dengxiao = 0;
//	for (unsigned int i = 0; i < s.size() - 1; i++) {
//		dengxiao += (s[i] != s[i + 1]);
//	}
//	dengxiao++;
//	cout << (dengxiao + 1) / 2 << endl;
//	int x;
//	char y;
//	while (q--) {
//		cin >> x >> y;
//		x--;
//		if (y == s[x]) cout << (dengxiao + 1) / 2 << endl;
//		else {
//			if (x == 0 || x == (int)(s.size() - 1)) {
//				if (x == 0) {
//					if (s[x + 1] == y) dengxiao -= 1;
//					else if (s[x] == s[x + 1]) dengxiao += 1;
//				} else if (x == (int)(s.size() - 1)) {
//					if (s[x - 1] == y) dengxiao -= 1;
//					else if (s[x] == s[x - 1]) dengxiao += 1;
//				}
//				s[x] = y;
//				cout << (dengxiao + 1) / 2 << endl;
//			} else {
//				if (s[x] == s[x - 1] && s[x] == s[x + 1]) dengxiao += 2;
//				else if (s[x] == s[x - 1]) {
//					if (y != s[x + 1]) dengxiao++;
//				} else if (s[x] == s[x + 1]) {
//					if (y != s[x - 1]) dengxiao++;
//				} else {
//					if (y == s[x - 1] || y == s[x + 1]) dengxiao--;
//				}
//				s[x] = y;
//				cout << (dengxiao + 1) / 2 << endl;
//			}
//		}
//	}
//	return 0;
//}



// 12


// 13
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 15;
//int ans[N], n, ans_cnt;
//bool vis_lie[N], zuoxie[2 * N + 3], youxie[2 * N + 3];
//
//void dfs(int s) {
//	if (s == n + 1) {
//		if (ans_cnt < 3) {
//			for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
//			cout << endl;
//		}
//		ans_cnt++;
//	}
//	for (int i = 1; i <= n; i++) {
//		if (!vis_lie[i] && !zuoxie[i - s + n] && !youxie[i + s]) {
//			vis_lie[i] = 1;
//			zuoxie[i - s + n] = 1;
//			youxie[i + s] = 1;
//			ans[s] = i;
//			dfs(s + 1);
//			vis_lie[i] = 0;
//			zuoxie[i - s + n] = 0;
//			youxie[i + s] = 0;
//			ans[s] = 0;
//		}
//	}
//}
//
//int main() {
//	cin >> n;
//	dfs(1);
//	cout << ans_cnt << endl;
//	return 0;
//}



// 14
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1000010;
vector<vector<pair<int, int>>> a(N);
vector<int> siz(N);
int n, ans;

void dfs(int x, int fa) {
	siz[x] = 1;
	for (unsigned int i = 0; i < a[x].size(); i++) {
		int to = a[x][i].first;
		if (to == fa) continue;
		dfs(to, x);
		siz[x] += siz[to];
		ans += a[x][i].second * abs(2 * siz[to] - n);
	}
}

signed main() {
	cin >> n;
	int x, y, z;
	for (int i = 0; i < n - 1; i++) {
		cin >> x >> y >> z;
		a[x].push_back({y, z});
		a[y].push_back({x, z});
	}
	dfs(1, 0);
	cout << ans << endl;
	return 0;
}
