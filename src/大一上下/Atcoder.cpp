// 389   2025.1.20
// A
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	string s;
//	cin >> s;
//	int a = s[0] - '0';
//	int b = s[2] - '0';
//	cout << a * b;
//	return 0;
//}



// B
//#include <bits/stdc++.h>
//using namespace std;
//
//#define int long long
//
//int f[50];
//
//signed main() {
//	f[0] = 1;
//	f[1] = 1;
//	for (int i = 2; i < 50; i++) f[i] = f[i - 1] * i;
//	int x;
//	cin >> x;
//	for (int i = 1; i < 50; i++) {
//		if (f[i] == x) {
//			cout << i << endl;
//			break;
//		}
//	}
//	return 0;
//}



// C
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//struct snake {
//	int tou;
//	int len;
//};
//
//int main() {
//	int q;
//	cin >> q;
//	vector<snake> a;
//	int jian = 0;
//	int cnt = 0;
//	while (q--) {
//		int t, k;
//		cin >> t;
//		if (t == 1) {
//			cin >> k;
//			if (a.size() - cnt == 0) {
//				a.push_back({0, k});
//				jian = 0;
//			} else a.push_back({a.back().tou + a.back().len, k});
//		} else if (t == 2) {
//			jian += a[0 + cnt].len;
//			cnt++;
//		} else {
//			cin >> k;
//			cout << a[k - 1 + cnt].tou - jian << endl;
//		}
//	}
//	return 0;
//}



