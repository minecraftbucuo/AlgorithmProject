// 1
//#include<iostream>
//using namespace std;
//int main() {
//	string ans [] = {
//		"1204", // 双引号中替换为 A 题的答案
//		"1100325199.77", // 双引号中替换为 B 题的答案
//	};
//	char T;
//	cin >> T;
//	cout << ans[T - 'A'] << endl;
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//	long long chang = 343720;
//	long long kuang = 233333;
//	int x = 15, y = 17;
//	for (; ; x += 15, y += 17) {
//		if (x % (2 * chang) == 0 && y % (2 * kuang) == 0) break;
//	}
//	cout << x * x + y * y << endl;
//	printf("%.2Lf", sqrtl(x * x + y * y));
//	return 0;
//}



// 2
//#include <bits/stdc++.h>
//using namespace std;
//
//bool is_hao(int x) {
//	string s = to_string(x);
//	reverse(s.begin(), s.end());
//	for (int i = 0; i < (int)s.size(); i += 2) {
//		if ((s[i] - '0') % 2 == 0)
//			return false;
//	}
//
//	for (int i = 1; i < (int)s.size(); i += 2) {
//		if ((s[i] - '0') % 2 != 0)
//			return false;
//	}
//
//	return true;
//}
//
//int main() {
//	int n;
//	cin >> n;
//	int ans = 0;
//	for (int i = 0; i <= n; i++) {
//		if (is_hao(i)) ans++;
//	}
//	cout << ans << endl;
//	return 0;
//}


// 3
#include <bits/stdc++.h>
using namespace std;

string chen(string s, int b) {
	string res;
	int t = 0;
	reverse(s.begin(), s.end());
	for (int i = 0; i < (int)s.size(); i++) {
		t = t + b * (s[i] - '0');
		res.push_back(t % 10);
		t /= 10;
	}
	while (t) {
		res.push_back(t % 10);
		t /= 10;
	}
	for (int i = 0; i < (int)res.size(); i++) {
		res[i] += '0';
	}
	return string(res.rbegin(), res.rend());
}

string chen(string s1, string s2) {
	string res(s1.size() + s2.size() + 1, 0);
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	for (int i = 0; i < (int)s1.size(); i++) {
		for (int j = 0; j < (int)s2.size(); j++) {
			int a = s1[i] - '0';
			int b = s2[j] - '0';
			res[i + j] += a * b;
			res[i + j + 1] += res[i + j] / 10;
			res[i + j] %= 10;
		}
	}
	while (res.size() > 1 && res.back() == 0) res.pop_back();
	for (int i = 0; i < (int)res.size(); i++) {
		res[i] += '0';
	}
	return string(res.rbegin(), res.rend());
}

int main() {
	string two = "1";
	int n;
	cin >> n;
	string s_d;
	cin >> s_d;
	int dot_pos = -1;
	for (int i = 0; i < (int)s_d.size(); i++) {
		if (s_d[i] == '.') {
			dot_pos = i;
			s_d.erase(s_d.begin() + i);
			break;
		}
	}
	dot_pos = s_d.size() - dot_pos;
	for (int i = 1; i <= n; i++) {
		two = chen(two, 2);
	}
	string ans = chen(two, s_d);
	if (ans[ans.size() - dot_pos] >= '5') {
		for (int i = ans.size() - dot_pos - 1; i >= 0; i--) {
			ans[i] -= '0';
			if (i == (int)ans.size() - dot_pos - 1) {
				ans[i] += 1;
			}
			ans[i] %= 10;
			ans[i - 1] += ans[i] / 10;
			ans[i] += '0';
		}
	}
	for (int i = 0; i < (int)ans.size() - dot_pos; i++) {
		cout << ans[i];
	}
	return 0;
}



// 4
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++) cin >> a[i];
//	sort(a.begin(), a.end());
//	vector<int> cnt(1e5 + 1);
//	int maxn = 0;
//	for (int i = 0; i < n; i++) {
//		for (int j = 1; j <= a[i] / j; j++) {
//			if (a[i] % j == 0) {
//				cnt[j]++;
//				if (a[i] / j != j) cnt[a[i] / j]++;
//				maxn = max(maxn, a[i] / j);
//			}
//		}
//	}
//	int x = -1;
//	for (int i = maxn; i >= 1; i--) {
//		if (cnt[i] >= 3) {
//			x = i;
//			break;
//		}
//	}
//	for (int i = 0, y = 0; i < n && y < 3; i++) {
//		if (a[i] % x == 0) {
//			cout << a[i] << ' ';
//			y++;
//		}
//	}
//	return 0;
//}



// 5   妈的题目意思都理解错了，做尼玛呢
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	int sum = 0;
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//		sum = sum + a[i];
//	}
//	vector<int> b = a;
//	sort(b.begin(), b.end());
//	unordered_map<int, int> dp;
//	for (int i = 0; i < n; i++) {
//		for (int j = sum / 2; j >= a[i]; j--) {
//			dp[j] = max(dp[j - a[i]] + a[i], dp[j]);
//		}
//	}
//	cout << sum - 2 * dp[sum / 2] << endl;
//	return 0;
//}


// AC Code
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//	int n;
//	cin >> n;
//	vector<int> a(n + 2);
//	int ans = 1e17;
//	for (int i = 1; i <= n; i++) cin >> a[i];
//	for (int i = 1; i <= n; i++) a[i] += a[i - 1];
//	for (int i = 1; i < n; i++) {
//		for (int j = i; j < n; j++) {
//			int l = i - 1, r = j + 1;
//			while (l >= 0 && r <= n) {
//				ans = min(ans, abs(a[i] - a[l] - (a[r] - a[j])));
//				if (a[i] - a[l] > a[r] - a[j]) r++;
//				else l--;
//			}
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}
