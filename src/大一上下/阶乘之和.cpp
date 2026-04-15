#include<iostream>
using namespace std;

int a[1024], res[1024];

int main() {
	int n;

	cin >> n;
	a[0] = 1;
	res[0] = 1;
	for (int i = 2; i <= n; i++) {
		int carry = 0;
		for (int j = 0; j < 1024; j++) {
			a[j] = a[j] * i + carry;
			carry = a[j] / 10;
			a[j] %= 10;
		}

		int carry2 = 0;
		for (int j = 0; j < 1024; j++) {
			res[j] = res[j] + a[j] + carry2;
			carry2 = res[j] / 10;
			res[j] %= 10;
		}

	}

	int i;
	for (i = 1024; i >= 0; i--) {
		if (res[i] != 0) {
			break;
		}
	}

	for (int j = i; j >= 0; j--) {
		cout << res[j];
	}
	return 0;
}
