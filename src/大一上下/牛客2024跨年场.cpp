//2024 12 31

//A
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int t;
//	cin >> t;
//	cout << "Bob" << endl;
//	return 0;
//}


//B
//PHP语言
//2024


//G
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	for (int i = 2026; i <= 9999; i++) {
//		string s = to_string(i);
//		int a = stoi(s.substr(0, 2));
//		int b = stoi(s.substr(2, 2));
//		if ((a + b) * (a + b) == i) {
//			cout << i << endl;
//		}
//	}
//	return 0;
//}


//J
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int t;
//	cin >> t;
//	int n;
//	while (t--) {
//		cin >> n;
//		for (int i = 1; i <= n; i++) {
//			cout << "GL";
//		}
//		cout << endl;
//	}
//	return 0;
//}


//D
//#include <bits/stdc++.h>
//using namespace std;
//
//#define int long long
//
//signed main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int n;
//		cin >> n;
//		vector<int> a(n + 1);
//		for (int i = 1; i <= n; i++) cin >> a[i];
//		sort(a.begin(), a.end());
//		vector<int> sum(n + 1);
//		for (int i = 1; i <= n; i++) {
//			sum[i] = sum[i - 1] + a[i];
//		}
//
//		bool have_ans = false;
//		for (int i = n; i >= 3; i--) {
//			if (sum[i - 1] > a[i]) {
//				cout << sum[i] << endl;
//				have_ans = true;
//				break;
//			}
//		}
//
//		if (!have_ans)
//			cout << 0 << endl;
//	}
//	return 0;
//}


//E 没过 呜呜呜
//#include <bits/stdc++.h>
//using namespace std;
//
//void get_ans(vector<vector<int>>& g, vector<int>& ans, vector<bool>& vis, int start, int& step, int idx) {
//	if (vis[start]) return;
//	vis[start] = 1;
//	int i;
//	for (i = 1; i <= 29; i++) {
//		if (!vis[i] && g[start][i]) {
//			step++;
//			get_ans(g, ans, vis, i, step, idx);
//		}
//	}
//	ans[idx] = max(ans[idx], step);
//}
//
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int a, b;
//		vector<vector<int>> g(30, vector<int>(30));
//		for (int i = 1; i <= 19; i++) {
//			cin >> a >> b;
//			g[a][b] = 1;
//			g[b][a] = 1;
//		}
//
//		vector<bool> vis(30);
//
//		vector<int> ans(50, -1);
//
//		for (int i = 1; i <= 22; i++) {
//			int step = 1;
//			get_ans(g, ans, vis, i, step, i);
//		}
//
//		sort(ans.begin(), ans.end());
//
//		if (ans[ans.size() - 1] == 6 && ans[ans.size() - 2] == 6 && ans[ans.size() - 3] == 6 && ans[ans.size() - 4] == 4) {
//			cout << 2025 << endl;
//		} else {
//			cout << 2024 << endl;
//		}
//
//	}
//	return 0;
//}


