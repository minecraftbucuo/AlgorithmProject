//#include <bits/stdc++.h>
//using namespace std;
//
//unordered_map<string, int> mp = {
//	{"tourist", 3858},
//	{"ksun48", 3679},
//	{"Benq", 3658},
//	{"Um_nik", 3648},
//	{"apiad", 3638},
//	{"Stonefeang", 3630},
//	{"ecnerwala", 3613},
//	{"mnbvmar", 3555},
//	{"newbiedmy", 3516},
//	{"semiexp", 3481}
//};
//
//int main() {
//	string s;
//	cin >> s;
//	cout << mp[s] << endl;
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 0; i <= n; i++) {
//		int j = 1;
//		for (; j <= 9; j++) {
//			if (n % j == 0) {
//				if (i % (n / j) == 0) {
//					cout << j;
//					break;
//				}
//			}
//		}
//		if (j >= 10) cout << '-';
//	}
//	return 0;
//}


// 59c4a227d33b875c9b5926de2258661221574466-%00UserName%3Aminecraftbucuo%00%00a%3Afalse%00%00w%3Afalse%00%00_TS%3A1758263306%00%00csrf_token%3AW0EIcsdMbtOaXXUP9xhXuaQ5GLG4OYjBms2hHA2EUx0%3D%00%00SessionKey%3A5cf583dd7a8a20287bdb9929b9690977b3d73b75ea9bdf5793a3709cb7f96c83%00%00UserScreenName%3Aminecraftbucuo%00


//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	string s;
//	cin >> s;
//	if (s == "ABC") cout << "ARC";
//	else cout << "ABC";
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<pair<int, int>> a(n);
//	for (int i = 0; i < n; i++) {
//		cin >> a[i].first >> a[i].second;
//	}
//	if (n == 1) cout << 0 << endl;
//	else {
//		int ans = 0;
//		for (int i = 0; i < n - 1; i++) {
//			for (int j = i + 1; j < n; j++) {
//				double k = 1.0 * (a[j].second - a[i].second) / (a[j].first - a[i].first);
//				if (k >= -1 && k <= 1) ans++;
//			}
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int h, w, n;
//	cin >> h >> w >> n;
//	vector<array<int, 2>> a(n);
//	for (int i = 0; i < n; i++) {
//		cin >> a[i][0] >> a[i][1];
//	}
//	vector<int> x;
//	vector<int> y;
//	for (int i = 0; i < n; i++) {
//		x.push_back(a[i][0]);
//		y.push_back(a[i][1]);
//	}
//	sort(x.begin(), x.end());
//	sort(y.begin(), y.end());
//	x.erase(unique(x.begin(), x.end()), x.end());
//	y.erase(unique(y.begin(), y.end()), y.end());
//	for (int i = 0; i < n; i++) {
//		int x_ = (lower_bound(x.begin(), x.end(), a[i][0]) - x.begin()) + 1;
//		int y_ = (lower_bound(y.begin(), y.end(), a[i][1]) - y.begin()) + 1;
//		cout << x_ << ' ' << y_ << endl;
//	}
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//	int n, k;
//	cin >> n >> k;
//	vector<int> a(n + 1);
//	for (int i = 1; i <= n; i++) cin >> a[i];
//	vector<int> sum(n + 1);
//	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
//	unordered_map<int, int> mp;
//	int ans = 0;
//	mp[0] = 1;
//	for (int i = 1; i <= n; i++) {
//		ans += mp[sum[i] - k];
//		mp[sum[i]]++;
//	}
//	cout << ans << endl;
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//	int a, b;
//	cin >> a >> b;
//	int ans = 0;
//	while (b) {
//		int a_ = a, b_ = b;
//		a = min(a_, b_);
//		b = max(a_, b_);
//		ans += b / a;
//		b %= a;
//	}
//	cout << ans - 1 << endl;
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//	int n, k;
//	cin >> n >> k;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++) cin >> a[i];
//	set<int> s;
//	for (int i = 0; i < n; i++) s.insert(a[i]);
//	int ans = 0;
//	for (int i = 1; i <= k; i++) {
//		ans = *s.begin();
//		s.erase(s.begin());
//		for (int i = 0; i < n; i++)
//			s.insert(ans + a[i]);
//	}
//	cout << ans << endl;
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n, x, y;
//	cin >> n;
//	vector<pair<int, int>> a(n);
//	for (int i = 0; i < n; i++) {
//		cin >> x >> y;
//		a[i].first = min(x, y);
//		a[i].second = max(x, y);
//	}
//	sort(a.begin(), a.end());
//	set<int> s;
//	bool is_jiao = false;
//	for (int i = 0; i < n; i++) {
//		if (s.empty()) s.insert(a[i].second);
//		else {
//			if (a[i].first < *s.begin()) {
//				if (a[i].second > *s.begin()) {
//					is_jiao = true;
//					break;
//				} else {
//					s.insert(a[i].second);
//				}
//			} else {
//				while (!s.empty() && a[i].first > *s.begin()) s.erase(s.begin());
//				if (s.empty()) {
//					s.insert(a[i].second);
//				} else {
//					if (a[i].second > *s.begin()) {
//						is_jiao = true;
//						break;
//					} else {
//						s.insert(a[i].second);
//					}
//				}
//			}
//		}
//	}
//	if (is_jiao) cout << "Yes" << endl;
//	else cout << "No" << endl;
//	return 0;
//}

