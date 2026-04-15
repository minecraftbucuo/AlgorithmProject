#include <fstream>
using namespace std;
#define int long long

signed main() {
	int cnt_t = 50;
	for (int t = 1; t <= cnt_t; t++) {
		string out_name = "./test_data/" + to_string(t) + ".out";
		string in_name = "./test_data/" + to_string(t) + ".in";
		ofstream out(out_name);
		ifstream in(in_name);
		int x;
		in >> x;
		x /= 9;
//		int a = x - 1, b = 1;
//		int c = 1 + 3 * x - x * x * x;
//		int d = 1 + x + x * x;
//		int e = 3 * x + 3 * x * x;
//		out << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << d << endl;
		out << endl;
		out.close();
	}
	return 0;
}
