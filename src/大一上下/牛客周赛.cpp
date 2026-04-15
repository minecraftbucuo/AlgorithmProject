// 2024 12 22 牛客周赛 Round 73

//小红的正整数构造
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int l, r, x;
//	cin >> l >> r >> x;
//	int i;
//	for (i = l; i <= r; i++) {
//		if (i % x == 0) {
//			cout << i << endl;
//			break;
//		}
//	}
//	if (i == r + 1) {
//		cout << -1 << endl;
//	}
//	return 0;
//}


//小红的区间构造
//#include <bits/stdc++.h>
//using namespace std;
//
//#define int long long
//
//signed main() {
//	int n, k, x;
//	cin >> n >> k >> x;
//	if (x == 1) {
//		if (k != n) cout << -1 << endl;
//		else {
//			cout << 1 << ' ' << k << endl;
//		}
//	} else {
//		int max_len = (n + 1) * x - 1;
//		int min_len = n * x - x + 1;
//		if (k >= min_len && k <= max_len) {
//			if (k < n * x) {
//				cout << n * x - k + 1 << ' ' << n * x << endl;
//			} else {
//				cout << 1 << ' ' << k << endl;
//			}
//		} else {
//			cout << -1 << endl;
//		}
//	}
//	return 0;
//}


//小红的排列构造
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	string s;
//	cin >> n >> s;
//	bool no_ans = false;
//	int sum = 0;
//	for (int i = 0; i < n; i++) {
//		if (s[i] == '0') {
//			sum++;
//		}
//	}
//	if (sum == n) no_ans = true;
//	if (s[n - 1] == '0') no_ans = true;
//	if (no_ans) cout << -1 << endl;
//	else {
//		vector<bool> vis(n + 3);
//		vector<int> ans;
//		int minx = 1;
//		for (int i = 0; i < n; i++) {
//			if (s[i] == '0') {
//				if (i == 0) {
//					ans.push_back(2);
//					vis[2] = 1;
//				} else {
//					if (s[i - 1] == '1') {
//						ans.push_back(i + 2);
//						vis[i + 2] = 1;
//					} else {
//						ans.push_back(ans.back() + 1);
//						vis[ans.back()] = 1;
//					}
//				}
//			} else {
//				for (int i = minx; ; i++) {
//					if (!vis[i]) {
//						ans.push_back(i);
//						vis[i] = 1;
//						minx = i + 1;
//						break;
//					}
//				}
//			}
//		}
//
//		for (int i = 0; i < n; i++) {
//			cout << ans[i] << ' ';
//		}
//	}
//	return 0;
//}


//小红的01子序列构造（easy）无法战胜
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	
//	return 0;
//}




// 小苯的矩阵反转
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<string> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		vector<int> lie(m), hang(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == '1') {
					hang[i]++;
					lie[j]++;
				}
			}
		}
		
//		cout << endl;
//		for (int i = 0; i < n; i++) cout << hang[i] << ' ';
//		cout << endl;
//		for (int i = 0; i < m; i++) cout << lie[i] << ' ';
//		cout << endl;
		
		bool hang_manzu = false;
		
		int cnt = 0;
		int cnt0 = 0;
		for (int i = 0; i < n; i++) cnt0 += hang[i];
		for (int i = 0; i < n; i++) {
			if (hang[i] == m) {
				cnt++;
				if (cnt == 2) {
					hang_manzu = true;
				} else if (cnt >= 3) {
					hang_manzu = false;
					break;
				}
			} else {
				if (hang[i] != 0) {
					cnt0++;
					hang_manzu = false;
					break;
				}
			}
		}
		if (hang_manzu || cnt0 == 0) {
			cout << "YES" << endl;
			continue;
		}
		
		bool lie_manzu = false;
		cnt = 0;
		cnt0 = 0;
		for (int i = 0; i < n; i++) cnt0 += hang[i];
		for (int i = 0; i < m; i++) {
			if (lie[i] == n) {
				cnt++;
				if (cnt == 2) lie_manzu = true;
				else if (cnt >= 3) {
					lie_manzu = false;
					break;
				}
			} else {
				if (lie[i] != 0) {
					lie_manzu = false;
					break;
				}
			}
		}
		if (lie_manzu) {
			cout << "YES" << endl;
			continue;
		}
		
		int cnt01 = 0;
		bool manzu = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == '0') {
					if (hang[i] == m - 1 && lie[j] == n - 1) {
						cnt01++;
					} else if (hang[i] == 1 && lie[j] == 1) {
						
					} else {
						manzu = false;
						break;
					}
				}
			}
		}
		
		if (manzu && cnt01 == 1) {
			cout << "YES" << endl;
			continue;
		}
		
		cout << "NO" << endl;
	}
	return 0;
}


