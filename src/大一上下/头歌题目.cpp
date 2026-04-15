//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n, x;
//	cin >> n >> x;
//	if (n != 1) {
//		vector<int> vec(n);
//		for (int i = 0; i < n; i++) {
//			cin >> vec[i];
//		}
//		int left = 0, right = 1;
//		int ans = 1;
//		while (right < n) {
//			if (vec[right] - vec[right - 1] <= x) {
//				right++;
//			} else {
//				left = right;
//				right++;
//			}
//
//			ans = max(ans, right - left);
//		}
//
//		cout << ans << endl;
//	} else {
//		cout << 1 << endl;
//	}
//}

// 没有过，不知道为什么
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int> a(n), b(n);
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 0; i < n; i++) {
//		cin >> b[i];
//	}
//	sort(a.begin(), a.end());
//	sort(b.begin(), b.end());
//	int step = 1;
//	while (a.size() != 1 || b.size() != 1) {
//		if (step & 1) {
//			if (abs(a[a.size() - 1] - b[0]) < abs(b[b.size() - 1] - a[0])) {
//				a.pop_back();
//			} else {
//				a.erase(a.begin());
//			}
//		} else {
//			if (abs(b[b.size() - 1] - a[0]) < abs(a[a.size() - 1] - b[0])) {
//				b.erase(b.begin());
//
//			} else {
//				b.pop_back();
//			}
//		}
//		step++;
//	}
//
//	cout << abs(a[0] - b[0]) << endl;
//	return 0;
//}

// 最小公倍数
//#include<stdio.h>
//
//long long gcd(long long a, long long b) {
//	if (a == 0) return b;
//	else return gcd(b % a, a);
//}
//
//int main() {
//	long long a, b;
//	while (scanf("%lld%lld", &a, &b) != EOF) {
//		printf("%lld\n", a * b / gcd(a, b));
//	}
//
//	return 0;
//}

// 等差数列最少有多少项
//#include<stdio.h>
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int> a(n);
//
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//	sort(a.begin(), a.end());
//
//	int min_cha = a[1] - a[0];
//	if (min_cha != 0) {
//		for (int i = 1; i < n - 1; i++) {
//			min_cha = min(min_cha, a[i + 1] - a[i]);
//		}
//
//		for (; min_cha > 1; min_cha-- ) {
//			int have_ans = false;
//			for (int i = 0; i < n; i++) {
//				if (a[i] % min_cha != 0) {
//					break;
//				}
//				if (i == n - 1)
//					have_ans = true;
//			}
//			if (have_ans)
//				break;
//		}
//		int ans = (a[a.size() - 1] - a[0]) / min_cha + 1;
//		cout << ans << endl;
//	} else {
//		cout << n << endl;
//	}
//	return 0;
//}

//计算菜价
//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	char s[100];
//	double a, b;
//	double ans;
//	while (scanf("%s%lf%lf", s, &a, &b) != EOF) {
//		ans += a * b;
//	}
//
//	printf("%.1f", ans);
//	return 0;
//}

//To Crash or not To Crash 无语，不知道为啥过不了，最讨厌这样的了
//下面代码改进了一下，和书上的思路一样了，过了，但我不知道我代码哪里有问题，删都删掉了
//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	vector<string> a(3);
//	int x, y;
//	cin >> a[0] >> a[1] >> a[2];
//
//	bool have_found = false;
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 10; j++) {
//			if (a[i][j] == '=') {
//				x = i, y = j;
//				have_found = true;
//				break;
//			}
//		}
//
//		if (have_found) break;
//	}
//
//	int j;
//	y++;
//
//	for (j = y; j < 10; j++) {
//		if (a[x][j] != '.') {
//			cout << a[x][j] << endl;
//			return 0;
//		}
//	}
//	cout << "You shall pass!!!" << endl;
//	return 0;
//}

//Integer Prefix
//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	string s;
//	cin >> s;
//	int idx = 0;
//	while (idx < (int)s.size()) {
//		if ('0' <= s[idx] && s[idx] <= '9') {
//			idx++;
//		} else {
//			break;
//		}
//	}
//
//	if (idx == 0) {
//		cout << -1 << endl;
//	} else {
//		for (int i = 0; i < idx; i++) {
//			cout << s[i];
//		}
//	}
//
//	return 0;
//}


// 2024 10 31 So Easy
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	int x0, y0;
//	vector<vector<int>> arr(n, vector<int>(n));
//	vector<vector<int>> dir = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cin >> arr[i][j];
//			if (arr[i][j] == -1) {
//				x0 = i;
//				y0 = j;
//			}
//		}
//	}
//	int x, y;
//	for (int i = 0; i < 4; i++) {
//		x = x0 + dir[i][0];
//		y = y0 + dir[i][1];
//		if (x >= 0 && x < n && y >= 0 && y < n) {
//			break;
//		}
//	}
//
//	cout << arr[x][y0] + arr[x0][y] - arr[x][y] << endl;
//	return 0;
//}

//Mental Rotation
//#include<bits/stdc++.h>
//using namespace std;
//
//void move(int n, vector<string>& a, vector<string>& b, unordered_map<char, char>& mp) {
//	for (int x = 0; x < n; x++) {
//		for (int y = 0; y < n; y++) {
//			b[x][y] = mp[a[n - y - 1][x]];
//		}
//	}
//
//	a.assign(b.begin(), b.end());
//}
//
//int main() {
//	int n;
//	cin >> n;
//	string s;
//	cin >> s;
//	vector<string> a(n);
//	vector<string> b;
//	unordered_map<char, char> mp;
//	mp['>'] = 'v', mp['^'] = '>', mp['<'] = '^', mp['.'] = '.', mp['v'] = '<';
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//	b.assign(a.begin(), a.end());
//
//	int rnum = 0, lnum = 0;
//	for (char c : s) {
//		if (c == 'L') lnum++;
//		else if (c == 'R') rnum++;
//	}
//
//	if (rnum > lnum) {
//		rnum -= lnum;
//		rnum %= 4;
//	} else {
//		lnum -= rnum;
//		lnum %= 4;
//		rnum = 4 - lnum;
//		rnum %= 4;
//	}
//
//	for (int i = 1; i <= rnum; i++) {
//		move(n, a, b, mp);
//	}
//
//	for (int i = 0; i < n; i++) {
//		cout << a[i] << endl;
//	}
//	cout << endl;
//	return 0;
//}


//Kernel of Love
//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int t, x;
//	cin >> t;
//	int n = 1e5;
//	vector<int> a(n + 1);
//	a[3] = 2;
//	for (int i = 4; i <= n; i++) {
//		if ((i % 3 && (i + 1) % 3) || i % 3 == 0) {
//			a[i] = a[i - 1] + 1;
//		} else {
//			a[i] = a[i - 1];
//		}
//	}
//	while (t--) {
//		cin >> x;
//		cout << a[x] << endl;
//	}
//
//
//	return 0;
//}

//回文字符串
//#include<bits/stdc++.h>
//using namespace std;
//
//bool is_hui(string s) {
//	for (int i = 0; i < (int)s.size(); i++) {
//		if (s[i] != s[s.size() - i - 1]) {
//			return false;
//		}
//	}
//	return true;
//}
//
//int main() {
//	string s;
//	cin >> s;
//	if (is_hui(s)) {
//		cout << s << endl;
//	} else {
//		for (int i = s.size() - 2; i >= 0; i--) {
//			s += s[i];
//		}
//		cout << s << endl;
//	}
//	return 0;
//}


//#include<stdio.h>                        //1表示灯亮，0表示灯灭
//int main() {
//	int n, a[100] = {0}, i, j, count = 0;//初始灯数组a[100]值为0，表示灯灭
//	scanf("%d", &n);
//	/**********Begin*************/
//	for (i = 0; i < n; i++) {
//		for (j = 0; j < 100; j = j + i + 2) {
//			a[j] = a[j] ? 0 : 1;
//		}
//	}
//
//	for (i = 0; i < 100; i++) {
//		if (a[i]) count++;
//	}
//	/**********End*************/
//	printf("%d", count);    //输出还有多少灯亮着
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//typedef long long LL;
//const int mod = 1e4;
//LL dp[20190325];   //数列从1下标开始
//int main() {
//	int n;
//	dp[1] = dp[2] = dp[3] = 1;
//	for (int i = 4; i < 20190325; i++) {
//		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % mod;
//	}
//	while (scanf("%d", &n) != EOF) {
//		cout << dp[n] << endl;
//	}
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	while (scanf("%d", &n) != EOF) {
//		vector<int> ans;
//		while (n != 0) {
//			ans.push_back(n % 2);
//			n /= 2;
//		}
//
//		for (int i = ans.size() - 1; i >= 0; i--) {
//			cout << ans[i];
//		}
//		cout << endl;
//	}
//	return 0;
//}


//矩阵快速幂
//#include<iostream>
//#include<stdio.h>
//using namespace std;
//#define maxn 110
//const long long mod=1000000007;
//long long size_;
//struct Matrix{
//	long long a[maxn][maxn];
//	Matrix operator*(const Matrix &B){
//		Matrix ret ;
//		int i,j,k;
//		for(i=0;i<size_;i++){
//			for(j=0;j<size_;j++){
//				ret.a[i][j]=0;
//				for(k=0;k<size_;k++)
//					ret.a[i][j]+=a[i][k]%mod*(B.a[k][j]%mod)%mod,ret.a[i][j]%=mod;
//			}
//		}
//		return ret;
//	}
//	void setE(){
//		/**************Begin****************/
//		for (int i = 0; i < size_; i++) {
//			a[i][i] = 1;
//		}
//		/***************End*****************/
//	}
//	Matrix pow(long long n){
//		Matrix t,A;t.setE();A=*this;
//		while(n>0){
//			if(n&1) t=t*A;
//			A=A*A;
//			n>>=1;
//		}
//		return t;
//	}
//	void pr(){
//		for(int i=0;i<size_;i++){
//			for(int j=0;j<size_;j++){
//				printf("%lld",a[i][j]%mod);
//			}
//			printf("\n");
//		}
//	}
//}M;
//int main(){
//	long long k,i,j;
//	while(scanf("%lld%lld",&size_,&k)!=EOF){
//		for(i=0;i<size_;i++){
//			for(j=0;j<size_;j++)
//				scanf("%lld",&M.a[i][j]);
//		}
//		Matrix t=M.pow(k);
//		t.pr();
//	}
//	return 0;
//}


//敲七游戏
//#include<bits/stdc++.h>
//using namespace std;
//
//bool panduan(int i) {
//	if (i % 7 == 0) {
//		return true;
//	}
//
//	while (i != 0) {
//		if (i % 10 == 7) {
//			return true;
//		}
//		i /= 10;
//	}
//	return false;
//}
//
//int main() {
//	int n;
//	cin >> n;
//	int ans = 0;
//	for (int i = 6; i <= n; i++) {
//		if (panduan(i)) ans++;
//	}
//
//	cout << ans << endl;
//	return 0;
//}


//防御导弹
//#include <bits/stdc++.h>
//using namespace std;
//
//
//int main() {
//	vector<int> a;
//	int n;
//	while (scanf("%d", &n) != EOF) {
//		a.push_back(n);
//	}
//
//	int i = a.size();
//
//	vector<int> ans(21, 1);
//	for (int j = 1; j < i; j++) {
//		for (int k = 0; k < j; k++) {
//			if (a[k] >= a[j]) {
//				ans[j] = max(ans[j], ans[k] + 1);
//			}
//		}
//	}
//
//	int ans_ = 1;
//	for (int k = 0; k < i; k++) {
//		ans_ = max(ans_, ans[k]);
//	}
//	cout << ans_ << endl;
//	return 0;
//}


//发工资
//#include<bits/stdc++.h>
//using namespace std;
//
//int nums(int x) {
//	int ans = 0;
//	ans += x / 100;
//	x %= 100;
//	ans += x / 50;
//	x %= 50;
//	ans += x / 10;
//	x %= 10;
//	ans += x / 5;
//	x %= 5;
//	ans += x / 2;
//	x %= 2;
//	ans += x;
//
//	return ans;
//}
//
//int main() {
//	int n;
//	while (scanf("%d", &n)) {
//		if (n == 0) break;
//		int x;
//		int ans = 0;
//		for (int i = 0; i < n; i++) {
//			cin >> x;
//			ans += nums(x);
//		}
//
//		cout << ans << endl;
//	}
//	return 0;
//}


// 移动字符串
//#include <stdio.h>
//#include <math.h>
//#include <string.h>
//int main() {
//	char s[1000] = { 0 }, ans[1000] = { 0 };
//	int pos;
//	scanf("%s %d", s, &pos);
//	int p = 0;
//	/***********Begin**************/
//	int len = strlen(s);
//	pos %= len;
//	if (pos == 0) {
//		for (int i = 0; i < len; i++) {
//			ans[i] = s[i];
//		}
//		ans[len] = '\0';
//	} else {
//		char temp[pos];
//		for (int i = 0; i < pos; i++) {
//			temp[i] = s[i];
//		}
//
//		for (int i = pos; i < len; i++) {
//			ans[i - pos] = s[i];
//		}
//
//		for (int i = len - pos; i < len; i++) {
//			ans[i] = temp[i - len + pos];
//		}
//		ans[len] = '\0';
//	}
//
//	/***********End**************/
//	printf("%s\n", ans);
//	return 0;
//}


//可能的青梅竹马
//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	string s1, s2;
//	cin >> s1 >> s2;
//	vector<int> a1, a2;
//	int left = 1, right = 1;
//	while (left != (int)s1.size()) {
//		if (s1[right] == ',' || s1[right] == ']') {
//			a1.push_back(stoi(string(s1.begin() + left, s1.begin() + right)));
//			left = right + 1;
//		}
//		right++;
//	}
//
//	left = 1, right = 1;
//	while (left != (int)s2.size()) {
//		if (s2[right] == ',' || s2[right] == ']') {
//			a2.push_back(stoi(string(s2.begin() + left, s2.begin() + right)));
//			left = right + 1;
//		}
//		right++;
//	}
//
//	sort(a1.begin(), a1.end());
//	sort(a2.begin(), a2.end());
//
//	int i = 0, j = 0;
//	int ans = INT32_MAX;
//	while (i < (int)a1.size() && j < (int)a2.size()) {
//		if (a1[i] != a2[j]) {
//			ans = min(ans, abs(a1[i] - a2[j]));
//			a1[i] > a2[j] ? j++ : i++;
//		} else {
//			ans = 0;
//			break;
//		}
//	}
//
//	cout << ans << endl;
//	return 0;
//}


//统计问题
//#include<bits/stdc++.h>
//using namespace std;
//
//using ll = long long;
//
//int main() {
//	vector<ll> a(21);
//	vector<ll> b(21);
//	vector<ll> c(21);
//
//	a[1] = b[1] = c[1] = 1;
//	for (int i = 2; i <= 20; i++) {
//		a[i] = a[i - 1] + b[i - 1] + c[i - 1];
//		b[i] = b[i - 1] + a[i - 1];
//		c[i] = c[i - 1] + a[i - 1];
//	}
//
//	int t, n;
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		cout << a[n] + b[n] + c[n] << endl;
//	}
//	return 0;
//}


//后缀表达式
//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n, m;
//
//	while (cin >> n >> m) {
//		int fu_cnt = 0;
//		int max_one = -1000000000;
//		int min_one = 1000000000;
//		vector<int> a(m + n + 1);
//		for (int i = 0; i < m + n + 1; i++) {
//			cin >> a[i];
//			max_one = max(max_one, a[i]);
//			min_one = min(min_one, a[i]);
//			if (a[i] < 0) fu_cnt++;
//		}
//
//		int ans = 0;
//		if (m == 0) {
//			for (int num : a) ans += num;
//		} else {
//			for (int num : a) {
//				if (num == max_one) {
//					ans += num;
//				} else if (num == min_one) {
//					ans -= num;
//				} else {
//					ans += abs(num);
//				}
//			}
//		}
//
//		cout << ans << endl;
//	}
//
//	return 0;
//}


//Octal Fractions 2024 11 11 比较难理解，它是逐位运算的
//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	string s1;
//	while (cin >> s1) {
//		vector<int> ans(3 * s1.size() + 1);
//		int t = 0;
//		for (int i = s1.size() - 1; i >= 2; i--) {
//			int d = s1[i] - '0';
//			int k = 0, j = 0;
//			while (j < t || d) {
//				d = d * 10 + ans[j++];
//				ans[k++] = d / 8;
//				d %= 8;
//			}
//			t = k;
//		}
//
//		cout << s1 << "[8]=0.";
//		for (int i = 0; i < t; i++) {
//			cout << ans[i];
//		}
//		cout << "[10]" << endl;
//	}
//
//	return 0;
//}


//子序列 2024 11 12 我认为没问题，但是过不了
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	string s, t;
//	cin >> s >> t;
//	int max_common = 0;
//	for (int i = 0; i <= (int)(s.size() - t.size()); i++) {
//		int max_common_temp = 0;
//		for (int j = 0; j < (int)t.size(); j++) {
//			if (t[j] == s[i + j]) max_common_temp++;
//		}
//		max_common = max(max_common, max_common_temp);
//	}
//
//	cout << t.size() - max_common << endl;
//	return 0;
//}


//同上题 这个是答案 能过
//#include<bits/stdc++.h>
//using namespace std;
//
//const int N = 1e3+10;
//int dp[N][N];
//string s, t;
//
//int main() {
//	cin >> s >> t;
//	int ls = s.size();
//	int lt = t.size();
//	if (s[0] != t[0]) {
//		dp[0][0] = 1;
//	}
//	for (int i = 1; i < lt; i++) {
//		if(s[i] == t[i]) dp[i][i] = dp[i - 1][i - 1];
//		else dp[i][i] = dp[i - 1][i - 1] + 1;
//	}
//	for (int i = 1; i < ls; i++) {
//		if (s[i] == t[0]) dp[i][0] = 0;
//		else dp[i][0] = dp[i - 1][0];
//	}
//	for (int j = 1; j < lt; j++) {
//		for (int i = j + 1; i < ls; i++) {
//			if (s[i] == t[j]) dp[i][j] = dp[i - 1][j - 1];
//			else dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1] + 1);
//		}
//	}
//
//	printf("%d\n", dp[ls - 1][lt - 1]);
//	return 0;
//}


//查找素数对
//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	int ans = 0;
//	for (int i = 0; i < n; i++) cin >> a[i];
//	for (int i = 0; i < n - 2; i++) {
//		for (int j = i + 1; j < n - 1; j++) {
//			for (int k = j + 1; k < n; k++) {
//				if ((gcd(a[i], a[j]) == 1 && gcd(a[i], a[k]) == 1 && gcd(a[k], a[j]) == 1) || (gcd(a[i], a[j]) != 1 && gcd(a[i], a[k]) != 1 && gcd(a[k], a[j]) != 1)) {
//					ans++;
//				}
//			}
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}


//简单逆序对
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++) cin >> a[i];
//	int ans = 0;
//	for (int i = 0; i < n - 1; i++) {
//		for (int j = i + 1; j < n; j++) {
//			if (a[j] < a[i]) ans++;
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}


//题目很长懒得写
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n, c;
//	cin >> n >> c;
//	vector<int> p(n), t(n);
//	for (int i = 0; i < n; i++) cin >> p[i];
//	for (int i = 0; i < n; i++) cin >> t[i];
//	int sum1 = 0, sum2 = 0;
//	int tq = 0;
//	for (int i = 0; i < n; i++) {
//		tq += t[i];
//		sum1 += max(0, p[i] - c * tq);
//	}
//
//	tq = 0;
//	for (int i = n - 1; i >= 0; i--) {
//		tq += t[i];
//		sum2 += max(0, p[i] - c * tq);
//	}
//
//	if (sum1 > sum2) cout << "Limak" << endl;
//	else if (sum1 < sum2) cout << "Radewoosh" << endl;
//	else cout << "Tie" << endl;
//	return 0;
//}


// 砍树 被他搞死，下标从1开始呜呜呜
//#include<stdio.h>
//#include<stdlib.h>
//
//int max(int x, int y) {
//	return x > y ? x : y;
//}
//int main() {
//	int n, bz, mid, leftt = 0, longest = 0, trees[1000008];
//	scanf("%d%d", &n, &bz);
//	for (int i = 1; i <= n; i++) {
//		scanf("%d", &trees[i]);
//		longest = max(longest, trees[i]); //找到最长木材
//	}
//	/*************Begin*************/
//	while (leftt < longest) {
//		mid = (leftt + longest + 1) >> 1;
//		int sum = 0;
//		for (int i = 1; i <= n; i++) {
//			if (trees[i] > mid) sum += trees[i] - mid;
//		}
//		if (sum >= bz) leftt = mid;
//		else longest = mid - 1;
//	}
//	/*************End*************/
//	printf("%d\n", leftt);
//	return 0;
//}
