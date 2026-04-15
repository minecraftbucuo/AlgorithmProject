#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

const int N = 500000 + 10, P = 131;
ull zuo[N], you[N], p[N];

void Hash(string s)
{
    p[0] = 1, zuo[0] = s[0], you[0] = s.back();
    for (int i = 1; i <= (int)s.size(); i++)
        p[i] = P * p[i - 1];
    for (int i = 1; i < (int)s.size(); i++)
        zuo[i] = zuo[i - 1] * P + s[i];
    for (int i = s.size() - 2, j = 1; i >= 0; i--, j++)
        you[j] = you[j - 1] * P + s[i];
}

ull get(int l, int r, ull a[])
{
    if (l == 0)
        return a[r];
    return a[r] - a[l - 1] * p[r - l + 1];
}

bool check(int mid, int i, int mode)
{
    if (mid == 0)
        return true;
    if (mode)
        return get(i, i + mid - 1, you) == get(0, mid - 1, zuo);
    else
        return get(i, i + mid - 1, zuo) == get(0, mid - 1, you);
}

signed main()
{
    string s;
    cin >> s;
    int ans = 0;
    while (s.size() >= 2 && s.front() == s.back())
    {
        ans++;
        s.erase(s.begin());
        s.erase(s.end() - 1);
    }
    Hash(s);
    int maxn = 0;
    for (int i = 1; i <= (int)s.size() - 1; i++)
    {
        int l = 0, r = (s.size() - i) / 2;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (check(mid, i, 0))
                l = mid + 1;
            else
                r = mid - 1;
        }
        maxn = max(maxn, l - 1);
    }
    // for (int i = 1; i < (int)s.size() - 1; i++)
    // {
    //     int l = 0, r = (s.size() - i) / 2;
    //     while (l <= r)
    //     {
    //         int mid = (l + r) >> 1;
    //         if (check(mid, i, 1))
    //             l = mid + 1;
    //         else
    //             r = mid - 1;
    //     }
    //     maxn = max(maxn, l - 1);
    // }
    cout << ans + maxn << endl;
    return 0;
}