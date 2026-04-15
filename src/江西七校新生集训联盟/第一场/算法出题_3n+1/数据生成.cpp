#include <fstream>
#include <ctime>
#define int long long
using namespace std;

int randint(int l, int r) {
	if (r < l) return 0;
	return (rand() * rand() % (r - l + 1)) + l;
}

signed main() {
	srand(time(0));
	int cnt_t = 100;
	for (int t = 1; t <= cnt_t; t++) {
		string out_name = "./test_data/" + to_string(t) + ".in";
		ofstream out(out_name);
		out << 1 << ' ' << randint(1, 1e6) * randint(1, 1e6);
		out.close();
	}
	return 0;
}
