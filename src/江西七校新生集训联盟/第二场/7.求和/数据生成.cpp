#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

int randint(int l, int r) {
	return rand() * rand() % (r - l + 1) + l;
}

signed main() {
	srand(time(0));
	int T = 12;
	for (int i = 1; i <= T; i++) {
		string name = "./test_data/" + to_string(i) + ".in";
		ofstream out(name);
		if (i <= 6) {
			int n = randint(1, 100000) * randint(1, 10000);
			int m = randint(1, 10000) * randint(1, 10000);
			if (m == 1) m++;
			out << n << ' ' << m;
		} else if (i <= 11) {
			int n = randint(1, 100000) * randint(1, 10000);
			int m = randint(1, 100);
			if (m == 1) m++;
			out << n << ' ' << m;
		} else {
			int n = 1000000000;
			int m = 2;
			out << n << ' ' << m;
		}
	}
	return 0;
}
