#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	if (n < 2) {
		cout << 0;
	} else if (n == 2) {
		cout << 2 << endl << 1;
	} else {
		vector<int> p;
		p.push_back(2);
		int sum = 2;
		int i = 3;
		while (sum <= n) {
			for (int j = 0; j < (int)p.size(); j++) {
				if (i % p[j] == 0) {
					break;
				}

				if (j == (int)p.size() - 1) {
					p.push_back(i);
					sum += i;
				}
			}

			i++;
		}

		p.pop_back();

		for (int k = 0; k < (int)p.size(); k++) {
			cout << p[k] << endl;
		}
		cout << p.size();
	}


	return 0;
}
