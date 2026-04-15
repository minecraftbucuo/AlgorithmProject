//#include <bits/stdc++.h>
//using namespace std;
//
//class Solution {
//public:
//	vector<vector<int>> merge(vector<vector<int>>& intervals) {
//		// 使用选择排序
//		int left = 0;
//		int right = 0;
//		while (left < intervals.size() - 1) {
//			for (int i = left + 1; i < intervals.size(); i++) {
//				if (intervals[right][0] > intervals[i][0])
//					right = i;
//			}
//			vector<int> temp = intervals[left];
//			intervals[left] = intervals[right];
//			intervals[right] = temp;
//			left++;
//			right = left;
//		}
//
//		return intervals;
//	}
//};
//
//int main() {
//	vector<vector<int>> test = {{3, 1}, {4, 3}, {2, 0}, {8, 10}, {0, 10}};
//	Solution().merge(test);
//
//	for (int i = 0; i < test.size(); i++) {
//		cout << test[i][0] << " " << test[i][1] << endl;
//	}
//	return 0;
//}

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
//	cout << 3137 + 9837632 << endl;
//	cout << gcd(3137, 9837632);
//	return 0;
//}

//#include<bits/stdc++.h>
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
//int main() {
//	vector<int> a = {4, 3, 1, 2};
//	vector<int> b = {3, 1, 4};
//	cout << is_baohan(a, b) << endl;
//	return 0;
//}


//#include<stdio.h>
//
//int main() {
//	double ans = 0;
//	double fenzi = 2;
//	double fenmu = 1;
//	for (int i = 1; i <= 100; i++) {
//		ans += fenzi / fenmu;
//		fenzi = fenzi + fenmu;
//		fenmu = fenzi - fenmu;
//	}
//
//	printf("%lf", ans);
//	return 0;
//}

// 2024 10 28 C语言课上机题目
//第一题
//#include<iostream>
//using namespace std;
//
//int main( ) {
// char a;
// cin >> a;
// cout << (char)(a + 32) << endl;
// return 0;
//}

//第二题
//#include <iostream>
//using namespace std;
//
//int main() {
//	int a, b;
//	cin >> a >> b;
//	int ji, tu;
//	tu = (b - 2 * a) / 2;
//	ji = a - tu;
//	cout << ji << " " << tu << endl;
//	return 0;
//}


//第三题
//#include <iostream>
//using namespace std;
//int main() {
// int cnt = 1;
// for (int i = 1; i <= 5; i++) {
//  for (int j = 1; j <= cnt; j++) {
//   cout << 'M';
//  }
//  cout << endl;
//  if (i < 3) cnt += 2;
//  else cnt -= 2;
// }
// return 0;
//}

// 第四题
//#include<iostream>
//using namespace std;
//int main() {
//	for (int i = 1; i <= 4; i++) {
//		for (int j = 1; j <= i; j++) {
//			cout << "* ";
//		}
//		cout << endl;
//	}
//	return 0;
//}


// p15-6
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
// double a, b, c;
// cin >> a >> b >> c;
// cout << "x1 = " << (-b + sqrt(b * b - 4 * a * c)) / (2 * a) << endl;
// cout << "x2 = " << (-b - sqrt(b * b - 4 * a * c)) / (2 * a) << endl;
// return 0;
//}

//p14-2
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
// double F;
// cin >> F;
// printf("%.2f", 5.0 / 9 * (F - 32));
// return 0;
//}

//p14-3
//#include <bits/stdc++.h>
//using namespace std;
//int main() {
// double r1, r2, r3;
// cin >> r1 >> r2 >> r3;
// printf("%.2f", 1.0/(1/r1 + 1/r2+1/r3));
// return 0;
//}

//p14-5
//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	const double M_3 = pow(6, 1.0 / 3) * 1e8;
//	const double R = 6.371e6;
//	const double pi = 3.1415927;
//	double T;
//	cin >> T;
//	double H = M_3 * pow((6.67e-11 * T*T) / (4 * pi*pi), 1.0 / 3) - R;
//	cout << H << endl;
//	return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	long long n;
//	long long ans;
//	string s;
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		ans = n;
//		s = to_string(n);
//		for (int i = 0; i < (int)s.size() - 1; i++) {
//			string temp(s.begin() + 1, s.end());
//			s = temp + s[0];
//			ans = min(stoll(s), ans);
//		}
//
//		cout << ans << endl;
//	}
//
//	return 0;
//}


//2024 11 11 C语言上机
//#include<stdio.h>
//int c1,c2,c3;
//void fun(long n) {
//	c1 = c2 = c3 = 0;
//	while (n) {
//		int x = n % 10;
//		switch (x) {
//		case 1:
//			c1++;
//			break;
//		case 2:
//			c2++;
//			break;
//		case 3:
//			c3++;
//			break;
//		}
//		n /= 10;
//	}
//}
//
//int main() {
//	long n = 123114350L;
//	fun(n);
//	printf("\nThe result :\n");
//	printf("%d, %d, %d", c1, c2, c3);
//}


//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	char c;
//	cin >> c;
//	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) {
//		cout << "字母" << endl;
//	} else if ('0' <= c && c <= '9') {
//		cout << "数字" << endl;
//	} else {
//		cout << "其他" << endl;
//	}
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	vector<double> a(3);
//	for (int i = 0; i < 3; i++) {
//		cin >> a[i];
//	}
//	sort(a.begin(), a.end());
//
//	if (a[0] + a[1] > a[2]) {
//		double area;
//		double S = (a[0] + a[1] + a[2]) / 2;
//		area = sqrt(S * (S - a[0]) * (S - a[1]) * (S - a[2]));
//		cout << area << endl;
//	} else {
//		cout << "ERROR!" << endl;
//	}
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int a;
//	cin >> a;
//	cout << (((a % 4 == 0 && a % 100 != 0) || a % 400 == 0) ? "是闰年" : "不是闰年") << endl;
//	return 0;
//}


//2024 11 18 上机
//猴子吃桃
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int ans = 1;
//	for (int i = 9; i >= 1; i--) {
//		ans = (ans + 1) * 2;
//	}
//
//	cout << ans << endl;
//	return 0;
//}


//数列求和
//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	double ans = 0;
//	for (int i = 1; i <= 20; i++) {
//		ans += 1.0 / (i * (i + 1));
//	}
//	cout << ans << endl;
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int ans = INT32_MIN;
//	int n;
//	while (cin >> n) {
//		if (n == 0) break;
//		ans = max(ans, n);
//	}
//
//	cout << ans << endl;
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	vector<double> fact(21, 1);
//	for (int i = 2; i <= 20; i++) {
//		fact[i] = fact[i - 1] * i;
//	}
//
//	double sum = 0;
//	for (int i = 1; i <= 20; i++) {
//		sum += fact[i];
//	}
//
//	cout << sum << endl;
//	return 0;
//}


//2024 11 25 上机
//#include<bits/stdc++.h>
//using namespace std;
//
//long long operator*(string a, int n) {
//	string t = a;
//	for (int i = 1; i < n; i++ ) {
//		a += t;
//	}
//	return stoll(a);
//}
//
//int main() {
//	int n;
//	string a;
//	cin >> a >> n;
//	long long ans = 0;
//	for (int i = 1; i <= n; i++) {
//		ans += a * i;
//	}
//	cout << ans << endl;
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//int fact(int n) {
//	int res = 1;
//	for (int i = 2; i <= n; i++) {
//		res *= i;
//	}
//	return res;
//}
//
//int main() {
//	double x;
//	cin >> x;
//	double ans = 1;
//	for (int i = 1, j = 1; i <= 8; i++, j *= -1) {
//		ans += j * pow(x, i) / fact(i);
//	}
//
//	cout << ans << endl;
//
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	for (int i = 1; i <= 6; i++) {
//		for (int j = 1; j <= 2 * i - 1; j++) {
//			cout << "* ";
//		}
//		cout << endl;
//	}
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	for (int i = 7; i >= 1; i--) {
//		char x = 'X';
//		for (int j = 1; j <= i; j++) {
//			cout << x;
//			x++;
//			if (x > 'Y') x = 'X';
//		}
//		cout << endl;
//	}
//	return 0;
//}


//2024 12 2 C语言上机
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	double sum = 0;
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		sum += 1.0 / (i * (i + 1));
//	}
//	cout << sum << endl;
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//
//int fun(int n) {
//	for (int i = 2; i * i <= n; i++) {
//		if (n % i == 0) return 0;
//	}
//	return 1;
//}
//
//int main() {
//	int n;
//	cin >> n;
//	cout << fun(n) << endl;
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//int fun(int n) {
//	return n == 1 ? 10 : fun(n - 1) + 2;
//}
//
//int main() {
//	int n;
//	cin >> n;
//	cout << fun(n) << endl;
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//int gcd(int a, int b) {
//	return a == 0 ? b : gcd(b % a, a);
//}
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	cout << gcd(n, m) << endl;
//	return 0;
//}


//2024 12 9 C语言上机
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	string s;
//	int daxie = 0, xiaoxie = 0, shuzi = 0, qita = 0;
//	int t = 5;
//	while (t--) {
//		getline(cin, s);
//		for (int i = 0; i < (int)s.length(); i++) {
//			if (s[i] >= '0' && s[i] <= '9') shuzi++;
//			else if (s[i] >= 'a' && s[i] <= 'z') xiaoxie++;
//			else if (s[i] >= 'A' && s[i] <= 'Z') daxie++;
//			else qita++;
//		}
//	}
//
//	cout << "数字个数：" << shuzi << endl;
//	cout << "小写字母个数：" << xiaoxie << endl;
//	cout << "大写字母个数：" << daxie << endl;
//	cout << "其他字符个数：" << qita << endl;
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//#define M 4
//#define N 5
//int fun(int a[M][N]) {
//	int sum = 0;
//	for (int i = 0; i < M; i++) {
//		for (int j = 0; j < N; j++) {
//			if (i == 0 || j == 0 || i == M - 1 || j == N - 1)sum += a[i][j];
//		}
//	}
//	return sum;
//}
//int main() {
//	int aa[M][N] = {{1, 3, 5, 7, 9}, {2, 9, 9, 9, 4}, {6, 9, 9, 9, 8}, {1, 3, 5, 7, 0}};
//	int i, j, y;
//	printf("The original date is : \n");
//	for (i = 0; i < M; i++) {
//		for (j = 0; j < N; j++) {
//			printf("%6d", aa[i][j]);
//		}
//		printf("\n");
//	}
//	y = fun(aa);
//	printf("\nThe sum:%d\n", y);
//	printf("\n");
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	vector<int> a(10);
//	for (int i = 0; i < 10; i++) cin >> a[i];
//	sort(a.begin(), a.end());
//
//	double sum = 0;
//	for (int i = 1; i < 9; i++) sum += a[i];
//
//	cout << sum / 8 << endl;
//
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	vector<int> a(10);
//	for (int i = 0; i < 10; i++) cin >> a[i];
//	for (int i = 0; i < 5; i++) swap(a[i], a[9 - i]);
//	for (int i : a) cout << i << ' ';
//	return 0;
//}
