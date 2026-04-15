/******begin******/
#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		vector<double> fen(n);
		for (int i = 0; i < n; i++) {
			cin >> fen[i];
		}

		sort(fen.begin(), fen.end());

		double sum = 0;
		for (int i = 1; i < n - 1; i++) {
			sum += fen[i];
		}

		printf("%.2lf\n", (sum / (n - 2)));
	}
}
/*******end*******/

