//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int n;
//		cin >> n;
//		vector<int> a(n);
//		for (int i = 0; i < n; i++) cin >> a[i];
//		sort(a.begin(), a.end());
//		cout << a.back() - a[0] << endl;
//	}
//	return 0;
//}



//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		string a, b;
//		int n;
//		cin >> n;
//		cin >> a >> b;
//		int jia = 0, oua = 0;
//		for (int i = 0; i < n; i++) {
//			if (a[i] == '1') {
//				if ((i + 1) % 2 == 0) oua++;
//				else jia++;
//			}
//		}
//		int jib = 0, oub = 0;
//		for (int i = 0; i < n; i++) {
//			if (b[i] == '0') {
//				if (i % 2 == 0) {
//					oub++;
//				} else jib++;
//			}
//		}
////		cout << "jia" << jia << " oua" << oua << endl;
////		cout << "jib" << jib << " oub" << oub << endl;
//		if (jib >= jia && oub >= oua) cout << "Yes" << endl;
//		else cout << "No" << endl;
//	}
//	return 0;
//}



#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		int ji = 0, ou = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] & 1) ji++;
			else ou++;
		}
		if (ji == 0 || ou == 0) cout << *max_element(a.begin(), a.end()) << endl;
		else {
			int jia = 0;
			for (int i = 0; i < n - 1; i++) {
				if (a[i] & 1) jia += a[i] - 1;
				else jia += a[i];
			}
			cout << a.back() + jia << endl;
		}
	}
	return 0;
}
