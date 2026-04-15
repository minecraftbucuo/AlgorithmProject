#include <bits/stdc++.h>
#define rep(i, a, n) for (int(i) = (a); (i) <= (n); (i)++)
#define pre(i, a, n) for (int(i) = (a); (i) >= (n); (i)--)
#define ull unsigned long long
#define int long long
using namespace std;
const int N = 1000000 + 10;
const ull Hash = 911;    // 为了防止被卡，而且发现911也是一个质数qwq
ull ha[N], hb[N], pw[N]; // 哈希自然溢出
ull gethash(ull t[], int l, int r)
{
    return t[r] - t[l - 1] * pw[r - l + 1]; // 取区间字符串哈希值11
}
int solve(string s)
{
    int n = s.size();
    s = " " + s; // 在s前插一个空格，这样下标就从1开始了
    pw[0] = 1;
    rep(i, 1, n)
    {
        pw[i] = pw[i - 1] * Hash;                // 预处理次方数组，因为是自然溢出不用取模
        ha[i] = ha[i - 1] * Hash + s[i];         // 维护前缀哈希值
        hb[i] = hb[i - 1] * Hash + s[n - i + 1]; // 维护后缀哈希值
    }
    int mx = 0; // 记录最大答案
    rep(i, 1, n)
    {
        int l = 1, r = (n - i) / 2; // r从现有长度 / 2开始
        while (l <= r)
        {
            int mid = l + r >> 1;
            if (gethash(ha, 1, mid) == gethash(hb, i + 1, i + mid))
                // 判断长度为mid前后缀哈希值是否相等，其中后缀哈希数组对应的下标需要推一下
                l = mid + 1;
            else
                r = mid - 1;
        }
        mx = max(mx, r);
    }
    return mx;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    int l = 0, r = n - 1; // 第一步
    while (s[l] == s[r] && l <= r)
        l++, r--;
    if (l > r)
        cout << l; // 如果l>r说明本来就是一个回文串，不用删，l即为答案
    else
    {
        s = s.substr(l, r - l + 1);  // 取出删掉前后缀的字符串
        string t = s;                // 用另一个字符串做后缀
        reverse(t.begin(), t.end()); // 翻转
        cout << max(solve(s), solve(t)) + l;
    }
    return 0;
}