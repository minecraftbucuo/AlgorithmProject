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
	int T = 6;
	vector<string> a = {"High", "Medium", "Low"};
	vector<string> b = {"Military", "Livelihood", "Governance", "PersonalCultivation"};
	for (int i = 1; i <= T; i++) {
		string name = "./test_data/" + to_string(i) + ".in";
		ofstream out(name);
		int n = randint(1, 1000);
		out << n << endl;
		for (int j = 1; j <= n; j++) {
			out << a[randint(0, 2)] << ' ' << b[randint(0, 3)] << endl;
		}
	}
	return 0;
}
