//#include <iostream>
//#include <vector>
//
//using namespace std;
//// 2024 10 8 A
//int main() {
//	int t, n, k, x;
//	cin >> t;
//	for (int i = 0; i < t; i++) {
//		cin >> n >> k >> x;
//		if (k - x >= 2) {
//			cout << -1 << endl;
//		} else if (k - x == 1 && n < x + 1) {
//			cout << -1 << endl;
//		} else if (k == x && n < x) {
//			cout << -1 << endl;
//		} else if (n < k) {
//			cout << -1 << endl;
//		} else {
//			vector<int> vec(n);
//			for (int i = 0; i < k; i++) {
//				vec[i] = i;
//			}
//			if (k != x) {
//				for (int i = k; i < n; i++) {
//					vec[i] = x;
//				}
//			} else {
//				for (int i = k; i < n; i++) {
//					vec[i] = x - 1;
//				}
//			}
//
//			int sum = 0;
//			for (int num : vec) {
//				sum += num;
//			}
//			cout << sum << endl;
//		}
//	}
//
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//// 2024 10 9 B
//
//int main() {
//	int t;
//	cin >> t;
//	string s;
//	for (int i = 0; i < t; i++) {
//		cin >> s;
//
//		if (s == "abc") {
//			cout << "YES" << endl;
//		} else if (s == "acb") {
//			cout << "YES" << endl;
//		} else if (s == "bac") {
//			cout << "YES" << endl;
//		} else if (s == "bca") {
//			cout << "NO" << endl;
//		} else if (s == "cab") {
//			cout << "NO" << endl;
//		} else {
//			cout << "YES" << endl;
//		}
//	}
//	return 0;
//}


//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//  C
//int main() {
//	int t, n;
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		vector<int> vec(n);
//		for (int i = 0; i < n; i++) {
//			cin >> vec[i];
//		}
//		sort(vec.begin(), vec.end());
//		vec[0]++;
//		int ans = 1;
//		for (int num : vec) {
//			ans *= num;
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}

//2024 10 11 D
//#include<bits/stdc++.h>
//using namespace std;
//
//int fen(int i, int j) {
//	if (i == 0 || i == 9 || j == 0 || j == 9) return 1;
//	if (i == 1 || i == 8 || j == 1 || j == 8) return 2;
//	if (i == 2 || i == 7 || j == 2 || j == 7) return 3;
//	if (i == 3 || i == 6 || j == 3 || j == 6) return 4;
//	if (i == 4 || i == 5 || j == 4 || j == 5) return 5;
//}
//
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int ans = 0;
//		char x;
//		for (int i = 0; i < 10; i++) {
//			for (int j = 0; j < 10; j++) {
//				cin >> x;
//				if (x == 'X') {
//					ans += fen(i, j);
//				}
//			}
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}


// 2024 10 12-13 E 暂未做出 这种解题逻辑太傻逼了，唉
// 记录一下吧，我10.12做的，用这傻逼方法，半天都错，从22：10多做到1：30多
// 今天问了学长思路，让我懂得了正确解题思路的重要性，不然怎么努力都是白费
//#include <bits/stdc++.h>
//using namespace std;
//
//bool panduan(string s1, string s2) {
//	if (s1 == s2) {
//		return true;
//	} else {
//		int n = s1.size();
//		vector<int> s3(n);
//		for (int i = 0; i < n; i++) {
//			if (s1[i] == s2[i] && s1[i] == '1') s3[i] = 1;
//			else if (s1[i] == s2[i] && s1[i] == '0') s3[i] = 0;
//			else s3[i] = -1;
//		}
//
//		vector<vector<int>> fuzhu;
//		int i = 1;
//		while (i < n) {
//			if (s3[i] != -1) {
//				i++;
//				continue;
//			} else {
//				if (fuzhu.size() == 0) {
//					int left1 = 0;
//					int right1 = n - 1;
//					while (s3[left1] != s3[right1] && right1 - left1 > 1) {
//						right1--;
//					}
//					int x = 0, left2 = 1;
//					while (s3[x] == s3[left2] && left2 < i) {
//						left2++;
//					}
//					bool path2 = true;
//					if (left2 == i) {
//						left2--;
//						path2 = false;
//					}
//					int right2 = n - 1;
//					while (s3[left2] != s3[right2] && right2 - left2 > 1) {
//						right2--;
//					}
//					if (right2 - left2 <= 1 && right1 - left1 <= 1) {
//						return false;
//					}
//
//					if (path2 == false) {
//						fuzhu.push_back({left1, right1});
//					} else {
//						if (right2 - left2 > right1 - left1) {
//							fuzhu.push_back({left2, right2});
//						} else {
//							fuzhu.push_back({left1, right1});
//						}
//					}
//
//					i = fuzhu[0][1] + 1;
//				} else {
//					int left1 = fuzhu[fuzhu.size() - 1][1];
//					int right1 = n - 1;
//					while (s3[left1] != s3[right1] && right1 - left1 > 1) {
//						right1--;
//					}
//					int x = fuzhu[fuzhu.size() - 1][1], left2 = fuzhu[fuzhu.size() - 1][1] + 1;
//					while (s3[x] == s3[left2] && left2 < i) {
//						left2++;
//					}
//					bool path2 = true;
//					if (left2 == i) {
//						left2--;
//						path2 = false;
//					}
//					int right2 = n - 1;
//					while (s3[left2] != s3[right2] && right2 - left2 > 1) {
//						right2--;
//					}
//					if (right2 - left2 <= 1 && right1 - left1 <= 1) {
//						return false;
//					}
//
//					if (path2 == false) {
//						fuzhu.push_back({left1, right1});
//					} else {
//						if (right2 - left2 > right1 - left1) {
//							fuzhu.push_back({left2, right2});
//						} else {
//							fuzhu.push_back({left1, right1});
//						}
//					}
//
//					i = fuzhu[fuzhu.size() - 1][1] + 1;
//				}
//			}
//
//		}
//
//		return true;
//	}
//}
//
//int main() {
//	int t;
//	cin >> t;
//	string s1, s2;
//	while (t--) {
//		cin >> s1 >> s2;
//		if (panduan(s1, s2)) {
//			cout << "YES" << endl;
//		} else {
//			cout << "NO" << endl;
//		}
//	}
//	return 0;
//}

// 同上一题 E 感谢吴欣达学长点拨做出来了 2024 10 13
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int t;
//	cin >> t;
//	string s1, s2;
//	while (t--) {
//		cin >> s1 >> s2;
//		int n = s1.size();
//		vector<int> s3(n);
//		for (int i = 0; i < n; i++) {
//			if (s1[i] == s2[i] && s1[i] == '1') s3[i] = 1;
//			else if (s1[i] == s2[i] && s1[i] == '0') s3[i] = 0;
//			else s3[i] = -1;
//		}
//		bool have_ans = false;
//		for (int i = 0; i < n - 1; i++) {
//			if (s3[i] == 0 && s3[i + 1] == 1) {
//				cout << "YES" << endl;
//				have_ans = true;
//				break;
//			}
//		}
//
//		if (!have_ans) {
//			cout << "NO" << endl;
//		}
//	}
//	return 0;
//}


//2024 10 12-13 F 暂未做出 现已做出
//测试样例：
//2
//2 3
//0 1
//1 2 3
//3 1
//1 1 2
//1
//答案
//0 1
//2 3


// 2024 10 13
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//
//	int t, n, m;
//	cin >> t;
//	while (t--) {
//		cin >> n >> m;
//		vector<int> a(n);
//		vector<int> b(m);
//		for (int i = 0; i < n; i++) cin >> a[i];
//		for (int i = 0; i < m; i++) cin >> b[i];
//
//		int a_lei = 0;
//		for (int i = 0; i < n; i++) {
//			a_lei ^= a[i];
//		}
//
//		int b_lei = b[0];
//		for (int i = 1; i < m; i++) {
//			b_lei |= b[i];
//		}
//
//		int x = 0;
//		for (int i = 0; i < n; i++) {
//			x ^= (b_lei | a[i]);
//		}
//
//		int max1 = max(x, a_lei);
//		int min1 = min(x, a_lei);
//
//		cout << min1 << " " << max1 << endl;
//	}
//	return 0;
//}


//2024 10 13-14 G 比较复杂啊这个思路
//#include<bits/stdc++.h>
//using namespace std;
//
//bool panduan(vector<char>& ans, vector<char>& target) {
//	int s_t = target.size();
//	int s_a = ans.size();
//
//	for (int i = 0; i < s_a - s_t + 1; i++) {
//		for (int j = 0; j < s_t; j++) {
//			if (ans[i + j] != target[j]) {
//				break;
//			}
//			if (j == s_t - 1) {
//				return true;
//			}
//		}
//	}
//	return false;
//}
//
//bool is_right(vector<char> s) {
//	stack<char> stack_;
//
//	for (int i = 0; i < s.size(); i++) {
//		if (s[i] == ')') {
//			if (stack_.empty() || stack_.top() == s[i]) {
//				return false;
//			} else {
//				stack_.pop();
//			}
//		} else {
//			stack_.push(s[i]);
//		}
//	}
//
//	return stack_.empty();
//}
//
//void getAns(vector<vector<char>>& ans, vector<char>& s, int dep, int n, int start, vector<char>& target, bool& jixu) {
//	if (jixu) {
//		if (dep == n + 1) {
//			s[0] = '(';
//			s[s.size() - 1] = ')';
//			for (int i = 0; i < s.size(); i++) {
//				if (s[i] == ' ') s[i] = ')';
//			}
//			if (is_right(s))
//				if (!panduan(s, target)) {
//					jixu = false;
//					cout << "YES" << endl;
//					for (int i = 0; i < s.size(); i++) {
//						cout << s[i];
//					}
//					cout << endl;
//				}
//			ans.push_back(s);
//			return;
//		} else {
//			for (int i = start; i < s.size() - 1; i++) {
//				s[i] = '(';
//				getAns(ans, s, dep + 1, n, i + 1, target, jixu);
//				s[i] = ' ';
//			}
//		}
//	}
//}
//
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		string s;
//		cin >> s;
//		vector<char> s1(s.begin(), s.end());
//		int n = s.size();
//		vector<char> s2(2 * n, ' ');
//
//		vector<vector<char>> ans;
//		bool jixu = true;
//
//		getAns(ans, s2, 1, n - 1, 1, s1, jixu);
//
////		for (int i = 0; i < ans.size(); i++) {
////			for (int j = 0; j < ans[i].size(); j++) {
////				cout << ans[i][j];
////			}
////			cout << endl;
////		}
//
//		if (jixu) {
//			cout << "NO" << endl;
//		}
//
//	}
//	return 0;
//}

//同上题G，看看佬码 2024 10 14
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//string find_one(int count, int level, string current, const string& sub) {
//	if (count == 0) {
//		if (current.find(sub) == string::npos) {
//			return current;
//		} else {
//			return string("");
//		}
//	} else {
//		if (level < count) {
//			string result = find_one(count - 1, level + 1, current + '(', sub);
//			if (result != "") {
//				return result;
//			}
//		}
//		if (level > 0) {
//			string result = find_one(count - 1, level - 1, current + ')', sub);
//			if (result != "") {
//				return result;
//			}
//		}
//		return string("");
//	}
//}
//
//int main() {
//	int t;
//	cin >> t;
//	cin.ignore();
//	for (; t > 0; --t) {
//		string s;
//		getline(cin, s);
//		if (s == "(" || s == ")" || s == "()") {
//			cout << "NO" << endl;
//		} else {
//			cout << "YES" << endl;
//			int n = s.size();
//			string result = find_one(2 * n, 0, "", s);
//			cout << result << endl;
//		}
//	}
//	return 0;
//}


//2024 10 15 H
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int n, k;
//		cin >> n >> k;
//		string s;
//		cin >> s;
//		int ans = 0;
//		int p = 0;
//		while (p < n) {
//			if (s[p] == 'B') {
//				for (int i = 0; i < k; i++) {
//					if (p + i < n)
//						s[p + i] = 'W';
//				}
//				ans++;
//				p = p + k;
//			} else {
//				p++;
//			}
//		}
//
//		cout << ans << endl;
//	}
//	return 0;
//}

//2024 10 16 I
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int t;
//	cin >> t;
//	while (t -- ) {
//		int n, k;
//		cin >> n >> k;
//		vector<int> color(n);
//		for (int i = 0; i < n; i++) {
//			cin >> color[i];
//		}
//
//		int left = 0, right = n - 1;
//		int left_n = 0, right_n = 0;
//		bool left_manzu = false, right_manzu = false;
//		while (left < n) {
//			if (color[left] == color[0]) {
//				left_n++;
//			}
//			if (left_n == k) {
//				left_manzu = true;
//				break;
//			}
//			left++;
//		}
//
//		while (right >= 0) {
//			if (color[right] == color[n - 1]) {
//				right_n++;
//			}
//			if (right_n == k) {
//				right_manzu = true;
//				break;
//			}
//			right--;
//		}
//		if (color[0] == color[n - 1] && right_manzu && left_manzu) {
//			cout << "YES" << endl;
//		} else {
//			if (right_manzu && left_manzu && left < right) {
//				cout << "YES" << endl;
//			} else {
//				cout << "NO" << endl;
//			}
//		}
//
//	}
//	return 0;
//}


//2024 10 17 J //此版本会超时
//#include<bits/stdc++.h>
//using namespace std;
//
//long long f(int a, int b, vector<vector<long long>>& pos, int k) {
//	if (a <= k && b <= k) {
//		return 0;
//	} else {
//		return abs(pos[a][0] - pos[b][0]) + abs(pos[a][1] - pos[b][1]);
//	}
//}
//
//long long get_ans(int a, int b, int k, vector<vector<long long>>& pos, int n, int step) {
//	if (step == 1) {
//		return f(a, b, pos, k);
//	}
//	long long min_ans = f(a, b, pos, k);
//	for (int i = 1; i <= n; i++) {
//		if (i == a || i == b) {
//			continue;
//		}
//		min_ans = min(min_ans, get_ans(a, i, k, pos, n, step - 1) + f(i, b, pos, k));
//	}
//	return min_ans;
//}
//
//int main() {
//	int t;
//	cin >> t;
//	int n, k, a, b;
//	while (t--) {
//		cin >> n >> k >> a >> b;
//		vector<vector<long long>> pos(n + 1, vector<long long>(2));
//		for (int i = 1; i <= n; i++) {
//			cin >> pos[i][0] >> pos[i][1];
//		}
//
//		long long ans = get_ans(a, b, k, pos, n, 1);
//		for (int i = 2; i <= n - 1; i++) {
//			ans = min(ans, get_ans(a, b, k, pos, n, i));
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}

// 同上题 J 依然超时 无语了
//#include<bits/stdc++.h>
//using namespace std;
//
//long long f(int a, int b, vector<vector<long long>>& pos, int k) {
//	if (a <= k && b <= k) {
//		return 0;
//	} else {
//		return abs(pos[a][0] - pos[b][0]) + abs(pos[a][1] - pos[b][1]);
//	}
//}
//
//long long get_ans(int a, int b, int k, vector<vector<long long>>& pos, int n, int step, unordered_map<string, long long>& ans_temp) {
//	if (step == 1) {
//		string str = to_string(a) + ' ' + to_string(b) + ' ' + to_string(step);
//		if (ans_temp.find(str) != ans_temp.end()) {
//			return ans_temp[str];
//		} else {
//			ans_temp[str] = f(a, b, pos, k);
//			return ans_temp[str];
//		}
//	}
//	long long min_ans = f(a, b, pos, k);
//	for (int i = 1; i <= n; i++) {
//		if (i == a || i == b) {
//			continue;
//		}
//		string str = to_string(a) + ' ' + to_string(i) + ' ' + to_string(step - 1);
//		if (ans_temp.find(str) != ans_temp.end()) {
//			min_ans = min(min_ans, ans_temp[str] + f(i, b, pos, k));
//		} else {
//			ans_temp[str] = get_ans(a, i, k, pos, n, step - 1, ans_temp);
//			min_ans = min(min_ans, ans_temp[str] + f(i, b, pos, k));
//		}
//	}
//	return min_ans;
//}
//
//int main() {
//	int t;
//	cin >> t;
//	int n, k, a, b;
//	while (t--) {
//		cin >> n >> k >> a >> b;
//		vector<vector<long long>> pos(n + 1, vector<long long>(2));
//		for (int i = 1; i <= n; i++) {
//			cin >> pos[i][0] >> pos[i][1];
//		}
//
//		unordered_map<string, long long> ans_temp;
//
//		long long ans = get_ans(a, b, k, pos, n, n - 1, ans_temp);
//		cout << ans << endl;
//	}
//	return 0;
//}


// 同上题 J 再次改进呜呜呜 终于过了哈哈哈 2024 10 18
//#include<bits/stdc++.h>
//using namespace std;
//
//long long f(int a, int b, vector<vector<long long>>& pos, int k) {
//	if (a <= k && b <= k) {
//		return 0;
//	} else {
//		return abs(pos[a][0] - pos[b][0]) + abs(pos[a][1] - pos[b][1]);
//	}
//}
//
//int main() {
//	int t;
//	cin >> t;
//	int n, k, a, b;
//	while (t--) {
//		cin >> n >> k >> a >> b;
//		vector<vector<long long>> pos(n + 1, vector<long long>(2));
//		for (int i = 1; i <= n; i++) {
//			cin >> pos[i][0] >> pos[i][1];
//		}
//
//		pair<long long, int> ans;
//		ans.first = f(a, b, pos, k);
//		ans.second = a;
//
//		while (ans.second != b) {
//			long long last_step = ans.first - f(ans.second, b, pos, k);
//			long long min_one = f(ans.second, b, pos, k);
//			int min_one_idx = 0;
//			long long flb_min = -1;
//			int flb_min_idx = 0;
//			for (int j = 1; j <= n; j++) {
//				if (j <= k) {
//					if (flb_min == -1) {
//						long long min_2 = f(ans.second, j, pos, k) + f(j, b, pos, k);
//						for (int l = 1; l <= k; l++) {
//							if (min_2 > f(ans.second, j, pos, k) + f(l, b, pos, k)) {
//								min_2 = f(ans.second, j, pos, k) + f(l, b, pos, k);
//								min_one_idx = l;
//								flb_min = f(l, b, pos, k);
//								flb_min_idx = l;
//							} else if (min_2 == f(ans.second, j, pos, k) + f(l, b, pos, k)) {
//								if (min_one_idx != b) {
//									min_one_idx = l;
//									flb_min = f(l, b, pos, k);
//									flb_min_idx = l;
//								}
//							}
//						}
//						if (min_one > min_2) {
//							min_one = min_2;
//						} else {
//							min_one_idx = b;
//						}
//					} else {
//						if (min_one > f(ans.second, j, pos, k) + flb_min) {
//							min_one = f(ans.second, j, pos, k) + flb_min;
//							min_one_idx = flb_min_idx;
//						} else {
//							min_one_idx = b;
//						}
//					}
//
//				} else {
//					if (min_one > f(ans.second, j, pos, k) + f(j, b, pos, k)) {
//						min_one = f(ans.second, j, pos, k) + f(j, b, pos, k);
//						min_one_idx = j;
//					} else if (min_one == f(ans.second, j, pos, k) + f(j, b, pos, k)) {
//						if (min_one_idx != b) {
//							min_one_idx = j;
//						}
//					}
//				}
//			}
//
//			ans.second = min_one_idx == 0 ? ans.second : min_one_idx;
//			ans.first = last_step + min_one;
//		}
//
//		cout << ans.first << endl;
//	}
//	return 0;
//}


//2024 10 18 K 对数学爱好者很友好，算数基本定理秒了。
//#include <bits/stdc++.h>
//using namespace std;
//
//bool is_prime(int x) {
//	for (int i = 2; i <= sqrt(x); i++) {
//		if (x % i == 0) {
//			return false;
//		}
//	}
//	return true;
//}
//
//int main() {
//	int t, l, r;
//	cin >> t;
//	while (t--) {
//		cin >> l >> r;
//		if (r < 4) {
//			cout << -1 << endl;
//		} else {
//			if (r - l >= 1) {
//				cout << r / 2 << ' ' << r / 2 << endl;
//			} else {
//				if (is_prime(l)) {
//					cout << -1 << endl;
//				} else {
//					int i = 2;
//					for (; i <= sqrt(l); i++) {
//						if (l % i == 0) {
//							break;
//						}
//					}
//					cout << l / i << ' ' << (i - 1) * (l / i) << endl;
//				}
//			}
//		}
//
//	}
//
//	return 0;
//}

//2024 10 22 L
//#include <bits/stdc++.h>
//using namespace std;
//
//bool is_baohan(vector<int>& a, vector<int>& b) {
//	int up = 0, down = 0;
//	while (up < a.size()) {
//		if (a[up] == b[down]) {
//			up++;
//			down++;
//		} else {
//			up++;
//		}
//
//		if (down == b.size()) {
//			return true;
//		}
//	}
//	return false;
//}
//
//vector<int> getAns(vector<vector<int>>& a, int n, int x) {
//	vector<int> ans_temp;
//	for (int i = 0; i <= n; i++) {
//		ans_temp.assign(a[0].begin(), a[0].end());
//		ans_temp.insert(ans_temp.begin() + i, x);
//		for (int j = 1; j < n; j++) {
//			if (!is_baohan(ans_temp, a[j]))
//				break;
//			if (j == n - 1) {
//				return ans_temp;
//			}
//		}
//	}
//}
//
//int main() {
//	int t, n;
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		unordered_map<int, int> map;
//		vector<vector<int>> a(n, vector<int>(n - 1));
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n - 1; j++) {
//				cin >> a[i][j];
//				if (i == 0) {
//					map[a[i][j]]++;
//				}
//			}
//		}
//		int x;
//		for (int i = 1; i <= n; i++) {
//			if (map.find(i) == map.end()) {
//				x = i;
//				break;
//			}
//		}
//		vector<int> ans;
//		ans = getAns(a, n, x);
//		for (int i = 0; i < n; i++) {
//			cout << ans[i] << ' ';
//		}
//		cout << endl;
//	}
//	return 0;
//}

// 2024 10 23 M
//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int t, n;
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		vector<int> arr = {1, 3, 5};
//		while ((int)arr.size() != n) {
//			int next_num = arr.back() + 1;
//			while (3 * next_num % (arr.back() + arr[arr.size() - 2]) == 0) {
//				next_num++;
//			}
//			arr.push_back(next_num);
//		}
//
//		for (int num : arr) {
//			cout << num << ' ';
//		}
//		cout << endl;
//	}
//	return 0;
//}

//2024 10 25 N
//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int t, n;
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		vector<int> a(n);
//		for (int i = 0; i < n; i++) cin >> a[i];
//		int min_cha = 1e9;
//		for (int i = 0; i < n - 1; i++) {
//			min_cha = min(min_cha, a[i + 1] - a[i]);
//		}
//		if (min_cha < 0) {
//			cout << 0 << endl;
//		} else {
//			cout << min_cha / 2 + 1 << endl;
//		}
//	}
//	return 0;
//}

//2024 10 28 O
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int t, n, m;
//	cin >> t;
//	string x, s;
//	while (t--) {
//		cin >> n >> m;
//		cin >> x >> s;
//		int ans = 0;
//		if (x.find(s) != string::npos) {
//			cout << ans << endl;
//		} else {
//			while (x.size() < s.size()) {
//				x += x;
//				ans++;
//			}
//
//			if (x.find(s) != string::npos) {
//				cout << ans << endl;
//			} else {
//				x += x;
//				ans++;
//				if (x.find(s) != string::npos) {
//					cout << ans << endl;
//				} else {
//					cout << -1 << endl;
//				}
//			}
//
//		}
//
//	}
//	return 0;
//}

//2024 10 31 P
//#include <bits/stdc++.h>
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
//
//		sort(a.begin(), a.end());
//
//		long long ans = (long long)a[n - 2] * (long long)a[n - 1];
//		ans = max(ans, (long long)a[0] * (long long)a[1]);
//		cout << ans << endl;
//
//	}
//	return 0;
//}

//2024 11 3 Q
//#include <bits/stdc++.h>
//using namespace std;
//
//void getans(int dep, int& ans, long long X, int max_dep, vector<vector<long long>>& vec, long long the_x) {
//	if (dep == max_dep) {
//		if (the_x == X) {
//			ans++;
//		}
//	} else {
//		for (int i = 0; i < (int)vec[dep].size(); i++) {
//			getans(dep + 1, ans, X, max_dep, vec, the_x * vec[dep][i] % 1000000000000000001);
//		}
//	}
//}
//
//int main() {
//	int N, L;
//	long long X;
//	cin >> N >> X;
//	vector<vector<long long>> a(N, vector<long long>());
//	for (int i = 0; i < N; i++) {
//		cin >> L;
//		a[i].resize(L);
//		for (int j = 0; j < L; j++) {
//			cin >> a[i][j];
//		}
//	}
//
//	int ans = 0;
//	getans(0, ans, X, N, a, 1);
//	cout << ans << endl;
//
//	return 0;
//}


//2024 11 5 R
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
//
//		if(n == 1 || n == 2) {
//			cout << "YES" << endl;
//		} else {
//			bool have_ans = false;
//			for(int i = 2; i < n; i++) {
//				if (gcd(a[i-2]*a[i-1]/gcd(a[i-2],a[i-1]), a[i]*a[i-1]/gcd(a[i],a[i-1]))!=a[i-1]) {
//					cout << "NO" << endl;
//					have_ans = true;
//					break;//草了，就这个没写害惨我了，妈的。
//				}
//			}
//			if (!have_ans) cout << "YES" << endl;
//		}
//	}
//	return 0;
//}

//2024 11 11 S 题改了，这题没了。
//#include <bits/stdc++.h>
//using namespace std;
//
//using ll = long long;
//
//int main() {
//	int t;
//	ll n, b, c;
//	cin >> t;
//	while (t--) {
//		cin >> n >> b >> c;
//		if (b == 0) {
//			if (c <= n - 3) {
//				cout << -1 << endl;
//			} else {
//				cout << n - 1 << endl;
//			}
//		} else {
//			ll zuo = max(1LL, -((c + b - 1) / b) + 1);
//			ll you = min(n, (ll)((n - 1 - c) * 1.0 / b + 1));
//			if ((n - 1 - c) * 1.0 / b < 0 && (n - 1 - c) * 1.0 / b > -1e-16) you--;
//			ll shu = you - zuo + 1;
//			cout << n - shu << endl;
//		}
//	}
//	return 0;
//}


//2024 11 11 S 往往需要看到问题的本质————0与1的个数
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int t, n, zero_cnt, one_cnt;
//	string s1, s2;
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		cin >> s1 >> s2;
//		zero_cnt = count(s1.begin(), s1.end(), '0');
//		one_cnt = count(s1.begin(), s1.end(), '1');
//		bool have_ans = false;
//		for (int i = 0; i < n - 2; i++) {
//			if (s2[i] == '1') {
//				if (zero_cnt >= 2 && one_cnt > 0) {
//					zero_cnt--;
//				} else {
//					cout << "NO" << endl;
//					have_ans = true;
//					break;
//				}
//			} else {
//				if (one_cnt >= 2 && zero_cnt > 0) {
//					one_cnt--;
//				} else {
//					cout << "NO" << endl;
//					have_ans = true;
//					break;
//				}
//			}
//		}
//
//		if (zero_cnt == 1 && one_cnt == 1) {
//			cout << "YES" << endl;
//		} else {
//			if (!have_ans) cout << "NO" << endl;
//		}
//	}
//
//	return 0;
//}

//T - 11.11
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//
//	sort(a.begin(), a.end());
//
//	int ans = 1;
//	bool keyile = false;
//	for (int i = 0; i < n - 1; i++) {
//		for (int j = i + ans; j < n; j++) {
//			if (j >= n) {
//				keyile = true;
//				break;
//			}
//			if (a[j] - a[i] < m) {
//				ans = max(j - i + 1, ans);
//			} else {
//				break;
//			}
//		}
//
//		if (keyile) break;
//	}
//
//	cout << ans << endl;
//	return 0;
//}


//2024 11 19 W
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int t, n;
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		vector<int> a(n);
//		int ji = 0;
//		for (int i = 0; i < n; i++) {
//			cin >> a[i];
//			if (a[i] & 1) ji++;
//		}
//
//		if (ji % 2 == 0) cout << "YES" << endl;
//		else cout << "NO" << endl;
//	}
//	return 0;
//}


//U - 2024.11.19 此法不通，会超时
//#include<bits/stdc++.h>
//using namespace std;
//
//int f(vector<int>& a, int l, int r, vector<vector<int>>& jiyi) {
//	if (jiyi[l][r] != -1) return jiyi[l][r];
//	int res = 0;
//	if (l == r) return res;
//	else {
//		for (int i = l; i < r; i++) {
//			res += abs(a[i] - a[i + 1]);
//		}
//		jiyi[l][r] = res;
//		return jiyi[l][r];
//	}
//}
//
//void getAns(vector<int>& a, int deep, int k, int& ans, int sum, int idx, vector<vector<int>>& jiyi) {
//	if (deep == k) {
//		ans = min(ans, sum + f(a, idx, a.size() - 1, jiyi));
//	} else {
//		if (sum >= ans) return;
//		for (int i = idx; i < (int)a.size() - 1; i++) {
//			if (i + k - deep - 1 > (int)a.size() - 2) break;
//			getAns(a, deep + 1, k, ans, sum + f(a, idx, i, jiyi), i + 1, jiyi);
//		}
//	}
//}
//
//int main() {
//	int t, n, k;
//	cin >> t;
//	while (t--) {
//		cin >> n >> k;
//		vector<int> a(n);
//		vector<vector<int>> jiyi(n, vector<int>(n, -1));
//		for (int i = 0; i < n; i++) cin >> a[i];
//		if (k == n) {
//			cout << 0 << endl;
//		} else if (k == 1) {
//			cout << f(a, 0, a.size() - 1, jiyi) << endl;
//		} else {
//			int ans = INT32_MAX;
//			getAns(a, 1, k, ans, 0, 0, jiyi);
//			cout << ans << endl;
//		}
//
//	}
//	return 0;
//}


//U - 2024.11.19 （同上题目）英雄哥：过啦！
//#include<bits/stdc++.h>
//using namespace std;
//
//bool cmp(pair<int, int>& a, pair<int, int>& b) {
//	return a.first > b.first;
//}
//
//bool cmp2(pair<int, int>& a, pair<int, int>& b) {
//	return a.second < b.second;
//}
//
//int f(vector<int>& a, int l, int r) {
//	if (l == r) return 0;
//	else {
//		int res = 0;
//		for (int i = l; i < r; i++) {
//			res += abs(a[i] - a[i + 1]);
//		}
//		return res;
//	}
//}
//
//int main() {
//	int t, n, k;
//	cin >> t;
//	while (t--) {
//		cin >> n >> k;
//		vector<int> a(n);
//		for (int i = 0; i < n; i++) cin >> a[i];
//		vector<pair<int, int>> cha(n - 1);
//		for (int i = 0; i < n - 1; i++) {
//			cha[i] = make_pair(abs(a[i] - a[i + 1]), i);
//		}
//
//		sort(cha.begin(), cha.end(), cmp);
//		if (k == n) {
//			cout << 0 << endl;
//		} else if (k == 1) {
//			cout << f(a, 0, a.size() - 1) << endl;
//		} else {
//			int ans = 0;
//			sort(cha.begin(), cha.begin() + k - 1, cmp2);
//			int idx = 0;
//			for (int i = 0; i < k - 1; i++) {
//				ans += f(a, idx, cha[i].second);
//				idx = cha[i].second + 1;
//			}
//			ans += f(a, idx, a.size() - 1);
//
//			cout << ans << endl;
//		}
//	}
//	return 0;
//}


//V - 2024.11.20    需要灵光一现啊
//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int t, n, x, xi;
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		vector<vector<int>> a(n);
//		for (int i = 0; i < n; i++) {
//			cin >> x;
//			for (int j = 0; j < x; j++) {
//				cin >> xi;
//				a[i].push_back(xi);
//			}
//		}
//
//		if (n == 1) cout << 0 << endl;
//		else {
//			map<int, vector<int>> mp;
//			for (int i = 0; i < n; i++) {
//				for (int j = 0; j < (int)a[i].size(); j++) {
//					mp[a[i][j]].push_back(i);
//				}
//			}
//
//			int ans = -1;
//			for (int i = 1; i <= 50; i++) {
//				if (mp.find(i) == mp.end()) continue;
//				vector<int> b(n);
//				for (int j = 0; j < n; j++) b[j] = j;
//				for (int num : mp[i]) {
//					b.erase(find(b.begin(), b.end(), num));
//				}
//				set<int> ans_set;
//				for (int num : b) {
//					for (int k = 0; k < (int)a[num].size(); k++) {
//						ans_set.insert(a[num][k]);
//					}
//				}
//
//				ans = max(ans, (int)ans_set.size());
//			}
//
//			cout << ans << endl;
//		}
//	}
//	return 0;
//}


//X - 2024.11.22  二分不行，因为k能达到1e18，错了可能是这个原因
//不不不！后来改了，把sqrt改为更高精度的sqrtl就行了
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int t;
//	long long k;
//	cin >> t;
//	while (t--) {
//		cin >> k;
//		long long left = 1, right = LONG_LONG_MAX - 1;
//		long long ans = 0, mid = 0;
//		while (left <= right) {
//			mid = (left + right) >> 1;
//			if (mid - (int)sqrtl(mid) >= k) {
//				ans = mid;
//				right = mid - 1;
//			} else {
//				left = mid + 1;
//			}
//		}
//
//		cout << ans << endl;
//	}
//	return 0;
//}


// 同上题  还是错，因为sqrt精度问题 改为sqrtl就行了
//#include <bits/stdc++.h>
//using namespace std;
//
//
//int main() {
//	int t;
//	long long k;
//	cin >> t;
//	while (t--) {
//		cin >> k;
//		long long shu = sqrtl(k);
//		long long ans = k + shu;
//		long long shu2 = sqrtl(ans);
//		while (shu2 - shu != 0) {
//			ans += shu2 - shu;
//			shu = shu2;
//			shu2 = sqrtl(ans);
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}


// Y - 2024.11.22
//#include<bits/stdc++.h>
//using namespace std;
//
//long long shanghai(vector<int>& a, long long mid) {
//	long long ans = 0;
//	for (int i = 0; i < (int)a.size() - 1; i++) {
//		ans += min(mid, (long long)(a[i + 1] - a[i]));
//	}
//	ans += mid;
//	return ans;
//}
//
//int main() {
//	int t, n;
//	long long h;
//	cin >> t;
//	while (t--) {
//		cin >> n >> h;
//		vector<int> a(n);
//		for (int i = 0; i < n; i++) {
//			cin >> a[i];
//		}
//		long long ans = 0;
//		long long left = 0, right = h;
//		long long mid;
//		while (left <= right) {
//			mid = (left + right) >> 1;
//			if (shanghai(a, mid) >= h) {
//				ans = mid;
//				right = mid - 1;
//			} else {
//				left = mid + 1;
//			}
//		}
//
//		cout << ans << endl;
//	}
//	return 0;
//}


// Z - 11.27 理解错题目意思了，但是保留代码，因为这代码太TM屎山了，有纪念意义
//#include <bits/stdc++.h>
//using namespace std;
//
//int find(vector<int>& a, int idx) {
//	int f = a[idx];
//	while (f != a[f]) {
//		f = a[f];
//	}
//	return f;
//}
//
//void xuan(int& jixu, int deep, int a, vector<int>& qujian, vector<int>& father, unordered_map<int, vector<int>>& mp) {
//	if (jixu) {
//		if (deep == 2) {
//			for (int i = 0; i < (int)mp[father[qujian[0]]].size(); i++) {
//				for (int j = 0; j < (int)mp[father[qujian[1]]].size(); j++) {
//					if (i == 0 && j == 0) continue;
//					cout << mp[father[qujian[0]]][i] << ' ' << mp[father[qujian[1]]][j] << endl;
//					jixu--;
//					if (jixu <= 0) {
//						break;
//					}
//				}
//
//				if (jixu <= 0) {
//					break;
//				}
//			}
//		} else {
//			for (int i = a; i < (int)father.size(); i++) {
//				qujian.push_back(i);
//				xuan(jixu, deep + 1, i + 1, qujian, father, mp);
//				qujian.pop_back();
//			}
//		}
//	}
//}
//
//int main() {
//	int t, n;
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		vector<int> a(n + 1);
//		unordered_map<int, int> mp;
//		for (int i = 1; i <= n; i++) {
//			cin >> a[i];
//		}
//
//		for (int i = 1; i <= n; i++) {
//			if (mp.find(a[i]) == mp.end())
//				mp[a[i]] = i;
//		}
//
//		for (int i = 1; i <= n; i++) {
//			a[i] = mp[a[i]];
//		}
//
//		int x = 0;
//		unordered_map<int, vector<int>> jihe;
//		vector<int> father;
//		for (int i = 1; i <= n; i++) {
//			if (i == find(a, i)) {
//				x++;
//				father.push_back(i);
//			}
//
//			jihe[find(a, i)].push_back(i);
//		}
//
//		if (x == 1) cout << "NO" << endl;
//		else {
//			cout << "YES" << endl;
//			int xulian = n - 1;
//
//			for (int i = 0; i < (int)father.size() - 1; i++) {
//				cout << father[i] << ' ' << father[i + 1] << endl;
//				xulian--;
//				if (xulian <= 0) break;
//			}
//
//			if (xulian > 0) {
//				vector<int> qujian;
//				xuan(xulian, 0, 0, qujian, father, jihe);
//			}
//		}
//
//	}
//	return 0;
//}



// Z - 11.27 同上题  过了，嘿嘿，分析出前面代码的问题来了
//#include <bits/stdc++.h>
//using namespace std;
//
//int find(vector<int>& a, int idx) {
//	int f = a[idx];
//	while (f != a[f]) {
//		f = a[f];
//	}
//	return f;
//}
//
//int main() {
//	int t, n;
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		vector<int> a(n + 1);
//		unordered_map<int, int> mp;
//		for (int i = 1; i <= n; i++) {
//			cin >> a[i];
//		}
//
//		for (int i = 1; i <= n; i++) {
//			if (mp.find(a[i]) == mp.end())
//				mp[a[i]] = i;
//		}
//
//		for (int i = 1; i <= n; i++) {
//			a[i] = mp[a[i]];
//		}
//
//		int x = 0;
//		unordered_map<int, vector<int>> jihe;
//		vector<int> father;
//		for (int i = 1; i <= n; i++) {
//			if (i == find(a, i)) {
//				x++;
//				father.push_back(i);
//			}
//
//			jihe[find(a, i)].push_back(i);
//		}
//
//		if (x == 1) cout << "NO" << endl;
//		else {
//			cout << "YES" << endl;
//			for (int i = 1; i < (int)father.size(); i++) {
//				for (int j = 0; j < (int)jihe[father[i]].size(); j++) {
//					cout << father[0] << ' ' << jihe[father[i]][j] << endl;
//				}
//			}
//
//			for (int i = 1; i < (int)jihe[father[0]].size(); i++) {
//				cout << jihe[father[0]][i] << ' ' << father[1] << endl;
//			}
//		}
//
//	}
//	return 0;
//}

