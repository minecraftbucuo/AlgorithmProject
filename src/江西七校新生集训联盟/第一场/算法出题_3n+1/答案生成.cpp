#include <fstream>
using namespace std;
#define int long long

signed main() {
	int cnt_t = 100;
	for (int t = 1; t <= cnt_t; t++) {
		string in_name = "./test_data/" + to_string(t) + ".in";
		string out_name = "./test_data/" + to_string(t) + ".out";

		ifstream in(in_name);
		ofstream out(out_name);

		int n, m;
		in >> n >> m;
		out << 1;

		in.close();
		out.close();
	}
	return 0;
}
