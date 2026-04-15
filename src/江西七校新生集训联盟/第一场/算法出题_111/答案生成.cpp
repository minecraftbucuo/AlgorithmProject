#include <fstream>
#include <vector>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

signed main() {
	int cnt_t = 100;
	for (int t = 1; t <= cnt_t; t++) {
		string in_name = "./test_data/" + to_string(t) + ".in";
		string out_name = "./test_data/" + to_string(t) + ".out";

		ifstream in(in_name);
		ofstream out(out_name);
		int n;
		in >> n;
		vector<int> a(n + 1);
		a[0] = 1, a[1] = 2, a[2] = 4;
		for (int i = 3; i <= n; i++) a[i] = (a[i - 1] + a[i - 2] + a[i - 3]) % mod;
		out << a[n];

		in.close();
		out.close();
	}
	return 0;
}
