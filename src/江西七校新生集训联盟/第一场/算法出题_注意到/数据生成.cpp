#include <fstream>
#include <ctime>
#include <iostream>
using namespace std;

int randint(int l, int r) {
	return rand() % (r - l + 1) + l;
}

signed main() {
	srand(time(0));
	int cnt_t = 50;
	for (int t = 1; t <= cnt_t; t++) {
		string name = "./test_data/" + to_string(t) + ".in";
		ofstream out(name);
		int n = randint(9, 100000);
		n = n / 9 * 9;
		out << n;
		cout << n << endl;
		out.close();
	}
	return 0;
}
