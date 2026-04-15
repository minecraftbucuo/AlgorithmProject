// gcd 之和
//#include<bits/stdc++.h>
//using namespace std;
//
//using ll = long long;
//
//void xiangjia(vector<int>& dest, ll n) {
//	string n_s = to_string(n);
//	vector<int> n_v(31);
//	for (int i = 0; i < (int)n_s.size(); i++) {
//		n_v[i] = n_s[n_s.size() - 1 - i] - '0';
//	}
//
//	int x = 0;
//	for (int i = 0; i <= 30; i++) {
//		dest[i] = dest[i] + n_v[i] + x;
//		x = dest[i] / 10;
//		dest[i] %= 10;
//	}
//}
//
//ll f(vector<ll>& a, vector<vector<ll>>& huo, vector<vector<ll>>& gcdzhi, int l, int r) {
////	if (huo[l][r] == -1) {
////		if (r - 1 > 0 && huo[l][r - 1] != -1) {
////			huo[l][r] = huo[l][r - 1] | a[r];
////		} else {
////			huo[l][r] = 0;
////			for (int i = l; i <= r; i++) {
////				huo[l][r] |= a[i];
////			}
////		}
////		huo[l][r] = huo[l][r - 1] | a[r];
////	}
//	if (l != r) {
//		huo[l][r] = huo[l][r - 1] | a[r];
//		gcdzhi[l][r] = gcd(gcdzhi[l][r - 1], a[r]);
//	}
//
////	if (gcdzhi[l][r] == -1) {
////		if (r - 1 > 0 && gcdzhi[l][r - 1] != -1) {
////			gcdzhi[l][r] = gcd(gcdzhi[l][r - 1], a[r]);
////		} else {
////			gcdzhi[l][r] = 0;
////			for (int i = l; i <= r; i++) {
////				gcdzhi[l][r] = gcd(gcdzhi[l][r], a[i]);
////			}
////		}
////		gcdzhi[l][r] = gcd(gcdzhi[l][r - 1], a[r]);
////	}
//
//	return gcdzhi[l][r] * huo[l][r];
//}
//
//int main() {
//	int t, n;
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		vector<ll> a(n + 1);
//		vector<vector<ll>> huo(n + 1, vector<ll>(n + 1, -1));
//		vector<vector<ll>> gcdzhi(n + 1, vector<ll>(n + 1, -1));
//
//		for (int i = 1; i <= n; i++) huo[i][i] = a[i];
//		for (int i = 1; i <= n; i++) gcdzhi[i][i] = a[i];
//
//		for (int i = 1; i <= n; i++) cin >> a[i];
//		vector<int> ans(31);
//		for (int l = 1; l <= n; l++) {
//			for (int r = l; r <= n; r++) {
//				xiangjia(ans, f(a, huo, gcdzhi, l, r));
//			}
//		}
//
//		while (ans.back() == 0 && ans.size() > 1) ans.pop_back();
//		for (int i = ans.size() - 1; i >= 0; i--) {
//			cout << ans[i];
//		}
//		cout << endl;
//
//	}
//	return 0;
//}


//斐波那契
//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int q, x, y, n;
//	cin >> q;
//	while (q--) {
//		cin >> x >> y >> n;
//		if (x % 2 == 0 && y % 2 == 0) cout << 0 << endl;
//		else if (x % 2 == 0 && y % 2 != 0) {
//			n = n % 3;
//			if (n == 1) cout << 0 << endl;
//			else if (n == 2) cout << 1 << endl;
//			else cout << 1 << endl;
//		} else if (x % 2 != 0 && y % 2 != 0) {
//			n = n % 3;
//			if (n == 1) cout << 1 << endl;
//			else if (n == 2) cout << 1 << endl;
//			else cout << 0 << endl;
//		} else {
//			n = n % 3;
//			if (n == 1) cout << 1 << endl;
//			else if (n == 2) cout << 0 << endl;
//			else cout << 1 << endl;
//		}
//
//	}
//	return 0;
//}


//劳苏的数字
//#include<bits/stdc++.h>
//using namespace std;
//
//bool is_3(string s) {
//	int a = 0;
//	for (int i = 0; i < (int)s.length(); i++) {
//		a += s[i] - '0';
//	}
//	if (a % 3 == 0) return true;
//	else return false;
//}
//
//int main() {
//	int t;
//	string a, b, c;
//	cin >> t;
//	while (t--) {
//		cin >> a >> b >> c;
//		if (is_3(a) || is_3(b) || is_3(c)) cout << "LaoSu Like Fake" << endl;
//		else cout << "LaoSu Don't Like Fake" << endl;
//	}
//	return 0;
//}


//乖乖起飞！
//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int t, n, ans;
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		ans = 0;
//		vector<int> a(n + 1);
//		for (int i = 1; i <= n; i++) cin >> a[i];
//		queue<pair<int, int>> q;
//		q.push(make_pair(a[1], 0));
//		vector<bool> vis(n + 1);
//		while (!q.empty()) {
//			int pos = q.front().first;
//			int ans_ = q.front().second;
//			q.pop();
//			vis[pos] = 1;
//
//			vector<int> houxuan = {pos + 1, pos - 1, pos + a[pos], pos - a[pos]};
//			if (pos == n) {
//				ans = ans_ - 1;
//				break;
//			}
//			for (int i = 0; i < 4; i++) {
//				if (houxuan[i] < 1 || houxuan[i] > n || vis[houxuan[i]]) continue;
//				q.push(make_pair(houxuan[i], ans_ + 1));
//				vis[houxuan[i]] = 1;
//			}
//		}
//
//		cout << ans << endl;
//	}
//	return 0;
//}


// 环形取数
//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int t, n;
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		vector<int> a(n);
//		for (int i = 0; i < n; i++) {
//			cin >> a[i];
//		}
//	}
//	return 0;
//}


// Never Loneliness   写的屎山
//#include<bits/stdc++.h>
//using namespace std;
//
//#define int long long
//
//signed main() {
//	int t, n;
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		int ans = 0;
//		vector<int> a(n);
//		for (int i = 0; i < n; i++) cin >> a[i];
//
//		if (a[0] > 0) {
//			int ans1 = 0, ans2 = 0;
//			vector<int> sum(n);
//			sum[0] = a[0];
//			for (int i = 1; i < n; i++) {
//				sum[i] = sum[i - 1] + a[i];
//				if (i % 2) {
//					if (sum[i] >= 0) {
//						ans1 += sum[i] + 1;
//						sum[i] = -1;
//					}
//				} else {
//					if (sum[i] <= 0) {
//						ans1 += 1 - sum[i];
//						sum[i] = 1;
//					}
//				}
//			}
//
//			sum[0] = -1;
//			ans2 = a[0] + 1;
//			for (int i = 1; i < n; i++) {
//				sum[i] = sum[i - 1] + a[i];
//				if (i % 2 == 0) {
//					if (sum[i] >= 0) {
//						ans2 += sum[i] + 1;
//						sum[i] = -1;
//					}
//				} else {
//					if (sum[i] <= 0) {
//						ans2 += 1 - sum[i];
//						sum[i] = 1;
//					}
//				}
//			}
//
//			ans = min(ans1, ans2);
//
//		} else if (a[0] < 0) {
//			int ans1 = 0, ans2 = 0;
//			vector<int> sum(n);
//			sum[0] = a[0];
//			for (int i = 1; i < n; i++) {
//				sum[i] = sum[i - 1] + a[i];
//				if (i % 2 == 0) {
//					if (sum[i] >= 0) {
//						ans1 += sum[i] + 1;
//						sum[i] = -1;
//					}
//				} else {
//					if (sum[i] <= 0) {
//						ans1 += 1 - sum[i];
//						sum[i] = 1;
//					}
//				}
//			}
//
//			sum[0] = 1;
//			ans2 =  -a[0] + 1;
//			for (int i = 1; i < n; i++) {
//				sum[i] = sum[i - 1] + a[i];
//				if (i % 2) {
//					if (sum[i] >= 0) {
//						ans2 += sum[i] + 1;
//						sum[i] = -1;
//					}
//				} else {
//					if (sum[i] <= 0) {
//						ans2 += 1 - sum[i];
//						sum[i] = 1;
//					}
//				}
//			}
//
//			ans = min(ans1, ans2);
//
//		} else {
//			int ans1 = 1, ans2 = 1;
//			vector<int> sum(n);
//			sum[0] = 1;
//			for (int i = 1; i < n; i++) {
//				sum[i] = sum[i - 1] + a[i];
//				if (i % 2) {
//					if (sum[i] >= 0) {
//						ans1 += sum[i] + 1;
//						sum[i] = -1;
//					}
//				} else {
//					if (sum[i] <= 0) {
//						ans1 += 1 - sum[i];
//						sum[i] = 1;
//					}
//				}
//			}
//
//			sum[0] = -1;
//			for (int i = 1; i < n; i++) {
//				sum[i] = sum[i - 1] + a[i];
//				if (i % 2 == 0) {
//					if (sum[i] >= 0) {
//						ans2 += sum[i] + 1;
//						sum[i] = -1;
//					}
//				} else {
//					if (sum[i] <= 0) {
//						ans2 += 1 - sum[i];
//						sum[i] = 1;
//					}
//				}
//			}
//
//			ans = min(ans1, ans2);
//
//		}
//
//		cout << ans << endl;
//	}
//	return 0;
//}
