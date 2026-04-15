//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	vector<vector<double>> a(n + 1, vector<double>(m + 1));
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			cin >> a[i][j];
//		}
//	}
//	vector<vector<double>> b(a.begin(), a.end());
//	for (int i = 2; i < n; i++)
//		for (int j = 2; j < m; j++)
//			a[i][j] = (b[i][j - 1] + b[i][j + 1] + b[i][j] + b[i - 1][j] + b[i + 1][j]) / 5;
//
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			printf("%.0lf ", a[i][j]);
//		}
//		cout << endl;
//	}
//	return 0;
//}



//#include <bits/stdc++.h>
//using namespace std;
//
//stack<int> num;
//stack<char> op;
//
//void calc() {
//	int b = num.top();
//	num.pop();
//	int a = num.top();
//	num.pop();
//	char o = op.top();
//	op.pop();
//	if (o == '+') num.push(a + b);
//	else if (o == '-') num.push(a - b);
//	else if (o == '*') num.push(a * b);
//	else if (o == '/') num.push(a / b);
//	else num.push(a % b);
//}
//
//int main() {
//	string s;
//	getline(cin, s);
//	for (unsigned int i = 0; i < s.size(); i++) {
//		if (s[i] >= '0' && s[i] <= '9') {
//			unsigned int j = i;
//			int t = 0;
//			while (j < s.size() && s[j] >= '0' && s[j] <= '9') {
//				t = t * 10 + s[j] - '0';
//				j++;
//			}
//			num.push(t);
//			i = j - 1;
//		} else if (s[i] == ' ') continue;
//		else {
//			while (!op.empty()) calc();
//			op.push(s[i]);
//		}
//	}
//	while (!op.empty()) calc();
//	cout << num.top() << endl;
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//stack<int> num;
//stack<char> op;
//
//void calc() {
//	int b = num.top();
//	num.pop();
//	int a = num.top();
//	num.pop();
//	char o = op.top();
//	op.pop();
//	if (o == '+') num.push(a + b);
//	else num.push(a - b);
//}
//
//int main() {
//	string s;
//	getline(cin, s);
//	for (unsigned int i = 0; i < s.size(); i++) {
//		if (isdigit(s[i])) {
//			unsigned int j = i;
//			int t = 0;
//			while (j < s.size() && isdigit(s[j])) {
//				t = 10 * t + s[j] - '0';
//				j++;
//			}
//			num.push(t);
//			i = j - 1;
//		} else if (s[i] == ' ') continue;
//		else {
//			if (s[i] == '+' || s[i] == '-') {
//				while (!op.empty()) calc();
//				op.push(s[i]);
//			}
//		}
//	}
//	while (!op.empty()) calc();
//	cout << num.top() << endl;
//	return 0;
//}



//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	int ans = 0;
//	for (int i = n + 1; i < m; i++) {
//		if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) ans += i;
//	}
//	cout << ans << endl;
//	return 0;
//}



//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	vector<int> t(m + 1);
//	for (int i = 1; i <= m; i++) cin >> t[i];
//	vector<long long> sum(n + 1);
//	vector<vector<int>> ans(n + 1);
//	for (int i = 1; i <= m; i++) {
//		int idx = 1;
//		for (int j = 2; j <= n; j++) {
//			if (sum[j] < sum[idx])
//				idx = j;
//		}
//		sum[idx] = sum[idx] + t[i];
//		ans[idx].push_back(i);
//	}
//	for (int i = 1; i <= n; i++) {
//		if (ans[i].empty()) cout << 0 << endl;
//		else {
//			for (int j : ans[i]) {
//				cout << j << ' ';
//			}
//			cout << endl;
//		}
//	}
//	return 0;
//}



//#include <bits/stdc++.h>
//using namespace std;
//
//
//int main() {
//	char a;
//	a = getchar();
//	int zuo = 0;
//	string ans = "YES";
//	while (a != '@') {
//		if (a == '(') zuo++;
//		else if (a == ')') {
//			if (zuo <= 0) {
//				ans = "NO";
//				break;
//			}
//			zuo--;
//		}
//		a = getchar();
//	}
//	if (ans == "YES") {
//		if (zuo != 0) ans = "NO";
//	}
//	cout << ans << endl;
//	return 0;
//}



//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	vector<int> a(8);
//	vector<int> b(4);
//	vector<int> c(3);
//	for (int i = 0; i < 8; i++) cin >> a[i];
//	for (int i = 0; i < 4; i++) cin >> b[i];
//	for (int i = 0; i < 3; i++) cin >> c[i];
//	int ans1 = 0;
//	int ans2 = 0;
//	int ans3 = 0;
//	for (int i = 0; i < 8; i++) ans1 += a[i];
//	if (ans1 >= 80)
//		for (int i = 0; i < 4; i++) ans2 += b[i];
//	if (ans2 >= 40)
//		for (int i = 0; i < 3; i++) ans3 += c[i];
//	cout << ans1 + ans2 + ans3 << endl;
//	return 0;
//}



//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	vector<int> juli(n);
//	vector<int> red(n);
//	vector<int> green(n);
//	juli[0] = m;
//	for (int i = 1; i < n; i++) cin >> juli[i];
//	for (int i = 0; i < n; i++) cin >> red[i];
//	for (int i = 0; i < n; i++) cin >> green[i];
//	int t = 0;
//	for (int i = 0; i < n; i++) {
//		t += juli[i];
//		int x = t % (red[i] + green[i]);
//		if (x > green[i]) {
//			t += red[i] - x + green[i];
//		}
//		cout << t << endl;
//	}
//	return 0;
//}



//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	string s1, s2;
//	cin >> s1;
//	getchar();
//	getline(cin, s2);
//	s2 = ' ' + s2;
//	s2.back() = ' ';
//	int first = -1;
//	int cnt = 0;
//	for (unsigned int i = 1; i < s2.size(); i++) {
//		if ((s2[i - 1] == ' ') && (i + s1.size() < s2.size()) && (s2[i + s1.size()] == ' ')) {
//			bool is_match = true;
//			for (unsigned int j = 0; j < s1.size(); j++) {
//				if (s1[j] != s2[j + i] && abs(s1[j] - s2[j + i]) != abs('A' - 'a')) {
//					is_match = false;
//					break;
//				}
//			}
//			if (is_match) {
//				cnt++;
//				if (first == -1) first = i - 1;
//			}
//		}
//	}
//	if (cnt == 0) cout << -1;
//	else {
//		cout << cnt << ' ' << first << endl;
//	}
//	return 0;
//}



//#include <bits/stdc++.h>
//using namespace std;
//
//bool is_he(string & s, vector<string> & match) {
//	for (unsigned int i = 0; i < match.size(); i++) {
//		if (s.find(match[i]) != string::npos)
//			return false;
//	}
//	return true;
//}
//
//int main() {
//	int n;
//	cin >> n;
//	vector<string> name(n);
//	for (int i = 0; i < n; i++) cin >> name[i];
//	int m;
//	cin >> m;
//	vector<string> match(m);
//	for (int i = 0; i < m; i++) cin >> match[i];
//	for (int i = 0; i < n; i++) {
//		if (is_he(name[i], match)) cout << "No" << endl;
//		else cout << "Yes" << endl;
//	}
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//vector<string> mkdir(string & s) {
//	vector<string> res;
//	res.push_back(s);
//	for (unsigned int i = 1; i < s.size(); i++) {
//		if (s[i] == '/') {
//			res.push_back(s.substr(0, i));
//		}
//	}
//	return res;
//}
//
//int main() {
//	int n;
//	cin >> n;
//	string s;
//	unordered_map<string, bool> e;
//	int ans = 0;
//	while (n--) {
//		cin >> s;
//		vector<string> a = mkdir(s);
//		for (string s : a) {
//			if (!e[s]) {
//				ans++;
//				e[s] = 1;
//			}
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}



#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	string ans = "";
	for (unsigned int i = 0; i < s.size(); i += 5) {
		string sub = s.substr(i, 4);
		if (sub != "0000") {
			int j = 0;
			while (sub[j] == '0') j++;
			ans += sub.substr(j, sub.size() - j) + ':';
		} else ans += "0000:";
	}
	ans = ans.substr(0, ans.size() - 1);

	vector<string> match = {
		"0000:0000:0000:0000:0000:0000:0000:0000",
		"0000:0000:0000:0000:0000:0000:0000",
		"0000:0000:0000:0000:0000:0000",
		"0000:0000:0000:0000:0000",
		"0000:0000:0000:0000",
		"0000:0000:0000",
		"0000:0000",
		"0000"
	};
	int start = -1;
	int end = -1;
//	cout << ans << endl;
	for (string s : match) {
		if (ans.find(s) != string::npos) {
			start = ans.find(s);
			end = start + s.size() - 1;
			break;
		}
	}
	if (start == -1) cout << ans << endl;
	else {
//		cout << start << ' ' << end << endl;
		string new_ans = "";
		if (start == 0) new_ans = ":";
		for (int i = 0; i < start; i++) new_ans += ans[i];
		for (unsigned int i = end + 1; i < ans.size(); i++) new_ans += ans[i];
		if (end == (int)ans.size() - 1) new_ans += ":";

		string new_new_ans = "";
//		cout << new_ans << endl;

		for (unsigned int i = 0; i < new_ans.size(); i++) {
			if (new_ans[i] == '0') {
				new_new_ans += "0:";
				while (i < new_ans.size() && new_ans[i] != ':') {
					i++;
				}
			} else if (new_ans[i] != ':') {
				while (i < new_ans.size() && new_ans[i] != ':') {
					new_new_ans += new_ans[i];
					i++;
				}
				new_new_ans += ':';
			} else {
				new_new_ans += ':';
			}
		}
		if (!(new_new_ans.back() == ':' && new_new_ans[new_new_ans.size() - 2] == ':'))
			new_new_ans = new_new_ans.substr(0, new_new_ans.size() - 1);
		cout << new_new_ans << endl;
	}
	return 0;
}



//#include <bits/stdc++.h>
//using namespace std;
//
//int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
//int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};
//
//int main() {
//	int n, m, x, y;
//	cin >> n >> m >> x >> y;
//	vector<vector<int>> a(n + 1, vector<int>(m + 1, -1));
//	vector<vector<bool>> vis(n + 1, vector<bool>(m + 1));
//	a[x][y] = 0;
//	queue<array<int, 3>> q;
//	q.push({x, y, 0});
//	vis[x][y] = 1;
//
//	while (!q.empty()) {
//		array<int, 3> ar = q.front();
//		q.pop();
//		int step = ar[2] + 1;
//		for (int i = 0; i < 8; i++) {
//			int x_ = ar[0] + dx[i];
//			int y_ = ar[1] + dy[i];
//			if (x_ >= 1 && x_ <= n && y_ >= 1 && y_ <= m && !vis[x_][y_]) {
//				vis[x_][y_] = 1;
//				q.push({x_, y_, step});
//				a[x_][y_] = step;
//			}
//		}
//	}
//
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			cout << a[i][j] << ' ';
//		}
//		cout << endl;
//	}
//
//	return 0;
//}
