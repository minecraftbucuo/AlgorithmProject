#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

int randint(int l, int r) {
	return rand() * rand() % (r - l + 1) + l;
}

signed main() {
	srand(time(0));
	int T = 6;
	for (int i = 1; i <= T; i++) {
		string name = "./test_data/" + to_string(i) + ".in";
		ofstream out(name);
		int n = randint(1, 100000);
		out << n << endl;
		for (int j = 1; j <= n; j++) {
			out << randint(0, 1000000) * (randint(0, 1) ? -1 : 1) << ' ';
		}
	}
	return 0;
}
