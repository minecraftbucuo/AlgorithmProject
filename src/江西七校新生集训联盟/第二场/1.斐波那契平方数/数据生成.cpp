#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;
#define int long long

int randint(int l, int r) {
	return rand() * rand() % (r - l + 1) + l;
}

signed main() {
	srand(time(0));
	int T = 6;
	for (int i = 1; i <= T; i++) {
		string name = "./test_data/" + to_string(i) + ".in";
		ofstream out(name);
		if (i <= 3) {
			int x = randint(1, 1000000000) * randint(1, 1000000000);
			out << x;
		} else if (i == 4) {
			out << (int)1e18 << endl;
		} else if (i == 5) {
			out << 1 << endl;
		} else {
			out << 2 << endl;
		}
	}
	return 0;
}
