// 题目 3290: 蓝桥杯2024年第十五届决赛真题-蚂蚁开会
// #include <map>
// #include <iostream>
// using namespace std;
//
// int gcd(int a, int b) {
//	if (a == 0) return b;
//	return gcd(b % a, a);
// }
//
//
// int main() {
//	int n, x1, x2, y1, y2;
//	cin >> n;
//	map<pair<int, int>, int> mp;
//	map<pair<int, int>, int> vis;
//
//	int ans = 0;
//
//	while (n--) {
//		cin >> x1 >> y1 >> x2 >> y2;
//		int g = gcd(abs(x1 - x2), abs(y1 - y2));
//		int x_ = (x2 - x1) / g;
//		int y_ = (y2 - y1) / g;
//		int x = x1, y = y1;
//
//		while (x != x2 || y != y2) {
//			mp[make_pair(x, y)]++;
//
//			if (mp[make_pair(x, y)] >= 2 && !vis[make_pair(x, y)]) {
//				ans++;
//				vis[make_pair(x, y)] = 1;
//			}
//
//			x += x_;
//			y += y_;
//		}
//
//		mp[make_pair(x2, y2)]++;
//		if (mp[make_pair(x2, y2)] >= 2 && !vis[make_pair(x2, y2)]) {
//			ans++;
//			vis[make_pair(x2, y2)] = 1;
//		}
//	}
//
//	cout << ans << endl;
//	return 0;
// }

// 题目 3291: 蓝桥杯2024年第十五届决赛真题-立定跳远
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//	int n, m, ans;
//	cin >> n >> m;
//	m++;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//	int left = 1, right = *max_element(a.begin(), a.end());
//	while (left <= right) {
//		int x = 0, mid = (left + right) >> 1;
//		for (int i = 1; i < n; i++) {
//			int juli = a[i] - a[i - 1];
//			if (juli > mid) {
//				if (juli % mid == 0) {
//					x += juli / mid - 1;
//				} else {
//					x += juli / mid;
//				}
//			}
//		}
//
//		if (x <= m) {
//			ans = mid;
//			right = mid - 1;
//		} else {
//			left = mid + 1;
//		}
//	}
//
//	cout << ans << endl;
//	return 0;
// }

// 题目 3292: 蓝桥杯2024年第十五届决赛真题-最小字符串
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;
    sort(s2.begin(), s2.end());
    string ans;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (s1[i] > s2[j])
        {
            ans += s2[j++];
        }
        else
        {
            ans += s1[i++];
        }
    }

    for (; i < n; i++)
    {
        ans += s1[i];
    }

    for (; j < m; j++)
    {
        ans += s2[j];
    }

    cout << ans << endl;

    return 0;
}
