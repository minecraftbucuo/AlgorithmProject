//
// Created by MINEC on 2026/3/2.
//

// 大二下启动！

// 1. https://codeforces.com/contest/2203/problem/E
// #include <bits/stdc++.h>
// using namespace std;
// constexpr int N = 2e5 + 2, mod = 998244353;
// #define int long long
//
// int ksm(int a, int k, int mod) {
//     int res = 1;
//     while (k) {
//         if (k & 1) res = res * a % mod;
//         a = a * a % mod;
//         k >>= 1;
//     }
//     return res;
// }
//
// template<typename T> T pred(T a, T b) { return a + b; }
// template<typename T, T (*Pred)(T, T) = pred<T>, T Init = 0>
// class BIT {
// public:
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
//     int lower_bound(T x) {
//         T sum = Init;
//         int index = 0;
//         for (size_t i = 1 << __lg(n); i; i >>= 1) {
//             if (index + i <= n && sum + data[index + i] < x) {
//                 index += i;
//                 sum += data[index];
//             }
//         }
//         return index + 1;
//     }
// };
//
//
// signed main() {
//     std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
//     int m;
//     std::cin >> m;
//     BIT<int> bit1(m + 1), bit2(m + 1);
//     std::vector<int> a(m + 1);
//     for (int i = 1; i <= m; i++) std::cin >> a[i];
//     std::vector<int> b = a;
//     std::sort(b.begin() + 1, b.end());
//     std::unordered_map<int, int> mp;
//     for (int i = 1; i <= m; i++) mp[b[i]] = i;
//     for (int i = 1; i <= 3; i++) bit1.update(mp[a[i]], a[i]), bit2.update(mp[a[i]], 1);
//     std::cout << "0\n";
//     auto findId = [&](int x) -> int {
//         return bit2.lower_bound(x) - 1;
//     };
//     for (int i = 4; i <= m; i++) {
//         bit1.update(mp[a[i]], a[i]), bit2.update(mp[a[i]], 1);
//         int l = 1, r = i;
//         int ans = 1e18;
//         while (l <= r) {
//             int mid = (l + r) >> 1;
//             int left = findId(mid - 1);
//             int right = findId(mid + 1);
//             int ans1 = (mid - 2) * b[left] - bit1.query(1, left - 1);
//             int ans2 = bit1.query(right + 1, m) - (i - mid - 1) * b[right];
//             ans = std::min(ans, std::max(ans1, ans2));
//             if (ans1 > ans2) r = mid - 1;
//             else l = mid + 1;
//         }
//         std::cout << ans % mod * ksm(i - 2, mod - 2, mod) % mod << "\n";
//     }
//     return 0;
// }

// 2. https://codeforces.com/contest/2205/problem/C
// #include <bits/stdc++.h>
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n;
//         std::cin >> n;
//         std::vector<std::vector<int>> a(n + 1);
//         for (int i = 1, l; i <= n; i++) {
//             std::cin >> l;
//             a[i].assign(l + 1, 1);
//             for (int j = 1; j <= l; j++) std::cin >> a[i][j];
//             for (int j = 1, k = l; j < k; j++, k--) std::swap(a[i][j], a[i][k]);
//             std::unordered_map<int, int> mp;
//             int j = 1, k = 1;
//             while (k < a[i].size()) {
//                 while (k < a[i].size() && mp[a[i][k]]) k++;
//                 if (k < a[i].size()) {
//                     a[i][j++] = a[i][k];
//                     mp[a[i][k]] = true;
//                 }
//             }
//             if (j < a[i].size()) a[i].erase(a[i].begin() + j, a[i].end());
//         }
//         std::unordered_map<int, bool> num_vis, pos_vis;
//         auto is_lower = [&](const int i, const int j) -> bool {
//             int ii = a[i][0], jj = a[j][0];
//             while (ii < a[i].size() && num_vis[a[i][ii]]) ii++;
//             while (jj < a[j].size() && num_vis[a[j][jj]]) jj++;
//             a[i][0] = ii, a[j][0] = jj;
//             while (ii < a[i].size() && jj < a[j].size()) {
//                 if (a[i][ii] < a[j][jj]) return true;
//                 if (a[i][ii] > a[j][jj]) return false;
//                 ++ii, ++jj;
//                 while (ii < a[i].size() && num_vis[a[i][ii]]) ii++;
//                 while (jj < a[j].size() && num_vis[a[j][jj]]) jj++;
//             }
//             if (ii == a[i].size()) return true;
//             return false;
//         };
//         std::vector<int> ans;
//         for (int i = 1, j = 1; i <= n; i++) {
//             while (pos_vis[j]) j++;
//             int mi = j;
//             for (int k = 1; k <= n; k++) {
//                 if (k == mi || pos_vis[k]) continue;
//                 if (is_lower(k, mi)) mi = k;
//             }
//             ans.push_back(mi);
//             pos_vis[mi] = true;
//             for (int k = 1; k < a[mi].size(); k++) num_vis[a[mi][k]] = true;
//         }
//         std::unordered_map<int, int> vis;
//         for (const int i : ans) {
//             for (int j = 1; j < a[i].size(); j++) {
//                 if (!vis[a[i][j]]) {
//                     std::cout << a[i][j] << " ";
//                     vis[a[i][j]] = 1;
//                 }
//             }
//         }
//         std::cout << "\n";
//     }
//     return 0;
// }

// 3. https://codeforces.com/contest/2200/problem/D
// #include <bits/stdc++.h>
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n, x, y;
//         std::cin >> n >> x >> y;
//         std::vector<int> a(n + 1);
//         for (int i = 1; i <= n; i++) std::cin >> a[i];
//         std::vector<int> b, c;
//         for (int i = 1; i <= n; i++) {
//             if (i > x && i <= y) b.push_back(a[i]);
//             else c.push_back(a[i]);
//         }
//         unsigned int id = 0;
//         for (int i = 1; i < b.size(); i++) if (b[i] < b[id]) id = i;
//         unsigned int t = 0;
//         while (t < c.size() && c[t] < b[id]) {
//             std::cout << c[t] << " ";
//             t++;
//         }
//         for (unsigned i = id, j = 1; j <= b.size(); j++, i = (i + 1) % b.size()) {
//             std::cout << b[i] << " ";
//         }
//         for (; t < c.size(); t++) std::cout << c[t] << " ";
//         std::cout << "\n";
//     }
//     return 0;
// }

// 4. https://codeforces.com/contest/2200/problem/E
// #include <bits/stdc++.h>
// constexpr int N = 1e6 + 1;
//
// int primes[N], vis[N], cnt;
// void euler() {
//     for (int i = 2; i < N; i++) {
//         if (!vis[i]) primes[cnt++] = i;
//         for (int j = 0; 1LL * primes[j] * i < N; j++) {
//             vis[primes[j] * i] = 1;
//             if (i % primes[j] == 0) break;
//         }
//     }
// }
//
// signed main() {
//     euler();
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n;
//         std::cin >> n;
//         std::vector<int> a(n + 1);
//         for (int i = 1; i <= n; i++) std::cin >> a[i];
//         int mi = 1e9;
//         bool is_alice = false;
//         if (std::is_sorted(a.begin() + 1, a.end())) {
//             std::cout << "Bob\n";
//             continue;
//         }
//         for (int i = n; i >= 1; i--) {
//             int mx = 0;
//             if (!vis[a[i]]) {
//                 mi = std::min(mi, a[i]);
//                 mx = std::max(mx, a[i]);
//             } else {
//                 for (int j = 0; j < cnt && primes[j] <= a[i]; j++) {
//                     if (a[i] % primes[j] == 0) {
//                         mi = std::min(mi, primes[j]);
//                         mx = std::max(mx, primes[j]);
//                         while (a[i] % primes[j] == 0) a[i] /= primes[j];
//                     }
//                 }
//             }
//             if (mx > mi) {
//                 is_alice = true;
//                 break;
//             }
//         }
//         if (is_alice) std::cout << "Alice\n";
//         else std::cout << "Bob\n";
//     }
//     return 0;
// }

// 5. https://codeforces.com/contest/2200/problem/F
// #include <bits/stdc++.h>
// #define int long long
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n, m;
//         std::cin >> n >> m;
//         std::vector<std::pair<int, int>> a(n);
//         for (int i = 0; i < n; i++) std::cin >> a[i].second >> a[i].first;
//         std::sort(a.rbegin(), a.rend());
//         std::multiset<int> s;
//         int sum = 0, mx = 0;
//         std::vector<int> pre(n + 1);
//         for (int k = n, id = 0; k >= 0; k--) {
//             while (id < n && a[id].first >= k) {
//                 sum += a[id].second;
//                 s.insert(a[id].second);
//                 id++;
//             }
//             while (s.size() > k + 1) {
//                 sum -= *s.begin();
//                 s.erase(s.begin());
//             }
//             mx = std::max(mx, sum);
//             pre[k] = s.size() < k + 1 ? sum : sum - *s.begin();
//         }
//         for (int i = 1; i <= n; i++) pre[i] = std::max(pre[i], pre[i - 1]);
//         while (m--) {
//             int x, y;
//             std::cin >> x >> y;
//             std::cout << std::max(mx, pre[y] + x) << " ";
//         }
//         std::cout << "\n";
//     }
//     return 0;
// }

// 6. https://pintia.cn/problem-sets/1905921897702723584/exam/problems/type/7?problemSetProblemId=1905921897736278022
// #include <bits/stdc++.h>
//
// signed main() {
//     std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
//     int n;
//     std::cin >> n;
//     std::unordered_map<std::string, std::string> mp;
//     for (int i = 0; i < n; i++) {
//         std::string s1, s2;
//         std::cin >> s1 >> s2;
//         mp[s1] = s2;
//         mp[s2] = s1;
//     }
//     int m;
//     std::cin >> m;
//     std::vector<std::string> a(m + 1);
//     std::unordered_map<std::string, int> pos;
//     for (int i = 1; i <= m; i++) {
//         std::cin >> a[i];
//         pos[a[i]] = i;
//     }
//     std::vector<int> sum(m + 2), cha(m + 2);
//     for (int i = 1; i <= m; i++) {
//         if (mp.find(a[i]) != mp.end() && pos.find(mp[a[i]]) != pos.end()) {
//             if (std::abs(i - pos[mp[a[i]]]) == 1) {
//                 cha[std::min(i, pos[mp[a[i]]]) - 1] += 1;
//                 cha[std::max(i, pos[mp[a[i]]]) + 1] += 1;
//             } else {
//                 sum[std::min(i, pos[mp[a[i]]]) + 1] += 1;
//                 sum[std::max(i, pos[mp[a[i]]])] -= 1;
//             }
//         }
//     }
//     std::vector<int> ans(m + 2);
//     for (int i = 1; i <= m; i++) {
//         sum[i] += sum[i - 1];
//         ans[i] = sum[i] + cha[i];
//     }
//     int mx = -1;
//     for (int i = 1; i <= m; i++)
//         if (mp.find(a[i]) == mp.end() || pos.find(mp[a[i]]) == pos.end())
//             mx = std::max(mx, ans[i]);
//     std::vector<std::string> ans_vec;
//     for (int i = 1; i <= m; i++) {
//         if (mx == ans[i] && (mp.find(a[i]) == mp.end() || pos.find(mp[a[i]]) == pos.end()))
//             ans_vec.push_back(a[i]);
//     }
//     std::sort(ans_vec.begin(), ans_vec.end());
//     for (std::string& i : ans_vec) {
//         std::cout << i << " \n"[&i == &ans_vec.back()];
//     }
//     return 0;
// }

// 7. https://codeforces.com/contest/2200/problem/G
// #include <bits/stdc++.h>
// #define int long long
// constexpr int mod = 1e9 + 7;
//
// int ksm(int a, int k) {
//     int res = 1;
//     while (k) {
//         if (k & 1) res = res * a % mod;
//         k >>= 1;
//         a = a * a % mod;
//     }
//     return res;
// }
//
// int inv(const int a) {
//     return ksm(a, mod - 2);
// }
//
// int fact[4000];
//
// signed main() {
//     fact[0] = 1;
//     for (int i = 1; i <= 3100; i++) fact[i] = fact[i - 1] * i % mod;
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n, x;
//         std::cin >> n >> x;
//         std::vector<int> ji = {0};
//         int sum = 0;
//         for (int i = 0; i < n; i++) {
//             std::string s;
//             std::cin >> s;
//             if (s[0] == '+') sum += std::stoll(s.substr(1));
//             else if (s[0] == '-') sum += mod + std::stoll(s);
//             else if (s[0] == '/') ji.push_back(inv(std::stoll(s.substr(1))));
//             else ji.push_back(std::stoll(s.substr(1)));
//             sum %= mod;
//         }
//         const unsigned m = ji.size() - 1;
//         std::vector<int> dp(m + 1);
//         dp[0] = 1;
//         for (int i = 1; i <= m; i++) {
//             for (int j = i; j >= 1; j--) {
//                 dp[j] += ji[i] * dp[j - 1] % mod;
//                 dp[j] %= mod;
//             }
//         }
//         int s = 0;
//         for (int i = 0; i <= m; i++) {
//             s += dp[i] % mod * inv(fact[m]) % mod * fact[i] % mod * fact[m - i] % mod;
//             s %= mod;
//         }
//         s = s * inv(m + 1) % mod;
//         x = x * dp[m] % mod;
//         int ans = sum * s % mod + x;
//         ans %= mod;
//         std::cout << ans << "\n";
//     }
//     return 0;
// }

// 8. https://www.luogu.com.cn/problem/P12874
// #include <bits/stdc++.h>
// #define int long long
//
// signed main() {
//     int n, k;
//     std::cin >> n >> k;
//     std::vector<std::vector<std::pair<int, int>>> g(n + 1);
//     for (int i = 1, u, v, w; i < n; i++) {
//         std::cin >> u >> v >> w;
//         g[u].emplace_back(v, w);
//         g[v].emplace_back(u, w);
//     }
//     int ans = 0;
//     std::vector<bool> vis(n + 1);
//     auto dfs = [&](auto&& self, const int st, const int cnt, const int sum) -> void {
//         if (cnt == k) ans += sum;
//         else {
//             for (const auto& [v, w] : g[st]) {
//                 if (!vis[v]) {
//                     vis[v] = true;
//                     self(self, v, cnt + 1, sum + w);
//                     vis[v] = false;
//                 }
//             }
//         }
//     };
//     for (int i = 1; i <= n; i++) {
//         vis[i] = true;
//         dfs(dfs, i, 0, 0);
//         vis[i] = false;
//     }
//     std::cout << ans << "\n";
//     return 0;
// }

// 9.
// #include <bits/stdc++.h>
//
// signed main() {
//     int n;
//     std::cin >> n;
//     std::vector<int> a(n + 1);
//     for (int i = 1; i <= n; i++) std::cin >> a[i];
//     std::vector<int> b(n + 1);
//     int t = 1;
//     auto dfs = [&](auto&& self, const int u) -> void {
//         if (u << 1 <= n) self(self, u << 1);
//         if ((u << 1 | 1) <= n) self(self, u << 1 | 1);
//         b[u] = a[t++];
//     };
//     dfs(dfs, 1);
//     std::queue<int> q;
//     q.push(1);
//     while (!q.empty()) {
//         t = q.front();
//         q.pop();
//         std::cout << b[t] << " ";
//         if (t << 1 <= n) q.push(t << 1);
//         if ((t << 1 | 1) <= n) q.push(t << 1 | 1);
//     }
//     return 0;
// }

// 10. https://codeforces.com/contest/2205/problem/D
// #include <bits/stdc++.h>
//
// class SegTree {
// public:
//     struct node {
//         int l, r, mx;
//     };
//
//     explicit SegTree(const std::vector<int>& vec) : tr(vec.size() << 2) {
//         build(vec, 1, 1, vec.size() - 1);
//     }
//
//     void pushup(const int u) {
//         tr[u].mx = std::max(tr[u << 1].mx, tr[u << 1 | 1].mx);
//     }
//
//     void build(const std::vector<int>& vec, const int u, const int l, const int r) {
//         tr[u] = {l, r};
//         if (l == r) {
//             tr[u].mx = vec[l];
//             return;
//         }
//         const int mid = (l + r) >> 1;
//         build(vec, u << 1, l, mid), build(vec, u << 1 | 1, mid + 1, r);
//         pushup(u);
//     }
//
//     int query(const int l, const int r) {
//         return query(1, l, r);
//     }
//
//     int query(const int u, const int l, const int r) {
//         if (l <= tr[u].l && tr[u].r <= r) return tr[u].mx;
//         const int mid = (tr[u].l + tr[u].r) >> 1;
//         if (r <= mid) return query(u << 1, l, r);
//         if (l > mid) return query(u << 1 | 1, l, r);
//         return std::max(query(u << 1, l, mid), query(u << 1 | 1, mid + 1, r));
//     }
//
// private:
//     std::vector<node> tr;
// };
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n;
//         std::cin >> n;
//         std::vector<int> a(n + 1);
//         for (int i = 1; i <= n; i++) std::cin >> a[i];
//         std::vector<int> mp(n + 1);
//         for (int i = 1; i <= n; i++) mp[a[i]] = i;
//         SegTree seg_tree(a);
//         int ans = 1e9;
//         auto dfs = [&](auto&& self, const int l, const int r, const int sum) -> void {
//             if (l + 1 == r) ans = std::min(ans, sum);
//             else {
//                 if (const int id = mp[seg_tree.query(l + 1, r - 1)]; id == l + 1 || id == r - 1) {
//                     if (id == l + 1) self(self, id, r, sum);
//                     else self(self, l, id, sum);
//                 } else {
//                     self(self, id, r, sum + id - l - 1);
//                     self(self, l, id, sum + r - id - 1);
//                 }
//             }
//         };
//         dfs(dfs, 0, n + 1, 0);
//         std::cout << ans << "\n";
//     }
//     return 0;
// }

// 11. https://pintia.cn/problem-sets/2030671300454481920/exam/problems/type/7?problemSetProblemId=2030671300483842061
// #include <bits/stdc++.h>
//
// signed main() {
//     int n;
//     std::cin >> n;
//     std::vector<int> a(n + 1);
//     for (int i = 1; i <= n; i++) std::cin >> a[i];
//     std::vector sum(n + 1, std::vector<int>(n + 1));
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j < i; j++) {
//             if (a[j] > a[i]) sum[i][j] = 1;
//         }
//     }
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j < i; j++)
//             sum[i][j] += sum[i][j - 1];
//
//     std::vector<int> b(n + 1);
//     for (int i = 1; i <= n; i++) {
//         b[i] = b[i - 1] + sum[i][i - 1];
//     }
//     for (int i = 1; i <= n; i++) {
//         int s = 0;
//         for (int j = i; j <= n; j++) {
//             s += sum[j][i - 1];
//             const int t = b[j] - b[i - 1] - s;
//             std::cout << b[n] + (j - i + 1) * (j - i) / 2 - 2 * t << " \n"[i == n && j == n];
//         }
//     }
//     return 0;
// }

// 12. https://pintia.cn/problem-sets/2030671300454481920/exam/problems/type/7?problemSetProblemId=2030671300483842060
// #include <bits/stdc++.h>
//
// signed main() {
//     std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
//     int n, m, s, t;
//     std::cin >> n >> m >> s >> t;
//     std::vector<int> a(n + 1);
//     for (int i = 1; i <= n; i++) std::cin >> a[i];
//     a[t] = 0;
//     std::vector<std::vector<std::pair<int, int>>> g(n + 1);
//     for (int i = 0, u, v, w; i < m; i++) {
//         std::cin >> u >> v >> w;
//         g[u].emplace_back(w, v);
//         g[v].emplace_back(w, u);
//     }
//
//     std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, std::greater<>> q;
//     q.push({0, 0, s});
//     std::vector<int> vis(n + 1);
//     while (!q.empty()) {
//         const auto [w, mx, u] = q.top();
//         q.pop();
//         if (vis[u]) continue;
//         vis[u] = 1;
//         if (u == t) {
//             std::cout << w << " " << mx << "\n";
//             return 0;
//         }
//         for (const auto& [w_, v] : g[u]) {
//             if (!vis[v]) {
//                 q.push({w_ + w, std::max(mx, a[v]), v});
//             }
//         }
//     }
//     std::cout << "Impossible\n";
//     return 0;
// }

// 13. https://codeforces.com/contest/2207/problem/B
// #include <bits/stdc++.h>
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n, m, l;
//         std::cin >> n >> m >> l;
//         std::vector<int> a(n + 1);
//         for (int i = 1; i <= n; i++) std::cin >> a[i];
//         int t = 1;
//         std::multiset<int> s;
//         for (int i = 1; i <= n; i++) {
//             while (s.size() > n - i + 2) s.erase(s.begin());
//             while (t <= a[i]) {
//                 t++;
//                 if (s.size() < n - i + 2 && s.size() < m) s.insert(1);
//                 else {
//                     auto it = s.begin();
//                     s.erase(it);
//                     s.insert(*it + 1);
//                 }
//             }
//             s.erase(s.find(*s.rbegin()));
//             s.insert(0);
//         }
//         int mx = *s.rbegin() + l - a[n];
//         std::cout << mx << "\n";
//     }
//     return 0;
// }

// 14. https://codeforces.com/contest/2207/problem/C
// 看了题解，发现我这方法和题解思路一样，但是我的好蠢，最大值边枚举就可以边算，根本不需要线段树。。。
// #include <bits/stdc++.h>
// #define int long long
//
// class SegTree {
// public:
//     struct node {
//         int l, r, mx, mx_id;
//     };
//
//     explicit SegTree(const std::vector<int>& vec) : tr(vec.size() << 2) {
//         build(vec, 1, 1, vec.size() - 1);
//     }
//
//     void pushup(const int u) {
//         if (tr[u << 1].mx > tr[u << 1 | 1].mx) tr[u].mx_id = tr[u << 1].mx_id;
//         else tr[u].mx_id = tr[u << 1 | 1].mx_id;
//         tr[u].mx = std::max(tr[u << 1].mx, tr[u << 1 | 1].mx);
//     }
//
//     static void pushup(node& root, node&& left, node&& right) {
//         if (left.mx > right.mx) root.mx_id = left.mx_id;
//         else root.mx_id = right.mx_id;
//         root.mx = std::max(left.mx, right.mx);
//     }
//
//     void build(const std::vector<int>& vec, const int u, const int l, const int r) {
//         tr[u] = {l, r};
//         if (l == r) {
//             tr[u].mx = vec[l];
//             tr[u].mx_id = l;
//             return;
//         }
//         const int mid = (l + r) >> 1;
//         build(vec, u << 1, l, mid), build(vec, u << 1 | 1, mid + 1, r);
//         pushup(u);
//     }
//
//     node query(const int l, const int r) {
//         return query(1, l, r);
//     }
//
//     node query(const int u, const int l, const int r) {
//         if (l <= tr[u].l && tr[u].r <= r) return tr[u];
//         const int mid = (tr[u].l + tr[u].r) >> 1;
//         if (r <= mid) return query(u << 1, l, r);
//         if (l > mid) return query(u << 1 | 1, l, r);
//         node res;
//         pushup(res, query(u << 1, l, mid), query(u << 1 | 1, mid + 1, r));
//         return res;
//     }
//
// private:
//     std::vector<node> tr;
// };
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n, h;
//         std::cin >> n >> h;
//         std::vector<int> a(n + 1);
//         for (int i = 1; i <= n; i++) std::cin >> a[i];
//         SegTree seg_tree(a);
//         std::vector<int> dp(n + 1);
//         for (int i = 1; i <= n; i++) {
//             int mx = a[i];
//             dp[i] += h - mx;
//             for (int j = i - 1; j >= 1; j--) {
//                 mx = std::max(mx, a[j]);
//                 dp[i] += h - mx;
//             }
//             mx = a[i];
//             for (int j = i + 1; j <= n; j++) {
//                 mx = std::max(mx, a[j]);
//                 dp[i] += h - mx;
//             }
//         }
//         int ans = 0;
//         for (int i = 1; i <= n; i++) {
//             for (int j = i + 1; j <= n; j++) {
//                 const int mx_id = seg_tree.query(i, j).mx_id;
//                 ans = std::max(ans, dp[i] + dp[j] - dp[mx_id]);
//             }
//         }
//         if (n == 1) ans = h - a[1];
//         std::cout << ans << "\n";
//     }
//     return 0;
// }

// 15. https://codeforces.com/gym/106416/problem/B
// #include <bits/stdc++.h>
//
// signed main() {
//     int n;
//     std::cin >> n;
//     std::vector<int> a(n + 1);
//     for (int i = 1; i <= n; i++) std::cin >> a[i];
//     std::set<std::pair<int, int>> s;
//     for (int i = 1; i <= n; i++) s.insert({a[i], i});
//     std::vector<std::pair<int, int>> ans;
//     while (true) {
//         const auto st = *s.begin();
//         const auto ed = *s.rbegin();
//         if (ed.first - st.first <= 1) break;
//         s.erase(s.begin());
//         s.erase(std::prev(s.end()));
//         const int x1 = (st.first + ed.first) >> 1;
//         const int x2 = (st.first + ed.first + 1) >> 1;
//         a[st.second] = x1, a[ed.second] = x2;
//         s.insert({x1, st.second});
//         s.insert({x2, ed.second});
//         ans.emplace_back(st.second, ed.second);
//     }
//     int t = 0;
//     for (int i = 1; i <= n; i++) t += a[i];
//     t /= n;
//     int l = 1, r = n;
//     while (l < r) {
//         while (l <= n && a[l] != t + 1) l++;
//         while (r >= 1 && a[r] != t) r--;
//         if (l < r) {
//             std::swap(a[l], a[r]);
//             ans.emplace_back(l, r);
//         }
//     }
//     std::cout << ans.size() << "\n";
//     for (const auto& [x, y] : ans) {
//         std::cout << x << " " << y << "\n";
//     }
//     return 0;
// }

// 16. https://codeforces.com/contest/2188/problem/D
// #include <bits/stdc++.h>
// #define int long long
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int x, y;
//         std::cin >> x >> y;
//         int p = 0, q = 0, mi = 1e18;
//         auto update = [&](const int _p, const int _q) -> void {
//             if ((_p & _q) == 0 && std::abs(_p - x) + std::abs(_q - y) < mi) {
//                 mi = std::abs(_p - x) + std::abs(_q - y);
//                 p = _p, q = _q;
//             }
//         };
//         update(x, y);
//         for (int i = 29; i >= 0; i--) {
//             if ((x & y) >> i & 1) {
//                 update((x >> i << i) + (1LL << i), y);
//                 update(x, (y >> i << i) + (1LL << i));
//                 update(x >> i << i, (y >> i << i) - 1);
//                 update((x >> i << i) - 1, y >> i << i);
//                 break;
//             }
//         }
//         std::cout << p << " " << q << "\n";
//     }
//     return 0;
// }

// 17. https://codeforces.com/contest/2208/problem/A
// #include <bits/stdc++.h>
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n;
//         std::cin >> n;
//         std::unordered_map<int, int> mp;
//         for (int i = 1, x; i <= n * n; i++) {
//             std::cin >> x;
//             mp[x] ++;
//         }
//         int mx = 0;
//         for (const auto& [x, cnt] : mp) {
//             mx = std::max(mx, cnt);
//         }
//         if (mx <= n * (n - 1)) std::cout << "Yes\n";
//         else std::cout << "No\n";
//     }
//     return 0;
// }

// 18. https://codeforces.com/contest/2208/problem/B
// #include <bits/stdc++.h>
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n, k, p, m;
//         std::cin >> n >> k >> p >> m;
//         std::vector<int> a(n + 1);
//         for (int i = 1; i <= n; i++) std::cin >> a[i];
//         std::multiset<int> q;
//         for (int i = 1; i <= k; i++) q.insert(a[i]);
//         int ans = 0;
//         if (a[p] > m) {
//             std::cout << 0 << "\n";
//             continue;
//         }
//         if (p <= k) {
//             ans++;
//             m -= a[p];
//             q.erase(q.find(a[p]));
//             a.emplace_back(a[p]);
//             p = a.size() - 1;
//             k++;
//             while (k == p && m >= a[p]) {
//                 ans++;
//                 m -= a[p];
//                 a.emplace_back(a[p]);
//                 p = a.size() - 1;
//                 k++;
//             }
//             q.insert(a[k]);
//         }
//         while (m >= a[p]) {
//             int t = *q.begin();
//             if (t > m) break;
//             m -= t;
//             q.erase(q.begin());
//             a.emplace_back(t);
//             k++;
//             if (k == p) {
//                 if (m < a[p]) break;
//                 while (k == p && m >= a[p]) {
//                     ans++;
//                     m -= a[p];
//                     a.emplace_back(a[p]);
//                     p = a.size() - 1;
//                     k++;
//                     q.insert(a[k]);
//                 }
//             } else {
//                 q.insert(a[k]);
//             }
//         }
//         std::cout << ans << "\n";
//     }
//     return 0;
// }

// 2026.3.16 Educational Codeforces Round 188 (Rated for Div. 2)
// 19. A
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
//         s = " " + s;
//         int t = 1;
//         while (t <= n && s[t] == 'R') t++;
//         std::cout << std::min(n, t) << "\n";
//     }
//     return 0;
// }

// 20. B
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
//         std::vector<int> mx(n + 1);
//         for (int i = 1; i <= n; i++) mx[i] = std::max(mx[i - 1], a[i]);
//         int ans = 0;
//         while (n > 0) {
//             int m = mx[n];
//             while (n >= 1 && a[n] != m) n--;
//             ans++;
//             n--;
//         }
//         std::cout << ans << "\n";
//     }
//     return 0;
// }

// 21. C
// #include <bits/stdc++.h>
// #define int long long
//
// int get_ans(int a, int b, int c, int m) {
//     int lcm_abc = std::lcm(a, std::lcm(b, c));
//     int t3 = m / lcm_abc;
//     int lcm_ab = std::lcm(a, b);
//     int lcm_ac = std::lcm(a, c);
//     int t2 = m / lcm_ab + m / lcm_ac - 2 * t3;
//     int t1 = m / a - t2 - t3;
//     return 6 * t1 + 3 * t2 + 2 * t3;
// }
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int a, b, c, m;
//         std::cin >> a >> b >> c >> m;
//         std::cout << get_ans(a, b, c, m) << " ";
//         std::cout << get_ans(b, a, c, m) << " ";
//         std::cout << get_ans(c, a, b, m) << "\n";
//     }
//     return 0;
// }

// 22. D
// #include <bits/stdc++.h>
// #define int long long
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n, m;
//         std::cin >> n >> m;
//         std::vector<std::vector<int>> g(n + 1);
//         for (int i = 1, u, v; i <= m; i++) {
//             std::cin >> u >> v;
//             g[u].emplace_back(v);
//             g[v].emplace_back(u);
//         }
//         std::vector<int> vis(n + 1);
//         int ans = 0;
//         for (int i = 1; i <= n; i++) {
//             if (g[i].empty()) {
//                 ans++;
//                 vis[i] = 1;
//             }
//         }
//         std::vector<int> cnt(n + 1);
//         auto dfs = [&](auto&& self, const int u, const int ji) -> void {
//             vis[u] = 1;
//             for (const auto v : g[u]) {
//                 cnt[u] += ji;
//                 cnt[v] += ji ^ 1;
//                 if (!vis[v]) {
//                     self(self, v, ji ^ 1);
//                 }
//             }
//         };
//         auto dfs2 = [&](auto&& self, const int u, int& c, int& cn) -> void {
//             vis[u] = 2;
//             cn++;
//             if (cnt[u] != 0 && cnt[u] != 2 * g[u].size()) c = -1;
//             if (c == -1) return;
//             if (cnt[u] == 0) c++;
//             for (const auto v : g[u]) {
//                 if (vis[v] != 2) {
//                     self(self, v, c, cn);
//                 }
//             }
//         };
//         for (int i = 1; i <= n; i++) {
//             if (!vis[i]) {
//                 dfs(dfs, i, 1);
//                 int c = 0, cn = 0;
//                 dfs2(dfs2, i, c, cn);
//                 if (c != -1) ans += std::max(c, cn - c);
//             }
//         }
//         std::cout << ans << "\n";
//     }
//     return 0;
// }

// 23. https://codeforces.com/contest/2208/problem/C
// #include <bits/stdc++.h>
// #define double long double
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n;
//         std::cin >> n;
//         std::vector<double> c(n + 1), p(n + 1);
//         for (int i = 1; i <= n; i++) std::cin >> c[i] >> p[i];
//         std::vector<double> dp(n + 2);
//         for (int i = n; i >= 1; i--) {
//             dp[i] = std::max(dp[i + 1], c[i] + dp[i + 1] * (1.0 - p[i] / 100));
//         }
//         std::cout << std::fixed << std::setprecision(10) << dp[1] << "\n";
//     }
//     return 0;
// }

// 24. https://codeforces.com/contest/2204/problem/E
// #include <bits/stdc++.h>
//
// int get(int n) {
//     int x = 0;
//     while (n) {
//         x += n % 10;
//         n /= 10;
//     }
//     return x;
// }
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         std::string s;
//         std::cin >> s;
//         if (s.size() == 1) {
//             std::cout << s << "\n";
//             continue;
//         }
//         int sum = 0;
//         std::vector<int> cnt(10);
//         for (const char c : s) {
//             sum += c - '0';
//             cnt[c - '0']++;
//         }
//         for (int i = 1; i <= sum; i++) {
//             int num = i;
//             std::string t = std::to_string(i);
//             while (std::to_string(num).size() > 1) {
//                 num = get(num);
//                 t += std::to_string(num);
//             }
//             int sum_ = sum;
//             bool can = true;
//             std::vector<int> cnt2(10);
//             for (const char c : t) {
//                 cnt2[c - '0']++;
//             }
//             for (int j = 0; j < 10; j++) {
//                 if (cnt[j] < cnt2[j]) {
//                     can = false;
//                     break;
//                 }
//                 sum_ -= j * cnt2[j];
//             }
//             if (can && sum_ == i) {
//                 std::string ans = "";
//                 for (int j = 9; j >= 0; j--) {
//                     for (int k = 0; k < cnt[j] - cnt2[j]; k++) {
//                         ans += std::to_string(j);
//                     }
//                 }
//                 ans += t;
//                 std::cout << ans << "\n";
//                 break;
//             }
//         }
//     }
//     return 0;
// }

// 2026.3.21   The 2024 ICPC Asia Hangzhou Regional Contest (The 3rd Universal Cup. Stage 25: Hangzhou)
// 25. https://codeforces.com/gym/105657/problem/A
// #include <bits/stdc++.h>
// #define int long long
//
// int fa[26];
//
// int find(int x) {
//     if (x != fa[x]) fa[x] = find(fa[x]);
//     return fa[x];
// }
//
// void merge(int x, int y) {
//     fa[find(x)] = find(y);
// }
//
// void solve() {
//     std::string s1, s2, s3;
//     std::cin >> s1 >> s2 >> s3;
//     if (s1.size() != s2.size()) {
//         std::cout << "NO\n";
//         return;
//     }
//     if (s1.size() != s3.size()) {
//         std::cout << "YES\n";
//         return;
//     }
//     for (int i = 0; i < 26; i++) fa[i] = i;
//     for (int i = 0; i < s1.size(); i++) {
//         merge(s1[i] - 'a', s2[i] - 'a');
//     }
//     for (int i = 0; i < s1.size(); i++) {
//         if (find(s3[i] - 'a') != find(s1[i] - 'a')) {
//             std::cout << "YES\n";
//             return;
//         }
//     }
//     std::cout << "NO\n";
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

// 26. https://www.luogu.com.cn/problem/P3372
// #include <bits/stdc++.h>
// #define int long long
//
// class BIT {
// public:
//     BIT(std::vector<int>& a) : tr(a), n(a.size()) {
//         for (int i = 1; i < n; i++) {
//             int j = i + (i & -i);
//             if (j < n) tr[j] += tr[i];
//         }
//     }
//
//     void update(int x, const int v) {
//         for (; x < n; x += x & -x) {
//             tr[x] += v;
//         }
//     }
//
//     [[nodiscard]] int query(int x) const {
//         int res = 0;
//         for (; x; x -= x & -x) {
//             res += tr[x];
//         }
//         return res;
//     }
//
//     [[nodiscard]] int query(const int l, const int r) const {
//         return query(r) - query(l - 1);
//     }
// private:
//     std::vector<int> tr;
//     size_t n;
// };
//
// signed main() {
//     int n, m;
//     std::cin >> n >> m;
//     std::vector<int> a(n + 1);
//     for (int i = 1; i <= n; i++) std::cin >> a[i];
//     for (int i = n; i >= 1; i--) a[i] -= a[i - 1];
//     BIT tr1(a);
//     for (int i = 1; i <= n; i++) a[i] = a[i] * i;
//     BIT tr2(a);
//     while (m--) {
//         int op;
//         std::cin >> op;
//         if (op == 1) {
//             int x, y, k;
//             std::cin >> x >> y >> k;
//             tr1.update(x, k), tr1.update(y + 1, -k);
//             tr2.update(x, k * x), tr2.update(y + 1, -k * (y + 1));
//         } else {
//             int x, y;
//             std::cin >> x >> y;
//             std::cout << (y + 1) * tr1.query(y) - tr2.query(y) - (x * tr1.query(x - 1) - tr2.query(x - 1)) << "\n";
//         }
//     }
//     return 0;
// }

// 27. https://www.luogu.com.cn/problem/P4514
// #include <bits/stdc++.h>
// #define int long long
//
// class BIT {
// public:
//     explicit BIT(const std::vector<std::vector<int>>& a) : tr(a), n(a.size()), m(a[0].size()) { }
//
//     void update(int x, int y, const int v) {
//         for (; x < n; x += x & -x) {
//             for (int j = y; j < m; j += j & -j) {
//                 tr[x][j] += v;
//             }
//         }
//     }
//
//     [[nodiscard]] int query(int x, int y) const {
//         int res = 0;
//         for (; x; x -= x & -x) {
//             for (int j = y; j; j -= j & -j) {
//                 res += tr[x][j];
//             }
//         }
//         return res;
//     }
//
// private:
//     std::vector<std::vector<int>> tr;
//     size_t n;
//     size_t m;
// };
//
// signed main() {
//     char cha;
//     int n, m;
//     std::cin >> cha >> n >> m;
//     const std::vector x(n + 1, std::vector<int>(m + 1));
//     BIT bit0(x), bit1(x), bit2(x), bit3(x);
//     auto sum = [&](const int x_, const int y) -> int {
//         return (x_ + 1) * (y + 1) * bit0.query(x_, y) - (x_ + 1) * bit2.query(x_, y) -
//             (y + 1) * bit1.query(x_, y) + bit3.query(x_, y);
//     };
//     while (std::cin >> cha) {
//         if (cha == 'L') {
//             int a, b, c, d, delta;
//             std::cin >> a >> b >> c >> d >> delta;
//             bit0.update(a, b, delta);
//             bit0.update(a, d + 1, -delta);
//             bit0.update(c + 1, b, -delta);
//             bit0.update(c + 1, d + 1, delta);
//
//             bit1.update(a, b, a * delta);
//             bit1.update(a, d + 1, -a * delta);
//             bit1.update(c + 1, b, -(c + 1) * delta);
//             bit1.update(c + 1, d + 1, (c + 1) * delta);
//
//             bit2.update(a, b, b * delta);
//             bit2.update(a, d + 1, -(d + 1) * delta);
//             bit2.update(c + 1, b, -b * delta);
//             bit2.update(c + 1, d + 1, (d + 1) * delta);
//
//             bit3.update(a, b, a * b * delta);
//             bit3.update(a, d + 1, -a * (d + 1) * delta);
//             bit3.update(c + 1, b, -(c + 1) * b * delta);
//             bit3.update(c + 1, d + 1, (c + 1) * (d + 1) * delta);
//         } else {
//             int a, b, c, d;
//             std::cin >> a >> b >> c >> d;
//             std::cout << sum(c, d) - sum(a - 1, d) - sum(c, b - 1) + sum(a - 1, b - 1) << "\n";
//         }
//     }
//     return 0;
// }

// 2026.3.22   努力刷题！！！今天开始！！！
// 28. https://codeforces.com/gym/105657/problem/K
// #include <bits/stdc++.h>
//
// void solve() {
//     int n, m, k;
//     std::cin >> n >> m >> k;
//     std::unordered_map<int, int> mp;
//     std::vector<int> p(n * m + 1);
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= m; j++) {
//             std::cin >> p[(i - 1) * m + j];
//             mp[(i - 1) * m + j] = i;
//         }
//     }
//     std::vector<int> a(n + 1);
//     int ans = 0, mx = 0;
//     while (true) {
//         const int t = ++a[mp[p[ans + 1]]];
//         mx = std::max(mx, t);
//         ans++;
//         const int shen = std::min(k, ans - t);
//         if (t >= m - shen) break;
//         if (mx >= m - std::min(k, ans - mx)) break;
//     }
//     std::cout << ans << "\n";
// }
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) solve();
//     return 0;
// }

// 29. https://codeforces.com/gym/105657/problem/M
// #include <bits/stdc++.h>
// #define int long long
// constexpr int N = 5e4 + 10;
//
// int st[N];
//
// void solve() {
//     int n, k;
//     std::cin >> n >> k;
//     std::vector<int> a(n + 1);
//     for (int i = 1; i <= n; i++) std::cin >> a[i];
//     int mi = *std::min_element(a.begin() + 1, a.end());
//     int g = 0;
//     for (int i = 2; i <= n; i++) g = std::gcd(g, a[i] - a[i - 1]);
//     if (g == 0) {
//         std::cout << k << " " << k * (k + 1) / 2 << "\n";
//         return;
//     }
//     auto check = [&](const int x) -> bool {
//         int top = 0;
//         for (int i = 1; i <= n; i++) {
//             while (top && st[top - 1] > a[i] + x) {
//                 if (st[top - 1] % (a[i] + x) != 0) return false;
//                 top--;
//             }
//             if (top && (a[i] + x) % st[top - 1] != 0) return false;
//             st[top++] = a[i] + x;
//         }
//         return true;
//     };
//     int cnt = 0, sum = 0;
//     for (int i = 1; i * i <= g; i++) {
//         if (g % i == 0) {
//             if (i - mi >= 1 && i - mi <= k && check(i - mi)) {
//                 cnt++;
//                 sum += i - mi;
//             }
//             const int z = g / i;
//             if (z != i && z - mi >= 1 && z - mi <= k && check(z - mi)) {
//                 cnt++;
//                 sum += z - mi;
//             }
//         }
//     }
//     std::cout << cnt << " " << sum << "\n";
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

// 30. https://www.luogu.com.cn/problem/P5854
// #include <bits/stdc++.h>
// const int N = 1e7 + 5;
// #define int long long
//
// struct node {
//     int l, r;
// };
//
// int stk[N], top;
//
// signed main() {
//     std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
//     int n;
//     std::cin >> n;
//     std::vector<int> a(n + 1);
//     for (int i = 1; i <= n; i++) std::cin >> a[i];
//     std::vector<node> tr(n + 1);
//
//     for (int i = 1; i <= n; i++) {
//         int cur = top;
//         while (cur && a[stk[cur]] > a[i]) cur--;
//         if (cur) tr[stk[cur]].r = i;
//         if (cur < top) tr[i].l = stk[cur + 1];
//         top = cur + 1;
//         stk[top] = i;
//     }
//
//     int ans1 = 0, ans2 = 0;
//     for (int i = 1; i <= n; i++) {
//         ans1 ^= i * (tr[i].l + 1);
//         ans2 ^= i * (tr[i].r + 1);
//     }
//     std::cout << ans1 << " " << ans2 << "\n";
//     return 0;
// }

// 31. https://www.luogu.com.cn/problem/P1377   笛卡尔树
// #include <bits/stdc++.h>
// constexpr int N = 1e5 + 10;
//
// int stk[N], top;
//
// struct node {
//     int l, r;
// };
//
// signed main() {
//     int n;
//     std::cin >> n;
//     std::vector<int> a(n + 1);
//     for (int i = 1; i <= n; i++) std::cin >> a[i];
//     std::vector<int> b(n + 1);
//     for (int i = 1; i <= n; i++) b[a[i]] = i;
//     std::vector<node> tr(n + 1);
//     for (int i = 1; i <= n; i++) {
//         int cur = top;
//         while (cur && b[stk[cur]] > b[i]) cur--;
//         if (cur) tr[stk[cur]].r = i;
//         if (top > cur) tr[i].l = stk[cur + 1];
//         top = cur + 1;
//         stk[top] = i;
//     }
//     // auto dfs = [&](auto&& self, const int x) -> void {
//     //     if (!x) return;
//     //     std::cout << x << " ";
//     //     self(self, tr[x].l);
//     //     self(self, tr[x].r);
//     // };
//     // dfs(dfs, stk[1]);
//     top = 1;
//     while (top) {
//         const int t = stk[top--];
//         std::cout << t << " ";
//         if (tr[t].r) stk[++top] = tr[t].r;
//         if (tr[t].l) stk[++top] = tr[t].l;
//     }
//     return 0;
// }

// 32. https://atcoder.jp/contests/abc450/tasks/abc450_d
// #include <bits/stdc++.h>
// #define int long long
//
// signed main() {
//     int n, k;
//     std::cin >> n >> k;
//     std::vector<int> a(n + 1);
//     for (int i = 1; i <= n; i++) std::cin >> a[i], a[i] %= k;
//     std::sort(a.begin() + 1, a.end());
//     std::deque<int> q;
//     for (int i = 1; i <= n; i++) q.emplace_back(a[i]);
//     int ans = q.back() - q.front();
//     for (int i = 1; i <= n; i++) {
//         int t = q.front();
//         q.pop_front();
//         q.emplace_back(t + k);
//         ans = std::min(ans, q.back() - q.front());
//     }
//     std::cout << ans << "\n";
//     return 0;
// }

// 33. https://codeforces.com/problemset/problem/2209/C
// #include <bits/stdc++.h>
//
// int query(const int x, const int y) {
//     std::cout << "? " << x << " " << y << std::endl;
//     int res;
//     std::cin >> res;
//     return res;
// }
//
// void solve() {
//     int n;
//     std::cin >> n;
//     for (int i = 3; i <= 2 * n; i += 2) {
//         int c = query(i, i + 1);
//         if (c == 1) {
//             std::cout << "! " << i << std::endl;
//             return;
//         }
//     }
//     int c = query(1, 3);
//     if (c == 1) std::cout << "! 3" << std::endl;
//     else {
//         c = query(1, 4);
//         if (c == 1) std::cout << "! 4" << std::endl;
//         else std::cout << "! 2" << std::endl;
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

// 34. https://codeforces.com/problemset/problem/1748/E   笛卡尔树
// #include <bits/stdc++.h>
// #define int long long
// constexpr int N = 2e5 + 10, mod = 1e9 + 7;
//
// int stk[N], top;
//
// struct node {
//     int l, r;
// };
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n, m;
//         std::cin >> n >> m;
//         std::vector<int> a(n + 1);
//         for (int i = 1; i <= n; i++) std::cin >> a[i];
//         std::vector<node> tr(n + 1);
//         top = 0;
//         for (int i = 1, cur; i <= n; i++) {
//             cur = top;
//             while (cur && a[stk[cur]] < a[i]) cur--;
//             if (cur) tr[stk[cur]].r = i;
//             if (top > cur) tr[i].l = stk[cur + 1];
//             top = cur + 1;
//             stk[top] = i;
//         }
//         std::vector dp(n + 1, std::vector<int>(m + 1));
//         for (int i = 0; i <= m; i++) dp[0][i] = 1;
//         auto dfs = [&](auto&& self, const int x) -> void {
//             if (!x) return;
//             self(self, tr[x].l);
//             self(self, tr[x].r);
//             std::vector<int> tmp(m + 1);
//             for (int i = 1; i <= m; i++) {
//                 tmp[i] = dp[tr[x].l][i - 1] * dp[tr[x].r][i] % mod;
//             }
//             for (int i = 1; i <= m; i++) {
//                 dp[x][i] = (dp[x][i - 1] + tmp[i]) % mod;
//             }
//         };
//         dfs(dfs, stk[1]);
//         std::cout << dp[stk[1]][m] << "\n";
//     }
//     return 0;
// }

// 35. https://www.luogu.com.cn/problem/P6453   笛卡尔树
// #include <bits/stdc++.h>
// #define int long long
// constexpr int mod = 1e9 + 7, N = 550, M = 1e6 + 1;
//
// struct node {
//     int l, r;
// };
//
// int stk[N], top;
// int fac[M], inv[M];
//
// int ksm(int a, int k) {
//     int res = 1;
//     while (k) {
//         if (k & 1) res = res * a % mod;
//         a = a * a % mod;
//         k >>= 1;
//     }
//     return res;
// }
//
// void init() {
//     fac[0] = inv[0] = 1;
//     for (int i = 1; i < M; i++) fac[i] = fac[i - 1] * i % mod;
//     inv[M - 1] = ksm(fac[M - 1], mod - 2);
//     for (int i = M - 2; i >= 1; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
// }
//
// int C(const int n, const int m) {
//     if (n < m) return 0;
//     return fac[n] * inv[m] % mod * inv[n - m] % mod;
// }
//
// signed main() {
//     init();
//     int n, k;
//     std::cin >> n >> k;
//     std::vector<int> a(n + 1);
//     for (int i = 1; i <= n; i++) std::cin >> a[i];
//     std::vector<node> tr(n + 1);
//     for (int i = 1, cur; i <= n; i++) {
//         cur = top;
//         while (cur && a[stk[cur]] > a[i]) cur--;
//         if (cur) tr[stk[cur]].r = i;
//         if (top > cur) tr[i].l = stk[cur + 1];
//         top = cur + 1;
//         stk[top] = i;
//     }
//     std::vector dp(n + 1, std::vector<int>(k + 1));
//     dp[0][0] = 1;
//     std::vector<int> siz(n + 1);
//     auto dfs = [&](auto&& self, const int u, const int fa) -> void {
//         if (!u) return;
//         self(self, tr[u].l, u);
//         self(self, tr[u].r, u);
//         siz[u] = siz[tr[u].l] + siz[tr[u].r] + 1;
//         std::vector<int> tmp(k + 1);
//         for (int l = 0; l <= std::min(k, siz[tr[u].l]); l++) {
//             for (int r = 0; r <= std::min(k - l, siz[tr[u].r]); r++) {
//                 tmp[l + r] = (tmp[l + r] + dp[tr[u].l][l] * dp[tr[u].r][r] % mod) % mod;
//             }
//         }
//
//         for (int i = 0; i <= std::min(siz[u], k); i++) {
//             for (int j = 0; j <= i; j++) {
//                 dp[u][i] = (dp[u][i] + C(siz[u] - j, i - j) *
//                     C(a[u] - a[fa], i - j) % mod * fac[i - j] % mod * tmp[j] % mod) % mod;
//             }
//         }
//     };
//     dfs(dfs, stk[1], 0);
//     std::cout << dp[stk[1]][k] << "\n";
//     return 0;
// }

// 36. https://atcoder.jp/contests/abc450/tasks/abc450_e
// #include <bits/stdc++.h>
// #define int long long
//
// signed main() {
//     std::string s1, s2;
//     std::cin >> s1 >> s2;
//     std::vector cnt1(26, std::vector<int>(s1.size() + 1)), cnt2(26, std::vector<int>(s2.size() + 1));
//     for (int i = 0; i < 26; i++) {
//         for (int j = 1; j <= s1.size(); j++) {
//             cnt1[i][j] = cnt1[i][j - 1] + (s1[j - 1] - 'a' == i);
//         }
//     }
//     for (int i = 0; i < 26; i++) {
//         for (int j = 1; j <= s2.size(); j++) {
//             cnt2[i][j] = cnt2[i][j - 1] + (s2[j - 1] - 'a' == i);
//         }
//     }
//     std::vector<int> len(3);
//     len[1] = static_cast<int>(s1.size()), len[2] = static_cast<int>(s2.size());
//     for (int i = 2; ; i++) {
//         len.emplace_back(len[i - 1] + len[i]);
//         if (len.back() >= 1e18) break;
//     }
//     std::vector vis(len.size() + 1, std::vector<int>(26));
//     for (int i = 0; i < 26; i++) {
//         vis[1][i] = cnt1[i][s1.size()], vis[2][i] = cnt2[i][s2.size()];
//         for (int j = 3; j <= len.size(); j++) {
//             vis[j][i] = vis[j - 1][i] + vis[j - 2][i];
//         }
//     }
//     auto calc = [&](auto&& self, const int n, const int l, const int c) -> int {
//         if (l <= 0) return 0;
//         if (n == 1) return cnt1[c][l];
//         if (n == 2) return cnt2[c][l];
//         if (l >= len[n - 1]) return vis[n - 1][c] + self(self, n - 2, l - len[n - 1], c);
//         return self(self, n - 1, l, c);
//     };
//     int q;
//     std::cin >> q;
//     while (q--) {
//         int l, r;
//         char c_;
//         std::cin >> l >> r >> c_;
//         int c = c_ - 'a';
//         std::cout << calc(calc, len.size() - 1, r, c) - calc(calc, len.size() - 1, l - 1, c) << "\n";
//     }
//     return 0;
// }

// 37. https://atcoder.jp/contests/abc450/tasks/abc450_f
// #include <bits/stdc++.h>
// #define int long long
// constexpr int mod = 998244353;
//
// class SegTree {
// public:
//     struct node {
//         int l, r, x, lz;
//     };
//
//     explicit SegTree(const int n) : tr((n + 1) << 2) {
//         build(1, 1, n);
//     }
//
//     void build(const int u, const int l, const int r) {
//         tr[u] = {l, r, 0, 1};
//         if (l == r) return;
//         const int mid = (l + r) >> 1;
//         build(u << 1, l, mid);
//         build(u << 1 | 1, mid + 1, r);
//     }
//
//     void pushup(const int u) {
//         tr[u].x = (tr[u << 1].x + tr[u << 1 | 1].x) % mod;
//     }
//
//     void pushdown(const int u) {
//         if (tr[u].lz != 1) {
//             tr[u << 1].lz = tr[u << 1].lz * tr[u].lz % mod;
//             tr[u << 1 | 1].lz = tr[u << 1 | 1].lz * tr[u].lz % mod;
//             tr[u << 1].x = tr[u << 1].x * tr[u].lz % mod;
//             tr[u << 1 | 1].x = tr[u << 1 | 1].x * tr[u].lz % mod;
//             tr[u].lz = 1;
//         }
//     }
//
//     int query(const int u, const int l, const int r) {
//         if (l <= tr[u].l && tr[u].r <= r) return tr[u].x;
//         pushdown(u);
//         const int mid = (tr[u].l + tr[u].r) >> 1;
//         if (r <= mid) return query(u << 1, l, r);
//         if (l > mid) return query(u << 1 | 1, l, r);
//         return (query(u << 1, l, mid) + query(u << 1 | 1, mid + 1, r)) % mod;
//     }
//
//     void modify_x(const int u, const int l, const int r, const int x) {
//         if (r < l) return;
//         if (l <= tr[u].l && tr[u].r <= r) {
//             tr[u].x = tr[u].x * x % mod;
//             tr[u].lz = tr[u].lz * x % mod;
//             return;
//         }
//         pushdown(u);
//         const int mid = (tr[u].l + tr[u].r) >> 1;
//         if (r <= mid) modify_x(u << 1, l, r, x);
//         else if (l > mid) modify_x(u << 1 | 1, l, r, x);
//         else modify_x(u << 1, l, mid, x), modify_x(u << 1 | 1, mid + 1, r, x);
//         pushup(u);
//     }
//
//     void modify_add(const int u, const int p, const int x) {
//         if (tr[u].l == tr[u].r) {
//             tr[u].x = (tr[u].x + x) % mod;
//             return;
//         }
//         pushdown(u);
//         const int mid = (tr[u].l + tr[u].r) >> 1;
//         if (p <= mid) modify_add(u << 1, p, x);
//         else modify_add(u << 1 | 1, p, x);
//         pushup(u);
//     }
//
// private:
//     std::vector<node> tr;
// };
//
// signed main() {
//     int n, m;
//     std::cin >> n >> m;
//     std::vector<std::pair<int, int>> a(m + 1);
//     for (int i = 1; i <= m; i++) std::cin >> a[i].first >> a[i].second;
//     std::sort(a.begin() + 1, a.end());
//     SegTree seg_tree(n + 1);
//     seg_tree.modify_add(1, 1, 1);
//     for (int i = 1; i <= m; i++) {
//         const int sum = seg_tree.query(1, a[i].first, a[i].second);
//         seg_tree.modify_x(1, a[i].second + 1, n, 2);
//         seg_tree.modify_x(1, 1, a[i].first - 1, 2);
//         seg_tree.modify_add(1, a[i].second, sum);
//     }
//     std::cout << seg_tree.query(1, n, n);
//     return 0;
// }

// 38. https://www.luogu.com.cn/problem/P4145
// #include <bits/stdc++.h>
// #define int long long
// constexpr int N = 1e5 + 10;
//
// struct node {
//     int l, r, mx, sum;
// } tr[N << 2];
//
// int a[N];
//
// void pushup(const int u) {
//     tr[u].mx = std::max(tr[u << 1].mx, tr[u << 1 | 1].mx);
//     tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
// }
//
// void build(const int u, const int l, const int r) {
//     tr[u] = {l, r};
//     if (l == r) {
//         tr[u].mx = tr[u].sum = a[l];
//         return;
//     }
//     const int mid = (l + r) >> 1;
//     build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
//     pushup(u);
// }
//
// int query(const int u, const int l, const int r) {
//     if (l <= tr[u].l && tr[u].r <= r) return tr[u].sum;
//     const int mid = (tr[u].l + tr[u].r) >> 1;
//     if (r <= mid) return query(u << 1, l, r);
//     if (l > mid) return query(u << 1 | 1, l, r);
//     return query(u << 1, l, mid) + query(u << 1 | 1, mid + 1, r);
// }
//
// void modify(const int u, const int l, const int r) {
//     if (tr[u].mx <= 1) return;
//     if (tr[u].l == tr[u].r) {
//         tr[u].mx = tr[u].sum = static_cast<int>(sqrtl(tr[u].sum));
//         return;
//     }
//     const int mid = (tr[u].l + tr[u].r) >> 1;
//     if (r <= mid) modify(u << 1, l, r);
//     else if (l > mid) modify(u << 1 | 1, l, r);
//     else modify(u << 1, l, mid), modify(u << 1 | 1, mid + 1, r);
//     pushup(u);
// }
//
// signed main() {
//     std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
//     int n;
//     std::cin >> n;
//     for (int i = 1; i <= n; i++) std::cin >> a[i];
//     build(1, 1, n);
//     int m;
//     std::cin >> m;
//     while (m--) {
//         int k, l, r;
//         std::cin >> k >> l >> r;
//         if (l > r) std::swap(l, r);
//         if (k == 0) modify(1, l, r);
//         else std::cout << query(1, l, r) << "\n";
//     }
//     return 0;
// }

// 39. https://codeforces.com/problemset/problem/438/D
// #include <bits/stdc++.h>
// #define int long long
// constexpr int N = 1e5 + 10;
//
// struct node {
//     int l, r, mx, sum;
// } tr[N << 2];
//
// int a[N];
//
// void pushup(const int u) {
//     tr[u].mx = std::max(tr[u << 1].mx, tr[u << 1 | 1].mx);
//     tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
// }
//
// void build(const int u, const int l, const int r) {
//     tr[u] = {l, r};
//     if (l == r) {
//         tr[u].mx = tr[u].sum = a[l];
//         return;
//     }
//     const int mid = (l + r) >> 1;
//     build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
//     pushup(u);
// }
//
// int query(const int u, const int l, const int r) {
//     if (l <= tr[u].l && tr[u].r <= r) return tr[u].sum;
//     const int mid = (tr[u].l + tr[u].r) >> 1;
//     if (r <= mid) return query(u << 1, l, r);
//     if (l > mid) return query(u << 1 | 1, l, r);
//     return query(u << 1, l, mid) + query(u << 1 | 1, mid + 1, r);
// }
//
// void modify(const int u, const int l, const int r, const int x) {
//     if (tr[u].mx < x) return;
//     if (tr[u].l == tr[u].r) {
//         tr[u].mx = tr[u].sum = tr[u].sum % x;
//         return;
//     }
//     const int mid = (tr[u].l + tr[u].r) >> 1;
//     if (r <= mid) modify(u << 1, l, r, x);
//     else if (l > mid) modify(u << 1 | 1, l, r, x);
//     else modify(u << 1, l, mid, x), modify(u << 1 | 1, mid + 1, r, x);
//     pushup(u);
// }
//
// void modify(const int u, const int p, const int x) {
//     if (tr[u].l == tr[u].r) {
//         tr[u].sum = tr[u].mx = x;
//         return;
//     }
//     const int mid = (tr[u].l + tr[u].r) >> 1;
//     if (p <= mid) modify(u << 1, p, x);
//     else modify(u << 1 | 1, p, x);
//     pushup(u);
// }
//
// signed main() {
//     std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
//     int n, m;
//     std::cin >> n >> m;
//     for (int i = 1; i <= n; i++) std::cin >> a[i];
//     build(1, 1, n);
//     while (m--) {
//         int op;
//         std::cin >> op;
//         if (op == 1) {
//             int l, r;
//             std::cin >> l >> r;
//             std::cout << query(1, l, r) << "\n";
//         } else if (op == 2) {
//             int l, r, x;
//             std::cin >> l >> r >> x;
//             modify(1, l, r, x);
//         } else {
//             int k, x;
//             std::cin >> k >> x;
//             modify(1, k, x);
//         }
//     }
//     return 0;
// }

// 40. https://www.luogu.com.cn/problem/P3740
// #include <bits/stdc++.h>
// constexpr int N = 50000;
//
// struct node {
//     int l, r, lz, x;
// } tr[N << 2];
//
// void build(const int u, const int l, const int r) {
//     tr[u] = {l, r};
//     if (l == r) return;
//     const int mid = (l + r) >> 1;
//     build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
// }
//
// void pushdown(const int u) {
//     if (tr[u].lz != 0) {
//         tr[u << 1].lz = tr[u << 1].x = tr[u].lz;
//         tr[u << 1 | 1].lz = tr[u << 1 | 1].x = tr[u].lz;
//         tr[u].lz = 0;
//     }
// }
//
// void modify(const int u, const int l, const int r, const int x) {
//     if (l <= tr[u].l && tr[u].r <= r) {
//         tr[u].lz = x;
//         tr[u].x = x;
//         return;
//     }
//     pushdown(u);
//     const int mid = (tr[u].l + tr[u].r) >> 1;
//     if (r <= mid) modify(u << 1, l, r, x);
//     else if (l > mid) modify(u << 1 | 1, l, r, x);
//     else modify(u << 1, l, mid, x), modify(u << 1 | 1, mid + 1, r, x);
// }
//
// void query(const int u, std::set<int>& st) {
//     if (tr[u].l == tr[u].r) {
//         if (tr[u].x) st.insert(tr[u].x);
//         return;
//     }
//     pushdown(u);
//     query(u << 1, st), query(u << 1 | 1, st);
// }
//
// signed main() {
//     int n, m;
//     std::cin >> n >> m;
//     std::vector<std::pair<int, int>> a(m + 1);
//     for (int i = 1; i <= m; i++) std::cin >> a[i].first >> a[i].second;
//     std::vector<int> tmp;
//     for (int i = 1; i <= m; i++) tmp.push_back(a[i].first), tmp.push_back(a[i].second);
//     std::sort(tmp.begin(), tmp.end());
//     tmp.erase(std::unique(tmp.begin(), tmp.end()), tmp.end());
//     std::vector<int> id(1);
//     for (int i = 0; i < tmp.size(); i++) {
//         id.push_back(tmp[i]);
//         if (i != tmp.size() - 1 && tmp[i + 1] - tmp[i] > 1) id.push_back(tmp[i] + 1);
//     }
//     auto find_id = [&](const int x) -> int {
//         return std::lower_bound(id.begin(), id.end(), x) - id.begin();
//     };
//     build(1, 1, id.size());
//     for (int i = 1; i <= m; i++) {
//         modify(1, find_id(a[i].first), find_id(a[i].second), i);
//     }
//     std::set<int> st;
//     query(1, st);
//     std::cout << st.size() << "\n";
//     return 0;
// }

// 41. https://www.luogu.com.cn/problem/P1438
// #include <bits/stdc++.h>
// #define int long long
//
// class SegTree {
// public:
//     struct node {
//         int l, r, x, lz;
//     };
//
//     explicit SegTree(const int n) : tr((n + 1) << 2), n(n) {
//         build(1, 1, n);
//     }
//
//     explicit SegTree(const std::vector<int>& a) : tr(a.size() << 2), n(a.size() - 1) {
//         build(1, 1, n, a);
//     }
//
//     void build(const int u, const int l, const int r) {
//         tr[u] = {l, r, 0, 0};
//         if (l == r) return;
//         const int mid = (l + r) >> 1;
//         build(u << 1, l, mid);
//         build(u << 1 | 1, mid + 1, r);
//     }
//
//     void build(const int u, const int l, const int r, const std::vector<int>& a) {
//         tr[u] = {l, r, 0, 0};
//         if (l == r) {
//             tr[u].x = a[l];
//             return;
//         }
//         const int mid = (l + r) >> 1;
//         build(u << 1, l, mid, a);
//         build(u << 1 | 1, mid + 1, r, a);
//         pushup(u);
//     }
//
//     void pushup(const int u) {
//         tr[u].x = tr[u << 1].x + tr[u << 1 | 1].x;
//     }
//
//     void pushdown(const int u) {
//         if (tr[u].lz) {
//             tr[u << 1].lz = tr[u << 1].lz + tr[u].lz;
//             tr[u << 1 | 1].lz = tr[u << 1 | 1].lz + tr[u].lz;
//             tr[u << 1].x = tr[u << 1].x + tr[u].lz * (tr[u << 1].r - tr[u << 1].l + 1);
//             tr[u << 1 | 1].x = tr[u << 1 | 1].x + tr[u].lz * (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1);
//             tr[u].lz = 0;
//         }
//     }
//
//     int query(const int u, const int l, const int r) {
//         if (l <= tr[u].l && tr[u].r <= r) return tr[u].x;
//         pushdown(u);
//         const int mid = (tr[u].l + tr[u].r) >> 1;
//         if (r <= mid) return query(u << 1, l, r);
//         if (l > mid) return query(u << 1 | 1, l, r);
//         return (query(u << 1, l, mid) + query(u << 1 | 1, mid + 1, r));
//     }
//
//     void modify(const int u, const int l, const int r, const int x) {
//         if (r < l) return;
//         if (l <= tr[u].l && tr[u].r <= r) {
//             tr[u].x = tr[u].x + (tr[u].r - tr[u].l + 1) * x;
//             tr[u].lz = tr[u].lz + x;
//             return;
//         }
//         pushdown(u);
//         const int mid = (tr[u].l + tr[u].r) >> 1;
//         if (r <= mid) modify(u << 1, l, r, x);
//         else if (l > mid) modify(u << 1 | 1, l, r, x);
//         else modify(u << 1, l, mid, x), modify(u << 1 | 1, mid + 1, r, x);
//         pushup(u);
//     }
//
//     void modify_add(const int u, const int p, const int x) {
//         if (p > n) return;
//         if (tr[u].l == tr[u].r) {
//             tr[u].x = tr[u].x + x;
//             return;
//         }
//         pushdown(u);
//         const int mid = (tr[u].l + tr[u].r) >> 1;
//         if (p <= mid) modify_add(u << 1, p, x);
//         else modify_add(u << 1 | 1, p, x);
//         pushup(u);
//     }
//
// private:
//     std::vector<node> tr;
//     int n;
// };
//
// signed main() {
//     std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
//     int n, m;
//     std::cin >> n >> m;
//     std::vector<int> a(n + 1);
//     for (int i = 1; i <= n; i++) std::cin >> a[i];
//     for (int i = n; i >= 1; i--) a[i] -= a[i - 1];
//     SegTree seg_tree(a);
//     while (m--) {
//         int op;
//         std::cin >> op;
//         if (op == 1) {
//             int l, r, k, d;
//             std::cin >> l >> r >> k >> d;
//             seg_tree.modify_add(1, l, k);
//             seg_tree.modify(1, l + 1, r, d);
//             seg_tree.modify_add(1, r + 1, -k - (r - l) * d);
//         } else {
//             int p;
//             std::cin >> p;
//             std::cout << seg_tree.query(1, 1, p) << "\n";
//         }
//     }
//     return 0;
// }

// 42. https://www.luogu.com.cn/problem/AT_abc449_c
// #include <bits/stdc++.h>
// #define int long long
//
// signed main() {
//     int n, l, r;
//     std::string s;
//     std::cin >> n >> l >> r >> s;
//     std::vector sum(26, std::vector<int>(s.size() + 1));
//     for (int i = 1; i <= n; i++) sum[s[i - 1] - 'a'][i]++;
//     for (int i = 0; i < 26; i++) {
//         for (int j = 1; j <= n; j++) {
//             sum[i][j] += sum[i][j - 1];
//         }
//     }
//     int ans = 0;
//     for (int i = 1; i <= n; i++) {
//         int l_ = std::max(0LL, i - r - 1);
//         int r_ = std::max(0LL, i - l);
//         ans += sum[s[i - 1] - 'a'][r_] - sum[s[i - 1] - 'a'][l_];
//     }
//     std::cout << ans << std::endl;
//     return 0;
// }

// 43. https://atcoder.jp/contests/abc449/tasks/abc449_d
// #include <bits/stdc++.h>
// #define int long long
//
// signed main() {
//     int l, r, d, u;
//     std::cin >> l >> r >> d >> u;
//     int ans = 0;
//     if (l <= 0 && r >= 0 && d <= 0 && u >= 0) ans++;
//     for (int i = 2; i <= 1000000; i += 2) {
//         if (l <= i && i <= r) ans += std::max(0LL, std::min(u, i) - std::max(d, -i) + 1);
//         if (l <= -i && -i <= r) ans += std::max(0LL, std::min(u, i) - std::max(d, -i) + 1);
//         if (d <= i && i <= u) ans += std::max(0LL, std::min(r, i - 1) - std::max(l, -i + 1) + 1);
//         if (d <= -i && -i <= u) ans += std::max(0LL, std::min(r, i - 1) - std::max(l, -i + 1) + 1);
//     }
//     std::cout << ans << "\n";
//     return 0;
// }

// 2026.3.28 VP The 2023 ICPC Asia Hangzhou Regional Contest (The 2nd Universal Cup. Stage 22: Hangzhou)
// 44. https://codeforces.com/gym/104976/problem/G
// #include <bits/stdc++.h>
//
// int dx[] = {1, 0, -1, 0};
// int dy[] = {0, 1, 0, -1};
//
// struct node {
//     int x, y, step;
// };
//
// void solve() {
//     int n, m, k;
//     std::cin >> n >> m >> k;
//     std::vector<std::pair<int, int>> a(k + 1);
//     for (int i = 1; i <= k; i++) std::cin >> a[i].first >> a[i].second;
//     std::map<std::pair<int, int>, int> ma;
//     for (int i = 1; i <= k; i++) ma[a[i]] = i;
//     std::vector mp(n + 1, std::vector<char>(m + 1));
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= m; j++) {
//             std::cin >> mp[i][j];
//         }
//     }
//     std::queue<node> q;
//     std::vector mi(n + 1, std::vector<int>(m + 1, 1e9));
//     q.push({a[1].first, a[1].second, 0});
//     while (!q.empty()) {
//         const auto [x, y, step] = q.front();
//         q.pop();
//         mi[x][y] = std::min(mi[x][y], step);
//         for (int i = 0; i < 4; i++) {
//             int nx = x + dx[i], ny = y + dy[i];
//             if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
//             if (mp[nx][ny] == '#') continue;
//             if (auto it = ma.find({nx, ny}); it != ma.end()) {
//                 if (step >= k - it->second) {
//                     if (step + 1 < mi[nx][ny]) {
//                         mi[nx][ny] = step + 1;
//                         q.push({nx, ny, step + 1});
//                     }
//                 } else {
//                     int t = -step + k - it->second;
//                     t += step + 1;
//                     if (t < mi[nx][ny]) {
//                         mi[nx][ny] = t;
//                         q.push({nx, ny, t});
//                     }
//                 }
//             } else {
//                 if (step + 1 < mi[nx][ny]) {
//                     mi[nx][ny] = step + 1;
//                     q.push({nx, ny, step + 1});
//                 }
//             }
//         }
//     }
//     // for (int i = 1; i <= n; i++) {
//     //     for (int j = 1; j <= m; j++) {
//     //         std::cout << mi[i][j] << " ";
//     //     }
//     //     std::cout << "\n";
//     // }
//     unsigned long long ans = 0;
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= m; j++) {
//             if (mi[i][j] != 1e9) {
//                 ans += 1LL * mi[i][j] * mi[i][j];
//             }
//         }
//     }
//     std::cout << ans << "\n";
// }
//
// signed main() {
//     std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
//     int T = 1;
//     while (T--) {
//         solve();
//     }
//     return 0;
// }

// 45. https://codeforces.com/gym/104976/problem/J
// #include <bits/stdc++.h>
//
// int query(int x, int y) {
//     std::cout << "? " << x << " " << y << std::endl;
//     int res;
//     std::cin >> res;
//     return res;
// }
//
// void solve() {
//     int n;
//     std::cin >> n;
//     for (int i = 1; i < n; i += 2) {
//         int t = query(i, i + 1);
//         if (t == 1) {
//             std::vector<int> tmp;
//             for (int j = 1; j <= n; j++) {
//                 if (j != i && j != i + 1) {
//                     tmp.emplace_back(j);
//                 }
//                 if (tmp.size() == 2) break;
//             }
//             int t1 = query(i, tmp[0]);
//             int t2 = query(i + 1, tmp[0]);
//             if (t1 == 0 && t2 == 0) {
//                 std::cout << "! 1" << std::endl;
//                 return;
//             }
//             if (t1 == 1) {
//                 t1 = query(i, tmp[1]);
//                 if (t1 == 1) std::cout << "! 2" << std::endl;
//                 else std::cout << "! 1" << std::endl;
//                 return;
//             } else {
//                 t1 = query(i + 1, tmp[1]);
//                 if (t1 == 1) std::cout << "! 2" << std::endl;
//                 else std::cout << "! 1" << std::endl;
//                 return;
//             }
//         }
//     }
//     if (n & 1) {
//         int t = query(1, n);
//         if (!t) {
//             std::cout << "! 1" << std::endl;
//             return;
//         } else {
//             std::vector<int> tmp;
//             for (int j = 1; j <= n; j++) {
//                 if (j != 1 && j != n) {
//                     tmp.emplace_back(j);
//                 }
//                 if (tmp.size() == 2) break;
//             }
//             int t1 = query(1, tmp[0]);
//             int t2 = query(n, tmp[0]);
//             if (t1 == 0 && t2 == 0) {
//                 std::cout << "! 1" << std::endl;
//                 return;
//             }
//             if (t1 == 1) {
//                 t1 = query(1, tmp[1]);
//                 if (t1 == 1) std::cout << "! 2" << std::endl;
//                 else std::cout << "! 1" << std::endl;
//                 return;
//             } else {
//                 t1 = query(n, tmp[1]);
//                 if (t1 == 1) std::cout << "! 2" << std::endl;
//                 else std::cout << "! 1" << std::endl;
//                 return;
//             }
//         }
//     }
//     std::cout << "! 1" << std::endl;
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

// 46. https://atcoder.jp/contests/abc449/tasks/abc449_e
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// template<typename T> T pred(T a, T b) { return a + b; }
// template<typename T, T (*Pred)(T, T) = pred<T>, T Init = 0>
// struct BIT {
//     size_t n;
//     vector<T> data;
//     explicit BIT(const size_t n): BIT(vector<T>(n + 1, Init)) {}
//     explicit BIT(const vector<T> &v): n(v.size() - 1), data(v) {
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
//     T query(const size_t l, const size_t r) {
//         return query(r) - query(l - 1);
//     }
//     int lower_bound(T x) {
//         T sum = Init;
//         int index = 0;
//         for (size_t i = 1 << __lg(n); i; i >>= 1) {
//             if (index + i <= n && sum + data[index + i] < x) {
//                 index += i;
//                 sum += data[index];
//             }
//         }
//         return index + 1;
//     }
// };
//
// signed main() {
//     int n, m;
//     std::cin >> n >> m;
//     std::vector<int> a(n + 1), c(m + 1);
//     for (int i = 1; i <= n; i++) std::cin >> a[i], c[a[i]]++;
//     std::vector<std::pair<int, int>> cnt;
//     for (int i = 1; i <= m; i++) cnt.emplace_back(c[i], i);
//     std::sort(cnt.begin(), cnt.end());
//     std::vector<int> sum(cnt.size());
//     sum[0] = cnt.front().first;
//     for (int i = 1; i < cnt.size(); i++) sum[i] = sum[i - 1] + cnt[i].first;
//     int t = 0;
//     int q;
//     std::cin >> q;
//     std::vector<int> query(q + 1);
//     for (int i = 1; i <= q; i++) std::cin >> query[i];
//     std::vector<int> ans(q + 1);
//     std::vector<int> id(q + 1);
//     std::iota(id.begin(), id.end(), 0);
//     std::sort(id.begin() + 1, id.end(), [&](const int x, const int y) -> bool {
//        return query[x] < query[y];
//     });
//     BIT<int> bit(m + 1);
//     for (int _ = 1; _ <= q; _++) {
//         const int i = id[_];
//         if (query[i] <= n) ans[i] = a[query[i]];
//         else {
//             const int step = query[i] - n;
//             while (t < cnt.size() && (t + 1) * cnt[t].first - sum[t] < step) {
//                 bit.update(cnt[t].second, 1);
//                 t++;
//             }
//             int x = (step - t * cnt[t - 1].first + sum[t - 1]) % t;
//             if (x == 0) x = t;
//             ans[i] = bit.lower_bound(x) - 1;
//         }
//     }
//     for (int i = 1; i <= q; i++) std::cout << ans[i] << "\n";
//     return 0;
// }

// 47. https://codeforces.com/problemset/problem/1181/D
// 和上面那题几乎一模一样，输入顺序换一下就过了，但这个是蓝题，上面是绿题(●'◡'●)
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// template<typename T> T pred(T a, T b) { return a + b; }
// template<typename T, T (*Pred)(T, T) = pred<T>, T Init = 0>
// struct BIT {
//     size_t n;
//     vector<T> data;
//     explicit BIT(const size_t n): BIT(vector<T>(n + 1, Init)) {}
//     explicit BIT(const vector<T> &v): n(v.size() - 1), data(v) {
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
//     T query(const size_t l, const size_t r) {
//         return query(r) - query(l - 1);
//     }
//     int lower_bound(T x) {
//         T sum = Init;
//         int index = 0;
//         for (size_t i = 1 << __lg(n); i; i >>= 1) {
//             if (index + i <= n && sum + data[index + i] < x) {
//                 index += i;
//                 sum += data[index];
//             }
//         }
//         return index + 1;
//     }
// };
//
// signed main() {
//     int n, m, q;
//     std::cin >> n >> m >> q;
//     std::vector<int> a(n + 1), c(m + 1);
//     for (int i = 1; i <= n; i++) std::cin >> a[i], c[a[i]]++;
//     std::vector<std::pair<int, int>> cnt;
//     for (int i = 1; i <= m; i++) cnt.emplace_back(c[i], i);
//     std::sort(cnt.begin(), cnt.end());
//     std::vector<int> sum(cnt.size());
//     sum[0] = cnt.front().first;
//     for (int i = 1; i < cnt.size(); i++) sum[i] = sum[i - 1] + cnt[i].first;
//     int t = 0;
//     std::vector<int> query(q + 1);
//     for (int i = 1; i <= q; i++) std::cin >> query[i];
//     std::vector<int> ans(q + 1);
//     std::vector<int> id(q + 1);
//     std::iota(id.begin(), id.end(), 0);
//     std::sort(id.begin() + 1, id.end(), [&](const int x, const int y) -> bool {
//        return query[x] < query[y];
//     });
//     BIT<int> bit(m + 1);
//     for (int _ = 1; _ <= q; _++) {
//         const int i = id[_];
//         if (query[i] <= n) ans[i] = a[query[i]];
//         else {
//             const int step = query[i] - n;
//             while (t < cnt.size() && (t + 1) * cnt[t].first - sum[t] < step) {
//                 bit.update(cnt[t].second, 1);
//                 t++;
//             }
//             int x = (step - t * cnt[t - 1].first + sum[t - 1]) % t;
//             if (x == 0) x = t;
//             ans[i] = bit.lower_bound(x) - 1;
//         }
//     }
//     for (int i = 1; i <= q; i++) std::cout << ans[i] << "\n";
//     return 0;
// }

// 48. https://atcoder.jp/contests/abc448/tasks/abc448_d
// #include <bits/stdc++.h>
//
// signed main() {
//     int n;
//     std::cin >> n;
//     std::vector<int> a(n + 1);
//     for (int i = 1; i <= n; i++) std::cin >> a[i];
//     std::vector<std::vector<int>> g(n + 1);
//     for (int i = 1, u, v; i < n; i++) {
//         std::cin >> u >> v;
//         g[u].emplace_back(v);
//         g[v].emplace_back(u);
//     }
//     std::unordered_map<int, int> mp;
//     std::vector<int> ans(n + 1);
//     auto dfs = [&](auto&& self, const int u, const int fa, bool is_yes) -> void {
//         if (is_yes) ans[u] = 1;
//         if (mp[a[u]]) {
//             is_yes = true;
//             ans[u] = 1;
//         }
//         mp[a[u]]++;
//         for (const int v : g[u]) {
//             if (v == fa) continue;
//             self(self, v, u, is_yes);
//         }
//         mp[a[u]]--;
//     };
//     dfs(dfs, 1, 0, false);
//     for (int i = 1; i <= n; i++) {
//         if (ans[i]) std::cout << "Yes\n";
//         else std::cout << "No\n";
//     }
//     return 0;
// }

// 49. https://www.luogu.com.cn/problem/AT_abc448_e
// #include <bits/stdc++.h>
// #define int long long
// constexpr int mod = 10007;
//
// int ksm(int a, int k, const int mod) {
//     int res = 1;
//     while (k) {
//         if (k & 1) res = res * a % mod;
//         a = a * a % mod;
//         k >>= 1;
//     }
//     return res;
// }
//
// int calc(int n, int len, const int mod) {
//     int res = 0;
//     int w_len = 1;
//     while (len) {
//         if (len & 1) {
//             res = (res * ksm(10, w_len, mod) % mod + n) % mod;
//         }
//         n = (n * ksm(10, w_len, mod) % mod + n) % mod;
//         w_len += w_len;
//         len >>= 1;
//     }
//     return res;
// }
//
// signed main() {
//     int k, m;
//     std::cin >> k >> m;
//     std::vector<std::pair<int, int>> a(k + 1);
//     for (int i = 1; i <= k; i++) std::cin >> a[i].first >> a[i].second;
//     int res1 = calc(a[1].first, a[1].second, mod);
//     for (int i = 2; i <= k; i++) {
//         res1 = (res1 * ksm(10, a[i].second, mod) % mod + calc(a[i].first, a[i].second, mod)) % mod;
//     }
//     const int m_inv = ksm(m, mod - 2, mod);
//     res1 = res1 * m_inv % mod;
//     int res2 = calc(a[1].first, a[1].second, m);
//     for (int i = 2; i <= k; i++) {
//         res2 = (res2 * ksm(10, a[i].second, m) % m + calc(a[i].first, a[i].second, m)) % m;
//     }
//     res2 = res2 * m_inv % mod;
//     const int ans = ((res1 - res2) % mod + mod) % mod;
//     std::cout << ans << "\n";
//     return 0;
// }

// 50. https://codeforces.com/contest/2210/problem/C1
// #include <bits/stdc++.h>
//
// void solve() {
//     int n;
//     std::cin >> n;
//     std::vector<int> a(n + 1), b(n + 1);
//     for (int i = 1; i <= n; i++) std::cin >> a[i];
//     for (int i = 1; i <= n; i++) std::cin >> b[i];
//     a[1] = std::gcd(b[1], b[2]);
//     a[n] = std::gcd(a[n], a[n - 1]);
//     for (int i = 2; i < n; i++) {
//         a[i] = std::min(b[i], std::lcm(std::gcd(b[i], b[i - 1]), std::gcd(b[i], b[i + 1])));
//     }
//     int ans = 0;
//     for (int i = 1; i <= n; i++) ans += a[i] != b[i];
//     std::cout << ans << "\n";
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

// 51. https://atcoder.jp/contests/abc447/tasks/abc447_e
// #include <bits/stdc++.h>
// #define int long long
// constexpr int N = 2e5 + 10;
// constexpr int mod = 998244353;
//
// int fa[N], siz[N];
//
// int find(int x) {
//     if (x != fa[x]) fa[x] = find(fa[x]);
//     return fa[x];
// }
//
// bool merge(int x, int y, int mx) {
//     if (find(x) == find(y)) return true;
//     if (siz[find(x)] + siz[find(y)] == mx) return false;
//     siz[find(x)] += siz[find(y)];
//     fa[find(y)] = fa[find(x)];
//     return true;
// }
//
// int ksm(int a, int k) {
//     int res = 1;
//     while (k) {
//         if (k & 1) res = res * a % mod;
//         a = a * a % mod;
//         k >>= 1;
//     }
//     return res;
// }
//
// signed main() {
//     int n, m;
//     std::cin >> n >> m;
//     std::vector<std::pair<int, int>> mp(m + 1);
//     for (int i = 0, u, v; i < m; i++) {
//         std::cin >> u >> v;
//         mp[i + 1] = {u, v};
//     }
//     int ans = 0;
//     for (int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
//     for (int i = m; i >= 1; i--) {
//         if (!merge(mp[i].first, mp[i].second, n)) {
//             ans = (ans + ksm(2, i)) % mod;
//         }
//     }
//     std::cout << ans << "\n";
//     return 0;
// }

// 52. https://atcoder.jp/contests/abc447/tasks/abc447_f
// #include <bits/stdc++.h>
//
// void solve() {
//     int n;
//     std::cin >> n;
//     std::vector<std::vector<int>> g(n + 1);
//     for (int i = 1, u, v; i < n; i++) {
//         std::cin >> u >> v;
//         g[u].emplace_back(v);
//         g[v].emplace_back(u);
//     }
//     int ans = 1;
//     std::vector<int> dp(n + 1);
//     auto dfs = [&](auto&& self, const int u, const int fa) -> void {
//         int mx = -1, cmx = -1, ch = 0;
//         for (const int v : g[u]) {
//             if (v == fa) continue;
//             self(self, v, u);
//             if (dp[v] > mx) {
//                 cmx = mx;
//                 mx = dp[v];
//             } else {
//                 cmx = std::max(cmx, dp[v]);
//             }
//             ch++;
//         }
//         if (g[u].size() >= 4) {
//             ans = std::max(ans, mx + cmx + 1);
//         } else if (g[u].size() == 3) {
//             ans = std::max(ans, mx + 1);
//         }
//         if (ch >= 3) dp[u] = mx + 1;
//         else if (ch == 2) dp[u] = 1;
//         else dp[u] = 0;
//     };
//     dfs(dfs, 1, 0);
//     std::cout << ans << "\n";
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

// 53. https://www.luogu.com.cn/problem/P3369   P3369 【模板】普通平衡树
// #include <bits/stdc++.h>
// constexpr int N = 1e5 + 10;
//
// class ScapegoatTree {
// public:
//     explicit ScapegoatTree(const int n) : right(n), left(n), key(n), key_cnt(n), num_size(n), node_size(n), tmp(n) {
//
//     }
//
//     void insert(const int num) {
//         top = father = side = 0;
//         insert(head, 0, 0, num);
//         rebuild();
//     }
//
//     int getRank(const int num) {
//         return small(head, num) + 1;
//     }
//     // 获取最大的小于num的数
//     int pre(const int num) {
//         const int kth = getRank(num);
//         if (kth == 1) return INT32_MIN;
//         return index(kth - 1);
//     }
//     // 获取最小的大于num的数
//     int post(const int num) {
//         const int kth = getRank(num + 1);
//         if (kth == num_size[head] + 1) return INT32_MAX;
//         return index(kth);
//     }
//     // 获取从小到大排序后排名第x的数字
//     int index(const int x) {
//         return index(head, x);
//     }
//
//     void remove(const int num) {
//         if (getRank(num) != getRank(num + 1)) {
//             top = father = side = 0;
//             remove(head, 0, 0, num);
//             rebuild();
//         }
//     }
//
// private:
//     int index(const int u, const int x) {
//         if (num_size[left[u]] >= x) return index(left[u], x);
//         if (num_size[left[u]] + key_cnt[u] < x) return index(right[u], x - num_size[left[u]] - key_cnt[u]);
//         return key[u];
//     }
//
//     void remove(const int i, const int f, const int s, const int num) {
//         if (key[i] == num) {
//             key_cnt[i]--;
//         } else if (key[i] > num) {
//             remove(left[i], i, 1, num);
//         } else {
//             remove(right[i], i, 2, num);
//         }
//         up(i);
//         if (!balance(i)) {
//             top = i;
//             father = f;
//             side = s;
//         }
//     }
//
//     void insert(const int i, const int f, const int s, const int num) {
//         if (i == 0) {
//             if (f == 0) head = init(num);
//             else if (s == 1) left[f] = init(num);
//             else right[f] = init(num);
//         } else {
//             if (num == key[i]) key_cnt[i]++;
//             else if (num < key[i]) insert(left[i], i, 1, num);
//             else insert(right[i], i, 2, num);
//             up(i);
//             if (!balance(i)) {
//                 top = i;
//                 father = f;
//                 side = s;
//             }
//         }
//     }
//
//     // 统计小于num的元素个数
//     int small(const int u, const int num) {
//         if (u == 0) return 0;
//         if (key[u] >= num) return small(left[u], num);
//         return key_cnt[u] + num_size[left[u]] + small(right[u], num);
//     }
//
//     void up(const int i) {
//         num_size[i] = num_size[left[i]] + num_size[right[i]] + key_cnt[i];
//         node_size[i] = node_size[left[i]] + node_size[right[i]] + (key_cnt[i] > 0);
//     }
//
//     [[nodiscard]] bool balance(const int i) const {
//         return ALPHA * node_size[i] >= std::max(node_size[left[i]], node_size[right[i]]);
//     }
//
//     // 收集需要重构的节点
//     void inorder(const int i) {
//         if (i == 0) return;
//         inorder(left[i]);
//         if (key_cnt[i] > 0) tmp[++tmp_cnt] = i;
//         inorder(right[i]);
//     }
//
//     void rebuild() {
//         if (top == 0) return;
//         tmp_cnt = 0;
//         inorder(top);
//         if (tmp_cnt <= 0) return;
//         if (father == 0) head = build(1, tmp_cnt);
//         else if (side == 1) left[father] = build(1, tmp_cnt);
//         else right[father] = build(1, tmp_cnt);
//     }
//
//     int build(const int l, const int r) {
//         if (l > r) return 0;
//         const int mid = (l + r) >> 1;
//         const int t = tmp[mid];
//         left[t] = build(l, mid - 1);
//         right[t] = build(mid + 1, r);
//         up(t);
//         return t;
//     }
//
//     int init(const int num) {
//         key[++cnt] = num;
//         key_cnt[cnt] = num_size[cnt] = node_size[cnt] = 1;
//         return cnt;
//     }
//
//     std::vector<int> right;
//     std::vector<int> left;
//     std::vector<int> key;
//     std::vector<int> key_cnt;
//     std::vector<int> num_size;
//     std::vector<int> node_size;
//     std::vector<int> tmp;
//     int cnt{}, top{}, father{}, head{}, side{}, tmp_cnt{};
//     static constexpr double ALPHA = 0.7;
// };
//
// signed main() {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);
//     int n;
//     std::cin >> n;
//     ScapegoatTree scapegoat_tree(N);
//     for (int i = 1; i <= n; i++) {
//         int op, x;
//         std::cin >> op >> x;
//         if (op == 1) {
//             scapegoat_tree.insert(x);
//         } else if (op == 2) {
//             scapegoat_tree.remove(x);
//         } else if (op == 3) {
//             std::cout << scapegoat_tree.getRank(x) << "\n";
//         } else if (op == 4) {
//             std::cout << scapegoat_tree.index(x) << "\n";
//         } else if (op == 5) {
//             std::cout << scapegoat_tree.pre(x) << "\n";
//         } else {
//             std::cout << scapegoat_tree.post(x) << "\n";
//         }
//     }
//     return 0;
// }

// 54. https://codeforces.com/gym/103055/problem/D
// #include <bits/stdc++.h>
// #define int long long
// constexpr int inf = 1e18;
//
// bool is_fu(const int u, const int v) {
//     if (u > v) return false;
//     return v >> (std::__lg(v) - std::__lg(u)) == u;
// }
//
// signed main() {
//     std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
//     int n, m;
//     std::cin >> n >> m;
//     std::vector<std::vector<std::pair<int, int>>> g(n + 1);
//     for (int i = 0, u, v, w; i < m; i++) {
//         std::cin >> u >> v >> w;
//         g[u].emplace_back(v, w);
//         g[v].emplace_back(u, w);
//     }
//     std::vector<std::unordered_map<int, int>> dis(n + 1);
//     std::vector<int> vis(n + 1);
//     auto dijkstra = [&](int s) -> void {
//         std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
//         q.emplace(0, s);
//         while (!q.empty()) {
//             const auto [sum, u] = q.top();
//             q.pop();
//             if (vis[u] == s) continue;
//             vis[u] = s;
//             dis[s][u] = sum;
//             for (const auto [v, w] : g[u]) {
//                 if (is_fu(s, v) && vis[v] != s && (dis[s].find(v) == dis[s].end() || dis[s][v] > sum + w)) {
//                     dis[s][v] = sum + w;
//                     q.emplace(sum + w, v);
//                 }
//             }
//         }
//     };
//     for (int i = 1; i <= n; i++) {
//         dijkstra(i);
//     }
//     int q;
//     std::cin >> q;
//     while (q--) {
//         int s, t;
//         std::cin >> s >> t;
//         if (s > t) std::swap(s, t);
//         int ans = dis[s].find(t) != dis[s].end() ? dis[s][t] : inf;
//         int c = s >> 1;
//         while (c) {
//             const int t1 = dis[c].find(s) != dis[c].end() ? dis[c][s] : inf;
//             const int t2 = dis[c].find(t) != dis[c].end() ? dis[c][t] : inf;
//             ans = std::min(ans, t1 + t2);
//             c >>= 1;
//         }
//         std::cout << (ans >= inf ? -1 : ans) << "\n";
//     }
//     return 0;
// }

// 55. https://codeforces.com/gym/105158   D
// #include <bits/stdc++.h>
// #define x first
// #define y second
//
// const double cos45 = std::sqrt(2) / 2;
//
// double dis(const std::pair<double, double> &a, const std::pair<double, double> &b) {
//     return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
// }
//
// double calc(const std::pair<double, double> &a, const std::pair<double, double> &b) {
//     return (std::abs(a.x - b.x) + std::abs(a.y - b.y)) / dis(a, b);
// }
//
// void solve() {
//     int n;
//     std::cin >> n;
//     std::vector<std::pair<int, int>> a(n + 1);
//     for (int i = 1; i <= n; i++) {
//         std::cin >> a[i].x >> a[i].y;
//     }
//     std::vector<std::pair<double, double>> b(n + 1);
//     for (int i = 1; i <= n; i++) {
//         b[i].x = a[i].x * cos45 - a[i].y * cos45;
//         b[i].y = a[i].x * cos45 + a[i].y * cos45;
//     }
//     double ans = -1;
//     std::vector<int> id(n + 1);
//     std::iota(id.begin(), id.end(), 0);
//     std::sort(id.begin() + 1, id.end(), [&](const int a_, const int b_) -> bool {
//         return b[a_].x < b[b_].x;
//     });
//     for (int i = 1; i <= n; i++) {
//         const int i_ = id[i];
//         for (int j = i + 1; j <= std::min(n, i + 1); j++) {
//             const int j_ = id[j];
//             ans = std::max(ans, calc(a[i_], a[j_]));
//         }
//         for (int j = i - 1; j >= std::max(1, i - 1); j--) {
//             const int j_ = id[j];
//             ans = std::max(ans, calc(a[i_], a[j_]));
//         }
//     }
//     std::iota(id.begin(), id.end(), 0);
//     std::sort(id.begin() + 1, id.end(), [&](const int a_, const int b_) -> bool {
//         return b[a_].y < b[b_].y;
//     });
//     for (int i = 1; i <= n; i++) {
//         const int i_ = id[i];
//         for (int j = i + 1; j <= std::min(n, i + 1); j++) {
//             const int j_ = id[j];
//             ans = std::max(ans, calc(a[i_], a[j_]));
//         }
//         for (int j = i - 1; j >= std::max(1, i - 1); j--) {
//             const int j_ = id[j];
//             ans = std::max(ans, calc(a[i_], a[j_]));
//         }
//     }
//     std::cout << std::fixed << std::setprecision(10) << ans << "\n";
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

// 56. https://www.luogu.com.cn/problem/AT_abc446_e
// #include <bits/stdc++.h>
//
// signed main() {
//     int m, a, b;
//     std::cin >> m >> a >> b;
//     std::vector vis(m + 1, std::vector<int>(m + 1, -1));
//     auto dfs = [&](auto&& self, const int x, const int y) -> int {
//         if (vis[x][y] == -2) return vis[x][y] = 1;
//         if (vis[x][y] != -1) return vis[x][y];
//         if (x == 0 || y == 0) return vis[x][y] = 0;
//         vis[x][y] = -2;
//         return vis[x][y] = self(self, y, (a * y + b * x) % m);
//     };
//     int ans = 0;
//     for (int x = 0; x < m; x++) {
//         for (int y = 0; y < m; y++) {
//             ans += dfs(dfs, x, y);
//         }
//     }
//     std::cout << ans << "\n";
//     return 0;
// }

// 57. https://www.luogu.com.cn/problem/AT_abc446_f
// #include <bits/stdc++.h>
//
// signed main() {
//     int n, m;
//     std::cin >> n >> m;
//     std::vector<std::vector<int>> g(n + 1);
//     for (int i = 1; i <= m; i++) {
//         int u, v;
//         std::cin >> u >> v;
//         if (u == v) continue;
//         g[u].emplace_back(v);
//     }
//     std::priority_queue<int, std::vector<int>, std::greater<>> q;
//     q.push(1);
//     std::vector<int> vis(n + 1);
//     vis[1] = 1;
//     int cnt = 0;
//     for (int i = 1; i <= n; i++) {
//         while (!q.empty() && q.top() <= i) {
//             cnt++;
//             const int t = q.top();
//             q.pop();
//             for (const int v : g[t]) {
//                 if (!vis[v]) {
//                     vis[v] = 1;
//                     q.push(v);
//                 }
//             }
//         }
//         std::cout << (cnt != i ? -1 : static_cast<int>(q.size())) << "\n";
//     }
//     return 0;
// }

// 58. https://codeforces.com/contest/2217/problem/C
// #include <bits/stdc++.h>
// #define int long long
//
// void solve() {
//     int n, m, a, b;
//     std::cin >> n >> m >> a >> b;
//     if (std::gcd(n, a) == 1 && std::gcd(m, b) == 1 && std::gcd(n, m) <= 2) {
//         std::cout << "YES\n";
//     } else {
//         std::cout << "NO\n";
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

// 59. https://codeforces.com/contest/2217/problem/D
// #include <bits/stdc++.h>
//
// void solve() {
//     int n, k;
//     std::cin >> n >> k;
//     std::vector<int> a(n + 2), b(k + 2);
//     for (int i = 1; i <= n; i++) std::cin >> a[i];
//     for (int i = 1; i <= k; i++) std::cin >> b[i];
//     b[k + 1] = n + 1;
//     const int t = a[b[1]];
//     for (int i = 1; i <= n; i++) a[i] = (a[i] != t);
//     for (int i = n + 1; i >= 1; i--) a[i] = a[i] ^ a[i - 1];
//     int sum = 0;
//     for (int i = 1; i <= n + 1; i++) sum += a[i];
//     int mx = 0;
//     for (int i = 0; i <= k; i++) {
//         int c = 0;
//         for (int j = b[i] + 1; j <= b[i + 1]; j++) c += a[j];
//         mx = std::max(mx, c);
//     }
//     std::cout << std::max(sum / 2, mx) << "\n";
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

// 60. https://codeforces.com/contest/2225/problem/A
// #include <bits/stdc++.h>
// #define int long long
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int x, y;
//         std::cin >> x >> y;
//         if (const int t = y / x; t >= 3) std::cout << "YES\n";
//         else std::cout << "NO\n";
//     }
//     return 0;
// }

// 61. https://codeforces.com/contest/2225/problem/B
// #include <bits/stdc++.h>
// #define int long long
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         std::string s;
//         std::cin >> s;
//         int cnt = 0;
//         for (int i = 0; i < s.size() - 1; i++) {
//             if (s[i] == s[i + 1]) cnt++;
//         }
//         if (cnt <= 2) std::cout << "YES\n";
//         else std::cout << "NO\n";
//     }
//     return 0;
// }

// 62. https://codeforces.com/problemset/problem/2225/C
// #include <bits/stdc++.h>
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n;
//         std::cin >> n;
//         std::vector<std::string> s(2);
//         std::cin >> s[0] >> s[1];
//         std::vector<int> dp(n);
//         dp[0] = s[0][0] != s[1][0];
//         dp[1] = std::min(dp[0] + (s[0][1] != s[1][1]), (s[0][0] != s[0][1]) + (s[1][0] != s[1][1]));
//         for (int i = 2; i < n; i++) {
//             dp[i] = std::min(dp[i - 1] + (s[0][i] != s[1][i]),
//                 dp[i - 2] + (s[0][i] != s[0][i - 1]) + (s[1][i] != s[1][i - 1]));
//         }
//         std::cout << dp[n - 1] << "\n";
//     }
//     return 0;
// }

// 63. https://www.luogu.com.cn/problem/AT_abc445_e
// #include <bits/stdc++.h>
// #define int long long
// constexpr int N = 1e4, mod = 998244353;
//
// int primes[N], cnt, vis[N];
//
// void euler() {
//     for (int i = 2; i < N; i++) {
//         if (!vis[i]) primes[cnt++] = i;
//         for (int j = 0; primes[j] * i < N; j++) {
//             vis[i * primes[j]] = 1;
//             if (i % primes[j] == 0) break;
//         }
//     }
// }
//
// struct node {
//     int mx1 = -1, mx2 = -1;
//     void insert(const int x) {
//         if (x >= mx1) {
//             mx2 = mx1;
//             mx1 = x;
//         } else {
//             mx2 = std::max(mx2, x);
//         }
//     }
// };
//
// int ksm(int a, int k, const int mo) {
//     int res = 1;
//     while (k) {
//         if (k & 1) res = res * a % mo;
//         a = a * a % mo;
//         k >>= 1;
//     }
//     return res;
// }
//
// int inv(const int a) {
//     return ksm(a, mod - 2, mod);
// }
//
// void solve() {
//     std::unordered_map<int, node> mp;
//     int n;
//     std::cin >> n;
//     std::vector<std::unordered_map<int, int>> mp2(n + 1);
//     std::vector<int> a(n + 1);
//     for (int i = 1; i <= n; i++) std::cin >> a[i];
//     for (int i = 1; i <= n; i++) {
//         int t = a[i];
//         for (int j = 0; primes[j] * primes[j] <= t && j < cnt; j++) {
//             if (t % primes[j] == 0) {
//                 int cn = 0;
//                 while (t % primes[j] == 0) {
//                     cn++;
//                     t /= primes[j];
//                 }
//                 mp[primes[j]].insert(cn);
//                 mp2[i][primes[j]] = cn;
//             }
//         }
//         if (t > 1) mp[t].insert(1), mp2[i][t] = 1;
//     }
//     int ans = 1;
//     for (const auto& [p, no] : mp) {
//         if (no.mx1 != -1) ans = ans * ksm(p, no.mx1, mod) % mod;
//     }
//     for (int i = 1; i <= n; i++) {
//         int t = ans;
//         for (const auto& [p, cn] : mp2[i]) {
//             if (mp[p].mx1 == cn && mp[p].mx2 != mp[p].mx1) {
//                 t = t * inv(ksm(p, cn, mod)) % mod;
//                 t = t * ksm(p, std::max(mp[p].mx2, 0LL), mod) % mod;
//             }
//         }
//         std::cout << t << " ";
//     }
//     std::cout << "\n";
// }
//
// signed main() {
//     euler();
//     int T;
//     std::cin >> T;
//     while (T--) {
//         solve();
//     }
//     return 0;
// }

// 64. https://atcoder.jp/contests/abc445/tasks/abc445_f
// #include <bits/stdc++.h>
// #define int long long
// constexpr int inf = 1e18;
//
// std::vector<std::vector<int>> multi(std::vector<std::vector<int>> A, std::vector<std::vector<int>> B, int N) {
//     std::vector<std::vector<int>> res(N + 1, std::vector<int>(N + 1, inf));
//     for (int i = 1; i <= N; i++) {
//         for (int j = 1; j <= N; j++) {
//             for (int k = 1; k <= N; k++) {
//                 res[i][j] = std::min(res[i][j], A[i][k] + B[k][j]);
//             }
//         }
//     }
//     return res;
// }
//
// std::vector<std::vector<int>> ksm(std::vector<std::vector<int>> A, int K, int N) {
//     std::vector<std::vector<int>> res(N + 1, std::vector<int>(N + 1, inf));
//     for (int i = 1; i <= N; i++) res[i][i] = 0;
//     while (K) {
//         if (K & 1) res = multi(res, A, N);
//         A = multi(A, A, N);
//         K >>= 1;
//     }
//     return res;
// }
//
// signed main() {
//     int n, k;
//     std::cin >> n >> k;
//     std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1));
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= n; j++)
//             std::cin >> a[i][j];
//     a = ksm(a, k, n);
//     for (int i = 1; i <= n; i++) {
//         std::cout << a[i][i] << "\n";
//     }
//     return 0;
// }

// 65. https://www.luogu.com.cn/problem/AT_abc444_e
// #include <bits/stdc++.h>
// #define int long long
//
// signed main() {
//     int n, d;
//     std::cin >> n >> d;
//     std::vector<int> a(n + 1);
//     for (int i = 1; i <= n; i++) std::cin >> a[i];
//     std::multiset<int> s;
//     int l = 1, r;
//     int ans = 0;
//     auto get_mx = [&](const int x) -> int {
//         int mx = 1e18;
//         auto it = s.lower_bound(a[r]);
//         if (it != s.end()) mx = std::min(mx, std::abs(a[r] - *it));
//         if (it != s.begin()) {
//             --it;
//             mx = std::min(mx, std::abs(a[r] - *it));
//         }
//         return mx;
//     };
//     for (r = 1; r <= n; r++) {
//         int mx = get_mx(a[r]);
//         if (mx >= d) ans += r - l + 1;
//         else {
//             do {
//                 s.erase(s.find(a[l++]));
//             } while (get_mx(a[r]) < d);
//             ans += r - l + 1;
//         }
//         s.insert(a[r]);
//     }
//     std::cout << ans << "\n";
//     return 0;
// }

// 66. https://codeforces.com/contest/2225/problem/D
// #include <bits/stdc++.h>
// #define int long long
// constexpr int mod = 998244353;
//
// int calc(const int r, const int m) {
//     if (r < m) return 0;
//     return (1 + (r - m) / 4) % mod;
// }
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n, x;
//         std::cin >> n >> x;
//         int ans = 0;
//         for (int i = 1; i <= 3; i += 2) {
//             ans += (calc(x - 1, i) + (i == 3)) * (calc(n, i) - calc(x - 1, i) + mod);
//             ans %= mod;
//         }
//         std::cout << ans << "\n";
//     }
//     return 0;
// }

// 67. https://www.luogu.com.cn/problem/CF2227F
// #include <bits/stdc++.h>
// #define int long long
//
// class BitTree {
// public:
//     explicit BitTree(const int n) : a(n + 1), cnt(n + 1) { }
//
//     void add(const int p, const int x) {
//         for (int i = p; i < a.size(); i += i & -i) {
//             cnt[i] += 1;
//             a[i] += x;
//         }
//     }
//
//     [[nodiscard]] int sum_cnt(const int x) const {
//         int res = 0;
//         for (int i = x; i > 0; i -= i & -i) {
//             res += cnt[i];
//         }
//         return res;
//     }
//
//     [[nodiscard]] int sum(const int x) const {
//         int res = 0;
//         for (int i = x; i > 0; i -= i & -i) {
//             res += a[i];
//         }
//         return res;
//     }
//
//     [[nodiscard]] int sum(const int l, const int r) const {
//         if (r < l) return 0;
//         return sum(r) - sum(l - 1);
//     }
//
//     [[nodiscard]] int sum_cnt(const int l, const int r) const {
//         if (r < l) return 0;
//         return sum_cnt(r) - sum_cnt(l - 1);
//     }
//
// private:
//     std::vector<int> a;
//     std::vector<int> cnt;
// };
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n;
//         std::cin >> n;
//         std::vector<int> a(n + 1);
//         for (int i = 1; i <= n; i++) std::cin >> a[i];
//         BitTree bit_tree(n);
//         std::vector<int> b(n + 1), c(n + 1);
//         int ans = 0;
//         for (int i = 1; i <= n; i++) {
//             int cnt = bit_tree.sum_cnt(a[i], n);
//             int sum = bit_tree.sum(a[i], n);
//             b[i] = sum - cnt * a[i];
//             ans += b[i];
//             cnt = bit_tree.sum_cnt(a[i] - 1, n);
//             sum = bit_tree.sum(a[i] - 1, n);
//             c[i] = sum - cnt * (a[i] - 1);
//             bit_tree.add(a[i], a[i]);
//         }
//         BitTree bit_tree2(n);
//         const int base = ans;
//         for (int i = n; i >= 1; i--) {
//             ans = std::max(ans, base - b[i] + c[i] - bit_tree2.sum_cnt(0, a[i] - 1));
//             bit_tree2.add(a[i], 1);
//         }
//         std::cout << ans << "\n";
//     }
//     return 0;
// }

// 68. https://www.luogu.com.cn/problem/AT_abc443_f
// #include <bits/stdc++.h>
// #define int long long
//
// void solve() {
//     int n;
//     std::cin >> n;
//     if (n % 10 == 0) {
//         std::cout << -1 << "\n";
//         return;
//     }
//     if (n < 10) {
//         std::cout << n << "\n";
//         return;
//     }
//     std::vector vis(n, std::vector<bool>(10));
//     std::queue<std::pair<int, int>> q;
//     std::vector pre(n, std::vector<std::pair<int, int>>(10));
//     for (int i = 1; i < 10; ++i) {
//         vis[i][i] = true;
//         q.emplace(i, i);
//         pre[i][i] = {-1, -1};
//     }
//     while (!q.empty()) {
//         const auto [mod, ed] = q.front();
//         q.pop();
//         for (int i = ed; i < 10; i++) {
//             const int m = (10 * mod + i) % n;
//             if (m == 0) {
//                 std::string ans = std::to_string(i);
//                 int cur_mod = mod, cur_ed = ed;
//                 while (cur_ed != -1) {
//                     ans += std::to_string(cur_ed);
//                     const int t = cur_mod;
//                     cur_mod = pre[cur_mod][cur_ed].first;
//                     cur_ed = pre[t][cur_ed].second;
//                 }
//                 std::reverse(ans.begin(), ans.end());
//                 std::cout << ans << "\n";
//                 return;
//             }
//             if (!vis[m][i]) {
//                 vis[m][i] = true;
//                 q.emplace(m, i);
//                 pre[m][i] = {mod, ed};
//             }
//         }
//     }
//     std::cout << -1 << "\n";
// }
//
// signed main() {
//     solve();
//     return 0;
// }

// 69. https://www.luogu.com.cn/problem/AT_abc443_e
// #include <bits/stdc++.h>
//
// void solve() {
//     int n, c;
//     std::cin >> n >> c;
//     std::vector mp(n + 1, std::vector<char>(n + 1));
//     std::vector vis(n + 1, std::vector<int>(n + 1));
//     std::vector ok(n + 1, std::vector<bool>(n + 1));
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= n; j++)
//             std::cin >> mp[i][j];
//     for (int i = 1; i <= n; i++) {
//         int j = n;
//         while (j >= 1 && mp[j][i] == '.') j--;
//         ok[j][i] = true;
//     }
//     std::queue<std::pair<int, int>> q;
//     q.emplace(n, c);
//     while (!q.empty()) {
//         const auto [x, y] = q.front();
//         q.pop();
//         if (mp[x][y] == '#') {
//             int j = x - 1;
//             while (j >= 1 && mp[j][y] == '.') j--;
//             ok[j][y] = true;
//         }
//         for (int i = -1; i <= 1; ++i) {
//             int nx = x - 1, ny = y + i;
//             if (ny < 1 || ny > n) continue;
//             if (vis[nx][ny]) continue;
//             if (mp[nx][ny] == '#' && !ok[nx][ny]) continue;
//             vis[nx][ny] = 1;
//             if (nx == 1) continue;
//             q.emplace(nx, ny);
//         }
//         if (mp[x][y] == '#' && mp[x - 1][y] == '#' && !vis[x - 1][y]) {
//             vis[x - 1][y] = 1;
//             if (x != 2) q.emplace(x - 1, y);
//         }
//     }
//     for (int i = 1; i <= n; i++) std::cout << vis[1][i];
//     std::cout << "\n";
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

// 70. https://codeforces.com/contest/2227/problem/E
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
//         std::vector<int> mi(n + 1);
//         mi[n] = a[n];
//         for (int i = n - 1; i >= 1; i--) mi[i] = std::min(mi[i + 1], a[i]);
//         int ans = 0;
//         for (int i = 1; i <= n; i++) ans += a[i] - mi[i];
//         int t = ans;
//         std::vector<int> l(n + 1);
//         std::stack<int> stk;
//         stk.push(0);
//         for (int i = 1; i <= n; i++) {
//             while (a[stk.top()] >= a[i]) stk.pop();
//             l[i] = stk.top();
//             stk.push(i);
//         }
//         for (int i = 1; i <= n; i++) {
//             if (a[i] == mi[i]) {
//                 ans = std::max(ans, t + i - 1 - l[i]);
//             }
//         }
//         std::cout << ans << "\n";
//     }
//     return 0;
// }

// 71. https://qoj.ac/contest/3758/problem/18273?locale=zh-cn 南昌2026邀请B题
// #include <bits/stdc++.h>
// #define int long long
//
// signed main() {
//     int T;
//     std::cin >> T;
//     std::unordered_map<char, int> mp = {{'R', 0}, {'Y', 1}, {'G', 2}, {'B', 3}};
//     while (T--) {
//         int n;
//         std::cin >> n;
//         n *= 4;
//         std::vector<std::pair<int, char>> a(n + 1);
//         for (int i = 1; i <= n; i++) {
//             std::cin >> a[i].first >> a[i].second;
//         }
//         std::string ans = "YES";
//         for (int i = 1; i <= n; i++) {
//             for (int j = i + 1; j <= n; j++) {
//                 if (a[i].second == a[j].second) continue;
//                 if (mp[a[i].second] > mp[a[j].second] && a[i].first != a[j].first) {
//                     ans = "NO";
//                     break;
//                 }
//             }
//             if (ans == "NO") break;
//         }
//         std::cout << ans << "\n";
//     }
//     return 0;
// }

// 72. https://qoj.ac/contest/3758/problem/18279   2026南昌邀请赛H
// #include <bits/stdc++.h>
// #define int long long
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n, k;
//         std::cin >> n >> k;
//         std::vector<int> a(n + 1);
//         for (int i = 1; i <= n; i++) std::cin >> a[i];
//         bool xian_win = false;
//         for (int i = 1; i <= k; i <<= 1) {
//             int sum = 0;
//             for (int j = 1; j <= n; j++) {
//                 sum += a[j] / i;
//             }
//             if (sum & 1) {
//                 xian_win = true;
//                 break;
//             }
//         }
//         if (xian_win) std::cout << "Alice\n";
//         else std::cout << "Bob\n";
//     }
//     return 0;
// }

// 73. https://qoj.ac/contest/3758/problem/18280   2026南昌邀请赛I
// #include <bits/stdc++.h>
// #define int long long
// constexpr int inf = 1e18;
//
// signed main() {
//     int l, d, t0, t1, t2;
//     std::cin >> l >> d >> t0 >> t1 >> t2;
//     std::string s;
//     std::cin >> s;
//     std::vector<int> a(l + 1);
//     for (int i = 1; i <= l; i++) {
//         if (s[i - 1] == '0') a[i] = t0;
//         else if (s[i - 1] == '1') a[i] = t1;
//         else a[i] = t2;
//     }
//     std::vector dp(l + 1, std::vector<int>(4, inf));
//     dp[0][0] = 0;
//     for (int i = 1; i <= l; i++) {
//         for (int j = 0; j <= 3; j++) {
//             dp[i][j] = std::min(dp[i][j], dp[i - 1][j] + a[i]);
//             if (i - d >= 0 && j) {
//                 dp[i][j] = std::min(dp[i][j], dp[i -d][j - 1]);
//             }
//         }
//     }
//     int ans = std::min({dp[l][0], dp[l][1], dp[l][2], dp[l][3]});
//     for (int i = l - d; i <= l; i++) {
//         ans = std::min({ans, dp[i][0], dp[i][1], dp[i][2]});
//     }
//     std::cout << ans << "\n";
//     return 0;
// }

// 74. https://qoj.ac/contest/3758/problem/18274 2026南昌邀请赛C
// #include <bits/stdc++.h>
// #define int long long
// constexpr int inf = 1e9;
//
// struct Mat {
//     int n;
//     std::vector<std::vector<int>> a;
//     explicit Mat(const int _n) : n(_n), a(n + 1, std::vector<int>(n + 1, inf)) {}
//     Mat operator*(const Mat& mat) const {
//         Mat res(n);
//         for (int i = 1; i <= n; i++) {
//             for (int j = 1; j <= n; j++) {
//                 for (int k = 1; k <= n; k++) {
//                      res.a[i][j] = std::min(res.a[i][j], std::max(a[i][k], mat.a[k][j]));
//                 }
//             }
//         }
//         return res;
//     }
//
//     [[nodiscard]] Mat pow(int k) const {
//         Mat res(n);
//         Mat x = *this;
//         for (int i = 1; i <= n; i++) res.a[i][i] = 0;
//         while (k) {
//             if (k & 1) res = res * x;
//             x = x * x;
//             k >>= 1;
//         }
//         return res;
//     }
// };
//
// signed main() {
//     std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
//     int n, m;
//     std::cin >> n >> m;
//     Mat a(n);
//     for (int i = 1, u, v; i <= m; i++) {
//         std::cin >> u >> v;
//         a.a[u][v] = 0;
//     }
//     int k;
//     std::cin >> k;
//     for (int i = 1, u, v; i <= k; i++) {
//         std::cin >> u >> v;
//         a.a[u][v] = std::min(a.a[u][v], i);
//     }
//     int q, w;
//     std::cin >> q >> w;
//     const auto res = a.pow(w);
//     for (int i = 1; i <= q; i++) {
//         int s, t;
//         std::cin >> s >> t;
//         if (res.a[s][t] < inf) std::cout << res.a[s][t] << "\n";
//         else std::cout << "-1\n";
//     }
//     return 0;
// }

// 75. https://www.luogu.com.cn/problem/AT_abc440_e
// #include <bits/stdc++.h>
// #define int long long
//
// struct node {
//     int cnt, sum, id;
//     bool operator<(const node& other) const {
//         return sum < other.sum;
//     }
// };
//
// signed main() {
//     int n, k, x;
//     std::cin >> n >> k >> x;
//     std::vector<int> a(n + 1);
//     for (int i = 1; i <= n; i++) std::cin >> a[i];
//     std::sort(a.begin() + 1, a.end(), std::greater<>());
//     const int mx = k * a[1];
//     std::cout << mx << "\n";
//     if (x == 1) return 0;
//     std::priority_queue<node> q;
//     q.push({1, mx - a[1] + a[2], 2});
//     for (int i = 1; i < x; i++) {
//         const auto [cnt, sum, id] = q.top();
//         q.pop();
//         std::cout << sum << "\n";
//         if (cnt < k) q.push({cnt + 1, sum - a[1] + a[id], id});
//         if (id < n) q.push({cnt, sum - a[id] + a[id + 1], id + 1});
//     }
//     return 0;
// }

// 76. https://qoj.ac/contest/3758/problem/18281
// #include <bits/stdc++.h>
// #define int long long
// constexpr int N = 2e6 + 10;
//
// struct DSU {
//     int n;
//     std::vector<int> fa;
//     explicit DSU(const int _n) : n(_n), fa(n + 1) {
//         std::iota(fa.begin(), fa.end(), 0);
//     }
//
//     int find(const int x) {
//         if (x == fa[x]) return x;
//         return fa[x] = find(fa[x]);
//     }
// };
//
// signed main() {
//     std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
//     int n, q;
//     std::cin >> n >> q;
//     std::vector<int> a(n + 1);
//     std::vector<int> vis(N);
//     DSU dsu(N);
//     std::vector<int> node(N), fa(N), deep(N);
//     std::vector up(N, std::vector<int>(22));
//     for (int i = 1; i <= n; i++) std::cin >> a[i], vis[a[i]] = 1;
//     const int mx = *std::max_element(a.begin() + 1, a.end());
//     int cnt = mx;
//     for (int i = mx; i >= 1; i--) {
//         int fst = -1;
//         for (int j = i; j <= mx; j += i) {
//             if (!vis[j]) continue;
//             if (fst == -1) fst = j;
//             else {
//                 const int fax = dsu.find(fst);
//                 if (const int fay = dsu.find(j); fax != fay) {
//                     ++cnt;
//                     dsu.fa[fax] = cnt;
//                     dsu.fa[fay] = cnt;
//                     node[cnt] = i;
//                     fa[fax] = cnt;
//                     fa[fay] = cnt;
//                 }
//             }
//         }
//     }
//     for (int i = cnt; i >= 1; i--) {
//         if (fa[i] == 0) {
//             up[i][0] = i;
//             deep[i] = 0;
//         } else {
//             deep[i] = deep[fa[i]] + 1;
//             up[i][0] = fa[i];
//         }
//         for (int j = 1; j <= 21; j++) {
//             up[i][j] = up[up[i][j - 1]][j - 1];
//         }
//     }
//     while (q--) {
//         int x, y;
//         std::cin >> x >> y;
//         x = a[x], y = a[y];
//         if (x == y) std::cout << x << "\n";
//         else {
//             if (deep[x] < deep[y]) std::swap(x, y);
//             const int deep_delta = deep[x] - deep[y];
//             for (int i = 0; i <= 21; i++) {
//                 if (deep_delta >> i & 1) x = up[x][i];
//             }
//             int lca;
//             if (x == y) lca = x;
//             else {
//                 for (int i = 21; i >= 0; i--) {
//                     if (up[x][i] != up[y][i]) {
//                         x = up[x][i];
//                         y = up[y][i];
//                     }
//                 }
//                 lca = up[x][0];
//             }
//             std::cout << node[lca] << "\n";
//         }
//     }
//     return 0;
// }

// 77. https://qoj.ac/contest/3758/problem/18278  由 AI 生成
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 200005;

struct Node {
    int a;       // 未匹配的 ')' 数量
    int b;       // 未匹配的 '(' 数量
    int len;     // 区间长度
    int ans;     // 区间内最长合法连续子串长度
    bool is_leaf;
    char c;
} tree[MAXN * 4];

string s;

// 获取 u 节点消耗最后 k 个 '(' 后，连同前面的有效括号构成的后缀长度
int query_suff(int u, int k) {
    if (tree[u].is_leaf) {
        if (tree[u].c == ')') return 0;
        return k == 1 ? 1 : 0;
    }
    int lc = 2 * u, rc = 2 * u + 1;

    // 如果需要的 '(' 数量比右孩子少，完全在右侧解决
    if (k < tree[rc].b) {
        return query_suff(rc, k);
    }
    // 如果相等，且右侧自带的 ')' 超出了左侧能提供的 '('，导致无法继续向左穿透
    else if (k == tree[rc].b && tree[rc].a > tree[lc].b) {
        return query_suff(rc, k);
    }
    // 向左穿透：吃满右侧，并将剩下的需求和右侧的内部需求丢给左侧
    else {
        return tree[rc].len + query_suff(lc, tree[rc].a + k - tree[rc].b);
    }
}

// 获取 u 节点消耗最前 k 个 ')' 后，连同后面的有效括号构成的前缀长度
int query_pref(int u, int k) {
    if (tree[u].is_leaf) {
        if (tree[u].c == '(') return 0;
        return k == 1 ? 1 : 0;
    }
    int lc = 2 * u, rc = 2 * u + 1;

    // 逻辑与 query_suff 完全对称
    if (k < tree[lc].a) {
        return query_pref(lc, k);
    } else if (k == tree[lc].a && tree[lc].b > tree[rc].a) {
        return query_pref(lc, k);
    } else {
        return tree[lc].len + query_pref(rc, tree[lc].b + k - tree[lc].a);
    }
}

// 向上合并逻辑
void push_up(int u) {
    int lc = 2 * u, rc = 2 * u + 1;
    tree[u].len = tree[lc].len + tree[rc].len;
    tree[u].a = tree[lc].a + max(0, tree[rc].a - tree[lc].b);
    tree[u].b = tree[rc].b + max(0, tree[lc].b - tree[rc].a);

    int k = min(tree[lc].b, tree[rc].a);
    int boundary = query_suff(lc, k) + query_pref(rc, k);
    tree[u].ans = max({tree[lc].ans, tree[rc].ans, boundary});
}

// 建树
void build(int u, int start, int end) {
    if (start == end) {
        tree[u].is_leaf = true;
        tree[u].c = s[start];
        tree[u].len = 1;
        tree[u].ans = 0;
        if (s[start] == '(') {
            tree[u].a = 0; tree[u].b = 1;
        } else {
            tree[u].a = 1; tree[u].b = 0;
        }
        return;
    }
    int mid = start + (end - start) / 2;
    build(2 * u, start, mid);
    build(2 * u + 1, mid + 1, end);
    tree[u].is_leaf = false;
    push_up(u);
}

// 单点修改翻转
void update(int u, int start, int end, int pos) {
    if (start == end) {
        if (tree[u].c == '(') {
            tree[u].c = ')';
            tree[u].a = 1; tree[u].b = 0;
        } else {
            tree[u].c = '(';
            tree[u].a = 0; tree[u].b = 1;
        }
        return;
    }
    int mid = start + (end - start) / 2;
    if (pos <= mid) update(2 * u, start, mid, pos);
    else update(2 * u + 1, mid + 1, end, pos);
    push_up(u);
}

// 用于收集查询覆盖到的线段树节点
struct QueryNode {
    int a, b, len, ans, node_idx;
};
vector<QueryNode> q_nodes;

// 收集区间
void collect_nodes(int u, int start, int end, int l, int r) {
    if (l <= start && end <= r) {
        q_nodes.push_back({tree[u].a, tree[u].b, tree[u].len, tree[u].ans, u});
        return;
    }
    int mid = start + (end - start) / 2;
    if (l <= mid) collect_nodes(2 * u, start, mid, l, r);
    if (r > mid) collect_nodes(2 * u + 1, mid + 1, end, l, r);
}

// 供区间查询使用的状态记录
struct State {
    int a, b, len, ans;
};

// 严谨的区间查询与合并
int solve_query(int l, int r, int n) {
    q_nodes.clear();
    collect_nodes(1, 1, n, l, r);
    if (q_nodes.empty()) return 0;

    // 动态维护前缀的状态
    vector<State> prefs(q_nodes.size());
    prefs[0] = {q_nodes[0].a, q_nodes[0].b, q_nodes[0].len, q_nodes[0].ans};

    for (size_t i = 1; i < q_nodes.size(); i++) {
        int a1 = prefs[i-1].a, b1 = prefs[i-1].b;
        int a2 = q_nodes[i].a, b2 = q_nodes[i].b;

        prefs[i].a = a1 + max(0, a2 - b1);
        prefs[i].b = b2 + max(0, b1 - a2);
        prefs[i].len = prefs[i-1].len + q_nodes[i].len;

        int k = min(b1, a2);

        // 按照与 query_suff 完全相同的阻断逻辑计算左侧后缀长度
        int suff = 0;
        int cur_k = k;
        for (int j = i - 1; j >= 0; j--) {
            int u = q_nodes[j].node_idx;
            int left_b = (j > 0) ? prefs[j-1].b : 0;

            if (cur_k < tree[u].b) {
                suff += query_suff(u, cur_k);
                break;
            } else if (cur_k == tree[u].b && tree[u].a > left_b) {
                suff += query_suff(u, cur_k);
                break;
            } else {
                suff += tree[u].len;
                cur_k = tree[u].a + cur_k - tree[u].b;
            }
        }

        int pref = query_pref(q_nodes[i].node_idx, k);
        prefs[i].ans = max({prefs[i-1].ans, q_nodes[i].ans, suff + pref});
    }

    return prefs.back().ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    cin >> s;
    s = " " + s; // 1-based index mapping

    build(1, 1, n);

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int k;
            cin >> k;
            update(1, 1, n, k);
        } else if (op == 2) {
            int l, r;
            cin >> l >> r;
            cout << solve_query(l, r, n) << "\n";
        }
    }

    return 0;
}






