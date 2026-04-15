#include<bits/stdc++.h>
using namespace std;

int main() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			for (int k = 0; k < 6; k++) {
				cout << (i + j + k) % 6 + 1 << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}
