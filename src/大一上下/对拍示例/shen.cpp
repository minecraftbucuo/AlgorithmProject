#include <bits/stdc++.h>
using namespace std;

int randint(int l, int r)
{
    return (rand() % (r - l + 1)) + l;
}

int main()
{
    srand(time(0));
    int n = randint(10, 30000);
    string s = "";
    for (int i = 1; i <= n; i++)
        s += randint(0, 25) + 'a';
    cout << s;
    return 0;
}