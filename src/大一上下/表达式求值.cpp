#include <bits/stdc++.h>
using namespace std;

stack<int> num;
stack<char> op;
unordered_map<char, int> pr = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

void calc() {
	int b = num.top();
	num.pop();
	int a = num.top();
	num.pop();
	char o = op.top();
	op.pop();

	if (o == '+') num.push(a + b);
	else if (o == '-') num.push(a - b);
	else if (o == '*') num.push(a * b);
	else if (o == '/') num.push(a / b);
}

int main() {
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (isdigit(s[i])) {
			int x = 0, j = i;
			while (j < s.size() && isdigit(s[j])) {
				x = 10 * x + s[j] - '0';
				j++;
			}
			num.push(x);
			i = j - 1;
		} else if (s[i] == '(') {
			op.push('(');
		} else if (s[i] == ')') {
			while (op.top() != '(') calc();
			op.pop();
		} else {
			while (!op.empty() && pr[op.top()] >= pr[s[i]]) calc();
			op.push(s[i]);
		}
	}

	while (!op.empty()) calc();
	cout << num.top() << endl;
	return 0;
}

