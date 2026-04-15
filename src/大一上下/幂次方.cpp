#include<bits/stdc++.h>
using namespace std;

string trans(int n) {
	if (n == 0) {
		string s = "2(0)";
		return s;
	} else if (n == 1) {
		string s = "2";
		return s;
	} else if (n == 2) {
		string s = "2(2)";
		return s;
	} else {
		vector<int> b;
		int n_copy = n;
		while (n_copy != 1) {
			b.push_back(n_copy % 2);
			n_copy /= 2;
		}
		b.push_back(1);

		string s1 = "";
		for (int i = b.size() - 1; i >= 0; i--) {
			if (b[i] == 0)
				continue;
			s1 += trans(i) + "+";
		}
		s1.pop_back();

		string s2 = "2(" + s1 + ")";
		return s2;
	}
}

string ans(int n) {
	vector<int> b;
	int n_copy = n;
	while (n_copy != 1) {
		b.push_back(n_copy % 2);
		n_copy /= 2;
	}
	b.push_back(1);

	string ans = "";
	for (int i = b.size() - 1; i >= 0; i--) {
		if (b[i] == 0)
			continue;
		ans += trans(i) + "+";
	}
	ans.pop_back();

	return ans;
}

int main() {
	int n;
	cin >> n;
	string s = ans(n);
	cout << s;
	return 0;
}
