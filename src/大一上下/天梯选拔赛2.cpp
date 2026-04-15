// 2025.3.2   打得一坨屎

// 1
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	vector<vector<double>> a(n + 1, vector<double>(m + 1));
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cin >> a[i][j];
//		}
//	}
//	vector<vector<double>> b(a.begin(), a.end());
//	for (int i = 1; i < n - 1; i++) {
//		for (int j = 1; j < m - 1; j++) {
//			b[i][j] = (a[i - 1][j] + a[i + 1][j] + a[i][j - 1] + a[i][j + 1] + a[i][j]) / 5;
//		}
//	}
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			printf("%.0lf ", b[i][j]);
//		}
//		cout << endl;
//	}
//	return 0;
//}


// 2
//#include <bits/stdc++.h>
//using namespace std;
//
//stack<int> num;
//stack<char> op;
//
//int main() {
//	string s;
//	getline(cin, s);
//	int t = 0;
//	for (int i = 0; i < (int)s.size(); i++) {
//		if (s[i] >= '0' && s[i] <= '9') {
//			t = t * 10 + s[i] - '0';
//		} else if (s[i] == ' ' || s[i] == '\n') {
//			num.push(t);
//			t = 0;
//		} else {
//			num.push(t);
//			t = 0;
//			op.push(s[i]);
//		}
//	}
//	num.push(t);
//	if (op.top() == '+') {
//		int b = num.top();
//		num.pop();
//		int a = num.top();
//		cout << a + b << endl;
//	} else if (op.top() == '-') {
//		int b = num.top();
//		num.pop();
//		int a = num.top();
//		cout << a - b << endl;
//	} else if (op.top() == '*') {
//		int b = num.top();
//		num.pop();
//		int a = num.top();
//		cout << a * b << endl;
//	} else if (op.top() == '/') {
//		int b = num.top();
//		num.pop();
//		int a = num.top();
//		cout << a / b << endl;
//	} else {
//		int b = num.top();
//		num.pop();
//		int a = num.top();
//		cout << a % b << endl;
//	}
//	return 0;
//}


// 3
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//
//signed main() {
//	string s;
//	char op = ' ';
//	getline(cin, s);
//	int a = -1;
//	int t = 0;
//	for (int i = 0; i < (int)s.size(); i++) {
//		t = 0;
//		int j = i;
//		if (s[j] >= '0' && s[j] <= '9') {
//			while (j < (int)s.size() && s[j] >= '0' && s[j] <= '9') {
//				t = 10 * t + s[j] - '0';
//				j++;
//			}
//			if (a == -1) a = t;
//			else {
//				if (op == '+') a = a + t;
//				if (op == '-') a = a - t;
//			}
//			i = j - 1;
//		} else {
//			if (s[i] != '+' && s[i] != '-') continue;
//			op = s[i];
//		}
//	}
////	if (op == '+') a = a + t;
////	if (op == '-') a = a - t;
//	cout << a << endl;
//	return 0;
//}


// 4
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	int ans = 0;
//	for (int i = n + 1; i < m; i++) {
//		if (i % 4 == 0 && i % 25 == 0) ans += i;
//	}
//	cout << ans << endl;
//	return 0;
//}


// 5



// 6
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



// I
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	string s1, s;
//	getline(cin, s1);
//	vector<string> s2;
//	while (cin >> s) {
//		s2.push_back(s);
//	}
//	for (int i = 0; i < (int)s1.size(); i++) {
//		if (s1[i] >= 'A' && s1[i] <= 'Z') s1[i] -= 'A' - 'a';
//	}
//
//	for (int i = 0; i < (int)s2.size(); i++) {
//		for (int j = 0; j < (int)s2[i].size(); j++) {
//			if (s2[i][j] >= 'A' && s2[i][j] <= 'Z') s2[i][j] -= 'A' - 'a';
//		}
//	}
//
//	int ans1 = -1;
//	int ans2 = 0;
//	for (int i = 0; i < (int)s2.size(); i++) {
//		if (s2[i] == s1) {
//			if (ans1 == -1)
//				ans1 = i;
//			ans2++;
//		}
//	}
//	if (ans1 == -1) {
//		cout << -1 << endl;
//	} else {
//		cout << ans2 << ' ' << ans1 << endl;
//	}
//	return 0;
//}



//
//#include <bits/stdc++.h>
//using namespace std;
//
//vector<string> shuchu(string& s) {
//	vector<string> res;
//	res.push_back(s);
//	for (int i = 1; i < (int)s.size(); i++) {
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
//	unordered_map<string, bool> mp;
//	int ans = 0;
//	while (n--) {
//		cin >> s;
//		vector<string> res = shuchu(s);
//		for (auto x : res) {
//			if (!mp[x]) {
//				ans++;
//				mp[x] = 1;
//			}
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}



//
//#include <bits/stdc++.h>
//using namespace std;
//
//bool is_he(string & s1, vector<string> & s2) {
//	for (int i = 0; i < (int)s2.size(); i++) {
//		if (s1.find(s2[i]) != string::npos) {
//			return false;
//		}
//	}
//	return true;
//}
//
//
//int main() {
//	int n, m;
//	cin >> n;
//	vector<string> s1(n);
//	for (int i = 0; i < n; i++) cin >> s1[i];
//	cin >> m;
//	vector<string> s2(m);
//	for (int i = 0; i < m; i++) cin >> s2[i];
//
//	for (int i = 0; i < n; i++) {
//		if (is_he(s1[i], s2)) cout << "No" << endl;
//		else cout << "Yes" << endl;
//	}
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//
//signed main() {
//	int n, m;
//	cin >> n >> m;
//	vector<int> a(m);
//	for (int i = 0; i < m; i++) cin >> a[i];
//	vector<vector<int>> ans(n);
//	vector<int> b(n);
//
//	for (int i = 0; i < m; i++) {
//		int idx = 0;
//		for (int j = 1; j < n; j++) {
//			if (b[j] < b[idx]) idx = j;
//		}
//		b[idx] += a[i];
//		ans[idx].push_back(i + 1);
//	}
//	for (int i = 0; i < n; i++) {
//		if (!ans[i].empty()) {
//			for (int j = 0; j < (int)ans[i].size(); j++) {
//				cout << ans[i][j] << ' ';
//			}
//			cout << endl;
//		} else {
//			cout << 0 << endl;
//		}
//	}
//	return 0;
//}



//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//
//signed main() {
//	vector<int> a(8);
//	vector<int> b(4);
//	vector<int> c(3);
//
//	for (int i = 0; i < 8; i++) cin >> a[i];
//	for (int i = 0; i < 4; i++) cin >> b[i];
//	for (int i = 0; i < 3; i++) cin >> c[i];
//
//	int ans1 = 0;
//	int ans2 = 0;
//	int ans3 = 0;
//	for (int i = 0; i < 8; i++) {
//		ans1 += a[i];
//	}
//	if (ans1 >= 80) {
//		for (int i = 0; i < 4; i++) {
//			ans2 += b[i];
//		}
//	}
//
//	if (ans2 >= 40) {
//		for (int i = 0; i < 3; i++) {
//			ans3 += c[i];
//		}
//	}
//	cout << ans1 + ans2 + ans3 << endl;
//
//	return 0;
//}
