// #include<bits/stdc++.h>
// using namespace std;

// int main() {
// 	long long n;
// 	long long ans;
// 	string s;
// 	int t;
// 	cin >> t;
// 	while (t--) {
// 		cin >> n;
// 		ans = n;
// 		s = to_string(n);
// 		for (int i = 0; i < (int)s.size() - 1; i++) {
// 			string temp(s.begin() + 1, s.end());
// 			s = temp + s[0];
// 			ans = min(stoll(s), ans);
// 		}

// 		cout << ans << endl;
// 	}

// 	return 0;
// }