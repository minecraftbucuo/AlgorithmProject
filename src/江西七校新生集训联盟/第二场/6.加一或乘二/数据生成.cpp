#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

int randint(int l, int r) {
	return rand() * rand() % (r - l + 1) + l;
}

signed main() {
	srand(time(0));
	int T = 8;
	for (int i = 1; i <= T; i++) {
		string name = "./test_data/" + to_string(i) + ".in";
		ofstream out(name);
		if (i <= 5) {
			int n = randint(1, 100000);
			out << n << endl;
			int mx = 0;
			out << mx << ' ';
			for (int j = 2; j <= n; j++) {
				int t = (randint(0, 1) ? 0 : mx + 1);
				out << t << ' ';
				mx = max(mx, t);
			}
		} else if (i == 6) {
			out << 2 << endl;
			out << 0 << ' ' << 0;
		} else if (i == 7) {
			out << 2 << endl;
			out << 0 << ' ' << 1;
		} else {
			int n = randint(3, 5);
			out << n << endl;
			int mx = 0;
			out << mx << ' ';
			for (int j = 2; j <= n; j++) {
				int t = (randint(0, 1) ? 0 : mx + 1);
				out << t << ' ';
				mx = max(mx, t);
			}
		}

	}
	return 0;
}
