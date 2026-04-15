//
// Created by MINEC on 2026/1/8.
//
// 2026-01-08 寒假开始，新的刷算法的文件。

// VP Educational Codeforces Round 185 (Rated for Div. 2)
// 1. A
// #include <bits/stdc++.h>
// #define int long long
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n;
//         std::cin >> n;
//         if (n <= 2) {
//             if (n == 1) std::cout << 1 << std::endl;
//             else std::cout << 9 << std::endl;
//         } else {
//             int t = 3 * n * n - 3 + n * (n - 1) - 1;
//             t = std::max(t, 3 * n * (n - 1) - 3 + n * (n - 2) - 1 + n * n - 1);
//             std::cout << t << std::endl;
//         }
//     }
//     return 0;
// }

// 2. B
// #include <bits/stdc++.h>
// #define int long long
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n, sum = 0;
//         std::cin >> n;
//         std::vector<int> a(n + 1);
//         for (int i = 1; i <= n; i++) std::cin >> a[i], sum += a[i];
//         std::sort(a.begin() + 1, a.end());
//         int ans = n;
//         for (int i = 1; i <= n; i++) {
//             if (a[i] == 0) ans--;
//             else break;
//         }
//         ans = std::min(ans, sum - n + 1);
//         std::cout << ans << std::endl;
//     }
//     return 0;
// }

// 3. C
// #include <bits/stdc++.h>
// #define int long long
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n, k;
//         std::cin >> n >> k;
//         std::vector<int> a(n + 1), b(n + 1);
//         for (int i = 1; i <= n; i++) std::cin >> a[i];
//         for (int i = 1; i <= n; i++) std::cin >> b[i];
//         std::sort(a.begin() + 1, a.end());
//         std::sort(b.begin() + 1, b.end());
//         int up = n;
//         int ans = 0;
//         for (int i = 1; i <= n && up; i++) {
//             if (b[i] + (b[i] + 1) * a[up] <= k) {
//                 ans++;
//                 up--;
//             } else {
//                 up--;
//                 i--;
//             }
//         }
//         std::cout << ans << std::endl;
//     }
//     return 0;
// }

// 4. E
// #include <bits/stdc++.h>
// #define int long long
// constexpr int mod = 998244353;
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n, m;
//         std::cin >> n >> m;
//         std::vector<int> mx(n + 1);
//         while (m--) {
//             int l, r;
//             std::cin >> l >> r;
//             mx[r] = std::max(mx[r], l);
//         }
//         for (int i = 1; i <= n; i++) mx[i] = std::max(mx[i], mx[i - 1]);
//         std::vector<int> dp(n + 1), sum(n + 1);
//         dp[0] = 1, sum[0] = 1;
//         for (int i = 1; i <= n; i++) {
//             dp[i] = (dp[i] + sum[i - 1] - (mx[i] == 0 ? 0 : sum[mx[i] - 1])) % mod;
//             dp[i] = (dp[i] + mod) % mod;
//             sum[i] = (sum[i - 1] + dp[i]) % mod;
//         }
//         std::cout << dp[n] * 2 % mod << std::endl;
//     }
//     return 0;
// }

// 5. D
// #include <bits/stdc++.h>
// #define int long long
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n, q;
//         std::cin >> n >> q;
//         std::string s;
//         std::cin >> s;
//         int ans = 0, cnt1 = 0, cnt2 = 0, cnt = 0, len = 0;
//         for (const char c : s) cnt += (c == '?');
//         for (int i = 0; i < n; i++) {
//             if (s[i] == 'I') {
//                 ans += 1;
//                 if (i + 1 < n && s[i + 1] == '?' && i + 2 < n && (s[i + 2] == 'V' || s[i + 2] == 'X')) {
//                     ans -= 2;
//                     s[i + 1] = '-';
//                     ans += s[i + 2] == 'V' ? 5 : 10;
//                     i += 2;
//                 } else if (i + 1 < n && s[i + 1] == '?') {
//                     cnt1++;
//                     s[i + 1] = '-';
//                     i += 1;
//                 } else if (i + 1 < n && (s[i + 1] == 'V' || s[i + 1] == 'X')) {
//                     ans -= 2;
//                 }
//             } else if (s[i] == '?') {
//                 if (i + 1 < n && (s[i + 1] == 'V' || s[i + 1] == 'X')) {
//                     ans += s[i + 1] == 'V' ? 5 : 10;
//                     s[i] = '-';
//                     i += 1;
//                     cnt2++;
//                 }
//             } else if (s[i] == 'V') {
//                 ans += 5;
//             } else {
//                 ans += 10;
//             }
//         }
//         int t = 0;
//         for (int i = 0; i < n; i++) {
//             if (s[i] == '?') t++;
//             else {
//                 len += t / 2;
//                 t = 0;
//             }
//         }
//         len += t / 2;
//         while (q--) {
//             int X, V, I;
//             std::cin >> X >> V >> I;
//             int x = 0, v = 0, i = 0;
//             int out = ans;
//             if (I >= cnt) i = cnt;
//             else if (V >= cnt - I) {
//                 i = I;
//                 v = cnt - i;
//             } else {
//                 i = I;
//                 v = V;
//                 x = cnt - i - v;
//             }
//             out += i + 5 * v + 10 * x;
//             v += x;
//             out -= 2 * std::min(cnt1, v);
//             v -= std::min(cnt1, v);
//             out -= 2 * std::min(cnt2, i);
//             i -= std::min(cnt2, i);
//             out -= 2 * std::min({len, i, v});
//             std::cout << out << std::endl;
//         }
//     }
//     return 0;
// }

// 2026.1.10 VP Educational Codeforces Round 143 (Rated for Div. 2)
// 6. A
// #include <bits/stdc++.h>
// #define int long long
//
// void solve() {
//     int x, y;
//     std::cin >> x >> y;
//     std::string a, b;
//     std::cin >> a >> b;
//     a += std::string(b.rbegin(), b.rend());
//     int t = 1;
//     int cnt = 0;
//     for (int i = 1; i < a.size(); i++) {
//         if (a[i] == a[i - 1]) t++;
//         else {
//             t = 1;
//         }
//         if (t >= 3) {
//             std::cout << "NO" << std::endl;
//             return;
//         }
//         if (t >= 2) {
//             cnt++;
//         }
//     }
//     if (cnt >= 2) {
//         std::cout << "NO" << std::endl;
//     } else {
//         std::cout << "YES" << std::endl;
//     }
// }
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         solve();
//     }
//     return 0;
// }

// 7. B
// #include <bits/stdc++.h>
// #define int long long
//
// void solve() {
//     int n, k;
//     std::cin >> n >> k;
//     int L = -1, R = 51;
//     for (int i = 0; i < n; i++) {
//         int l, r;
//         std::cin >> l >> r;
//         if (l <= k && k <= r) {
//             L = std::max(L, l);
//             R = std::min(R, r);
//         }
//     }
//     if (L == R) std::cout << "YES" << std::endl;
//     else std::cout << "NO" << std::endl;
// }
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         solve();
//     }
//     return 0;
// }

// 8. C
// #include <bits/stdc++.h>
// #define int long long
//
// void solve() {
//     int n;
//     std::cin >> n;
//     std::vector<int> a(n + 1), b(n + 1);
//     for (int i = 1; i <= n; i++) std::cin >> a[i];
//     for (int i = 1; i <= n; i++) std::cin >> b[i];
//     std::vector<int> add(n + 2), cnt(n + 2), suma(n + 2), sumb(n + 2);
//     for (int i = 1; i <= n; i++) {
//         suma[i] = suma[i - 1] + a[i];
//         sumb[i] = sumb[i - 1] + b[i];
//     }
//     for (int i = 1; i <= n; i++) {
//         if (a[i] < b[i]) {
//             add[i] += a[i];
//         } else {
//             int l = i + 1, r = n;
//             while (l <= r) {
//                 int mid = (l + r) >> 1;
//                 if (sumb[mid] - sumb[i - 1] <= a[i]) l = mid + 1;
//                 else r = mid - 1;
//             }
//             cnt[i] += 1;
//             cnt[l] -= 1;
//             add[l] += a[i] - (sumb[l - 1] - sumb[i - 1]);
//         }
//     }
//     for (int i = 1; i <= n; i++) {
//         cnt[i] += cnt[i - 1];
//         std::cout << cnt[i] * b[i] + add[i] << " ";
//     }
//     std::cout << std::endl;
// }
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         solve();
//     }
//     return 0;
// }

// 9. D
// #include <bits/stdc++.h>
// #define int long long
//
// const int N = 3e5 + 10;
// const int mod = 998244353;
// int fact[N], infact[N];
//
// int ksm(int a, int k, int mod) {
//     int res = 1;
//     a %= mod;
//     while (k) {
//         if (k & 1) res = 1LL * res * a % mod;
//         a = 1LL * a * a % mod;
//         k >>= 1;
//     }
//     return res;
// }
//
// void init() {
//     infact[0] = fact[0] = 1;
//     for (int i = 1; i < N; i++) {
//         fact[i] = 1LL * fact[i - 1] * i % mod;
//         infact[i] = 1LL * infact[i - 1] * ksm(i, mod - 2, mod) % mod;
//     }
// }
// // 从 n 个里面选 m 个
// int C(int n, int m) {
//     return (1LL * fact[n] * infact[n - m] % mod) * infact[m] % mod;
// }
//
// void solve() {
//     int n;
//     std::cin >> n;
//     std::vector<int> a(n + 1);
//     int ans = 1;
//     for (int i = 1; i <= n; i++) std::cin >> a[i];
//     for (int i = 1; i <= n; ) {
//         std::set<int> s;
//         std::map<int, int> cnt;
//         for (int c = 0; c < 3; c++, i++) {
//             s.insert(a[i]);
//             cnt[a[i]]++;
//         }
//         if (s.size() == 2) {
//             if (cnt[*s.begin()] == 2) ans = 2 * ans % mod;
//         }
//         else if (s.size() == 1) ans = ans * 3 % mod;
//     }
//     ans = ans * C(n / 3, n / 6) % mod;
//     std::cout << ans << std::endl;
// }
//
// signed main() {
//     init();
//     int T = 1;
//     while (T--) {
//         solve();
//     }
//     return 0;
// }

// 10. https://www.luogu.com.cn/problem/CF2164D
// #include <bits/stdc++.h>
// #define int long long
//
// void solve() {
//     int n, k;
//     std::cin >> n >> k;
//     std::string s, t;
//     std::cin >> s >> t;
//     int i, j;
//     std::vector<int> up(n);
//     int mx = 0;
//     for (i = 0, j = 0; i < n; i++) {
//         while (j < n && s[i] == t[j] && i <= j) {
//             j++;
//         }
//     }
//     if (j != n) {
//         std::cout << -1 << std::endl;
//         return;
//     }
//
//     i = n - 1, j = n - 1;
//     for (; j >= 0; j--) {
//         while (i > j) i--;
//         while (i >= 0 && s[i] != t[j]) i--;
//         up[j] = i;
//         mx = std::max(mx, j - i);
//     }
//
//     if (mx > k) {
//         std::cout << -1 << std::endl;
//         return;
//     }
//     std::cout << mx << std::endl;
//     for (i = 0; i < mx; i++) {
//         std::unordered_map<int, int> vis;
//         for (j = n - 1; j >= 0; j--) {
//             if (j == up[j]) continue;
//             if (!vis[up[j]]) {
//                 s[up[j] + 1] = s[up[j]];
//                 vis[up[j]] = 1;
//                 up[j]++;
//             } else {
//                 up[j]++;
//             }
//         }
//         std::cout << s << std::endl;
//     }
//
// }
//
// signed main() {
//     std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
//     int T;
//     std::cin >> T;
//     while (T--) {
//         solve();
//     }
//     return 0;
// }

// 11. https://www.luogu.com.cn/problem/CF2164C
// #include <bits/stdc++.h>
// #define int long long
//
// void solve() {
//     int n, m;
//     std::cin >> n >> m;
//     std::vector<int> b(m + 1), c(m + 1);
//     std::multiset<int> s;
//     for (int i = 1, x; i <= n; i++) std::cin >> x, s.insert(x);
//     for (int i = 1; i <= m; i++) std::cin >> b[i];
//     for (int i = 1; i <= m; i++) std::cin >> c[i];
//     std::vector<int> d0, d1;
//     for (int i = 1; i <= m; i++) {
//         if (c[i] == 0) d0.emplace_back(i);
//         else d1.emplace_back(i);
//     }
//     int ans = 0;
//     std::sort(d1.begin(), d1.end(), [&](const int i, const int j) { return b[i] < b[j]; });
//     for (const int i : d1) {
//         int x = b[i];
//         if (auto t = s.lower_bound(x); t != s.end()) {
//             ans++;
//             int j = *t;
//             s.erase(t);
//             s.insert(std::max(c[i], j));
//         }
//     }
//     for (const int i : d0) {
//         int x = b[i];
//         if (auto t = s.lower_bound(x); t != s.end()) {
//             ans++;
//             s.erase(t);
//         }
//     }
//     std::cout << ans << std::endl;
// }
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         solve();
//     }
//     return 0;
// }

// 12. https://www.luogu.com.cn/problem/CF1661C
// #include <bits/stdc++.h>
// #define int long long
//
// void calc(int ji, int ou, int& ans) {
//     if (ji > ou) ans = std::min(ans, 2 * ou + 2 * (ji - ou - 1) + 1);
//     else if (ji == ou) ans = std::min(ans, 2 * ou);
//     else {
//         int x = ji, y = ou;
//         if ((x - y) % 3 == 0) {
//             int t = (y - x) / 3;
//             x += 2 * t;
//             ans = std::min(ans, 2 * x);
//         } else if ((x - y) % 3 == -1) {
//             int t = (y - x - 1) / 3;
//             x += 2 * t;
//             ans = std::min(ans, 2 * x + 2);
//         } else {
//             int t = (y - x + 1) / 3;
//             x += 2 * t;
//             ans = std::min(ans, 2 * x - 1);
//         }
//     }
// }
//
// void solve() {
//     int n;
//     std::cin >> n;
//     std::vector<int> a(n + 1);
//     int ji = 0, ou = 0, sum = 0, mx = -1;
//     for (int i = 1; i <= n; i++) {
//         std::cin >> a[i];
//         mx = std::max(mx, a[i]);
//     }
//     for (int i = 1; i <= n; i++) {
//         a[i] = mx - a[i];
//         ji += a[i] & 1;
//         sum += a[i];
//     }
//     ou = (sum - ji) / 2;
//     int ans = 9e18;
//     calc(ji, ou, ans);
//     ou = (sum + ji) / 2;
//     ji = n - ji;
//     calc(ji, ou, ans);
//     std::cout << ans << std::endl;
// }
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         solve();
//     }
//     return 0;
// }


// 13. https://www.luogu.com.cn/problem/CF1114C
// #include <bits/stdc++.h>
// #define int long long
//
// const int N = 2e6 + 10;
// int primes[N], vis[N], cnt;
//
// void euler() {
//     vis[1] = 1;
//     for (int i = 2; i < N; i++) {
//         if (!vis[i]) primes[cnt++] = i;
//         for (int j = 0; i * primes[j] < N; j++) {
//             vis[i * primes[j]] = 1;
//             if (i % primes[j] == 0) break;
//         }
//     }
// }
//
// signed main() {
//     euler();
//     int n, b;
//     std::cin >> n >> b;
//     std::unordered_map<int, int> mp;
//     for (int i = 0; i < cnt; i++) {
//         while (b % primes[i] == 0) {
//             b /= primes[i];
//             mp[primes[i]]++;
//         }
//     }
//     if (b > 1) mp[b]++;
//     int ans = 1e18;
//     for (const auto& [x, y] : mp) {
//         int res = 0, t = x;
//         while (n >= t) {
//             res += n / t;
//             if ((__int128)t * x > n) break;
//             t = t * x;
//         }
//         ans = std::min(ans, res / y);
//     }
//     std::cout << ans << std::endl;
//     return 0;
// }

// 14. https://www.luogu.com.cn/problem/CF1168A
// #include <bits/stdc++.h>
// #define int long long
//
// bool check(std::vector<int> a, int mid, int m) {
//     int n = a.size() - 1;
//     for (int i = 1; i <= n; i++) {
//         if (a[i] == a[i - 1]) continue;
//         if (a[i] > a[i - 1]) {
//             if ((a[i] + mid) % m >= a[i - 1] && a[i] + mid >= m) a[i] = a[i - 1];
//         } else {
//             if (a[i] + mid >= a[i - 1]) a[i] = a[i - 1];
//             else return false;
//         }
//     }
//     return true;
// }
//
// signed main() {
//     int n, m;
//     std::cin >> n >> m;
//     std::vector<int> a(n + 1);
//     for (int i = 1; i <= n; i++) std::cin >> a[i];
//     int l = 0, r = m - 1;
//     while (l <= r) {
//         int mid = (l + r) >> 1;
//         if (check(a, mid, m)) r = mid - 1;
//         else l = mid + 1;
//     }
//     std::cout << r + 1 << std::endl;
//     return 0;
// }

// 15. https://www.luogu.com.cn/problem/CF1307D
// #include <bits/stdc++.h>
// constexpr int N = 2e5 + 10;
//
// int d1[N], d2[N];
// std::vector<int> g[N];
// int mp[N];
//
// void bfs(int start, int dis[]) {
//     std::unordered_map<int, int> vis;
//     std::queue<int> q;
//     q.push(start);
//     vis[start] = 1;
//     while (!q.empty()) {
//         int u = q.front();
//         q.pop();
//         for (int v : g[u]) {
//             if (!vis[v]) {
//                 dis[v] = dis[u] + 1;
//                 vis[v] = 1;
//                 q.push(v);
//             }
//         }
//     }
// }
//
// signed main() {
//     int n, m, k;
//     std::cin >> n >> m >> k;
//     std::vector<int> a(k);
//     for (int i = 0; i < k; i++) std::cin >> a[i], mp[a[i]] = 1;
//     for (int i = 0, x, y; i < m; i++) {
//         std::cin >> x >> y;
//         g[x].emplace_back(y);
//         g[y].emplace_back(x);
//     }
//     bfs(1, d1);
//     bfs(n, d2);
//     int ans = 0;
//     std::multiset<int> s;
//     for (int i = 0; i < k; i++) s.insert(d2[a[i]]);
//     std::queue<int> q;
//     q.push(1);
//     std::unordered_map<int, int> vis;
//     vis[1] = 1;
//     while (!q.empty()) {
//         int u = q.front();
//         q.pop();
//         if (mp[u]) {
//             s.erase(s.find(d2[u]));
//             if (s.size()) ans = std::max(ans, d1[u] + *s.rbegin() + 1);
//         }
//         for (int v : g[u]) {
//             if (!vis[v]) {
//                 vis[v] = 1;
//                 q.push(v);
//             }
//         }
//     }
//     std::cout << std::min(ans, d1[n]) << std::endl;
//     return 0;
// }

// 16. https://www.luogu.com.cn/problem/P1378
// #include <bits/stdc++.h>
// #define int long long
// #define double long double
// constexpr int N = 10;
// const double pi = acosl(-1);
//
// double n, l, r, down, up;
// double ans;
// std::pair<std::pair<double, double>, double> a[N];
// int vis[N];
//
// double dis(int i, int j) {
//     double x = a[i].first.first, y = a[i].first.second;
//     double x1 = a[j].first.first, y1 = a[j].first.second;
//     return sqrtl((x - x1) * (x - x1) + (y - y1) * (y - y1));
// }
//
// void dfs(const int s) {
//     if (s == n) {
//         double x = 0;
//         for (int i = 0; i < n; i++) x += pi * a[i].second * a[i].second;
//         ans = std::max(ans, x);
//         return;
//     }
//     for (int i = 0; i < n; i++) {
//         if (!vis[i]) {
//             double mxr = std::min({a[i].first.first - l, r - a[i].first.first, a[i].first.second - down, up - a[i].first.second});
//             for (int j = 0; j < n; j++) {
//                 if (vis[j]) {
//                     mxr = std::min(mxr, std::max(dis(i, j) - a[j].second, 0.0L));
//                 }
//             }
//             a[i].second = mxr;
//             vis[i] = 1;
//             dfs(s + 1);
//             vis[i] = 0;
//         }
//     }
// }
//
// signed main() {
//     std::cin >> n;
//     double x, y, x1, y1;
//     std::cin >> x >> y >> x1 >> y1;
//     l = std::min(x, x1), r = std::max(x, x1);
//     down = std::min(y, y1), up = std::max(y, y1);
//     for (int i = 0; i < n; i++) std::cin >> a[i].first.first >> a[i].first.second;
//     dfs(0);
//     ans = (r - l) * (up - down) - ans;
//     printf("%.0Lf", ans);
//     return 0;
// }

// 17. https://www.luogu.com.cn/problem/P1363
// #include <bits/stdc++.h>
// constexpr int N = 1510;
//
// int n, m, sx, sy;
// char a[N][N];
// bool vis[N][N], yes;
// std::pair<int, int> pos[N][N];
//
// int dx[] = {1, -1, 0, 0};
// int dy[] = {0, 0, -1, 1};
//
// void dfs(int x, int y, int px, int py) {
//     if (yes) return;
//     vis[x][y] = true, pos[x][y] = {px, py};
//     for (int i = 0; i < 4; i++) {
//         int nx = (x + dx[i] + n) % n;
//         int ny = (y + dy[i] + m) % m;
//         int npx = px + dx[i];
//         int npy = py + dy[i];
//         if (a[nx][ny] == '.' || a[nx][ny] == 'S') {
//             if (!vis[nx][ny]) {
//                 dfs(nx, ny, npx, npy);
//             } else {
//                 if (pos[nx][ny].first != npx || pos[nx][ny].second != npy) {
//                     yes = true;
//                     return;
//                 }
//             }
//         }
//     }
// }
//
// signed main() {
//     while (std::cin >> n >> m) {
//         yes = false;
//         memset(vis, 0, sizeof(vis));
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 std::cin >> a[i][j];
//                 if (a[i][j] == 'S') {
//                     sx = i;
//                     sy = j;
//                 }
//             }
//         }
//         dfs(sx, sy, sx, sy);
//         if (yes) std::cout << "Yes" << std::endl;
//         else std::cout << "No" << std::endl;
//     }
//     return 0;
// }

// 18. https://www.luogu.com.cn/problem/P4155
// #include <bits/stdc++.h>
//
// struct node {
//     int l, r, id;
// };
//
// signed main() {
//     int n, m;
//     std::cin >> n >> m;
//     std::vector<node> a(2 * n + 1);
//     for (int i = 1; i <= n; i++) {
//         std::cin >> a[i].l >> a[i].r;
//         if (a[i].r < a[i].l) a[i].r += m;
//         a[i].id = i;
//     }
//     for (int i = 1; i <= n; i++) {
//         a[i + n].l = a[i].l + m;
//         a[i + n].r = a[i].r + m;
//     }
//     std::sort(a.begin() + 1, a.end(), [](const node x, const node y) {
//         return x.l < y.l;
//     });
//     std::vector b(2 * n + 1, std::vector<int>(20));
//     for (int i = 1, p = 1; i <= 2 * n; i++) {
//         while (p <= 2 * n && a[p].l <= a[i].r) p++;
//         b[i][0] = p - 1;
//     }
//     for (int i = 1; i < 20; i++) {
//         for (int j = 1; j <= 2 * n; j++) {
//             b[j][i] = b[b[j][i - 1]][i - 1];
//         }
//     }
//     std::vector<int> ans(n + 1);
//     for (int i = 1; i <= n; i++) {
//         int t = 1, lim = a[i].l + m, x = i;
//         for (int j = 19; j >= 0; j--) {
//             if (a[b[x][j]].r < lim) {
//                 t += 1 << j;
//                 x = b[x][j];
//             }
//         }
//         ans[a[i].id] = t + 1;
//     }
//     for (int i = 1; i <= n; i++) std::cout << ans[i] << ' ';
//     return 0;
// }

// 19. https://www.luogu.com.cn/problem/P1896
// #include <bits/stdc++.h>
// #define int long long
//
// signed main() {
//     int n, k;
//     std::cin >> n >> k;
//     std::vector<int> he, cnt1;
//     for (int i = 0; i < 1 << n; i++) {
//         if ((i & (i << 1)) == 0 && (i & (i >> 1)) == 0) {
//             he.emplace_back(i);
//             int c = 0, t = i;
//             while (t) {
//                 c++;
//                 t -= t & -t;
//             }
//             cnt1.emplace_back(c);
//         }
//     }
//     std::vector dp(n, std::vector(he.size(), std::vector<int>(n * n + 1)));
//     for (unsigned i = 0; i < he.size(); i++) {
//         dp[0][i][cnt1[i]] = 1;
//     }
//     for (int i = 1; i < n; i++) {
//         for (int j = 0; j < he.size(); j++) {
//             for (int o = 0; o < n * n; o++) {
//                 if (dp[i - 1][j][o]) {
//                     for (int z = 0; z < he.size(); z++) {
//                         if ((he[j] & he[z]) == 0 && (he[j] & he[z] << 1) == 0 && (he[j] & he[z] >> 1) == 0) {
//                             dp[i][z][o + cnt1[z]] += dp[i - 1][j][o];
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     int ans = 0;
//     for (int i = 0; i < he.size(); i++) {
//         ans += dp[n - 1][i][k];
//     }
//     std::cout << ans << std::endl;
//     return 0;
// }

// 20. https://codeforces.com/contest/2185/problem/E
// #include <bits/stdc++.h>
// #define int long long
// using namespace std;
//
// const int mod = 1e9+7;
// template<typename T> T pred(T a, T b) { return (a + b) % mod; }
// template<typename T, T (*Pred)(T, T) = pred<T>, T Init = 0>
// struct BIT {
//     size_t n;
//     vector<T> data;
//     BIT(size_t n): BIT(vector<T>(n + 1, Init)) {}
//     BIT(const vector<T> &v): n(v.size() - 1), data(v) {
//         for (size_t i = 1; i <= n; i ++) {
//             size_t j = i + (i & -i);
//             if (j <= n) data[j] = Pred(data[j], data[i]);
//         }
//     }
//     void update(size_t i, T v = 1) {
//         i ++;
//         for (; i <= n; i += i & -i) {
//             data[i] = Pred(data[i], v);
//         }
//     }
//     T query(size_t i) {
//         i ++;
//         T res = Init;
//         for (; i; i -= i & -i) {
//             res = Pred(res, data[i]);
//         }
//         return res;
//     }
//     T query(size_t l, size_t r) {
//         return query(r) - query(l - 1);
//     }
// };
//
// struct node {
//     int l, r, id;
// };
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n, m, k;
//         std::cin >> n >> m >> k;
//         std::vector<int> a(n + 1), b(m + 2);
//         for (int i = 1; i <= n; i++) std::cin >> a[i];
//         for (int i = 1; i <= m; i++) std::cin >> b[i];
//         b[0] = -1e17, b[m + 1] = 1e17;
//         std::sort(b.begin(), b.end());
//         std::vector<node> L, R(n + 1);
//         for (int i = 1; i <= n; i++) {
//             auto it = lower_bound(b.begin(), b.end(), a[i]);
//             R[i] = {a[i] - *(it - 1), *it - a[i], i};
//         }
//         std::sort(R.begin() + 1, R.end(), [](const node& x, const node& y) {
//            return x.r < y.r;
//         });
//         unordered_map<int, int> pos;
//         for (int i = 1; i <= n; i++) pos[R[i].id] = i;
//         L = R;
//         std::sort(L.begin() + 1, L.end(), [](const node& x, const node& y) {
//             return x.l < y.l;
//         });
//         string s;
//         std::cin >> s;
//         BIT<int> bit(n + 1);
//         int mil = 0, mxr = 0, p = 0, l = 1, r = 1;
//         for (int i = 0; i < s.size(); i++) {
//             if (s[i] == 'L') p -= 1;
//             else p += 1;
//             mil = std::min(mil, p);
//             mxr = std::max(mxr, p);
//             while (l <= n && L[l].l <= -mil) {
//                 bit.update(pos[L[l].id]);
//                 l++;
//             }
//             while (r <= n && R[r].r <= mxr) r++;
//             std::cout << n - (r + l - 2 - bit.query(r - 1)) << ' ';
//         }
//         std::cout << endl;
//     }
//     return 0;
// }

// 21. https://codeforces.com/contest/2185/problem/F
// #include <bits/stdc++.h>
//
// int main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n, q;
//         std::cin >> n >> q;
//         std::vector<int> a((1 << n) + 1);
//         for (int i = 1; i <= 1 << n; i++) std::cin >> a[i];
//         std::vector<int> b = a;
//         for (int i = 1; i < b.size(); i++) b[i] ^= b[i - 1];
//         auto get = [&](const int l, const int r, const int id, const int c) -> int {
//             int res = b[r] ^ b[l - 1];
//             if (l <= id && id <= r) res ^= a[id] ^ c;
//             return res;
//         };
//         while (q--) {
//             int id, c;
//             std::cin >> id >> c;
//             int l = 1, r = 1 << n;
//             int ans = 0;
//             while (l < r) {
//                 int mid = (l + r) >> 1;
//                 int zuo = get(l, mid, id, c);
//                 int you = get(mid + 1, r, id, c);
//                 if (id <= mid) {
//                     if (zuo >= you) ans += mid - l + 1;
//                     r = mid;
//                 } else {
//                     if (you > zuo) ans += mid - l + 1;
//                     l = mid + 1;
//                 }
//             }
//             std::cout << (1 << n) - ans - 1 << std::endl;
//         }
//     }
//     return 0;
// }

// 22. https://codeforces.com/contest/2185/problem/G
// #include <bits/stdc++.h>
// #define int long long
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n;
//         std::cin >> n;
//         std::vector a(n, std::vector<int>());
//         std::vector mp(n, std::unordered_map<int, int>());
//         std::vector<int> mex(n), p(n, 1);
//         for (int i = 0; i < n; i++) {
//             int l;
//             std::cin >> l;
//             a[i].resize(l);
//             for (int j = 0; j < l; j++) std::cin >> a[i][j], mp[i][a[i][j]]++;
//         }
//         for (int i = 0; i < n; i++) {
//             while (mp[i][mex[i]]) mex[i]++;
//         }
//         for (int i = 0; i < n; i++) {
//             while (mp[i][mex[i] + p[i]]) p[i]++;
//         }
//         int mex_sum = 0;
//         std::unordered_map<int, int> mex_cnt;
//         for (int i = 0; i < n; i++) mex_cnt[mex[i]] += p[i], mex_sum += mex[i];
//         int ans = 0;
//         for (int i = 0; i < n; i++) {
//             for (int j : a[i]) {
//                 if (j > mex[i] || mp[i][j] > 1) {
//                     ans += mex_sum * (n - 1) + mex_cnt[j];
//                 } else {
//                     ans += (mex_sum - mex[i] + j) * (n - 1) + mex_cnt[j];
//                 }
//             }
//         }
//         std::cout << ans << std::endl;
//     }
//     return 0;
// }

// 23. https://www.luogu.com.cn/problem/CF2181M
// #include <bits/stdc++.h>
//
// void solve() {
//     std::string a, b;
//     std::cin >> a >> b;
//     std::vector<int> a_(a.size()), b_(b.size());
//     for (int i = 0; i < a.size(); i++) b_[i] = b[i] - '0';
//     a_[0] = a[0] - '0';
//     for (int i = 1; i < a.size(); i++) a_[i] = (a_[i - 1] + a[i] - '0') % 2;
//     std::vector<int> c;
//     int i = 0;
//     while (i < a.size() && a_[i] == b_[i]) i++;
//     while (i < a.size()) {
//         int cnt = 0;
//         if (c.size() & 1) {
//             while (i < a.size() && a_[i] == b_[i]) cnt++, i++;
//         } else {
//             while (i < a.size() && a_[i] != b_[i]) cnt++, i++;
//         }
//         c.push_back(cnt);
//     }
//     int ans = 0;
//     for (i = 0; i < c.size(); i++) {
//         if (c[i] == 1) ans++, i++;
//         else ans++;
//     }
//     std::cout << ans << std::endl;
// }
//
// int main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         solve();
//     }
//     return 0;
// }

// 24. https://www.luogu.com.cn/problem/CF2181F
// #include <bits/stdc++.h>
//
// int main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n;
//         std::cin >> n;
//         std::vector<int> a(n);
//         int cnt0 = 0, cnt1 = 0;
//         for (int i = 0; i < n; i++) {
//             std::cin >> a[i];
//             if (a[i] == 1) cnt1++;
//             else cnt0++;
//         }
//         if (cnt1 == 0) {
//             std::cout << "Alice" << std::endl;
//         } else {
//             if (cnt0 == 0) {
//                 if (cnt1 & 1) std::cout << "Alice" << std::endl;
//                 else std::cout << "Bob" << std::endl;
//             } else {
//                 if (cnt1 & 1) std::cout << "Bob" << std::endl;
//                 else std::cout << "Alice" << std::endl;
//             }
//         }
//     }
//     return 0;
// }

// 25. https://codeforces.com/contest/2181/problem/B
// #include <bits/stdc++.h>
//
// void solve() {
//     int n, m;
//     std::cin >> n >> m;
//     std::multiset<int> a, b;
//     for (int i = 0, x; i < n; i++) std::cin >> x, a.insert(x);
//     for (int i = 0, x; i < m; i++) std::cin >> x, b.insert(x);
//     int x = 1;
//     while (!a.empty() && !b.empty()) {
//         if (x) {
//             auto ita = a.rbegin();
//             auto itb = b.rbegin();
//             if (*ita >= *itb) b.erase(--b.rbegin().base());
//             else {
//                 b.insert(*itb - *ita);
//                 b.erase(--b.rbegin().base());
//             }
//         } else {
//             auto ita = a.rbegin();
//             auto itb = b.rbegin();
//             if (*itb >= *ita) a.erase(--a.rbegin().base());
//             else {
//                 a.insert(*ita - *itb);
//                 a.erase(--a.rbegin().base());
//             }
//         }
//         x ^= 1;
//     }
//     if (a.empty()) std::cout << "Bob" << std::endl;
//     else std::cout << "Alice" << std::endl;
// }
//
// int main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         solve();
//     }
//     return 0;
// }

// 26. https://codeforces.com/contest/2189/problem/C1
// #include <bits/stdc++.h>
//
// int main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n;
//         std::cin >> n;
//         std::vector<int> a(n + 1), ans(n + 1);
//         ans[n] = 1;
//         a[1] = 1;
//         for (int i = 2; i < n; i++) {
//             ans[i] = i ^ 1;
//             a[ans[i]] = 1;
//         }
//         for (int i = 1; i <= n; i++) {
//             if (!a[i]) {
//                 ans[1] = i;
//                 break;
//             }
//         }
//         for (int i = 1; i <= n; i++) std::cout << ans[i] << " \n"[i == n];
//     }
//     return 0;
// }

// 26. https://codeforces.com/contest/2189/problem/C2
// #include <bits/stdc++.h>
//
// int main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n;
//         std::cin >> n;
//         std::vector<int> a(n + 1), ans(n + 1);
//         ans[n] = 1;
//         a[1] = 1;
//         for (int i = 2; i < n; i++) {
//             ans[i] = i ^ 1;
//             a[ans[i]] = 1;
//         }
//         for (int i = 1; i <= n; i++) {
//             if (!a[i]) {
//                 ans[1] = i;
//                 break;
//             }
//         }
//         if ((ans[1] ^ 1) <= n) {
//             for (int i = 1; i <= n; i++) std::cout << ans[i] << " \n"[i == n];
//         } else {
//             if ((ans[1] & (ans[1] - 1)) == 0) std::cout << -1 << std::endl;
//             else {
//                 int x = ans[1] & -ans[1];
//                 std::swap(ans[1], ans[x]);
//                 for (int i = 1; i <= n; i++) std::cout << ans[i] << " \n"[i == n];
//             }
//         }
//     }
//     return 0;
// }

// 27. https://www.luogu.com.cn/problem/CF2180C
// #include <bits/stdc++.h>
//
// int main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n, k;
//         std::cin >> n >> k;
//         if (k & 1) {
//             for (int i = 1; i <= k; i++) std::cout << n << " \n"[i == k];
//             continue;
//         }
//         std::vector<int> a(k + 1);
//         int cnt = 0;
//         for (int i = 30; i >= 0; i--) {
//             if (n >> i & 1) {
//                 cnt++;
//                 if (cnt <= k) {
//                     for (int j = 1; j <= k; j++) {
//                         if (j == cnt) continue;
//                         a[j] |= 1 << i;
//                     }
//                 } else {
//                     for (int j = 2; j <= k; j++) {
//                         a[j] |= 1 << i;
//                     }
//                 }
//             } else {
//                 if (cnt <= k) {
//                     for (int j = 1; j <= cnt / 2 * 2; j++) {
//                         a[j] |= 1 << i;
//                     }
//                 } else {
//                     for (int j = 1; j <= k / 2 * 2; j++) {
//                         a[j] |= 1 << i;
//                     }
//                 }
//             }
//         }
//         for (int i = 1; i <= k; i++) std::cout << a[i] << " \n"[i == k];
//     }
//     return 0;
// }

// 28. https://www.luogu.com.cn/problem/CF2175B
// #include <bits/stdc++.h>
//
// int main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n, l, r;
//         std::cin >> n >> l >> r;
//         std::vector<int> a(n + 1), x(n + 1);
//         std::unordered_map<int, int> mp;
//         mp[0] = 1;
//         int t = 1;
//         for (int i = 1; i < r; i++) {
//             while (mp[t ^ x[i - 1]]) t++;
//             a[i] = t;
//             x[i] = x[i - 1] ^ a[i];
//             mp[x[i]] = 1;
//         }
//         a[r] = x[l - 1] ^ x[r - 1];
//         x[r] = x[r - 1] ^ a[r];
//         for (int i = r + 1; i <= n; i++) {
//             while (mp[t ^ x[i - 1]]) t++;
//             a[i] = t;
//             x[i] = x[i - 1] ^ a[i];
//             mp[x[i]] = 1;
//         }
//         for (int i = 1; i <= n; i++) std::cout << a[i] << " \n"[i == n];
//     }
//     return 0;
// }

// 29. https://ac.nowcoder.com/acm/contest/127240/D
// #include <bits/stdc++.h>
//
// int main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n;
//         std::cin >> n;
//         std::vector<std::vector<int>> g(n + 1);
//         for (int i = 1; i < n; i++) {
//             int u, v;
//             std::cin >> u >> v;
//             g[u].emplace_back(v);
//             g[v].emplace_back(u);
//         }
//         std::vector<int> fa(n + 1), cnt(n + 1);
//         int ans = 0;
//         auto dfs = [&](auto&& self, int u, int f) -> void {
//             fa[u] = f;
//             for (int v : g[u]) {
//                 if (v == f) continue;
//                 self(self, v, u);
//                 cnt[u] += cnt[v];
//             }
//             cnt[u]++;
//             int x = (n - cnt[u]) & 1 | f == 0;
//             for (int v : g[u]) {
//                 if (v == f) continue;
//                 x &= cnt[v] & 1;
//             }
//             ans += x;
//         };
//         dfs(dfs, 1, 0);
//         std::cout << ans << std::endl;
//     }
//     return 0;
// }

// 2026.2.1 vp Codeforces Round 1076 (Div. 3)
// 30. A
// #include <bits/stdc++.h>
//
// int main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n, s, x;
//         std::cin >> n >> s >> x;
//         int sum = 0;
//         for (int i = 0, y; i < n; i++) std::cin >> y, sum += y;
//         int t = s - sum;
//         if (t < 0) std::cout << "No" << std::endl;
//         else {
//             if (t % x == 0) std::cout << "Yes" << std::endl;
//             else std::cout << "No" << std::endl;
//         }
//     }
//     return 0;
// }

// 31. B
// #include <bits/stdc++.h>
//
// int main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n;
//         std::cin >> n;
//         std::vector<int> a(n + 1);
//         for (int i = 1; i <= n; i++) std::cin >> a[i];
//         int r = 1, l = 1;
//         int mx = n;
//         while (l <= n && a[l] == mx) l++, mx--;
//         while (r <= n && a[r] != mx) r++;
//         if (l > n || r > n) {
//             for (int i = 1; i <= n; i++) std::cout << a[i] << " \n"[i == n];
//             continue;
//         }
//         for (; l < r; l++, r--) std::swap(a[l], a[r]);
//         for (int i = 1; i <= n; i++) std::cout << a[i] << " \n"[i == n];
//     }
//     return 0;
// }

// 32. C
// #include <bits/stdc++.h>
//
// int main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n, q;
//         std::cin >> n >> q;
//         std::vector<int> a(n + 1), b(n + 1);
//         for (int i = 1; i <= n; i++) std::cin >> a[i];
//         for (int i = 1; i <= n; i++) std::cin >> b[i];
//         std::vector<int> c(n + 1);
//         c[n] = std::max(a[n], b[n]);
//         for (int i = n - 1; i >= 1; i--) {
//             c[i] = std::max({c[i + 1], a[i], b[i]});
//         }
//         for (int i = 1; i <= n; i++) c[i] += c[i - 1];
//         while (q--) {
//             int l, r;
//             std::cin >> l >> r;
//             std::cout << c[r] - c[l - 1] << " \n"[q == 0];
//         }
//     }
//     return 0;
// }

// 33. D
// #include <bits/stdc++.h>
// #define int long long
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n;
//         std::cin >> n;
//         std::vector<int> a(n + 1), b(n + 1);
//         for (int i = 1; i <= n; i++) std::cin >> a[i];
//         for (int i = 1; i <= n; i++) std::cin >> b[i];
//         int ans = 0;
//         std::sort(a.begin() + 1, a.end());
//         for (int i = 1; i <= n; i++) b[i] += b[i - 1];
//         auto calc = [&](int mid) -> int {
//             int cnt = a.end() - std::lower_bound(a.begin() + 1, a.end(), mid);
//             int y = std::upper_bound(b.begin(), b.end(), cnt) - b.begin() - 1;
//             return y * mid;
//         };
//         for (int i = 1; i <= n; i++) ans = std::max(ans, calc(a[i]));
//         std::cout << ans << std::endl;
//     }
//     return 0;
// }

// 34. E
// #include <bits/stdc++.h>
// #define int long long
// constexpr int N = 3e5 + 1;
// constexpr int inf = 1e12;
//
// signed main() {
//     int T;
//     std::cin >> T;
//     std::vector<std::vector<int>> fac(N);
//     for (int i = 1; i < N; i++)
//         for (int j = i; j < N; j += i)
//             fac[j].emplace_back(i);
//     while (T--) {
//         int n;
//         std::cin >> n;
//         std::vector<int> a(n + 1), dp(n + 1, inf);
//         for (int i = 1; i <= n; i++) std::cin >> a[i], dp[a[i]] = 1;
//         for (int i = 1; i <= n; i++) {
//             for (int j : fac[i]) {
//                 dp[i] = std::min(dp[i], dp[j] + dp[i / j]);
//             }
//             if (dp[i] >= inf) std::cout << -1 << " \n"[i == n];
//             else std::cout << dp[i] << " \n"[i == n];
//         }
//     }
//     return 0;
// }

// 35. F
// #include <bits/stdc++.h>
// #define int long long
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n, ax, ay, bx, by;
//         std::cin >> n >> ax >> ay >> bx >> by;
//         std::vector<int> x(n + 1), y(n + 1);
//         for (int i = 1; i <= n; i++) std::cin >> x[i];
//         for (int i = 1; i <= n; i++) std::cin >> y[i];
//         std::map<int, std::pair<int, int>> mp;
//         for (int i = 1; i <= n; i++) {
//             if (mp.find(x[i]) == mp.end()) {
//                 mp[x[i]] = {y[i], y[i]};
//             } else {
//                 mp[x[i]].first = std::min(mp[x[i]].first, y[i]);
//                 mp[x[i]].second = std::max(mp[x[i]].second, y[i]);
//             }
//         }
//         mp[bx] = {by, by};
//         std::vector dp(mp.size() + 3, std::vector<int>(2, 1e15));
//         dp[0][0] = 0, dp[0][1] = 0;
//         int cnt = 1;
//         int y_[2] = {ay, ay};
//         auto calc = [](int _y, int _y0, int _y1, int op) -> int {
//             int len = _y1 - _y0;
//             if (op == 0) {
//                 if (_y < _y0) return _y1 - _y + len;
//                 return std::abs(_y1 - _y) + len;
//             }
//             if (_y < _y1) return std::abs(_y0 - _y) + len;
//             return len + _y - _y0;
//         };
//         for (const auto& [a, b] : mp) {
//             for (int i = 0; i < 2; i++) {
//                 int dy = y_[i];
//                 for (int j = 0; j < 2; j++) {
//                     dp[cnt][j] = std::min(dp[cnt][j], dp[cnt - 1][i] + calc(dy, b.first, b.second, j));
//                 }
//             }
//             y_[0] = b.first, y_[1] = b.second;
//             cnt++;
//         }
//         cnt--;
//         std::cout << dp[cnt][0] + bx - ax << std::endl;
//     }
//     return 0;
// }

// 36. https://codeforces.com/contest/2188/problem/C
// #include <bits/stdc++.h>
//
// int main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n;
//         std::cin >> n;
//         std::vector<int> a(n);
//         for (int i = 0; i < n; i++) std::cin >> a[i];
//         if (std::is_sorted(a.begin(), a.end())) {
//             std::cout << -1 << std::endl;
//             continue;
//         }
//         std::vector b = a;
//         std::sort(b.begin(), b.end());
//         int ans = 2e9;
//         for (int i = 0; i < n; i++) {
//             if (a[i] != b[i]) {
//                 ans = std::min(ans, std::max(a[i] - b.front(), b.back() - a[i]));
//             }
//         }
//         std::cout << ans << std::endl;
//     }
//     return 0;
// }

// 37. https://www.luogu.com.cn/problem/CF2180D
// #include <bits/stdc++.h>
//
// signed main() {
//     std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n;
//         std::cin >> n;
//         std::vector<int> a(n + 1);
//         for (int i = 1; i <= n; i++) std::cin >> a[i];
//         double l = 0.0001, r = 1e18;
//         int ans = 0;
//         for (int i = 2; i <= n; i++) {
//             if (const int d = a[i] - a[i - 1]; d > r) {
//                 const double t = l;
//                 l = d - r;
//                 r = d - t;
//                 ans++;
//             } else if (d > l) {
//                 r = d - 0.0001;
//                 i--;
//             } else {
//                 l = 0.0001;
//                 r = d - l;
//             }
//         }
//         std::cout << ans << std::endl;
//     }
//     return 0;
// }

// 2026.2.6 VP Codeforces Round 1073 (Div. 2)
// 38. A
// #include <bits/stdc++.h>
//
// void solve() {
//     int n;
//     std::cin >> n;
//     std::vector<int> a(n + 1);
//     for (int i = 1; i <= n; i++) std::cin >> a[i];
//     std::unordered_map<int, int> mp;
//     for (int i = 1; i <= n; i++) mp[a[i]] = i & 1;
//     std::sort(a.begin() + 1, a.end());
//     for (int i = 2; i <= n; i++) {
//         if (mp[a[i]] == mp[a[i - 1]]) {
//             std::cout << "NO" << std::endl;
//             return;
//         }
//     }
//     std::cout << "YES" << std::endl;
// }
//
// int main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         solve();
//     }
//     return 0;
// }

// 39. B
// #include <bits/stdc++.h>
//
// void solve() {
//     int n;
//     std::cin >> n;
//     std::vector<int> a(n + 1);
//     for (int i = 1; i <= n; i++) std::cin >> a[i];
//     std::sort(a.begin() + 1, a.end(), std::greater<int>());
//     std::vector<int> pre(n + 1), ed(n + 1);
//     std::unordered_map<int, int> mp;
//     int t = 0;
//     for (int i = 1; i <= n; i++) {
//         mp[a[i]] = 1;
//         while (mp[t]) t++;
//         pre[i] = t;
//     }
//     t = 0;
//     mp.clear();
//     for (int i = n; i >= 1; i--) {
//         mp[a[i]] = 1;
//         while (mp[t]) t++;
//         ed[i] = t;
//     }
//     for (int i = 1; i < n; i++) {
//         if (pre[i] == ed[i + 1]) {
//             std::cout << "NO" << std::endl;
//             return;
//         }
//     }
//     std::cout << "YES" << std::endl;
// }
//
// int main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         solve();
//     }
//     return 0;
// }

// 40. C
// #include <bits/stdc++.h>
//
// void solve() {
//     int n;
//     std::cin >> n;
//     std::string s;
//     std::cin >> s;
//     if (std::is_sorted(s.begin(), s.end())) {
//         std::cout << "Bob" << std::endl;
//         return;
//     }
//     std::cout << "Alice" << std::endl;
//     std::vector<int> ans;
//     s = '0' + s + '1';
//     int l = 0, r = s.size() - 1;
//     while (s[l] == '0') l++;
//     while (s[r] == '1') r--;
//     while (l < r) {
//         ans.emplace_back(l);
//         ans.emplace_back(r);
//         l++, r--;
//         while (s[l] == '0') l++;
//         while (s[r] == '1') r--;
//     }
//     std::sort(ans.begin(), ans.end());
//     std::cout << ans.size() << std::endl;
//     for (int i = 0; i < ans.size(); i++) {
//         std::cout << ans[i] << " \n"[i == ans.size() - 1];
//     }
// }
//
// int main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         solve();
//     }
//     return 0;
// }

// 41. D
// #include <bits/stdc++.h>
//
// void solve() {
//     int n;
//     std::cin >> n;
//     std::string s;
//     std::cin >> s;
//     int l = 0;
//     while (s[l] != ')') l++;
//     int l1 = l;
//     int cnt = l + 1;
//     while (s[l] == ')') l++;
//     int cnt2 = l - l1 - 1;
//     int x = 0, y = cnt;
//     int ans = cnt;
//     for (int i = l + 1; i < s.size(); i++) {
//         if (s[i] == '(') x++;
//         else {
//             if (y) {
//                 y--;
//                 ans++;
//             } else if (x) {
//                 x--;
//                 ans += 2;
//             }
//         }
//     }
//     while (cnt2 && y) {
//         cnt2--;
//         y--;
//         ans++;
//     }
//     while (cnt2 && x) {
//         x--;
//         cnt2--;
//         ans += 2;
//     }
//     if (!y) std::cout << ans << std::endl;
//     else std::cout << -1 << std::endl;
// }
//
// int main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         solve();
//     }
//     return 0;
// }

// 42. https://www.luogu.com.cn/problem/P2638
// #include <bits/stdc++.h>
// #define int __int128
//
// int vis[51][51][51], n, a, b;
//
// std::ostream& operator<<(std::ostream& os, __int128 n) {
//     if (n == 0) return os << 0;
//     if (n < 0) return os << '-' << -n;
//     std::string s;
//     while (n > 0) {
//         s += char('0' + n % 10);
//         n /= 10;
//     }
//     std::reverse(s.begin(), s.end());
//     return os << s;
// }
//
// std::istream& operator>>(std::istream& is, __int128& x) {
//     char c;
//     while(c = is.get(), c != '-' && !isdigit(c)) {}
//     if(c == '-') {
//         x = '0' - is.get();
//         while(isdigit(c = is.get())) x = x * 10 + '0' - c;
//     } else {
//         x = c - '0';
//         while(isdigit(c = is.get())) x = x * 10 - '0' + c;
//     }
//     return is;
// }
//
// int dfs(const int deep, const int _a, const int _b) {
//     if (deep == n) return 1;
//     if (vis[deep][_a][_b]) return vis[deep][_a][_b];
//     int res = 0;
//     for (int i = 0; i <= _a; i++) {
//         for (int j = 0; j <= _b; j++) {
//             res += dfs(deep + 1, _a - i, _b - j);
//         }
//     }
//     vis[deep][_a][_b] = res;
//     return res;
// }
//
// signed main() {
//     std::cin >> n >> a >> b;
//     std::cout << dfs(0, a, b) << std::endl;
//     return 0;
// }

// 43. https://www.luogu.com.cn/problem/P3601
// #include <bits/stdc++.h>
// #define int long long
// constexpr int N = 1e6 + 1;
// constexpr int mod = 666623333;
//
// int primes[N], cnt, vis[N], phi[N], x[N];
// void euler() {
//     vis[1] = 1;
//     for (int i = 2; i < N; i++) {
//         if (!vis[i]) primes[cnt++] = i;
//         for (int j = 0; i * primes[j] < N; j++) {
//             vis[i * primes[j]] = 1;
//             if (i % primes[j] == 0) break;
//         }
//     }
// }
//
// signed main() {
//     euler();
//     int l, r;
//     std::cin >> l >> r;
//     for (int i = l; i <= r; i++) phi[i - l] = i, x[i - l] = i;
//     for (int i = 0; i < cnt; i++) {
//         for (int j = (l + primes[i] - 1) / primes[i] * primes[i]; j <= r; j += primes[i]) {
//             phi[j - l] = phi[j - l] / primes[i] * (primes[i] - 1);
//             while (x[j - l] % primes[i] == 0) x[j - l] /= primes[i];
//         }
//     }
//     for (int i = l; i <= r; i++) {
//         if (x[i - l] > 1) phi[i - l] = phi[i - l] / x[i - l] * (x[i - l] - 1);
//     }
//     int ans = 0;
//     for (int i = l; i <= r; i++) ans = (ans + i - phi[i - l]) % mod;
//     std::cout << ans << std::endl;
//     return 0;
// }

// 44. https://www.luogu.com.cn/problem/P1069
// #include <bits/stdc++.h>
// constexpr int inf = 1e9;
//
// signed main() {
//     int n, m1, m2;
//     std::cin >> n >> m1 >> m2;
//     std::unordered_map<int, int> mp;
//     for (int i = 2; i <= m1; i++) {
//         while (m1 % i == 0) mp[i] += m2, m1 /= i;
//     }
//     int ans = inf;
//     for (int i = 0, x; i < n; ++i) {
//         std::cin >> x;
//         int mx = 0;
//         for (const auto [x1, x2] : mp) {
//             int cnt = 0;
//             while (x % x1 == 0) x /= x1, cnt++;
//             if (cnt == 0) {
//                 mx = inf;
//                 break;
//             }
//             mx = std::max(mx, (x2 + cnt - 1) / cnt);
//         }
//         ans = std::min(ans, mx);
//     }
//     if (ans == inf) std::cout << -1 << std::endl;
//     else std::cout << ans << std::endl;
//     return 0;
// }

// 2026.2.7 VP Codeforces Round 1072 (Div. 3)
// 45. A
// #include <bits/stdc++.h>
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n;
//         std::cin >> n;
//         if (n == 2) std::cout << 2 << std::endl;
//         else if (n == 3) std::cout << 3 << std::endl;
//         else {
//             if (n & 1) std::cout << 1 << std::endl;
//             else std::cout << 0 << std::endl;
//         }
//     }
//     return 0;
// }

// B
// #include <bits/stdc++.h>
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int s, k, m;
//         std::cin >> s >> k >> m;
//         if (s >= k) {
//             int t = m / k;
//             if (t & 1) {
//                 std::cout << k - m % k << std::endl;
//             } else {
//                 std::cout << s - m % k << std::endl;
//             }
//         } else {
//             std::cout << std::max(0, s - m % k) << std::endl;
//         }
//     }
//     return 0;
// }

// 46. C
// #include <bits/stdc++.h>
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n, k;
//         std::cin >> n >> k;
//         int deep = 0, have_ans = false;
//         std::unordered_map<int, int> vis;
//         auto dfs = [&](auto&& self, int x, int d) -> bool {
//             if (vis.find(x) != vis.end()) return vis[x];
//             if (have_ans) return vis[x] = true;
//             if (x < k) return vis[x] = false;
//             if (x == k) {
//                 deep = d;
//                 have_ans = true;
//                 return vis[x] = true;
//             }
//             int x1 = x / 2, x2 = x - x / 2;
//             if (x1 == x2) return vis[x] = self(self, x1, d + 1);
//             return vis[x] = self(self, x1, d + 1) || self(self, x2, d + 1);
//         };
//         if (dfs(dfs, n, 0)) {
//             std::cout << deep << std::endl;
//         } else {
//             std::cout << -1 << std::endl;
//         }
//     }
//     return 0;
// }

// 47. E
// #include <bits/stdc++.h>
// #define int long long
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n;
//         std::cin >> n;
//         std::vector<int> a(n + 1);
//         for (int i = 1; i <= n; i++) std::cin >> a[i];
//         std::set<int> s;
//         std::unordered_map<int, int> mp;
//         s.insert(1);
//         mp[1] = n;
//         std::vector<std::pair<int, int>> dis(n);
//         for (int i = 1; i < n; i++) {
//             dis[i] = {std::abs(a[i + 1] - a[i]), i};
//         }
//         std::sort(dis.begin() + 1, dis.end());
//         int t = 1;
//         int ans = 1LL * n * (n - 1) / 2;
//         for (int i = 1; i < n; i++) {
//             while (t < n && dis[t].first < i) {
//                 auto it = s.upper_bound(dis[t].second);
//                 --it;
//                 int len = mp[*it] - *it + 1;
//                 ans -= 1LL * len * (len - 1) / 2;
//                 int len1 = dis[t].second - *it + 1;
//                 int len2 = mp[*it] - dis[t].second;
//                 ans += 1LL * len1 * (len1 - 1) / 2;
//                 ans += 1LL * len2 * (len2 - 1) / 2;
//                 if (len2 != 1) {
//                     mp[dis[t].second + 1] = mp[*it];
//                     s.insert(dis[t].second + 1);
//                 }
//                 if (len1 == 1) s.erase(*it);
//                 else mp[*it] = dis[t].second;
//                 t++;
//             }
//             std::cout << ans << " \n"[i == n - 1];
//         }
//     }
//     return 0;
// }

// 48. F
// #include <bits/stdc++.h>
// #define int long long
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n;
//         std::cin >> n;
//         std::vector<std::vector<int>> g(n + 1);
//         for (int i = 1, u, v; i < n; i++) {
//             std::cin >> u >> v;
//             g[u].emplace_back(v);
//             g[v].emplace_back(u);
//         }
//         std::vector<std::array<int, 3>> ans(n + 1);
//         std::vector<int> vis(n + 1);
//         auto dfs = [&](auto&& self, int u, int fa) -> void {
//             for (int v : g[u]) {
//                 if (v == fa) continue;
//                 self(self, v, u);
//                 ans[v][1] = 1;
//                 auto x = ans[u];
//                 ans[u] = {0, 0, 0};
//                 for (int i = 0; i < 3; i++) {
//                     if (ans[v][i]) {
//                         if (vis[u]) {
//                             for (int j = 0; j < 3; j++) {
//                                 if (x[j]) {
//                                     ans[u][(j + i) % 3] = 1;
//                                 }
//                             }
//                         } else {
//                             ans[u][i] = 1;
//                         }
//                     }
//                 }
//                 vis[u] = 1;
//             }
//         };
//         dfs(dfs, 1, 0);
//         if (ans[1][0]) std::cout << "YES" << std::endl;
//         else std::cout << "NO" << std::endl;
//     }
//     return 0;
// }

// 49. https://codeforces.com/contest/2184/problem/D
// #include <bits/stdc++.h>
// constexpr int N = 35;
//
// int C[N][N];
//
// void init() {
//     for (auto & i : C) i[0] = 1;
//     for (int i = 1; i < N; i++)
//         for (int j = 1; j <= i; j++)
//             C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
// }
//
// signed main() {
//     init();
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n, k;
//         std::cin >> n >> k;
//         int ans = 0;
//         for (int i = 1, j = 1; i <= n; i <<= 1, j++) {
//             if (i == n) {
//                 if (j > k) ans++;
//                 break;
//             }
//             for (int z = std::max(k - j + 1, 0); z < j; z++)
//                 ans += C[j - 1][z];
//         }
//         std::cout << ans << std::endl;
//     }
//     return 0;
// }

// 50. https://codeforces.com/contest/2184/problem/G
// #include <bits/stdc++.h>
// constexpr int N = 2e5 + 10;
//
// struct node {
//     int l, r, mi;
// } tr[N << 2];
//
// int a[N];
//
// void pushup(int u) {
//     tr[u].mi = std::min(tr[u << 1].mi, tr[u << 1 | 1].mi);
// }
//
// void build(int u, int l, int r) {
//     tr[u] = {l, r};
//     if (l == r) {
//         tr[u].mi = a[l];
//         return;
//     }
//     int mid = (l + r) >> 1;
//     build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
//     pushup(u);
// }
//
// int query(int u, int l, int r) {
//     if (l <= tr[u].l && tr[u].r <= r) return tr[u].mi;
//     int mid = (tr[u].l + tr[u].r) >> 1;
//     if (r <= mid) return query(u << 1, l, r);
//     if (l > mid) return query(u << 1 | 1, l, r);
//     return std::min(query(u << 1, l, mid), query(u << 1 | 1, mid + 1, r));
// }
//
// void change(int u, int p, int x) {
//     if (tr[u].l == tr[u].r) {
//         tr[u].mi = x;
//         return;
//     }
//     int mid = (tr[u].l + tr[u].r) >> 1;
//     if (p <= mid) change(u << 1, p, x);
//     else change(u << 1 | 1, p, x);
//     pushup(u);
// }
//
// signed main() {
//     std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n, q;
//         std::cin >> n >> q;
//         for (int i = 1; i <= n; i++) std::cin >> a[i];
//         build(1, 1, n);
//         while (q--) {
//             int idx;
//             std::cin >> idx;
//             if (idx == 1) {
//                 int i, x;
//                 std::cin >> i >> x;
//                 change(1, i, x);
//             } else {
//                 int l_, r_;
//                 std::cin >> l_ >> r_;
//                 int l = 0, r = r_ - l_;
//                 int cnt = 0;
//                 while (l <= r) {
//                     int mid = (l + r) >> 1;
//                     int t = query(1, l_, l_ + mid);
//                     if (t == mid) {
//                         cnt++;
//                         break;
//                     }
//                     if (t < mid) r = mid - 1;
//                     else l = mid + 1;
//                 }
//                 std::cout << cnt << std::endl;
//             }
//         }
//     }
//     return 0;
// }

// 51. https://leetcode.cn/problems/russian-doll-envelopes/?envType=study-plan-v2&envId=dynamic-programming
// #include <bits/stdc++.h>
// using namespace std;
//
//
// class Solution {
// public:
//     static int maxEnvelopes(vector<vector<int>>& envelopes) {
//         std::sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
//             if (a[0] != b[0]) return a[0] < b[0];
//             return a[1] > b[1];
//         });
//         std::vector<vector<int>> dp(envelopes.size());
//         dp[0] = envelopes[0];
//         int ans = 1;
//         for (int i = 1; i < envelopes.size(); i++) {
//             int l = 0, r = ans - 1;
//             while (l <= r) {
//                 int mid = (l + r) >> 1;
//                 if (dp[mid][0] < envelopes[i][0] && dp[mid][1] < envelopes[i][1]) {
//                     l = mid + 1;
//                 } else {
//                     r = mid - 1;
//                 }
//             }
//             ans = std::max(ans, l + 1);
//             dp[l] = envelopes[i];
//         }
//         return ans;
//     }
// };
//
// int main() {
//     vector<vector<int>> envelopes = {{5,4},{6,4},{6,7},{2,3}};
//     std::cout << Solution::maxEnvelopes(envelopes);
//     return 0;
// }

// 2026.2.9 VP Codeforces Round 1078 (Div. 2)
// 52. A
// #include <bits/stdc++.h>
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n, w;
//         std::cin >> n >> w;
//         int ans = n / w * (w - 1);
//         int mod = n % w;
//         ans += mod;
//         std::cout << ans << std::endl;
//     }
//     return 0;
// }

// 53. B
// #include <bits/stdc++.h>
// #define int long long
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n, x, y;
//         std::cin >> n >> x >> y;
//         std::vector<int> a(n);
//         for (int i = 0; i < n; i++) std::cin >> a[i];
//         int sum = 0;
//         for (int i = 0; i < n; i++) sum += a[i] / x * y;
//         int ans = 0;
//         for (int i = 0; i < n; i++) ans = std::max(ans, sum - a[i] / x * y + a[i]);
//         std::cout << ans << std::endl;
//     }
//     return 0;
// }

// 54. C
// #include <bits/stdc++.h>
//
// void solve() {
//     int n, k;
//     std::cin >> n >> k;
//     std::vector<std::string> a(k);
//     for (int i = 0; i < k; i++) std::cin >> a[i];
//     std::vector<int> ans;
//     for (int i = 1; i * i <= n; i++) {
//         if (n % i == 0) {
//             ans.push_back(n / i);
//             if (i != n / i) ans.push_back(i);
//         }
//     }
//     std::vector<std::array<int, 26>> vis(n);
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < k; j++) {
//             vis[i][a[j][i] - 'a'] = 1;
//         }
//     }
//     std::sort(ans.begin(), ans.end());
//     for (const int x : ans) {
//         std::string best;
//         bool have_ans = true;
//         for (int i = 0; i < x; i++) {
//             auto bit = vis[i];
//             for (int j = i + x; j < n; j += x) {
//                 for (int c = 0; c < 26; c++) {
//                     bit[c] &= vis[j][c];
//                 }
//             }
//             bool have = false;
//             for (int c = 0; c < 26; c++) {
//                 if (bit[c]) {
//                     have = true;
//                     best += c + 'a';
//                     break;
//                 }
//             }
//             have_ans &= have;
//             if (!have) break;
//         }
//         if (have_ans) {
//             std::string ans_;
//             for (int i = 0; i < n / x; i++) ans_ += best;
//             std::cout << ans_ << std::endl;
//             return;
//         }
//     }
// }
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         solve();
//     }
//     return 0;
// }

// 55. D
// #include <bits/stdc++.h>
// #define int long long
//
// void solve() {
//     int n, m;
//     std::cin >> n >> m;
//     std::vector a(n + 1, std::vector<int>(m + 1));
//     int cnt1 = 0;
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= m; j++) {
//             std::cin >> a[i][j];
//             cnt1 += a[i][j];
//         }
//     }
//     auto cnt = a;
//     for (int j = 1; j <= m; j++) {
//         for (int i = n - 1; i >= 1; i--) {
//             cnt[i][j] += cnt[i + 1][j];
//         }
//     }
//     int x = cnt1 / 2;
//     int ans = x * (cnt1 - x);
//     std::cout << ans << std::endl;
//     std::string s;
//     int posx = 1, posy = 1;
//     int dang = 0;
//     while (posx != n + 1 || posy != m + 1) {
//         if (dang == x) {
//             if (posx != n + 1) {
//                 posx++;
//                 s += 'D';
//             } else {
//                 posy++;
//                 s += 'R';
//             }
//             continue;
//         }
//         if (dang + cnt[posx][posy] <= x) {
//             dang += cnt[posx][posy];
//             posy++;
//             s += 'R';
//         } else {
//             posx++;
//             s += 'D';
//         }
//     }
//     std::cout << s << std::endl;
// }
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         solve();
//     }
//     return 0;
// }

// 2026.2.10 VP Educational Codeforces Round 186 (Rated for Div. 2)
// 56. A
// #include <bits/stdc++.h>
// #define int long long
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n;
//         std::cin >> n;
//         std::string s;
//         std::cin >> s;
//         if (s.find("2025") == std::string::npos || s.find("2026") != std::string::npos) {
//             std::cout << 0 << "\n";
//         } else {
//             std::cout << 1 << "\n";
//         }
//     }
//     return 0;
// }

// 57. B
// #include <bits/stdc++.h>
// #define int long long
//
// signed main() {
//     int T;
//     std::cin >> T;
//     std::vector<int> mi(30);
//     mi[1] = 1;
//     for (int i = 2; i < 30; i++) mi[i] = mi[i - 1] * 2;
//     std::vector<int> ji(30), ou(30);
//     for (int i = 1; i <= 30; i++) {
//         ji[i] = ji[i - 1] + (i & 1 ? mi[i] : 0);
//         ou[i] = ou[i - 1] + (i & 1 ? 0 : mi[i]);
//     }
//     while (T--) {
//         int a, b;
//         std::cin >> a >> b;
//         int l = 1, r = 21;
//         while (l <= r) {
//             int mid = (l + r) >> 1;
//             if ((ji[mid] <= a && ou[mid] <= b) || (ji[mid] <= b && ou[mid] <= a)) {
//                 l = mid + 1;
//             } else {
//                 r = mid - 1;
//             }
//         }
//         std::cout << l - 1 << std::endl;
//     }
//     return 0;
// }

// 58. C
// #include <bits/stdc++.h>
// #define int long long
//
// bool he(std::vector<int>& a, std::vector<int>& b, int s) {
//     int n = a.size() - 1;
//     for (int i = 1; i <= n; i++) {
//         if (a[i] >= b[((i + s) % n) == 0 ? n : (i + s) % n]) return false;
//     }
//     return true;
// }
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n;
//         std::cin >> n;
//         std::vector<int> a(n + 1), b(n + 1), c(n + 1);
//         for (int i = 1; i <= n; i++) std::cin >> a[i];
//         for (int i = 1; i <= n; i++) std::cin >> b[i];
//         for (int i = 1; i <= n; i++) std::cin >> c[i];
//         int cnt1 = 0;
//         for (int i = 1; i <= n; i++) {
//             if (he(a, b, i)) cnt1++;
//         }
//         int cnt2 = 0;
//         for (int i = 1; i <= n; i++) {
//             if (he(b, c, i)) cnt2++;
//         }
//         std::cout << n * cnt1 * cnt2 << std::endl;
//     }
//     return 0;
// }

// 59. D
// #include <bits/stdc++.h>
// #define int long long
// constexpr int mod = 998244353;
//
// const int N = 1e5 + 10;
// int fact[N], infact[N];
//
// int ksm(int a, int k, int mod) {
//     int res = 1;
//     a %= mod;
//     while (k) {
//         if (k & 1) res = 1LL * res * a % mod;
//         a = 1LL * a * a % mod;
//         k >>= 1;
//     }
//     return res;
// }
//
// void init() {
//     infact[0] = fact[0] = 1;
//     for (int i = 1; i < N; i++) {
//         fact[i] = 1LL * fact[i - 1] * i % mod;
//         infact[i] = 1LL * infact[i - 1] * ksm(i, mod - 2, mod) % mod;
//     }
// }
// // 从 n 个里面选 m 个
// int C(int n, int m) {
//     return (1LL * fact[n] * infact[n - m] % mod) * infact[m] % mod;
// }
//
// int A(int n, int m) {
//     return 1LL * fact[n] * infact[n - m] % mod;
// }
//
// signed main() {
//     init();
//     int T;
//     std::cin >> T;
//     std::vector<int> fac(52);
//     fac[0] = 1;
//     for (int i = 1; i <= 50; i++) fac[i] = fac[i - 1] * i % mod;
//     while (T--) {
//         int n;
//         std::cin >> n;
//         std::vector<int> a(n + 1);
//         for (int i = 0; i <= n; i++) std::cin >> a[i];
//         int mx = 0, sum = 0;
//         for (int i = 1; i <= n; i++) {
//             mx = std::max(mx, a[i]);
//             sum += a[i];
//         }
//         int cnt_mx = 0;
//         for (int i = 1; i <= n; i++) cnt_mx += a[i] == mx;
//         int i;
//         for (i = n; i >= 1; i--) {
//             int mi_sum = mx * i + (mx - 1) * (n - i);
//             if (mi_sum - sum <= a[0]) break;
//         }
//         if (i < cnt_mx) std::cout << 0 << std::endl;
//         else {
//             std::cout << fac[n - cnt_mx] * A(i, cnt_mx) % mod << std::endl;
//         }
//     }
//     return 0;
// }

// 60. E
// #include <bits/stdc++.h>
// #define int long long
//
// struct node {
//     int x, y, z;
// };
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n, m, k;
//         std::cin >> n >> m >> k;
//         std::vector<int> a(m + 1);
//         for (int i = 1; i <= m; i++) std::cin >> a[i];
//         std::vector<node> b(n + 1);
//         for (int i = 1; i <= n; i++) std::cin >> b[i].x >> b[i].y >> b[i].z, k -= b[i].y;
//         std::sort(b.begin() + 1, b.end(), [](const node& x, const node& y) {
//             return x.z - x.y > y.z - y.y || (x.z - x.y == y.z - y.y && x.x < y.x);
//         });
//         std::multiset<int> ms;
//         for (int i = 1; i <= m; i++) ms.insert(a[i]);
//         std::vector<bool> vis(n + 1);
//         int ans = 0;
//         for (int i = 1; i <= n; i++) {
//             if (ms.empty()) break;
//             if (auto it = ms.lower_bound(b[i].x); it != ms.end()) {
//                 ans++;
//                 ms.erase(it);
//                 vis[i] = true;
//             }
//         }
//         std::vector<node> c;
//         for (int i = 1; i <= n; i++) {
//             if (!vis[i]) c.push_back(b[i]);
//         }
//         std::sort(c.begin(), c.end(), [](const node& x, const node& y) {
//             return x.z - x.y < y.z - y.y;
//         });
//         for (int i = 0; i < c.size(); i++) {
//             if (k >= c[i].z - c[i].y) {
//                 k -= c[i].z - c[i].y;
//                 ans++;
//             } else {
//                 break;
//             }
//         }
//         std::cout << ans << std::endl;
//     }
//     return 0;
// }

// 2026.2.11 VP The 2023 ICPC Asia Nanjing Regional Contest (The 2nd Universal Cup. Stage 11: Nanjing)
// 61. I
// #include <bits/stdc++.h>
// #define int long long
//
// void solve() {
//     int n, m;
//     std::cin >> n >> m;
//     std::vector<std::pair<int, int>> a(m + 1);
//     for (int i = 1; i <= m; i++) std::cin >> a[i].first >> a[i].second;
//     std::sort(a.begin() + 1, a.end());
//     int cnt = 0, x = 0;
//     for (int i = 1; i <= m; i++) {
//         int step = a[i].first - cnt;
//         if (!(step > a[i].second || step + x == a[i].second)) {
//             std::cout << "No" << "\n";
//             return;
//         }
//         cnt = a[i].first, x = a[i].second;
//     }
//     std::cout << "Yes" << "\n";
// }
//
// signed main() {
//     std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
//     int T;
//     std::cin >> T;
//     while (T--) {
//         solve();
//     }
//     return 0;
// }

// 62. G
// #include <bits/stdc++.h>
// #define int long long
//
// signed main() {
//     int n, w, k;
//     std::cin >> n >> w >> k;
//     std::vector<std::pair<int, int>> a(n);
//     for (int i = 0; i < n; i++) std::cin >> a[i].first >> a[i].second;
//     std::sort(a.begin(), a.end());
//     std::vector<int> suf(n + 1);
//     std::priority_queue<int, std::vector<int>, std::greater<>> q;
//     for (int i = n - 1; i >= n - k; i--) {
//         suf[i] = suf[i + 1] + a[i].second;
//         q.push(a[i].second);
//     }
//     for (int i = n - k - 1; i > 0; i--) {
//         q.push(a[i].second);
//         suf[i] = suf[i + 1] - q.top() + a[i].second;
//         q.pop();
//     }
//     std::vector<int> dp(w + 1);
//     int ans = 0;
//     for (int i = 0; i < n; i++) {
//         for (int j = w; j >= a[i].first; j--) {
//             dp[j] = std::max(dp[j], dp[j - a[i].first] + a[i].second);
//         }
//         ans = std::max(ans, dp[w] + suf[i + 1]);
//     }
//     std::cout << ans << std::endl;
//     return 0;
// }

// 63. F
// #include <bits/stdc++.h>
//
// void solve() {
//     int n, m;
//     std::cin >> n >> m;
//     std::vector<int> du(n + 1);
//     std::vector<std::vector<int>> pos(m + 1);
//     std::vector<std::vector<int>> g(n + 1);
//     for (int i = 1, p; i <= n; i++) {
//         std::cin >> p;
//         for (int j = 0, x; j < p; j++) {
//             std::cin >> x;
//             pos[x].emplace_back(i);
//         }
//     }
//     for (int i = 1; i <= m; i++) {
//         const int sz = pos[i].size() - 1;
//         for (int j = 0; j < sz; j++) {
//             du[pos[i].back()]++;
//             g[pos[i][j]].emplace_back(pos[i].back());
//         }
//     }
//     std::priority_queue<int> q;
//     for (int i = 1; i <= n; i++) {
//         if (!du[i]) q.push(i);
//     }
//     std::vector<int> ans;
//     while (!q.empty()) {
//         int u = q.top();
//         q.pop();
//         ans.emplace_back(u);
//         for (int v : g[u]) {
//             if (!--du[v]) {
//                 q.push(v);
//             }
//         }
//     }
//     if (std::is_sorted(ans.begin(), ans.end())) {
//         std::cout << "No\n";
//     } else {
//         std::cout << "Yes\n";
//         for (int i = 0; i < n; i++) std::cout << ans[i] << " \n"[i == n - 1];
//     }
// }
//
// int main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         solve();
//     }
//     return 0;
// }

// 2026.2.12 VP The 2024 CCPC Shandong Invitational Contest and Provincial Collegiate Programming Contest
// 64. I
// #include <bits/stdc++.h>
//
// signed main() {
//     std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
//     int T;
//     std::cin >> T;
//     while (T--) {
//         std::string s;
//         std::cin >> s;
//         if (s[0] == s.back()) std::cout << 0 << "\n";
//         else if (s.size() == 1) std::cout << 0 << "\n";
//         else {
//             int n = s.size() - 1;
//             int i;
//             bool have = false;
//             for (i = 0; i < n; i++) {
//                 if (s[i] == s[i + 1]) {
//                     have = true;
//                     break;
//                 }
//             }
//             if (have) std::cout << i + 1 << "\n";
//             else std::cout << -1 << "\n";
//         }
//     }
//     return 0;
// }

// 65. https://codeforces.com/gym/104821/problem/C
// #include <bits/stdc++.h>
// #define int long long
//
// signed main() {
//     std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int p, m;
//         std::cin >> p >> m;
//         int ans = m / p;
//         for (int i = m / p; i <= m / p + 2; i++) {
//             if (((i * p + 1) ^ (p - 1)) <= m) ans++;
//         }
//         std::cout << ans << "\n";
//     }
//     return 0;
// }

// 66.
// #include <bits/stdc++.h>
// #define int long long
//
// signed main() {
//     std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int p, a, b, q, c, d, m, t;
//         std::cin >> p >> a >> b >> q >> c >> d >> m >> t;
//         while (true) {
//             int mx = m / p;
//             if (mx <= 0) break;
//             int x = mx * (q - p);
//             int cnt = (p - m % p + x - 1) / x;
//             int ts = mx * (a + c) + b + d;
//             int tt = cnt * ts;
//             if (tt > t) {
//                 cnt = t / ts;
//                 x = cnt * (q - p) * mx;
//                 t %= ts;
//                 m += x;
//                 cnt = (t - b - d) / (a + c);
//                 if (cnt <= 0) break;
//                 m += cnt * (q - p);
//                 break;
//             }
//             m += cnt * x;
//             t -= tt;
//         }
//         std::cout << m << "\n";
//     }
//     return 0;
// }

// 67. https://www.luogu.com.cn/problem/P2657
// #include <bits/stdc++.h>
// #define int long long
//
// int A[12];
// int dp[12][10][2][2];
//
// int dfs(int deep, int shang, bool xian, bool start) {
//     if (dp[deep][shang][xian][start] != -1) return dp[deep][shang][xian][start];
//     if (deep == 0) return 1;
//     int res = 0;
//     if (!start) {
//         int t = A[deep];
//         if (!xian) t = 9;
//         for (int i = 0; i <= t; i++) {
//             res += dfs(deep - 1, i, xian && (i == A[deep]), i != 0);
//         }
//     } else {
//         int t = A[deep];
//         if (!xian) t = 9;
//         for (int i = shang + 2; i <= t; i++) {
//             res += dfs(deep - 1, i, xian && (i == A[deep]), start);
//         }
//         for (int i = std::min(shang - 2, t); i >= 0; i--) {
//             res += dfs(deep - 1, i, xian && (i == A[deep]), start);
//         }
//     }
//     return dp[deep][shang][xian][start] = res;
// }
//
// signed main() {
//     memset(dp, -1, sizeof dp);
//     int a, b;
//     std::cin >> a >> b;
//     a--;
//     int cnt = 0;
//     while (a) A[++cnt] = a % 10, a /= 10;
//     int x1 = dfs(cnt, 0, true, false);
//     memset(dp, -1, sizeof dp);
//     cnt = 0;
//     while (b) A[++cnt] = b % 10, b /= 10;
//     int x2 = dfs(cnt, 0, true, false);
//     std::cout << x2 - x1;
//     return 0;
// }

// 68. https://www.luogu.com.cn/problem/P12835
// #include <bits/stdc++.h>
// #define int long long
//
// signed main() {
//     int n;
//     std::cin >> n;
//     std::vector<int> mi(20);
//     mi[1] = 1;
//     for (int i = 2; i < 20; i++) mi[i] = 10 * mi[i - 1];
//     int l = 10, r = 1e18;
//     while (l <= r) {
//         int mid = (l + r) >> 1;
//         int t = mid, cnt = 0;
//         while (t) t /= 10, cnt++;
//         int vis[20][2][2][2];
//         memset(vis, -1, sizeof vis);
//         auto dfs = [&](auto&& self, int wei, bool is_xian, bool is_start, bool is_ji) -> int {
//             if (vis[wei][is_xian][is_start][is_ji] != -1) return vis[wei][is_xian][is_start][is_ji];
//             if (wei == 0) return 1;
//             int res = 0;
//             int bit = mid / mi[wei] % 10;
//             if (is_start) {
//                 int ed = bit;
//                 if (!is_xian) ed = 9;
//                 for (int i = is_ji ^ 1; i <= ed; i += 2) {
//                     res += self(self, wei - 1, is_xian && (i == bit), true, is_ji ^ 1);
//                 }
//             } else {
//                 int st = 0, ed = bit;
//                 if (!is_xian) ed = 9;
//                 if (wei == 2) st = 1;
//                 for (int i = st; i <= ed; i++) res += self(self, wei - 1, is_xian && i == ed, i != 0, i & 1);
//             }
//             return vis[wei][is_xian][is_start][is_ji] = res;
//         };
//         int x = dfs(dfs, cnt, true, false, false);
//         if (x >= n) r = mid - 1;
//         else l = mid + 1;
//     }
//     std::cout << r + 1;
//     return 0;
// }

// 69. https://codeforces.com/gym/105486/problem/A
// #include <bits/stdc++.h>
//
// void solve() {
//     std::string s;
//     std::cin >> s;
//     int n = s.size();
//     s = " " + s;
//     if (s[1] != '>' || s[n] != '>' || s[n - 1] != '>' || s[n - 2] != '>') {
//         std::cout << "No\n";
//         return;
//     }
//     bool have_ = false;
//     for (int i = 1; i <= n; i++) have_ |= s[i] == '-';
//     if (!have_) {
//         std::cout << "No\n";
//         return;
//     }
//     int l = 1, r = n, cnt = 0;
//     while (s[r] == '>') r--, cnt++;
//     int t = r, r_ = r;
//     r_ += 3;
//     while (s[t] == '-') t--;
//     r = n;
//     std::vector<std::pair<int, int>> ans;
//     while (l < n - cnt) {
//         ans.emplace_back(l, r - l + 1);
//         l++;
//         while (s[l] != '>') l++;
//         if (r > r_) r--;
//     }
//     while (r >= r_) {
//         ans.emplace_back(t, r - t + 1);
//         r--;
//     }
//     std::cout << "Yes " << ans.size() << '\n';
//     for (const auto& [x, y] : ans) {
//         std::cout << x << " " << y << '\n';
//     }
// }
//
// signed main() {
//     std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
//     int T;
//     std::cin >> T;
//     while (T--) {
//         solve();
//     }
//     return 0;
// }

// 70. https://codeforces.com/gym/105486/problem/L
// #include <bits/stdc++.h>
//
// signed main() {
//     int a, b, c;
//     std::cin >> a >> b >> c;
//     std::cout << 100 << '\n';
//     for (int i = 1; i <= 50; i++) std::cout << a << ' ';
//     for (int i = 51; i <= 95; i++) std::cout << b << ' ';
//     for (int i = 96; i <= 99; i++) std::cout << c << ' ';
//     std::cout << c + 1 << '\n';
//     return 0;
// }

// 71. https://codeforces.com/gym/105486/problem/G
// #include <bits/stdc++.h>
//
// void add(int x, int y, std::set<int>& s) {
//     s.insert(x);
//     s.insert(y);
//     s.insert(x | y);
//     s.insert(x & y);
//     s.insert(x ^ y);
//     s.insert(x & (x ^ y));
//     s.insert(x ^ (x | y));
//     s.insert(y & (x ^ y));
//     s.insert(y ^ (x | y));
// }
//
// signed main() {
//     int n;
//     std::cin >> n;
//     std::vector<int> a(n + 1);
//     std::set<int> s;
//     for (int i = 1; i <= n; i++) std::cin >> a[i];
//     for (int i = 1; i < n; i++) add(a[i], a[i + 1], s);
//     s.insert(0);
//     std::cout << s.size();
//     return 0;
// }

// 72. https://codeforces.com/contest/2195/problem/E
// #include <bits/stdc++.h>
// constexpr int mod = 1e9 + 7;
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n;
//         std::cin >> n;
//         std::vector<std::vector<int>> g(n + 1);
//         std::vector<int> fa(n + 1), ans(n + 1), deep(n + 1);
//         for (int i = 1; i <= n; i++) {
//             int l, r;
//             std::cin >> l >> r;
//             if (l == 0) continue;
//             g[i].emplace_back(l);
//             g[i].emplace_back(r);
//             fa[l] = i, fa[r] = i;
//         }
//         auto dfs = [&](auto&& self, const int u, const int d) -> int {
//             ans[u] = 1;
//             deep[u] = d;
//             for (int v : g[u]) {
//                 ans[u] += self(self, v, d + 1);
//             }
//             return ans[u];
//         };
//         dfs(dfs, 1, 1);
//         for (int i = 1; i <= n; i++) ans[i] = (ans[i] - 1) * 2 % mod;
//         auto dfs2 = [&](auto&& self, const int u) -> void {
//             ans[u] = (ans[u] + ans[fa[u]]) % mod;
//             for (int v : g[u]) {
//                 self(self, v);
//             }
//         };
//         dfs2(dfs2, 1);
//         for (int i = 1; i <= n; i++) std::cout << (ans[i] + deep[i]) % mod << " \n"[i == n];
//     }
//     return 0;
// }

// 73. https://codeforces.com/problemset/problem/2195/F
// #include <bits/stdc++.h>
// #define int long long
//
// struct node {
//     int a, b, c;
// };
//
// bool is_less(const node& x, const node& y) {
//     if (x.a > y.a) return false;
//     if (x.a == y.a) return x.b == y.b && x.c < y.c;
//     const int a = x.a - y.a, b = x.b - y.b, c = x.c - y.c;
//     return b * b - 4 * a * c < 0;
// }
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n;
//         std::cin >> n;
//         std::vector<node> a(n);
//         for (int i = 0; i < n; i++) std::cin >> a[i].a >> a[i].b >> a[i].c;
//         std::vector<int> du1(n), du2(n), dp1(n), dp2(n);
//         std::vector<std::vector<int>> g1(n), g2(n);
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (is_less(a[i], a[j])) {
//                     du1[j]++, du2[i]++;
//                     g1[i].emplace_back(j), g2[j].emplace_back(i);
//                 }
//             }
//         }
//         std::queue<int> q;
//         for (int i = 0; i < n; i++) if (!du1[i]) q.push(i), dp1[i] = 1;
//         while (!q.empty()) {
//             const int u = q.front();
//             q.pop();
//             for (const int v : g1[u]) {
//                 dp1[v] = std::max(dp1[v], dp1[u] + 1);
//                 if (!--du1[v]) q.push(v);
//             }
//         }
//         for (int i = 0; i < n; i++) if (!du2[i]) q.push(i), dp2[i] = 1;
//         while (!q.empty()) {
//             const int u = q.front();
//             q.pop();
//             for (const int v : g2[u]) {
//                 dp2[v] = std::max(dp2[v], dp2[u] + 1);
//                 if (!--du2[v]) q.push(v);
//             }
//         }
//         for (int i = 0; i < n; i++) std::cout << dp1[i] + dp2[i] - 1 << " \n"[i == n - 1];
//     }
//     return 0;
// }

// 74. https://codeforces.com/contest/2192/problem/C
// #include <bits/stdc++.h>
// #define int long long
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n, h, k;
//         std::cin >> n >> h >> k;
//         std::vector<int> a(n + 1);
//         for (int i = 1; i <= n; i++) std::cin >> a[i];
//         std::vector<int> sum(n + 1), mi(n + 1), mx(n + 2);
//         mi[0] = 1e9, mx[n + 1] = 0;
//         for (int i = 1; i <= n; i++) {
//             sum[i] = sum[i - 1] + a[i];
//             mi[i] = std::min(mi[i - 1], a[i]);
//         }
//         for (int i = n; i >= 1; i--) {
//             mx[i] = std::max(mx[i + 1], a[i]);
//         }
//         const int ans = h / sum[n] * (k + n);
//         h %= sum[n];
//         if (!h) std::cout << ans - k << '\n';
//         else {
//             for (int i = 1; i <= n; i++) {
//                 if (sum[i] - mi[i] + mx[i + 1] >= h || sum[i] >= h) {
//                     std::cout << ans + i << '\n';
//                     break;
//                 }
//             }
//         }
//     }
//     return 0;
// }

// 75. https://codeforces.com/contest/2192/problem/D
// #include <bits/stdc++.h>
// #define int long long
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n;
//         std::cin >> n;
//         std::vector<int> a(n + 1);
//         for (int i = 1; i <= n; i++) std::cin >> a[i];
//         std::vector<std::vector<int>> g(n + 1);
//         for (int i = 1, u, v; i < n; i++) {
//             std::cin >> u >> v;
//             g[u].emplace_back(v);
//             g[v].emplace_back(u);
//         }
//         std::vector<int> deep(n + 1), ans(n + 1), mo(n + 1);
//         std::vector<int> sum = a;
//         auto dfs = [&](auto&& self, const int u, const int fa) -> void {
//             for (const int v : g[u]) {
//                 if (v == fa) continue;
//                 self(self, v, u);
//                 deep[u] = std::max(deep[u], deep[v] + 1);
//                 sum[u] += sum[v];
//                 mo[u] += sum[v] + mo[v];
//             }
//             ans[u] = mo[u];
//             for (const int v : g[u]) {
//                 if (v == fa) continue;
//                 ans[u] = std::max(ans[u], mo[u] - mo[v] + ans[v]);
//             }
//             std::multiset<int> mx;
//             for (const int v : g[u]) {
//                 if (v == fa) continue;
//                 mx.insert(deep[v]);
//             }
//             if (mx.size() > 1) {
//                 for (const int v : g[u]) {
//                     if (v == fa) continue;
//                     mx.erase(mx.find(deep[v]));
//                     ans[u] = std::max(ans[u], mo[u] + (*mx.rbegin() + 1) * sum[v]);
//                     mx.insert(deep[v]);
//                 }
//             }
//         };
//         dfs(dfs, 1, 0);
//         for (int i = 1; i <= n; i++) std::cout << ans[i] << " \n"[i == n];
//     }
//     return 0;
// }

// 76. https://codeforces.com/contest/2202/problem/C1
// #include <bits/stdc++.h>
// #define int long long
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n;
//         std::cin >> n;
//         std::vector<int> a(n + 1);
//         for (int i = 1; i <= n; i++) std::cin >> a[i];
//         int ans = 1;
//         int l = a[1], r = a[1];
//         for (int i = 2; i <= n; i++) {
//             if (a[i] == a[i - 1] + 1) {
//                 r = a[i];
//             } else {
//                 if (l < a[i] && a[i] <= r) {
//                     r = a[i];
//                 } else {
//                     ans++;
//                     l = r = a[i];
//                 }
//             }
//         }
//         std::cout << ans << std::endl;
//     }
//     return 0;
// }

// 77. https://codeforces.com/contest/2202/problem/C2
// #include <bits/stdc++.h>
// #define int long long
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n;
//         std::cin >> n;
//         std::vector<int> a(n + 1), dp(n + 1);
//         for (int i = 1; i <= n; i++) std::cin >> a[i];
//         dp[1] = 1;
//         int l = 1, r = 1;
//         std::unordered_map<int, int> mp;
//         mp[a[1]] = 1;
//         for (int i = 2; i <= n; i++) {
//             if (a[i] == a[i - 1] + 1) {
//                 dp[i] = dp[i - 1] + 1;
//                 r = i;
//             } else {
//                 if (a[l] < a[i] && a[i] <= a[r]) {
//                     r = i;
//                     dp[i] = dp[i - 1] + r - mp[a[i] - 1];
//                 } else {
//                     l = r = i;
//                     dp[i] = dp[i - 1] + i;
//                 }
//             }
//             mp[a[i]] = i;
//         }
//         int ans = 0;
//         for (int i = 1; i <= n; i++) ans += dp[i];
//         std::cout << ans << "\n";
//     }
//     return 0;
// }

// 78. https://codeforces.com/contest/2202/problem/A
// #include <bits/stdc++.h>
// #define int long long
//
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int x, y;
//         std::cin >> x >> y;
//         if ((x + y) % 3 != 0) {
//             std::cout << "No\n";
//         } else {
//             int t = (x + y) / 3;
//             int z = x - 2 * t;
//             if (y == t - z && z <= 2 * t && z >= 0)  {
//                 std::cout << "Yes\n";
//             } else {
//                 std::cout << "No\n";
//             }
//         }
//     }
//     return 0;
// }

// 2026.2.25 Educational Codeforces Round 187 (Rated for Div. 2)
// 79. A
// #include <bits/stdc++.h>
// #define int long long
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n, m, d;
//         std::cin >> n >> m >> d;
//         if (m > d) std::cout << n << "\n";
//         else {
//             int x = d / m + 1;
//             std::cout << (n + x - 1) / x << "\n";
//         }
//     }
//     return 0;
// }

// 80. B
// #include <bits/stdc++.h>
// #define int long long
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         std::string s;
//         std::cin >> s;
//         std::priority_queue<int> q;
//         int sum = 0;
//         for (const char c : s) sum += c - '0';
//         q.push(s[0] - '0' - 1);
//         for (int i = 1; i < s.size(); i++) {
//             q.push(s[i] - '0');
//         }
//         int ans = 0;
//         while (sum >= 10) {
//             ans++;
//             sum -= q.top();
//             q.pop();
//         }
//         std::cout << ans << "\n";
//     }
//     return 0;
// }

// 81. C
// #include <bits/stdc++.h>
// #define int long long
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int s, m;
//         std::cin >> s >> m;
//         if ((s & -s) >= (m & -m)) {
//             int l = 1, r = 1e18;
//             while (l <= r) {
//                 int mid = (l + r) >> 1;
//                 int t = 0;
//                 for (int i = 63; i >= 0; i--) {
//                     t = (t << 1) + (s >> i & 1);
//                     if (m >> i & 1) {
//                         t -= std::min(t, mid);
//                     }
//                 }
//                 if (t == 0) r = mid - 1;
//                 else l = mid + 1;
//             }
//             std::cout << r + 1 << "\n";
//         } else {
//             std::cout << -1 << "\n";
//         }
//     }
//     return 0;
// }

// 82. D
// #include <bits/stdc++.h>
// constexpr int N = 2e6 + 1;
//
// signed main() {
//     std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n, m;
//         std::cin >> n >> m;
//         std::vector<int> b(m + 1);
//         std::unordered_map<int, int> vis;
//         for (int i = 1, x; i <= n; i++) std::cin >> x, vis[x]++;
//         for (int i = 1; i <= m; i++) std::cin >> b[i];
//         std::vector<int> mp(n + m + 1);
//         for (const auto& [x, y] : vis) {
//             for (int j = x; j <= n + m; j += x) mp[j] += y;
//         }
//         int alice_cnt = 0, bob_cnt = 0, tot_cnt = 0;
//         for (int i = 1; i <= m; i++) {
//             if (mp[b[i]] && mp[b[i]] != n) tot_cnt++;
//             else if (mp[b[i]]) alice_cnt++;
//             else bob_cnt++;
//         }
//         if (tot_cnt & 1) {
//             if (alice_cnt >= bob_cnt) {
//                 std::cout << "Alice\n";
//             } else {
//                 std::cout << "Bob\n";
//             }
//         } else {
//             if (alice_cnt > bob_cnt) {
//                 std::cout << "Alice\n";
//             } else {
//                 std::cout << "Bob\n";
//             }
//         }
//     }
//     return 0;
// }

// 寒假结束了！只做了80多道题，太逊了，这学期要努力刷题啊！ ————2026.3.2

















