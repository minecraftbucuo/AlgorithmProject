#include <fstream>
#include <vector>
//#define int long long
using namespace std;
const int mod = 1e9 + 7;


signed main() {
	int T = 8;
	for (int i = 1; i <= T; i++) {
		string in_name = "./test_data/" + to_string(i) + ".in";
		string out_name = "./test_data/" + to_string(i) + ".out";
		ifstream in(in_name);
		ofstream out(out_name);
		int n;
		in >> n;
		vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) in >> a[i];
		int ans = 2;
		for (int i = 2; i <= n; i++) {
			if (a[i] > a[i - 1]) ans = 2 * ans % mod;
			else ans = (ans + 1) % mod;
		}
		out << ans << endl;
	}
	return 0;
}
