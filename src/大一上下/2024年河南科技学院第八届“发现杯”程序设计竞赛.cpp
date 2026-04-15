//2024年河南科技学院第八届“发现杯”程序设计竞赛  2024 12 21

//A
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	cout << "HISTCPC" << endl;
//	return 0;
//}

//B
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	cout << n - 1939 << endl;
//	return 0;
//}

//C
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int a, b;
//	cin >> a >> b;
//	cout << a / b << endl;
//	return 0;
//}

//D
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	char a;
//	int t_ = 3;
//	char t = 'A';
//	char ans;
//	while (t_--) {
//		cin >> a;
//		if (a == 'G') ans = t;
//		t++;
//	}
//
//	cout << ans << endl;
//	return 0;
//}

//E
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int t, n, k;
//	string s1, s2;
//	cin >> t;
//	while (t--) {
//		cin >> n >> k;
//		cin >> s1 >> s2;
//		sort(s1.begin(), s1.end());
//		sort(s2.begin(), s2.end());
//		if (s1 == s2) {
//			cout << "YES" << endl;
//		} else {
//			cout << "NO" << endl;
//		}
//	}
//
//	return 0;
//}


//F
//#include <bits/stdc++.h>
//using namespace std;
//
//#define int long long
//
//signed main() {
//	int t, n, m;
//	cin >> t;
//	while (t--) {
//		cin >> n >> m;
//		cout << (m % n == 0 ? n : m % n) << ' ';
//		int ans = (-1.0 + sqrtl(1 + 8 * m)) / 2.0;
//
//		int xiang;
//		if (ans % 2 == 0) {
//			xiang = ans / 2 * (ans + 1);
//		} else {
//			xiang = (ans + 1) / 2 * ans;
//		}
//
//		if (xiang == m) cout << ans << endl;
//		else {
//			if (ans % 2 == 0) {
//				cout << m - ans / 2 * (ans + 1) << endl;
//			} else {
//				cout << m - ans * (ans + 1) / 2 << endl;
//			}
//		}
//	}
//	return 0;
//}


//E
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 1e5 + 3;
//vector<int> g[N];
//bool vis[N];
//int sum, n, x;
//
//void dfs(int s, int x) {
//	for (int i : g[s]) {
//		if (vis[i]) continue;
//		vis[i] = 1;
//		dfs(i, x + 1);
//	}
//	sum = max(sum, x);
//}
//
//int main() {
//	cin >> n >> x;
//	int t = n - 1;
//	int u, v;
//	while (t--) {
//		cin >> u >> v;
//		g[u].push_back(v);
//		g[v].push_back(u);
//	}
//	vis[x] = 1;
//	dfs(x, 0);
//	cout << 2 * (n - 1) - sum << endl;
//
//	return 0;
//}


//F
//#include<bits/stdc++.h>
//using namespace std;
//
//const int N = 1e5 + 5;
//int a[N], b[N];
//int add[4] = {2, 2, -2, -2};
//
//signed main() {
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++) cin >> a[i];
//	if (n <= 3) cout << "NO" << endl;
//	else {
//		cout << "YES" << endl;
//		if (n % 4 == 0) {
//			b[1] = 3;
//			b[2] = 4;
//			b[3] = 1;
//			b[4] = 2;
//		} else if (n % 4 == 1) {
//			b[1] = 3;
//			b[2] = 4;
//			b[3] = 5;
//			b[4] = 1;
//			b[5] = 2;
//		} else if (n % 4 == 2) {
//			b[1] = 3;
//			b[2] = 4;
//			b[3] = 5;
//			b[4] = 6;
//			b[5] = 2;
//			b[6] = 1;
//		} else if (n % 4 == 3) {
//			b[1] = 3;
//			b[2] = 4;
//			b[3] = 5;
//			b[4] = 6;
//			b[5] = 7;
//			b[6] = 1;
//			b[7] = 2;
//		}
//
//		int yu = n % 4;
//		int idx = 0;
//		for (int i = 5 + yu; i <= n; i++) {
//			b[i] = i + add[idx];
//			idx++;
//			idx%=4;
//		}
//
//		for (int i = 1; i <= n; i++) {
//			cout << b[a[i]] << ' ';
//		}
//		cout << endl;
//	}
//
//	return 0;
//}

