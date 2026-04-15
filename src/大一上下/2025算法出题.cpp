// 1
//#include <bits/stdc++.h>
//using namespace std;
//
//bool is_prime(int x) {
//	for (int i = 2; i * i <= x; i++)
//		if (x % i == 0)
//			return false;
//	return true;
//}
//
//int main() {
//	for (int i = 2; i <= 10000; i++) {
//		if (is_prime(i)) cout << i << endl;
//	}
//	return 0;
//}


// 2
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	string A = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//	string s = "", t;
//	while (cin >> t) {
//		s += t;
//	}
//	unordered_map<char, int> mp;
//	for (int i = 0; i < (int)s.size(); i++) {
//		if ('A' <= s[i] && s[i] <= 'Z') {
//			mp[s[i]]++;
//		}
//	}
//	int hang = 0;
//	for (auto x : mp) {
//		hang = max(hang, x.second);
//	}
//	for (int i = 0; i < hang; i++) {
//		for (char c : A) {
//			if (mp[c] + i >= hang) {
//				cout << "*" << " \n"[c == 'Z'];
//			} else {
//				cout << " " << " \n"[c == 'Z'];
//			}
//		}
//	}
//	cout << "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";
//	return 0;
//}



// 3

