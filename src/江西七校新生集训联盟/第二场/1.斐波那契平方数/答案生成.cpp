#include <fstream>
#include <vector>
using ll = long long;
using namespace std;


signed main() {
	int T = 6;
	for (int i = 1; i <= T; i++) {
		string in_name = "./test_data/" + to_string(i) + ".in";
		string out_name = "./test_data/" + to_string(i) + ".out";
		ifstream in(in_name);
		ofstream out(out_name);
		ll x;
		in >> x;
		if (x < 144) out << 2 << endl;
		else out << 3 << endl;
	}
	return 0;
}
