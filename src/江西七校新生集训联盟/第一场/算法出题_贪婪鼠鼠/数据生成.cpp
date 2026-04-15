#include <fstream>
#include <ctime>
using namespace std;

int randint(int l, int r) {
	if (r < l) return 0;
	return (rand() * rand() % (r - l + 1)) + l;
}

signed main() {
	srand(time(0));
	int cnt_t = 6;
	for (int t = 1; t <= cnt_t; t++) {
		string name = "./test_data/" + to_string(t) + ".in";
		ofstream out(name);
		int T = randint(10, 20);
		out << T << endl;
		while (T--) {
			int n = randint(0, 100000), m = randint(0, 100000 - n);
			out << n << ' ' << m << endl;
		}
		out.close();
	}
	return 0;
}
