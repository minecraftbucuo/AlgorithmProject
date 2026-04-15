//#include <iostream>
//using namespace std;
//
//int main() {
//	int t;
//	cin >> t;
//	for (int i = 0; i < t; i++) {
//		int a, b;
//		cin >> a >> b;
//		cout << b - a << endl;
//	}
//	return 0;
//}


//#include <iostream>
//using namespace std;
//
//int main() {
//	int t;
//	cin >> t;
//	for (int i = 0; i < t; i++) {
//		int a;
//		cin >> a;
//		int niu = a / 4;
//		int kun = (a % 4) / 2;
//		cout << niu + kun << endl;
//	}
//	return 0;
//}


//#include <iostream>
//#include <cmath>
//using namespace std;
//
//int main() {
//	int t;
//	int x, y, k;
//	cin >> t;
//	for (int i = 0; i < t; i++) {
//
//		cin >> x >> y >> k;
//		int xia = ceil(y * 1.0 / k);
//		int you = ceil(x * 1.0 / k);
//		if (you > xia) {
//			cout << 2 * xia + (you - xia) * 2 - 1 << endl;
//		} else if (you == xia) {
//			cout << 2 * xia << endl;
//		} else {
//			cout << 2 * you - 1 + (xia - (you - 1)) * 2 - 1 << endl;
//		}
//	}
//	return 0;
//}


//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//int main() {
//	int t, n;
//	cin >> t;
//	for (int i = 0; i < t; i++) {
//		cin >> n;
//		vector<string> vec(n);
//		for (int j = 0; j < n; j++) {
//			cin >> vec[j];
//		}
//
//		for (int k = n - 1; k >= 0; k--) {
//			for (int x = 0; x < 4; x++) {
//				if (vec[k][x] == '#') {
//					cout << x + 1 << " ";
//					break;
//				}
//			}
//		}
//		cout << endl;
//	}
//	return 0;
//}


//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//int main() {
//	int t, n, k;
//	cin >> t;
//	for (int i = 0; i < t; i++) {
//		cin >> n >> k;
//		int num = n / k;
//		vector<string> vec(n);
//		for (int j = 0; j < n; j++) {
//			cin >> vec[j];
//		}
//
//		for (int y = 0; y < num; y++) {
//			for (int x = 0; x < num; x++) {
//				cout << vec[k * y][k * x];
//			}
//			cout << endl;
//		}
//	}
//	return 0;
//}


//#include <iostream>
//#include <cmath>
//using namespace std;
//
//int main() {
//	int t, x, y;
//	cin >> t;
//	for (int i = 0; i < t; i++) {
//		cin >> x >> y;
//		if (y % 2 == 0) {
//			int ans = y / 2;
//			int shen = 7 * ans;
//			if (x <= shen) {
//				cout << ans << endl;
//			} else {
//				ans = ans + ceil((x - shen) * 1.0 / 15);
//				cout << ans << endl;
//			}
//		} else {
//			int ans = y / 2 + 1;
//			int shen = 7 * (ans - 1) + 11;
//			if (x <= shen) {
//				cout << ans << endl;
//			} else {
//				ans = ans + ceil((x - shen) * 1.0 / 15);
//				cout << ans << endl;
//			}
//		}
//	}
//	return 0;
//}


#include <iostream>
using namespace std;

int main() {
	int t, a, b, c;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a >> b >> c;
		int ans = 0;
		for (int i = 0; i <= 5; i++) {
			for (int j = 0; j <= 5; j++) {
				if ( 5 - i - j >= 0)
					ans = ans > (a + i) * (b + j) * (c + 5 - i - j) ? ans : (a + i) * (b + j) * (c + 5 - i - j);
				else
					break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
