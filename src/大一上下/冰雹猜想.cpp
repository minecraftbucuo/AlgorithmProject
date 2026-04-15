//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	// 定义一个数组存储每次变化后的n，初始只有一个元素即为 n
//	vector<int> arr = {n};
//	// 循环退出条件为 n==1 时
//	while (n != 1) {
//		if (n % 2 == 1) {
//			n = n * 3 + 1;
//			// 把变化后的n加入数组
//			arr.push_back(n);
//		} else {
//			n = n / 2;
//			// 把变化后的n加入数组
//			arr.push_back(n);
//		}
//	}
//
//	// 倒着输出数组里的元素 其中 arr.size() 表示数组arr中的元素个数
//	for (int i = arr.size() - 1; i >= 0; i--) {
//		cout << arr[i] << " ";
//	}
//	return 0;
//}


#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> jihao(n + 1);
	for (int i = 1; i <= n; i++) {
		string s;
		getline(cin, s);
		jihao[i] = s;
	}
//	for (string s : jihao) cout << s;
	vector<int> hang(m);
	for (int i = 0; i < m; i++) cin >> hang[i];
	unordered_map<int, vector<int>> mp;
//	vector<vector<int>> mp(10, vector<int>(n + 1));
//	for (int i = 0; i < m; i++) {
//		mp[hang[i]].resize(n + 1);
//	}
//	for (int i = 0; i < m; i++) {
//		for (int j = 1; j <= n; j++) {
//			cin >> mp[hang[i]][j];
//		}
//	}
//	int t;
//	cin >> t;
//	while (t--) {
//		string x;
//		cin >> x;
//		int h, l;
//		if (x.size() == 1) {
//			h = 0;
//			l = x[0] - '0';
//		} else {
//			h = x[0] - '0';
//			l = x[1] - '0';
//		}
//		if (mp.find(h) == mp.end()) {
//			cout << "?" << endl;
//		} else {
//			int t = mp[h][l];
//			cout << jihao[t] << endl;
//		}
//	}
	return 0;
} 
