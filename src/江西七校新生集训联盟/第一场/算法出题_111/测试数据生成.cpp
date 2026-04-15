#include <fstream>
#include <ctime>
using namespace std;

int randint(int l, int r) {
	if (r < l) return 0;
	return (rand() * rand() % (r - l + 1)) + l;
}

signed main() {
	srand(time(0));
	int cnt_t = 100;
	for (int t = 1; t <= cnt_t; t++) {
		string name = "./test_data/" + to_string(t) + ".in";
		ofstream out(name);
		int n = randint(1, 1000000);
		if (t <= 10) n = t;
		out << n;
		out.close();
	}
	return 0;
}
