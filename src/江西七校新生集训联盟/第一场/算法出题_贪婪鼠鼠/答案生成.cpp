#include <fstream>
using namespace std;


signed main() {
	int cnt_t = 6;
	for (int t = 1; t <= cnt_t; t++) {
		string in_name = "./test_data/" + to_string(t) + ".in";
		string out_name = "./test_data/" + to_string(t) + ".out";
		ifstream in(in_name);
		ofstream out(out_name);
		int T;
		in >> T;
		while (T--) {
			int n, m;
			in >> n >> m;
			if (n & 1) out << "1.00" << endl;
			else out << "0.00" << endl;
		}
		in.close();
		out.close();
	}
	return 0;
}
