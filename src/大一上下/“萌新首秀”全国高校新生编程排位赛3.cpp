//2024 10 11

//#include <iostream>
//using namespace std;
//int main() {
//	cout << 2028;
//	return 0;
//}


//#include <iostream>
//#include <unordered_map>
//using namespace std;
//int main() {
//	// 请在此输入您的代码
//	int n, x;
//	unordered_map<int, int> map;
//	cin >> n;
//	while (n--) {
//		cin >> x;
//		map[x]++;
//	}
//	for (int i = 1; ; i++) {
//		if (!map[i]) {
//			cout << i;
//			break;
//		}
//	}
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//
//bool is_chaoji(string str) {
//	char c = str[0];
//	for (int i = 1; i < (int)str.size(); i++) {
//		if (c != str[i]) return false;
//	}
//	return true;
//}
//
//int main() {
//	// 请在此输入您的代码
//	int n, ans = 0;
//	string str;
//	cin >> n;
//	while (n--) {
//		cin >> str;
//		if (is_chaoji(str)) ans++;
//	}
//
//	cout << ans;
//	return 0;
//}


//#include <iostream>
//#include <vector>
//#include <set>
//using namespace std;
//int main() {
//	// 请在此输入您的代码
//	set<int> set_data;
//	int n;
//	cin >> n;
//	vector<int> data(n);
//	for (int i = 0; i < n; i++) {
//		cin >> data[i];
//	}
//
//	for (int num : data) {
//		set_data.insert(num);
//	}
//
//	for (int x = 0; x < n; x++) {
//		for (int y = x + 1; y < n; y++) {
//			set_data.insert(data[x] + data[y]);
//		}
//	}
//
//	for (int x = 0; x < n; x++) {
//		for (int y = x + 1; y < n; y++) {
//			for (int z = y + 1; z < n; z++) {
//				set_data.insert(data[x] + data[y] + data[z]);
//			}
//		}
//	}
//
//	cout << set_data.size() + 1;
//
//	return 0;
//}


#include <iostream>
using namespace std;
int main() {
	// 请在此输入您的代码
	int n;
	cin >> n;
	if (n & 1) {
		cout << 1;
	} else {
		cout << n / 2;
	}
	return 0;
}
