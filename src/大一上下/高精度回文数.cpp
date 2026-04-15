// 2024.10.5

#include<bits/stdc++.h>
using namespace std;

char m[303];
int n;

bool is_hui(char a[], int l) {
	for (int i = 0, j = l - 1; i < l; i++, j--) {
		if (a[i] != a[j]) return false;
	}
	return true;
}

void trans(char a[], int n, int& l) {
	char b[303];
	memset(b, 0, sizeof(b));
	for (int i = 0; i < l; i++) {
		b[i] = a[l - i - 1];
	}
	l += 2;
	for (int i = 0; i < l; i++) {
		a[i] = a[i] + b[i];
		if (a[i] >= n) {
			a[i] -= n;
			a[i + 1]++;
		}
	}

	while (!a[l - 1]) l--;
}

int main() {
	cin >> n >> m;
	int l = strlen(m);

	for (int i = 0; i < l; i++) {
		if (m[i] >= '0' && m[i] <= '9') m[i] -= '0';
		else m[i] = m[i] - 'A' + 10;
	}
	int ans = 0;
	while (!is_hui(m, l)) {
		trans(m, n, l);
		ans++;
		if (ans >= 30) {
			cout << "Impossible!";
			return 0;
		}
	}

	cout << "STEP=" << ans;

	return 0;
}
