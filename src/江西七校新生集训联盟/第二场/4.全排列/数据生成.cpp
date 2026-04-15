#include <fstream>
#include <ctime>
#include <cstdlib>
#include <bits/stdc++.h>
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
		out << i;
	}
	return 0;
}
