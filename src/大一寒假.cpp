// AcWing课程代码练习（寒假我努力的见证）

// 快速排序 2025.1.8
// #include <bits/stdc++.h>
// using namespace std;
//
// void quick_sort(vector<int>& a, int l, int r) {
//     if (l >= r) return;
//     int x = a[l + r >> 1];
//     int i = l - 1, j = r + 1;
//     while (i < j) {
//         do i++; while (a[i] < x);
//         do j--; while (a[j] > x);ha
//         if (i < j) swap(a[i], a[j]);
//     }
//     quick_sort(a, l, j);
//     quick_sort(a, j + 1, r);
// }
//
// int main() {
//     vector<int> a = {2, 1};
//     // vector<int> a = {3, 5, 32, 2, 432, 543, 2, 2, 2, 4543, 34, 23, 334, 212, 43, 2};
//     quick_sort(a, 0, a.size() - 1);
//     for (int i : a) cout << i << ' ';
//     return 0;
// }

// 第k个数 2025.1.8
// #include <bits/stdc++.h>
// using namespace std;
//
// int quick_sort(vector<int>& a, int l, int r, int k) {
//     if (l == r) return a[l];
//     int x = a[l], i = l - 1, j = r + 1;
//     while (i < j) {
//         while (a[++i] < x);
//         while (a[--j] > x);
//         if (i < j) swap(a[i], a[j]);
//     }
//
//     int sl = j - l + 1;
//     if (k <= sl) return quick_sort(a, l, j, k);
//     else return quick_sort(a, j + 1, r, k - sl);
// }
//
// int main() {
//     int n, k;
//     cin >> n >> k;
//     vector<int> a(n);
//     for (int i = 0; i < n; i++) cin >> a[i];
//     cout << quick_sort(a, 0, n - 1, k) << endl;
//     return 0;
// }

// 归并排序  2025.1.9
//  #include <bits/stdc++.h>
//  using namespace std;
//
//  void merge_sort(vector<int>& a, int l, int r) {
//      if (l >= r) return;
//      int mid = l + r >> 1;
//      merge_sort(a, l, mid); merge_sort(a, mid + 1, r);
//
//      vector<int> temp(r - l + 1);
//      int k = 0, i = l, j = mid + 1;
//      while (i <= mid && j <= r) {
//          if (a[i] <= a[j]) temp[k++] = a[i++];
//          else temp[k++] = a[j++];
//      }
//
//      while (i <= mid) temp[k++] = a[i++];
//      while (j <= r) temp[k++] = a[j++];
//
//      for (i = l, j = 0; i <= r; i++, j++) a[i] = temp[j];
//  }
//
//  int main() {
//      int n;
//      cin >> n;
//      vector<int> a(n);
//      for (int i = 0; i < n; i++) cin >> a[i];
//      merge_sort(a, 0, n - 1);
//      for (int i : a) cout << i << ' ';
//      return 0;
//  }

// 求逆序对数量 2025.1.9
//  #include <bits/stdc++.h>
//  using namespace std;
//
//  #define int long long
//
//  int merge_sort(vector<int>& a, int l, int r) {
//      if (l >= r) return 0;
//      int mid = l + r >> 1;
//      int res = merge_sort(a, l, mid) + merge_sort(a, mid + 1, r);
//
//      int i = l, j = mid + 1, k = 0;
//      vector<int> temp(r - l + 1);
//      while (i <= mid && j <= r) {
//          if (a[i] <= a[j]) temp[k++] = a[i++];
//          else {
//              temp[k++] = a[j++];
//              res += mid - i + 1;
//          }
//      }
//
//      while (i <= mid) temp[k++] = a[i++];
//      while (j <= r) temp[k++] = a[j++];
//
//      for (i = l, j = 0; i <= r; i++, j++) a[i] = temp[j];
//      return res;
//  }
//
//  signed main() {
//      int n;
//      cin >> n;
//      vector<int> a(n);
//      for (int i = 0; i < n; i++) cin >> a[i];
//      cout << merge_sort(a, 0, n - 1) << endl;
//      return 0;
//  }

// 二分 数的范围 2025.1.9
// #include <bits/stdc++.h>
// using namespace std;
//
// int binary_search1(vector<int>& a, int l, int r, int k) {
//     int ans = 0;
//     while (l <= r) {
//         int mid = l + r >> 1;
//         if (a[mid] <= k) {
//             ans = mid;
//             l = mid + 1;
//         } else {
//             r = mid - 1;
//         }
//     }
//     if (a[ans] == k) return ans;
//     return -1;
// }
//
//
// int binary_search2(vector<int>& a, int l, int r, int k) {
//     int ans = 0;
//     while (l <= r) {
//         int mid = l + r >> 1;
//         if (a[mid] >= k) {
//             ans = mid;
//             r = mid - 1;
//         } else {
//             l = mid + 1;
//         }
//     }
//     if (a[ans] == k) return ans;
//     return -1;
// }
//
// int main() {
//     int n, q;
//     cin >> n >> q;
//     vector<int> a(n);
//     for (int i = 0; i < n; i++) cin >> a[i];
//     while (q--) {
//         int x;
//         cin >> x;
//         cout << binary_search2(a, 0, n - 1, x) << ' ' << binary_search1(a, 0, n - 1, x) << endl;
//     }
//     return 0;
// }

// 二分 数的三次方根 2025.1.9
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//     double x;
//     cin >> x;
//     double l = -10000, r = 10000;
//     while (abs(l - r) > 1e-7) {
//         double mid = (l + r) / 2;
//         if (mid * mid * mid <= x) {
//             l = mid;
//         } else {
//             r = mid;
//         }
//     }
//     printf("%.6lf", l);
//     return 0;
// }

// 子矩阵的和 2025.1.9
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//     int n, m, q;
//     cin >> n >> m >> q;
//     vector<vector<int>> a(n + 1, vector<int>(m + 1));
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= m; j++) {
//             cin >> a[i][j];
//         }
//     }
//
//     vector<vector<int>> sum(n + 1, vector<int>(m + 1));
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= m; j++) {
//             sum[i][j] = a[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
//         }
//     }
//
//     while (q--) {
//         int x1, x2, y1, y2;
//         cin >> x1 >> y1 >> x2 >> y2;
//         cout << sum[x2][y2] + sum[x1 - 1][y1 - 1] - sum[x1 - 1][y2] - sum[x2][y1 - 1] << endl;
//     }
//
//     return 0;
// }

// 线性筛质数 2025.1.10
// 自带质因数分解
// #include <bits/stdc++.h>
// using namespace std;
//
// void get_primes(vector<int>& res, vector<int>& not_prime, int maxn) {
//     not_prime.resize(maxn + 1);
//     for (int i = 2; i <= maxn; i++) {
//         if (!not_prime[i]) res.push_back(i);
//         for (int j = 0; res[j] <= maxn / i; j++) {
//             not_prime[i * res[j]] = res[j];
//             if (i % res[j] == 0) break;
//         }
//     }
// }
//
// void print_fenjie(vector<int>& min_yinzi, int n) {
//     while (min_yinzi[n] != 0) {
//         cout << min_yinzi[n] << 'x';
//         n /= min_yinzi[n];
//     }
//     cout << n;
// }
//
// int main() {
//     vector<int> primes;
//     vector<int> min_yinzi;
//     get_primes(primes, min_yinzi, 1e8);
//     for (int i = 2; i <= 100000000; i++) {
//         cout << i << '=';
//         print_fenjie(min_yinzi, i);
//         cout << endl;
//     }
//     return 0;
// }

// 差分 2025.1.10
// #include <bits/stdc++.h>
// using namespace std;
//
// const int N = 100010;
//
// int n, m, l, r, c;
// int a[N], b[N];
//
// void insert(int l, int r, int c) {
//     b[l] += c;
//     b[r + 1] -= c;
// }
//
// int main() {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++) cin >> a[i];
//     for (int i = 1; i <= n; i++) insert(i, i, a[i]);
//     while (m--) {
//         cin >> l >> r >> c;
//         insert(l, r, c);
//     }
//     for (int i = 1; i <= n; i++) b[i] += b[i - 1];
//     for (int i = 1; i <= n; i++) cout << b[i] << ' ';
//     return 0;
// }

// 最长连续不重复子序列 2025.1.11
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     unordered_map<int, int> mp;
//     for (int i = 0; i < n; i++) cin >> a[i];
//     int res = 0;
//     for (int i = 0, j = 0; i < n; i++) {
//         mp[a[i]]++;
//         while (mp[a[i]] >= 2) {
//             mp[a[j]]--;
//             j++;
//         }
//         res = max(res, i - j + 1);
//     }
//     cout << res << endl;
//     return 0;
// }

// 数组元素的目标和 2025.1.11
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//     int n, m, x;
//     cin >> n >> m >> x;
//     vector<int> a(n), b(m);
//     for (int i = 0; i < n; i++) cin >> a[i];
//     for (int i = 0; i < m; i++) cin >> b[i];
//     int i = 0, j = m - 1;
//     while (a[i] + b[j] != x) {
//         if (a[i] + b[j] > x) j--;
//         else i++;
//     }
//     cout << i << ' ' << j;
//     return 0;
// }

// 判断子序列 2025.1.11
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//     int n, m;
//     cin >> n >> m;
//     vector<int> a(n), b(m);
//     for (int i = 0; i < n; i++) cin >> a[i];
//     for (int i = 0; i < m; i++) cin >> b[i];
//
//     int i = 0, j = 0;
//     bool yes = false;
//     while (j < m) {
//         if (a[i] == b[j]) {
//             i++;
//             j++;
//         } else {
//             j++;
//         }
//
//         if (i == n) {
//             yes = true;
//             break;
//         }
//     }
//
//     if (yes) cout << "Yes";
//     else cout << "No";
//
//     return 0;
// }

// 二进制中1的个数 2025.1.11
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//     int n, x;
//     cin >> n;
//     while (n--) {
//         cin >> x;
//         int ans = 0;
//         while (x != 0) {
//             ans += (x & 1);
//             x >>= 1;
//         }
//         cout << ans << ' ';
//     }
//     return 0;
// }

// 二进制中1的个数(方法2) 2025.1.11
// #include <bits/stdc++.h>
// using namespace std;
//
// int lowbit(int x) {
//     return x & (~x + 1);
// }
//
// int main() {
//     int n, x;
//     cin >> n;
//     while (n--) {
//         cin >> x;
//         int ans = 0;
//         while (x) {
//             x -= lowbit(x);
//             ans++;
//         }
//         cout << ans << ' ';
//     }
//     return 0;
// }

// 区间和 (离散化) 2025.1.11
// #include <bits/stdc++.h>
// using namespace std;
//
// int find(int x, vector<int>& all) {
//     int l = 0, r = all.size() - 1;
//     while (l <= r) {
//         int mid = l + r >> 1;
//         if (all[mid] >= x) r = mid - 1;
//         else l = mid + 1;
//     }
//     return r + 2;
// }
//
// int main() {
//     int n, m;
//     cin >> n >> m;
//     vector<pair<int, int>> add, qiu;
//     vector<int> all;
//     while (n--) {
//         int x, c;
//         cin >> x >> c;
//         add.push_back({x, c});
//         all.push_back(x);
//     }
//
//     while (m--) {
//         int l, r;
//         cin >> l >> r;
//         qiu.push_back({l, r});
//         all.push_back(l);
//         all.push_back(r);
//     }
//
//     sort(all.begin(), all.end());
//     all.erase(unique(all.begin(), all.end()), all.end());
//
//     vector<int> a(all.size() + 1), s(all.size() + 1);
//     for (auto ad : add) {
//         a[find(ad.first, all)] += ad.second;
//     }
//
//     for (int i = 1; i <= all.size(); i++) {
//         s[i] = s[i - 1] + a[i];
//     }
//
//     for (auto q : qiu) {
//         int l = find(q.first, all);
//         int r = find(q.second, all);
//         cout << s[r] - s[l - 1] << endl;
//     }
//     return 0;
// }

// 给数组去重 2025.1.11
// #include <bits/stdc++.h>
// using namespace std;
//
// int unique(vector<int>& a) {
//     int j = 0;
//     for (int i = 0; i < a.size(); i++)
//         if (!i || a[i] != a[i - 1])
//             a[j++] = a[i];
//
//     return j;
// }
//
// int main() {
//     vector<int> a = {1, 3, 4, 4, 5, 5, 5, 6, 6, 6, 6, 6, 7, 7, 8};
//     int b = unique(a);
//     cout << b << endl;
//     for (int x : a) cout << x << ' ';
//     return 0;
// }

// 区间合并 2025.1.12
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//     int n;
//     cin >> n;
//     vector<pair<int, int>> a(n);
//     for (int i = 0; i < n; i++) {
//         cin >> a[i].first >> a[i].second;
//     }
//     sort(a.begin(), a.end());
//     vector<pair<int, int>> res;
//     int st = a[0].first, ed = a[0].second;
//     for (int i = 1; i < a.size(); i++) {
//         if (ed < a[i].first) {
//             res.emplace_back(st, ed);
//             st = a[i].first; ed = a[i].second;
//         } else {
//             ed = max(a[i].second, ed);
//         }
//     }
//     res.emplace_back(st, ed);
//     cout << res.size() << endl;
//
//     // for (auto q : res) {
//     //     cout << q.first << ' ' << q.second << endl;
//     // }
//     return 0;
// }

// 单链表 2025.1.13
// #include <bits/stdc++.h>
// using namespace std;
//
// const int N = 100010;
// int ne[N], e[N], idx, head;
//
// void add_to_head(int x) {
//     e[idx] = x;
//     ne[idx] = head;
//     head = idx;
//     idx++;
// }
//
// void add(int k, int x) {
//     e[idx] = x;
//     ne[idx] = ne[k];
//     ne[k] = idx;
//     idx++;
// }
//
// void del(int k) {
//     ne[k] = ne[ne[k]];
//     if (k == 0) {
//         head = ne[head];
//     }
// }
//
// int main() {
//     head = -1;
//     idx = 1;
//     int n, k, x;
//     char c;
//     cin >> n;
//     while (n--) {
//         cin >> c;
//         if (c == 'H') {
//             cin >> x;
//             add_to_head(x);
//         } else if (c == 'I') {
//             cin >> k >> x;
//             add(k, x);
//         } else {
//             cin >> k;
//             del(k);
//         }
//     }
//     int next = head;
//     while (next != -1) {
//         cout << e[next] << ' ';
//         next = ne[next];
//     }
//
//     return 0;
// }

// 表达式求值 2025.1.13
// #include <bits/stdc++.h>
// using namespace std;
//
// stack<int> num;
// stack<char> op;
// unordered_map<char, int> pr = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
//
// void calc() {
//     int b = num.top(); num.pop();
//     int a = num.top(); num.pop();
//     char o = op.top(); op.pop();
//
//     if (o == '+') num.push(a + b);
//     else if (o == '-') num.push(a - b);
//     else if (o == '*') num.push(a * b);
//     else if (o == '/') num.push(a / b);
// }
//
// int main() {
//     string s;
//     cin >> s;
//
//     for (int i = 0; i < s.size(); i++) {
//         if (isdigit(s[i])) {
//             int x = 0, j = i;
//             while (j < s.size() && isdigit(s[j])) {
//                 x = 10 * x + s[j] - '0';
//                 j++;
//             }
//             num.push(x);
//             i = j - 1;
//         } else if (s[i] == '(') {
//             op.push('(');
//         } else if (s[i] == ')') {
//             while (op.top() != '(') calc();
//             op.pop();
//         } else {
//             while (!op.empty() && pr[op.top()] >= pr[s[i]]) calc();
//             op.push(s[i]);
//         }
//     }
//
//     while (!op.empty()) calc();
//     cout << num.top() << endl;
//     return 0;
// }

// 昨天太放松了！今天必须卷！！！（2025.1.15）
// 830. 单调栈
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for (int i = 0; i < n; i++) cin >> a[i];
//     stack<int> stk;
//     for (int i = 0; i < n; i++) {
//         while (!stk.empty() && a[i] <= stk.top()) stk.pop();
//         if (stk.empty()) cout << -1 << ' ';
//         else cout << stk.top() << ' ';
//         stk.push(a[i]);
//     }
//     return 0;
// }

// 154. 滑动窗口 2025.1.15
// 还是需要多理解理解
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//     int n, k;
//     cin >> n >> k;
//     vector<int> a(n);
//     for (int i = 0; i < n; i++) cin >> a[i];
//     int hh = 0; int tt = -1;
//     vector<int> q(n + 1);
//     for (int i = 0; i < n; i++) {
//         if (hh <= tt && q[hh] < i - k + 1) hh++;
//         while (hh <= tt && a[q[tt]] >= a[i]) tt--;
//
//         q[++tt] = i;
//         if (i >= k - 1) cout << a[q[hh]] << ' ';
//     }
//     cout << endl;
//
//     hh = 0; tt = -1;
//     for (int i = 0; i < n; i++) {
//         if (hh <= tt && q[hh] < i - k + 1) hh++;
//         while (hh <= tt && a[q[tt]] <= a[i]) tt--;
//
//         q[++tt] = i;
//         if (i >= k - 1) cout << a[q[hh]] << ' ';
//     }
//
//     return 0;
// }

// 831. KMP字符串 2025.1.15
// 有点抽象啊
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//     int n, m;
//     string p, s;
//     cin >> n >> p >> m >> s;
//     p = ' ' + p;
//     s = ' ' + s;
//
//     vector<int> ne(n + 1);
//     for (int i = 2, j = 0; i <= n; i++) {
//         while (j && p[i] != p[j + 1]) j = ne[j];
//         if (p[i] == p[j + 1]) j++;
//         ne[i] = j;
//     }
//
//     for (int i = 1, j = 0; i <= m; i++) {
//         while (j && s[i] != p[j + 1]) j = ne[j];
//         if (s[i] == p[j + 1]) j++;
//
//         if (j == n) {
//             cout << i - n << ' ';
//             j = ne[j];
//         }
//     }
//
//     return 0;
// }

// 835. Trie字符串统计
// 2025.1.16 此方法没有用到 Trie树
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//     int n;
//     char c;
//     string s;
//     cin >> n;
//     unordered_map<string, int> mp;
//     while (n--) {
//         cin >> c >> s;
//         if (c == 'I') {
//             mp[s]++;
//         } else {
//             cout << mp[s] << endl;
//         }
//     }
//     return 0;
// }
// Trie 树写法
// #include <bits/stdc++.h>
// using namespace std;
//
// const int N = 100010;
// int a[N][26], cnt[N], idx;
//
// void cha(string& s) {
//     int q = 0;
//     for (int i = 0; i < s.size(); i++) {
//         int u = s[i] - 'a';
//         if (!a[q][u]) a[q][u] = ++idx;
//         q = a[q][u];
//     }
//     cnt[q]++;
// }
//
// int qurry(string& s) {
//     int q = 0;
//     for (int i = 0; i < s.size(); i++) {
//         int u = s[i] - 'a';
//         if (!a[q][u]) return 0;
//         q = a[q][u];
//     }
//     return cnt[q];
// }
//
// int main() {
//     int n;
//     char c;
//     string s;
//     cin >> n;
//     while (n--) {
//         cin >> c >> s;
//         if (c == 'I') {
//             cha(s);
//         } else {
//             cout << qurry(s) << endl;
//         }
//     }
//     return 0;
// }

// AcWing 143. 最大异或对
// 2025.1.18
// #include <bits/stdc++.h>
// using namespace std;
//
// const int N = 100010;
// int a[N], n, t[30 * N][2], idx;
//
// void insert(int x) {
//     int p = 0;
//     for (int i = 30; i >= 0; i--) {
//         if (!t[p][x >> i & 1]) t[p][x >> i & 1] = ++idx;
//         p = t[p][x >> i & 1];
//     }
// }
//
// int main() {
//     cin >> n;
//     for (int i = 0; i < n; i++) cin >> a[i];
//     for (int i = 0; i < n; i++) insert(a[i]);
//     int res = 0;
//     for (int i = 0; i < n; i++) {
//         int a2 = 0;
//         int p = 0;
//         for (int j = 30; j >= 0; j--) {
//             if (t[p][!(a[i] >> j & 1)]) {
//                 p = t[p][!(a[i] >> j & 1)];
//                 a2 = (!(a[i] >> j & 1)) + (a2 << 1);
//             } else {
//                 p = t[p][(a[i] >> j & 1)];
//                 a2 = (a[i] >> j & 1) + (a2 << 1);
//             }
//         }
//         res = max(res, a[i] ^ a2);
//     }
//     cout << res << endl;
//     return 0;
// }

// AcWing 836. 合并集合
// 2025.1.18
// #include <bits/stdc++.h>
// using namespace std;
//
// const int N = 100010;
// int fa[N], n, m;
//
// int find(int x) {
//     if (fa[x] != x) fa[x] = find(fa[x]);
//     return fa[x];
// }
//
// void insert(int x, int y) {
//     fa[find(x)] = find(y);
// }
//
// int main() {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++) fa[i] = i;
//     while (m--) {
//         char o;
//         int a, b;
//         cin >> o >> a >> b;
//         if (o == 'M') {
//             insert(a, b);
//         } else {
//             if (find(a) == find(b)) cout << "Yes" << endl;
//             else cout << "No" << endl;
//         }
//     }
//
//     return 0;
// }

// 837. 连通块中点的数量
// 2025.1.18
// #include <bits/stdc++.h>
// using namespace std;
//
// const int N = 100010;
// int n, m, a, b, fa[N], si[N];
// string op;
//
// int find(int x) {
//     if (x != fa[x]) fa[x] = find(fa[x]);
//     return fa[x];
// }
//
// void insert(int a, int b) {
//     if (find(a) != find(b)) si[find(b)] += si[find(a)];
//     fa[find(a)] = find(b);
// }
//
// int main() {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++) {
//         fa[i] = i;
//         si[i] = 1;
//     }
//     while (m--) {
//         cin >> op;
//         if (op == "C") {
//             cin >> a >> b;
//             insert(a, b);
//         } else if (op == "Q1") {
//             cin >> a >> b;
//             if (find(a) == find(b)) cout << "Yes" << endl;
//             else cout << "No" << endl;
//         } else {
//             cin >> a;
//             cout << si[find(a)] << endl;
//         }
//     }
//     return 0;
// }

// 240. 食物链
// 2025.1.18
// #include <bits/stdc++.h>
// using namespace std;
//
// const int N = 50010;
// int n, k, t, x, y, fa[N], d[N];
//
// int find(int u) {
//     if (fa[u] != u) {
//         int t_ = find(fa[u]);
//         d[u] += d[fa[u]];
//         fa[u] = t_;
//     }
//     return fa[u];
// }
//
// int main() {
//     cin >> n >> k;
//     for (int i = 1; i <= n; i++) fa[i] = i;
//     int ans = 0;
//     while (k--) {
//         cin >> t >> x >> y;
//         if (x > n || y > n) ans++;
//         else {
//             int f_x = find(x), f_y = find(y);
//             if (t == 1) {
//                 if (f_x == f_y && (d[x] - d[y]) % 3) ans++;
//                 else if (f_x != f_y) {
//                     fa[f_x] = f_y;
//                     d[f_x] = d[y] - d[x];
//                 }
//             } else {
//                 if (f_x == f_y) {
//                     // if ((d[x] - d[y]) % 3 != 1) ans++;
//                     // 灵异事件待解决
//                     if ((d[x] - d[y] - 1) % 3) ans++;
//                 }
//                 else if (f_x != f_y) {
//                     fa[f_x] = f_y;
//                     d[f_x] = d[y] - d[x] + 1;
//                 }
//             }
//         }
//     }
//     cout << ans << endl;
//     return 0;
// }

// 838. 堆排序
// 2025.1.19
// #include <bits/stdc++.h>
// using namespace std;
//
// const int N = 500010;
// int h[N], siz, n, m;
//
// void down(int u) {
//     int t = u;
//     if (2 * u <= siz && h[2 * u] < h[t]) t = 2 * u;
//     if (2 * u + 1 <= siz && h[2 * u + 1] < h[t]) t = 2 * u + 1;
//     if (t != u) {
//         swap(h[t], h[u]);
//         down(t);
//     }
// }
//
// int main() {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++) cin >> h[++siz];
//     for (int i = n / 2; i >= 1; i--) down(i);
//     while (m--) {
//         cout << h[1] << ' ';
//         h[1] = h[siz--];
//         down(1);
//     }
//     return 0;
// }

// 841. 字符串哈希 y总都说非常牛逼的东西！
// 2025.1.19
// #include <bits/stdc++.h>
// using namespace std;
//
// using ULL = unsigned long long;
// const int N = 100010;
// ULL p[N], h[N];
//
// int n, m, P = 131;
// string s;
//
// ULL get(int l, int r) {
//     return h[r] - h[l - 1] * p[r - l + 1];
// }
//
// int main() {
//     cin >> n >> m;
//     cin >> s;
//     s = ' ' + s;
//     p[0] = 1;
//     for (int i = 1; i <= n; i++) {
//         p[i] = p[i - 1] * P;
//         h[i] = h[i - 1] * P + s[i];
//     }
//
//     while (m--) {
//         int l1, l2, r1, r2;
//         cin >> l1 >> r1 >> l2 >> r2;
//         if (get(l1, r1) == get(l2, r2)) cout << "Yes" << endl;
//         else cout << "No" << endl;
//     }
//     return 0;
// }

// 今天2025.1.22了，两天没刷了！
// AcWing 842. 排列数字
// 2025.1.22
// #include <bits/stdc++.h>
// using namespace std;
//
// const int N = 10;
// int ans[N], n;
//
// void dfs(int u, int state) {
//     if (u == n) {
//         for (int i = 0; i < n; i++) cout << ans[i] << ' ';
//         cout << endl;
//     } else {
//         for (int i = 1; i <= n; i++) {
//             if (((state >> (i - 1)) & 1) == 0) {
//                 ans[u] = i;
//                 dfs(u + 1, state | (1 << (i - 1)));
//             }
//         }
//     }
// }
//
// int main() {
//     cin >> n;
//     dfs(0, 0);
//     return 0;
// }

// AcWing 843. n-皇后问题
// 2025.1.22
// #include <bits/stdc++.h>
// using namespace std;
//
// const int N = 20;
// int n, col[N], dg[N], udg[N];
// char ans[N][N];
//
// void dfs(int u) {
//     if (u == n) {
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++)
//                 cout << ans[i][j];
//             cout << endl;
//         }
//         cout << endl;
//     } else {
//         for (int i = 0; i < n; i++) {
//             if (!col[i] && !dg[i + u] && !udg[i - u + n]) {
//                 ans[u][i] = 'Q';
//                 col[i] = dg[i + u] = udg[i - u + n] = 1;
//                 dfs(u + 1);
//                 ans[u][i] = '.';
//                 col[i] = dg[i + u] = udg[i - u + n] = 0;
//             }
//         }
//     }
// }
//
// int main() {
//     cin >> n;
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < n; j++)
//             ans[i][j] = '.';
//     dfs(0);
//     return 0;
// }

// 844. 走迷宫
// 2025.1.22
// #include <bits/stdc++.h>
// using namespace std;
//
// const int N = 110;
// int dx[] = {0, 1, -1, 0};
// int dy[] = {1, 0, 0, -1};
// int a[N][N];
// bool vis[N][N];
// int n, m;
//
// struct mes {
//     int x;
//     int y;
//     int step;
// };
//
// int main() {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= m; j++)
//             cin >> a[i][j];
//     queue<mes> q;
//     q.push({1, 1, 0});
//     vis[1][1] = 1;
//     int ans = 0;
//     int have_ans = false;
//     while (!q.empty()) {
//         mes pos = q.front();
//         q.pop();
//         for (int i =0; i < 4; i++) {
//             int x = pos.x + dx[i];
//             int y = pos.y + dy[i];
//             if (x >= 1 && x <= n && y >= 1 && y <= m && !vis[x][y] && a[x][y] != 1) {
//                 vis[x][y] = 1;
//                 if (x == n && y == m) {
//                     ans = pos.step + 1;
//                     have_ans = true;
//                     break;
//                 }
//                 q.push({x, y, pos.step + 1});
//             }
//         }
//         if (have_ans) break;
//     }
//     cout << ans << endl;
//     return 0;
// }

// 845. 八数码
// 2025.1.22
// #include <bits/stdc++.h>
// using namespace std;
//
// string target = "12345678x";
// int dx[] = {0, 0, 1, -1};
// int dy[] = {1, -1, 0, 0};
//
// struct mes {
//     string s;
//     int x;
//     int y;
//     int step;
// };
//
// int main() {
//     char x;
//     string s;
//     int j = 0;
//     for (int i = 0; i < 9; i++) {
//         cin >> x;
//         if (x == 'x') j = i;
//         s += x;
//     }
//     unordered_map<string, bool> vis;
//     vis[s] = 1;
//     queue<mes> q;
//     q.push({s, j / 3, j % 3, 0});
//     int ans = -1;
//     bool have_ans = false;
//     if (s == target) {
//         ans = 0;
//         have_ans = true;
//     }
//     while (!q.empty() && !have_ans) {
//         mes m = q.front();
//         q.pop();
//         for (int i = 0; i < 4; i++) {
//             int x = m.x + dx[i];
//             int y = m.y + dy[i];
//             if (x >= 0 && x <= 2 && y >= 0 && y <= 2) {
//                 string s1 = m.s;
//                 swap(s1[3 * x + y], s1[3 * m.x + m.y]);
//                 if (!vis[s1]) {
//                     vis[s1] = 1;
//                     if (s1 == target) {
//                         ans = m.step + 1;
//                         have_ans = true;
//                         break;
//                     }
//                     q.push({s1, x, y, m.step + 1});
//                 }
//             }
//         }
//     }
//     cout << ans << endl;
//     return 0;
// }

// vscode启动！

// 846. 树的重心  写法很巧妙，真的
// 2025.1.26
// #include <bits/stdc++.h>
// using namespace std;

// const int N = 100010, M = 2 * N;
// int h[N], e[M], ne[M], idx, n;
// bool vis[N];
// int ans = N;

// void add(int a, int b) {
//     e[idx] = b;
//     ne[idx] = h[a];
//     h[a] = idx++;
// }

// int dfs(int u) {
//     vis[u] = 1;
//     int sum = 1, res = 0;
//     for (int i = h[u]; i != -1; i = ne[i]) {
//         int j = e[i];
//         if (!vis[j]) {
//             int s = dfs(j);
//             sum += s;
//             res = max(res, s);
//         }
//     }

//     res = max(res, n - sum);
//     ans = min(ans, res);
//     return sum;
// }

// int main() {
//     memset(h, -1, sizeof h);
//     cin >> n;
//     for (int i = 0; i < n - 1; i++) {
//         int a, b;
//         cin >> a >> b;
//         add(a, b), add(b, a);
//     }
//     dfs(1);
//     cout << ans;
//     return 0;
// }

// 847. 图中点的层次
// 2025.1.26
// #include <bits/stdc++.h>
// using namespace std;

// const int N = 100010;
// vector<int> a[N];
// bool vis[N];

// int main() {
//     int n, m;
//     cin >> n >> m;
//     while (m--) {
//         int u, v;
//         cin >> u >> v;
//         a[u].push_back(v);
//     }

//     queue<pair<int, int>> q;
//     q.push({1, 0});
//     vis[1] = 1;
//     int ans = (n == 1 ? 0 : -1);
//     while (!q.empty()) {
//         pair<int, int> pa = q.front();
//         q.pop();
//         for (int u : a[pa.first]) {
//             if (!vis[u]) {
//                 vis[u] = 1;
//                 q.push({u, pa.second + 1});
//                 if (u == n) {
//                     ans = pa.second + 1;
//                 }
//             }
//         }
//     }
//     cout << ans << endl;
//     return 0;
// }

// 848. 有向图的拓扑序列
// 2025.1.26
// #include <bits/stdc++.h>
// using namespace std;

// const int N = 100010;
// int n, m, e[N], ne[N], h[N], d[N], q[N], idx;

// void add(int a, int b) {
//     e[idx] = b;
//     ne[idx] = h[a];
//     h[a] = idx++;
// }

// bool topsort() {
//     int hh = 0, tt = -1;
//     for (int i = 1; i <= n; i++) {
//         if (d[i] == 0) q[++tt] = i;
//     }

//     while (hh <= tt) {
//         int x = q[hh++];
//         for (int i = h[x]; i != -1; i = ne[i]) {
//             int j = e[i];
//             d[j]--;
//             if (d[j] == 0) q[++tt] = j;
//         }
//     }

//     return tt == n - 1;
// }

// int main() {
//     memset(h, -1, sizeof h);
//     cin >> n >> m;
//     while (m--) {
//         int u, v;
//         cin >> u >> v;
//         add(u, v);
//         d[v]++;
//     }

//     if (topsort()) {
//         for (int i = 0; i < n; i++) {
//             cout << q[i] << ' ';
//         }
//         cout << endl;
//     } else {
//         cout << -1 << endl;
//     }
//     return 0;
// }

// 866. 试除法判定质数
// 2025.1.26
// #include <bits/stdc++.h>
// using namespace std;

// void pan(int x) {
//     if (x == 1) {
//         cout << "No" << endl;
//         return;
//     }
//     for (int i = 2; i <= x / i; i++) {
//         if (x % i == 0) {
//             cout << "No" << endl;
//             return;
//         }
//     }
//     cout << "Yes" << endl;
// }

// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         int x;
//         cin >> x;
//         pan(x);
//     }
//     return 0;
// }

// 867. 分解质因数
// 2025.1.26
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int t, n;
//     cin >> t;
//     while (t--) {
//         cin >> n;
//         map<int, int> mp;
//         for (int i = 2; i <= n / i; i++) {
//             while (n % i == 0) {
//                 mp[i]++;
//                 n /= i;
//             }
//         }

//         if (n > 1) mp[n]++;

//         for (auto it : mp) {
//             cout << it.first << ' ' << it.second << endl;
//         }
//         cout << endl;
//     }
//     return 0;
// }

// 868. 筛质数 (再次回顾)
// 2025.1.26
// #include <bits/stdc++.h>
// using namespace std;

// const int N = 1e6 + 2;
// int s[N], p[N], vis[N], cnt;

// void euler(int n) {
//     for (int i = 2; i <= n; i++) {
//         if (!vis[i]) p[cnt++] = i;
//         for (int j = 0; p[j] <= n / i; j++) {
//             vis[p[j] * i] = 1;
//             if (i % p[j] == 0) break;
//         }
//     }
// }

// int main() {
//     int n;
//     cin >> n;
//     euler(n);
//     cout << cnt << endl;
//     return 0;
// }

// 869. 试除法求约数
// 2025.1.29
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//     int n;
//     cin >> n;
//     int a;
//     while (n--) {
//         cin >> a;
//         vector<int> ans;
//         for (int i = 1; i <= a / i; i++) {
//             if (a % i == 0) {
//                 if (i != a / i) {
//                     ans.push_back(i);
//                     ans.push_back(a / i);
//                 } else {
//                     ans.push_back(i);
//                 }
//             }
//         }
//         sort(ans.begin(), ans.end());
//         for (int i : ans) {
//             cout << i << ' ';
//         }
//         cout << endl;
//     }
//     return 0;
// }

// 870. 约数个数
// 2025.1.29
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int mod = 1e9 + 7;
//
// signed main() {
//     int n;
//     int ans = 1;
//     cin >> n;
//     unordered_map<int, int> mp;
//     while (n--) {
//         int a;
//         cin >> a;
//         for (int i = 2; i <= a / i; i++) {
//             while (a % i == 0) {
//                 mp[i]++;
//                 a /= i;
//             }
//         }
//         if (a > 1) mp[a]++;
//     }
//     for (auto i : mp) {
//         ans = (i.second + 1) * ans % mod;
//     }
//     cout << ans << endl;
//     return 0;
// }

// 871. 约数之和
// 2025.1.29
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// const int mod = 1e9 + 7;
//
// int chen(int a, int b) {
//     int res = 1;
//     a %= mod;
//     while (b) {
//         if (b & 1) res = (res * a) % mod;
//         a = (a * a) % mod;
//         b >>= 1;
//     }
//     return res;
// }
//
// int jishu(int p, int n) {
//     if (n == 0) return 1;
//     else if (n & 1) {
//         return (1 + chen(p, n / 2 + 1)) * jishu(p, n / 2) % mod;
//     } else {
//         return (p % mod * jishu(p, n - 1) + 1) % mod;
//     }
// }
//
// signed main() {
//     int n;
//     cin >> n;
//     int x;
//     unordered_map<int, int> hash;
//     int ans = 1;
//     while (n--) {
//         cin >> x;
//         for (int i = 2; i <= x / i; i++) {
//             while (x % i == 0) {
//                 x /= i;
//                 hash[i]++;
//             }
//         }
//         if (x > 1) hash[x]++;
//     }
//
//     for (auto i : hash)
//         ans = ans * jishu(i.first, i.second) % mod;
//     cout << ans << endl;
//     return 0;
// }

// 873. 欧拉函数
// 2025.1.30
// #include <bits/stdc++.h>
// using namespace std;
//
// int euler(int a) {
//     int a_ = a;
//     unordered_map<int, int> mp;
//     for (int i = 2; i <= a / i; i++) {
//         while (a % i == 0) {
//             a /= i;
//             mp[i]++;
//         }
//     }
//     if (a > 1) mp[a]++;
//     for (auto p : mp) {
//         a_ = a_ / p.first * (p.first - 1);
//     }
//     return a_;
// }
//
// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         int a;
//         cin >> a;
//         cout << euler(a) << endl;
//     }
//     return 0;
// }

// AcWing 874. 筛法求欧拉函数
// 2025.1.30
// #include <bits/stdc++.h>
// using namespace std;
//
// const int N = 1000010;
// bool vis[N];
// int primes[N], ans[N], n, cnt;
//
// void get_ans() {
//     for (int i = 2; i <= n; i++) {
//         if (!vis[i]) {
//             primes[cnt++] = i;
//             ans[i] = i - 1;
//         }
//         for (int j = 0; primes[j] <= n / i; j++) {
//             vis[primes[j] * i] = true;
//             if (i % primes[j] == 0) {
//                 ans[i * primes[j]] = ans[i] * primes[j];
//                 break;
//             }
//             ans[i * primes[j]] = ans[i] * (primes[j] - 1);
//         }
//     }
// }
//
// int main() {
//     ans[1] = 1;
//     cin >> n;
//     get_ans();
//     long long x = 0;
//     for (int i = 1; i <= n; i++) x += ans[i];
//     cout << x << endl;
//     return 0;
// }

// 875. 快速幂
// 2025.1.30
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// int ans(int a, int b, int p) {
//     a %= p;
//     int res = 1;
//     while (b) {
//         if (b & 1) {
//             res = res * a % p;
//         }
//         b >>= 1;
//         a = a * a % p;
//     }
//     return res;
// }
//
// signed main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         int a, b, p;
//         cin >> a >> b >> p;
//         cout << ans(a, b, p) << endl;
//     }
//     return 0;
// }

// 876. 快速幂求逆元
// 2025.1.31
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// int ans(int a, int p) {
//    int res = 1;
//    int p_ = p + 2;
//    while (p) {
//        if (p & 1) res = res * a % p_;
//        a = a * a % p_;
//        p >>= 1;
//    }
//    return res;
//}
//
// signed main() {
//    int n, a, p;
//    cin >> n;
//    while (n--) {
//        cin >> a >> p;
//        if (gcd(a, p) != 1) {
//            cout << "impossible" << endl;
//        } else {
//            cout << ans(a, p - 2) << endl;
//        }
//
//    }
//    return 0;
//}

// 877. 扩展欧几里得算法 （自己想的方法）
// 2025.1.31
// #include <bits/stdc++.h>
// using namespace std;
//
// array<int, 2> ex_gcd(int a, int b, int a1, int a2, int b1, int b2) {
//    if (a == 0) {
//        return {b1, b2};
//    } else {
//        int x = -(b / a);
//        int b1_ = b1, b2_ = b2;
//        b1 = a1;
//        b2 = a2;
//        a1 = x * a1 + b1_;
//        a2 = x * a2 + b2_;
//        // 这个 return 一定要加上
//        return ex_gcd(b % a, a, a1, a2, b1, b2);
//    }
//}
// int main() {
//    int n;
//    cin >> n;
//    while (n--) {
//        int a, b;
//        cin >> a >> b;
//        array<int, 2> ans = ex_gcd(a, b, 1, 0, 0, 1);
//        cout << ans[0] << ' ' << ans[1] << endl;
//    }
//    return 0;
//}

// kmp复习, 尝试再写一遍, 但是使用胡浩大佬的思路写的
// https://www.luogu.com.cn/problem/P3375
// 2025.2.2
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//    string s1, s2;
//    cin >> s1 >> s2;
//    string s = ' ' + s2 + '#' + s1;
//    vector<int> ne(s.size() + 5);
//    for (int i = 2, j = 0; i < s.size(); i++) {
//        while (j && s[j + 1] != s[i]) j = ne[j];
//        if (s[j + 1] == s[i]) j++;
//        ne[i] = j;
//        if (i > s2.size()) {
//            if (ne[i] == s2.size()) {
//                cout << i - 2 * s2.size() << endl;
//            }
//        }
//    }
//    for (int i = 1; i <= s2.size(); i++) cout << ne[i] << ' ';
//    return 0;
//}

// 878. 线性同余方程
// 2025.2.2
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// void ex_gcd(int a, int b, int a1, int a2, int& b1, int& b2) {
//    if (a == 0) {
//        return;
//    } else {
//        int k = -(b / a);
//        int a1_ = a1, a2_ = a2;
//        a1 = k * a1 + b1;
//        a2 = k * a2 + b2;
//        b1 = a1_, b2 = a2_;
//        ex_gcd(b % a, a, a1, a2, b1, b2);
//    }
//}
// signed main() {
//    int n, a, b, m;
//    cin >> n;
//    while (n --) {
//        cin >> a >> b >> m;
//        if (b % gcd(a, m)) {
//            cout << "impossible" << endl;
//        } else {
//            int x = 0, y = 1;
//            ex_gcd(a, m, 1, 0, x, y);
//            cout << b / gcd(a, m) * x << endl;
//        }
//    }
//    return 0;
//}

// 204. 表达整数的奇怪方式
// 2025.2.5
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
//// 类似y总的 扩展欧几里得 算法
// int exgcd(int a, int b, int& x, int& y) {
//     if (a == 0) {
//         x = 0, y = 1;
//         return b;
//     } else {
//         int d = exgcd(b % a, a, x, y);
//         swap(x, y);
//         x -= b / a * y;
//         return d;
//     }
// }
//
// signed main() {
//     int n;
//     cin >> n;
//     int a1, m1, a2, m2;
//     cin >> a1 >> m1;
//     bool no_ans = false;
//     for (int i = 0; i < n - 1; i++) {
//         cin >> a2 >> m2;
//         int k1, k2;
//         int d = exgcd(a1, a2, k1, k2);
//         if ((m2 - m1) % d != 0) {
//             no_ans = true;
//             break;
//         }
//         k1 *= (m2 - m1) / d;
//         k1 = (k1 % (a2 / d) + a2 / d) % (a2 / d);
//         m1 = k1 * a1 + m1;
//         a1 = a1 / d * a2;
//     }
//     if (no_ans) cout << -1 << endl;
//     else {
//         cout << m1 % a1 << endl;
//     }
//     return 0;
// }

// __int128的读入与输出
// 2025.2.5
// #include <bits/stdc++.h>
//
//__int128 read() {
//    int f = 1;
//    __int128 x = 0;
//    char c;
//    c = getchar();
//    while (c > '9' || c < '0') {
//        if (c == '-') f = -1;
//        c = getchar();
//    }
//    while ('0' <= c && c <= '9') {
//        x = 10 * x + c - '0';
//        c = getchar();
//    }
//    return x * f;
//}
//
// void write(__int128 a) {
//    if (a) {
//        write(a / 10);
//        putchar(a % 10 + '0');
//    }
//}
//
// int main() {
//    __int128 a = read();
//    write(a);
//    return 0;
//}

// 890. 能被整除的数
// 2025.2.6
// #include <bits/stdc++.h>
// using namespace std;
// #define LL long long
//
// signed main() {
//    int n, m;
//    cin >> n >> m;
//    vector<int> a(m);
//    for (int i = 0; i < m; i++) cin >> a[i];
//    int res = 0;
//    for (int i = 1; i < 1 << m; i++) {
//        int cnt = 0, t = 1;
//        for (int j = 0; j < m; j++) {
//            if (i >> j & 1) {
//                cnt++;
//                if ((LL)t * a[j] > n) {
//                    t = -1;
//                    break;
//                }
//                t *= a[j];
//            }
//        }
//        if (t != -1) {
//            if (cnt & 1) res += n / t;
//            else res -= n / t;
//        }
//    }
//    cout << res << endl;
//    return 0;
//}

// 905. 区间选点
// 2025.2.8
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//    int n;
//    cin >> n;
//    vector<pair<int, int>> a(n);
//    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
//    sort(a.begin(), a.end());
//    if (n == 1) cout << 1 << endl;
//    else {
//        int ans = 1;
//        int r = a[0].second;
//        for (int i = 1; i < n; i++) {
//            if (a[i].first > r) {
//                ans++;
//                r = a[i].second;
//            } else {
//                r = min(r, a[i].second);
//            }
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 908. 最大不相交区间数量
// 2025.2.8
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//    int n;
//    cin >> n;
//    vector<pair<int, int>> a(n);
//    for (int i = 0; i < n; i++) cin >> a[i].second >> a[i].first;
//    sort(a.begin(), a.end());
//    int ans = 1;
//    int ed = a[0].first;
//    for (int i = 1; i < n; i++) {
//        if (a[i].second > ed) {
//            ans++;
//            ed = a[i].first;
//        }
//    }
//    cout << ans << endl;
//    return 0;
//}

// 906. 区间分组
// 2025.2.8
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//    int n;
//    cin >> n;
//    vector<pair<int, int>> a(n);
//    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
//    sort(a.begin(), a.end());
//    priority_queue<int, vector<int>, greater<> > q;
//    q.push(a[0].second);
//    int ans = 1;
//    for (int i = 1; i < n; i++) {
//        if (a[i].first <= q.top()) {
//            q.push(a[i].second);
//            ans++;
//        } else {
//            q.pop();
//            q.push(a[i].second);
//        }
//    }
//    cout << ans << endl;
//    return 0;
//}

// 907. 区间覆盖    一直wa，一直加补丁，终于ac了，服了哈哈哈。
// 2025.2.9
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//    int n;
//    int s, t;
//    cin >> s >> t;
//    cin >> n;
//    vector<pair<int, int>> a(n);
//    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
//    sort(a.begin(), a.end());
//    int max_r = s;
//    int i = 0;
//    int ans = 0;
//    int bi = s;
//    bool no_ans = false;
//    do {
//        int you = 0;
//        for (; i < n; i++) {
//            if (a[i].first > bi) {
//                if (you == 0) no_ans = true;
//                break;
//            }
//            you++;
//            max_r = max(max_r, a[i].second);
//        }
//        bi = max_r;
//        ans++;
//        if (no_ans || (i == n && max_r < t)) {
//            ans = -1;
//            break;
//        }
//    } while (max_r < t);
//    cout << ans << endl;
//    return 0;
//}

// 148. 合并果子
// 2025.2.14
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//    int n;
//    cin >> n;
//    int x;
//    priority_queue<int, vector<int>, greater<> > q;
//    for (int i = 0; i < n; i++) {
//        cin >> x;
//        q.push(x);
//    }
//    int ans = 0;
//    while (q.size() > 1) {
//        int t1 = q.top(); q.pop();
//        int t2 = q.top(); q.pop();
//        ans += t1 + t2;
//        q.push(t1 + t2);
//    }
//    cout << ans << endl;
//    return 0;
//}

// 913. 排队打水
// 2025.2.14
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//    int n;
//    cin >> n;
//    vector<int> a(n);
//    for (int i = 0; i < n; i++) cin >> a[i];
//    sort(a.begin(), a.end());
//    long long ans = 0;
//    for (int i = 0; i < n; i++) ans += (long long)a[i] * (n - i - 1);
//    cout << ans << endl;
//    return 0;
//}

// 125. 耍杂技的牛
// 2025.2.14
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// struct niu {
//    int sum;
//    int idx;
//    bool operator<(const niu& b) const{
//        return sum < b.sum;
//    }
//};
//
// signed main() {
//    int n, sum_ = 0, s;
//    cin >> n;
//    vector<int> w(n);
//    vector<niu> ni(n);
//    for (int i = 0; i < n; i++) {
//        cin >> w[i] >> s;
//        ni[i] = {w[i] + s, i};
//        sum_ += w[i];
//    }
//    int ans = -1e16;
//    sort(ni.begin(), ni.end());
//    for (int i = n - 1; i >= 0; i--) {
//        ans = max(sum_ - ni[i].sum, ans);
//        sum_ -= w[ni[i].idx];
//    }
//    cout << ans << endl;
//    return 0;
//}

// 883. 高斯消元解线性方程组
// 2025.2.20
// #include <bits/stdc++.h>
// using namespace std;
//
// const int N = 105;
// const double eps = 1e-6;
// int n;
// double a[N][N];
//
// void out() {
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j <= n; j++)
//            printf("%.2lf   ", a[i][j]);
//        cout << endl;
//    }
//    cout << endl;
//}
//
// int gauss() {
//    int c, r;
//    for (c = 0, r = 0; c < n; c++) {
//        int t = r;
//        for (int i = r + 1; i < n; i++) {
//            if (abs(a[i][c]) > abs(a[t][c]))
//                t = i;
//        }
//        if (abs(a[t][c]) < eps) continue;
//        if (t != r)
//            for (int i = c; i <= n; i++)
//                swap(a[t][i], a[r][i]);
//        for (int i = n; i >= c; i--) a[r][i] /= a[r][c];
//        for (int i = r + 1; i < n; i++)
//            if (abs(a[i][c]) > eps)
//                for (int j = n; j >= c; j--)
//                    a[i][j] -= a[i][c] * a[r][j];
//
//        r++;
//    }
//
//    if (r < n) {
//        for (int i = r; i < n; i++) {
//            if (abs(a[i][n]) > eps)
//                return 1;
//        }
//        return 0;
//    } else {
//        for (int i = n - 1; i >= 0; i--)
//            for (int j = i + 1; j < n; j++)
//                a[i][n] -= a[j][n] * a[i][j];
//        return 2;
//    }
//}
//
// int main() {
//    cin >> n;
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j <= n; j++)
//            cin >> a[i][j];
//
//    int x = gauss();
//    if (x == 0) cout << "Infinite group solutions" << endl;
//    else if (x == 1) cout << "No solution" << endl;
//    else {
//        for (int i = 0; i < n; i++) printf("%.2lf\n", a[i][n]);
//    }
//    return 0;
//}

// 885. 求组合数 I
// 2025.2.20
// #include <bits/stdc++.h>
// using namespace std;
//
// const int N = 2001;
// int c[N][N];
// const int mod = 1e9 + 7;
//
// void init() {
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j <= i; j++) {
//            if (!j) c[i][j] = 1;
//            else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
//        }
//    }
//}
//
// int main() {
//    init();
//    int n;
//    cin >> n;
//    int a, b;
//    while (n--) {
//        cin >> a >> b;
//        cout << c[a][b] << endl;
//    }
//    return 0;
//}

// 886. 求组合数 II
// 2025.2.20
// #include <bits/stdc++.h>
// using namespace std;
//
// const int N = 100010, mod = 1e9 + 7;
// int fact[N], infact[N];
//
// int fi(int a, int k, int p) {
//    int res = 1;
//    while (k) {
//        if (k & 1) res = (long long)res * a % p;
//        a = (long long)a * a % p;
//        k >>= 1;
//    }
//    return res;
//}
// int main() {
//    fact[0] = infact[0] = 1;
//    for (int i = 1; i < N; i++) {
//        fact[i] = (long long)fact[i - 1] * i % mod;
//        infact[i] = fi(fact[i], mod - 2, mod);
//    }
//    int n, a, b;
//    cin >> n;
//    while (n --) {
//        cin >> a >> b;
//        cout << (long long)fact[a] * infact[a - b] % mod * infact[b] % mod << endl;
//    }
//    return 0;
//}

// 242. 一个简单的整数问题
// 2025.3.26
// #include <bits/stdc++.h>
// using namespace std;
//
// const int N = 1e5 + 10;
// int tr[N];
//
// void add(int x, int c) {
//    for (int i = x; i < N; i += i & -i)
//        tr[i] += c;
//}
//
// void add(int l, int r, int k) {
//    add(l, k);
//    add(r + 1, -k);
//}
//
// int qiu(int x) {
//    int res = 0;
//    for (int i = x; i > 0; i -= i & -i)
//        res += tr[i];
//    return res;
//}
//
// int main() {
//    int n, m;
//    cin >> n >> m;
//    int x;
//    for (int i = 1; i <= n; i++) {
//        cin >> x;
//        add(i, i, x);
//    }
//    while (m--) {
//        char o;
//        cin >> o;
//        if (o == 'Q') {
//            cin >> x;
//            cout << qiu(x) << endl;
//        } else {
//            int y, d;
//            cin >> x >> y >> d;
//            add(x, y, d);
//        }
//    }
//    return 0;
//}

// 244. 谜一样的牛   水过去了！！！
// 2025.3.27
// #include <bits/stdc++.h>
// using namespace std;
//
// const int N = 100010;
//
// int main() {
//    int n;
//    cin >> n;
//    vector<int> a(n);
//    for (int i = 1; i < n; i++) cin >> a[i];
//    vector<int> ans(n);
//    vector<int> s;
//    for (int i = 1; i <= n; i++) s.push_back(i);
//    for (int i = n - 1; i >= 0; i--) {
//        ans[i] = *(s.begin() + a[i]);
//        s.erase(s.begin() + a[i]);
//    }
//    for (int i = 0; i < n; i++) cout << ans[i] << endl;
//    return 0;
//}

// 244. 谜一样的牛
// 2025.3.27
// #include <bits/stdc++.h>
// using namespace std;
//
// const int N = 1e5 + 10;
// int tr[N];
// unordered_map<int, bool> vis;
//
// void add(int x, int c) {
//    for (int i = x; i < N; i += i & -i)
//        tr[i] += c;
//}
//
// int sum(int x) {
//    int res = 0;
//    for (int i = x; i > 0; i -= i & -i)
//        res += tr[i];
//    return res;
//}
//
// int find(int x) {
//    int l = 1, r = N - 1;
//    int ans = -1;
//    while (l <= r) {
//        int mid = (l + r) / 2;
//        if (sum(mid) >= x) {
//            r = mid - 1;
//            ans = mid;
//        }
//        else l = mid + 1;
//    }
//    return ans;
//}
//
// int main() {
//    int n;
//    cin >> n;
//    for (int i = 1; i <= n; i++) add(i, 1);
//    vector<int> a(n);
//    for (int i = 1; i < n; i++) cin >> a[i];
//    vector<int> ans(n);
//    for (int i = n - 1; i >= 0; i--) {
//        ans[i] = find(a[i] + 1);
//        add(ans[i], -1);
//    }
//    for (int i = 0; i < n; i++) cout << ans[i] << endl;
//    return 0;
//}

// 1275. 最大数
// 2025.3.31
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// const int N = 2e5 + 3;
// int a[4 * N];
//
// void change(int x, int y, int l, int r, int i) {
//    if (l == r) {
//        a[i] = y;
//    } else {
//        int mid = (l + r) >> 1;
//        if (x <= mid) {
//            change(x, y, l, mid, i << 1);
//        }
//        if (x > mid) {
//            change(x, y, mid + 1, r, i << 1 | 1);
//        }
//        a[i] = max(a[i << 1], a[i << 1 | 1]);
//    }
//}
//
// int query(int jobl, int jobr, int l, int r, int i) {
//    if (jobl <= l && r <= jobr) {
//        return a[i];
//    } else {
//        int mid = (l + r) >> 1;
//        int maxn = -99999;
//        if (jobl <= mid) {
//            maxn = max(maxn, query(jobl, jobr, l, mid, i << 1));
//        }
//        if (mid < jobr) {
//            maxn = max(maxn, query(jobl, jobr, mid + 1, r, i << 1 | 1));
//        }
//        return maxn;
//    }
//}
//
// signed main() {
//    int idx = 1;
//    int n, p, the = 0;
//    cin >> n >> p;
//    while (n--) {
//        char o;
//        int x;
//        cin >> o >> x;
//        if (o == 'A') {
//            int shu = (the + x) % p;
//            change(idx, shu, 1, N - 3, 1);
//            idx++;
//        } else {
//            the = query(idx - x, idx - 1, 1, N - 3, 1);
//            cout << the << endl;
//        }
//    }
//    return 0;
//}

// AcWing 1275. 最大数
// 2025.4.7
// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define int long long
//
// struct Node {
//    int l, r;
//    int v;
//};
//
// const int N = 200010;
// Node tr[4 * N];
// int m, p;
//
// void build(int u, int l, int r) {
//    tr[u] = {l, r};
//    if (l == r) return;
//    int mid = (l + r) >> 1;
//    build(u << 1, l, mid);
//    build(u << 1 | 1, mid + 1, r);
//}
//
// int query(int u, int l, int r) {
//    if (l <= tr[u].l && tr[u].r <= r) return tr[u].v;
//    int mid = (tr[u].l + tr[u].r) >> 1;
//    int v = 0;
//    if (mid >= l) v = query(u << 1, l, r);
//    if (mid < r) v = max(v, query(u << 1 | 1, l, r));
//    return v;
//}
//
// void change(int u, int x, int v) {
//    if (tr[u].l == x && tr[u].r == x) tr[u].v = v;
//    else {
//        int mid = (tr[u].l + tr[u].r) >> 1;
//        if (x <= mid) change(u << 1, x, v);
//        if (mid < x) change(u << 1 | 1, x, v);
//        tr[u].v = max(tr[u << 1].v, tr[u << 1 | 1].v);
//    }
//}
//
// signed main() {
//    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//    cin >> m >> p;
//    build(1, 1, m);
//    int last = 0, n = 1;
//    while (m--) {
//        char o;
//        int t;
//        cin >> o >> t;
//        if (o == 'A') {
//            int jia = (t + last) % p;
//            change(1, n++, jia);
//        } else {
//            last = query(1, n - t, n - 1);
//            cout << last << endl;
//        }
//    }
//    return 0;
//}

// 245. 你能回答这些问题吗
// #include <bits/stdc++.h>
// using namespace std;
//
// struct Node {
//    int l, r;
//    int sum;
//    int lmax, rmax, tmax;
//};
//
// const int N = 500010;
// Node tr[4 * N];
// int n, m, a[N];
//
// void pushup(Node &u, Node& x, Node& y) {
//    u.sum = x.sum + y.sum;
//    u.lmax = max(x.lmax, x.sum + y.lmax);
//    u.rmax = max(y.rmax, y.sum + x.rmax);
//    u.tmax = max(max(x.tmax, y.tmax), x.rmax + y.lmax);
//}
//
// void pushup(int u, int l, int r) {
//    pushup(tr[u], tr[l], tr[r]);
//}
//
// void build(int u, int l, int r) {
//    if (l == r) tr[u] = {l, r, a[l], a[l], a[l], a[l]};
//    else {
//        int mid = (l + r) >> 1;
//        tr[u] = {l, r};
//        build(u << 1, l, mid);
//        build(u << 1 | 1, mid + 1, r);
//        pushup(u, u << 1, u << 1 | 1);
//    }
//}
//
// void change(int u, int x, int v) {
//    if (tr[u].l == x && tr[u].r == x) tr[u] = {tr[u].l, tr[u].r, v, v, v, v};
//    else {
//        int mid = (tr[u].l + tr[u].r) >> 1;
//        if (x <= mid) change(u << 1, x, v);
//        else change(u << 1 | 1, x, v);
//        pushup(u, u << 1, u << 1 | 1);
//    }
//}
//
// Node query(int u, int l, int r) {
//    if (l <= tr[u].l && tr[u].r <= r) return tr[u];
//    else {
//        int mid = (tr[u].l + tr[u].r) >> 1;
//        if (mid < l) {
//            return query(u << 1 | 1, l, r);
//        } else if (mid >= r) {
//            return query(u << 1, l, r);
//        } else {
//            Node res;
//            Node left = query(u << 1, l, r);
//            Node right = query(u << 1 | 1, l, r);
//            pushup(res, left, right);
//            return res;
//        }
//    }
//}
//
// int main() {
//    cin >> n >> m;
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    build(1, 1, n);
//    while (m--) {
//        int o, x, y;
//        cin >> o >> x >> y;
//        if (o == 1) {
//            if (x > y) swap(x, y);
//            cout << query(1, x, y).tmax << endl;
//        } else {
//            change(1, x, y);
//        }
//    }
//    return 0;
//}

// 246. 区间最大公约数
// 2025.4.17
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 500010;
// #define int long long
//
// int n, m, w[N];
// struct Node {
//    int l, r;
//    int sum, d;
//} tr[4 * N];
//
// void pushup(Node& fa, Node& a, Node& b) {
//    fa.sum = a.sum + b.sum;
//    fa.d = gcd(a.d, b.d);
//}
//
// void pushup(int u) {
//    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
//}
//
// void build(int u, int l, int r) {
//    if (l == r) {
//        int s = w[l] - w[l - 1];
//        tr[u] = {l, r, s, s};
//    } else {
//        int mid = (l + r) >> 1;
//        tr[u].l = l, tr[u].r = r;
//        build(u << 1, l, mid);
//        build(u << 1 | 1, mid + 1, r);
//        pushup(u);
//    }
//}
//
// Node query(int u, int l, int r) {
//    if (l <= tr[u].l && tr[u].r <= r) {
//        return tr[u];
//    } else {
//        int mid = (tr[u].l + tr[u].r) >> 1;
//        if (r <= mid) return query(u << 1, l, r);
//        else if (mid < l) return query(u << 1 | 1, l, r);
//        else {
//            auto left = query(u << 1, l, r);
//            auto right = query(u << 1 | 1, l, r);
//            Node res = {0, 0, 0, 0};
//            pushup(res, left, right);
//            return res;
//        }
//    }
//}
//
// void modify(int u, int x, int c) {
//    if (tr[u].l == tr[u].r) {
//        tr[u].sum += c;
//        tr[u].d += c;
//    } else {
//        int mid = (tr[u].l + tr[u].r) >> 1;
//        if (x <= mid) modify(u << 1, x, c);
//        else modify(u << 1 | 1, x, c);
//        pushup(u);
//    }
//}
//
// signed main() {
//    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
//    cin >> n >> m;
//    for (int i = 1; i <= n; i++) cin >> w[i];
//    build(1, 1, n);
//    while (m--) {
//        char c;
//        cin >> c;
//        if (c == 'Q') {
//            int l, r;
//            cin >> l >> r;
//            Node s = query(1, 1, l);
//            Node d = {0, 0, 0, 0};
//            if (l + 1 <= r)
//                d = query(1, l + 1, r);
//            cout << gcd(s.sum, d.d) << endl;
//        } else {
//            int l, r, d;
//            cin >> l >> r >> d;
//            modify(1, l, d);
//            if (r + 1 <= n) modify(1, r + 1, -d);
//        }
//    }
//    return 0;
//}

// 243. 一个简单的整数问题2
// 2025.4.17
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// const int N = 100010;
// struct Node {
//    int l, r;
//    int sum, add;
//} tr[4 * N];
//
// int n, m, w[N];
//
// void pushup(int u) {
//    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
//}
//
// void pushdown(int u) {
//    Node & root = tr[u];
//    Node & left = tr[u << 1];
//    Node & right = tr[u << 1 | 1];
//    if (root.add) {
//        left.add += root.add;
//        left.sum += (left.r - left.l + 1) * root.add;
//        right.add += root.add;
//        right.sum += (right.r - right.l + 1) * root.add;
//        root.add = 0;
//    }
//}
//
// void build(int u, int l, int r) {
//    if (l == r) {
//        tr[u] = {l, r, w[l], 0};
//    } else {
//        int mid = (l + r) >> 1;
//        tr[u].l = l, tr[u].r = r;
//        build(u << 1, l, mid);
//        build(u << 1 | 1, mid + 1, r);
//        pushup(u);
//    }
//}
//
// int query(int u, int l, int r) {
//    if (l <= tr[u].l && tr[u].r <= r) return tr[u].sum;
//    else {
//        int res = 0;
//        int mid = (tr[u].l + tr[u].r) >> 1;
//        pushdown(u);
//        if (l <= mid) res += query(u << 1, l, r);
//        if (mid < r) res += query(u << 1 | 1, l, r);
//        return res;
//    }
//}
//
// void modify(int u, int l, int r, int v) {
//    if (l <= tr[u].l && tr[u].r <= r) {
//        tr[u].add += v;
//        tr[u].sum += v * (tr[u].r - tr[u].l + 1);
//    } else {
//        int mid = (tr[u].l + tr[u].r) >> 1;
//        pushdown(u);
//        if (l <= mid) modify(u << 1, l, r, v);
//        if (mid < r) modify(u << 1 | 1, l, r, v);
//        pushup(u);
//    }
//}
//
// signed main()  {
//    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
//    cin >> n >> m;
//    for (int i = 1; i <= n; i++) cin >> w[i];
//    build(1, 1, n);
//    int l, r, d;
//    char o;
//    while (m--) {
//        cin >> o >> l >> r;
//        if (o == 'Q') {
//            cout << query(1, l, r) << endl;
//        } else {
//            cin >> d;
//            modify(1, l, r, d);
//        }
//    }
//    return 0;
//}

// 2025.5.10
// 2. 01背包问题
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//    int n, V;
//    cin >> n >> V;
//    vector<pair<int, int>> a(n);
//    for (auto & [v, w] : a) cin >> v >> w;
//    vector<int> dp(V + 1);
//    for (auto & [v, w] : a) {
//        for (int i = V; i >= v; i--) {
//            dp[i] = max(dp[i - v] + w, dp[i]);
//        }
//    }
//    cout << dp[V] << endl;
//    return 0;
//}

// 3. 完全背包问题
// #include <bits//stdc++.h>
// using namespace std;
//
// int main() {
//    int N, V;
//    cin >> N >> V;
//    vector<pair<int, int>> a(N);
//    for (auto & [v, w] : a) cin >> v >> w;
//    vector<int> dp(V + 1);
//    for (auto & [v, w] : a) {
//        for (int i = v; i <= V; i++) {
//            dp[i] = max(dp[i], dp[i - v] + w);
//        }
//    }
//    cout << dp[V];
//    return 0;
//}

// 4. 多重背包问题 I
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//    int N, V;
//    cin >> N >> V;
//    vector<array<int, 3>> a(N);
//    for (auto & [v, w, s] : a) cin >> v >> w >> s;
//    vector<int> dp(V + 1);
//    for (auto & [v, w, s] : a) {
//        for (int i = V; i >= v; i--) {
//            for (int j = 1; j <= s && i >= j * v; j++) {
//                dp[i] = max(dp[i], dp[i - j * v] + j * w);
//            }
//        }
//    }
//    cout << dp[V];
//    return 0;
//}

// 5. 多重背包问题 II
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//    int n, v;
//    cin >> n >> v;
//    vector<pair<int, int>> a;
//    for (int i = 0; i < n; i++) {
//        int x, y, s;
//        cin >> x >> y >> s;
//        for (int k = 1; s >= k; k *= 2) {
//            s -= k;
//            a.emplace_back(x * k, y * k);
//        }
//        if (s > 0) a.emplace_back(s * x, s * y);
//    }
//    vector<int> dp(v + 1);
//    for (auto & [x, y] : a) {
//        for (int i = v; i >= x; i--) {
//            dp[i] = max(dp[i], dp[i - x] + y);
//        }
//    }
//    cout << dp[v];
//    return 0;
//}

// 9. 分组背包问题
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//    int n, m;
//    cin >> n >> m;
//    vector<vector<pair<int, int>>> a(n);
//    for (int i = 0; i < n; i++) {
//        int t;
//        cin >> t;
//        for (int j = 0; j < t; j++) {
//            int v, w;
//            cin >> v >> w;
//            a[i].emplace_back(v, w);
//        }
//    }
//    vector<int> dp(m + 1);
//    for (int i = 0; i < n; i++) {
//        for (int j = m; j >= 0; j--) {
//            for (auto & k : a[i]) {
//                if (j >= k.first) {
//                    dp[j] = max(dp[j], dp[j - k.first] + k.second);
//                }
//            }
//        }
//    }
//    cout << dp[m];
//    return 0;
//}

// 2025.5.12
// 895. 最长上升子序列
// #include <bits/stdc++.h>
// using namespace std;
//
// const int N = 1010;
// int a[N], dp[N];
//
// int main() {
//    int n;
//    cin >> n;
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    for (int i = 1; i <= n; i++) dp[i] = 1;
//    int ans = 1;
//    for (int i = 2; i <= n; i++)
//        for (int j = i - 1; j >= 1; j--)
//            if (a[j] < a[i])
//                dp[i] = max(dp[i], dp[j] + 1), ans = max(ans, dp[i]);
//    cout << ans << endl;
//    return 0;
//}

// 896. 最长上升子序列 II
// #include <bits/stdc++.h>
// using namespace std;
//
// const int N = 100010;
// int a[N], dp[N];
// int main() {
//    int n;
//    cin >> n;
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    int ans = 0;
//    dp[0] = -2e9;
//    for (int i = 1; i <= n; i++) {
//        int l = 0, r = ans;
//        while (l <= r) {
//            int mid = (l + r) >> 1;
//            if (dp[mid] < a[i]) l = mid + 1;
//            else r = mid - 1;
//        }
//        int the = l - 1;
//        ans = max(ans, the + 1);
//        dp[the + 1] = a[i];
//    }
//    cout << ans << endl;
//    return 0;
//}

// AcWing 897. 最长公共子序列
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//    int n, m;
//    cin >> n >> m;
//    string a, b;
//    cin >> a >> b;
//    a = ' ' + a;
//    b = ' ' + b;
//    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//            if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
//            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//        }
//    }
//    cout << dp[n][m] << endl;
//    return 0;
//}