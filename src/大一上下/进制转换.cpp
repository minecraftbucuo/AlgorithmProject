// 2024.10.5

#include<bits/stdc++.h>
using namespace std;

int to_int(char a) {
	switch (a) {
		case '0':
			return 0;
			break;
		case '1':
			return 1;
			break;
		case '2':
			return 2;
			break;
		case '3':
			return 3;
			break;
		case '4':
			return 4;
			break;
		case '5':
			return 5;
			break;
		case '6':
			return 6;
			break;
		case '7':
			return 7;
			break;
		case '8':
			return 8;
			break;
		case '9':
			return 9;
			break;
		case 'A':
			return 10;
			break;
		case 'B':
			return 11;
			break;
		case 'C':
			return 12;
			break;
		case 'D':
			return 13;
			break;
		case 'E':
			return 14;
			break;
		case 'F':
			return 15;
			break;
	}
}

char to_char(int x) {
	switch (x) {
		case 0:
			return '0';
			break;
		case 1:
			return '1';
			break;
		case 2:
			return '2';
			break;
		case 3:
			return '3';
			break;
		case 4:
			return '4';
			break;
		case 5:
			return '5';
			break;
		case 6:
			return '6';
			break;
		case 7:
			return '7';
			break;
		case 8:
			return '8';
			break;
		case 9:
			return '9';
			break;
		case 10:
			return 'A';
			break;
		case 11:
			return 'B';
			break;
		case 12:
			return 'C';
			break;
		case 13:
			return 'D';
			break;
		case 14:
			return 'E';
			break;
		case 15:
			return 'F';
			break;
	}
}

int main() {
	int a, c;
	string b;
	cin >> a;
	cin >> b >> c;

	int x = 0;
	for (int i = 0; i < b.size(); i++) {
		x += to_int(b[i]) * (int)pow(a, b.size() - 1 - i);
	}

	vector<char> ans;
	while (x != 0) {
		int a = x % c;
		ans.push_back(to_char(a));
		x /= c;
	}

	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i];

	return 0;
}
