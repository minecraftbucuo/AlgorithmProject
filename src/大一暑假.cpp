// 今天2025.7.3，暑假训练第一天，加油奥里给！！！
// 001. https://codeforces.com/contest/2117/problem/G   G. Omg Graph
// CF 1900
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 2e5 + 10;
// #define endl '\n'
//
// vector<pair<int, int>> g[N];
// vector<int> minn(N), mini(N);
//
// int main() {
//    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
//    int t;
//    cin >> t;
//    while (t--) {
//        int n, m;
//        cin >> n >> m;
//        for (int i = 1; i <= n; i++) g[i].clear();
//        for (int i = 1; i <= n; i++) minn[i] = 2e9;
//        for (int i = 1; i <= n; i++) mini[i] = 2e9;
//        for (int i = 0; i < m; i++) {
//            int u, v, w;
//            cin >> u >> v >> w;
//            g[u].emplace_back(v, w);
//            g[v].emplace_back(u, w);
//            mini[u] = min(mini[u], w);
//            mini[v] = min(mini[v], w);
//        }
//        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
//        minn[1] = 0;
//        q.emplace(0, 1);
//        while (!q.empty()) {
//            pair<int, int> d = q.top();
//            q.pop();
//            if (d.first != minn[d.second])
//                continue;
//            for (auto& [u, w] : g[d.second]) {
//                int len = max(w, d.first);
//                if (minn[u] > len) {
//                    minn[u] = len;
//                    q.emplace(len, u);
//                }
//            }
//        }
//        int ans = 2e9;
//        for (int i = 1; i <= n; i++) ans = min(ans, mini[i] + max(minn[i], minn[n]));
//        cout << ans << endl;
//    }
//    return 0;
//}

// 002.https://www.luogu.com.cn/problem/P5651
// 洛谷 小黄题 P5651 基础最短路练习题
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//    int n, m, Q;
//    cin >> n >> m >> Q;
//    vector<vector<pair<int, int>>> g(n + 1);
//    for (int i = 0; i < m; i++) {
//        int x, y, w;
//        cin >> x >> y >> w;
//        g[x].emplace_back(y, w);
//        g[y].emplace_back(x, w);
//    }
//    vector<int> ans(n + 1, -1);
//    ans[1] = 0;
//    queue<pair<int, int>> q;
//    q.emplace(1, 0);
//    while (!q.empty()) {
//        pair<int, int> now = q.front();
//        q.pop();
//        for (auto& [u, w] : g[now.first]) {
//            if (ans[u] == -1) {
//                ans[u] = now.second ^ w;
//                q.emplace(u, ans[u]);
//            }
//        }
//    }
//    while (Q--) {
//        int x, y;
//        cin >> x >> y;
//        cout << (ans[x] ^ ans[y]) << endl;
//    }
//    return 0;
//}

// VP https://codeforces.com/contest/845
// 003.A
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//    int n;
//    cin >> n;
//    vector<int> a(2 * n + 1);
//    for (int i = 1; i <= 2 * n; i++) cin >> a[i];
//    sort(a.begin() + 1, a.end());
//    if (a[n] < a[n + 1]) cout << "YES" << endl;
//    else cout << "NO" << endl;
//    return 0;
//}

// 004.B
// #include <bits/stdc++.h>
// using namespace std;
//
// int cha(string& s1, string& s2) {
//    int n1 = 0, n2 = 0;
//    for (char c : s1) n1 += c - '0';
//    for (char c : s2) n2 += c - '0';
//    if (n1 > n2) {
//        swap(n1, n2);
//        swap(s1, s2);
//    }
//    if (n1 == n2) return 0;
//    int chaju = n2 - n1;
//    int mini = 0;
//    for (int i = 1; i < 3; i++) {
//        if (s1[i] < s1[mini]) {
//            mini = i;
//        }
//    }
//    int maxi = 0;
//    for (int i = 1; i < 3; i++) {
//        if (s2[i] > s2[maxi]) {
//            maxi = i;
//        }
//    }
//    int max1 = 9 - (s1[mini] - '0');
//    int max2 = s2[maxi] - '0';
//    if (max1 > max2) {
//        if (max1 >= chaju) {
//            s1 = s2;
//            return 1;
//        } else {
//            s1[mini] = '9';
//        }
//    } else {
//        if (max2 >= chaju) {
//            s1 = s2;
//            return 1;
//        } else {
//            s2[maxi] = '0';
//        }
//    }
//    return 1;
//}
//
// int main() {
//    string s;
//    cin >> s;
//    string q = s.substr(0, 3);
//    string h = s.substr(3, 3);
//    int ans = 0;
//    while (cha(q, h)) ans++;
//    cout << ans << endl;
//    return 0;
//}

// 005.C
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//    int n;
//    cin >> n;
//    vector<pair<int, int>> a(n);
//    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
//    priority_queue<int, vector<int>, greater<>> q;
//    sort(a.begin(), a.end());
//    q.emplace(1e9 + 1);
//    int ans = 0;
//    for (auto& [l, r] : a) {
//        int mi = q.top();
//        if (mi >= l) {
//            ans++;
//        } else {
//            q.pop();
//        }
//        q.push(r);
//    }
//    if (ans <= 2) cout << "YES" << endl;
//    else cout << "NO" << endl;
//    return 0;
//}

// 好菜真的，好容易写错代码，然后半天发现不了错误，代码写少了，需加倍努力！

// 006. P3812 【模板】线性基
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// signed main() {
//    int n;
//    cin >> n;
//    vector<int> a(n);
//    for (int i = 0; i < n; i++) cin >> a[i];
//    vector<int> ans(50);
//    for (int i = 0; i < n; i++) {
//        for (int j = 49; j >= 0; j--) {
//            if ((a[i] >> j) & 1) {
//                if (!ans[j]) {
//                    ans[j] = a[i];
//                    break;
//                } else {
//                    a[i] = a[i] ^ ans[j];
//                }
//            }
//        }
//    }
//    int max_ans = ans[49];
//    for (int i = 48; i >= 0; i--) {
//        max_ans = max(max_ans, max_ans ^ ans[i]);
//    }
//    cout << max_ans << endl;
//    return 0;
//}

// 007. P4570 [BJWC2011] 元素      线性基
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// signed main() {
//    int n;
//    cin >> n;
//    vector<pair<int, int>> a(n);
//    for (int i = 0; i < n; i++) cin >> a[i].second >> a[i].first;
//    sort(a.begin(), a.end(), greater());
//    vector<int> ji(64);
//    int ans = 0;
//    for (auto& [w, i] : a) {
//        for (int j = 63; j >= 0; j--) {
//            if (i == 0) break;
//            if ((i >> j) & 1) {
//                if (!ji[j]) {
//                    ji[j] = i;
//                    ans += w;
//                    break;
//                } else {
//                    i = i ^ ji[j];
//                }
//            }
//        }
//    }
//    cout << ans << endl;
//    return 0;
//}

// 008. P3857 [TJOI2008] 彩灯      线性基
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int mod = 2008;
//
// signed main() {
//    int n, m;
//    cin >> n >> m;
//    vector<string> a(m);
//    vector<int> b(m);
//    for (int i = 0; i < m; i++) cin >> a[i];
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < a[i].size(); j++) {
//            if (a[i][j] == 'O') {
//                b[i] = (b[i] << 1) + 1;
//            } else {
//                b[i] <<= 1;
//            }
//        }
//    }
//    vector<int> ji(51);
//    int ans = 0;
//    for (int& i : b) {
//        for (int j = 50; j >= 0; j--) {
//            if ((i >> j) & 1) {
//                if (!ji[j]) {
//                    ji[j] = i;
//                    ans++;
//                    break;
//                } else {
//                    i = i ^ ji[j];
//                }
//            }
//        }
//    }
//    int out = 1;
//    int p = 2;
//    while (ans) {
//        if (ans & 1) {
//            out = out * p % mod;
//        }
//        p = p * p % mod;
//        ans >>= 1;
//    }
//    cout << out << endl;
//    return 0;
//}

// 009. https://codeforces.com/contest/845/problem/G   2300
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 10;
//
// struct node {
//    node(int u, int w) {
//        this->u = u;
//        this->w = w;
//    }
//    int u, w;
//};
// vector<node> g[N];
// vector<bool> vis(N);
// struct XXJ {
//    vector<int> ji;
//    int n;
//    XXJ(int n = 31) {
//        this->n = n;
//        ji.resize(n + 1, 0);
//    }
//
//    void insert(int x) {
//        for (int i = n; i >= 0; i--) {
//            if ((x >> i) & 1) {
//                if (!ji[i]) {
//                    ji[i] = x;
//                    break;
//                } else {
//                    x = x ^ ji[i];
//                }
//            }
//        }
//    }
//
//    int qmin(int t = 0) {
//        int res = t;
//        for (int i = this->n; i >= 0; i--) {
//            res = min(res, res ^ ji[i]);
//        }
//        return res;
//    }
//};
//
// XXJ ji;
// vector<int> dis(N);
//
// void dfs(int u, int fa) {
//    vis[u] = true;
//    for (auto & [v, w] : g[u]) {
//        if (!vis[v]) {
//            dis[v] = dis[u] ^ w;
//            dfs(v, u);
//        } else {
//            ji.insert(dis[v]^dis[u]^w);
//        }
//    }
//}
//
// signed main() {
//    int n, m;
//    cin >> n >> m;
//    while (m--) {
//        int u, v, w;
//        cin >> u >> v >> w;
//        g[u].emplace_back(v, w);
//        g[v].emplace_back(u, w);
//    }
//    dfs(1, 0);
//    cout << ji.qmin(dis[1] ^ dis[n]) << endl;
//    return 0;
//}

// 010. P4151 [WC2011] 最大XOR和路径
// 和上一题几乎一样，双倍快乐！
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 10;
// #define int long long
//
// struct node {
//    node(int u, int w) {
//        this->u = u;
//        this->w = w;
//    }
//    int u, w;
//};
// vector<node> g[N];
// vector<bool> vis(N);
// struct XXJ {
//    vector<int> ji;
//    int n;
//    XXJ(int n = 63) {
//        this->n = n;
//        ji.resize(n + 1, 0);
//    }
//
//    void insert(int x) {
//        for (int i = n; i >= 0; i--) {
//            if ((x >> i) & 1) {
//                if (!ji[i]) {
//                    ji[i] = x;
//                    break;
//                } else {
//                    x = x ^ ji[i];
//                }
//            }
//        }
//    }
//
//    int qmax(int t = 0) {
//        int res = t;
//        for (int i = this->n; i >= 0; i--) {
//            res = max(res, res ^ ji[i]);
//        }
//        return res;
//    }
//};
//
// XXJ ji;
// vector<int> dis(N);
//
// void dfs(int u, int fa) {
//    vis[u] = true;
//    for (auto & [v, w] : g[u]) {
//        if (!vis[v]) {
//            dis[v] = dis[u] ^ w;
//            dfs(v, u);
//        } else {
//            ji.insert(dis[v]^dis[u]^w);
//        }
//    }
//}
//
// signed main() {
//    int n, m;
//    cin >> n >> m;
//    while (m--) {
//        int u, v, w;
//        cin >> u >> v >> w;
//        g[u].emplace_back(v, w);
//        g[v].emplace_back(u, w);
//    }
//    dfs(1, 0);
//    cout << ji.qmax(dis[1] ^ dis[n]) << endl;
//    return 0;
//}

// 2025.7.4   新的一天，昨天做了10道题。

// 011. P4427 [BJOI2018] 求和
// 调死我了，真服了，还好有AI！
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define endl '\n'
// const int mod = 998244353, N = 3e5 + 10;
//
// vector<int> g[N];
// vector<int> deep(N);
// int fa[N][20];
// int he[N][51];
//
// void dfs(int u, int f) {
//    deep[u] = deep[f] + 1;
//    fa[u][0] = f;
//    for (int i = 1; i <= 19; i++)
//        fa[u][i] = fa[fa[u][i - 1]][i - 1];
//    for (int v : g[u]) {
//        if (v != f) {
//            dfs(v, u);
//        }
//    }
//}
//
// int lca(int u, int v) {
//    if (deep[u] < deep[v]) swap(u, v);
//    for (int i = 19; i >= 0; i--)
//        if (deep[fa[u][i]] >= deep[v]) u = fa[u][i];
//    if (u == v) return u;
//    for (int i = 19; i >= 0; i--) {
//        if (fa[u][i] != fa[v][i]) {
//            u = fa[u][i];
//            v = fa[v][i];
//        }
//    }
//    return fa[u][0];
//}
//
// void init() {
//    for (int i = 1; i < N; i++) {
//        he[i][1] = i;
//        for (int j = 2; j <= 50; j++) {
//            he[i][j] = i * he[i][j - 1] % mod;
//        }
//    }
//    for (int i = 1; i <= 50; i++) {
//        for (int j = 2; j < N; j++) {
//            he[j][i] = (he[j][i] + he[j - 1][i]) % mod;
//        }
//    }
//}
//
// signed main() {
//    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
//    init();
//    int n;
//    cin >> n;
//    for (int i = 1; i < n; i++) {
//        int u, v;
//        cin >> u >> v;
//        g[u].emplace_back(v);
//        g[v].emplace_back(u);
//    }
//    deep[0] = -1;
//    dfs(1, 0);
//    int m;
//    cin >> m;
//    while (m--) {
//        int i, j, k;
//        cin >> i >> j >> k;
//        int a = deep[i], b = deep[j];
//        int w = lca(i, j);
//        int c = deep[w];
//        int base = (c >= 1) ? he[c - 1][k] : 0;
//        int ans = (he[a][k] + he[b][k]) % mod;
//        ans = ans - he[c][k] - base;
//        ans = (ans % mod + mod) % mod;
//        cout << ans << endl;
//    }
//    return 0;
//}

// VP 牛客周赛Round98 https://ac.nowcoder.com/acm/contest/112918
// 牛逼，第一次AK！1h20min！当然是因为太简单了。
// 012. A
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int a;
//    cin >> a;
//    for (int i = 1; i <= a; i++) {
//        if (a % i == 0) {
//            if ((a + i) & 1) {
//                cout << "Yes" << endl;
//                return 0;
//            }
//        }
//    }
//    cout << "No" << endl;
//    return 0;
//}

// 013. B
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        int a, b;
//        cin >> a >> b;
//        int c = gcd(a, b);
//        int a_ = max(a, b);
//        int b_ = min(a, b);
//        if (a_ < c + b_) {
//            cout << "Yes" << endl;
//        } else {
//            cout << "No" << endl;
//        }
//    }
//    return 0;
//}

// 014. C
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int n;
//    string s;
//    string temp = "red";
//    cin >> n >> s;
//    for (int i = 0; i < n - 2; i++) {
//        if (s[i] == s[i + 1] && s[i + 2] == s[i + 1]) {
//            unordered_map<char, int> vis;
//            vis[s[i]] = 1;
//            for (char c : temp) {
//                if (!vis[c]) {
//                    s[i + 1] = c;
//                    break;
//                }
//            }
//        }
//    }
//    for (int i = 0; i < n - 1; i++) {
//        if (s[i] == s[i + 1]) {
//            unordered_map<char, int> vis;
//            vis[s[i]] = 1;
//            if (i - 1 >= 0) vis[s[i - 1]] = 1;
//            for (char c : temp) {
//                if (!vis[c]) {
//                    s[i] = c;
//                    break;
//                }
//            }
//        }
//    }
//    cout << s << endl;
//    return 0;
//}

// 015. D
// #include <bits/stdc++.h>
// using namespace std;
//
// int n, a[20];
//
// void dfs(int deep, int sum) {
//    if (sum == 0) {
//        for (int i = 1; i < deep; i++) {
//            cout << a[i] << ' ';
//        }
//        cout << endl;
//    } else {
//        for (int i = 1; i <= sum; i++) {
//            if (a[deep - 1] != i) {
//                a[deep] = i;
//                dfs(deep + 1, sum - i);
//                a[deep] = 0;
//            }
//        }
//    }
//}
//
// signed main() {
//    cin >> n;
//    dfs(1, n);
//    return 0;
//}

// 016. F
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int mod = 998244353;
//
// int ksm(int a, int k) {
//    int res = 1;
//    while (k) {
//        if (k & 1) res = res * a % mod;
//        a = a * a % mod;
//        k >>= 1;
//    }
//    return res;
//}
//
// int niyuan(int a) {
//    return ksm(a, mod - 2);
//}
//
// signed main() {
//    int n;
//    cin >> n;
//    int a = 400 * niyuan(81 * 99) % mod;
//    int b = 280 * niyuan(81 * 9) % mod;
//    int c = 49 * niyuan(81);
//    int x = (ksm(100, n) - 1) % mod;
//    int y = (ksm(10, n) - 1) % mod;
//    int z = 0;
//    int n_ = n;
//    while (c) {
//        if (c & 1) z = z + n_ % mod;
//        n_ = (n_ + n_) % mod;
//        c >>= 1;
//    }
//    cout << ((a * x) % mod + (b * y) % mod + z) % mod << endl;
//    return 0;
//}

// 017. E
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// signed main() {
//    int n;
//    cin >> n;
//    vector<int> a(n);
//    for (int i = 0; i < n; i++) cin >> a[i];
//    unordered_map<int, int> mp;
//    for (int i = 0; i < n; i++) {
//        for (int j = 1; j * j <= a[i]; j++) {
//            if (a[i] % j == 0) {
//                mp[j] += a[i];
//                if (j != a[i] / j) {
//                    mp[a[i] / j] += a[i];
//                }
//            }
//        }
//    }
//    int ans = 0;
//    for (auto& [yin, he] : mp) {
//        ans = max(ans, yin * he);
//    }
//    cout << ans << endl;
//    return 0;
//}

// 018. U81904 【模板】树的直径
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 5e5 + 10;
//
// int ans;
// vector<pair<int, int>> g[N];
// vector<int> d1(N), d2(N);
//
// void dfs(int u, int fa) {
//    d1[u] = 0, d2[u] = 0;
//    for (auto & [v, w] : g[u]) {
//        if (v != fa) {
//            dfs(v, u);
//            int t = d1[v] + w;
//            if (t > d1[u]) {
//                d2[u] = d1[u];
//                d1[u] = t;
//            } else if (t > d2[u]) {
//                d2[u] = t;
//            }
//        }
//    }
//    ans = max(ans, d1[u] + d2[u]);
//}
//
// signed main() {
//    int n;
//    cin >> n;
//    for (int i = 1; i < n; i++) {
//        int u, v, w;
//        cin >> u >> v >> w;
//        g[u].emplace_back(v, w);
//        g[v].emplace_back(u, w);
//    }
//    dfs(1, 0);
//    cout << ans << endl;
//    return 0;
//}

// 2025.7.5
// VP   Codeforces Round 1034 (Div. 3)
// 019. A
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        int n;
//        cin >> n;
//        if (n % 4 == 0) {
//            cout << "Bob" << endl;
//        } else {
//            cout << "Alice" << endl;
//        }
//    }
//    return 0;
//}

// 020. B
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        int n, j, k;
//        cin >> n >> j >> k;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        int x = a[j];
//        sort(a.begin() + 1, a.end());
//        if (k >= 2) {
//            cout << "YES" << endl;
//        } else {
//            if (a[n] == x) cout << "YES" << endl;
//            else cout << "NO" << endl;
//        }
//    }
//    return 0;
//}

// 021. C
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 2);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        vector<int> mx(n + 2), mn(n + 2);
//        mn[1] = a[1];
//        mx[n] = a[n];
//        for (int i = 2; i <= n; i++) mn[i] = min(mn[i - 1], a[i]);
//        for (int i = n - 1; i >= 1; i--) mx[i] = max(mx[i + 1], a[i]);
//        vector<int> ans(n + 1);
//        for (int i = 1; i <= n; i++) {
//            if (i == 1) {
//                ans[i] = 1;
//            } else if (i == n) {
//                ans[i] = 1;
//            } else {
//                if (a[i] > mn[i - 1] && a[i] < mx[i + 1]) ans[i] = 0;
//                else ans[i] = 1;
//            }
//        }
//        for (int i = 1; i <= n; i++) cout << ans[i];
//        cout << endl;
//    }
//    return 0;
//}

// 022. D
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        int n, k;
//        cin >> n >> k;
//        string s;
//        cin >> s;
//        if (2 * k > n) cout << "Alice" << endl;
//        else {
//            int cnt1 = 0;
//            for (char c : s) cnt1 += (c == '1');
//            if (cnt1 <= k) cout << "Alice" << endl;
//            else cout << "Bob" << endl;
//        }
//    }
//    return 0;
//}

// 赛后做的，打得好菜啊服了。
// 023. F
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 10;
//
// int primes[N], vis[N], cnt;
//
// void euler() {
//    for (int i = 2; i < N; i++) {
//        if (!vis[i]) primes[cnt++] = i;
//        for (int j = 0; primes[j] * i < N; j++) {
//            vis[primes[j] * i] = 1;
//            if (i % primes[j] == 0) break;
//        }
//    }
//}
//
// int main() {
//    euler();
//    int t;
//    cin >> t;
//    while (t--) {
//        int n;
//        cin >> n;
//        vector<int> ans(n + 1);
//        for (int i = cnt - 1; i >= 0; i--) {
//            vector<int> cycle;
//            for (int j = primes[i]; j <= n; j += primes[i]) {
//                if (!ans[j]) cycle.push_back(j);
//            }
//            for (int j = 0; j < cycle.size(); j++) {
//                ans[cycle[j]] = cycle[(j + 1) % cycle.size()];
//            }
//        }
//        ans[1] = 1;
//        for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
//        cout << endl;
//    }
//    return 0;
//}

// 024. P3805 【模板】manacher
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    string a;
//    cin >> a;
//    string s = "$#";
//    for (int i = 0; i < a.size(); i++) {
//        s += a[i];
//        s += '#';
//    }
//    vector<int> d(s.size() + 1);
//    d[1] = 1;
//    for (int i = 2, l = 0, r = 1; i < s.size(); i++) {
//        if (i <= r) d[i] = min(d[l + r - i], r - i + 1);
//        while (s[i - d[i]] == s[i + d[i]]) d[i]++;
//        if (i + d[i] - 1 > r) r = i + d[i] - 1, l = i - d[i] + 1;
//    }
//    int ans = 0;
//    for (int i = 1; i < s.size(); i++) ans = max(ans, d[i]);
//    cout << ans - 1 << endl;
//    return 0;
//}

// 025. P5091 【模板】扩展欧拉定理
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// int ksm(int a, int k, int p) {
//    int res = 1;
//    a %= p;
//    while (k) {
//        if (k & 1) res = res * a % p;
//        a = a * a % p;
//        k >>= 1;
//    }
//    return res;
//}
//
// signed main() {
//    int a, m;
//    string b;
//    cin >> a >> m >> b;
//    a %= m;
//    int phi = 1, mm = m;
//    for (int i = 2; i * i <= mm; i++) {
//        if (mm % i == 0) {
//            phi *= i - 1;
//            mm /= i;
//            while (mm % i == 0) {
//                mm /= i;
//                phi *= i;
//            }
//        }
//    }
//    if (mm > 1) phi *= mm - 1;
//    int t = 0;
//    bool is_da = false;
//    for (int i = 0; i < b.size(); i++) {
//        t = 10LL * t + b[i] - '0';
//        if (t >= phi) {
//            is_da = true;
//            t %= phi;
//        }
//    }
//    if (is_da) {
//        cout << ksm(a, t + phi, m) << endl;
//    } else {
//        cout << ksm(a, t, m) << endl;
//    }
//    return 0;
//}

// 026. P1962 斐波那契数列
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int mod = 1e9 + 7;
//
// struct Matrix {
//    int a[3][3];
//    Matrix() { memset(a, 0, sizeof a); }
//    void setE() {
//        for (int i = 1; i <= 2; i++) a[i][i] = 1;
//    }
//
//    Matrix operator*(const Matrix& m) {
//        Matrix res;
//        for (int i = 1; i <= 2; i++) {
//            for (int j = 1; j <= 2; j++) {
//                for (int k = 1; k <= 2; k++) {
//                    res.a[i][j] = (res.a[i][j] + a[i][k] * m.a[k][j]) % mod;
//                }
//            }
//        }
//        return res;
//    }
//
//    Matrix ksm(int k) {
//        Matrix res;
//        res.setE();
//        Matrix t = *this;
//        while (k) {
//            if (k & 1) res = res * t;
//            t = t * t;
//            k >>= 1;
////            t.print();
//        }
//        return res;
//    }
//
//    void print() {
//        for (int i = 1; i <= 2; i++) {
//            for (int j = 1; j <= 2; j++) {
//                cout << a[i][j] << ' ';
//            }
//            cout << endl;
//        }
//        cout << endl;
//    }
//};
//
// signed main() {
//    int n;
//    cin >> n;
//    Matrix m;
//    m.a[1][2] = m.a[2][1] = m.a[2][2] = 1;
//    Matrix res = m.ksm(n - 1);
//    cout << (res.a[1][1] + res.a[2][1]) % mod << endl;
//    return 0;
//}

// 027. P1939 矩阵加速（数列）
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int mod = 1e9 + 7;
//
// struct Matrix {
//    int a[4][4];
//    Matrix() {
//        memset(a, 0, sizeof a);
//    }
//    void setE() {
//        for (int i = 1; i <= 3; i++) a[i][i] = 1;
//    }
//    Matrix operator*(const Matrix& m) {
//        Matrix res;
//        for (int i = 1; i <= 3; i++) {
//            for (int j = 1; j <= 3; j++) {
//                for (int k = 1; k <= 3; k++) {
//                    res.a[i][j] = (res.a[i][j] + a[i][k] * m.a[k][j]) % mod;
//                }
//            }
//        }
//        return res;
//    }
//};
//
// Matrix ksm(Matrix a, int k) {
//    Matrix res;
//    res.setE();
//    while (k) {
//        if (k & 1) res = res * a;
//        a = a * a;
//        k >>= 1;
//    }
//    return res;
//}
//
// signed main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        int n;
//        cin >> n;
//        Matrix F, M;
//        F.a[1][1] = F.a[1][2] = F.a[1][3] = 1;
//        M.a[1][3] = M.a[2][1] = M.a[3][2] = M.a[3][3] = 1;
//        Matrix res = ksm(M, n - 1);
//        F = F * res;
//        cout << F.a[1][1] << endl;
//    }
//    return 0;
//}

// 028. P1349 广义斐波那契数列
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// int mod = 1e9 + 7;
//
// struct Matrix {
//    int a[3][3];
//    Matrix() {
//        memset(a, 0, sizeof a);
//    }
//    void setE() {
//        for (int i = 1; i <= 2; i++) a[i][i] = 1;
//    }
//    Matrix operator*(const Matrix& m) {
//        Matrix res;
//        for (int i = 1; i <= 2; i++) {
//            for (int j = 1; j <= 2; j++) {
//                for (int k = 1; k <= 2; k++) {
//                    res.a[i][j] = (res.a[i][j] + a[i][k] * m.a[k][j]) % mod;
//                }
//            }
//        }
//        return res;
//    }
//};
//
// Matrix qmi(Matrix a, int k) {
//    Matrix res;
//    res.setE();
//    while (k) {
//        if (k & 1) res = res * a;
//        a = a * a;
//        k >>= 1;
//    }
//    return res;
//}
//
// signed main() {
//    int p, q, a1, a2, n;
//    cin >> p >> q >> a1 >> a2 >> n >> mod;
//    Matrix F, M;
//    F.a[1][1] = a1, F.a[1][2] = a2;
//    M.a[1][2] = q, M.a[2][1] = 1, M.a[2][2] = p;
//    Matrix res = qmi(M, n - 1);
//    F = F * res;
//    cout << F.a[1][1] << endl;
//    return 0;
//}

// 029. P3846 [TJOI2007] 可爱的质数/【模板】BSGS
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// int ksm(int a, int k, int p) {
//    int res = 1;
//    a %= p;
//    while (k) {
//        if (k & 1) res = 1LL * res * a % p;
//        a = 1LL * a * a % p;
//        k >>= 1;
//    }
//    return res;
//}
//
// signed main() {
//    int p, b, n;
//    cin >> p >> b >> n;
//    if (n == 1) {
//        cout << 0 << endl;
//        return 0;
//    }
//    int p_ = (int)sqrt(p) + 1;
//    unordered_map<int, int> mp;
//    int x = n;
//    mp[n % p] = 0;
//    for (int i = 1; i < p_; i++) {
//        x = x * b % p;
//        mp[x] = i;
//    }
//    int b_ = ksm(b, p_, p);
//    int t = 1;
//    int ans = -1;
//    for (int i = 1; i <= p_; i++) {
//        t = t * b_ % p;
//        if (mp.find(t) != mp.end()) {
//            ans = p_ * i - mp[t];
//            break;
//        }
//    }
//    if (ans == -1) cout << "no solution" << endl;
//    else cout << ans << endl;
//    return 0;
//}

// 030. P3379 【模板】最近公共祖先（LCA）
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 5e5 + 10;
// #define endl '\n'
//
// vector<int> g[N];
// int fa[N][20];
// int deep[N];
//
// void dfs(int u, int f) {
//    deep[u] = deep[f] + 1;
//    fa[u][0] = f;
//    for (int i = 1; i <= 19; i++)
//        fa[u][i] = fa[fa[u][i - 1]][i - 1];
//    for (int v : g[u])
//        if (v != f) dfs(v, u);
//}
//
// int lca(int a, int b) {
//    if (a == b) return a;
//    if (deep[a] < deep[b]) swap(a, b);
//    for (int i = 19; i >= 0; i--)
//        if (deep[fa[a][i]] >= deep[b])
//            a = fa[a][i];
//    if (a == b) return a;
//    for (int i = 19; i >= 0; i--)
//        if (fa[a][i] != fa[b][i])
//            a = fa[a][i], b = fa[b][i];
//    return fa[a][0];
//}
//
// signed main() {
//    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
//    int n, m, s;
//    cin >> n >> m >> s;
//    for (int i = 1; i < n; i++) {
//        int u, v;
//        cin >> u >> v;
//        g[u].emplace_back(v);
//        g[v].emplace_back(u);
//    }
//    dfs(s, 0);
//    while (m--) {
//        int a, b;
//        cin >> a >> b;
//        cout << lca(a, b) << endl;
//    }
//    return 0;
//}

// 2025.7.6  VP  牛客小白月赛119   好菜啊，活在别人的阴影下。。。
// 031. A
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    vector<int> a(5);
//    vector<int> b(5);
//    for (int i = 0; i < 5; i++) cin >> a[i];
//    for (int i = 0; i < 5; i++) cin >> b[i];
//    sort(a.begin(), a.end());
//    sort(b.begin(), b.end());
//    int sum1 = 0, sum2 = 0;
//    for (int i = 0; i < 5; i++) sum1 += a[i], sum2 += b[i];
//    sum1 += a[4];
//    sum2 += b[0];
//    if (sum1 > sum2) cout << "YES" << endl;
//    else cout << "NO" << endl;
//    return 0;
//}

// 032. B
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        vector<int> a(5);
//        int sum = 0;
//        for (int i = 0; i < 5; i++) cin >> a[i], sum += a[i];
//        int k;
//        cin >> k;
//        if (sum == 0) {
//            cout << "1/1000" << endl;
//        } else {
//            int cnt = 0;
//            int cnt1 = 0;
//            for (int i = 0; i < 5; i++) {
//                cnt += (a[i] == k);
//                cnt1 += (a[i] != 0);
//            }
//            if (cnt == 0) {
//                cout << "0/1" << endl;
//            } else if (cnt == cnt1) {
//                cout << "1/1" << endl;
//            } else {
//                cout << cnt / gcd(cnt, cnt1) << "/" << cnt1 / gcd(cnt, cnt1) << endl;
//            }
//        }
//    }
//    return 0;
//}

// 033. C
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        sort(a.begin() + 1, a.end());
//        if (a[n] - a[1] == 0 && (2 * a[1] <= n || a[1] == n - 1)) cout << "Other" << endl;
//        else if (a[n] - a[1] == 1 && a[n] >= 2) {
//            int k = a[1];
//            int cnt = 0;
//            for (int i = 1; i <= n; i++) cnt += (k == a[i]);
//            if (cnt == a[n]) cout << "Other" << endl;
//            else cout << "Lie" << endl;
//        }
//        else cout << "Lie" << endl;
//    }
//    return 0;
//}

// 034. D
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 2e5 + 10;
//
// vector<int> g[N];
// int deep[N], du[N];
//
// void dfs(int u, int fa) {
//    if (g[u].size() == 1 && g[u][0] == fa) {
//        deep[u] = 0;
//    } else {
//        for (int v : g[u]) {
//            if (v != fa) {
//                dfs(v, u);
//                deep[u] = min(deep[u], deep[v] + 1);
//            }
//        }
//    }
//}
//
// void dfs2(int u, int fa) {
//    if (g[u].size() == 1 && g[u][0] == fa) {
//
//    } else {
//        for (int v : g[u]) {
//            deep[u] = min(deep[u], deep[v] + 1);
//        }
//        for (int v : g[u]) {
//            if (v != fa) {
//                dfs2(v, u);
//            }
//        }
//    }
//}
//
// signed main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        int n;
//        cin >> n;
//        for (int i = 1; i <= n; i++) {
//            du[i] = 0;
//            g[i].clear();
//            deep[i] = 1e9;
//        }
//        for (int i = 1; i < n; i++) {
//            int u, v;
//            cin >> u >> v;
//            g[u].emplace_back(v);
//            g[v].emplace_back(u);
//            du[u]++, du[v]++;
//        }
//        int u = 1;
//        while (du[u] == 1) u++;
//        dfs(u, 0);
//        dfs2(u, 0);
//        int maxn = 0;
//        vector<int> ans;
//        for (int i = 1; i <= n; i++) maxn = max(maxn, deep[i]);
//        for (int i = 1; i <= n; i++)
//            if (deep[i] == maxn)
//                ans.emplace_back(i);
//        cout << ans.size() << endl;
//        for (int i : ans) cout << i << ' ';
//        cout << endl;
//    }
//    return 0;
//}

// 035. E
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// signed main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        int ans = 1;
//        unordered_map<int, int> mp, mp_yin;
//        int x;
//        for (int i = 1; i <= n; i++) {
//            x = a[i];
//            int t_ = 0;
//            t_ = max(mp_yin[x] + 1, t_);
//            for (int j = 1; j * j <= x; j++) {
//                if (x % j == 0) {
//                    t_ = max(t_, mp[j] + 1);
//                    int y = x / j;
//                    if (y != j) t_ = max(t_, mp[y] + 1);
//                }
//            }
//
//            mp[x] = max(t_, mp[x]);
//            for (int j = 1; j * j <= x; j++) {
//                if (x % j == 0) {
//                    mp_yin[j] = max(t_, mp_yin[j]);
//                    int y = x / j;
//                    if (y != j) mp_yin[y] = max(t_, mp_yin[y]);
//                }
//            }
//            ans = max(ans, t_);
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// VP 牛客周赛 Round 99
// 036. A
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//    string n;
//    cin >> n;
//    string s = "99";
//    for (int i = 0; i < 4; i++) {
//        if (n.substr(i, 2) == s) {
//            cout << "YES" << endl;
//            return 0;
//        }
//    }
//    cout << "NO" << endl;
//    return 0;
//}

// 037. B
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        int n;
//        string s;
//        cin >> n >> s;
//        int ans = 0;
//        for (int i = 0; i < n; i++) ans = max(ans, (int)s[i]);
//        cout << ans << endl;
//    }
//    return 0;
//}

// 038. C
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        int k;
//        cin >> k;
//        if (k == 0) {
//            cout << 1 << endl;
//        } else if (k == 1) {
//            cout << 4 << endl;
//        } else if (k == 2) {
//            cout << 8 << endl;
//        } else {
//            if (k & 1) {
//                cout << 4;
//                k--;
//                for (int i = 1; i <= k / 2; i++) cout << 8;
//                cout << endl;
//            } else {
//                for (int i = 1; i <= k / 2; i++) cout << 8;
//                cout << endl;
//            }
//        }
//    }
//    return 0;
//}

// 039. D
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        int x, p;
//        cin >> x >> p;
//        int p_ = p;
//        if (x == 1) {
//            cout << 2 * p - 1 << endl;
//        } else {
//            if (p <= x - 1) cout << 2 * p << endl;
//            else {
//                p -= x - 1;
//                if ((p - 1) % x == 0) {
//                    int y = (p - 1) / x + 1;
//                    cout << 2 * y - 1 << endl;
//                } else {
//                    int y = (p - 1) / x + 1;
//                    p_ -= y;
//                    cout << 2 * p_ << endl;
//                }
//            }
//        }
//    }
//    return 0;
//}

// 040. F
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// signed main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        int n, m;
//        cin >> n >> m;
//        int ans = 0;
//        for (int i = 31; i >= 0; i--) {
//            int x = (1LL << i);
//            if (m * x <= n) {
//                ans += x;
//                n -= m * x;
//            } else {
//                if (n > m * (x - 1)) {
//                    int k = (n - m * (x - 1) + x - 1) / x;
//                    n -= k * x;
//                }
//            }
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 2025.7.7   同上场比赛
// 041. E
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 2, 1e9 + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        unordered_map<int, int> cnt, pos;
//        for (int i = 1; i <= n; i++) {
//            cnt[a[i]]++;
//            pos[a[i]] = i;
//        }
//        int r = n;
//        while (r >= 1 && a[r] < a[r + 1] && cnt[a[r]] == 1 && a[r] >= r)
//            r--;
//        if (r == 0) {
//            cout << 0 << endl;
//            continue;
//        }
//        set<int> st;
//        for (int i = 1; i <= r; i++) st.insert(a[i]);
//        int ans = st.size();
//        for (int s : st) {
//            if (cnt[s] == 1 && pos[s] == s) ans--;
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 042. P2730 [USACO3.2] 魔板 Magic Squares
// #include <bits/stdc++.h>
// using namespace std;
//
// struct node {
//    int step;
//    string s;
//    char op;
//    int qian;
//};
//
// string A(string a) {
//    return a.substr(4, 4) + a.substr(0, 4);
//}
//
// string B(string a) {
//    string res(8, ' ');
//    for (int i = 0; i < 4; i++) res[i] = a[((i - 1) % 4 + 4) % 4];
//    for (int i = 0; i < 4; i++) res[i + 4] = a[4 + ((i - 1) % 4 + 4) % 4];
//    return res;
//}
//
// string C(string a) {
//    string res = a;
//    res[1] = a[5];
//    res[2] = a[1];
//    res[5] = a[6];
//    res[6] = a[2];
//    return res;
//}
//
// signed main() {
//    vector<node> ans;
//    unordered_map<string, bool> vis;
//    string s;
//    for (int i = 1; i <= 8; i++) {
//        char c;
//        cin >> c;
//        s += c;
//    }
//    reverse(s.begin() + 4, s.end());
//    queue<node> q;
//    q.push({0, "12348765", ' ', -1});
//    while (!q.empty()) {
//        int qian = ans.size();
//        node no = q.front();
//        q.pop();
//        vis[no.s] = true;
//        ans.push_back(no);
//        if (no.s == s) {
//            break;
//        }
//        string sA = A(no.s);
//        if (!vis[sA]) {
//            q.push({no.step + 1, sA, 'A', qian});
//        }
//        string sB = B(no.s);
//        if (!vis[sB]) {
//            q.push({no.step + 1, sB, 'B', qian});
//        }
//        string sC = C(no.s);
//        if (!vis[sC]) {
//            q.push({no.step + 1, sC, 'C', qian});
//        }
//    }
//    cout << ans.back().step << endl;
//    string step(1, ans.back().op);
//    int i = ans.back().qian;
//    while (ans.back().step != 0) {
//        if (ans[i].op == ' ') break;
//        step += ans[i].op;
//        i = ans[i].qian;
//    }
//    reverse(step.begin(), step.end());
//    cout << step << endl;
//    return 0;
//}

// 043. P1120 小木棍
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 66;
//
// int n, a[N], sum, used[N], cnt, len;
//
// void dfs(int u, int cur, int start) {
//    if (u > cnt) {
//        cout << len << endl;
//        exit(0);
//    }
//    if (cur == len) dfs(u + 1, 0, 1);
//    for (int i = start; i <= n; i++) {
//        if (cur + a[i] > len) continue;
//        if (used[i]) continue;
//        used[i] = 1;
//        dfs(u, cur + a[i], i + 1);
//        used[i] = 0;
//
//        if (cur == 0) return;
//        if (a[i] + cur == len) return;
//        while (i < n && a[i] == a[i + 1]) i++;
//    }
//}
//
// signed main() {
//    cin >> n;
//    for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
//    sort(a + 1, a + n + 1);
//    reverse(a + 1, a + n + 1);
//    for (len = a[1]; ; len++) {
//        if (sum % len != 0) continue;
//        cnt = sum / len;
//        dfs(1, 0, 1);
//    }
//    return 0;
//}

// 044. P1368 【模板】最小表示法
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 6e5 + 10;
// int a[N];
//
// signed main() {
//    int n;
//    cin >> n;
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    for (int i = 1; i <= n; i++) a[i + n] = a[i];
//
//    int i = 1, j = 2, k = 0;
//    while (i <= n && j <= n) {
//        for (k = 0; a[i + k] == a[j + k]; k++);
//        if (a[i + k] > a[j + k]) i = i + k + 1;
//        else j = j + k + 1;
//        if (i == j) j++;
//    }
//    int ans = min(i, j);
//    for (i = ans; i <= ans + n - 1; i++) cout << a[i] << ' ';
//
//    return 0;
//}

// 045. 牛客挑战赛80 A https://ac.nowcoder.com/acm/contest/112318/A
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// signed main() {
//    int n, q;
//    cin >> n >> q;
//    vector<int> a(n + 1, n + 1);
//    string s;
//    cin >> s;
//    int ans = 0;
//    while (q--) {
//        int l, r;
//        cin >> l >> r;
//        ans += max(0LL, a[l] - r);
//        a[l] = min(a[l], r);
//        cout << ans << endl;
//    }
//    return 0;
//}

// 2025.7.8 昨天就做了5道题。。。
// 046. 牛客挑战赛80 B https://ac.nowcoder.com/acm/contest/112318/B
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// signed main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        int ans = 0;
//        for (int i = 1; i <= n; i++) ans ^= (a[i] & 1);
//        int quan1 = false;
//        for (int i = 1; i <= 60; i++) {
//            int x = 0;
//            if (!quan1) {
//                for (int j = 1; j <= n; j++) {
//                    if (((a[j] >> i) & 1) != ((a[j] >> (i - 1)) & 1)) {
//                        quan1 = true;
//                        break;
//                    }
//                    x ^= (a[j] >> i) & 1;
//                }
//            }
//            if (quan1 || x) ans += (1LL << i);
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// VP  AtCoder Beginner Contest 412
// 047. A
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int n;
//    cin >> n;
//    int ans = 0;
//    while (n--) {
//        int a, b;
//        cin >> a >> b;
//        ans += (b > a);
//    }
//    cout << ans << endl;
//    return 0;
//}

// 048. B
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    string s, t;
//    cin >> s >> t;
//    unordered_map<char, bool> mp;
//    for (char c : t) mp[c] = true;
//    int ans = true;
//    for (int i = 1; i < s.size(); i++) {
//        if (s[i] >= 'A' && s[i] <= 'Z') {
//            if (!mp[s[i - 1]]) {
//                ans = false;
//                break;
//            }
//        }
//    }
//    if (ans) cout << "Yes" << endl;
//    else cout << "No" << endl;
//    return 0;
//}

// 049. C
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        sort(a.begin() + 2, a.end() - 1);
//        int ans = 2;
//        if (2 * a[1] >= a[n]) {
//            cout << 2 << endl;
//            continue;
//        }
//        int shang = a[1];
//        for (int i = 2; i < n; i++) {
//            if (2 * shang >= a[n]) break;
//            int t = i;
//            while (i <= n && a[i] <= 2 * shang) i++;
//            if (i == t) {
//                ans = -1;
//                break;
//            }
//            if (i == n + 1) break;
//            shang = a[i - 1];
//            i--;
//            ans++;
//        }
//        if ((ans == 2 && a[1] * 2 < a[n]) || 2 * shang < a[n]) ans = -1;
//        cout << ans << endl;
//    }
//    return 0;
//}

// 050. E
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1e7 + 10;
//
// int primes[N], cnt;
// bool vis[N];
// bool vis2[N];
// int l, r;
// bool mi[N];
//
// void init() {
//    for (int i = 2; i < N; i++) {
//        if (!vis[i]) primes[cnt++] = i;
//        for (int j = 0; primes[j] * i < N; j++) {
//            vis[i * primes[j]] = true;
//            if (i % primes[j] == 0) break;
//        }
//    }
//}
//
// signed main() {
//    cin >> l >> r;
//    init();
//    for (int i = 0; i < cnt; i++) {
//        int p = primes[i];
//        int start = (l + p - 1) / p * p;
//        if (start == p) start = 2 * p;
//        for (int j = start; j <= r; j += p) vis2[j - l] = true;
//    }
//    for (int i = 0; i < cnt; i++) {
//        int p = primes[i];
//        while (p < l) p = p * primes[i];
//        while (p <= r) {
//            mi[p - l] = true;
//            p = p * primes[i];
//        }
//    }
//    int ans = 1;
//    for (int i = l + 1; i <= r; i++) {
//        ans += (mi[i - l] || !vis2[i - l]);
//    }
//    cout << ans << endl;
//    return 0;
//}

// 051. P1835 素数密度 (以前做过，复习一下，因为和上一题有相同的思想)
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1e6 + 10;
//
// int l, r, primes[N], cnt;
// bool vis[N];
//
// void euler() {
//    for (int i = 2; i < N; i++) {
//        if (!vis[i]) primes[cnt++] = i;
//        for (int j = 0; primes[j] * i < N; j++) {
//            vis[primes[j] * i] = true;
//            if (i % primes[j] == 0) break;
//        }
//    }
//}
//
// signed main() {
//    cin >> l >> r;
//    if (l == 1) l++;
//    euler();
//    memset(vis, 0, sizeof vis);
//    for (int i = 0; i < cnt; i++) {
//        int p = primes[i];
//        int start = (l + p - 1) / p * p;
//        if (start == p) start = 2 * p;
//        for (int j = start; j <= r; j += p) vis[j - l] = true;
//    }
//    int ans = 0;
//    for (int i = l; i <= r; i++) ans += (vis[i - l] == 0);
//    cout << ans << endl;
//    return 0;
//}

// VP Codeforces Round 479 (Div. 3)   https://codeforces.com/contest/977
// 很不错，AK！！！再一次AK！！！继续努力！
// 052. A
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int n, k;
//    cin >> n >> k;
//    while (k--) {
//        int x = n % 10;
//        if (x == 0) {
//            n = n / 10;
//        } else {
//            n = n - 1;
//        }
//    }
//    cout << n;
//    return 0;
//}

// 053. B
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int n;
//    cin >> n;
//    string s;
//    cin >> s;
//    unordered_map<string, int> mp;
//    for (int i = 0; i < n - 1; i++) mp[s.substr(i, 2)]++;
//    int maxn = -1;
//    string ans;
//    for (int i = 0; i < n - 1; i++) {
//        if (mp[s.substr(i, 2)] > maxn) {
//            maxn = mp[s.substr(i, 2)];
//            ans = s.substr(i, 2);
//        }
//    }
//    cout << ans << endl;
//    return 0;
//}

// 054. C
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int n, k;
//    cin >> n >> k;
//    vector<int> a(n + 1);
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    sort(a.begin() + 1, a.end());
//    if (k == n) {
//        cout << a[n] << endl;
//        return 0;
//    }
//    if (k == 0) {
//        int ans = a[1] - 1;
//        if (ans <= 0) cout << -1 << endl;
//        else cout << ans << endl;
//        return 0;
//    }
//    int ans = a[k];
//    if (ans == a[k + 1]) ans = -1;
//    cout << ans << endl;
//    return 0;
//}

// 055. F
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int n;
//    cin >> n;
//    vector<int> a(n + 1);
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    unordered_map<int, int> mp;
//    for (int i = 1; i <= n; i++) {
//        mp[a[i]] = mp[a[i] - 1] + 1;
//    }
//    int maxn = -1;
//    int last = -1;
//    for (auto& [x, cnt] : mp) {
//        if (cnt > maxn) {
//            maxn = cnt;
//            last = x;
//        }
//    }
//    vector<int> ans;
//    for (int i = n; i >= 1; i--) {
//        if (a[i] == last) {
//            ans.push_back(i);
//            last--;
//        }
//    }
//    reverse(ans.begin(), ans.end());
//    cout << maxn << endl;
//    for (int i : ans) cout << i << ' ';
//    cout << endl;
//    return 0;
//}

// 056. D
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// int n;
// unordered_map<int, int> mp;
// int ans[101];
//
// void dfs(int x, int cnt) {
//    ans[cnt] = x;
//    if (cnt == n) {
//        for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
//        exit(0);
//    } else {
//        if (mp[x * 2]) {
//            mp[x * 2]--;
//            dfs(x * 2, cnt + 1);
//            mp[x * 2]++;
//        }
//        if (x % 3 == 0 && mp[x / 3]) {
//            mp[x / 3]--;
//            dfs(x / 3, cnt + 1);
//            mp[x / 3]++;
//        }
//    }
//}
//
// signed main() {
//    cin >> n;
//    vector<int> a(n + 1);
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    for (int i = 1; i <= n; i++) mp[a[i]] = 1;
//    for (int i = 1; i <= n; i++) {
//        if (a[i] % 3 == 0) {
//            dfs(a[i], 1);
//        }
//    }
//    sort(a.begin() + 1, a.end());
//    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
//    return 0;
//}

// 057. E
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 2e5 + 10;
//
// vector<int> g[N];
// int vis[N];
//
// bool dfs(int u, int start, int sum) {
//    vis[u] = 1;
//    if (g[u].size() != 2) return false;
//    for (int i = 0; i < 2; i++) {
//        if (!vis[g[u][i]]) {
//            return dfs(g[u][i], start, sum + 1);
//        } else {
//            if (g[u][i] == start && sum >= 3) return true;
//        }
//    }
//    return false;
//}
//
// signed main() {
//    int n, m;
//    cin >> n >> m;
//    while (m--) {
//        int u, v;
//        cin >> u >> v;
//        g[u].emplace_back(v);
//        g[v].emplace_back(u);
//    }
//    int ans = 0;
//    for (int i = 1; i <= n; i++) {
//        if (!vis[i])
//            ans += dfs(i, i, 1);
//    }
//    cout << ans << endl;
//    return 0;
//}

// 2025.7.9
// 058. P2638 安全系统   真油饼，爆longlong。
// #include <bits/stdc++.h>
// using namespace std;
// #define int __int128
//
//// 重载 << 输出运算符
// std::ostream& operator<<(std::ostream& os, __int128 value) {
//     // 处理零的情况
//     if (value == 0) return os << "0";
//
//     // 处理负数
//     bool is_negative = false;
//     if (value < 0) {
//         is_negative = true;
//         value = -value; // 转换为正数处理
//     }
//
//     // 数字转字符串
//     char buffer[41]; // 最多39位数字 + 符号 + 空字符
//     char* ptr = buffer + sizeof(buffer) - 1;
//     *ptr = '\0';
//
//     while (value > 0) {
//         *--ptr = '0' + static_cast<char>(value % 10);
//         value /= 10;
//     }
//
//     if (is_negative) *--ptr = '-';
//
//     return os << ptr;
// }
//
// std::istream& operator>>(std::istream& is, __int128& value) {
//     value = 0;
//
//     std::string s;
//     is >> s; // 读取为字符串
//
//     // 处理符号和前缀空格
//     size_t start = 0;
//     bool is_negative = false;
//
//     if (s[0] == '-') {
//         is_negative = true;
//         start = 1;
//     } else if (s[0] == '+') {
//         start = 1;
//     }
//
//     // 验证字符串内容（只允许数字）
//     if (s.find_first_not_of("0123456789", start) != std::string::npos) {
//         is.setstate(std::ios::failbit);
//         return is;
//     }
//
//     // 字符串转数字
//     for (size_t i = start; i < s.size(); ++i) {
//         if (value > (std::numeric_limits<__int128>::max() / 10)) {
//             is.setstate(std::ios::failbit);
//             return is;
//         }
//
//         value *= 10;
//         value += s[i] - '0';
//     }
//
//     if (is_negative) value = -value;
//
//     return is;
// }
//
// int n, a_, b_;
// int vis[51][51][51];
//
// int dfs(int deep, int a, int b) {
//     if (vis[deep][a][b]) return vis[deep][a][b];
//     if (deep == n) return 1;
//     int res = 0;
//     for (int i = 0; i <= a; i++) {
//         for (int j = 0; j <= b; j++) {
//             res += dfs(deep + 1, a - i, b - j);
//         }
//     }
//     vis[deep][a][b] = res;
//     return res;
// }
//
// signed main() {
//     cin >> n >> a_ >> b_;
//     int ans = dfs(0, a_, b_);
//     cout << ans << endl;
//     return 0;
// }

// 059. P1246 编码
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// int C[30][30];
//
// void init() {
//    C[0][0] = 1;
//    for (int i = 1; i <= 29; i++) {
//        C[i][0] = 1;
//        for (int j = 1; j <= i; j++) {
//            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
//        }
//    }
//}
//
// signed main() {
//    init();
//    string s;
//    cin >> s;
//    int n = s.size();
//    if (n == 1) {
//        cout << (s[0] - 'a' + 1) << endl;
//        return 0;
//    }
//    for (int i = 0; i < n - 1; i++) {
//        if (s[i] >= s[i + 1]) {
//            cout << 0 << endl;
//            return 0;
//        }
//    }
//    int ans = 0;
//    for (int i = 1; i <= n - 1; i++) ans += C[26][i];
//    char d = 'a';
//    for (int i = 0; i < n; i++) {
//        while (d < s[i]) {
//            ans += C[('z' - d)][n - i - 1];
//            d++;
//        }
//        d++;
//    }
//    ans++;
//    cout << ans << endl;
//    return 0;
//}

// 060. P2842 纸币问题 1
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int n, w;
//    cin >> n >> w;
//    vector<int> dp(w + 1, 1e9);
//    vector<int> a(n);
//    for (int i = 0; i < n; i++) cin >> a[i];
//    sort(a.begin(), a.end());
//    for (int i : a)
//        if (i <= w) dp[i] = 1;
//    for (int i = 1; i <= w; i++) {
//        for (int j = 0; j < n; j++) {
//            if (i - a[j] > 0) dp[i] = min(dp[i], dp[i - a[j]] + 1);
//            else break;
//        }
//    }
//    cout << dp[w] << endl;
//    return 0;
//}

// VP Codeforces Round 710 (Div. 3) https://codeforces.com/contest/1506
// 061. A
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// signed main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        int n, m, x;
//        cin >> m >> n >> x;
//        int hang = (x / m) + 1;
//        int lie = x % m;
//        if (lie == 0) {
//            lie = m;
//            hang--;
//        }
//        int ans = n * (lie - 1) + hang;
//        cout << ans << endl;
//    }
//    return 0;
//}

// 062. B
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// signed main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        int n, k;
//        cin >> n >> k;
//        string s;
//        cin >> s;
//        int ans = 0;
//        int start, end;
//        for (start = 0; start < s.size(); start++) {
//            if (s[start] == '*') {
//                s[start] = 'x';
//                ans++;
//                break;
//            }
//        }
//        for (end = s.size() - 1; end >= 0; end--) {
//            if (s[end] == '*') {
//                ans++;
//                break;
//            }
//        }
//        if (end < 0) {
//            cout << ans << endl;
//            continue;
//        }
//        for (int i = start; i < s.size(); i++) {
//            if (s[i] == '*' && i - start > k) {
//                for (int j = i - 1; j > start; j--) {
//                    if (s[j] == '*') {
//                        start = j;
//                        ans++;
//                        break;
//                    }
//                }
//            }
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 063. C
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// signed main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        string s1, s2;
//        cin >> s1 >> s2;
//        int n1 = s1.size(), n2 = s2.size();
//        s1 = '@' + s1 + '#';
//        s2 = '%' + s2 + '*';
//        int maxn = -1;
//        for (int i = 1; i <= n1; i++) {
//            for (int j = 1; j <= n2; j++) {
//                int cnt = 0;
//                while (s1[i + cnt] == s2[j + cnt]) cnt++;
//                maxn = max(maxn, cnt);
//            }
//        }
//        int ans = (n1 + n2 - 2 * maxn);
//        cout << ans << endl;
//    }
//    return 0;
//}

// 064. D
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// signed main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        int n;
//        cin >> n;
//        unordered_map<int, int> mp;
//        for (int i = 1; i <= n; i++) {
//            int a;
//            cin >> a;
//            mp[a]++;
//        }
//        priority_queue<int> q;
//        for (auto& [key, cnt] : mp) q.push(cnt);
//        int ans = -1;
//        if (q.size() == 1) {
//            cout << q.top() << endl;
//            continue;
//        }
//        while (q.size() >= 2) {
//            int a = q.top();
//            q.pop();
//            int b = q.top();
//            q.pop();
//            if (a >= 1) q.push(a - 1);
//            if (b >= 1) q.push(b - 1);
//            if (a == 0 || b == 0) {
//                ans = max(a, b);
//                break;
//            }
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 065. E
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// signed main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        vector<int> ans_xiao(n + 1), ans_da(n + 1);
//        set<int> xiao, da;
//        for (int i = 1; i <= n; i++) {
//            xiao.insert(i);
//        }
//        int maxn = 0;
//        for (int i = 1; i <= n; i++) {
//            if (maxn < a[i]) {
//                for (int j = maxn + 1; j < a[i]; j++) da.insert(j);
//                ans_xiao[i] = a[i];
//                ans_da[i] = a[i];
//                xiao.erase(a[i]);
//                da.erase(a[i]);
//                maxn = a[i];
//            } else {
//                ans_xiao[i] = *xiao.begin();
//                xiao.erase(xiao.begin());
//                ans_da[i] = *da.rbegin();
//                da.erase(*da.rbegin());
//            }
//        }
//        for (int i = 1; i <= n; i++) cout << ans_xiao[i] << ' ';
//        cout << endl;
//        for (int i = 1; i <= n; i++) cout << ans_da[i] << ' ';
//        cout << endl;
//    }
//    return 0;
//}

// 066. G. Maximize the Remaining String
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        string s;
//        cin >> s;
//        stack<char> stk;
//        unordered_map<char, int> vis, cnt;
//        for (char c : s) cnt[c]++;
//        for (char i : s) {
//            if (stk.empty()) {
//                stk.push(i);
//                vis[i] = 1;
//                cnt[i]--;
//            } else {
//                if (!vis[i]) {
//                    while (!stk.empty() && i > stk.top() && cnt[stk.top()] > 0) {
//                        vis[stk.top()] = 0;
//                        stk.pop();
//                    }
//                    stk.push(i);
//                    vis[i] = 1;
//                    cnt[i]--;
//                } else {
//                    cnt[i]--;
//                }
//            }
//        }
//        string ans;
//        while (!stk.empty()) {
//            ans += stk.top();
//            stk.pop();
//        }
//        reverse(ans.begin(), ans.end());
//        cout << ans << endl;
//    }
//    return 0;
//}

// 2025.7.10
// VP AtCoder Beginner Contest 409
// 067. A
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int n;
//    cin >> n;
//    string t, s;
//    cin >> t >> s;
//    for (int i = 0; i < n; i++) {
//        if (s[i] == t[i] && s[i] == 'o') {
//            cout << "Yes" << endl;
//            return 0;
//        }
//    }
//    cout << "No" << endl;
//    return 0;
//}

// 068. B
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int n;
//    cin >> n;
//    vector<int> a(n);
//    for (int i = 0; i < n; i++) cin >> a[i];
//    int l = 0, r = *max_element(a.begin(), a.end());
//    while (l <= r) {
//        int mid = (l + r) >> 1;
//        int cnt = 0;
//        for (int i = 0; i < n; i++) {
//            if (a[i] >= mid) {
//                cnt++;
//            }
//        }
//        if (cnt >= mid) l = mid + 1;
//        else r = mid - 1;
//    }
//    cout << l - 1 << endl;
//    return 0;
//}

// 069. C
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// signed main() {
//    int n, l;
//    cin >> n >> l;
//    vector<int> a(n + 1);
//    for (int i = 1; i < n; i++) cin >> a[i];
//    for (int i = 1; i < n; i++) a[i] += a[i - 1];
//    if (l % 3 != 0) {
//        cout << 0 << endl;
//        return 0;
//    }
//    unordered_map<int, int> mp;
//    for (int i = 0; i < n; i++) mp[a[i] % l]++;
//    int ans = 0;
//    for (int i = 0; i < l; i++) {
//        if (i - l / 3 >= 0 && i + l / 3 < l) {
//            ans += mp[i - l / 3] * mp[i + l / 3] * mp[i];
//        }
//    }
//    cout << ans << endl;
//    return 0;
//}

// 070. D
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        string s;
//        cin >> s;
//        for (int i = 0; i < n - 1; i++) {
//            if (s[i] > s[i + 1]) {
//                char c = s[i];
//                int j = i + 1;
//                while (j < n && c >= s[j]) j++;
//                if (j == n) {
//                    s.erase(s.begin() + i);
//                    s += c;
//                    break;
//                } else {
//                    s.insert(s.begin() + j, c);
//                    s.erase(s.begin() + i);
//                    break;
//                }
//            }
//        }
//        cout << s << endl;
//    }
//    return 0;
//}

// 2025年ICPC新疆维吾尔自治区大学生程序设计竞赛（重现赛）@落雪世间白
// 071. A
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//    int a, b, x, y, p;
//    cin >> a >> b >> x >> y >> p;
//    set<int> s;
//    for (int i = 0; x * i <= p; i++) {
//        int shen = p - x * i;
//        for (int j = 0; j * y <= shen; j++) {
//            s.insert(b * i + a * j + i * j);
//        }
//    }
//    cout << s.size() << endl;
//    return 0;
//}

// 072. G
// #include <bits/stdc++.h>
// using namespace  std;
// #define int long long
//
// signed main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        vector<int> a(27);
//        unordered_map<char, int> mp;
//        for (char i = 'a'; i <= 'z'; i++) {
//            int x;
//            cin >> x;
//            mp[i] = x;
//        }
//        int ans = 0;
//        string s;
//        cin >> s;
//        for (char c : s) {
//            if (mp[c] != 0) ans++;
//        }
//        if (ans == 0) ans = s.length();
//        cout << ans << endl;
//    }
//    return 0;
//}

// 073. C
// #include <bits/stdc++.h>
// using namespace std;
// const int mod = 1e9 + 7;
// #define int long long
//
// signed main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        int n;
//        cin >> n;
//        vector<int> a(32);
//        for (int i = 1; i <= n; i++) {
//            int x;
//            cin >> x;
//            int v = 0;
//            for (int j = 0; j <= 31; j++) {
//                if ((x >> j) & 1) {
//                    v = (v + a[j]) % mod;
//                }
//            }
//
//            if (i == 1) v = 1;
//            if (i == n) cout << v << endl;
//
//            for (int j = 0; j <= 31; j++) {
//                if ((x >> j) & 1) {
//                    a[j] = (a[j] + v) % mod;
//                }
//            }
//        }
//    }
//    return 0;
//}

// 074. I
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e6 + 1, M = 1e6;
//
// struct node {
//    int l, r;
//    int ji, ou;
//};
//
// node tr[N << 2];
//
// void pushup(node& rt, node& zuo, node& you) {
//    rt.ji = max(zuo.ji, you.ji);
//    rt.ou = max(zuo.ou, you.ou);
//}
//
// void build(int u, int l, int r) {
//    tr[u] = {l, r};
//    if (l == r) return;
//    int mid = (l + r) >> 1;
//    build(u << 1, l, mid);
//    build(u << 1 | 1, mid + 1, r);
//}
//
// node query(int u, int l, int r) {
//    if (l <= tr[u].l && tr[u].r <= r) return tr[u];
//    int mid = (tr[u].l + tr[u].r) >> 1;
//    if (r <= mid) return query(u << 1, l, r);
//    else if (l > mid) return query(u << 1 | 1, l, r);
//    else {
//        node res1 = query(u << 1, l, mid);
//        node res2 = query(u << 1 | 1, mid + 1, r);
//        node res;
//        pushup(res, res1, res2);
//        return res;
//    }
//}
//
// void modify(int u, int pos, int x) {
//    if (tr[u].l == tr[u].r && tr[u].r == pos) {
//        if (x & 1) tr[u].ji = x;
//        else tr[u].ou = x;
//    } else {
//        int mid = (tr[u].l + tr[u].r) >> 1;
//        if (pos <= mid) modify(u << 1, pos, x);
//        else modify(u << 1 | 1, pos, x);
//        pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
//    }
//}
//
// signed main() {
//    int n, k1, k2;
//    cin >> n >> k1 >> k2;
//    build(1, 1, M);
//    for (int i = 1; i <= n; i++) {
//        int x;
//        cin >> x;
//        node ou = query(1, max(1, x - k1), min(M, x + k1));
//
//        node ji1 = {0, 0, -1, -1};
//        node ji2 = {0, 0, -1, -1};
//        if (x - k2 >= 1) ji1 = query(1, 1, max(1, x - k2));
//        if (x + k2 <= M) ji2 = query(1, min(M, x + k2), M);
//        int ji = max(ji1.ji, ji2.ji);
//        modify(1, x, ji + 1);
//        modify(1, x, ou.ou + 1);
//    }
//    node ans = query(1, 1, M);
//    cout << max(ans.ji, ans.ou) << endl;
//    return 0;
//}

// 075. E
// #include <bits/stdc++.h>
// using namespace std;
// const int mod = 1e9 + 7;
// #define int long long
//
// int qmi(int a, int k) {
//    int res = 1;
//    while (k) {
//        if (k & 1) res = res * a % mod;
//        a = a * a % mod;
//        k >>= 1;
//    }
//    return res;
//}
//
// signed main() {
//    int a, b, n;
//    cin >> a >> b >> n;
//    int d = gcd(a, b);
//    int a_ = a / d, b_ = b / d;
//    int x1 = a_ * qmi(b_, n) % mod;
//    int x2 = 0;
//    int b_mi = 1;
//    for (int i = 0; i < n; i++) {
//        x2 = (x2 + b_mi) % mod;
//        b_mi = (b_ * b_mi) % mod;
//    }
//    int ans = ((x1 + x2) % mod) * d % mod;
//    cout << ans << endl;
//    return 0;
//}

// 076. F
// #include <bits/stdc++.h>
// using namespace std;
//
// unordered_map<int, vector<pair<int, int>>> mp;
// unordered_map<int, int> vis;
// int n, k;
//
// int dfs(int x, pair<int, int>& p) {
//    if (vis.find(p.first * n + p.second) != vis.end()) {
//        return vis[p.first * n + p.second];
//    }
//    if (x == k) return 0;
//    int res = 1e9;
//    for (auto& p_n : mp[x + 1]) {
//        res = min(res, dfs(x + 1, p_n) + abs(p.first - p_n.first) + abs(p.second - p_n.second));
//    }
//    vis[p.first * n + p.second] = res;
//    return res;
//}
//
// signed main() {
//    cin >> n >> k;
//    int x;
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= n; j++) {
//            cin >> x;
//            mp[x].emplace_back(i, j);
//        }
//    }
//    for (int i = 1; i <= k; i++) {
//        if (mp[i].empty()) {
//            cout << -1 << endl;
//            return 0;
//        }
//    }
//    int ans = 1e9;
//    for (auto& p : mp[1]) {
//        ans = min(ans, dfs(1, p));
//    }
//    cout << ans << endl;
//    return 0;
//}

// 077. H
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int n, m;
//    cin >> n >> m;
//    vector<vector<int>> a(m, vector<int>());
//    for (int i = 0; i < m; i++) {
//        int cnt;
//        cin >> cnt;
//        for (int j = 0; j < cnt; j++) {
//            int k;
//            cin >> k;
//            a[i].push_back(--k);
//        }
//    }
//    int ans = 100;
//    int tar = (1 << n) - 1;
//    for (int i = 0; i < (1 << m); i++) {
//        int cnt = 0;
//        int temp = 0;
//        for (int j = 0; j < m; j++) {
//            if ((i >> j) & 1) {
//                cnt++;
//                for (int x : a[j]) {
//                   temp = temp | (1 << x);
//                }
//            }
//        }
//        if (temp == tar) {
//            ans = min(ans, cnt);
//        }
//    }
//    if (ans == 100) ans = -1;
//    cout << ans << endl;
//    return 0;
//}

// 078. AtCoder Beginner Contest 409 E
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1e5 + 10;
//
// int a[N], n, du[N];
// int ans;
// vector<pair<int, int>> g[N];
//
// void dfs(int u, int fa) {
//    for (auto & [v, w] : g[u]) {
//        if (v != fa) {
//            dfs(v, u);
//            ans += abs(w * a[v]);
//            a[u] += a[v];
//        }
//    }
//}
//
// signed main() {
//    cin >> n;
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    for (int i = 1; i < n; i++) {
//        int u, v, w;
//        cin >> u >> v >> w;
//        g[u].emplace_back(v, w);
//        g[v].emplace_back(u, w);
//        du[u]++;
//        du[v]++;
//    }
//    int u = 1;
//    while (du[u] == 1)u++;
//    dfs(u, 0);
//    cout << ans << endl;
//    return 0;
//}

// 2025.7.11
// 079. H
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 10, mod = 998244353;
// #define int long long
//
// int dp[N];
//
// signed main() {
//    memset(dp, 0x3f, sizeof dp);
//    int n;
//    cin >> n;
//    dp[0] = 0;
//    dp[1] = 1;
//    for (int i = 2; i <= n; i++) {
//        for (int j = 1; j * j <= i; j++) {
//            dp[i] = min(dp[i], dp[i - j * j] + 1);
//        }
//    }
//    int ans = 1;
//    for (int i = 1; i <= n; i++) {
//        ans = (ans * dp[i]) % mod;
//    }
//    cout << ans << endl;
//    return 0;
//}

// 080. D
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int n;
//    cin >> n;
//    vector<int> ans(n + 1);
//    for (int i = 1; i <= n; i++) cin >> ans[i];
//    vector<int> ans2(ans.begin(), ans.end());
//    if (n == 3) {
//        string s;
//        for (int i = 1; i <= n; i++) s += '0' + ans[i];
//        if (s == "123" || s == "321") {
//            cout << -1 << endl;
//        } else {
//            if (s == "132") {
//                cout << "2 1 3" << endl;
//            } else if (s == "213") {
//                cout << "1 3 2" << endl;
//            } else if (s == "231") {
//                cout << "3 1 2" << endl;
//            } else if (s == "312") {
//                cout << "2 3 1" << endl;
//            }
//        }
//        return 0;
//    }
//
//    int cnt1 = 0, cnt2 = 0;
//    unordered_map<int, int> vis;
//    for (int i = 1; i < n; i++) {
//        if (ans[i] < ans[i + 1]) {
//            swap(ans[i], ans[i + 1]);
//            cnt1++;
//            vis[i] = 1;
//            break;
//        }
//    }
//
//    for (int i = 1; i < n; i++) {
//        if (ans[i] > ans[i + 1] && !vis[i]) {
//            swap(ans[i], ans[i + 1]);
//            cnt2++;
//            break;
//        }
//    }
//    if (cnt1 == cnt2 && cnt1 == 1) {
//        for (int i = 1; i <= n; i++) {
//            cout << ans[i] << ' ';
//        }
//        cout << endl;
//    } else {
//        cnt1 = 0, cnt2 = 0;
//        vis.clear();
//        for (int i = 1; i < n; i++) {
//            if (ans2[i] > ans2[i + 1]) {
//                swap(ans2[i], ans2[i + 1]);
//                cnt1++;
//                vis[i] = 1;
//                break;
//            }
//        }
//
//        for (int i = 1; i < n; i++) {
//            if (ans2[i] < ans2[i + 1] && !vis[i]) {
//                swap(ans2[i], ans2[i + 1]);
//                cnt2++;
//                break;
//            }
//        }
//        if (cnt1 == cnt2 && cnt1 == 1) {
//            for (int i = 1; i <= n; i++) {
//                cout << ans2[i] << ' ';
//            }
//            cout << endl;
//        } else {
//            cout << -1 << endl;
//        }
//
//    }
//    return 0;
//}

// 081. B   线段树超时，服了，正解根本不用线段树，就我那么傻逼
// #include <bits/stdc++.h>
// #define endl '\n'
// using namespace std;
// const int N = 1e6 + 1;
//
// struct node {
//    int jian = 1e9, jia = 1e9, cntjian, cntjia;
//} tr[N << 2];
//
// void pushup(node& rt, node&zuo, node& you) {
//    if (zuo.jia < you.jia) {
//        rt.jia = zuo.jia;
//        rt.cntjia = zuo.cntjia;
//    } else if (zuo.jia > you.jia) {
//        rt.jia = you.jia;
//        rt.cntjia = you.cntjia;
//    } else {
//        rt.jia = you.jia;
//        rt.cntjia = max(zuo.cntjia, you.cntjia);
//    }
//
//    if (zuo.jian < you.jian) {
//        rt.jian = zuo.jian;
//        rt.cntjian = zuo.cntjian;
//    } else if (zuo.jian > you.jian) {
//        rt.jian = you.jian;
//        rt.cntjian = you.cntjian;
//    } else {
//        rt.jian = you.jian;
//        rt.cntjian = max(zuo.cntjian, you.cntjian);
//    }
//}
//
// node query(int u, int l, int r, int trl, int trr) {
//    if (l <= trl && trr <= r) return tr[u];
//    int mid = (trl + trr) >> 1;
//    if (r <= mid) return query(u << 1, l, r, trl, mid);
//    else if (l > mid) return query(u << 1 | 1, l, r, mid + 1, trr);
//    else {
//        node res1 = query(u << 1, l, mid, trl, mid);
//        node res2 = query(u << 1 | 1, mid + 1, r, mid + 1, trr);
//        node res;
//        pushup(res, res1, res2);
//        return res;
//    }
//}
//
// void modify(int u, int x, int jian, int jia, int cnt, int trl, int trr) {
//    if (trl == trr && trl == x) {
//        tr[u].jian = jian;
//        tr[u].jia = jia;
//        tr[u].cntjia = tr[u].cntjian = cnt;
//        return;
//    }
//    int mid = (trl + trr) >> 1;
//    if (x <= mid) modify(u << 1, x, jian, jia, cnt, trl, mid);
//    else modify(u << 1 | 1, x, jian, jia, cnt, mid + 1, trr);
//    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
//}
//
// signed main() {
//    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
//    int n, x;
//    cin >> n >> x;
//    modify(1, x, -x, x, 0, 1, N - 1);
//    for (int i = 1; i < n; i++) {
//        cin >> x;
//        node mi1 = query(1, 1, x, 1, N - 1);
//        node mi2 = query(1, x, N - 1, 1, N - 1);
//        int mi1_n = mi1.jian + x;
//        int mi2_n = mi2.jia - x;
//        if (mi1_n < mi2_n) {
//            modify(1, x, mi1_n - x, mi1_n + x, mi1.cntjian + 1, 1, N - 1);
//        } else if (mi1_n > mi2_n) {
//            modify(1, x, mi2_n - x, mi2_n + x, mi2.cntjia + 1, 1, N - 1);
//        } else {
//            modify(1, x, mi2_n - x, mi2_n + x, max(mi1.cntjian, mi2.cntjia) + 1, 1, N - 1);
//        }
//    }
//    node ans = query(1, x, x, 1, N - 1);
//    cout << (ans.jia + ans.jian) / 2 + n - 1 << ' ' << ans.cntjian << endl;
//    return 0;
//}

// 082. F
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int n, m;
//    cin >> n >> m;
//    vector<int> du(n + 1), vis(n + 1);
//    vector<int> g[n + 1];
//    while (m--) {
//        int u, v;
//        cin >> u >> v;
//        g[u].emplace_back(v);
//        du[v]++;
//    }
//    int k;
//    cin >> k;
//    vector<int> a(k), b(n + 1);
//    for (int i = 0; i < k; i++) {
//        cin >> a[i];
//        b[a[i]] = 1;
//    }
//    vector<int> ans;
//    bool have_ans = true;
//    auto topo = [&]() {
//        queue<int> q;
//        for (int i = 1; i <= n; i++)
//            if (!vis[i] && !b[i] && !du[i])
//                q.push(i);
//
//        while (!q.empty()) {
//            int v = q.front();
//            q.pop();
//            vis[v] = 1;
//            ans.push_back(v);
//            for (int i : g[v]) {
//                du[i]--;
//                if (!vis[i] && !b[i] && !du[i]) q.push(i);
//            }
//        }
//    };
//    topo();
//    for (int i : a) {
//        if (du[i]) {
//            have_ans = false;
//            break;
//        }
//        for (int j : g[i]) du[j]--;
//        ans.push_back(i);
//    }
//    topo();
//    if (!have_ans || ans.size() != n) cout << -1 << endl;
//    else {
//        for (int i : ans) cout << i << ' ';
//    }
//    return 0;
//}

// 2025.7.12
// 083. P2758 编辑距离
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    string a, b;
//    cin >> a >> b;
//    int n = a.size(), m = b.size();
//    a = ' ' + a;
//    b = ' ' + b;
//    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
//    for (int i = 1; i <= n; i++) dp[i][0] = i;
//    for (int i = 1; i <= m; i++) dp[0][i] = i;
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//            if (a[i] == b[j]) {
//                dp[i][j] = dp[i - 1][j - 1];
//            } else {
//                dp[i][j] = min(min(dp[i - 1][j], dp[i - 1][j - 1]), dp[i][j - 1]) + 1;
//            }
//        }
//    }
//    cout << dp[n][m] << endl;
//    return 0;
//}

// 084. P4838 P哥破解密码
// #include <bits/stdc++.h>
// using namespace std;
// const int mod = 19260817;
// #define int long long
//
// struct Matrix {
//    int a[4][4];
//    Matrix() {
//        memset(a, 0, sizeof a);
//    }
//    void setE() {
//        for (int i = 1; i <= 3; i++)
//            a[i][i] = 1;
//    }
//    Matrix operator*(const Matrix& b) {
//        Matrix res;
//        for (int i = 1; i <= 3; i++) {
//            for (int j = 1; j <= 3; j++) {
//                for (int k = 1; k <= 3; k++) {
//                    res.a[i][j] = (res.a[i][j] + this->a[i][k] * b.a[k][j]) % mod;
//                }
//            }
//        }
//        return res;
//    }
//};
//
// Matrix ksm(Matrix a, int k) {
//    Matrix res;
//    res.setE();
//    while (k) {
//        if (k & 1) res = res * a;
//        a = a * a;
//        k >>= 1;
//    }
//    return res;
//}
//
// signed main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        int n;
//        cin >> n;
//        Matrix a;
//        a.a[1][1] = 2, a.a[1][2] = 4, a.a[1][3] = 7;
//        Matrix chen;
//        chen.a[1][3] = chen.a[2][1] = chen.a[2][3] = chen.a[3][2] = chen.a[3][3] = 1;
//        a = a * ksm(chen, n - 1);
//        cout << a.a[1][1] << endl;
//    }
//    return 0;
//}

// 085. P1352 没有上司的舞会
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 6e3 + 10;
//
// int a[N], du[N];
// vector<int> g[N];
// int dp[N][2];
//
// void dfs(int u) {
//    if (g[u].size() == 0) {
//        dp[u][1] = a[u];
//        return;
//    }
//    dp[u][1] = a[u];
//    for (int i : g[u])  dfs(i);
//    for (int i : g[u]) {
//        dp[u][1] = max(dp[u][1] + dp[i][0], dp[u][1]);
//        dp[u][0] = max(dp[u][0], dp[u][0] + max(dp[i][1], dp[i][0]));
//    }
//}
//
// signed main() {
//    int n;
//    cin >> n;
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    for (int i = 1; i < n; i++) {
//        int u, v;
//        cin >> u >> v;
//        g[v].emplace_back(u);
//        du[u]++;
//    }
//    int u = 1;
//    while (du[u] != 0) u++;
//    dfs(u);
//    cout << max(dp[u][0], dp[u][1]) << endl;
//    return 0;
//}

// 086. P12136 [蓝桥杯 2025 省 B] 生产车间
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1010;
//
// vector<int> g[N];
// int a[N];
// int dp[N][N];
//
// void dfs(int u, int fa) {
//    if (g[u].size() == 1 && g[u][0] == fa) {
//        dp[u][a[u]] = a[u];
//        return;
//    }
//    for (int i : g[u]) {
//        if (i != fa) {
//            dfs(i, u);
//            for (int v = a[u]; v >= 0; v--) {
//                for (int j = 1; j <= v; j++) {
//                    dp[u][v] = max(dp[u][v], dp[u][v - j] + dp[i][j]);
//                }
//            }
//        }
//    }
//}
//
// signed main() {
//    int n;
//    cin >> n;
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    for (int i = 1; i < n; i++) {
//        int u, v;
//        cin >> u >> v;
//        g[u].emplace_back(v);
//        g[v].emplace_back(u);
//    }
//    dfs(1, 0);
//    cout << dp[1][a[1]] << endl;
//    return 0;
//}

// 087. P1005 [NOIP 2007 提高组] 矩阵取数游戏
// #include <bits/stdc++.h>
// using namespace std;
// #define int __int128
//
// std::ostream& operator<<(std::ostream& os, __int128 n) {
//    if (n == 0) {
//        return os << 0;
//    }
//    std::string s;
//    while (n > 0) {
//        s += char('0' + n % 10);
//        n /= 10;
//    }
//    std::reverse(s.begin(), s.end());
//    return os << s;
//}
//
// std::istream& operator>>(std::istream& is, __int128& x) {
//    char c;
//    while(c = is.get(), c != '-' && !isdigit(c));
//    if(c == '-') {
//        x = '0' - (c = is.get());
//        while(isdigit(c = getchar())) x = x * 10 + '0' - c;
//    } else {
//        x = c - '0';
//        while(isdigit(c = is.get())) x = x * 10 - '0' + c;
//    }
//    return is;
//}
//
// int mi[82];
//
// void init() {
//    mi[0] = 1;
//    for (int i = 1; i < 82; i++) mi[i] = 2 * mi[i - 1];
//}
//
// signed main() {
//    init();
//    int n, m;
//    cin >> n >> m;
//    vector<vector<int>> a(n + 1, vector<int>(m + 1));
//    for (int i = 1; i <= n; i++)
//        for (int j = 1; j <= m; j++)
//            cin >> a[i][j];
//    int ans = 0;
//    vector<vector<int>> dp(m + 1, vector<int>(m + 1));
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//            for (int k = 1; k + j - 1 <= m; k++) {
//                if (j == 1) {
//                    dp[k][j] = a[i][k] * 2;
//                } else {
//                    dp[k][j] = max(dp[k][j - 1] * 2 + 2 * a[i][k + j - 1], dp[k + 1][j - 1] * 2 + 2 * a[i][k]);
//                }
//            }
//        }
//        ans += dp[1][m];
//    }
//    cout << ans << endl;
//    return 0;
//}

// 牛客练习赛142(重现赛)
// 088. A
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int n;
//    cin >> n;
//    int x;
//    int ans = 0;
//    for (int i = 1; i <= n; i++) {
//        cin >> x;
//        string s = to_string(x);
//        ans -= x;
//        for (char & j : s) {
//            if (j == '0') j = '8';
//        }
//        ans += stoi(s);
//    }
//    cout << ans << endl;
//    return 0;
//}

// 089. B
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// int f(int x) {
//    int res = 0;
//    while (x) {
//        res++;
//        x = x - (x & -x);
//    }
//    return res;
//}
//
// int g(int x) {
//    int res = 0;
//    while (x) {
//        if (x & 1) {
//            x >>= 1;
//            continue;
//        }
//        res++;
//        x >>= 1;
//    }
//    return res + 1;
//}
//
// signed main() {
//    int x;
//    cin >> x;
//    int t = 1000;
//    while (t--) {
//        if (x == g(f(x))) {
//            cout << x << endl;
//            return 0;
//        }
//        x = g(f(x));
//    }
//    cout << -1 << endl;
//    return 0;
//}

// 090. C 战前准备
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int n, m;
//    cin >> n >> m;
//    stack<int> s;
//    for (int i = 1; i <= n; i++) {
//        int x;
//        cin >> x;
//        while (!s.empty() && s.top() + 1 < x) s.pop();
//        s.push(x);
//    }
//    int ans = 0;
//    while (!s.empty()) {
//        if (s.top() == 0) ans++;
//        s.pop();
//    }
//    cout << ans << endl;
//    return 0;
//}

// 091. D 第四次忍界大战
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 10;
// using ll = long long;
//
// int a[N], n;
// vector<int> g[N];
// ll ans;
//
// map<int, int> dfs(int u, int fa) {
//    map<int, int> mp;
//    for (int v : g[u]) {
//        if (v == fa) continue;
//        map<int, int> mpz = dfs(v, u);
//        ans = ans + mpz[a[u]];
//        for (auto& [x, cnt] : mpz) {
//            if (x < a[u]) ans = ans + cnt * mp[x];
//            mp[x] += mpz[x];
//        }
//    }
//    auto en = mp.lower_bound(a[u]);
//    if (en != mp.end()) mp.erase(en, mp.end());
//    mp[a[u]]++;
//    return mp;
//}
//
// signed main() {
//    cin >> n;
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    for (int i = 1; i < n; i++) {
//        int u, v;
//        cin >> u >> v;
//        g[u].emplace_back(v);
//        g[v].emplace_back(u);
//    }
//    dfs(1, 0);
//    cout << ans * 2 << endl;
//    return 0;
//}

// 092. https://codeforces.com/contest/2063/problem/C
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 2e5 + 10;
//
// vector<int> g[N];
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        for (int i = 1; i <= n; i++) g[i].clear();
//        for (int i = 1; i < n; i++) {
//            int u, v;
//            cin >> u >> v;
//            g[u].emplace_back(v);
//            g[v].emplace_back(u);
//        }
//        multiset<int> s;
//        for (int i = 1; i <= n; i++) s.insert(g[i].size());
//        int ans = 0;
//        for (int i = 1; i <= n; i++) {
//            s.erase(s.find(g[i].size()));
//            for (int j : g[i]) {
//                s.erase(s.find(g[j].size()));
//                s.insert(g[j].size() - 1);
//            }
//            ans = max(ans, (int)g[i].size() + *s.rbegin() - 1);
//            for (int j : g[i]) {
//                s.erase(s.find(g[j].size() - 1));
//                s.insert(g[j].size());
//            }
//            s.insert(g[i].size());
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 093. https://codeforces.com/problemset/problem/1221/D
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 3e5 + 10;
// #define int long long
//
// int a[N], b[N];
// vector<vector<int>> dp;
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
//        dp.assign(n + 1, vector<int>(3, (int)2e18));
//        dp[1][0] = 0, dp[1][1] = b[1], dp[1][2] = 2 * b[1];
//        for (int i = 2; i <= n; i++) {
//            for (int j = 0; j <= 2; j++) {
//                for (int k = 0; k <= 2; k++) {
//                    if (a[i] + j != a[i - 1] + k) {
//                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + j * b[i]);
//                    }
//                }
//            }
//        }
//        int ans = min(dp[n][0], dp[n][1]);
//        ans = min(ans, dp[n][2]);
//        cout << ans << endl;
//    }
//    return 0;
//}

// 094. P1106 删数问题
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    string s;
//    cin >> s;
//    int k;
//    cin >> k;
//    stack<char> st;
//    for (char c : s) {
//        if (st.empty()) {
//            st.push(c);
//        } else {
//            while (!st.empty() && (st.top() > c && k > 0)) {
//                st.pop();
//                k--;
//            }
//            st.push(c);
//        }
//    }
//    while (k > 0) {
//        st.pop();
//        k--;
//    }
//    string ans;
//    while (!st.empty()) {
//        ans += st.top();
//        st.pop();
//    }
//    while (ans.size() > 1 && ans.back() == '0') ans.pop_back();
//    reverse(ans.begin(), ans.end());
//    cout << ans << endl;
//    return 0;
//}

// 095. P3803 【模板】多项式乘法（FFT）
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 4e6 + 10;
// const double PI = acos(-1);
// complex<double> a[N], b[N];
//
// void FFT(complex<double> A[], int n, int op) {
//    if (n == 1) return;
//    complex<double> A1[n / 2], A2[n / 2];
//    for (int i = 0; i < n / 2; i++)
//        A1[i] = A[2 * i], A2[i] = A[2 * i + 1];
//    FFT(A1, n / 2, op), FFT(A2, n / 2, op);
//    complex<double> w1(cos(2 * PI / n), sin(2 * PI / n) * op);
//    complex<double> wk(1, 0);
//    for (int i = 0; i < n / 2; i++) {
//        A[i] = A1[i] + A2[i] * wk;
//        A[i + n / 2] = A1[i] - A2[i] * wk;
//        wk = wk * w1;
//    }
//}
//
// signed main() {
//    int n, m;
//    cin >> n >> m;
//    for (int i = 0; i <= n; i++) cin >> a[i];
//    for (int j = 0; j <= m; j++) cin >> b[j];
//    for (m = n + m, n = 1; n <= m; n <<= 1);
//    FFT(a, n, 1), FFT(b, n, 1);
//    for (int i = 0; i < n; i++) a[i] = a[i] * b[i];
//    FFT(a, n, -1);
//    for (int i = 0; i <= m; i++) {
//        cout << (int)(a[i].real() / n + 0.5) << ' ';
//    }
//    return 0;
//}
//
// 096. P1919 【模板】高精度乘法 | A*B Problem 升级版
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 4e6 + 10;
// const double PI = acos(-1);
// complex<double> a[N], b[N];
// int ans[N];
//
// void FFT(complex<double> A[], int n, int op) {
//    if (n == 1) return;
//    complex<double> A1[n / 2], A2[n / 2];
//    for (int i = 0; i < n / 2; i++)
//        A1[i] = A[i * 2], A2[i] = A[i * 2 + 1];
//    FFT(A1, n / 2, op), FFT(A2, n / 2, op);
//    complex<double> w(cos(2 * PI / n), sin(2 * PI / n) * op);
//    complex<double> wk(1, 0);
//    for (int i = 0; i < n / 2; i++) {
//        A[i] = A1[i] + A2[i] * wk;
//        A[i + n / 2] = A1[i] - A2[i] * wk;
//        wk = wk * w;
//    }
//}
//
// signed main() {
//    string s1, s2;
//    cin >> s1 >> s2;
//    int n = s1.size() - 1, m = s2.size() - 1;
//    for (int i = s1.size() - 1, k = 0; i >= 0; i--, k++) a[k] = s1[i] - '0';
//    for (int i = s2.size() - 1, k = 0; i >= 0; i--, k++) b[k] = s2[i] - '0';
//    for (m = n + m, n = 1; n <= m; n <<= 1);
//    FFT(a, n, 1), FFT(b, n, 1);
//    for (int i = 0; i < n; i++) a[i] = a[i] * b[i];
//    FFT(a, n, -1);
//    int t = 0, k = 0;
//    for (int i = 0; i < n || t; i++) {
//        t += (int)(a[i].real() / n + 0.5);
//        ans[k++] = t % 10;
//        t /= 10;
//    }
//    while (k > 1 && ans[k - 1] == 0) k--;
//    for (int i = k - 1; i >= 0; i--) cout << ans[i];
//    return 0;
//}

// 097. P2261 [CQOI2007] 余数求和
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// signed main() {
//    int n, k;
//    cin >> n >> k;
//    int ans = n * k;
//    for (int l = 1, r; l <= n; l = r + 1) {
//        int t = k / l;
//        if (t == 0) r = n;
//        else r = min(k / t, n);
//        ans -= t * (r - l + 1) * (l + r) / 2;
//    }
//    cout << ans << endl;
//    return 0;
//}

// 098. P2303 [SDOI2012] Longge 的问题
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// int phi(int n) {
//    int res = n;
//    for(int i = 2; i * i <= n; i++) {
//        if(n % i == 0) res = res / i * (i - 1);
//        while(n % i == 0) n /= i;
//    }
//    if(n > 1) res = res / n * (n - 1);
//    return res;
//}
//
// signed main() {
//    int n;
//    cin >> n;
//    int ans = 0;
//    for (int i = 1; i * i <= n; i++) {
//        if (n % i == 0) {
//            ans += i * phi(n / i);
//            int x = n / i;
//            if (x != i) ans += x * phi(n / x);
//        }
//    }
//    cout << ans << endl;
//    return 0;
//}

// 099. P2513 [HAOI2009] 逆序对数列
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int n, k;
//    cin >> n >> k;
//    vector<vector<int>> dp(n + 1, vector<int>(k + 1));
//    dp[1][0] = 1;
//    for (int i = 2; i <= n; i++) {
//        for (int j = 0; j <= k; j++) {
//            int to = max(j - i + 1, 0);
//            for (int z = j; z >= to; z--) {
//                dp[i][j] = (dp[i][j] + dp[i - 1][z]) % 10000;
//            }
//        }
//    }
//    cout << dp[n][k] % 10000 << endl;
//    return 0;
//}

// 100. P3572 [POI 2014] PTA-Little Bird
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e6 + 2;
//
// int a[N], q[N], dp[N];
//
// signed main() {
//    int n;
//    cin >> n;
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    int t;
//    cin >> t;
//    while (t--) {
//        int k;
//        cin >> k;
//        int head = 1, tail = 1;
//        q[tail] = 1;
//        for (int i = 2; i <= n; i++) {
//            while (head <= tail && i - q[head] > k) head++;
//            if (a[q[head]] > a[i]) dp[i] = dp[q[head]];
//            else dp[i] = dp[q[head]] + 1;
//            while (head <= tail && (dp[q[tail]] > dp[i] || (dp[q[tail]] == dp[i] && a[q[tail]] <= a[i]))) tail--;
//            q[++tail] = i;
//        }
//        cout << dp[n] << endl;
//    }
//    return 0;
//}

// 101. CF632D Longest Subsequence
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int n, m;
//    cin >> n >> m;
//    vector<int> a(n);
//    for (int i = 0; i < n; i++) cin >> a[i];
//    vector<int> b(a.begin(), a.end());
//    unordered_map<int, int> cnt;
//    for (int i : a) if (i <= m) cnt[i]++;
//    sort(b.begin(), b.end());
//    b.erase(unique(b.begin(), b.end()), b.end());
//    vector<int> ans(m + 1);
//    for (int i : b) {
//        if (i <= m) {
//            for (int j = i; j <= m; j += i) ans[j] += cnt[i];
//        } else break;
//    }
//    int l = 1, num = 0;
//    for (int i = 1; i <= m; i++) {
//        if (ans[i] > num) {
//            num = ans[i];
//            l = i;
//        }
//    }
//    cout << l << ' ' << num << endl;
//    for (int i = 0; i < n; i++) {
//        if (l % a[i] == 0) {
//            cout << i + 1 << ' ';
//        }
//    }
//    cout << endl;
//    return 0;
//}

// 102. CF687B Remainders Game
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define endl '\n'
//
// signed main() {
//    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
//    int n, k;
//    cin >> n >> k;
//    vector<int> a(n + 1);
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    int p = a[1];
//    for (int i = 2; i <= n; i++) {
//        p = lcm(p, a[i]) % k;
//    }
//    if (p % k == 0) cout << "Yes" << endl;
//    else cout << "No" << endl;
//    return 0;
//}

// 103. P2613 【模板】有理数取余
// #include <bits/stdc++.h>
// using namespace std;
// const int mod = 19260817;
//
// signed main() {
//    string a_, b_;
//    cin >> a_ >> b_;
//    int a = 0, b = 0;
//    for (char c : a_) {
//        a = 10LL * a + c - '0';
//        a = a % mod;
//    }
//    for (char c : b_) {
//        b = 10LL * b + c - '0';
//        b = b % mod;
//    }
//    if (b == 0) {
//        cout << "Angry!" << endl;
//        return 0;
//    }
//    int k = mod - 2, res = 1;
//    while (k) {
//        if (k & 1) res = 1LL * res * b % mod;
//        b = 1LL * b * b % mod;
//        k >>= 1;
//    }
//    cout << 1LL * a * res % mod << endl;
//    return 0;
//}

// 104. P6583 回首过去
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// signed main() {
//    int n;
//    cin >> n;
//    vector<int> mi;
//    mi.push_back(-1);
//    for (int i = 1; i <= n; i *= 2) {
//        for (int j = 1; i * j <= n; j *= 5) {
//            mi.push_back(i * j);
//        }
//    }
//    sort(mi.begin() + 1, mi.end());
//    int a = mi.size() - 1;
//    int ans = 0;
//    for (int l = 1, r = 0; l <= n; l = r + 1) {
//        int t = n / l;
//        if (t == 0) r = n;
//        else r = n / t;
//        while (a && mi[a] > t) a--;
//        int you = r - l + 1;
//        you -= r / 2 - (l - 1) / 2;
//        you -= r / 5 - (l - 1) / 5;
//        you += r / 10 - (l - 1) / 10;
//        ans += a * you * t;
//    }
//    cout << ans << endl;
//    return 0;
//}

// 105. P4310 绝世好题
// #include<bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int n;
//    cin >> n;
//    vector<int> a(n + 1);
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    set<pair<int, int>> s;
//    s.insert({1, a[1]});
//    for (int i = 2; i <= n; i++) {
//        int x = a[i];
//        int dang = 0;
//        for (auto p = s.rbegin(); p != s.rend(); p++) {
//            int dp = p->first, y = p->second;
//            if ((x & y) != 0) {
//                dang = dp + 1;
//                break;
//            }
//        }
//        if (dang) s.insert({dang, a[i]});
//        else s.insert({1, a[i]});
//    }
//    cout << s.rbegin()->first << endl;
//    return 0;
//}

// 106. P4933 大师
// #include <bits/stdc++.h>
// using namespace std;
// const int mod = 998244353;
//
// signed main() {
//    int n;
//    cin >> n;
//    vector<int> a(n + 1);
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    unordered_map<int, unordered_map<int, int>> dp(n + 1);
//    int ans = n;
//    for (int i = 1; i <= n; i++) {
//        for (int j = i - 1; j; j--) {
//            dp[i][a[i] - a[j]] += dp[j][a[i] - a[j]] + 1;
//            dp[i][a[i] - a[j]] %= mod;
//            ans += dp[j][a[i] - a[j]] + 1;
//            ans %= mod;
//        }
//    }
//    cout << ans << endl;
//    return 0;
//}

// 107. P1435 [IOI 2000] 回文字串
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    string s;
//    cin >> s;
//    int n = s.size();
//    s = ' ' + s;
//    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
//    for (int i = 2; i <= n; i++) {
//        for (int j = 1; j + i - 1 <= n; j++) {
//            dp[j][i] = min(dp[j][i - 1] + 1, dp[j + 1][i - 1] + 1);
//            dp[j][i] = min(dp[j + 1][i - 2] + 2 * (s[j] != s[j + i - 1]), dp[j][i]);
//        }
//    }
//    cout << dp[1][n] << endl;
//    return 0;
//}

// 108. CF607B Zuma
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int n;
//    cin >> n;
//    vector<int> a(n + 1);
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1e9));
//    for (int i = 1; i <= n; i++) dp[i][1] = 1;
//    for (int i = 1; i < n; i++) {
//        if (a[i] == a[i + 1]) dp[i][2] = 1;
//        else dp[i][2] = 2;
//    }
//    for (int j = 3; j <= n; j++) {
//        for (int i = 1; i + j - 1 <= n; i++) {
//            if (a[i] == a[i + j - 1]) dp[i][j] = dp[i + 1][j - 2];
//            for (int k = i + 1; k <= i + j - 1; k++) {
//                dp[i][j] = min(dp[i][j], dp[i][k - i] + dp[k][i + j - k]);
//            }
//        }
//    }
//    cout << dp[1][n] << endl;
//    return 0;
//}

// 109. https://codeforces.com/problemset/problem/2120/D
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1e5 + 10;
// const int mod = 1e9 + 7;
//
// int infact[N];
//
// int qmi(int a, int k, int p) {
//	int res = 1;
//	a %= p;
//	while (k) {
//		if (k & 1) res = res * a % p;
//		k >>= 1;
//		a = a * a % p;
//	}
//	return res;
//}
//
// void init() {
//	infact[0] = 1;
//	for (int i = 1; i < N; i++) {
//		infact[i] = infact[i - 1] * qmi(i, mod - 2, mod) % mod;
//	}
//}
//
// int C(int n, int m) {
//    int res = 1;
//    for (int i = n - m + 1; i <= n; i++)
//        res = (i % mod) * res % mod;
//    res = res * infact[m] % mod;
//    return res;
//}
//
// signed main() {
//    init();
//    int t;
//    cin >> t;
//    while (t--) {
//        int a, b, k;
//        cin >> a >> b >> k;
//        int n = (a - 1) * k + 1;
//        int m = (((b - 1) * k % mod) * C(n, a) + 1) % mod;
//        cout << n % mod << ' ' << m << endl;
//    }
//    return 0;
//}

// 110. P2015 二叉苹果树
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 110;
//
// vector<pair<int, int>> g[N];
// int n, q, dp[N][N];
//
// void dfs(int u, int fa, int tw) {
//    for (int i = 1; i <= q; i++) dp[u][i] = tw;
//    for (auto & [v, w] : g[u]) {
//        if (v == fa) continue;
//        dfs(v, u, w);
//        for (int j = q; j >= 1; j--) {
//            for (int k = 0; k <= j - 1; k++) {
//                dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[v][k]);
//            }
//        }
//    }
//}
//
// signed main() {
//    cin >> n >> q;
//    q++;
//    for (int i = 1; i < n; i++) {
//        int u, v, w;
//        cin >> u >> v >> w;
//        g[u].emplace_back(v, w);
//        g[v].emplace_back(u, w);
//    }
//    dfs(1, 0, 0);
//    cout << dp[1][q] << endl;
//    return 0;
//}

// 111. P12835 [蓝桥杯 2025 国 B] 蓝桥星数字
// 这个是别人的代码，太难写了！
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// int x;
// string s;
// int dp[22][2][3];
//
// int dfs(int u, int lst, int cnt, bool limit, bool lead0) {
//    if(u == s.size()) {
//        if(!lead0 && cnt > 1) {
//            return 1;
//        }
//        return 0;
//    }
//    if(!lead0 && !limit && dp[u][lst][cnt] != -1) {
//        return dp[u][lst][cnt];
//    }
//
//    int ans = 0;
//    int up = (limit ? s[u] - '0' : 9);
//    for(int i = 0; i <= up; i++) {
//        int now = i & 1;
//        if(lst == -1 || (now ^ lst)) {
//            if(lead0 && (i == 0)) {
//                ans += dfs(u + 1, -1, cnt, limit & (i == up), 1);
//            } else {
//                ans += dfs(u + 1, now, min(2LL, cnt + 1), limit & (i == up), lead0 & (i == 0));
//            }
//        }
//    }
//
//    return dp[u][lst][cnt] = ans;
//}
//
// bool check(int mid) {
//    s = to_string(mid);
//    memset(dp, -1, sizeof dp);
//    return dfs(0, -1, 0, 1, 1) >= x;
//}
//
// signed main() {
//    cin >> x;
//    int l = 10, r = 1e18;
//    while (l <= r) {
//        int mid = (l + r) >> 1;
//        if (check(mid)) r = mid - 1;
//        else l = mid + 1;
//    }
//    cout << r + 1 << endl;
//    return 0;
//}

// 2025.7.18 VP Codeforces Round 1006 (Div. 3)
// 112. A
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, k, p;
//        cin >> n >> k >> p;
//        if (k > n * p || k < -1 * n * p) cout << -1 << endl;
//        else {
//            k = abs(k);
//            cout << (k + p - 1) / p << endl;
//        }
//    }
//    return 0;
//}

// 113. B
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        string s;
//        cin >> n >> s;
//        int a = 0, b = 0;
//        for (char c : s) {
//            a += (c == '-');
//            b += (c == '_');
//        }
//        int x, y;
//        if (a % 2 == 0) x = y = a / 2;
//        else x = a / 2, y = x + 1;
//        cout << x * y * b << endl;
//    }
//    return 0;
//}

// 114. C
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, x;
//        cin >> n >> x;
//        if (n == 1) cout << x << endl;
//        else {
//            int wei = 0;
//            while ((x >> wei) & 1) wei++;
//            int y = (1LL << wei) - 1;
//            n -= 2;
//            int shu = min(n, y);
//            int dang = 0;
//            for (int i = 0; i <= shu; i++) {
//                dang = dang | i;
//                cout << i << ' ';
//            }
//            n = n + 2 - (shu + 1);
//            if (dang == x || (dang | (shu + 1)) == x) {
//                for (int i = 1 + shu; i <= n + shu; i++) {
//                    if ((dang | i) <= x) cout << i << ' ';
//                    else cout << x << ' ';
//                }
//            } else {
//                for (int i = 1; i <= n; i++) cout << x << ' ';
//            }
//            cout << endl;
//        }
//    }
//    return 0;
//}

// 115. D
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        int l = 1, r = 1;
//        int ans = 0;
//        for (int i = 1; i <= n; i++) {
//            int temp = 0;
//            for (int j = i + 1; j <= n; j++) {
//                if (a[i] > a[j]) temp++;
//                else if (a[i] < a[j]) temp--;
//                if (temp > ans) {
//                    ans = temp;
//                    l = i, r = j;
//                }
//            }
//        }
//        cout << l << ' ' << r << endl;
//    }
//    return 0;
//}

// 116. E
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// int f(int x) {
//    return x * (x - 1) / 2;
//}
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int k;
//        cin >> k;
//        if (k == 0) {
//            cout << 0 << endl;
//            continue;
//        }
//        int x = 1, y = 1;
//        vector<pair<int, int>> ans;
//        while (k) {
//            int l = 2, r = 500;
//            while (l <= r) {
//                int mid = (l + r) >> 1;
//                if (f(mid) <= k) l = mid + 1;
//                else r = mid - 1;
//            }
//            int n = l - 1;
//            k -= f(n);
//            for (int i = 1; i <= n; i++) {
//                ans.emplace_back(x, y);
//                y++;
//            }
//            x++;
//        }
//        cout << ans.size() << endl;
//        for (auto & [f, s] : ans) {
//            cout << f << ' ' << s << endl;
//        }
//
//    }
//    return 0;
//}

// 117. F
// #include <bits/stdc++.h>
// using namespace std;
//
// void print(int n, int k) {
//    if (n == 1) cout << k << ' ';
//    else if (n == 2) cout << k << ' ' << k << ' ';
//    else if (n == 3) cout << k << ' ' << 0 << ' ' << k << ' ';
//    else if (n == 4) for (int i = 1; i <= 4; i++) cout << k << ' ';
//    else {
//        if ((n & (n - 1)) == 0) {
//            for (int i = 1; i <= n; i++) cout << k << ' ';
//            return;
//        }
//        int wei = 2;
//        while ((1LL << wei) < n) wei++;
//        wei--;
//        int n_ = n - (1LL << wei);
//        print(n_, k);
//        int to = n - 2 * n_;
//        for (int i = 1; i <= to; i++) cout << 0 << ' ';
//        print(n_, k);
//    }
//}
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, k;
//        cin >> n >> k;
//        print(n, k);
//        cout << endl;
//    }
//    return 0;
//}

// 118. G
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int mod = 1e9 + 7;
//
// int p2[300010];
// void init() {
//    p2[1] = 1;
//    for (int i = 2; i < 300010; i++) {
//        p2[i] = (i * i % mod + p2[i - 1]) % mod;
//    }
//}
//
// signed main() {
//    init();
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, k;
//        cin >> n >> k;
//        int q = (int)sqrt(n);
//        int ans = 0;
//        for (int i = 2; i <= min(q, k); i++) {
//            int t = 0, x = n;
//            while (x) {
//                t = t * i % mod + x % i;
//                x /= i;
//            }
//            ans = (ans + t) % mod;
//        }
//        if (k > q) {
//            for (int l = q + 1, r = 0; l <= min(n, k); l = r + 1) {
//                int t = n / l;
//                r = (t == 0 ? min(n, k) : min(n / t, k));
//                ans = ((l + r) * (r - l + 1) / 2 % mod * n % mod + ans) % mod;
//                ans = ((ans - (p2[r] - p2[l - 1]) * t % mod) % mod + mod) % mod;
//                ans = (ans + (r - l + 1) * t % mod) % mod;
//            }
//        }
//        if (k > n) {
//            ans = ((k - n) % mod * n % mod + ans) % mod;
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 119. P5076 【深基16.例7】普通二叉树（简化版）
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int T;
//    cin >> T;
//    vector<int> a;
//    while (T--) {
//        int op, x;
//        cin >> op >> x;
//        if (op == 1) {
//            int ans = lower_bound(a.begin(), a.end(), x - 1) - a.begin() + 1;
//            cout << ans << endl;
//        } else if (op == 2) {
//            cout << a[x - 1] << endl;
//        } else if (op == 3) {
//            auto p = lower_bound(a.begin(), a.end(), x);
//            if (p == a.begin()) cout << "-2147483647" << endl;
//            else cout << *(p - 1) << endl;
//        } else if (op == 4) {
//            auto p = upper_bound(a.begin(), a.end(), x);
//            if (p == a.end()) cout << "2147483647" << endl;
//            else cout << *p << endl;
//        } else {
//            if (a.empty()) a.insert(a.begin(), x);
//            else {
//                auto p = lower_bound(a.begin(), a.end(), x);
//                a.insert(p, x);
//            }
//        }
//    }
//    return 0;
//}

// 120. P1892 [BalticOI 2003] 团伙
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1010;
//
// vector<int> a(N);
//
// int find(int x) {
//    if (x != a[x]) a[x] = find(a[x]);
//    return a[x];
//}
//
// signed main() {
//    int n, m;
//    cin >> n >> m;
//    vector<int> diren(n + 1, -1);
//    iota(a.begin(), a.end(), 0);
//    while (m--) {
//        char c;
//        int p, q;
//        cin >> c >> p >> q;
//        if (c == 'E') {
//            if (diren[p] == -1) diren[p] = q;
//            else a[find(q)] = find(diren[p]);
//            if (diren[q] == -1) diren[q] = p;
//            else a[find(p)] = find(diren[q]);
//        } else {
//            a[find(p)] = find(q);
//        }
//    }
//    int ans = 0;
//    for (int i = 1; i <= n; i++) ans += (a[i] == i);
//    cout << ans << endl;
//    return 0;
//}

// 121. P1072 [NOIP 2009 提高组] Hankson 的趣味题
// 有更简单得多的方法，哈哈哈哈哈，我这方法太笨了
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// set<int> s;
// unordered_map<int, int> fenjie(int x) {
//    unordered_map<int, int> res;
//    for (int i = 2; i * i <= x; i++) {
//        if (x % i == 0) {
//            while (x % i == 0) {
//                res[i]++;
//                x /= i;
//            }
//            s.insert(i);
//        }
//    }
//    if (x > 1) {
//        res[x]++;
//        s.insert(x);
//    }
//    return res;
//}
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int a0, a1, b0, b1;
//        cin >> a0 >> a1 >> b0 >> b1;
//        unordered_map<int, int> mpa0 = fenjie(a0);
//        unordered_map<int, int> mpa1 = fenjie(a1);
//        unordered_map<int, pair<int, int>> a;
//        for (auto & [p, cnt] : mpa0) {
//            if (cnt == mpa1[p]) a[p] = {cnt, INT32_MAX};
//            else a[p] = {min(cnt, mpa1[p]), min(cnt, mpa1[p])};
//        }
//        unordered_map<int, int> mpb1 = fenjie(b1);
//        unordered_map<int, int> mpb0 = fenjie(b0);
//        unordered_map<int, pair<int, int>> b;
//        for (auto & [p, cnt] : mpb1) {
//            if (mpb0[p] == cnt) b[p] = {0LL, cnt};
//            else b[p] = {cnt, cnt};
//        }
//        int ans = 1;
//        for (int i : s) {
//            if (a.find(i) == a.end()) {
//                ans = ans * (b[i].second - b[i].first + 1);
//            } else {
//                int l = a[i].first, r = a[i].second;
//                if (l > b[i].second || r < b[i].first) {
//                    ans = 0;
//                    break;
//                } else {
//                    l = max(l, b[i].first);
//                    r = min(r, b[i].second);
//                    ans *= (r - l + 1);
//                }
//            }
//        }
//        cout << ans << endl;
//        s.clear();
//    }
//    return 0;
//}

// 2025.7.19 VP Codeforces Round 1037 (Div. 3)
// 122. A
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        string s;
//        cin >> s;
//        int ans = 9;
//        for (char c : s) {
//            ans = min(ans, c - '0');
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 123. B
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        int n, k;
//        cin >> n >> k;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        int ans = 0;
//        for (int i = 1; i <= n; i++) {
//            if (a[i] == 0) {
//                int temp = 1;
//                int j = i;
//                for (; j <= i + k - 1 && j <= n; j++) {
//                    if (a[j] != 0) {
//                        temp = 0;
//                        break;
//                    }
//                }
//                if (j == n + 1 && j != i + k) temp = 0;
//                ans += temp;
//                i = j;
//            }
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 124. C
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        int n, k;
//        cin >> n >> k;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        int h = a[k];
//        sort(a.begin() + 1, a.end());
//        a.erase(unique(a.begin() + 1, a.end()), a.end());
//        int pos = lower_bound(a.begin() + 1, a.end(), h) - a.begin();
//        bool have_ans = true;
//        int shui = 0;
//        for (int i = pos; i <= a.size() - 2; i++) {
//            if (a[i] < shui + abs(a[i] - a[i + 1])) {
//                have_ans = false;
//                break;
//            } else {
//                shui += abs(a[i] - a[i + 1]);
//            }
//        }
//        if (have_ans) cout << "YES" << endl;
//        else cout << "NO" << endl;
//    }
//    return 0;
//}

// 125. D
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, k;
//        cin >> n >> k;
//        vector<int> l(n), r(n), real(n);
//        for (int i = 0; i < n; i++) cin >> l[i] >> r[i] >> real[i];
//        vector<int> a(n);
//        iota(a.begin(), a.end(), 0);
//        sort(a.begin(), a.end(), [&](int a, int b) {
//            return real[a] < real[b];
//        });
//        for (int i : a) {
//            if (l[i] <= k && k <= r[i]) k = max(k, real[i]);
//        }
//        cout << k << endl;
//    }
//    return 0;
//}

// 126. E
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 2), b(n + 2);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        for (int i = 1; i <= n; i++) cin >> b[i];
//        bool yes = true;
//        for (int i = 1; i <= n - 1; i++) {
//            if (a[i] % a[i + 1] != 0) {
//                yes = false;
//                break;
//            }
//        }
//        for (int i = n; i >= 2; i--) {
//            if (b[i] % b[i - 1] != 0) {
//                yes = false;
//                break;
//            }
//        }
//
//        for (int i = 0; i <= n; i++) {
//            if (gcd(a[i], b[i + 1]) != b[1]) {
//                yes = false;
//                break;
//            }
//        }
//        if (yes) cout << "YES" << endl;
//        else cout << "NO" << endl;
//    }
//    return 0;
//}

// 127. F
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 2e5 + 10;
// #define int long long
//
// vector<pair<int, int>> g[N];
// map<int, int> yan[N];
// int col[N], w[N], fa[N], sum;
//
// void dfs(int u, int f) {
//    fa[u] = f;
//    for (auto & [v, c] : g[u]) {
//        if (v == f) continue;
//        w[v] = c;
//        yan[u][col[v]] += c;
//        if (col[u] != col[v]) sum += c;
//        dfs(v, u);
//    }
//}
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, q;
//        cin >> n >> q;
//        for (int i = 1; i <= n; i++) {
//            g[i].clear();
//            yan[i].clear();
//        }
//        sum = 0;
//        for (int i = 1; i <= n; i++) cin >> col[i];
//        for (int i = 1; i < n; i++) {
//            int u, v, c;
//            cin >> u >> v >> c;
//            g[u].emplace_back(v, c);
//            g[v].emplace_back(u, c);
//        }
//        dfs(1, 0);
//        while (q--) {
//            int v, x;
//            cin >> v >> x;
//            if (x == col[v]) {
//                cout << sum << endl;
//                continue;
//            }
//            sum = sum + yan[v][col[v]] - yan[v][x];
//            if (v != 1) {
//                if (col[v] == col[fa[v]]) sum += w[v];
//                if (x == col[fa[v]]) sum -= w[v];
//                yan[fa[v]][x] += w[v];
//                yan[fa[v]][col[v]] -= w[v];
//            }
//            col[v] = x;
//            cout << sum << endl;
//        }
//    }
//    return 0;
//}

// VP 牛客周赛 Round 100
// 128. A
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int n;
//    cin >> n;
//    vector<int> a(2 * n + 1);
//    int cnt = 1;
//    for (int i = 1; i <= 2 * n; i += 2) {
//        a[i] = a[i + 1] = cnt;
//        cnt++;
//    }
//    for (int i = 1; i <= 2 * n; i++) cout << a[i] << ' ';
//    return 0;
//}

// 129. B
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int n;
//    cin >> n;
//    n = n * 2;
//    vector<int> a(n + 1);
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    vector<int> vis(n + 1), vis_pos(n + 1);
//    vector<int> ans;
//    for (int i = 1; i <= n; i++) {
//        if (!vis[a[i]]) {
//            vis[a[i]] = 1;
//            vis_pos[i] = 1;
//            ans.push_back(a[i]);
//        }
//    }
//    for (int i : ans) cout << i << ' ';
//    cout << endl;
//    for (int i = 1; i <= n; i++) {
//        if (!vis_pos[i]) {
//            cout << a[i] << ' ';
//        }
//    }
//    return 0;
//}

// 130. C
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        n *= 2;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        bool ans = false;
//        for (int i = 1; i <= n; i++) {
//            if (a[i] == a[n]) {
//                ans = true;
//                break;
//            } else {
//                int j = i + 1;
//                bool no = false;
//                while (j <= n && a[i] != a[j]) {
//                    if (a[j] == a[n]) no = true;
//                    j++;
//                }
//                if (no) break;
//                i = j;
//            }
//        }
//        if (ans) cout << "Yes" << endl;
//        else cout << "No" << endl;
//    }
//    return 0;
//}

// 131. F
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int mod = 1e9 + 7;
//
// int ksm(int a, int k, int p) {
//    int res = 1;
//    a %= p;
//    while (k) {
//        if (k & 1) res = res * a % p;
//        k >>= 1;
//        a = a * a % p;
//    }
//    return res;
//}
//
// signed main() {
//    int n;
//    cin >> n;
//    n = n * 2;
//    vector<int> a(n + 1);
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    int ans = 0;
//    int cnt = 1;
//    sort(a.begin() + 1, a.end());
//    for (int i = 1; i <= n; i += 2, cnt++) {
//        ans = (ans + cnt * 100 * ksm(a[i], mod - 2, mod) % mod) % mod;
//        ans = (ans + cnt * 100 * ksm(a[i + 1], mod - 2, mod) % mod) % mod;
//    }
//    cout << ans << endl;
//    return 0;
//}

// 132. P3601 签到题
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1e6 + 10, mod = 666623333;
//
// int primes[N], cnt, vis[N], phi[N], A[N], l, r;
//
// void euler() {
//    for (int i = 2; i < N; i++) {
//        if (!vis[i]) primes[cnt++] = i;
//        for (int j = 0; i * primes[j] < N; j++) {
//            vis[i * primes[j]] = 1;
//            if (i % primes[j] == 0) break;
//        }
//    }
//}
//
// void work() {
//    for (int i = 0; i < cnt && primes[i] * primes[i] <= r; i++) {
//        int p = primes[i];
//        int start = (l + p - 1) / p * p;
//        for (int j = start; j <= r; j += p) {
//            phi[j - l] = phi[j - l] / p * (p - 1);
//            while (A[j - l] % p == 0) A[j - l] /= p;
//        }
//    }
//    for (int i = l; i <= r; i++) {
//        if (A[i - l] > 1) phi[i - l] = phi[i - l] / A[i - l] * (A[i - l] - 1);
//    }
//}
//
// signed main() {
//    euler();
//    cin >> l >> r;
//    for (int i = l; i <= r; i++) {
//        phi[i - l] = A[i - l] = i;
//    }
//    work();
//    int ans;
//    if ((l + r) % 2 == 0) ans = (l + r) / 2 % mod * (r - l + 1) % mod;
//    else ans = (l + r) % mod * (r - l + 1) / 2 % mod;
//    for (int i = l; i <= r; i++) {
//        ans = (((ans - phi[i - l]) % mod) + mod) % mod;
//    }
//    cout << ans << endl;
//    return 0;
//}

// 133. P1390 公约数的和
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 2e6 + 10;
// using ll = long long;
//
// int primes[N], cnt, vis[N];
// ll phi[N];
//
// void euler() {
//    for (int i = 2; i < N; i++) {
//        if (!vis[i]) {
//            primes[cnt++] = i;
//            phi[i] = i - 1;
//        }
//        for (int j = 0; i * primes[j] < N; j++) {
//            vis[i * primes[j]] = 1;
//            if (i % primes[j] == 0) {
//                phi[i * primes[j]] = primes[j] * phi[i];
//                break;
//            } else {
//                phi[i * primes[j]] = phi[i] * phi[primes[j]];
//            }
//        }
//    }
//}
//
// signed main() {
//    euler();
//    int n;
//    cin >> n;
//    for (int i = 2; i <= n; i++) phi[i] += phi[i - 1];
//    ll ans = 0;
//    for (int i = 1; i <= n; i++) {
//        ans = ans + i * phi[n / i];
//    }
//    cout << ans << endl;
//    return 0;
//}

// 2025.7.20
// 134. 牛客周赛 Round 100 E
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// signed main() {
//    int n;
//    cin >> n;
//    n <<= 1;
//    vector<int> a(n + 1);
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    vector<int> dp(n + 1), pre(n + 1), sum(n + 1);
//    for (int i = 1; i <= n; i++) {
//        if (pre[a[i]] == 0) pre[a[i]] = i;
//        sum[i] = sum[i - 1] + a[i];
//    }
//    int ans = 0;
//    for (int i = 1; i <= n; i++) {
//        if (pre[a[i]] == i) dp[i] = dp[i - 1];
//        else dp[i] = max(dp[i - 1], dp[pre[a[i]] - 1] + sum[i] - sum[pre[a[i]] - 1]);
//        ans = max(ans, dp[i]);
//    }
//    cout << ans << endl;
//    return 0;
//}

// 135. P12021 面包题
// #include <bits/stdc++.h>
// using namespace std;
// const int mod = 998244353;
// #define int long long
//
// int fib[40];
// void init() {
//    fib[0] = 1, fib[1] = 2;
//    for (int i = 2; i < 40; i++)
//        fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
//}
//
// int ksm(int a, int k) {
//    int res = 1;
//    a %= mod;
//    while (k) {
//        if (k & 1) res = res * a % mod;
//        k >>= 1;
//        a = a * a % mod;
//    }
//    return res;
//}
//
// signed main() {
//    init();
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, k;
//        cin >> n >> k;
//        vector<int> a = {0};
//        int temp = n;
//        while (temp) {
//            a.emplace_back(temp - temp / k);
//            temp /= k;
//        }
//        for(int i = 1; i < a.size() - 1; i++) {
//            a[i] -= a[i+1];
//        }
//        int ans = 1;
//        for (int i = 1; i < a.size(); i++) {
//            ans = ans * ksm(fib[i], a[i]) % mod;
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 136. P10704 救赎（Redemption）
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int mod = 998244353;
// #define endl '\n'
// int a[1000010];
//
// signed main() {
//    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
//    int n, m;
//    cin >> n >> m;
//    for (int i = 0; i < n; i++) cin >> a[i];
//    sort(a, a + n);
//    int ans = 0;
//    for (int i = 0; i < n;) {
//        int temp = 0;
//        int m_ = m / a[i];
//        for (int l = 1, r = 0, *L = a, *R; l <= m_; l = r + 1, L = R) {
//            int t = m_ / l;
//            r = m_ / t;
//            R = upper_bound(L, a + n, r);
//            temp = (temp + (R - L) * t % mod) % mod;
//        }
//        do {
//            ans = (ans + temp) % mod;
//            i++;
//        } while (i < n && m / a[i] == m / a[i - 1]);
//    }
//    cout << ans << endl;
//    return 0;
//}

// 137. CF2B The least round way
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1010;
// #define endl '\n'
//
// pair<int, int> a[N][N];
// pair<int, int> dp[N][N];
// char mp2[N][N], mp5[N][N];
// pair<int, int> zero;
// bool have_zero;
//
// pair<int, int> operator+(const pair<int, int>& a, const pair<int, int>& b) {
//    return {a.first + b.first, a.second + b.second};
//}
//
// signed main() {
//    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
//    int n;
//    cin >> n;
//    int x;
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= n; j++) {
//            cin >> x;
//            if (x == 0) {
//                a[i][j] = {1e9, 1e9};
//                have_zero = true;
//                zero = {i, j};
//                continue;
//            }
//            int cnt2 = 0, cnt5 = 0;
//            while (x % 2 == 0) cnt2++, x /= 2;
//            while (x % 5 == 0) cnt5++, x /= 5;
//            a[i][j] = {cnt2, cnt5};
//        }
//    }
//    for (int i = 1; i <= n; i++) {
//        dp[1][i] = dp[1][i - 1] + a[1][i];
//        mp2[1][i] = mp5[1][i] = 'R';
//        dp[i][1] = dp[i - 1][1] + a[i][1];
//        mp2[i][1] = mp5[i][1] = 'D';
//    }
//
//    for (int i = 2; i <= n; i++) {
//        for (int j = 2; j <= n; j++) {
//            pair<int, int>& shang = dp[i - 1][j];
//            pair<int, int>& zuo = dp[i][j - 1];
//            pair<int, int>& dang = dp[i][j];
//
//
//            if (shang.first < zuo.first) {
//                dang.first = shang.first + a[i][j].first;
//                mp2[i][j] = 'D';
//            } else {
//                dang.first = zuo.first + a[i][j].first;
//                mp2[i][j] = 'R';
//            }
//
//            if (shang.second < zuo.second) {
//                dang.second = shang.second + a[i][j].second;
//                mp5[i][j] = 'D';
//            } else {
//                dang.second = zuo.second + a[i][j].second;
//                mp5[i][j] = 'R';
//            }
//        }
//    }
//    bool ans2 = false;
//    int ans = min(dp[n][n].first, dp[n][n].second);
//    if (ans >= 2 && have_zero) {
//        cout << 1 << endl;
//        for (int i = 2; i <= zero.first; i++) cout << 'D';
//        for (int i = 2; i <= zero.second; i++) cout << 'R';
//        for (int i = zero.first; i < n; i++) cout << 'D';
//        for (int i = zero.second; i < n; i++) cout << 'R';
//    } else {
//        if (dp[n][n].first < dp[n][n].second) ans2 = true;
//        cout << ans << endl;
//        string path;
//        if (ans2) {
//            int i = n, j = n;
//            while (i != 1 || j != 1) {
//                char c = mp2[i][j];
//                path += c;
//                if (c == 'R') j--;
//                else i--;
//            }
//        } else {
//            int i = n, j = n;
//            while (i != 1 || j != 1) {
//                char c = mp5[i][j];
//                path += c;
//                if (c == 'R') j--;
//                else i--;
//            }
//        }
//        reverse(path.begin(), path.end());
//        cout << path << endl;
//    }
//
//    return 0;
//}

// 138. CF3B Lorry
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int n, v;
//    cin >> n >> v;
//    vector<pair<int, int>> a1(1), a2(1);
//    for (int i = 1; i <= n; i++) {
//        int t, p;
//        cin >> t >> p;
//        if (t == 1) a1.emplace_back(p, i);
//        else a2.emplace_back(p, i);
//    }
//    int n1 = a1.size() - 1, n2 = a2.size() - 1;
//    sort(a1.begin() + 1, a1.end(), greater<>());
//    sort(a2.begin() + 1, a2.end(), greater<>());
//    vector<int> sum1(n1 + 1), sum2(n2 + 1);
//    for (int i = 1; i <= n1; i++) {
//        sum1[i] = sum1[i - 1] + a1[i].first;
//    }
//    for (int i = 1; i <= n2; i++) {
//        sum2[i] = sum2[i - 1] + a2[i].first;
//    }
//    int ans = 0, cnt1 = 0, cnt2 = 0;
//    for (int i = 0; i <= min(n1, v); i++) {
//        int j = min((v - i) / 2, n2);
//        int sum = sum1[i] + sum2[j];
//        if (sum > ans) {
//            ans = sum;
//            cnt1 = i, cnt2 = j;
//        }
//    }
//    cout << ans << endl;
//    for (int i = 1; i <= cnt1; i++) cout << a1[i].second << ' ';
//    for (int i = 1; i <= cnt2; i++) cout << a2[i].second << ' ';
//    return 0;
//}

// 139. CF6D Lizards and Basements 2
// #include <bits/stdc++.h>
// using namespace std;
//
// const int N = 15;
// int n, a, b, h[N];
// vector<int> vec, temp;
// int ans = 1e9;
//
// void dfs(int u, int cnt) {
//    if (cnt > ans) return;
//    if (u == n - 1) {
//        if (h[n - 1] < 0 && ans > cnt) {
//            ans = cnt;
//            vec = temp;
//        }
//    } else {
//        int up = max(max(h[u - 1] / b, 0) + 1, max(h[u] / a, 0) + 1);
//        if (u == n - 2) up = max(up, h[n - 1] / b + 1);
//        for (int i = 0; i <= up; i++) {
//            if (h[u - 1] - i * b < 0) {
//                h[u - 1] -= i * b;
//                h[u] -= i * a;
//                h[u + 1] -= i * b;
//                for (int j = 1; j <= i; j++) temp.emplace_back(u + 1);
//
//                dfs(u + 1, cnt + i);
//
//                h[u - 1] += i * b;
//                h[u] += i * a;
//                h[u + 1] += i * b;
//                for (int j = 1; j <= i; j++) temp.pop_back();
//            }
//        }
//    }
//}
//
// signed main() {
//    cin >> n >> a >> b;
//    for (int i = 0; i < n; i++) cin >> h[i];
//    dfs(1, 0);
//    cout << ans << endl;
//    for (int i : vec) cout << i << ' ';
//    return 0;
//}

// 140. CF7C Line
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// int exgcd(int a, int b, int& x, int& y) {
//    if (a == 0) {
//        x = 0, y = 1;
//        return b;
//    } else {
//        int d = exgcd(b % a, a, x, y);
//        swap(x, y);
//        x -= b / a * y;
//        return d;
//    }
//}
//
// signed main() {
//    int A, B, C;
//    cin >> A >> B >> C;
//    C = -C;
//    int x, y;
//    int d = exgcd(A, B, x, y);
//    if (C % d != 0) cout << -1 << endl;
//    else {
//        int k = C / d;
//        x = k * x;
//        y = k * y;
//        cout << x << ' ' << y << endl;
//    }
//    return 0;
//}

// 141. https://ac.nowcoder.com/acm/contest/113313/F   幂中幂plus
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// int ksm(int a, int k, int mod) {
//    int res = 1 % mod;
//    a %= mod;
//    while (k) {
//        if (k & 1) res = res * a % mod;
//        a = a * a % mod;
//        k >>= 1;
//    }
//    return res;
//}
//
// signed main() {
//    int b, c, mod;
//    cin >> b >> c >> mod;
//    vector<int> a(1);
//    vector<int> vis(mod + 1);
//    int c1 = ksm(b, c, mod);
//    a.emplace_back(c1);
//    vis[c1] = a.size() - 1;
//    int idx = -1;
//    while (true) {
//        int c_ = ksm(b, a.back(), mod);
//        if (vis[c_]) {
//            idx = vis[c_];
//            break;
//        } else {
//            a.emplace_back(c_);
//            vis[c_] = a.size() - 1;
//        }
//    }
//    int n = a.size() - 1;
//    vector<int> sum(n + 1);
//    for (int i = 1; i <= n; i++) sum[i] = (sum[i - 1] + a[i]) % mod;
//    int xun = ((sum[n] - sum[idx - 1]) % mod + mod) % mod;
//    int xun_len = n - idx + 1;
//    int q;
//    cin >> q;
//    while (q--) {
//        int k;
//        cin >> k;
//        if (k <= n) cout << sum[k] << endl;
//        else {
//            int ans = sum[idx - 1];
//            k = k - (idx - 1);
//            int cnt = k / xun_len % mod;
//            ans = (ans + cnt * xun) % mod;
//            cnt = k % xun_len;
//            ans = (ans + (sum[idx - 1 + cnt] - sum[idx - 1]) % mod + mod) % mod;
//            cout << ans << endl;
//        }
//    }
//    return 0;
//}

// 2025.7.21
// 142. https://codeforces.com/problemset/problem/2124/D
// #include <bits/stdc++.h>
// using namespace std;
//
// int get_max(int l1, int r1, int l2, int r2, int m, vector<int>& a) {
//    if (l1 >= r2) return 0;
//    int cnt1 = 0, cnt2 = 0;
//    for (int i = l1; i <= r1; i++) cnt1 += (a[i] == m);
//    for (int i = l2; i <= r2; i++) cnt2 += (a[i] == m);
//    if (l1 == l2) return min(cnt1, cnt2);
//    else return 2 * min(cnt1, cnt2);
//}
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, k;
//        cin >> n >> k;
//        vector<int> a(n);
//        for (int i = 0; i < n; i++) cin >> a[i];
//        vector<int> b = a;
//        sort(b.begin(), b.end());
//        int m = b[k - 1];
//        vector<int> hui_id, hui;
//        for (int i = 0; i < n; i++) {
//            if (a[i] < m) {
//                hui_id.emplace_back(i);
//                hui.emplace_back(a[i]);
//            }
//        }
//        if (hui.empty()) {
//            cout << "YES" << endl;
//            continue;
//        }
//        vector<int> hui_c(hui.rbegin(), hui.rend());
//        if (hui_c != hui) {
//            cout << "NO" << endl;
//            continue;
//        }
//        int temp = get_max(0, hui_id.front(), hui_id[hui_id.size() - 1], n - 1, m, a);
//        for (int i = 1; i < hui_id.size(); i++) {
//            temp += get_max(hui_id[i - 1], hui_id[i], hui_id[hui_id.size() - i - 1], hui_id[hui_id.size() - i], m, a);
//        }
//        if (hui.size() + temp >= k - 1) {
//            cout << "YES" << endl;
//        } else {
//            cout << "NO" << endl;
//        }
//    }
//    return 0;
//}

// 143. https://codeforces.com/problemset/problem/2121/H   H. Ice Baby
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        int n;
//        cin >> n;
//        multiset<int> s;
//        for (int i = 1; i <= n; i++) {
//            int l, r;
//            cin >> l >> r;
//            auto p = s.upper_bound(r);
//            if (p != s.end()) {
//                s.erase(p);
//            }
//            s.insert(l);
//            cout << s.size() << " \n"[i == n];
//        }
//    }
//    return 0;
//}

// 144. P3373 【模板】线段树 2
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1e5 + 10;
//
// int a[N], n, q, mod;
//
// struct Node {
//    int l, r;
//    int sum, add, mul;
//} tr[4 * N];
//
// void pushup(Node& rt, Node& le, Node& ri) {
//    rt.sum = (le.sum + ri.sum) % mod;
//}
//
// void pushdown(int u) {
//    Node& rt = tr[u], & le = tr[u << 1], & ri = tr[u << 1 | 1];
//    if (rt.mul == 1 && rt.add == 0) return;
//    le.sum = (le.sum * rt.mul % mod + rt.add * (le.r - le.l + 1) % mod) % mod;
//    le.mul = le.mul * rt.mul % mod;
//    le.add = (le.add * rt.mul + rt.add) % mod;
//
//    ri.sum = (ri.sum * rt.mul % mod + rt.add * (ri.r - ri.l + 1) % mod) % mod;
//    ri.mul = ri.mul * rt.mul % mod;
//    ri.add = (ri.add * rt.mul + rt.add) % mod;
//
//    rt.mul = 1;
//    rt.add = 0;
//}
//
// void build(int u, int l, int r) {
//    tr[u] = {l, r, 0, 0, 1};
//    if (l == r) tr[u].sum = a[l] % mod;
//    else {
//        int mid = (l + r) >> 1;
//        build(u << 1, l, mid);
//        build(u << 1 | 1, mid + 1, r);
//        pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
//    }
//}
//
// void changeMul(int u, int l, int r, int k) {
//    if (l <= tr[u].l && tr[u].r <= r) {
//        tr[u].sum = tr[u].sum * k % mod;
//        tr[u].add = tr[u].add * k % mod;
//        tr[u].mul = tr[u].mul * k % mod;
//    } else {
//        pushdown(u);
//        int mid = (tr[u].l + tr[u].r) >> 1;
//        if (r <= mid) changeMul(u << 1, l, r, k);
//        else if (l > mid) changeMul(u << 1 | 1, l, r, k);
//        else {
//            changeMul(u << 1, l, mid, k);
//            changeMul(u << 1 | 1, mid + 1, r, k);
//        }
//        pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
//    }
//}
//
// void changeAdd(int u, int l, int r, int k) {
//    if (l <= tr[u].l && tr[u].r <= r) {
//        tr[u].sum = (tr[u].sum + (tr[u].r - tr[u].l + 1) * k % mod) % mod;
//        tr[u].add = (tr[u].add + k) % mod;
//    } else {
//        pushdown(u);
//        int mid = (tr[u].l + tr[u].r) >> 1;
//        if (r <= mid) changeAdd(u << 1, l, r, k);
//        else if (l > mid) changeAdd(u << 1 | 1, l, r, k);
//        else {
//            changeAdd(u << 1, l, mid, k);
//            changeAdd(u << 1 | 1, mid + 1, r, k);
//        }
//        pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
//    }
//}
//
// int query(int u, int l, int r) {
//    if (l <= tr[u].l && tr[u].r <= r) return tr[u].sum;
//    pushdown(u);
//    int mid = (tr[u].l + tr[u].r) >> 1;
//    if (r <= mid) return query(u << 1, l, r);
//    else if (l > mid) return query(u << 1 | 1, l, r);
//    else return (query(u << 1, l, mid) + query(u << 1 | 1, mid + 1, r)) % mod;
//}
//
// signed main() {
//    cin >> n >> q >> mod;
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    build(1, 1, n);
//    while (q--) {
//        int op, x, y, k;
//        cin >> op;
//        if (op == 1) {
//            cin >> x >> y >> k;
//            changeMul(1, x, y, k);
//        } else if (op == 2) {
//            cin >> x >> y >> k;
//            changeAdd(1, x, y, k);
//        } else {
//            cin >> x >> y;
//            cout << query(1, x, y) << endl;
//        }
//    }
//    return 0;
//}

// 145. P3197 [HNOI2008] 越狱
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int mod = 100003;
//
// int ksm(int a, int k) {
//    int res = 1;
//    a %= mod;
//    while (k) {
//        if (k & 1) res = res * a % mod;
//        a = a * a % mod;
//        k >>= 1;
//    }
//    return res;
//}
//
// signed main() {
//    int m, n;
//    cin >> m >> n;
//    cout << ((ksm(m, n) - m * ksm(m - 1, n - 1) % mod) % mod + mod) % mod << endl;
//    return 0;
//}

// 146. P4551 最长异或路径
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 100010;
//
// vector<pair<int, int>> g[N];
// vector<int> a;
// int trie[35 * N][2], cnt = 1;
//
// void insert(int x) {
//    int p = 0;
//    for (int i = 31; i >= 0; i--) {
//        int wei = (x >> i) & 1;
//        if (trie[p][wei]) {
//            p = trie[p][wei];
//        } else {
//            trie[p][wei] = cnt++;
//            p = trie[p][wei];
//        }
//    }
//}
//
// int get_max(int x) {
//    int res = 0;
//    int p = 0;
//    for (int i = 31; i >= 0; i--) {
//        int wei = (x >> i) & 1;
//        if (trie[p][!wei]) {
//            res += (1 << i);
//            p = trie[p][!wei];
//        } else {
//            p = trie[p][wei];
//        }
//    }
//    return res;
//}
//
// void dfs(int u, int fa, int sum) {
//    a.push_back(sum);
//    insert(sum);
//    for (auto & [v, w] : g[u]) {
//        if (v == fa) continue;
//        dfs(v, u, sum ^ w);
//    }
//}
//
// signed main() {
//    int n;
//    cin >> n;
//    for (int i = 1; i < n; i++) {
//        int u, v, w;
//        cin >> u >> v >> w;
//        g[u].emplace_back(v, w);
//        g[v].emplace_back(u, w);
//    }
//    dfs(1, 0, 0);
//    int ans = 0;
//    for (int i : a) {
//        ans = max(ans, get_max(i));
//    }
//    cout << ans << endl;
//    return 0;
//}

// 147. B4273 [蓝桥杯青少年组省赛 2023] 最大的矩形纸片
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// signed main() {
//    int n;
//    cin >> n;
//    vector<int> a(n + 2);
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    stack<int> st;
//    st.push(0);
//    vector<int> zuo(n + 1), you(n + 1);
//    for (int i = 1; i <= n; i++) {
//        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
//        zuo[i] = st.top();
//        st.push(i);
//    }
//    while (!st.empty()) st.pop();
//    st.push(n + 1);
//    for (int i = n; i >= 1; i--) {
//        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
//        you[i] = st.top();
//        st.push(i);
//    }
//    int ans = 0;
//    for (int i = 1; i <= n; i++) {
//        ans = max(ans, (you[i] - zuo[i] - 1) * a[i]);
//    }
//    cout << ans << endl;
//    return 0;
//}

// 2025.7.22
// 148. CF2113F Two Arrays   https://www.luogu.com.cn/problem/CF2113F
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 2;
//
// int a[N], b[N], n, s, vis[N << 1], id[N];
// unordered_map<int, int> mp;
// vector<pair<int, int>> g[N << 1];
//
// void dfs(int u, int h) {
//    vis[u] = 1;
//    for (auto & [v, i] : g[u]) {
//        if (id[i] == 0) {
//            if (u == s) h++;
//            if (h == 1) id[i] = u;
//            else id[i] = v;
//            if (!vis[v]) dfs(v, h);
//        }
//    }
//}
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        cin >> n;
//        for (int i = 1; i <= n; i++) cin >> a[i], mp[a[i]]++;
//        for (int i = 1; i <= n; i++) cin >> b[i], mp[b[i]]++;
//        int ans = 0;
//        for (auto & [key, cnt] : mp) ans += min(2, cnt);
//        for (int i = 1; i <= n; i++) {
//            g[a[i]].emplace_back(b[i], i);
//            g[b[i]].emplace_back(a[i], i);
//        }
//
//        for (int i = 1; i <= 2 * n; i++) {
//            if (!vis[i] && mp[i] > 0) {
//                s = i;
//                dfs(i, 0);
//            }
//        }
//        for (int i = 1; i <= n; i++)
//            if (a[i] != id[i]) swap(a[i], b[i]);
//        cout << ans << endl;
//        for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
//        for (int i = 1; i <= n; i++) cout << b[i] << " \n"[i == n];
//
//        for (int i = 1; i <= n; i++) {
//            g[a[i]].clear();
//            g[b[i]].clear();
//            vis[a[i]] = 0;
//            vis[b[i]] = 0;
//            id[i] = 0;
//        }
//        mp.clear();
//    }
//    return 0;
//}

// 149. CF2112E Tree Colorings   https://www.luogu.com.cn/problem/CF2112E
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 5e5 + 10;
// int f[N];
//
// signed main() {
//    int t;
//    cin >> t;
//    memset(f, -1, sizeof f);
//    f[1] = 1;
//    for (int i = 3; i < N; i += 2) {
//        f[i] = 1e9;
//        for (int j = 1; j * j <= i; j++) {
//            if (i % j == 0) {
//                f[i] = min(f[i], f[i / j - 2] + f[j]);
//                int x = i / j;
//                f[i] = min(f[i], f[i / x - 2] + f[x]);
//            }
//        }
//    }
//    while (t--) {
//        int n;
//        cin >> n;
//        cout << f[n] << endl;
//    }
//    return 0;
//}

// 150. CF2112D Reachability and Tree   https://www.luogu.com.cn/problem/CF2112D
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 2e5 + 10;
//
// vector<int> g[N];
// vector<pair<int, int>> ans;
// int s;
//
// void dfs(int u, int fa, int op) {
//    if (u == s) op ^= 1;
//    for (int i : g[u]) {
//        if (i == fa) continue;
//        if (op) ans.emplace_back(u, i);
//        else ans.emplace_back(i, u);
//        dfs(i, u, op ^ 1);
//    }
//}
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        ans.clear();
//        for (int i = 1; i <= n; i++) g[i].clear();
//        for (int i = 1; i < n; i++) {
//            int u, v;
//            cin >> u >> v;
//            g[u].emplace_back(v);
//            g[v].emplace_back(u);
//        }
//        s = 1;
//        bool have_ans = false;
//        for (int i = 1; i <= n; i++) {
//            if (g[i].size() == 2) {
//                have_ans = true;
//                s = i;
//                break;
//            }
//        }
//        if (!have_ans) {
//            cout << "NO" << endl;
//            continue;
//        }
//        if (s == 1) dfs(2, 0, 0);
//        else dfs(1, 0, 0);
//        cout << "YES" << endl;
//        for (auto & [x, v] : ans) cout << x << ' ' << v << endl;
//    }
//    return 0;
//}

// 151. CF2112C Coloring Game   https://www.luogu.com.cn/problem/CF2112C
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n);
//        for (int i = 0; i < n; i++) cin >> a[i];
//        sort(a.begin(), a.end());
//        int ans = 0;
//        for (int i = n - 1; i >= 2; i--) {
//            int he = max(2 * a[i], a[n - 1]);
//            int mi = he - a[i];
//            for (int j = 0; j <= i - 2; j++) {
//                ans += (a.begin() + i) - upper_bound(a.begin() + j + 1, a.begin() + i, mi - a[j]);
//            }
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 152. CF2111E Changing the String   https://www.luogu.com.cn/problem/CF2111E
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, q;
//        cin >> n >> q;
//        string s;
//        cin >> s;
//        s = " " + s;
//        set<int> ba, bc, ca, cb;
//        for (int i = 1; i <= q; i++) {
//            string a, b;
//            cin >> a >> b;
//            string op = a + b;
//            if (op == "ba") ba.insert(i);
//            else if (op == "bc") bc.insert(i);
//            else if (op == "ca") ca.insert(i);
//            else if (op == "cb") cb.insert(i);
//        }
//        for (int i = 1; i <= n; i++) {
//            if (s[i] == 'a') continue;
//            if (s[i] == 'b') {
//                if (ba.size()) {
//                    s[i] = 'a';
//                    ba.erase(ba.begin());
//                } else {
//                    if (bc.size() && ca.size()) {
//                        int f = *bc.begin();
//                        auto x = ca.lower_bound(f);
//                        if (x != ca.end()) {
//                            s[i] = 'a';
//                            bc.erase(bc.begin());
//                            ca.erase(x);
//                        }
//                    }
//                }
//            } else if (s[i] == 'c') {
//                if (ca.size()) {
//                    s[i] = 'a';
//                    ca.erase(ca.begin());
//                } else {
//                    if (cb.size()) {
//                        int f = *cb.begin();
//                        s[i] = 'b';
//                        auto x = ba.lower_bound(f);
//                        if (x != ba.end()) {
//                            s[i] = 'a';
//                            ba.erase(x);
//                        }
//                        cb.erase(cb.begin());
//                    }
//                }
//            }
//        }
//        cout << s.substr(1, n) << endl;
//    }
//    return 0;
//}

// 153. P8687 [蓝桥杯 2019 省 A] 糖果
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int n, m, k;
//    cin >> n >> m >> k;
//    vector<int> dp(2 << m, 1e9);
//    vector<int> v(n + 1);
//    for (int i = 1; i <= n; i++) {
//        int h = 0;
//        for (int j = 1; j <= k; j++) {
//            int x;
//            cin >> x;
//            x--;
//            h = h | (1 << x);
//        }
//        v[i] = h;
//        dp[h] = 1;
//    }
//    for (int i = 0; i < (1 << m); i++) {
//        for (int j = 1; j <= n; j++) {
//            dp[i | v[j]] = min(dp[i | v[j]], dp[i] + 1);
//        }
//    }
//    cout << (dp[(1 << m) - 1] == 1e9 ? -1 : dp[(1 << m) - 1]) << endl;
//    return 0;
//}

// 154. P10031 「Cfz Round 3」Xor with Gcd
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// signed main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        int n;
//        cin >> n;
//        if (n & 1) cout << n << endl;
//        else cout << (n ^ (n / 2)) << endl;
//    }
//    return 0;
//}

// 155. P2398 GCD SUM   双倍快乐！
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 10;
// #define int long long
//
// int primes[N], vis[N], phi[N], cnt;
//
// void euler() {
//    for (int i = 2; i < N; i++) {
//        if (!vis[i]) {
//            primes[cnt++] = i;
//            phi[i] = i - 1;
//        }
//        for (int j = 0; primes[j] * i < N; j++) {
//            vis[i * primes[j]] = 1;
//            if (i % primes[j] == 0) {
//                phi[i * primes[j]] = phi[i] * primes[j];
//                break;
//            }
//            phi[i * primes[j]] = phi[i] * phi[primes[j]];
//        }
//    }
//}
//
// signed main() {
//    euler();
//    for (int i = 1; i < N; i++) phi[i] += phi[i - 1];
//    int n;
//    cin >> n;
//    int ans = 0;
//    for (int i = 1; i <= n; i++) {
//        ans += i * phi[n / i];
//    }
//    ans *= 2;
//    ans += n * (n + 1) / 2;
//    cout << ans << endl;
//    return 0;
//}

// 2025.7.23
// 156. P1403 [AHOI2005] 约数研究
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e6 + 10;
// #define int long long
//
// int a[N], primes[N], vis[N], cnt, d[N];
//
// void euler() {
//    vis[1] = 1;
//    d[1] = 1;
//    for (int i = 2; i < N; i++) {
//        if (!vis[i]) {
//            primes[cnt++] = i;
//            a[i] = 1, d[i] = 2;
//        }
//        for (int j = 0; i * primes[j] < N; j++) {
//            int m = i * primes[j];
//            vis[m] = 1;
//            if (i % primes[j] == 0) {
//                a[m] = a[i] + 1;
//                d[m] = d[i] / a[m] * (a[m] + 1);
//                break;
//            }
//            a[m] = 1;
//            d[m] = 2 * d[i];
//        }
//    }
//}
//
// signed main() {
//    euler();
//    int n;
//    cin >> n;
//    int ans = 0;
//    for (int i = 1; i <= n; i++) ans += d[i];
//    cout << ans << endl;
//    return 0;
//}

// 157. P3455 [POI 2007] ZAP-Queries
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 5e4 + 10;
// #define int long long
//
// int primes[N], cnt, vis[N], mu[N];
//
// void get_mu() {
//    mu[1] = 1;
//    for (int i = 2; i < N; i++) {
//        if (!vis[i]) {
//            primes[cnt++] = i;
//            mu[i] = -1;
//        }
//        for (int j = 0; primes[j] * i < N; j++) {
//            int m = primes[j] * i;
//            vis[m] = 1;
//            if (i % primes[j] == 0) {
//                break;
//            }
//            mu[m] = -mu[i];
//        }
//    }
//    for (int i = 1; i < N; i++) mu[i] += mu[i - 1];
//}
//
// signed main() {
//    get_mu();
//    int n;
//    cin >> n;
//    while (n--) {
//        int a, b, d;
//        cin >> a >> b >> d;
//        if (a > b) swap(a, b);
//        a = a / d, b = b / d;
//        int ans = 0;
//        for (int l = 1, r = 0; l <= a; l = r + 1) {
//            int t1 = a / l, t2 = b / l;
//            r = min(a / t1, b / t2);
//            ans = ans + t1 * t2 * (mu[r] - mu[l - 1]);
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 158. P2522 [HAOI2011] Problem b
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 5e4 + 10;
// #define int long long
//
// int primes[N], cnt, vis[N], mu[N];
//
// void get_mu() {
//    mu[1] = 1;
//    for (int i = 2; i < N; i++) {
//        if (!vis[i]) {
//            primes[cnt++] = i;
//            mu[i] = -1;
//        }
//        for (int j = 0; primes[j] * i < N; j++) {
//            int m = primes[j] * i;
//            vis[m] = 1;
//            if (i % primes[j] == 0) break;
//            mu[m] = -mu[i];
//        }
//    }
//    for (int i = 1; i < N; i++) mu[i] += mu[i - 1];
//}
//
// int calc(int a, int b, int d) {
//    if (a > b) swap(a, b);
//    a = a / d, b = b / d;
//    int ans = 0;
//    for (int l = 1, r = 0; l <= a; l = r + 1) {
//        int t1 = a / l, t2 = b / l;
//        r = min(a / t1, b / t2);
//        ans = ans + t1 * t2 * (mu[r] - mu[l - 1]);
//    }
//    return ans;
//}
//
// signed main() {
//    get_mu();
//    int n;
//    cin >> n;
//    while (n--) {
//        int a, b, c, d, k;
//        cin >> a >> b >> c >> d >> k;
//        int ans = calc(b, d, k) - calc(a - 1, d, k) - calc(b, c - 1, k) + calc(a - 1, c - 1, k);
//        cout << ans << endl;
//    }
//    return 0;
//}

// 159. P2257 YY的GCD
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e7 + 5;
// #define int long long
//
// int primes[N], cnt, vis[N], f[N], mu[N];
//
// void euler() {
//    mu[1] = 1;
//    for (int i = 2; i < N; i++) {
//        if (!vis[i]) {
//            primes[cnt++] = i;
//            mu[i] = -1;
//        }
//        for (int j = 0; primes[j] * i < N; j++) {
//            vis[primes[j] * i] = 1;
//            if (i % primes[j] == 0) break;
//            mu[i * primes[j]] = -mu[i];
//        }
//    }
//    for (int i = 0; i < cnt; i++) {
//        for (int j = 1; j * primes[i] < N; j++) {
//            f[j * primes[i]] += mu[j];
//        }
//    }
//    for (int i = 1; i < N; i++) f[i] += f[i - 1];
//}
//
// int calc(int n, int m) {
//    if (n > m) swap(n, m);
//    int ans = 0;
//    for (int l = 1, r; l <= n; l = r + 1) {
//        int t1 = n / l, t2 = m / l;
//        r = min(n / t1, m / t2);
//        ans += t1 * t2 * (f[r] - f[l - 1]);
//    }
//    return ans;
//}
//
// signed main() {
//    euler();
//    int t;
//    cin >> t;
//    while (t--) {
//        int n, m;
//        cin >> n >> m;
//        cout << calc(n, m) << endl;
//    }
//    return 0;
//}

// 160. https://codeforces.com/contest/2125/problem/C
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// vector<int> p = {2, 3, 5, 7};
//
// int get(int x) {
//    int ans = 0;
//    for (int i = 0; i < (1 << 4); i++) {
//        int f = 1;
//        int t = x;
//        for (int j = 0; j < 4; j++) {
//            if ((i >> j) & 1) {
//                f = -f;
//                t /= p[j];
//            }
//        }
//        ans += f * t;
//    }
//    return ans;
//}
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int l, r;
//        cin >> l >> r;
//        cout << get(r) - get(l - 1) << endl;
//    }
//    return 0;
//}

// 161. CF2121F Yamakasi
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, s, x;
//        cin >> n >> s >> x;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        vector<int> sum(n + 1);
//        for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
//        map<int, vector<int>> mp;
//        mp[0].emplace_back(0);
//        int ans = 0;
//        int fu = 0;
//        for (int i = 1; i <= n; i++) {
//            if (a[i] > x) {
//                mp.clear();
//                mp[sum[i]].emplace_back(i);
//                fu = 0;
//                continue;
//            }
//            if (a[i] == x) fu = i;
//            ans += (fu > 0) * (lower_bound(mp[sum[i] - s].begin(), mp[sum[i] - s].end(), fu) - mp[sum[i] - s].begin());
//            mp[sum[i]].emplace_back(i);
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 162. https://codeforces.com/problemset/problem/2113/C
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 510;
//
// char a[N][N];
// int s[N][N];
// int n, m, k;
//
// int get(int i, int j) {
//    int i_up = max(1, i - k + 1);
//    int j_up = max(1, j - k + 1);
//    int i_down = min(n, i + k - 1);
//    int j_down = min(m, j + k - 1);
//    return s[i_down][j_down] - s[i_down][j_up - 1] - s[i_up - 1][j_down] + s[i_up - 1][j_up - 1];
//}
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        cin >> n >> m >> k;
//        int cnt = 0;
//        for (int i = 1; i <= n; i++) {
//            for (int j = 1; j <= m; j++) {
//                cin >> a[i][j];
//                cnt += (a[i][j] == 'g');
//            }
//        }
//        for (int i = 1; i <= n; i++) {
//            for (int j = 1; j <= m; j++) {
//                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (a[i][j] == 'g');
//            }
//        }
//        int minn = cnt;
//        for (int i = 1; i <= n; i++) {
//            for (int j = 1; j <= m; j++) {
//                if (a[i][j] == '.') {
//                    minn = min(minn, get(i, j));
//                }
//            }
//        }
//        cout << cnt - minn << endl;
//    }
//    return 0;
//}

// 163. E. Make it Zero   https://codeforces.com/problemset/problem/2124/E
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        int mx = 0, sum = 0;
//        for (int i = 1; i <= n; i++) {
//            mx = max(mx, a[i]);
//            sum += a[i];
//        }
//        if (mx > sum - mx || sum & 1) {
//            cout << -1 << endl;
//            continue;
//        }
//        int temp = 0;
//        for (int i = 1; i <= n; i++) {
//            temp += a[i];
//            if (temp >= sum - temp) {
//                break;
//            }
//        }
//        if (temp == sum - temp) {
//            cout << 1 << endl;
//            for (int i = 1; i <= n; i++) cout << a[i] << ' ';
//            cout << endl;
//        } else {
//            cout << 2 << endl;
//            int cha = temp - sum + temp;
//            int t = cha / 2;
//            int i = 1;
//            for (; i <= n; i++) {
//                if (a[i] >= t) {
//                    cout << t << ' ';
//                    a[i] -= t;
//                    break;
//                } else {
//                    cout << a[i] << ' ';
//                    t -= a[i];
//                    a[i] = 0;
//                }
//            }
//            t = cha / 2;
//            for (i++; i <= n; i++) {
//                if (a[i] >= t) {
//                    cout << t << ' ';
//                    a[i] -= t;
//                    for (i++; i <= n; i++) cout << 0 << ' ';
//                    break;
//                } else {
//                    cout << a[i] << ' ';
//                    t -= a[i];
//                    a[i] = 0;
//                }
//            }
//            cout << endl;
//            for (int i = 1; i <= n; i++) cout << a[i] << ' ';
//            cout << endl;
//        }
//    }
//    return 0;
//}

// 2025.7.24
// 164. CF2125D Segments Covering   https://codeforces.com/contest/2125/problem/D
// #include <bits/stdc++.h>
// using namespace std;
// const int mod = 998244353, N = 2e5 + 10;
//
// vector<vector<tuple<int, int, int>>> a(N);
// vector<int> dp(N);
//
// int ksm(int a, int k) {
//    int res = 1;
//    while (k) {
//        if (k & 1) res = 1LL * res * a % mod;
//        a = 1LL * a * a % mod;
//        k >>= 1;
//    }
//    return res;
//}
//
// signed main() {
//    int n, m;
//    cin >> n >> m;
//    int bu = 1;
//    for (int i = 1; i <= n; i++) {
//        int l, r, x, y;
//        cin >> l >> r >> x >> y;
//        int ni = ksm(y, mod - 2);
//        int qu = 1LL * x * ni % mod;
//        int buqu = 1LL * (y - x) * ni % mod;
//        a[r].emplace_back(l, qu, buqu);
//        bu = 1LL * bu * buqu % mod;
//    }
//    dp[0] = bu;
//    for (int i = 1; i <= m; i++) {
//        int ans = 0;
//        for (auto & [l, qu, buqu] : a[i]) {
//            ans += 1LL * dp[l - 1] * qu % mod * ksm(buqu, mod - 2) % mod;
//            ans %= mod;
//        }
//        dp[i] = ans;
//    }
//    cout << dp[m] << endl;
//    return 0;
//}

// 165. CF2121E Sponsor of Your Problems   https://www.luogu.com.cn/problem/CF2121E
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        string l, r;
//        cin >> l >> r;
//        int ans = 0;
//        int n = l.size() - 1;
//        for (int i = 0; i <= n; i++) {
//            if (l[i] == r[i]) ans += 2;
//            else {
//                if (r[i] - l[i] == 1) {
//                    ans++;
//                    i++;
//                    while (i <= n && r[i] == '0' && l[i] == '9') {
//                        ans++;
//                        i++;
//                    }
//                }
//                break;
//            }
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 166. https://www.luogu.com.cn/problem/CF2121G
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// signed main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        int n;
//        cin >> n;
//        string s;
//        cin >> s;
//        s = " " + s;
//        int ans = n * (n + 1) * (n + 2) / 6;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) a[i] = a[i - 1] + (s[i] == '0' ? -1 : 1);
//        sort(a.begin(), a.end());
//        for (int i = 0; i <= n; i++) ans += a[i] * i - (n - i) * a[i];
//        ans /= 2;
//        cout << ans << endl;
//    }
//    return 0;
//}

// 167. P3931 SAC E#1 - 一道难题 Tree
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 100010;
// #define int long long
//
// vector<pair<int, int>> g[N];
// int a[N];
//
// void dfs(int u, int fa) {
//    if (g[u].size() == 1 && g[u][0].first == fa) a[u] = g[u][0].second;
//    else {
//        int temp = 0;
//        for (auto & [v, w] : g[u]) {
//            if (v != fa) {
//                dfs(v, u);
//                temp += min(w, a[v]);
//            }
//        }
//        a[u] = temp;
//    }
//}
//
// signed main() {
//    int n, r;
//    cin >> n >> r;
//    for (int i = 1; i < n; i++) {
//        int u, v, w;
//        cin >> u >> v >> w;
//        g[u].emplace_back(v, w);
//        g[v].emplace_back(u, w);
//    }
//    dfs(r, 0);
//    cout << a[r] << endl;
//    return 0;
//}

// 168. P4084 [USACO17DEC] Barn Painting G
// #include <bits/stdc++.h>
// using namespace std;
// const int mod = 1e9 + 7, N = 1e5 + 10;
// using ll = long long;
//
// vector<int> g[N];
// int dp[N][4];
//
// void dfs(int u, int fa) {
//    for (int i : g[u]) {
//        if (i == fa) continue;
//        dfs(i, u);
//        dp[u][1] = (ll)dp[u][1] * (dp[i][2] + dp[i][3]) % mod;
//        dp[u][2] = (ll)dp[u][2] * (dp[i][1] + dp[i][3]) % mod;
//        dp[u][3] = (ll)dp[u][3] * (dp[i][2] + dp[i][1]) % mod;
//    }
//}
//
// signed main() {
//    int n, k;
//    cin >> n >> k;
//    for (int i = 1; i < n; i++) {
//        int u, v;
//        cin >> u >> v;
//        g[u].emplace_back(v);
//        g[v].emplace_back(u);
//    }
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= 3; j++) {
//            dp[i][j] = 1;
//        }
//    }
//    while (k--) {
//        int b, c;
//        cin >> b >> c;
//        for (int i = 1; i <= 3; i++) {
//            if (i == c) continue;
//            dp[b][i] = 0;
//        }
//    }
//    dfs(1, 0);
//    cout << ((dp[1][1] + dp[1][2]) % mod + dp[1][3]) % mod << endl;
//    return 0;
//}

// 2025.7.25
// 169. P4147 玉蟾宫
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1010;
//
// char a[N][N];
// int h[N][N], l[N][N], r[N][N];
//
// signed main() {
//    int n, m;
//    cin >> n >> m;
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//            cin >> a[i][j];
//            if (a[i][j] == 'F') {
//                h[i][j] = h[i - 1][j] + 1;
//                l[i][j] = (a[i][j - 1] == 'F' ? l[i][j - 1] : j);
//            }
//        }
//        for (int j = m; j >= 1; j--) {
//            if (a[i][j] == 'F')
//                r[i][j] = (a[i][j + 1] == 'F' ? r[i][j + 1] : j);
//        }
//    }
//
//    int ans = 0;
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//            if (a[i][j] == 'F' && a[i - 1][j] == 'F') {
//                l[i][j] = max(l[i][j], l[i - 1][j]);
//                r[i][j] = min(r[i][j], r[i - 1][j]);
//            }
//            ans = max(ans, h[i][j] * (r[i][j] - l[i][j] + 1));
//        }
//    }
//    cout << 3 * ans << endl;
//    return 0;
//}

// 170. P2401 不等数列
// #include <bits/stdc++.h>
// using namespace std;
// const int mod = 2015;
//
// signed main() {
//    int n, k;
//    cin >> n >> k;
//    vector<vector<int>> dp(n + 1, vector<int>(k + 1));
//    for (int i = 1; i <= n; i++) dp[i][0] = 1;
//    for (int i = 2; i <= n; i++) {
//        for (int j = 1; j <= min(k, i - 1); j++) {
//            dp[i][j] = (j + 1) * dp[i - 1][j] + (i - j) * dp[i - 1][j - 1];
//            dp[i][j] %= mod;
//        }
//    }
//    cout << dp[n][k] << endl;
//    return 0;
//}

// 171. P1950 长方形
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1010;
//
// char a[N][N];
// int h[N][N];
// int l[N], r[N];
// int n, m;
//
// void init(int x) {
//    stack<int> s;
//    s.push(0);
//    for (int i = 1; i <= m; i++) {
//        while (s.size() >= 2 && h[x][s.top()] >= h[x][i]) s.pop();
//        l[i] = s.top();
//        s.push(i);
//    }
//    while (!s.empty()) s.pop();
//    s.push(m + 1);
//    for (int i = m; i >= 1; i--) {
//        while (s.size() >= 2 && h[x][s.top()] > h[x][i]) s.pop();
//        r[i] = s.top();
//        s.push(i);
//    }
//}
//
// signed main() {
//    cin >> n >> m;
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//            cin >> a[i][j];
//            if (a[i][j] == '.') {
//                h[i][j] = h[i - 1][j] + 1;
//            }
//        }
//    }
//    long long ans = 0;
//    for (int i = 1; i <= n; i++) {
//        init(i);
//        for (int j = 1; j <= m; j++) {
//            ans += 1LL * h[i][j] * (j - l[j]) * (r[j] - j);
//        }
//    }
//    cout << ans << endl;
//    return 0;
//}

// 172. P1880 [NOI1995] 石子合并
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int n;
//    cin >> n;
//    vector<int> a(2 * n + 1);
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    for (int i = 1; i <= n; i++) a[i + n] = a[i];
//    vector<int> sum(2 * n + 1);
//    for (int i = 1; i <= 2 * n; i++) sum[i] = sum[i - 1] + a[i];
//    int minn = 1e9, maxn = 0;
//    for (int z = 1; z < n; z++) {
//        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
//        vector<vector<int>> dp2(n + 1, vector<int>(n + 1, 1e9));
//        for (int i = 1; i <= n; i++) dp[1][i] = 0, dp2[1][i] = 0;
//        for (int i = 2; i <= n; i++) {
//            for (int j = 1; j + i - 1 <= n; j++) {
//                for (int k = j; k < j + i - 1; k++) {
//                    dp[i][j] = max(dp[i][j], dp[k - j + 1][j] + dp[j + i - k - 1][k + 1] + sum[i + j - 1 + z] - sum[j - 1 + z]);
//                    dp2[i][j] = min(dp2[i][j], dp2[k - j + 1][j] + dp2[j + i - k - 1][k + 1] + sum[i + j - 1 + z] - sum[j - 1 + z]);
//                }
//            }
//        }
//        minn = min(dp2[n][1], minn);
//        maxn = max(dp[n][1], maxn);
//    }
//    cout << minn << endl << maxn;
//    return 0;
//}

// 173. P2359 三素数数
// #include <bits/stdc++.h>
// using namespace std;
// const int mod = 1e9 + 9;
//
// bool is_prime(int n) {
//    for (int i = 2; i * i <= n; i++)
//        if (n % i == 0) return false;
//    return true;
//}
//
// signed main() {
//    vector<int> p;
//    for (int i = 100; i <= 1000; i++) if (is_prime(i)) p.push_back(i);
//    int n;
//    cin >> n;
//    vector<unordered_map<string, int>> dp(n + 1);
//    for (int i : p) {
//        dp[3][to_string(i).substr(1, 2)]++;
//    }
//    for (int i = 4; i <= n; i++) {
//        for (int j : p) {
//            dp[i][to_string(j).substr(1, 2)] += dp[i - 1][to_string(j).substr(0, 2)];
//            dp[i][to_string(j).substr(1, 2)] %= mod;
//        }
//    }
//    int ans = 0;
//    for (auto & [key, cnt] : dp[n]) ans = (ans + cnt) % mod;
//    cout << ans << endl;
//    return 0;
//}

// 174. P1651 塔
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 500010;
//
// signed main() {
//    int n;
//    cin >> n;
//    vector<int> a(n + 1);
//    int sum = 0;
//    for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
//    vector<vector<int>> dp(n + 1, vector<int>(N, -1e9));
//    dp[0][0] = 0;
//    for (int i = 1; i <= n; i++) {
//        for (int j = 0; j <= sum; j++) {
//            if (j + a[i] < N)
//                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + a[i]]);
//            if (j >= a[i]) dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i]] + a[i]);
//            else dp[i][j] = max(dp[i][j], dp[i - 1][a[i] - j] + j);
//        }
//    }
//    if (dp[n][0]) cout << dp[n][0] << endl;
//    else cout << -1 << endl;
//    return 0;
//}

// 175. https://codeforces.com/problemset/problem/2114/G
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, k;
//        cin >> n >> k;
//        vector<int> a(n + 1), f(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i], f[i] = a[i] / (a[i] & -a[i]);
//        vector<int> pre(n + 1), suf(n + 1);
//        for (int i = 1; i < n; i++) {
//            int temp = 0;
//            if (f[i] == f[i + 1] && a[i] > a[i + 1]) {
//                temp = (a[i] - 2 * a[i + 1]) / f[i] + 1;
//            } else {
//                temp = a[i] / f[i];
//            }
//            pre[i + 1] = pre[i] + temp;
//        }
//        for (int i = n; i >= 2; i--) {
//            int temp = 0;
//            if (f[i] == f[i - 1] && a[i] > a[i - 1]) {
//                temp = (a[i] - 2 * a[i - 1]) / f[i] + 1;
//            } else {
//                temp = a[i] / f[i];
//            }
//            suf[i - 1] = suf[i] + temp;
//        }
//        bool yes = false;
//        for (int i = 1; i <= n; i++) {
//            if (pre[i] + suf[i] + a[i] / f[i] >= k) {
//                yes = true;
//                break;
//            }
//        }
//        if (yes) cout << "YES" << endl;
//        else cout << "NO" << endl;
//    }
//    return 0;
//}

// 176. CF2118C Make It Beautiful
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, k;
//        cin >> n >> k;
//        vector<int> a(n);
//        for (int i = 0; i < n; i++) cin >> a[i];
//        vector<__int128> sum(61), cnt(61);
//        int ans = 0;
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j <= 60; j++) {
//                if ((a[i] >> j) & 1) {
//                    ans++;
//                } else {
//                    sum[j] += (1LL << j);
//                    cnt[j]++;
//                }
//            }
//        }
//        for (int i = 1; i <= 60; i++) sum[i] += sum[i - 1];
//        int id = lower_bound(sum.begin(), sum.end(), k) - sum.begin();
//        id--;
//        for (int i = 0; i <= id; i++) ans += cnt[i];
//        if (id >= 0) k -= sum[id];
//        while (k >= (1LL << (id + 1))) {
//            k -= (1LL << (id + 1));
//            ans++;
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 2025.7.26
// 177. https://www.luogu.com.cn/problem/CF2115A
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n);
//        int g = 0;
//        for (int i = 0; i < n; i++) cin >> a[i], g = gcd(g, a[i]);
//        int cnt = 0;
//        for (int i = 0; i < n; i++)
//            if (a[i] == g) cnt++;
//        if (cnt) {
//            cout << n - cnt << endl;
//            continue;
//        }
//        sort(a.begin(), a.end());
//        a.erase(unique(a.begin(), a.end()), a.end());
//        vector<int> b = a;
//        while (1) {
//            cnt++;
//            vector<int> c;
//            bool have = false;
//            for (int i : b) {
//                for (int j : a) {
//                    int x = gcd(i, j);
//                    if (x == g) {
//                        have = true;
//                        break;
//                    }
//                    c.emplace_back(x);
//                }
//                if (have) break;
//            }
//            if (have) break;
//            sort(c.begin(), c.end());
//            c.erase(unique(c.begin(), c.end()), c.end());
//            b = c;
//        }
//        cout << n + cnt - 1 << endl;
//    }
//    return 0;
//}

// 178. CF2071D1 Infinite Sequence (Easy Version)   https://www.luogu.com.cn/problem/CF2071D1
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 2e5 + 10;
// #define int long long
//
// int a[N], n, l, r;
//
// int get(int x);
//
// int xor_(int x) {
//    if (x <= n) return a[x];
//    if ((x & 1) && (n & 1)) return a[n];
//    if ((x & 1) && !(n & 1)) return a[n] ^ get(n + 1);
//    if (!(x & 1) && (n & 1)) return a[n] ^ get(x);
//    if (!(x & 1) && !(n & 1)) return a[n] ^ get(n + 1) ^ get(x);
//}
//
// int get(int x) {
//    if (x <= n) return a[x] ^ a[x - 1];
//    return xor_(x / 2);
//}
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        cin >> n >> l >> r;
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        for (int i = 1; i <= n; i++) a[i] ^= a[i - 1];
//        cout << get(l) << endl;
//    }
//    return 0;
//}

// 179. https://www.luogu.com.cn/problem/CF2071C
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 10;
//
// vector<int> g[N];
// int deep[N];
//
// void dfs(int u, int fa) {
//    deep[u] = deep[fa] + 1;
//    for (int v : g[u]) {
//        if (v == fa) continue;
//        dfs(v, u);
//    }
//}
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, st, en;
//        cin >> n >> st >> en;
//        for (int i = 1; i <= n; i++) g[i].clear(), deep[i] = 0;
//        for (int i = 1; i < n; i++) {
//            int u, v;
//            cin >> u >> v;
//            g[u].emplace_back(v);
//            g[v].emplace_back(u);
//        }
//        dfs(en, 0);
//        vector<int> a(n + 1);
//        iota(a.begin() + 1, a.end(), 1);
//        sort(a.begin() + 1, a.end(), [&](int i, int j) {
//            return deep[i] > deep[j];
//        });
//        for (int i = 1; i <= n; i++) cout << a[i] << ' ';
//        cout << endl;
//    }
//    return 0;
//}

// 180. CF2070C Limited Repainting
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, k;
//        cin >> n >> k;
//        string s;
//        cin >> s;
//        vector<int> a(n);
//        for (int i = 0; i < n; i++) cin >> a[i];
//        auto check = [&](int mid) ->bool {
//            int cnt = 0;
//            int jia = 1;
//            for (int i = 0; i < n; i++) {
//                if (s[i] == 'B' && a[i] > mid) {
//                    cnt += jia;
//                    jia = 0;
//                }
//                if (s[i] == 'R' && a[i] > mid) jia = 1;
//            }
//            return (cnt <= k);
//        };
//        int l = 0, r = 1e18;
//        while (l <= r) {
//            int mid = (l + r) >> 1;
//            if (check(mid)) r = mid - 1;
//            else l = mid + 1;
//        }
//        cout << r + 1 << endl;
//    }
//    return 0;
//}

// 181. CF2069C Beautiful Sequence
// #include <bits/stdc++.h>
// using namespace std;
// const int mod = 998244353;
// #define int long long
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        int ans = 0;
//        vector<int> f(n + 1);
//        int cnt1 = 0;
//        for (int i = 1; i <= n; i++) {
//            if (a[i] == 1) {
//                cnt1++;
//                f[i] = f[i - 1];
//            } else if (a[i] == 2) {
//                f[i] = (2 * f[i - 1] % mod + cnt1) % mod;
//            } else {
//                f[i] = f[i - 1];
//                ans = (ans + f[i - 1]) % mod;
//            }
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 182. CF2069D Palindrome Shuffle
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        string s;
//        cin >> s;
//        while (s.size() > 2 && s.back() == s.front()) {
//            s.erase(s.begin());
//            s.erase(s.end() - 1);
//        }
//        if (s.size() == 2) {
//            cout << 0 << endl;
//            continue;
//        }
//        vector<int> qian(27), hou(27);
//        for (char c : s) hou[c - 'a']++;
//        auto check = [&]() -> bool {
//            for (char c = 'a'; c <= 'z'; c++)
//                if (qian[c - 'a'] < hou[c - 'a']) return false;
//            return true;
//        };
//        int ans = 0;
//        for (int i = 0; i < s.size(); i++) {
//            qian[s[i] - 'a']++, hou[s[i] - 'a']--;
//            ans++;
//            if (check()) break;
//        }
//        if (ans == s.size() / 2) {
//            int d = 0;
//            while (s[s.size() / 2 + d] == s[s.size() / 2 - 1 - d]) {
//                ans--;
//                d++;
//            }
//        }
//        reverse(s.begin(), s.end());
//        qian.assign(qian.size(), 0), hou.assign(hou.size(), 0);
//        for (char c : s) hou[c - 'a']++;
//        int ans2 = 0;
//        for (int i = 0; i < s.size(); i++) {
//            qian[s[i] - 'a']++, hou[s[i] - 'a']--;
//            ans2++;
//            if (check()) break;
//        }
//        if (ans2 == s.size() / 2) {
//            int d = 0;
//            while (s[s.size() / 2 + d] == s[s.size() / 2 - 1 - d]) {
//                ans2--;
//                d++;
//            }
//        }
//
//        cout << min(ans, ans2) << endl;
//    }
//    return 0;
//}

// 183. https://codeforces.com/contest/2069/problem/E
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int a, b, ab, ba;
//        string s;
//        cin >> s >> a >> b >> ab >> ba;
//        int cnta = 0, cntb = 0;
//        for (char c : s) cnta += (c == 'A'), cntb += (c == 'B');
//        int xu = max(cnta - a, cntb - b);
//        vector<int> AB, BA;
//        int any = 0;
//        for (int i = 0, l = 0; i < s.size(); i++) {
//            if (i == s.size() - 1 || s[i] == s[i + 1]) {
//                int tmp = (i - l + 1) / 2;
//                if (tmp) {
//                    if (s[i] == s[l]) any += tmp;
//                    else {
//                        if (s[l] == 'A') AB.emplace_back(tmp);
//                        else BA.emplace_back(tmp);
//                    }
//                }
//                l = i + 1;
//            }
//        }
//        sort(AB.begin(), AB.end());
//        sort(BA.begin(), BA.end());
//        for (int i : AB) {
//            if (ab >= i) ab -= i, xu -= i;
//            else any += i - 1;
//        }
//        for (int i : BA) {
//            if (ba >= i) ba -= i, xu -= i;
//            else xu -= ba, i -= ba, any += i - 1, ba = 0;
//        }
//        if (xu <= min(ab + ba, any)) cout << "YES" << endl;
//        else cout << "NO" << endl ;
//    }
//    return 0;
//}

// 2025.7.27   今天刷几道水题
// 184. https://codeforces.com/problemset/problem/2124/A
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n);
//        for (int i = 0; i < n; i++) cin >> a[i];
//        vector<int> b = a;
//        sort(b.begin(), b.end());
//        if (a == b) {
//            cout << "NO" << endl;
//            continue;
//        }
//        cout << "YES" << endl;
//        vector<int> ans;
//        for (int i = 0; i < n; i++) {
//            if (a[i] != b[i]) ans.emplace_back(a[i]);
//        }
//        cout << ans.size() << endl;
//        for (int i : ans) cout << i << ' ';
//        cout << endl;
//    }
//
//    return 0;
//}

// 小橙题都做不出，真fw
// 185. https://www.luogu.com.cn/problem/CF2124B
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        if (a[1] >= a[2]) cout << a[1] + a[2] << endl;
//        else cout << 2 * a[1] << endl;
//    }
//    return 0;
//}

// 186. https://www.luogu.com.cn/problem/CF2119B
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        int x1, y1, x2, y2;
//        cin >> n >> x1 >> y1 >> x2 >> y2;
//        vector<double> a(n + 1);
//        a[0] = sqrt(1LL * (x1 - x2) * (x1 - x2) + 1LL * (y1 - y2) * (y1 - y2));
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        if (n == 1) {
//            if (a[0] == a[1]) cout << "YES" << endl;
//            else cout << "NO" << endl;
//            continue;
//        }
//        sort(a.begin(), a.end());
//        double sum = 0;
//        for (int i = 0; i < n; i++) sum += a[i];
//        if (sum >= a[n]) cout << "YES" << endl;
//        else cout << "NO" << endl;
//    }
//    return 0;
//}

// 2025.7.28
// 187. https://codeforces.com/problemset/problem/2126/G1
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        int ans = 0;
//        for (int i = 1; i <= 100; i++) {
//            vector<int> sum(n + 1);
//            for (int j = 1; j <= n; j++) {
//                if (a[j] < i) sum[j] = -1;
//                else sum[j] = 1;
//                sum[j] += sum[j - 1];
//            }
//            vector<int> qian(n + 1), hou(n + 1);
//            hou[n] = sum[n];
//            for (int j = 1; j <= n; j++) qian[j] = min(sum[j], qian[j - 1]);
//            for (int j = n - 1; j >= 1; j--) hou[j] = max(hou[j + 1], sum[j]);
//            for (int j = 1; j <= n; j++) {
//                if (qian[j - 1] <= sum[j] || hou[j] >= sum[j - 1]) {
//                    ans = max(ans, i - a[j]);
//                }
//            }
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 188. https://www.luogu.com.cn/problem/CF2124C
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        int ans = 1;
//        for (int i = 1; i < n; i++) {
//            if (a[i + 1] % a[i] != 0) {
//                ans = lcm(ans, a[i] / gcd(a[i], a[i + 1]));
//            }
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 189. https://www.luogu.com.cn/problem/CF2121D
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1), b(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        for (int i = 1; i <= n; i++) cin >> b[i];
//        vector<int> ans1, ans2, ans3;
//        for (int i = 1; i <= n; i++) {
//            for (int j = 1; j + i <= n; j++) {
//                if (a[j] > a[j + 1]) {
//                    swap(a[j], a[j + 1]);
//                    ans1.emplace_back(j);
//                }
//            }
//        }
//        for (int i = 1; i <= n; i++) {
//            for (int j = 1; j + i <= n; j++) {
//                if (b[j] > b[j + 1]) {
//                    swap(b[j], b[j + 1]);
//                    ans2.emplace_back(j);
//                }
//            }
//        }
//        for (int i = 1; i <= n; i++) {
//            if (a[i] > b[i]) {
//                swap(a[i], b[i]);
//                ans3.emplace_back(i);
//            }
//        }
//        int k = ans1.size() + ans2.size() + ans3.size();
//        cout << k << endl;
//        for (int i : ans1) cout << 1 << ' ' << i << endl;
//        for (int i : ans2) cout << 2 << ' ' << i << endl;
//        for (int i : ans3) cout << 3 << ' ' << i << endl;
//    }
//    return 0;
//}

// 190. https://www.luogu.com.cn/problem/CF1948B
// #include <bits/stdc++.h>
// using namespace std;
//
// bool is_fu(int x, int& end, int& beg) {
//    string s = to_string(x);
//    string s2 = s;
//    sort(s2.begin(), s2.end());
//    if (s == s2) {
//        end = s.back() - '0';
//        beg = s.front() - '0';
//        return true;
//    }
//    return false;
//}
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        int mi = 0;
//        bool yes = true;
//        for (int i = 1; i <= n; i++) {
//            int be, ed;
//            if (is_fu(a[i], ed, be)) {
//                if (be >= mi) mi = ed;
//                else {
//                    if (a[i] >= mi) mi = a[i];
//                    else {
//                        yes = false;
//                        break;
//                    }
//                }
//            } else {
//                if (a[i] >= mi) mi = a[i];
//                else {
//                    yes = false;
//                    break;
//                }
//            }
//        }
//        if (yes) cout << "YES" << endl;
//        else cout << "NO" << endl;
//    }
//    return 0;
//}

// 191. https://codeforces.com/contest/1948/problem/C
// #include <bits/stdc++.h>
// using namespace std;
//
// int dx[] = {1, -1, 0, 0};
// int dy[] = {0, 0, 1, -1};
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        vector<string> s(3);
//        int n;
//        cin >> n;
//        cin >> s[1] >> s[2];
//        s[1] = ' ' + s[1], s[2] = ' ' + s[2];
//        vector<vector<int>> vis(3, vector<int>(n + 1));
//        queue<pair<int, int>> q;
//        q.emplace(1, 1);
//        bool ans = false;
//        while (!q.empty()) {
//            pair<int, int> dang = q.front();
//            q.pop();
//            vis[dang.first][dang.second] = 1;
//            if (dang.first == 2 && dang.second == n) {
//                ans = true;
//                break;
//            }
//            for (int i = 0; i < 4; i++) {
//                int x = dang.first + dx[i];
//                int y = dang.second + dy[i];
//                if (1 <= x && x <= 2 && 1 <= y && y <= n) {
//                    int x_ = x;
//                    int y_ = y + (s[x][y] == '<' ? -1 : 1);
//                    if (1 <= y_ && y_ <= n && !vis[x_][y_]) {
//                        q.emplace(x_, y_);
//                        vis[x_][y_] = 1;
//                    }
//                }
//            }
//        }
//        if (ans) cout << "YES" << endl;
//        else cout << "NO" << endl;
//    }
//    return 0;
//}

// 192. https://www.luogu.com.cn/problem/CF1948D
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        string s;
//        cin >> s;
//        for (int i = s.size() / 2 * 2; i >= 0; i -= 2) {
//            int cnt = 0;
//            for (int j = 0; j + i / 2 < s.size(); j++) {
//                if (cnt == i / 2) break;
//                if (s[j] == s[j + i / 2] || s[j] == '?' || s[j + i / 2] == '?') cnt++;
//                else cnt = 0;
//            }
//            if (cnt == i / 2) {
//                cout << i << endl;
//                break;
//            }
//        }
//    }
//    return 0;
//}

// 193. AcWing 6447. 最长的括号匹配
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    string s;
//    cin >> s;
//    int ans = 0;
//    stack<int> st;
//    for (int i = 0; i < s.size(); i++) {
//        if (s[i] == ')' && st.size() && s[st.top()] == '(') {
//            st.pop();
//            if (st.size()) ans = max(ans, i - st.top());
//            else ans = max(ans, i + 1);
//        } else st.push(i);
//    }
//    cout << ans << endl;
//    return 0;
//}

// 2025.7.29
// 194. AcWing 3682. 图的连通分量
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 22, M = 1 << N;
//
// int n, m, have[M], vis[M], mask;
//
// void dfs(int u) {
//    if (vis[u]) return;
//    vis[u] = 1;
//    if (have[u]) dfs(u ^ mask);
//    for (int i = u; i; i -= i & -i) {
//        dfs(u - (i & -i));
//    }
//}
//
// signed main() {
//    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
//    while (cin >> n >> m) {
//        memset(have, 0, sizeof have);
//        memset(vis, 0, sizeof vis);
//        mask = (1 << n) - 1;
//        for (int i = 1; i <= m; i++) {
//            int x;
//            cin >> x;
//            have[x] = 1;
//        }
//        int ans = 0;
//        for (int i = 0; i < (1 << n); i++) {
//            if (have[i] && !vis[i]) {
//                vis[i] = 1;
//                ans++;
//                dfs(i ^ mask);
//            }
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 195. AcWing 6040. 小木棍
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 10, inf = 0x3f3f3f3f;
//
// int dp[N], qian[N];
// int dp2[N], qian2[N];
// int shu[6] = {7, 3, 6, 4, 5, 2};
// int shu2[6] = {7, 3, 4, 5, 2, 6};
// unordered_map<int, char> mp = {{7, '8'}, {3, '7'}, {6, '6'}, {4, '4'}, {5, '2'}, {2, '1'}};
// unordered_map<int, char> mp2 = {{7, '8'}, {3, '7'}, {6, '0'}, {4, '4'}, {5, '2'}, {2, '1'}};
//
// signed main() {
//    memset(dp, 0x3f, sizeof dp);
//    memset(dp2, 0x3f, sizeof dp2);
//    for (int i : shu) dp[i] = 1, qian[i] = i;
//    for (int i : shu2) dp2[i] = 1, qian2[i] = i;
//    for (int i = 8; i < N; i++) {
//        for (int j : shu) {
//            if (dp[i] >= dp[i - j] + 1) {
//                dp[i] = dp[i - j] + 1;
//                qian[i] = j;
//            }
//        }
//    }
//    for (int i = 8; i < N; i++) {
//        for (int j : shu2) {
//            if (dp2[i] >= dp2[i - j] + 1) {
//                dp2[i] = dp2[i - j] + 1;
//                qian2[i] = j;
//            }
//        }
//    }
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        if (dp[n] == inf) cout << -1 << endl;
//        else {
//            string s;
//            int x = n;
//            s += mp[qian[x]];
//            x -= qian[x];
//            while (x) {
//                s += mp2[qian2[x]];
//                x -= qian2[x];
//            }
//            sort(s.begin(), s.end());
//            if (s[0] == '0') {
//                int i = 1;
//                while (i < s.size() && s[i] == '0') i++;
//                swap(s[0], s[i]);
//            }
//            cout << s << endl;
//        }
//    }
//    return 0;
//}

// 196. https://www.luogu.com.cn/problem/CF2121C
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, m;
//        cin >> n >> m;
//        int mx = 0, cnt = 0;
//        vector<vector<int>> a(n + 1, vector<int>(m + 1));
//        for (int i = 1; i <= n; i++)
//            for (int j = 1; j <= m; j++) {
//                cin >> a[i][j];
//                mx = max(mx, a[i][j]);
//            }
//        vector<int> hang(n + 1), lie(m + 1);
//        for (int i = 1; i <= n; i++) {
//            for (int j = 1; j <= m; j++) {
//                if (a[i][j] == mx) {
//                    hang[i]++;
//                    lie[j]++;
//                    cnt++;
//                }
//            }
//        }
//        int keyi = 0;
//        for (int i = 1; i <= n; i++) {
//            for (int j = 1; j <= m; j++) {
//                if ((hang[i] + lie[j] - (a[i][j] == mx)) == cnt) {
//                    keyi = 1;
//                    break;
//                }
//            }
//            if (keyi) break;
//        }
//        cout << mx - keyi << endl;
//    }
//    return 0;
//}

// 197. https://www.luogu.com.cn/problem/CF2114E
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 2e5 + 10;
// #define int long long
//
// vector<int> g[N];
// int w[N], minn[N], maxn[N];
//
// void dfs(int u, int fa) {
//    maxn[u] = max(w[u], w[u] - minn[fa]);
//    minn[u] = min(w[u], w[u] - maxn[fa]);
//    for (int v : g[u]) {
//        if (v == fa) continue;
//        dfs(v, u);
//    }
//}
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        for (int i = 1; i <= n; i++) cin >> w[i];
//        for (int i = 1; i <= n; i++) g[i].clear();
//        for (int i = 1; i < n; i++) {
//            int u, v;
//            cin >> u >> v;
//            g[u].emplace_back(v);
//            g[v].emplace_back(u);
//        }
//        dfs(1, 0);
//        for (int i = 1; i <= n; i++) cout << maxn[i] << " \n"[i == n];
//    }
//    return 0;
//}

// 198. https://www.luogu.com.cn/problem/CF2061C
// #include <bits/stdc++.h>
// using namespace std;
// const int mod = 998244353;
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        vector<vector<int>> dp(n + 1, vector<int>(3));
//        if (a[1] == 0) dp[1][1] = 1;
//        dp[1][0] = 1;
//        for (int i = 2; i <= n; i++) {
//            dp[i][0] = dp[i - 1][1];
//            dp[i][1] = (dp[i - 1][1] * (a[i] == a[i - 1]) + dp[i - 1][0] * (a[i] == a[i - 2] + 1)) % mod;
//        }
//        cout << (dp[n][0] + dp[n][1]) % mod << endl;
//    }
//    return 0;
//}

// 199. https://codeforces.com/problemset/problem/2052/F
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<string> s(2);
//        cin >> s[0] >> s[1];
//        s[0] = ' ' + s[0], s[1] = ' ' + s[1];
//        vector<vector<int>> dp(n + 1, vector<int>(4));
//        string t = s[0].substr(1, 1) + s[1].substr(1, 1);
//        if (t == "..") dp[1][0] = 1, dp[1][3] = 1;
//        else if (t == "#.") dp[1][1] = 1;
//        else if (t == ".#") dp[1][2] = 1;
//        else dp[1][3] = 1;
//        for (int i = 2; i <= n; i++) {
//            t = s[0].substr(i, 1) + s[1].substr(i, 1);
//            if (t == "..") {
//                dp[i][3] = dp[i - 1][3] + dp[i - 1][0];
//                dp[i][0] = dp[i - 1][3];
//                dp[i][1] = dp[i - 1][2];
//                dp[i][2] = dp[i - 1][1];
//            }
//            else if (t == "#.") {
//                dp[i][3] = dp[i - 1][1];
//                dp[i][1] = dp[i - 1][3];
//            }
//            else if (t == ".#") {
//                dp[i][3] = dp[i - 1][2];
//                dp[i][2] = dp[i - 1][3];
//            }
//            else {
//                dp[i][3] = dp[i - 1][3];
//            }
//            for (int j = 0; j < 4; j++)
//                if (dp[i][j] > 2) dp[i][j] = 2;
//        }
//        if (dp[n][3] == 1) cout << "Unique" << endl;
//        else if (dp[n][3] > 1) cout << "Multiple" << endl;
//        else cout << "None" << endl;
//    }
//    return 0;
//}

// 2025.7.30
// 200. AcWing 6039. 地图探险
// #include <bits/stdc++.h>
// using namespace std;
//
// int dx[] = {0, 1, 0, -1};
// int dy[] = {1, 0, -1, 0};
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, m, k, x, y, d;
//        cin >> n >> m >> k >> x >> y >> d;
//        vector<vector<char>> a(n + 1, vector<char>(m + 1));
//        for (int i = 1; i <= n; i++)
//            for (int j = 1; j <= m; j++) cin >> a[i][j];
//        vector<vector<bool>> vis(n + 1, vector<bool>(m + 1));
//        int ans = 1;
//        vis[x][y] = true;
//        while (k--) {
//            int x_ = x + dx[d], y_ = y + dy[d];
//            if (1 <= x_ && x_ <= n && 1 <= y_ && y_ <= m && a[x_][y_] == '.') {
//                x = x_, y = y_;
//                if (!vis[x][y]) {
//                    ans++;
//                    vis[x][y] = true;
//                }
//            } else {
//                d =  (d + 1) % 4;
//            }
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 201. https://www.luogu.com.cn/problem/CF2102A
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, m, p, q;
//        cin >> n >> m >> p >> q;
//        if (n % p == 0) {
//            if (n / p * q == m) cout << "YES" << endl;
//            else cout << "NO" << endl;
//        } else cout << "YES" << endl;
//    }
//    return 0;
//}

// 2025.7.31
// 202. AcWing 5722. 十滴水
// #include <bits/stdc++.h>
// using namespace std;
//
// int c, m, n, ans;
// struct node {
//    int val, x;
//    node* pre{};
//    node* ne{};
//    node(int _val, int _x) : val(_val), x(_x) {};
//};
//
// void add(node* p1, node* p2) {
//    p1->ne = p2;
//    p2->pre = p1;
//}
//
// void del(node* p) {
//    p->pre->ne = p->ne;
//    if (p->ne) p->ne->pre = p->pre;
//    ans--;
//}
//
// signed main() {
//    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
//    cin >> c >> m >> n;
//    vector<pair<int, int>> a(m);
//    for (auto& [f, s] : a) cin >> f >> s;
//    sort(a.begin(), a.end());
//    unordered_map<int, node*> mp;
//    node* head = new node(-1, -1);
//    node* p = head;
//    for (auto [x, w] : a) {
//        node* no = new node(w, x);
//        add(p, no);
//        p = no;
//        mp[x] = p;
//        ans++;
//    }
//    while (n--) {
//        int x;
//        cin >> x;
//        p = mp[x];
//        p->val++;
//        if (p->val >= 5) {
//            node* qian = p->pre;
//            node* hou = p->ne;
//            if (qian != head) qian->val++;
//            if (hou) hou->val++;
//            del(p);
//            while ((qian != head && qian->val >= 5) || (hou && hou->val >= 5)) {
//                while (qian != head && qian->val >= 5) {
//                    p = qian;
//                    qian = p->pre;
//                    hou = p->ne;
//                    if (qian != head) qian->val++;
//                    if (hou) hou->val++;
//                    del(p);
//                }
//                if (hou && hou->val >= 5) {
//                    p = hou;
//                    qian = p->pre;
//                    hou = p->ne;
//                    if (qian != head) qian->val++;
//                    if (hou) hou->val++;
//                    del(p);
//                }
//            }
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 203. AcWing 3681. 小镇购物
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 10010;
//
// int dist[N][110];
// vector<int> g[N];
// int a[N];
//
// signed main() {
//    int n, m, k, s;
//    while (cin >> n >> m >> k >> s) {
//        memset(dist, -1, sizeof dist);
//        for (int i = 1; i <= n; i++) g[i].clear();
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        for (int i = 1; i <= m; i++) {
//            int u, v;
//            cin >> u >> v;
//            g[u].emplace_back(v);
//            g[v].emplace_back(u);
//        }
//        queue<int> q;
//        for (int i = 1; i <= k; i++) {
//            for (int j = 1; j <= n; j++) {
//                if (a[j] == i) q.push(j), dist[j][i] = 0;
//            }
//
//            while (!q.empty()) {
//                int u = q.front();
//                q.pop();
//                for (int v : g[u]) {
//                    if (dist[v][i] == -1) {
//                        dist[v][i] = dist[u][i] + 1;
//                        q.push(v);
//                    }
//                }
//            }
//        }
//
//        for (int i = 1; i <= n; i++) {
//            sort(dist[i] + 1, dist[i] + k + 1);
//            int res = 0;
//            for (int j = 1; j <= s; j++) res += dist[i][j];
//            cout << res << ' ';
//        }
//        cout << endl;
//    }
//
//    return 0;
//}

// 204. https://www.luogu.com.cn/problem/CF2120C
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, m;
//        cin >> n >> m;
//        if (m < n || m > (n + 1) * n / 2) cout << -1 << endl;
//        else {
//            vector<int> ans(n + 1);
//            int pos = 1;
//            vector<int> vis(n + 1);
//            int qian = 0, cnt = 0;
//            for (int i = n; i >= 1; i--) {
//                int mi = qian + i + (n - cnt - 1);
//                int mx = qian + i + (n - i - cnt) * i + i * (i - 1) / 2;
//                if (mi <= m && m <= mx) {
//                    vis[i] = 1;
//                    ans[pos++] = i;
//                    cnt++;
//                    qian += i;
//                }
//            }
//            for (int i = 1; i <= n; i++) {
//                if (!vis[i]) {
//                    ans[pos++] = i;
//                }
//            }
//            cout << ans[1] << endl;
//            for (int i = 1; i <= n - 1; i++) {
//                cout << ans[i] << ' ' << ans[i + 1] << endl;
//            }
//            cout << endl;
//        }
//    }
//    return 0;
//}

// 205. https://www.luogu.com.cn/problem/CF2119C
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, l, r, k;
//        cin >> n >> l >> r >> k;
//        if (n & 1) cout << l << endl;
//        else {
//            if (n == 2) cout << -1 << endl;
//            else {
//                int l_ = l;
//                while (l_ - (l_ & -l_) != 0) l_ -= (l_ & -l_);
//                l_ <<= 1;
//                if (l_ <= r) {
//                    if (n - k <= 1) cout << l_ << endl;
//                    else cout << l << endl;
//                } else cout << -1 << endl;
//            }
//        }
//    }
//    return 0;
//}

// 206. https://www.luogu.com.cn/problem/CF2104D
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 7e6 + 10;
//
// int primes[N], vis[N], cnt = 1;
//
// void euler() {
//    for (int i = 2; i < N; i++) {
//        if (!vis[i]) primes[cnt++] = i;
//        for (int j = 1; primes[j] * i < N; j++) {
//            vis[i * primes[j]] = 1;
//            if (i % primes[j] == 0) break;
//        }
//    }
//    for (int i = 1; i < cnt; i++) primes[i] += primes[i - 1];
//}
//
// signed main() {
//    euler();
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1);
//        int sum = 0;
//        for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
//        sort(a.begin() + 1, a.end());
//        for (int i = 1; i <= n; i++) a[i] += a[i - 1];
//        int ans = 0;
//        while (sum - a[ans] < primes[n - ans]) {
//            ans++;
//            if (ans == n - 1) break;
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 207. P5144 蜈蚣
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// signed main() {
//    int n, m;
//    cin >> n >> m;
//    vector<int> a(n + 1);
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    for (int i = 1; i <= n; i++) a[i] ^= a[i - 1];
//    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
//    for (int i = 1; i <= n; i++) dp[i][1] = a[i];
//    for (int i = 2; i <= m; i++) {
//        for (int j = i; j <= n; j++) {
//            for (int k = j - 1; k >= i - 1; k--) {
//                dp[j][i] = max(dp[j][i], dp[k][i - 1] + (a[j] ^ a[k]));
//            }
//        }
//    }
//    cout << dp[n][m] << endl;
//    return 0;
//}

// 208. P5151 HKE与他的小朋友
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int n, k;
//    cin >> n >> k;
//    vector<int> a(n + 1);
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    vector<vector<int>> b;
//    vector<int> vis(n + 1);
//    for (int i = 1; i <= n; i++) {
//        if (!vis[i]) {
//            b.emplace_back(1);
//            int t = i;
//            while (!vis[t]) {
//                vis[t] = 1;
//                b.back().emplace_back(t);
//                t = a[t];
//            }
//        }
//    }
//    vector<int> ans(n + 1);
//    for (auto & i : b) {
//        int s = k % ((int)i.size() - 1);
//        if (s == 0) s = (int)i.size() - 1;
//        s = (int)i.size() - 1 - s + 1;
//        for (int j = 1; j < i.size(); j++) {
//            ans[i[j]] = i[s];
//            s++;
//            if (s > (int)i.size() - 1) s = 1;
//        }
//    }
//    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
//    cout << endl;
//    return 0;
//}

// 2025.8.1
// 209. P2114 [NOI2014] 起床困难综合症
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int n, m;
//    cin >> n >> m;
//    vector<pair<string, int>> a(n + 1);
//    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
//    int ans = 0;
//    int dang = 0;
//    for (int i = 30; i >= 0; i--) {
//        int t = 0;
//        for (int j = 1; j <= n; j++) {
//            int wei = a[j].second >> i & 1;
//            if (a[j].first == "AND") {
//                t = t & wei;
//            } else if (a[j].first == "OR") {
//                t = t | wei;
//            } else {
//                t = t ^ wei;
//            }
//        }
//        if (t == 1) {
//            ans = ans | (1 << i);
//        } else {
//            t = 1;
//            for (int j = 1; j <= n; j++) {
//                int wei = a[j].second >> i & 1;
//                if (a[j].first == "AND") {
//                    t = t & wei;
//                } else if (a[j].first == "OR") {
//                    t = t | wei;
//                } else {
//                    t = t ^ wei;
//                }
//            }
//            if (t == 1 && (dang | (1 << i)) <= m) {
//                dang = dang | (1 << i);
//                ans = ans | (1 << i);
//            }
//        }
//    }
//    cout << ans << endl;
//    return 0;
//}

// 在 AcWing 重温许多旧题

// 210. P7073 [CSP-J2020] 表达式
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e6 + 10;
//
// string s;
// int cnt, f[N], flag[N], tr[N][2];
// int n, a[N];
//
// int dfs(int u, int g) {
//    a[u] ^= g;
//    if (u <= n) return a[u];
//    int x = dfs(tr[u][0], g ^ flag[tr[u][0]]);
//    int y = dfs(tr[u][1], g ^ flag[tr[u][1]]);
//    if (a[u] == 2) {
//        if (x == 0) f[tr[u][1]] = 1;
//        if (y == 0) f[tr[u][0]] = 1;
//        return x & y;
//    } else {
//        if (x == 1) f[tr[u][1]] = 1;
//        if (y == 1) f[tr[u][0]] = 1;
//        return x | y;
//    }
//}
//
// void dfs2(int u) {
//    if (u <= n) return;
//    f[tr[u][0]] |= f[u];
//    f[tr[u][1]] |= f[u];
//    dfs2(tr[u][0]);
//    dfs2(tr[u][1]);
//}
//
// signed main() {
//    getline(cin, s);
//    cin >> n;
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    cnt = n + 1;
//    stack<int> st;
//    for (int i = 0; i < s.size(); i += 2) {
//        if (s[i] == 'x') {
//            int x = 0;
//            i++;
//            while (s[i] != ' ') x = 10 * x + s[i] - '0', i++;
//            i--;
//            st.push(x);
//        } else if (s[i] == '&') {
//            int y = st.top();
//            st.pop();
//            int x = st.top();
//            st.pop();
//            a[cnt] = 2;
//            tr[cnt][0] = x;
//            tr[cnt][1] = y;
//            st.push(cnt++);
//        } else if (s[i] == '|') {
//            int y = st.top();
//            st.pop();
//            int x = st.top();
//            st.pop();
//            a[cnt] = 3;
//            tr[cnt][0] = x;
//            tr[cnt][1] = y;
//            st.push(cnt++);
//        } else {
//            flag[st.top()] ^= 1;
//        }
//    }
//    cnt--;
//    int ans = dfs(cnt, flag[cnt]);
//    dfs2(cnt);
//    int q;
//    cin >> q;
//    while (q--) {
//        int x;
//        cin >> x;
//        if (f[x]) cout << ans << endl;
//        else cout << !ans << endl;
//    }
//    return 0;
//}

// 211. P1175 表达式的转换
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1010;
//
// string s;
// int a[N];
// bool is_fu[N];
// int cnt, tr[N][2];
// unordered_map<char, int> mp = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3}};
// stack<int> num;
// stack<int> op;
// int head;
//
// int add() {
//    int y = num.top();
//    num.pop();
//    int x = num.top();
//    num.pop();
//    int z = op.top();
//    op.pop();
//    tr[z][0] = x;
//    tr[z][1] = y;
//    num.push(z);
//    return z;
//}
//
// void dfs(int u) {
//    if (!is_fu[u]) {
//        cout << a[u] << ' ';
//        return;
//    }
//    dfs(tr[u][0]);
//    dfs(tr[u][1]);
//    cout << (char)a[u] << ' ';
//}
//
// int dfs2(int u) {
//    if (!is_fu[u]) return a[u];
//    int x = dfs2(tr[u][0]);
//    int y = dfs2(tr[u][1]);
//    if (a[u] == '+') {
//        a[u] = x + y;
//    } else if (a[u] == '-') {
//        a[u] = x - y;
//    } else if (a[u] == '*') {
//        a[u] = x * y;
//    } else if (a[u] == '/') {
//        a[u] = x / y;
//    } else {
//        a[u] = (int)pow(x, y);
//    }
//    is_fu[u] = false;
//    dfs(head);
//    cout << endl;
//    return a[u];
//}
//
// signed main() {
//    cin >> s;
//    for (char i : s) {
//        if (isdigit(i)) {
//            a[++cnt] = i - '0';
//            num.push(cnt);
//        } else if (i == '(') {
//            a[++cnt] = '(';
//            op.push(cnt);
//            is_fu[cnt] = true;
//        } else if (i == ')') {
//            while (!op.empty() && (char)a[op.top()] != '(') add();
//            op.pop();
//        } else {
//            if (i != '^') {
//                while (!op.empty() && mp[(char)a[op.top()]] >= mp[i]) add();
//                a[++cnt] = i;
//                op.push(cnt);
//                is_fu[cnt] = true;
//            } else {
//                a[++cnt] = i;
//                op.push(cnt);
//                is_fu[cnt] = true;
//            }
//        }
//    }
//    while (!op.empty()) head = add();
//    dfs(head);
//    cout << endl;
//    dfs2(head);
//    return 0;
//}

// 212. P2397 yyy loves Maths VI (mode)
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int n;
//    cin >> n;
//    int home = 0, cnt = 0;
//    for (int i = 1; i <= n; i++) {
//        int x;
//        cin >> x;
//        if (home == 0) home = x;
//        if (home == x) cnt++;
//        else {
//            cnt--;
//            if (cnt == 0) home = 0;
//        }
//    }
//    cout << home << endl;
//    return 0;
//}

// 213. CF2066B White Magic
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1);
//        int id = n + 1, ans = 0;
//        for (int i = 1; i <= n; i++) {
//            cin >> a[i];
//            if (a[i] == 0) id = min(id, i);
//            else ans++;
//        }
//        if (id == n + 1) cout << n << endl;
//        else {
//            unordered_map<int, int> mp;
//            bool ke = true;
//            for (int i = 1; i <= n; i++) mp[a[i]]++;
//            int mex = 1, mi = 1e9;
//            while (mp[mex]) mex++;
//            for (int i = 1; i < id; i++) {
//                mi = min(mi, a[i]);
//                mp[a[i]]--;
//                if (mp[a[i]] == 0) mex = min(mex, a[i]);
//                if (mi < mex) {
//                    ke = false;
//                    break;
//                }
//            }
//            cout << ans + ke << endl;
//        }
//    }
//    return 0;
//}

// 214. https://codeforces.com/problemset/problem/2029/C
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1), b(n + 1), c(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        if (n == 1) {
//            cout << 0 << endl;
//            continue;
//        }
//        b[1] = 1;
//        for (int i = 2; i <= n; i++) {
//            if (b[i - 1] <= a[i]) b[i] = min(b[i - 1] + 1, a[i]);
//            else b[i] = b[i - 1] - 1;
//        }
//        set<int> s;
//        s.insert(0);
//        for (int i = 2; i <= n; i++) {
//            s.insert(b[i - 2]);
//            if (a[i] >= c[i - 1]) c[i] = min(a[i], c[i - 1] + 1);
//            else c[i] = c[i - 1] - 1;
//            int t = *s.rbegin();
//            if (t <= a[i]) t = min(t + 1, a[i]);
//            else t--;
//            c[i] = max(c[i], t);
//        }
//        s.insert(b[n - 1]);
//        int ans = *s.rbegin();
//        ans = max(ans, c[n]);
//        cout << ans << endl;
//    }
//    return 0;
//}

// 215. CF2085C Serval and The Formula
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int x, y;
//        cin >> x >> y;
//        if (x == y) {
//            cout << -1 << endl;
//            continue;
//        }
//        if (x < y) swap(x, y);
//        int ans = 0;
//        for (int i = 0; i <= 60; i++) {
//            int x_ = x >> i & 1;
//            int y_ = y >> i & 1;
//            if (x_ == 1 && y_ == 1) {
//                int _x = ((x & ((1LL << i) - 1)) ^ (((1LL << i) - 1))) + 1;
//                ans += _x;
//                x += _x;
//                y += _x;
//            }
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 2025.8.2
// 216. https://www.luogu.com.cn/problem/CF2070D
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 3e5 + 10, mod = 998244353;
//
// vector<int> g[N];
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        for (int i = 1; i <= n; i++) g[i].clear();
//        for (int i = 2; i <= n; i++) {
//            int x;
//            cin >> x;
//            g[x].emplace_back(i);
//            g[i].emplace_back(x);
//        }
//        vector<int> dp(n + 1), cen(n + 1), sum(n + 1);
//        dp[1] = 1, cen[1] = 1;
//        queue<int> q;
//        int ans = 1;
//        for (int i : g[1]) {
//            dp[i] = 1;
//            cen[i] = 2;
//            sum[cen[i]] += dp[i];
//            q.push(i);
//            ans = (ans + dp[i]) % mod;
//        }
//        while (!q.empty()) {
//            int x = q.front();
//            q.pop();
//            for (int i : g[x]) {
//                if (cen[i] != 0) continue;
//                dp[i] = ((sum[cen[x]] - dp[x]) % mod + mod) % mod;
//                cen[i] = cen[x] + 1;
//                sum[cen[i]] = (sum[cen[i]] + dp[i]) % mod;
//                q.push(i);
//                ans = (ans + dp[i]) % mod;
//            }
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 217. https://codeforces.com/problemset/problem/2096/C
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int inf = 1e15;
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<vector<int>> a(n + 1, vector<int>(n + 1));
//        for (int i = 1; i <= n; i++)
//            for (int j = 1; j <= n; j++)
//                cin >> a[i][j];
//        vector<int> A(n + 1), B(n + 1);
//        for (int i = 1; i <= n; i++) cin >> A[i];
//        for (int i = 1; i <= n; i++) cin >> B[i];
//        vector<vector<int>> hang(n + 1, vector<int>(2, inf));
//        hang[1][0] = 0, hang[1][1] = A[1];
//        for (int i = 2; i <= n; i++) {
//            int flag0 = true;
//            int flag1 = true;
//            for (int j = 1; j <= n; j++) {
//                if (a[i][j] == a[i - 1][j]) flag0 = false;
//                if (a[i][j] + 1 == a[i - 1][j]) flag1 = false;
//            }
//            if (flag0) hang[i][0] = hang[i - 1][0];
//            if (flag1) hang[i][1] = hang[i - 1][0] + A[i];
//
//            flag0 = true;
//            flag1 = true;
//            for (int j = 1; j <= n; j++) {
//                if (a[i][j] == a[i - 1][j] + 1) flag0 = false;
//                if (a[i][j] + 1 == a[i - 1][j] + 1) flag1 = false;
//            }
//            if (flag0) hang[i][0] = min(hang[i][0], hang[i - 1][1]);
//            if (flag1) hang[i][1] = min(hang[i][1], hang[i - 1][1] + A[i]);
//        }
//
//        vector<vector<int>> lie(n + 1, vector<int>(2, inf));
//        lie[1][0] = 0, lie[1][1] = B[1];
//        for (int i = 2; i <= n; i++) {
//            int flag0 = true;
//            int flag1 = true;
//            for (int j = 1; j <= n; j++) {
//                if (a[j][i] == a[j][i - 1]) flag0 = false;
//                if (a[j][i] + 1 == a[j][i - 1]) flag1 = false;
//            }
//            if (flag0) lie[i][0] = lie[i - 1][0];
//            if (flag1) lie[i][1] = lie[i - 1][0] + B[i];
//
//            flag0 = true;
//            flag1 = true;
//            for (int j = 1; j <= n; j++) {
//                if (a[j][i] == a[j][i - 1] + 1) flag0 = false;
//                if (a[j][i] + 1 == a[j][i - 1] + 1) flag1 = false;
//            }
//            if (flag0) lie[i][0] = min(lie[i][0], lie[i - 1][1]);
//            if (flag1) lie[i][1] = min(lie[i][1], lie[i - 1][1] + B[i]);
//        }
//        int ans = min(hang[n][0], hang[n][1]) + min(lie[n][0], lie[n][1]);
//        if (ans >= inf) ans = -1;
//        cout << ans << endl;
//    }
//    return 0;
//}

// 218. https://www.luogu.com.cn/problem/CF2091F
// #include <bits/stdc++.h>
// using namespace std;
// const int mod = 998244353;
//
// int mo(int x) {
//    return (x % mod + mod) % mod;
//}
//
// signed main() {
//    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, m, d;
//        cin >> n >> m >> d;
//        int d_ = (int)sqrt(d * d - 1);
//        vector<vector<char>> a(n + 1, vector<char>(m + 1));
//        for (int i = 1; i <= n; i++)
//            for (int j = 1; j <= m; j++)
//                cin >> a[i][j];
//        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
//        vector<vector<int>> sum(n + 1, vector<int>(m + 1));
//        for (int i = 1; i <= m; i++) {
//            if (a[n][i] == 'X') dp[n][i] = 1;
//            sum[n][i] = (sum[n][i - 1] + dp[n][i]) % mod;
//        }
//        for (int i = 1; i <= m; i++) {
//            if (a[n][i] == 'X') {
//                dp[n][i] = mo(sum[n][min(m, i + d)] - sum[n][max(0, i - d - 1)]);
//            }
//        }
//        for (int i = 1; i <= m; i++) sum[n][i] = (sum[n][i - 1] + dp[n][i]) % mod;
//
//        for (int i = n - 1; i >= 1; i--) {
//            for (int j = 1; j <= m; j++) {
//                if (a[i][j] == 'X') {
//                    dp[i][j] = mo(sum[i + 1][min(m, j + d_)] - sum[i + 1][max(0, j - d_ - 1)]);
//                }
//                sum[i][j] = (sum[i][j - 1] + dp[i][j]) % mod;
//            }
//            for (int j = 1; j <= m; j++) {
//                if (a[i][j] == 'X') {
//                    dp[i][j] = mo(sum[i][min(m, j + d)] - sum[i][max(0, j - d - 1)]);
//                }
//            }
//            for (int j = 1; j <= m; j++) {
//                sum[i][j] = (sum[i][j - 1] + dp[i][j]) % mod;
//            }
//        }
//        cout << sum[1][m] << endl;
//    }
//    return 0;
//}

// 2025.8.3
// 219. P1642 规划
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 110;
// const double eps = 1e-4;
//
// vector<int> g[N];
// double w[N], c[N];
// double dp[N][N];
// int n, m;
// double mid;
//
// void dfs(int u, int fa) {
//    dp[u][1] = w[u] - mid * c[u];
//    for (int v : g[u]) {
//        if (v == fa) continue;
//        dfs(v, u);
//        for (int i = m; i >= 1; i--) {
//            for (int k = 1; k <= i - 1; k++) {
//                dp[u][i] = max(dp[u][i], dp[u][i - k] + dp[v][k]);
//            }
//        }
//    }
//}
//
// signed main() {
//    cin >> n >> m;
//    m = n - m;
//    for (int i = 1; i <= n; i++) cin >> w[i];
//    for (int i = 1; i <= n; i++) cin >> c[i];
//    for (int i = 1; i < n; i++) {
//        int u, v;
//        cin >> u >> v;
//        g[u].emplace_back(v);
//        g[v].emplace_back(u);
//    }
//    double l = 0, r = 1e6;
//    while (r - l > eps) {
//        mid = (l + r) / 2;
//        for (int i = 1; i <= n; i++)
//            for (int j = 0; j <= m; j++)
//                dp[i][j] = -1e9;
//        dfs(1, 0);
//        double maxn = -1e9;
//        for (int i = 1; i <= n; i++) maxn = max(maxn, dp[i][m]);
//        if (maxn >= 0) l = mid;
//        else r = mid;
//    }
//    printf("%.1lf", mid);
//    return 0;
//}

// 220. P5663 [CSP-J2019] 加工零件
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int n, m, Q;
//    cin >> n >> m >> Q;
//    vector<vector<int>> g(n + 1);
//    for (int i = 1; i <= m; i++) {
//        int u, v;
//        cin >> u >> v;
//        g[u].emplace_back(v);
//        g[v].emplace_back(u);
//    }
//    vector<vector<int>> dist(n + 1, vector<int>(2, -1));
//    queue<int> q;
//    dist[1][0] = 0;
//    q.emplace(1);
//    while (!q.empty()) {
//        int x = q.front();
//        q.pop();
//        int d_ji = dist[x][0] != -1 ? dist[x][0] + 1 : -1;
//        int d_ou = dist[x][1] != -1 ? dist[x][1] + 1 : -1;
//        for (int v : g[x]) {
//            if (d_ji != -1 && dist[v][1] == -1) {
//                dist[v][1] = d_ji;
//                q.push(v);
//            }
//            if (d_ou != -1 && dist[v][0] == -1) {
//                dist[v][0] = d_ou;
//                q.push(v);
//            }
//        }
//    }
//    while (Q--) {
//        int a, l;
//        cin >> a >> l;
//        if (dist[a][l & 1] != -1 && dist[a][l & 1] <= l) {
//            cout << "Yes" << endl;
//        } else cout << "No" << endl;
//    }
//    return 0;
//}

// 221. P5662 [CSP-J2019] 纪念品
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 10010;
//
// signed main() {
//    int t, n, m;
//    cin >> t >> n >> m;
//    vector<vector<int>> a(t + 1, vector<int>(n + 1));
//    for (int i = 1; i <= t; i++)
//        for (int j = 1; j <= n; j++)
//            cin >> a[i][j];
//    int ans = m;
//    for (int i = 1; i <= t - 1; i++) {
//        vector<int> dp(N, -1e9);
//        dp[0] = ans;
//        for (int j = 1; j <= n; j++) {
//            for (int v = a[i][j]; v <= ans; v++) {
//                dp[v] = max(dp[v], dp[v - a[i][j]] + a[i + 1][j] - a[i][j]);
//            }
//        }
//        int mx = -1;
//        for (int j = 0; j <= ans; j++) mx = max(mx, dp[j]);
//        ans = mx;
//    }
//    cout << ans << endl;
//    return 0;
//}

// 222. https://codeforces.com/problemset/problem/2067/B
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) {
//            int x;
//            cin >> x;
//            a[x]++;
//        }
//        bool yes = true;
//        for (int i = 1; i <= n; i++) {
//            if (a[i] == 1) {
//                yes = false;
//                break;
//            }
//            if (a[i] >= 2) a[i + 1] += a[i] - 2;
//        }
//        if (yes) cout << "YES" << endl;
//        else cout << "NO" << endl;
//    }
//    return 0;
//}

// 223. https://www.luogu.com.cn/problem/CF2065C1   https://codeforces.com/contest/2065/problem/C2
// #include <bits/stdc++.h>
// using namespace std;
// const int inf = 2e9;
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, m;
//        cin >> n >> m;
//        vector<int> a(n + 1), b(m + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        for (int i = 1; i <= m; i++) cin >> b[i];
//        sort(b.begin() + 1, b.end());
//        vector<int> dp(n + 1, inf);
//        dp[1] = min(a[1], b[1] - a[1]);
//        bool yes = true;
//        for (int i = 2; i <= n; i++) {
//            auto it = lower_bound(b.begin() + 1, b.end(), dp[i - 1] + a[i]);
//            if (it != b.end()) dp[i] = *it - a[i];
//            if (a[i] >= dp[i - 1]) dp[i] = min(dp[i], a[i]);
//            if (dp[i] == inf) {
//                yes = false;
//                break;
//            }
//        }
//        if (yes) cout << "YES" << endl;
//        else cout << "NO" << endl;
//    }
//    return 0;
//}

// 224. https://www.luogu.com.cn/problem/CF2107C
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int inf = 1e18;
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, k;
//        cin >> n >> k;
//        vector<int> a(n + 1);
//        string s;
//        cin >> s;
//        s = ' ' + s;
//        int id = -1;
//        for (int i = 1; i <= n; i++) {
//            cin >> a[i];
//            if (s[i] == '0') {
//                a[i] = -1e9;
//                id = i;
//            }
//        }
//        auto calc = [&]() -> int {
//            vector<int> dp(n + 1);
//            dp[1] = a[1];
//            for (int i = 2; i <= n; i++) dp[i] = max(dp[i - 1] + a[i], a[i]);
//            int res = -inf;
//            for (int i = 1; i <= n; i++) res = max(res, dp[i]);
//            return res;
//        };
//        if (id == -1) {
//            int c = calc();
//            if (c == k) {
//                cout << "Yes" << endl;
//                for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
//            }
//            else cout << "No" << endl;
//        } else {
//            int l = -inf, r = inf;
//            while (l <= r) {
//                int mid = (l + r) >> 1;
//                a[id] = mid;
//                int c = calc();
//                if (c >= k) r = mid - 1;
//                else l = mid + 1;
//            }
//            a[id] = r + 1;
//            int c = calc();
//            if (c == k) {
//                cout << "Yes" << endl;
//                for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
//            }
//            else cout << "No" << endl;
//        }
//    }
//    return 0;
//}

// 2025.8.4
// 225. https://www.luogu.com.cn/problem/CF2064C
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        vector<int> qian(n + 1), hou(n + 2);
//        for (int i = 1; i <= n; i++) {
//            if (a[i] > 0) qian[i] = qian[i - 1] + a[i];
//            else qian[i] = qian[i - 1];
//        }
//        for (int i = n; i >= 1; i--) {
//            if (a[i] < 0) hou[i] = hou[i + 1] - a[i];
//            else hou[i] = hou[i + 1];
//        }
//        int ans = 0;
//        for (int i = 0; i <= n; i++) ans = max(ans, qian[i] + hou[i + 1]);
//        cout << ans << endl;
//    }
//    return 0;
//}

// 226. https://www.luogu.com.cn/problem/CF2049D
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, m, k;
//        cin >> n >> m >> k;
//        vector<vector<int>> a(n + 1, vector<int>(m + 1)), mn(n + 1, vector<int>(m + 1, 1e18));
//        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(m + 1, 1e18)));
//        for (int i = 1; i <= n; i++)
//            for (int j = 1; j <= m; j++)
//                cin >> a[i][j];
//        for (int i = 0; i < m; i++) {
//            dp[1][1][i] = a[1][i + 1] + i * k;
//            mn[1][1] = min(mn[1][1], dp[1][1][i]);
//        }
//        for (int i = 1; i <= n; i++) {
//            for (int j = 1; j <= m; j++) {
//                if (i == 1 && j == 1) continue;
//                for (int l = 0; l < m; l++) {
//                    int x = a[i][(j + l == m ? m : (j + l) % m)] + k * l;
//                    dp[i][j][l] = min(dp[i][j - 1][l] + x - k * l, mn[i - 1][j] + x);
//                    mn[i][j] = min(mn[i][j], dp[i][j][l]);
//                }
//            }
//        }
//        cout << mn[n][m] << endl;
//    }
//    return 0;
//}

// 227. https://www.luogu.com.cn/problem/CF2044G2
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<vector<int>> g(n + 1);
//        vector<int> du(n + 1);
//        for (int i = 1; i <= n; i++) {
//            int u;
//            cin >> u;
//            du[u]++;
//            g[i].emplace_back(u);
//        }
//        int ans = 0;
//        vector<int> zi(n + 1, 1);
//        queue<int> q;
//        for (int i = 1; i <= n; i++) {
//            if (du[i] == 0) q.push(i);
//        }
//        while (!q.empty()) {
//            int u = q.front();
//            q.pop();
//            ans = max(ans, zi[u]);
//            for (int v : g[u]) {
//                zi[v] += zi[u];
//                du[v]--;
//                if (du[v] == 0) q.push(v);
//            }
//        }
//        cout << ans + 2 << endl;
//    }
//    return 0;
//}

// 228. https://www.luogu.com.cn/problem/CF2044G1   上一题的easy version
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<vector<int>> g(n + 1);
//        vector<int> cen(n + 1, 1), du(n + 1);
//        for (int i = 1; i <= n; i++) {
//            int x;
//            cin >> x;
//            g[i].emplace_back(x);
//            du[x]++;
//        }
//        int ans = 0;
//        queue<int> q;
//        for (int i = 1; i <= n; i++)
//            if (du[i] == 0) q.emplace(i);
//        while (!q.empty()) {
//            int x = q.front();
//            q.pop();
//            ans = max(ans, cen[x]);
//            for (int i : g[x]) {
//                cen[i] = cen[x] + 1;
//                du[i]--;
//                if (du[i] == 0) q.emplace(i);
//            }
//        }
//        cout << ans + 2 << endl;
//    }
//    return 0;
//}

// 2025.8.5
// 229. https://www.luogu.com.cn/problem/CF2106E
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, q;
//        cin >> n >> q;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        unordered_map<int, int> mp;
//        for (int i = 1; i <= n; i++) mp[a[i]] = i;
//        while (q--) {
//            int l, r, k;
//            cin >> l >> r >> k;
//            if (mp[k] < l || mp[k] > r) cout << -1 << ' ';
//            else {
//                int xiao = 0, da = 0, xu_xiao = 0, xu_da = 0;
//                while (l <= r) {
//                    int mid = (l + r) >> 1;
//                    if (a[mid] == k) break;
//                    else if (a[mid] > k) {
//                        if (mid < mp[k]) {
//                            l = mid + 1;
//                            xu_xiao++;
//                        } else {
//                            da++;
//                            r = mid - 1;
//                        }
//                    } else {
//                        if (mid < mp[k]) {
//                            l = mid + 1;
//                            xiao++;
//                        } else {
//                            r = mid - 1;
//                            xu_da++;
//                        }
//                    }
//                }
//                if (xu_xiao + xiao <= k - 1 && xu_da + da <= n - k) {
//                    cout << 2 * max(xu_xiao, xu_da) << ' ';
//                } else cout << -1 << ' ';
//            }
//        }
//        cout << endl;
//    }
//    return 0;
//}

// 2025.8.6
// 230. https://www.luogu.com.cn/problem/CF2106F
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        string s;
//        cin >> s;
//        s = " " + s;
//        long long up = 0, down = 0, ans = 0;
//        for (int i = 1; i <= n; i++) {
//            if (s[i] == '1') {
//                up = down + 1;
//                down = 0;
//            } else {
//                up += i - 1;
//                down += n - i;
//            }
//            ans = max(ans, max(up, down));
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 231. https://codeforces.com/contest/2068/problem/J
// #include <bits/stdc++.h>
// using namespace std;

// signed main()
// {
//     int T;
//     cin >> T;
//     while (T--)
//     {
//         int n;
//         cin >> n;
//         string s;
//         cin >> s;
//         s = " " + s;
//         int cntw = 0;
//         for (int i = 1; i <= n; i++)
//             cntw += (s[i] == 'W');
//         if (cntw & 1)
//             cout << "NO" << endl;
//         else
//         {
//             cntw /= 2;
//             bool yes = true;
//             for (int i = 1; i <= cntw; i++)
//             {
//                 if (s[i] != 'W')
//                 {
//                     yes = false;
//                     break;
//                 }
//             }
//             for (int i = 2 * n; i > 2 * n - cntw && yes; i--)
//             {
//                 if (s[i] != 'R')
//                 {
//                     yes = false;
//                     break;
//                 }
//             }
//             if (yes)
//                 cout << "YES" << endl;
//             else
//                 cout << "NO" << endl;
//         }
//     }
//     return 0;
// }


// 2025.8.7
// 232. https://www.luogu.com.cn/problem/CF2111B
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 100;

// signed main()
// {
//     int T;
//     cin >> T;
//     vector<int> fib(N);
//     fib[1] = 1, fib[2] = 2;
//     for (int i = 3; i < N; i++)
//         fib[i] = fib[i - 1] + fib[i - 2];
//     while (T--)
//     {
//         int n, m;
//         cin >> n >> m;
//         string ans;
//         for (int i = 0; i < m; i++)
//         {
//             int w, l, h;
//             cin >> w >> l >> h;
//             int mi = min(w, min(l, h));
//             int mx = max(w, max(l, h));
//             if (mi >= fib[n] && mx >= fib[n + 1])
//                 ans += '1';
//             else
//                 ans += '0';
//         }
//         cout << ans << endl;
//     }
//     return 0;
// }

// 233. AcWing 6480. Tree Tree 的
//#include <bits/stdc++.h>
//using namespace std;
//const int N = 11;
//
//vector<int> a(N);
//set<int> g[N];
//int d1, d2;
//
//void dfs(int u, int dist) {
//    a[u] = dist;
//    for (int v : g[u]) {
//        if (a[v]) {
//            int d = a[u] - a[v] + 1;
//            if (d > d1) d2 = d1, d1 = d;
//            else if (d < d1 && d > d2) d2 = d;
//        } else {
//            dfs(v, dist + 1);
//        }
//    }
//    a[u] = 0;
//}
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, m;
//        cin >> n >> m;
//        d1 = 1, d2 = 0;
//        while (m--) {
//            int u, v;
//            cin >> u >> v;
//            d1 = 2, d2 = 1;
//            g[u].emplace(v), g[v].emplace(u);
//        }
//        for (int i = 1; i <= n; i++) dfs(i, 1);
//        cout << d1 << ' ' << d2 << endl;
//    }
//    return 0;
//}

// 234. AcWing 6481. 游戏设计师
//#include <bits/stdc++.h>
//using namespace std;
//
//struct node {
//    int x, y;
//    int s;
//    node(int _x, int _y, int _s) : x(_x), y(_y), s(_s) {}
//};
//
//const int N = 1010;
//int a[N][N];
//int ans[N][N][3];
//
//signed main() {
//    memset(ans, -1, sizeof ans);
//    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
//    int n, m;
//    cin >> n >> m;
//    int x_, y_;
//    string temp;
//    for (int i = 1; i <= n; i++) {
//        cin >> temp;
//        for (int j = 1; j <= m; j++) {
//            a[i][j] = temp[j - 1] - '0';
//            if (a[i][j] == 3) x_ = i, y_ = j;
//        }
//    }
//    auto fu = [&](int x, int y, int s) -> bool {
//        if (!(x >= 1 && x <= n && y >= 1 && y <= m)) return false;
//        if (ans[x][y][s] != -1) return false;
//        if (s == 0) return a[x][y] == 1;
//        if (s == 1) return a[x][y] >= 1 && a[x][y + 1] >= 1;
//        if (s == 2) return a[x][y] >= 1 && a[x + 1][y] >= 1;
//    };
//    queue<node> q;
//    q.emplace(x_, y_, 0);
//    ans[x_][y_][0] = 0;
//    while (!q.empty()) {
//        node no = q.front();
//        q.pop();
//        if (no.s == 0) {
//            if (fu(no.x - 2, no.y, 2)) {
//                ans[no.x - 2][no.y][2] = ans[no.x][no.y][no.s] + 1;
//                q.emplace(no.x - 2, no.y, 2);
//            }
//            if (fu(no.x + 1, no.y, 2)) {
//                ans[no.x + 1][no.y][2] = ans[no.x][no.y][no.s] + 1;
//                q.emplace(no.x + 1, no.y, 2);
//            }
//            if (fu(no.x, no.y - 2, 1)) {
//                ans[no.x][no.y - 2][1] = ans[no.x][no.y][no.s] + 1;
//                q.emplace(no.x, no.y - 2, 1);
//            }
//            if (fu(no.x, no.y + 1, 1)) {
//                ans[no.x][no.y + 1][1] = ans[no.x][no.y][no.s] + 1;
//                q.emplace(no.x, no.y + 1, 1);
//            }
//        } else if (no.s == 1) {
//            if (fu(no.x + 1, no.y, 1)) {
//                ans[no.x + 1][no.y][1] = ans[no.x][no.y][no.s] + 1;
//                q.emplace(no.x + 1, no.y, 1);
//            }
//            if (fu(no.x - 1, no.y, 1)) {
//                ans[no.x - 1][no.y][1] = ans[no.x][no.y][no.s] + 1;
//                q.emplace(no.x - 1, no.y, 1);
//            }
//            if (fu(no.x, no.y - 1, 0)) {
//                ans[no.x][no.y - 1][0] = ans[no.x][no.y][no.s] + 1;
//                q.emplace(no.x, no.y - 1, 0);
//            }
//            if (fu(no.x, no.y + 2, 0)) {
//                ans[no.x][no.y + 2][0] = ans[no.x][no.y][no.s] + 1;
//                q.emplace(no.x, no.y + 2, 0);
//            }
//        } else {
//            if (fu(no.x - 1, no.y, 0)) {
//                ans[no.x - 1][no.y][0] = ans[no.x][no.y][no.s] + 1;
//                q.emplace(no.x - 1, no.y, 0);
//            }
//            if (fu(no.x + 2, no.y, 0)) {
//                ans[no.x + 2][no.y][0] = ans[no.x][no.y][no.s] + 1;
//                q.emplace(no.x + 2, no.y, 0);
//            }
//            if (fu(no.x, no.y - 1, 2)) {
//                ans[no.x][no.y - 1][2] = ans[no.x][no.y][no.s] + 1;
//                q.emplace(no.x, no.y - 1, 2);
//            }
//            if (fu(no.x, no.y + 1, 2)) {
//                ans[no.x][no.y + 1][2] = ans[no.x][no.y][no.s] + 1;
//                q.emplace(no.x, no.y + 1, 2);
//            }
//        }
//    }
//    int T;
//    cin >> T;
//    while (T--) {
//        int x, y, s;
//        cin >> x >> y >> s;
//        cout << ans[x][y][s] << endl;
//    }
//    return 0;
//}

// 2025.8.8
// 235. P7074 [CSP-J2020] 方格取数
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//	int n, m;
//	cin >> n >> m;
//	vector<vector<int>> a(n + 1, vector<int>(m + 1));
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			cin >> a[i][j];
//		}
//	}
//	vector<vector<vector<int>>> dp(n + 2, vector<vector<int>>(m + 2, vector<int>(2, -1e18)));
//	dp[0][1][0] = 0;
//	for (int i = 1; i <= n; i++) dp[i][1][0] = dp[i - 1][1][0] + a[i][1];
//	for (int j = 2; j <= m; j++) {
//		for (int i = 1; i <= n; i++) {
//			dp[i][j][0] = dp[i][j][1] = max(dp[i][j - 1][0], dp[i][j - 1][1]) + a[i][j];
//		}
//		for (int i = 1; i <= n; i++) {
//			dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][0] + a[i][j]);
//		}
//		for (int i = n; i >= 1; i--) {
//			dp[i][j][1] = max(dp[i][j][1], dp[i + 1][j][1] + a[i][j]);
//		}
//	}
//	cout << dp[n][m][0] << endl;
//	return 0;
//}

// 236. AcWing 327. 玉米田
//#include <bits/stdc++.h>
//using namespace std;
//const int N = 14, mod = 1e8;
//
//int he[1 << N], cnt;
//int hang[N];
//int ans[N][1 << N];
//
//signed main() {
//	int n, m;
//	cin >> n >> m;
//	for (int i = 0; i < 1 << m; i++) {
//		if (!(i & (i >> 1))) he[cnt++] = i;
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = m - 1; j >= 0; j--) {
//			int x;
//			cin >> x;
//			hang[i] |= (x << j);
//		}
//	}
//	ans[0][0] = 1;
//	for (int i = 1; i <= n + 1; i++) {
//		for (int j = 0; j < cnt; j++) {
//			if ((he[j] & hang[i]) == he[j]) {
//				for (int k = 0; k < cnt; k++) {
//					if (!(he[j] & he[k])) {
//						ans[i][j] = (ans[i][j] + ans[i - 1][k]) % mod;
//					}
//				}
//			}
//		}
//	}
//	cout << ans[n + 1][0] << endl;
//	return 0;
//}


// VP Educational Codeforces Round 176 (Rated for Div. 2)
// 237. https://www.luogu.com.cn/problem/CF2075A
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//	int T;
//	cin >> T;
//	while (T--) {
//		int n, k;
//		cin >> n >> k;
//		if (n & 1) {
//			n -= k;
//			int ans = ((n + k - 2) / (k - 1)) + 1;
//			cout << ans << endl;
//		} else {
//			int ans = ((n + k - 2) / (k - 1));
//			cout << ans << endl;
//		}
//	}
//	return 0;
//}

// 238. https://www.luogu.com.cn/problem/CF2075B
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, k;
//        cin >> n >> k;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        if (k == 1) {
//            int ans = a[1] + a[n];
//            int mx = max(a[1], a[n]);
//            for (int i = 2; i < n; i++) ans = max(ans, mx + a[i]);
//            cout << ans << endl;
//        } else {
//            sort(a.begin() + 1, a.end(), greater<>());
//            int ans = 0;
//            for (int i = 1; i <= k + 1; i++) ans += a[i];
//            cout << ans << endl;
//        }
//    }
//    return 0;
//}

// 239. https://www.luogu.com.cn/problem/CF2075C
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, m;
//        cin >> n >> m;
//        vector<int> a(m + 1);
//        for (int i = 1; i <= m; i++) cin >> a[i];
//        sort(a.begin() + 1, a.end());
//        int ans = 0;
//        for (int i = 1; i <= n / 2; i++) {
//            int da = a.end() - lower_bound(a.begin() + 1, a.end(), n - i);
//            if (i != n - i)
//                ans += max(da * (da - 1), 0LL);
//            else
//                ans += max(da * (da - 1) / 2, 0LL);
//            int xiao = lower_bound(a.begin() + 1, a.end(), n - i) - lower_bound(a.begin() + 1, a.end(), i);
//            ans += max(xiao * da, 0LL);
//        }
//        cout << 2 * ans << endl;
//    }
//    return 0;
//}

// 240. https://codeforces.com/contest/2075/problem/D
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//const int N = 63;
//
//int dp[N][N], base[N];
//
//void init() {
//    for (int i = 0; i < N; i++)
//        for (int j = 0; j < N; j++) dp[i][j] = 1e18;
//    dp[0][0] = 0;
//    base[0] = 1;
//    for (int i = 1; i < N; i++) base[i] = base[i - 1] * 2;
//    for (int k = 0; k < N; k++) {
//        for (int i = N - 1; i >= 0; i--) {
//            for (int j = N - 1; j >= 0; j--) {
//                if (i >= k) dp[i][j] = min(dp[i][j], dp[i - k][j] + base[k]);
//                if (j >= k) dp[i][j] = min(dp[i][j], dp[i][j - k] + base[k]);
//            }
//        }
//    }
//}
//
//signed main() {
//    init();
//    int T;
//    cin >> T;
//    while (T--) {
//        int x, y;
//        cin >> x >> y;
//        int ans = 1e18;
//        for (int i = 0; i < N; i++) {
//            for (int j = 0; j < N; j++) {
//                if ((x >> i) == (y >> j)) {
//                    ans = min(ans, dp[i][j]);
//                }
//            }
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 2025.8.9
// 241. https://www.luogu.com.cn/problem/CF2086D
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//const int mod = 998244353;
//const int N = 5e5 + 10;
//
//int fact[N];
//
//int ksm(int a, int k) {
//    int res = 1;
//    while (k) {
//        if (k & 1) res = res * a % mod;
//        a = a * a % mod;
//        k >>= 1;
//    }
//    return res;
//}
//
//void init() {
//    fact[0] = 1;
//    for (int i = 1; i < N; i++) fact[i] = fact[i - 1] * i % mod;
//}
//
//signed main() {
//    init();
//    int T;
//    cin >> T;
//    while (T--) {
//        vector<int> a(27);
//        int sum = 0;
//        for (int i = 1; i <= 26; i++) cin >> a[i], sum += a[i];
//        vector<int> dp(sum + 1);
//        dp[0] = 1;
//        for (int i = 1; i <= 26; i++) {
//            if (a[i]) {
//                for (int j = sum; j >= a[i]; j--) {
//                    dp[j] = (dp[j] + dp[j - a[i]]) % mod;
//                }
//            }
//        }
//        int ans = dp[sum / 2] * fact[sum / 2] % mod * fact[(sum + 1) / 2] % mod;
//        for (int i = 1; i <= 26; i++) {
//            ans = ans * ksm(fact[a[i]], mod - 2) % mod;
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 242. https://www.luogu.com.cn/problem/CF2043D
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//int l, r, g;
//
//void solve() {
//    int len = r - l;
//    while (len >= 0) {
//        for (int i = l; i + len <= r; i++) {
//            if (gcd(i, i + len) == 1) {
//                cout << i * g << ' ' << (i + len) * g << endl;
//                return;
//            }
//        }
//        len--;
//    }
//    cout << -1 << ' ' << -1 << endl;
//}
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        cin >> l >> r >> g;
//        l = (l + g - 1) / g, r = r / g;
//        solve();
//    }
//    return 0;
//}

// 243. https://www.luogu.com.cn/problem/AT_arc137_a
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//int l, r;
//
//void solve() {
//    int len = r - l;
//    while (len > 0) {
//        for (int i = l; i + len <= r; i++) {
//            if (gcd(i, i + len) == 1) {
//                cout << len << endl;
//                return;
//            }
//        }
//        len--;
//    }
//}
//
//signed main() {
//    cin >> l >> r;
//    solve();
//    return 0;
//}

// 244. https://www.luogu.com.cn/problem/CF2043C
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int idx = 0;
//        int n;
//        cin >> n;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) {
//            cin >> a[i];
//            if (abs(a[i]) != 1) {
//                idx = i;
//            }
//        }
//        if (idx == 0) {
//            for (int i = 1; i <= n; i++) a[i] += a[i - 1];
//            int mx = 0, mi = 0;
//            int xiao = 1e9, da = -1e9;
//            for (int i = 1; i <= n; i++) {
//                mi = min(mi, a[i]);
//                mx = max(mx, a[i]);
//                xiao = min(xiao, a[i] - mx);
//                da = max(da, a[i] - mi);
//            }
//            cout << da - xiao + 1 << endl;
//            for (int i = xiao; i <= da; i++) cout << i << " \n"[i == da];
//        } else {
//            vector<int> sum(n + 1);
//            for (int i = 1; i < idx; i++) sum[i] = sum[i - 1] + a[i];
//            for (int i = idx + 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
//            int mx = 0, mi = 0;
//            int xiao = 1e9, da = -1e9;
//            for (int i = 1; i < idx; i++) {
//                mi = min(mi, sum[i]);
//                mx = max(mx, sum[i]);
//                xiao = min(xiao, sum[i] - mx);
//                da = max(da, sum[i] - mi);
//            }
//            mx = 0, mi = 0;
//            for (int i = idx + 1; i <= n; i++) {
//                mi = min(mi, sum[i]);
//                mx = max(mx, sum[i]);
//                xiao = min(xiao, sum[i] - mx);
//                da = max(da, sum[i] - mi);
//            }
//            set<int> ans;
//            ans.insert(0);
//            for (int i = xiao; i <= da; i++) ans.insert(i);
//            xiao = 0, da = 0;
//            for (int i = idx - 2; i >= 0; i--) {
//                xiao = min(xiao, sum[idx - 1] - sum[i]);
//                da = max(da, sum[idx - 1] - sum[i]);
//            }
//            int xiao1 = 0, da1 = 0;
//            for (int i = idx + 1; i <= n; i++) {
//                xiao1 = min(xiao1, sum[i] - sum[idx]);
//                da1 = max(da1, sum[i] - sum[idx]);
//            }
//            xiao = xiao + xiao1;
//            da = da + da1;
//            for (int i = xiao; i <= da; i++) ans.insert(i + a[idx]);
//            cout << ans.size() << endl;
//            for (int i : ans) cout << i << ' ';
//            cout << endl;
//        }
//    }
//    return 0;
//}

// 245. https://www.luogu.com.cn/problem/CF2043B
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, d;
//        cin >> n >> d;
//        cout << 1 << ' ';
//        if (d % 3 == 0 || n >= 3) cout << 3 << ' ';
//        if (d == 5) cout << 5 << ' ';
//        if (d == 7 || n >= 3) cout << 7 << ' ';
//        if (d == 9 || (d % 3 == 0 && n >= 3) || n >= 6) cout << 9 << ' ';
//        cout << endl;
//    }
//    return 0;
//}

// 2025.8.10
// 246. P9753 [CSP-S 2023] 消消乐   小蓝题，不过如此哈哈哈哈哈
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int n;
//    cin >> n;
//    string s;
//    cin >> s;
//    s = " " + s;
//    vector<int> dp(n + 1), len(n + 1);
//    for (int i = 2; i <= n; i++) {
//        if (s[i] == s[i - 1]) {
//            dp[i] = 1;
//            len[i] = 2;
//            dp[i] += dp[i - len[i]];
//        } else {
//            int id = i - 1;
//            while (id > 0 && len[id] != 0 && s[id - len[id]] != s[i]) id = id - len[id];
//            if (s[id - len[id]] == s[i]) {
//                len[i] = 1 + i - id + len[id];
//                dp[i] = 1 + dp[id - len[id] - 1];
//            }
//        }
//    }
//    int ans = 0;
//    for (int i = 1; i <= n; i++) ans += dp[i];
//    cout << ans << endl;
//    return 0;
//}

// 247. P11233 [CSP-S 2024] 染色
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        unordered_map<int, int> mp;
//        int n;
//        cin >> n;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        vector<int> s(n + 1);
//        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i] * (a[i] == a[i - 1]);
//        vector<int> dp(n + 1);
//        for (int i = 1; i <= n; i++) {
//            dp[i] = dp[i - 1];
//            if (mp[a[i]]) dp[i] = max(dp[i], dp[mp[a[i]] + 1] + a[i] + s[i] - s[mp[a[i]] + 1]);
//            mp[a[i]] = i;
//        }
//        cout << dp[n] << endl;
//    }
//    return 0;
//}

// 248. https://www.luogu.com.cn/problem/CF2042B
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        unordered_map<int, int> mp;
//        for (int i = 1; i <= n; i++) {
//            int x;
//            cin >> x;
//            mp[x]++;
//        }
//        int ans = 0;
//        int cnt = 0;
//        for (int i = 1; i <= n; i++) {
//            if (mp[i] == 1) {
//                cnt++;
//            }
//        }
//        int qu = (n + 1) / 2 - (cnt + 1) / 2;
//        ans = (cnt + 1) / 2 * 2;
//        for (int i = 1; i <= n; i++) {
//            if (mp[i] > 1 && qu) {
//                ans++;
//                qu--;
//            }
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

//249. https://codeforces.com/contest/2042/problem/C
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, k;
//        cin >> n >> k;
//        string s;
//        cin >> s;
//        vector<int> sum(n + 1);
//        for (int i = 1; i <= n; i++) {
//            sum[i] = sum[i - 1] + (s[i - 1] == '1' ? 1 : -1);
//        }
//        vector<int> a;
//        for (int i = 1; i < n; i++) {
//            a.push_back(sum[n] - sum[i]);
//        }
//        sort(a.begin(), a.end(), greater<>());
//        a.push_back(-1e9);
//        int ans = 1, mx = 0;
//        for (int i : a) {
//            if (mx >= k) {
//                cout << ans << endl;
//                break;
//            } else {
//                mx += i;
//                ans++;
//            }
//        }
//        if (mx < k) cout << -1 << endl;
//    }
//    return 0;
//}

// 代码太多了，换一个文件继续。。。   ————2025.8.10
// 现在重新整理了，所以还是同一个文件里 ————2026.2.1
//
// Created by MINEC on 2025/8/10.
//

// 250. https://www.luogu.com.cn/problem/CF2042D
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<pair<int, int>> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
//        vector<int> id(n + 1);
//        iota(id.begin() + 1, id.end(), 1);
//        sort(id.begin() + 1, id.end(), [&](int i1, int i2) {
//            return a[i1] < a[i2];
//        });
//        vector<int> ans(n + 1);
//        int to = 1;
//        multiset<int> s;
//        for (int i = 1; i <= n; i++) {
//            int l = a[id[i]].first, r = a[id[i]].second;
//            for (; to <= n; to++) {
//                if (a[id[to]].first <= l) {
//                    s.insert(a[id[to]].second);
//                } else break;
//            }
//            s.erase(s.find(r));
//            auto r_ = s.lower_bound(r);
//            if (r_ == s.end()) ans[id[i]] = -1e9;
//            else ans[id[i]] = *r_;
//            s.insert(r);
//        }
//        iota(id.begin() + 1, id.end(), 1);
//        sort(id.begin() + 1, id.end(), [&](int i1, int i2) {
//            return a[i1].second > a[i2].second;
//        });
//        s.clear();
//        to = 1;
//        for (int i = 1; i <= n; i++) {
//            int l = a[id[i]].first, r = a[id[i]].second;
//            for (; to <= n; to++) {
//                if (a[id[to]].second >= r) {
//                    s.insert(a[id[to]].first);
//                } else break;
//            }
//            s.erase(s.find(l));
//            auto r_ = s.upper_bound(l);
//            if (r_ == s.begin()) ans[id[i]] = 0;
//            else {
//                r_--;
//                ans[id[i]] = max(0LL, ans[id[i]] - *r_ - r + l);
//            }
//            s.insert(l);
//        }
//        for (int i = 1; i <= n; i++) cout << ans[i] << endl;
//    }
//    return 0;
//}

// 2025.8.11
// 251. https://www.luogu.com.cn/problem/CF2026B
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        int l = 1, r = 1e18;
//        auto check = [&](int mid) -> bool {
//            if (n == 1) return true;
//            int d = a[1] + mid;
//            int duo = 0;
//            for (int i = 2; i <= n; i++) {
//                int cnt = 0;
//                if (i <= n && a[i] <= d) {
//                    cnt++;
//                    i++;
//                }
//                if (cnt == 0) duo++;
//                if (i < n) d = a[i] + mid;
//                else if (i == n) duo++;
//            }
//            return duo <= 1;
//        };
//        while (l <= r) {
//            int mid = (l + r) >> 1;
//            if (check(mid)) r = mid - 1;
//            else l = mid + 1;
//        }
//        cout << r + 1 << endl;
//    }
//    return 0;
//}

// 252. https://www.luogu.com.cn/problem/CF2026C
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        string s;
//        cin >> s;
//        s = " " + s;
//        int ans = n * (n + 1) / 2;
//        set<int> s1, s0;
//        for (int i = 1; i <= n; i++) {
//            if (s[i] == '1') s1.insert(i);
//            else s0.insert(i);
//        }
//        for (int i = n; i >= 1; i--) {
//            if (s[i] == '0') {
//                if (s0.find(i) != s0.end()) s0.erase(i);
//            } else {
//                if (s1.find(i) == s1.end()) break;
//                else s1.erase(s1.find(i));
//                if (!s0.empty()) {
//                    ans -= i;
//                    s0.erase(*s0.rbegin());
//                } else if (!s1.empty()) {
//                    ans -= i;
//                    s1.erase(*s1.begin());
//                }
//            }
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 253. https://www.luogu.com.cn/problem/CF2026D
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int n;
//    cin >> n;
//    vector<int> a(n + 1);
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    vector<int> sum1(n + 1), sum2(n + 1);
//    for (int i = 1; i <= n; i++) {
//        sum1[i] = sum1[i - 1] + a[i];
//        sum2[i] = sum2[i - 1] + sum1[i];
//    }
//    vector<int> duan(n + 1);
//    for (int i = 1; i <= n; i++) duan[i] = sum2[n] - sum2[i - 1] - (n - i + 1) * sum1[i - 1];
//    for (int i = 1; i <= n; i++) duan[i] += duan[i - 1];
//    int q;
//    cin >> q;
//    while (q--) {
//        int l, r;
//        cin >> l >> r;
//        auto calc = [&](int x) -> int {
//            int le = 0, ri = n;
//            while (le <= ri) {
//                int mid = (le + ri) >> 1;
//                if (mid * n - mid * (mid - 1) / 2 <= x) le = mid + 1;
//                else ri = mid - 1;
//            }
//            int mid = le - 1;
//            int res = duan[mid];
//            int shen = x - (mid * n - mid * (mid - 1) / 2);
//            mid++;
//            if (shen) {
//                res += sum2[mid + shen - 1] - sum2[mid - 1] - shen * sum1[mid - 1];
//            }
//            return res;
//        };
//        cout << calc(r) - calc(l - 1) << endl;
//    }
//    return 0;
//}

// 2025.8.12
// 254. https://codeforces.com/contest/2025/problem/B
//#include <bits/stdc++.h>
//using namespace std;
//const int mod = 1e9 + 7;
//const int N = 1e5 + 10;
//
//int base[N];
//
//signed main() {
//    base[0] = 1;
//    for (int i = 1; i < N; i++) base[i] = 2 * base[i - 1] % mod;
//    int n;
//    cin >> n;
//    vector<int> a(n + 1);
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    for (int i = 1; i <= n; i++) {
//        int x;
//        cin >> x;
//        if (x == a[i]) cout << 1 << endl;
//        else cout << base[x] << endl;
//    }
//    return 0;
//}

// 255. https://www.luogu.com.cn/problem/CF2025C
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, k;
//        cin >> n >> k;
//        map<int, int> mp;
//        for (int i = 1; i <= n; i++) {
//            int x;
//            cin >> x;
//            mp[x]++;
//        }
//        int duan = 0;
//        int ans = 0;
//        int shang = -1;
//        int temp = 0;
//        for (auto & [x, cnt] : mp) {
//            if (shang == -1) {
//                duan = 1;
//                temp = cnt;
//            } else {
//                 if (x == shang + 1) {
//                    duan++;
//                    if (duan > k) {
//                       duan = k;
//                       temp = temp + cnt - mp[x - k];
//                    } else {
//                        temp += cnt;
//                    }
//                } else {
//                    duan = 1;
//                    temp = cnt;
//                }
//            }
//            ans = max(ans, temp);
//            shang = x;
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

//256. https://www.luogu.com.cn/problem/CF2025D
//#include <bits/stdc++.h>
//using namespace std;
//const int N = 5010;
//
//int trfu[N], trzheng[N];
//
//void add(int tr[], int x, int y) {
//    for (int i = x; i < N; i += i & -i)
//        tr[i] += y;
//}
//
//int sum(const int tr[], int x) {
//    int res = 0;
//    for (int i = x; i; i -= i & -i)
//        res += tr[i];
//    return res;
//}
//
//signed main() {
//    int n, m;
//    cin >> n >> m;
//    vector<int> a(n + 1);
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    vector<vector<int>> dp(2, vector<int>(m + 2));
//    int dang = 0;
//    int id = n;
//    int ans = 0;
//    for (int i = n; i >= 1; i--) {
//        if (a[i] > 0) {
//            add(trzheng, a[i], 1);
//        } else if (a[i] < 0) {
//            add(trfu, -a[i], 1);
//        } else {
//            auto& dp1 = dp[dang];
//            auto& dp2 = dp[dang ^ 1];
//            dang ^= 1;
//            for (int j = 0; j <= m; j++) {
//                dp1[j] = max(dp2[j + 1], dp2[j]) + sum(trzheng, j) + sum(trfu, m - j);
//                ans = max(ans, dp1[j]);
//            }
//            m--;
//            for (; id >= i; id--) {
//                if (a[id] > 0) add(trzheng, a[id], -1);
//                else if (a[id] < 0) add(trfu, -a[id], -1);
//            }
//        }
//    }
//    cout << ans << endl;
//    return 0;
//}

// 2025.8.13
// VP Educational Codeforces Round 169 (Rated for Div. 2)
// https://codeforces.com/contest/2004
// 257. A
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        if (n == 2 && (a[2] - a[1]) >= 2) cout << "YES" << endl;
//        else cout << "NO" << endl;
//    }
//    return 0;
//}

// 258. B
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int l, r, L, R;
//        cin >> l >> r >> L >> R;
//        if (r < L || R < l) cout << 1 << endl;
//        else {
//            if (l > L) swap(l, L), swap(r, R);
//            if (l == L) {
//                if (R != r) cout << min(R - L, r - l) + 1 << endl;
//                else cout << r - L << endl;
//            } else {
//                if (R > r) cout << r - L + 2 << endl;
//                else if (R == r) cout << r - L + 1 << endl;
//                else cout << R - L + 2 << endl;
//            }
//        }
//    }
//    return 0;
//}

// 259. C
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, k;
//        cin >> n >> k;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        sort(a.begin() + 1, a.end());
//        for (int i = n - 1; i >= 1; i -= 2) {
//            if (a[i] + k >= a[i + 1]) {
//                k -= a[i + 1] - a[i];
//                a[i] = a[i + 1];
//            } else {
//                a[i] += k;
//                k = 0;
//                break;
//            }
//        }
//        int ans = 0, op = 1;
//        for (int i = n; i >= 1; i--) {
//            ans += op * a[i];
//            op = -op;
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 260. D
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//const int inf = 1e18;
//
//signed main() {
//    vector<string> str = {"GR", "BG", "BR", "RY", "BY", "GY"};
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, q;
//        cin >> n >> q;
//        unordered_map<string, vector<int>> g;
//        unordered_map<int, string> mp;
//        for (int i = 1; i <= n; i++) {
//            string s;
//            cin >> s;
//            g[s].emplace_back(i);
//            mp[i] = s;
//        }
//        auto keda = [&](string s1, string s2) {
//            if (s1[0] == s2[0] || s1[0] == s2[1]) return true;
//            if (s1[1] == s2[0] || s1[1] == s2[1]) return true;
//            return false;
//        };
//        while (q--) {
//            int x, y;
//            cin >> x >> y;
//            if (keda(mp[x], mp[y])) cout << abs(x - y) << endl;
//            else {
//                if (x > y) swap(x, y);
//                int ans = inf;
//                for (string& s : str) {
//                    if (s != mp[x] && keda(s, mp[x])) {
//                        if (g[s].empty()) continue;
//                        auto it = lower_bound(g[s].begin(), g[s].end(), x);
//                        if (it != g[s].end())
//                            ans = min(ans, abs(x - *it) + abs(y - *it));
//                        if (it != g[s].begin()) {
//                            it--;
//                            ans = min(ans, abs(x - *it) + abs(y - *it));
//                        }
//                        it = lower_bound(g[s].begin(), g[s].end(), y);
//                        if (it != g[s].end())
//                            ans = min(ans, abs(x - *it) + abs(y - *it));
//                        if (it != g[s].begin()) {
//                            it--;
//                            ans = min(ans, abs(x - *it) + abs(y - *it));
//                        }
//                    }
//                }
//                if (ans != inf)
//                    cout << ans << endl;
//                else cout << -1 << endl;
//            }
//        }
//    }
//    return 0;
//}

//261. https://www.luogu.com.cn/problem/CF2004E   E
//#include <bits/stdc++.h>
//using namespace std;
//const int N = 1e7 + 10;
//
//int primes[N], cnt, sg[N], mi_p[N];
//bool vis[N];
//
//void init() {
//    for (int i = 2; i < N; i++) {
//        if (!vis[i]) {
//            primes[cnt++] = i;
//            sg[i] = cnt;
//            mi_p[i] = i;
//        }
//        for (int j = 0; 1LL * primes[j] * i < N; j++) {
//            vis[primes[j] * i] = true;
//            mi_p[primes[j] * i] = primes[j];
//            if (i % primes[j] == 0) break;
//        }
//    }
//    sg[1] = 1, sg[2] = 0;
//    for (int i = 3; i < N; i++) {
//        if (mi_p[i] != i) {
//            sg[i] = sg[mi_p[i]];
//        }
//    }
//}
//
//signed main() {
//    init();
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        int ans = 0;
//        for (int i = 1; i <= n; i++) {
//            int x;
//            cin >> x;
//            ans ^= sg[x];
//        }
//        if (ans) cout << "Alice" << endl;
//        else cout << "Bob" << endl;
//    }
//    return 0;
//}

// 262. https://www.acwing.com/file_system/file/content/whole/index/content/3843/
// AcWing 292. 炮兵阵地
//#include <bits/stdc++.h>
//using namespace std;
//const int N = 11;
//
//int cnt1[1 << N], cnt;
//int hang[N * 10], he[1 << N];
//
//signed main() {
//    int n, m;
//    cin >> n >> m;
//    for (int i = 0; i < 1 << m; i++) {
//        if ((i & (i >> 1)) == 0 && (i & (i >> 2)) == 0) {
//            he[cnt++] = i;
//            int x = i;
//            while (x) {
//                cnt1[i]++;
//                x -= x & -x;
//            }
//        }
//    }
//    for (int i = 1; i <= n; i++) {
//        string s;
//        cin >> s;
//        for (char j : s) hang[i] = hang[i] * 2 + (j == 'P');
//    }
//    int ans[n + 1][cnt + 1][cnt + 1];
//    memset(ans, 0, sizeof ans);
//    for (int i = 0; i < cnt; i++) {
//        if ((he[i] & hang[1]) == he[i]) {
//            ans[1][i][0] = cnt1[he[i]];
//        }
//    }
//    for (int i = 0; i < cnt && 2 <= n; i++) {
//        if ((he[i] & hang[2]) != he[i]) continue;
//        for (int j = 0; j < cnt; j++) {
//            if ((he[i] & he[j]) == 0) {
//                ans[2][i][j] = max(ans[2][i][j], ans[1][j][0] + cnt1[he[i]]);
//            }
//        }
//    }
//    for (int i = 3; i <= n; i++) {
//        for (int j = 0; j < cnt; j++) {
//            if ((he[j] & hang[i]) != he[j]) continue;
//            for (int k = 0; k < cnt; k++) {
//                if ((he[k] & hang[i - 1]) != he[k]) continue;
//                if ((he[k] & he[j]) != 0) continue;
//                for (int z = 0; z < cnt; z++) {
//                    if ((he[z] & hang[i - 2]) != he[z]) continue;
//                    if ((he[z] & he[j]) != 0) continue;
//                    if ((he[z] & he[k]) != 0) continue;
//                    ans[i][j][k] = max(ans[i][j][k], ans[i - 1][k][z] + cnt1[he[j]]);
//                }
//            }
//        }
//    }
//    int mx = 0;
//    for (int i = 0; i < cnt; i++) {
//        for (int j = 0; j < cnt; j++) {
//            mx = max(mx, ans[n][i][j]);
//        }
//    }
//    cout << mx << endl;
//    return 0;
//}

// 263. P1063 [NOIP 2006 提高组] 能量项链
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int n;
//    cin >> n;
//    vector<int> a(2 * n + 1);
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    for (int i = 1; i <= n; i++) a[i + n] = a[i];
//    n <<= 1;
//    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
//    for (int i = 1; i + 2 <= n; i++) dp[3][i] = a[i] * a[i + 1] * a[i + 2];
//    for (int i = 4; i <= n; i++) {
//        for (int j = 1; j + i - 1 <= n; j++) {
//            for (int k = j + 1; k < j + i - 1; k++) {
//                dp[i][j] = max(dp[i][j], dp[k - j + 1][j] + dp[j + i - k][k] + a[j] * a[k] * a[i + j - 1]);
//            }
//        }
//    }
//    int ans = 0;
//    int m = n / 2 + 1;
//    for (int i = 1; i + m - 1 <= n; i++) ans = max(ans, dp[m][i]);
//    cout << ans << endl;
//    return 0;
//}

// 2025.8.14
// VP https://codeforces.com/contest/1997   Educational Codeforces Round 168 (Rated for Div. 2)
// 264. A
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        string s;
//        cin >> s;
//        unordered_map<char, int> mp;
//        for (char c : s) mp[c]++;
//        char no;
//        for (no = 'a'; no <= 'z'; no++)
//            if (!mp[no]) break;
//        bool flag = false;
//        for (int i = 0; i < s.size() - 1; i++) {
//            if (s[i] == s[i + 1]) {
//                s.insert(s.begin() + i + 1, no);
//                flag = true;
//                break;
//            }
//        }
//        if (!flag) {
//            s += no;
//        }
//        cout << s << endl;
//    }
//    return 0;
//}

// 265. B
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<string> a(2);
//        for (int i = 0; i <= 1; i++) cin >> a[i], a[i] = " " + a[i];
//        int ans = 0;
//        for (int i = 2; i <= n - 1; i++) {
//            for (int j = 0; j <= 1; j++) {
//                if (a[j][i] == '.') {
//                    if (a[j][i - 1] == '.' && a[j][i + 1] == '.') {
//                        if (a[j ^ 1][i] == '.') {
//                            if (a[j ^ 1][i - 1] == 'x' && a[j ^ 1][i + 1] == 'x') {
//                                ans++;
//                            }
//                        }
//                    }
//                }
//            }
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 266. C
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        string s;
//        cin >> s;
//        s = " " + s;
//        stack<int> st;
//        int ans = 0;
//        for (int i = 1; i <= n; i++) {
//            if (s[i] == '_') {
//                if (st.empty()) {
//                    st.push(i);
//                } else {
//                    ans += i - st.top();
//                    st.pop();
//                }
//            } else {
//                if (s[i] == '(') st.push(i);
//                else {
//                    ans += i - st.top();
//                    st.pop();
//                }
//            }
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 267. D
//#include <bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 10;
//#define int long long
//
//int a[N];
//vector<int> g[N];
//
//bool dfs(int u, int fa, int xu) {
//    if (xu > 1000000000) return false;
//    if (g[u].size() == 1 && g[u][0] == fa)
//        return a[u] >= xu;
//    bool res = true;
//    for (int v : g[u]) {
//        if (v == fa) continue;
//        if (xu <= a[v]) res = (res && dfs(v, u, xu));
//        else res = (res && dfs(v, u, xu + xu - a[v]));
//    }
//    return res;
//}
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        for (int i = 1; i <= n; i++) g[i].clear();
//        for (int i = 2; i <= n; i++) {
//            int x;
//            cin >> x;
//            g[i].emplace_back(x);
//            g[x].emplace_back(i);
//        }
//        int l = a[1], r = 2e9;
//        while (l <= r) {
//            int mid = (l + r) >> 1;
//            if (dfs(1, 0, mid - a[1])) l = mid + 1;
//            else r = mid - 1;
//        }
//        cout << l - 1 << endl;
//    }
//    return 0;
//}

// 268. E
//#include <bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 10;
//
//int tr[N], mi[N], a[N];
//
//void add(int x, int y) {
//    for (int i = x; i < N; i += i & -i)
//        tr[i] += y;
//}
//
//int sum(int x) {
//    int res = 0;
//    for (int i = x; i; i -= i & -i)
//        res += tr[i];
//    return res;
//}
//
//signed main() {
//    int n, q;
//    cin >> n >> q;
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    for (int i = 1; i <= n; i++) {
//        int l = 1, r = N - 10;
//        while (l <= r) {
//            int mid = (l + r) >> 1;
//            if (sum(mid) < 1LL * mid * a[i]) r = mid - 1;
//            else l = mid + 1;
//        }
//        mi[i] = r + 1;
//        add(r + 1, 1);
//    }
//    while (q--) {
//        int i, x;
//        cin >> i >> x;
//        if (mi[i] <= x) cout << "YES" << endl;
//        else cout << "NO" << endl;
//    }
//    return 0;
//}

// 269. https://codeforces.com/contest/2046/problem/B
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        priority_queue<int, vector<int>, greater<>> q;
//        stack<int> st;
//        for (int i = 1; i <= n; i++) {
//            while (!st.empty() && st.top() > a[i]) {
//                q.emplace(st.top() + 1);
//                st.pop();
//            }
//            if (q.empty() || a[i] <= q.top()) st.push(a[i]);
//            else q.emplace(a[i] + 1);
//        }
//        vector<int> ans;
//        while (!st.empty()) {
//            ans.emplace_back(st.top());
//            st.pop();
//        }
//        reverse(ans.begin(), ans.end());
//        for (int i : ans) cout << i << ' ';
//        while (!q.empty()) {
//            cout << q.top() << ' ';
//            q.pop();
//        }
//        cout << endl;
//    }
//    return 0;
//}

// 270. https://www.luogu.com.cn/problem/CF2045B
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int n, d, s;
//    cin >> n >> d >> s;
//    n /= s, d /= s;
//    if (d == 0) cout << s << endl;
//    else {
//        if (n % 2 == 0) cout << min(2 * d * s, n * s);
//        else {
//            if (d + 1 >= n) cout << n * s << endl;
//            else {
//                for (int i = 3; i * i <= n; i++) {
//                    if (n % i == 0) {
//                        if (n - n / i <= d && n / i - 1 <= d) {
//                            cout << n * s << endl;
//                            return 0;
//                        }
//                        if (n - i <= d && i - 1 <= d) {
//                            cout << n * s << endl;
//                            return 0;
//                        }
//                    }
//                }
//                cout << min(2 * d * s, (n - 1) * s) << endl;
//            }
//        }
//    }
//    return 0;
//}

// 271. AcWing 5853. 骰子游戏
//#include <bits/stdc++.h>
//using namespace std;
//
//int a[6], level;
//
//int calc_level() {
//    vector<int> a_(6);
//    for (int i = 1; i <= 5; i++) a_[i] = a[i];
//    sort(a_.begin() + 1, a_.end());
//    set<int> s(a_.begin() + 1, a_.end());
//    if (a_[1] == a_[5]) return 9;
//    if (a_[1] == a_[4] || a_[2] == a_[5]) return 8;
//    if ((a_[1] == a_[2] && a_[3] == a_[5]) || (a_[1] == a_[3] && a_[4] == a_[5])) return 7;
//    if (s.size() == 5 && a_[1] == 2) return 6;
//    if (s.size() == 5 && a_[5] == 5) return 5;
//    if (a_[1] == a_[3] || a_[2] == a_[4] || a_[3] == a_[5]) return 4;
//    if (s.size() == 3) return 3;
//    if (s.size() == 4) return 2;
//    return 1;
//}
//
//int dfs(int deep, int s) {
//    if (deep == 6) return calc_level() > level;
//    if (s >> (deep - 1) & 1) {
//        int cnt = 0, t = a[deep];
//        for (int i = 1; i <= 6; i++) {
//            a[deep] = i;
//            cnt += dfs(deep + 1, s);
//        }
//        a[deep] = t;
//        return cnt;
//    }
//    return dfs(deep + 1, s);
//}
//
//int cmp(int x, int y, int x1, int y1) {
//    if (x * y1 > x1 * y) return 1;
//    if (x * y1 == x1 * y) return 0;
//    return -1;
//}
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        for (int i = 1; i <= 5; i++) cin >> a[i];
//        level = calc_level();
//        int ma = 0, mb = 1, bian = 6;
//        for (int state = 0; state < 1 << 5; state++) {
//            int tot = 1, cnt = 0;
//            for (int i = 0; i < 5; i++)
//                if (state >> i & 1) {
//                    tot *= 6;
//                    cnt++;
//                }
//
//            int da = dfs(1, state);
//            int d = gcd(da, tot);
//            da /= d, tot /= d;
//            int c = cmp(da, tot, ma, mb);
//            if (c != -1) {
//                ma = da;
//                mb = tot;
//                if (c == 0) bian = min(bian, cnt);
//                else bian = cnt;
//            }
//        }
//        cout << bian << ' ' << ma << ' ' << mb << endl;
//    }
//    return 0;
//}

// 272. AcWing 5854. 相对论大师
//#include <bits/stdc++.h>
//using namespace std;
//
//unordered_map<string, vector<string>> g;
//unordered_map<string, bool> vis, end_;
//unordered_map<string, string> pre;
//vector<string> ans, temp, start;
//
//void bfs(string st, string ed) {
//    vis[st] = true;
//    queue<string> q;
//    q.emplace(st);
//    while (!q.empty()) {
//        string d = q.front();
//        q.pop();
//        if (d == ed) {
//            string u = ed;
//            while (u != st) {
//                temp.emplace_back(u);
//                u = pre[u];
//            }
//            temp.emplace_back(st);
//            if (temp.size() < ans.size() || ans.empty()) ans = temp;
//            return;
//        }
//        for (string s : g[d]) {
//            if (!vis[s]) {
//                vis[s] = true;
//                pre[s] = d;
//                q.emplace(s);
//            }
//        }
//    }
//}
//
//signed main() {
//    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
//    int n;
//    cin >> n;
//    for (int i = 1; i <= n; i++) {
//        string s1, s2;
//        char x1, x2;
//        cin >> s1 >> x1 >> s2 >> x2;
//        string S1 = s1 + " " + x1;
//        string S2 = s2 + " " + x2;
//        g[S1].emplace_back(S2);
//        start.emplace_back(S1);
//        end_[S2] = true;
//    }
//    for (string s : start) {
//        string ed = s;
//        if (s.back() == '0') ed.back() = '1';
//        else ed.back() = '0';
//        if (!end_[ed]) continue;
//        temp.clear();
//        vis.clear();
//        bfs(s, ed);
//    }
//    reverse(ans.begin(), ans.end());
//    cout << ans[0] << ' ';
//    for (int i = 1; i < ans.size() - 1; i++) cout << ans[i] << ' ' << ans[i] << ' ';
//    cout << ans.back() << ' ';
//    cout << "= " << ans[0] << ' ' << ans.back();
//    return 0;
//}

// 2025.8.15
// VP Educational Codeforces Round 166 (Rated for Div. 2)   https://codeforces.com/contest/1976
// 273. A
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        string s;
//        cin >> n >> s;
//        string s_ = s;
//        sort(s_.begin(), s_.end());
//        if (s_ == s) cout << "YES" << endl;
//        else cout << "NO" << endl;
//    }
//    return 0;
//}

// 274. B
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1), b(n + 2);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        for (int i = 1; i <= n + 1; i++) cin >> b[i];
//        int ans = 0;
//        int last = 1000000000;
//        for (int i = 1; i <= n; i++) {
//            ans += abs(a[i] - b[i]);
//            if (a[i] > b[i]) swap(a[i], b[i]);
//            if (a[i] <= b[n + 1] && b[n + 1] <= b[i]) last = 1;
//            else {
//                last = min(last, 1 + abs(b[n + 1] - b[i]));
//                last = min(last, 1 + abs(b[n + 1] - a[i]));
//            }
//        }
//        cout << ans + last << endl;
//    }
//    return 0;
//}

// 275. C   赛时写的100多行代码，写了1个多小时，还好过了
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//const int N = 2e5 + 10;
//
//int a[N], b[N];
//struct node {
//    int l, r;
//    int quana, quanb, a, b, suma, sumb;
//} tr[N << 2];
//
//void pushup(int u) {
//    tr[u].quana = tr[u << 1].quana + tr[u << 1 | 1].quana;
//    tr[u].quanb = tr[u << 1].quanb + tr[u << 1 | 1].quanb;
//    tr[u].a = tr[u << 1].a + tr[u << 1 | 1].a;
//    tr[u].b = tr[u << 1].b + tr[u << 1 | 1].b;
//    tr[u].suma = tr[u << 1].suma + tr[u << 1 | 1].suma;
//    tr[u].sumb = tr[u << 1].sumb + tr[u << 1 | 1].sumb;
//}
//
//void pushup(node& rt, node& zuo, node& you) {
//    rt.quana = zuo.quana + you.quana;
//    rt.quanb = zuo.quanb + you.quanb;
//    rt.a = zuo.a + you.a;
//    rt.b = zuo.b + you.b;
//    rt.suma = zuo.suma + you.suma;
//    rt.sumb = zuo.sumb + you.sumb;
//}
//
//void build(int u, int l, int r) {
//    tr[u] = {l, r};
//    if (l == r) {
//        if (a[l] > b[l]) {
//            tr[u].quana = 1;
//            tr[u].quanb = 0;
//            tr[u].a = a[l];
//            tr[u].b = 0;
//            tr[u].suma = 0;
//            tr[u].sumb = b[l];
//        } else {
//            tr[u].quana = 0;
//            tr[u].quanb = 1;
//            tr[u].b = b[l];
//            tr[u].a = 0;
//            tr[u].suma = a[l];
//            tr[u].sumb = 0;
//        }
//        return;
//    }
//    int mid = (l + r) >> 1;
//    build(u << 1, l, mid);
//    build(u << 1 | 1, mid + 1, r);
//    pushup(u);
//}
//
//node query(int u, int l, int r) {
//    if (r < l) return {0, 0, 0, 0, 0, 0};
//    if (l <= tr[u].l && tr[u].r <= r) return tr[u];
//    int mid = (tr[u].l + tr[u].r) >> 1;
//    if (r <= mid) return query(u << 1, l, r);
//    else if (l > mid) return query(u << 1 | 1, l, r);
//    else {
//        node res;
//        node zuo = query(u << 1, l, mid), you = query(u << 1 | 1, mid + 1, r);
//        pushup(res, zuo, you);
//        return res;
//    }
//}
//
//void modify(int u, int x, int op) {
//    if (tr[u].l == tr[u].r && tr[u].l == x) {
//        if (op == 1) {
//            if (a[x] > b[x]) {
//                tr[u].quana = 1;
//                tr[u].quanb = 0;
//                tr[u].a = a[x];
//                tr[u].b = 0;
//                tr[u].suma = 0;
//                tr[u].sumb = b[x];
//            } else {
//                tr[u].quana = 0;
//                tr[u].quanb = 1;
//                tr[u].b = b[x];
//                tr[u].a = 0;
//                tr[u].suma = a[x];
//                tr[u].sumb = 0;
//            }
//        } else {
//            tr[u].a = 0;
//            tr[u].b = 0;
//            tr[u].quana = 0;
//            tr[u].quanb = 0;
//            tr[u].suma = 0;
//            tr[u].sumb = 0;
//        }
//    } else {
//        int mid = (tr[u].l + tr[u].r) >> 1;
//        if (x <= mid) modify(u << 1, x, op);
//        else modify(u << 1 | 1, x, op);
//        pushup(u);
//    }
//}
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, m;
//        cin >> n >> m;
//        int suma = 0, sumb = 0;
//        for (int i = 1; i <= n + m + 1; i++) {
//            cin >> a[i];
//            suma += a[i];
//        }
//        for (int i = 1; i <= n + m + 1; i++) {
//            cin >> b[i];
//            sumb += b[i];
//        }
//        build(1, 1, n + m + 1);
//        for (int i = 1; i <= n + m + 1; i++) {
//            modify(1, i, -1);
//            suma -= a[i];
//            sumb -= b[i];
//            int l = 0, r = n + m + 1;
//            node x;
//            while (l <= r) {
//                int mid = (l + r) >> 1;
//                x = query(1, 1, mid);
//                if (x.quana >= n || x.quanb >= m) r = mid - 1;
//                else l = mid + 1;
//            }
//            x = query(1, 1, r + 1);
//            if (x.quana >= n) {
//                cout << x.a + sumb - x.sumb << ' ';
//            } else if (x.quanb >= m) {
//                cout << x.b + suma - x.suma << ' ';
//            }
//            modify(1, i, 1);
//            suma += a[i];
//            sumb += b[i];
//        }
//        cout << endl;
//    }
//    return 0;
//}

// 276. E   jiangly的做法！！！
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        string s;
//        cin >> s;
//        int n = s.size();
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) {
//            a[i] = a[i - 1] + (s[i - 1] == '(' ? 1 : -1);
//        }
//        vector<vector<int>> pos(n / 2 + 1);
//        for (int i = 0; i <= n; i++) pos[a[i]].emplace_back(i);
//        set<int> mx;
//        int j = n / 2, ans = 0;
//        for (int i = n / 2; i >= 0; i--) {
//            while (j > 2 * i) {
//                for (int x : pos[j]) mx.insert(x);
//                j--;
//            }
//            int cnt = 1;
//            for (int k = 1; k < pos[i].size(); k++) {
//                auto it = mx.lower_bound(pos[i][k - 1]);
//                if (it != mx.end() && *it < pos[i][k]) cnt = 0;
//                ans += cnt;
//                cnt++;
//            }
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 2025.8.16
// VP   Educational Codeforces Round 165 (Rated for Div. 2)   https://codeforces.com/contest/1969
// 277. A
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int ans = 3;
//        int n;
//        cin >> n;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        for (int i = 1; i <= n; i++) {
//            if (a[a[i]] == i) {
//                ans = 2;
//                break;
//            }
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 278. B
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        string s;
//        cin >> s;
//        int n = s.size();
//        s = " " + s;
//        int cnt = 0, ans = 0;
//        for (int i = 1; i <= n; i++) {
//            if (s[i] == '1') cnt++;
//            else ans += (cnt == 0 ? 0 : cnt + 1);
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 279. C
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, k;
//        cin >> n >> k;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1e18));
//        for (int i = 0; i <= k; i++) dp[1][i] = a[1], dp[0][i] = 0;
//        for (int i = 2; i <= n; i++) {
//            for (int j = 0; j <= k; j++) {
//                int mi = a[i];
//                for (int z = 0; z <= j && i - z >= 1; z++) {
//                    mi = min(mi, a[i - z]);
//                    dp[i][j] = min(dp[i - 1 - z][j - z] + mi * (z + 1), dp[i][j]);
//                }
//            }
//        }
//        cout << dp[n][k] << endl;
//    }
//    return 0;
//}

// 280.  D
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, k;
//        cin >> n >> k;
//        vector<int> a(n + 1), b(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        for (int i = 1; i <= n; i++) cin >> b[i];
//        int sum = 0, jian = 0;
//        priority_queue<pair<int, int>> q1, q2;
//        for (int i = 1; i <= n; i++) {
//            a[i] = b[i] - a[i];
//            if (a[i] >= 0) {
//                sum += a[i];
//                q1.push({b[i], a[i]});
//            }
//        }
//        while (k-- && !q1.empty()) {
//            auto t = q1.top();
//            q1.pop();
//            jian += t.first;
//            q2.push({-t.second + t.first, t.first});
//        }
//        int ans = max(0LL, sum - jian);
//        while (!q1.empty() && !q2.empty()) {
//            auto t1 = q1.top();
//            q1.pop();
//            auto t2 = q2.top();
//            q2.pop();
//            sum += t2.first - t2.second;
//            jian += t1.first - t2.second;
//            q2.push({-t1.second + t1.first, t1.first});
//            ans = max(ans, sum - jian);
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 2025.8.17
// 281. https://www.luogu.com.cn/problem/P2865   次短路
//#include <bits/stdc++.h>
//using namespace std;
//const int N = 5010;
//
//vector<pair<int, int>> g[N];
//
//signed main() {
//    int n, m;
//    cin >> n >> m;
//    for (int i = 1; i <= m; i++) {
//        int u, v, w;
//        cin >> u >> v >> w;
//        g[u].emplace_back(v, w);
//        g[v].emplace_back(u, w);
//    }
//    vector<vector<int>> dist(n + 1, vector<int>(2, 1e9));
//    priority_queue<pair<int, int>> q;
//    q.emplace(0, 1);
//    while (!q.empty()) {
//        auto d = q.top();
//        q.pop();
//        for (auto& [v, w] : g[d.second]) {
//            int dis = -d.first + w;
//            if (dis < dist[v][0]) {
//                swap(dist[v][0], dist[v][1]);
//                dist[v][0] = dis;
//                q.emplace(-dis, v);
//            } else if (dis > dist[v][0] && dis < dist[v][1]) {
//                dist[v][1] = dis;
//                q.emplace(-dis, v);
//            }
//        }
//    }
//    cout << dist[n][1] << endl;
//    return 0;
//}

// 282. https://www.luogu.com.cn/problem/CF1954C
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        vector<string> a(2);
//        cin >> a[0] >> a[1];
//        if (a[0] == a[1]) cout << a[0] << endl << a[1] << endl;
//        else {
//            int i = 0;
//            while (a[0][i] == a[1][i]) i++;
//            if (a[0][i] < a[1][i]) swap(a[0], a[1]);
//            for (i = i + 1; i < a[0].size(); i++) {
//                if (a[0][i] > a[1][i]) swap(a[0][i], a[1][i]);
//            }
//            cout << a[0] << endl << a[1] << endl;
//        }
//    }
//    return 0;
//}

// 283. https://www.luogu.com.cn/problem/CF1954D
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//const int mod = 998244353;
//
//signed main() {
//    int n, sum = 0;
//    cin >> n;
//    vector<int> a(n + 1);
//    for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
//    sort(a.begin() + 1, a.end());
//    vector<int> dp(sum + 1);
//    int ans = 0;
//    dp[0] = 1;
//    for (int i = 1; i <= n; i++) {
//        for (int j = 0; j <= sum; j++) {
//            if (j <= a[i]) ans = (ans + dp[j] * a[i]) % mod;
//            else ans = (ans + dp[j] * ((a[i] + j + 1) / 2)) % mod;
//        }
//        for (int j = sum; j >= a[i]; j--) {
//            dp[j] = (dp[j] + dp[j - a[i]]) % mod;
//        }
//    }
//    cout << ans << endl;
//    return 0;
//}

// 284. https://codeforces.com/contest/2130/problem/D
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        int ans = 0;
//        for (int i = 1; i <= n; i++) {
//            int x = 0, y = 0;
//            for (int j = 1; j < i; j++) x += (a[j] > a[i]);
//            for (int j = i + 1; j <= n; j++) y += (a[j] > a[i]);
//            ans += min(x, y);
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 2025.8.18
// 285. https://www.luogu.com.cn/problem/P1829   P1829 [国家集训队] Crash的数字表格 / JZPTAB
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//const int mod = 20101009, N = 1e7 + 10;
//
//int primes[N], cnt, vis[N], mu[N], S[N];
//
//void euler() {
//    mu[1] = 1;
//    for (int i = 2; i < N; i++) {
//        if (!vis[i]) {
//            primes[cnt++] = i;
//            mu[i] = -1;
//        }
//        for (int j = 0; i * primes[j] < N; j++) {
//            vis[i * primes[j]] = 1;
//            if (i % primes[j] == 0) break;
//            mu[i * primes[j]] = -mu[i];
//        }
//    }
//    for (int i = 1; i < N; i++) S[i] = (S[i - 1] + i * i * mu[i]) % mod;
//}
//
//int G(int n, int m) {
//    return (n * (n + 1) / 2) % mod * (m * (m + 1) / 2 % mod) % mod;
//}
//
//int F(int n, int m) {
//    int res = 0;
//    for (int l = 1, r = 0; l <= n; l = r + 1) {
//        int t1 = n / l, t2 = m / l;
//        r = min(n / t1, m / t2);
//        res += ((S[r] - S[l - 1]) % mod + mod) % mod * G(t1, t2) % mod;
//        res %= mod;
//    }
//    return res;
//}
//
//signed main() {
//    euler();
//    int n, m;
//    cin >> n >> m;
//    if (n > m) swap(n, m);
//    int ans = 0;
//    for (int l = 1, r = 0; l <= n; l = r + 1) {
//        int t1 = n / l, t2 = m / l;
//        r = min(n / t1, m / t2);
//        ans += ((l + r) * (r - l + 1) / 2) % mod * F(t1, t2) % mod;
//        ans %= mod;
//    }
//    cout << ans << endl;
//    return 0;
//}

// 286. P3704 [SDOI2017] 数字表格
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//const int N = 1e6 + 10, mod = 1e9 + 7;
//
//int primes[N], cnt, vis[N], mu[N], F[N], f[N];
//
//int ksm(int a, int k) {
//    int res = 1;
//    while (k) {
//        if (k & 1) res = res * a % mod;
//        a = a * a % mod;
//        k >>= 1;
//    }
//    return res;
//}
//
//void init() {
//    mu[1] = 1, f[1] = 1, F[0] = 1;
//    for (int i = 2; i < N; i++) {
//        if (!vis[i]) primes[cnt++] = i, mu[i] = -1;
//        for (int j = 0; primes[j] * i < N; j++) {
//            vis[primes[j] * i] = 1;
//            if (i % primes[j] == 0) break;
//            mu[i * primes[j]] = -mu[i];
//        }
//    }
//    for (int i = 2; i < N; i++) f[i] = (f[i - 1] + f[i - 2]) % mod, F[i - 1] = 1;
//    for (int i = 1; i < N; i++) {
//        for (int j = i; j < N; j += i) {
//            if (mu[j / i] == 0) continue;
//            F[j] = F[j] * (mu[j / i] == 1 ? f[i] : ksm(f[i], mod - 2)) % mod;
//        }
//    }
//    for (int i = 2; i < N; i++) F[i] = F[i - 1] * F[i] % mod;
//}
//
//int calc(int n, int m) {
//    if (n > m) swap(n, m);
//    int res = 1;
//    for (int l = 1, r; l <= n; l = r + 1) {
//        int t1 = n / l, t2 = m / l;
//        r = min(n / t1, m / t2);
//        res = res * ksm((F[r] * ksm(F[l - 1], mod - 2)) % mod, t1 * t2 % (mod - 1)) % mod;
//    }
//    return res;
//}
//
//signed main() {
//    init();
//    int t;
//    cin >> t;
//    while (t--) {
//        int n, m;
//        cin >> n >> m;
//        cout << calc(n, m) << endl;
//    }
//    return 0;
//}

// 287. https://www.luogu.com.cn/problem/CF1923A
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        int i = 1, j = n;
//        while (i <= n && a[i] == 0) i++;
//        while (j >= 1 && a[j] == 0) j--;
//        int ans = 0;
//        for (; i <= j; i++) ans += a[i] ^ 1;
//        cout << ans << endl;
//    }
//    return 0;
//}

// 288. https://www.luogu.com.cn/problem/CF1923C
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, q;
//        cin >> n >> q;
//        vector<int> a(n + 1), one(n + 1), sum(n + 1);
//        for (int i = 1; i <= n; i++) {
//            cin >> a[i];
//            one[i] = (a[i] == 1);
//            one[i] += one[i - 1];
//            sum[i] = sum[i - 1] + a[i];
//        }
//        while (q--) {
//            int l, r;
//            cin >> l >> r;
//            if (l == r) cout << "NO" << endl;
//            else {
//                int on = one[r] - one[l - 1], non = r - l + 1 - on;
//                if (on * 2 + non > sum[r] - sum[l - 1]) cout << "NO" << endl;
//                else cout << "YES" << endl;
//            }
//        }
//    }
//    return 0;
//}

// 289. https://www.luogu.com.cn/problem/CF1923D
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 2), sum(n + 1), qian(n + 2), hou(n + 2);
//        for (int i = 1; i <= n; i++) {
//            cin >> a[i];
//            sum[i] = a[i] + sum[i - 1];
//        }
//        qian[0] = -1, qian[1] = -1, hou[n + 1] = -1, hou[n] = -1;
//        for (int i = 2; i <= n; i++) {
//            if (a[i] == a[i - 1]) qian[i] = qian[i - 1];
//            else qian[i] = i - 1;
//        }
//        for (int i = n - 1; i >= 1; i--) {
//            if (a[i] == a[i + 1]) hou[i] = hou[i + 1];
//            else hou[i] = i + 1;
//        }
//        vector<int> ans(n + 1);
//        for (int i = 1; i <= n; i++) {
//            if (a[i - 1] > a[i] || a[i] < a[i + 1]) ans[i] = 1;
//            else {
//                int tmp1 = 1000000000, tmp2 = 1000000000;
//                auto it = lower_bound(sum.begin(), sum.begin() + i, sum[i - 1] - a[i]);
//                if (it != sum.begin()) {
//                    int id = it - sum.begin();
//                    if (qian[i - 1] != -1) tmp1 = i - min(qian[i - 1], id);
//                }
//                it = upper_bound(sum.begin() + i, sum.end(), a[i] + sum[i]);
//                if (it != sum.end()) {
//                    int id = it - sum.begin();
//                    if (hou[i + 1] != -1) tmp2 = max(hou[i + 1], id) - i;
//                }
//                ans[i] = min(tmp1, tmp2);
//                if (ans[i] == 1000000000) ans[i] = -1;
//            }
//        }
//        for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
//        cout << endl;
//    }
//    return 0;
//}

// 290. https://www.luogu.com.cn/problem/CF1923E
//#include <bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 10;
//#define int long long
//
//int a[N], ans;
//vector<int> g[N];
//
//unordered_map<int, int> dfs(int u, int fa) {
//    unordered_map<int, int> mp;
//    for (int v : g[u]) {
//        if (v == fa) continue;
//        unordered_map<int, int> mpz = dfs(v, u);
//        ans += mpz[a[u]];
//        mpz.erase(a[u]);
//        if (mpz.size() > mp.size()) swap(mp, mpz);
//        for (auto& [key, cnt] : mpz) {
//            ans += mp[key] * cnt;
//            mp[key] += cnt;
//        }
//    }
//    mp[a[u]] = 1;
//    return mp;
//}
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        ans = 0;
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        for (int i = 1; i <= n; i++) g[i].clear();
//        for (int i = 1; i < n; i++) {
//            int u, v;
//            cin >> u >> v;
//            g[u].emplace_back(v);
//            g[v].emplace_back(u);
//        }
//        dfs(1, 0);
//        cout << ans << endl;
//    }
//    return 0;
//}

// 291. https://www.luogu.com.cn/problem/CF2104C
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        string s;
//        cin >> s;
//        if (n == 2) {
//            if (s == "AB") cout << "Alice" << endl;
//            else cout << "Bob" << endl;
//            continue;
//        }
//        int A = 0, B = 0;
//        for (int i = 0; i < n; i++) {
//            A += (s[i] == 'A');
//            B += (s[i] == 'B');
//        }
//        if (B == 1 || (s[n - 1] == 'A' && s[n - 2] == 'A') || (s[n - 1] == 'A' && s[0] == 'A'))
//            cout << "Alice" << endl;
//        else cout << "Bob" << endl;
//    }
//    return 0;
//}

// 292. https://www.luogu.com.cn/problem/CF2104E
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int n, k;
//    cin >> n >> k;
//    string s;
//    cin >> s;
//    s = " " + s;
//    vector<int> a(n + 1, 1e9);
//    vector<vector<int>> mp(k);
//    for (int i = 1; i <= n; i++) mp[s[i] - 'a'].emplace_back(i);
//    vector<int> lst(k);
//    a[n] = 1, a[0] = 0, lst[s[n] - 'a'] = n;
//    for (int i = n - 1; i >= 1; i--) {
//        for (int j = 0; j < k; j++) a[i] = min(a[i], 1 + a[lst[j]]);
//        lst[s[i] - 'a'] = i;
//    }
//    int q;
//    cin >> q;
//    while (q--) {
//        cin >> s;
//        int mi = 0;
//        for (char c : s) {
//            auto it = upper_bound(mp[c - 'a'].begin(), mp[c - 'a'].end(), mi);
//            if (it == mp[c - 'a'].end()) {
//                mi = -1;
//                break;
//            } else {
//                mi = *it;
//            }
//        }
//        if (mi == -1) cout << 0 << endl;
//        else cout << a[mi] << endl;
//    }
//    return 0;
//}

// 293. https://www.luogu.com.cn/problem/CF2104B
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        vector<int> mx(n + 1);
//        for (int i = 1; i <= n; i++) mx[i] = max(mx[i - 1], a[i]);
//        int sum = 0;
//        for (int i = n; i >= 1; i--) {
//            cout << sum + mx[i] << ' ';
//            sum += a[i];
//        }
//        cout << endl;
//    }
//    return 0;
//}

// 294. https://www.luogu.com.cn/problem/CF2129A
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<pair<int, int>> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
//        vector<int> id(n + 1);
//        iota(id.begin(), id.end(), 0);
//        vector<int> ans;
//        sort(id.begin(), id.end(), [&](int l, int r) {
//            if (a[l].first != a[r].first) return a[l].first < a[r].first;
//            return a[l].second > a[r].second;
//        });
//        int r = 0;
//        for (int i = 1; i <= n; i++) {
//            if (a[id[i]].second > r) {
//                ans.emplace_back(id[i]);
//                r = a[id[i]].second;
//            }
//        }
//        sort(ans.begin(), ans.end());
//        cout << ans.size() << endl;
//        for (int i : ans) cout << i << ' ';
//        cout << endl;
//    }
//    return 0;
//}

// 295. https://www.luogu.com.cn/problem/CF2130B
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, s;
//        cin >> n >> s;
//        int n0 = 0, n1 = 0, n2 = 0, sum = 0;
//        for (int i = 1; i <= n; i++) {
//            int x;
//            cin >> x;
//            n0 += x == 0;
//            n1 += x == 1;
//            n2 += x == 2;
//            sum += x;
//        }
//        if (sum == s || s - sum >= 2) cout << -1 << endl;
//        else {
//            for (int i = 1; i <= n0; i++) cout << 0 << ' ';
//            for (int i = 1; i <= n2; i++) cout << 2 << ' ';
//            for (int i = 1; i <= n1; i++) cout << 1 << ' ';
//            cout << endl;
//        }
//    }
//    return 0;
//}

// 2025.8.21   VP Codeforces Round 1025 (Div. 2)   https://codeforces.com/contest/2109
// 296. A
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        if (n == 2) {
//            if (a[1] == 1 && a[2] == 1) cout << "YES" << endl;
//            else if (a[1] == 0 && a[2] == 0) cout << "YES" << endl;
//            else cout << "NO" << endl;
//        } else {
//            bool is_no = true;
//            int sum = 0;
//            for (int i = 1; i <= n; i++) sum += a[i];
//            for (int i = 1; i < n; i++) {
//                if (a[i] + a[i + 1] == 0) {
//                    is_no = false;
//                    break;
//                }
//            }
//            if (is_no && sum <= n - 1) cout << "NO" << endl;
//            else cout << "YES" << endl;
//        }
//    }
//    return 0;
//}

// 297. B
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, m, a, b;
//        cin >> n >> m >> a >> b;
//        int ans = 1;
//        int n_ = n, m_ = m;
//        n = min(n - a + 1, a);
//        while (n != 1) {
//            ans++;
//            n = (n + 1) / 2;
//        }
//        while (m != 1) {
//            ans++;
//            m = (m + 1) / 2;
//        }
//        int ans_ = ans;
//        ans = 1;
//        n = n_, m = min(m_ - b + 1, b);
//        while (n != 1) {
//            ans++;
//            n = (n + 1) / 2;
//        }
//        while (m != 1) {
//            ans++;
//            m = (m + 1) / 2;
//        }
//        cout << min(ans, ans_) << endl;
//    }
//    return 0;
//}

// 298. C1
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, x;
//        cin >> n;
//        cout << "digit" << endl;
//        cout.flush();
//        cin >> x;
//        cout << "digit" << endl;
//        cout.flush();
//        cin >> x;
//        int t = 8;
//        for (int i = 1; i <= 4; i++) {
//            cout << "add -" << t << endl;
//            cout.flush();
//            cin >> x;
//            t /= 2;
//        }
//        cout << "mul " << n << endl;
//        cout.flush();
//        cin >> x;
//        cout << "!" << endl;
//        cin >> x;
//    }
//    return 0;
//}

// 299. D
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//const int N = 2e5 + 10, inf = 1e18;
//
//vector<int> g[N];
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, m, l;
//        cin >> n >> m >> l;
//        for (int i = 1; i <= n; i++) g[i].clear();
//        int sum = 0, ji_mi = inf;
//        for (int i = 1; i <= l; i++) {
//            int x;
//            cin >> x;
//            sum += x;
//            if (x & 1) ji_mi = min(ji_mi, x);
//        }
//        int ji, ou;
//        if (sum & 1) ji = sum, ou = sum - ji_mi;
//        else ou = sum, ji = sum - ji_mi;
//        for (int i = 1; i <= m; i++) {
//            int u, v;
//            cin >> u >> v;
//            g[u].emplace_back(v);
//            g[v].emplace_back(u);
//        }
//        vector<vector<int>> dist(n + 1, vector<int>(2, inf));
//        queue<int> q;
//        q.push(1);
//        dist[1][0] = 0;
//        while (!q.empty()) {
//            int d = q.front();
//            q.pop();
//            for (int d_ : g[d]) {
//                int ji_d = (dist[d][0] == inf ? -1 : dist[d][0] + 1);
//                int ou_d = (dist[d][1] == inf ? -1 : dist[d][1] + 1);
//                if (ji_d != -1 && ji_d < dist[d_][1]) {
//                    dist[d_][1] = ji_d;
//                    q.emplace(d_);
//                }
//                if (ou_d != -1 && ou_d < dist[d_][0]) {
//                    dist[d_][0] = ou_d;
//                    q.emplace(d_);
//                }
//            }
//        }
//        for (int i = 1; i <= n; i++) {
//            if (dist[i][1] <= ji || dist[i][0] <= ou) cout << 1;
//            else cout << 0;
//        }
//        cout << endl;
//    }
//    return 0;
//}

// 300. https://www.luogu.com.cn/problem/CF2109C2   C2
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, x;
//        cin >> n;
//        cout << "mul 9" << endl;
//        cin >> x;
//        cout << "digit" << endl;
//        cin >> x;
//        cout << "digit" << endl;
//        cin >> x;
//        cout << "add " << n - 9 << endl;
//        cin >> x;
//        cout << "!" << endl;
//        cin >> x;
//    }
//    return 0;
//}

// 301. C3
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, x;
//        cin >> n;
//        cout << "mul 999999999" << endl;
//        cin >> x;
//        cout << "digit" << endl;
//        cin >> x;
//        if (n != 81) {
//            cout << "add " << n - 81 << endl;
//            cin >> x;
//        }
//        cout << "!" << endl;
//        cin >> x;
//    }
//    return 0;
//}

// 2025.8.22
// 302. https://www.luogu.com.cn/problem/CF2110C
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        vector<pair<int, int>> b(n + 1);
//        for (int i = 1; i <= n; i++) cin >> b[i].first >> b[i].second;
//        vector<int> mi(n + 1);
//        mi[n] = b[n].first;
//        for (int i = n - 1; i >= 1; i--) mi[i] = max(mi[i + 1] - (a[i + 1] != 0), b[i].first);
//        vector<int> h(n + 1);
//        h[0] = 0;
//        for (int i = 1; i <= n; i++) {
//            if (a[i] == -1) {
//                if (h[i - 1] < mi[i]) a[i] = 1;
//                else a[i] = 0;
//                h[i] = h[i - 1] + a[i];
//            } else {
//                h[i] = h[i - 1] + a[i];
//            }
//        }
//        bool no_ans = false;
//        for (int i = 1; i <= n; i++) {
//            if (h[i] < b[i].first || h[i] > b[i].second) {
//                no_ans = true;
//                break;
//            }
//        }
//        if (no_ans) cout << -1 << endl;
//        else for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
//    }
//    return 0;
//}

// 303. https://www.luogu.com.cn/problem/CF2110D
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//const int N = 2e5 + 10;
//
//vector<pair<int, int>> g[N];
//int a[N];
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, m;
//        cin >> n >> m;
//        for (int i = 1; i <= n; i++) g[i].clear();
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        for (int i = 1; i <= m; i++) {
//            int u, v, w;
//            cin >> u >> v >> w;
//            g[u].emplace_back(v, w);
//        }
//        vector<int> mi(n + 1, 1e18), su(n + 1);
//        mi[1] = 0, su[1] = a[1];
//        priority_queue<tuple<int, int, int>> q;
//        q.emplace(0, a[1], 1);
//        while (!q.empty()) {
//            auto [quan, sum, id] = q.top();
//            q.pop();
//            for (auto& [v, w] : g[id]) {
//                if (sum >= w) {
//                    int xin = max(w, -quan);
//                    if ((xin < mi[v] || sum + a[v] > su[v]) && xin < mi[n]) {
//                        mi[v] = min(mi[v], xin);
//                        su[v] = max(su[v], sum + a[v]);
//                        q.emplace(-xin, sum + a[v], v);
//                    }
//                }
//            }
//        }
//        if (mi[n] == 1e18) cout << -1 << endl;
//        else cout << mi[n] << endl;
//    }
//    return 0;
//}

// 304. https://www.luogu.com.cn/problem/CF2110B
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        string s;
//        cin >> s;
//        int n = s.size();
//        bool is_yes = false;
//        int sum = 0;
//        for (int i = 0; i < n - 1; i++) {
//            sum += (s[i] == '(' ? 1 : -1);
//            if (sum <= 0) is_yes = true;
//        }
//        if (is_yes) cout << "YES" << endl;
//        else cout << "NO" << endl;
//    }
//    return 0;
//}

// 2025.8.23   VP Educational Codeforces Round 161 (Rated for Div. 2)   https://codeforces.com/contest/1922
// 很不错，677名，差一题AK，继续努力！
// 305. A
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n; cin >> n;
//        string a, b, c;
//        cin >> a >> b >> c;
//        int fu = 0;
//        for (int i = 0; i < n; i++) {
//            fu += (a[i] == c[i] || b[i] == c[i]);
//        }
//        if (fu == n) cout << "NO" << endl;
//        else cout << "YES" << endl;
//    }
//    return 0;
//}

// 306. B
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        vector<int> mp(n + 1);
//        for (int i = 1; i <= n; i++) mp[a[i]]++;
//        int ans = 0;
//        for (int i = n; i >= 0; i--) {
//            if (mp[i] >= 2) {
//                ans += mp[i] * (mp[i] - 1) / 2 * (n - mp[i]);
//                if (mp[i] >= 3) {
//                    ans += mp[i] * (mp[i] - 1) / 2 * (mp[i] - 2) / 3;
//                }
//            }
//            n -= mp[i];
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 307. C
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 2);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        a[n + 1] = 1e9, a[0] = 1e9;
//        vector<int> zuo(n + 1), you(n + 1);
//        zuo[2] = a[2] - a[1] - 1;
//        for (int i = 3; i <= n; i++) {
//            if (a[i] - a[i - 1] < a[i - 1] - a[i - 2]) zuo[i] = a[i] - a[i - 1] - 1;
//            zuo[i] += zuo[i - 1];
//        }
//        you[n - 1] = a[n] - a[n - 1] - 1;
//        for (int i = n - 2; i >= 1; i--) {
//            if (a[i + 1] - a[i] < a[i + 2] - a[i + 1]) you[i] = a[i + 1] - a[i] - 1;
//            you[i] += you[i + 1];
//        }
//        int m;
//        cin >> m;
//        while (m--) {
//            int x, y;
//            cin >> x >> y;
//            if (x < y) cout << a[y] - a[x] - (zuo[y] - zuo[x]) << endl;
//            else cout << a[x] - a[y] - (you[y] - you[x]) << endl;
//        }
//    }
//    return 0;
//}

// 308. E
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int x;
//        cin >> x;
//        vector<int> ans;
//        int id = 1e9;
//        while (x != 2) {
//            if (x & 1) {
//                ans.emplace_back(1);
//                x--;
//            } else {
//                ans.emplace_back(id--);
//                x /= 2;
//            }
//        }
//        ans.emplace_back(1);
//        reverse(ans.begin(), ans.end());
//        cout << ans.size() << endl;
//        for (int i : ans) cout << i << ' ';
//        cout << endl;
//    }
//    return 0;
//}

// 309. D
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 2), d(n + 2);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        for (int i = 1; i <= n; i++) cin >> d[i];
//        vector<int> zuo(n + 2), you(n + 2);
//        for (int i = 1; i <= n; i++) {
//            zuo[i] = i - 1;
//            you[i] = i + 1;
//        }
//        vector<int> shan, vis(n + 2);
//        vis[0] = vis[n + 1] = 1;
//        for (int i = 1; i <= n; i++) {
//            if (a[zuo[i]] + a[you[i]] > d[i]) {
//                shan.emplace_back(i);
//                vis[i] = 1;
//            }
//        }
//        int cnt = 1;
//        cout << shan.size() << ' ';
//        while (!shan.empty()) {
//            set<int> s;
//            for (int i : shan) {
//                if (!vis[zuo[i]]) s.insert(zuo[i]);
//                if (!vis[you[i]]) s.insert(you[i]);
//                you[zuo[i]] = you[i];
//                zuo[you[i]] = zuo[i];
//            }
//            vector<int> sh;
//            for (int i : s) {
//                if (!vis[i]) {
//                    if (a[zuo[i]] + a[you[i]] > d[i]) {
//                        sh.emplace_back(i);
//                        vis[i] = 1;
//                    }
//                }
//            }
//            cout << sh.size() << ' ';
//            cnt++;
//            swap(sh, shan);
//        }
//        for (int i = 1; i <= n - cnt; i++) cout << 0 << ' ';
//        cout << endl;
//    }
//    return 0;
//}

// 2025.8.24
// 310. https://www.luogu.com.cn/problem/CF2128D
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        vector<int> dp(n + 1);
//        dp[1] = 1;
//        if (a[2] < a[1]) dp[2] = 3;
//        else dp[2] = 2;
//        for (int i = 3; i <= n; i++) {
//            if (a[i] < a[i - 1]) {
//                dp[i] = dp[i - 1] + i;
//            } else {
//                dp[i] = dp[i - 2] + i;
//            }
//        }
//        int ans = 0;
//        for (int i = 1; i <= n; i++) ans += dp[i];
//        cout << ans << endl;
//    }
//    return 0;
//}

// 311. https://www.luogu.com.cn/problem/CF2128E1
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, k;
//        cin >> n >> k;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        int l = 1, r = n;
//        auto check = [&](int mid) -> bool {
//            vector<int> sum(n + 1);
//            int mi = 1e9;
//            for (int i = 1; i <= n; i++) {
//                if (a[i] < mid) sum[i] = -1;
//                else sum[i] = 1;
//                sum[i] += sum[i - 1];
//                if (i >= k) {
//                    mi = min(sum[i - k], mi);
//                    if (sum[i] - mi >= 0) return true;
//                }
//            }
//            return false;
//        };
//        while (l <= r) {
//            int mid = (l + r) >> 1;
//            if (check(mid)) l = mid + 1;
//            else r = mid - 1;
//        }
//        int ans = l - 1;
//        cout << ans << ' ';
//        vector<int> sum(n + 1);
//        int mi = 1e9, mi_id = 0;
//        for (int i = 1; i <= n; i++) {
//            if (a[i] < ans) sum[i] = -1;
//            else sum[i] = 1;
//            sum[i] += sum[i - 1];
//            if (i >= k) {
//                if (mi > sum[i - k]) {
//                    mi = sum[i - k];
//                    mi_id = i - k + 1;
//                }
//                if (sum[i] - mi >= 0) {
//                    l = mi_id;
//                    r = i;
//                    break;
//                }
//            }
//        }
//        cout << l << ' ' << r << endl;
//    }
//    return 0;
//}

// 312. https://www.luogu.com.cn/problem/CF2127D
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//const int N = 2e5 + 10, mod = 1e9 + 7;
//
//int fact[N];
//
//void solve() {
//    int n, m;
//    cin >> n >> m;
//    vector<vector<int>> g(n + 1);
//    for (int i = 1; i <= m; i++) {
//        int u, v;
//        cin >> u >> v;
//        g[u].emplace_back(v);
//        g[v].emplace_back(u);
//    }
//    if (m != n - 1) cout << 0 << endl;
//    else {
//        int ans = 1;
//        function<int(int, int, int)> dfs;
//        dfs = [&](int u, int fa, int deep) -> int {
//            vector<int> du;
//            for (int v : g[u]) {
//                if (v != fa) {
//                    du.push_back(dfs(v, u, deep + 1));
//                }
//            }
//            sort(du.begin(), du.end(), greater<>());
//            if (deep == 1) {
//                if (du.size() <= 2) {
//                    ans = (int)du.size() * ans % mod;
//                } else {
//                    if (du[2] != 0) ans = 0;
//                    else {
//                        if (du[0] == 0) {
//                            ans = ans * fact[du.size()] % mod;
//                        } else if (du[1] == 0) {
//                            ans = 2 * ans * fact[du.size() - 1] % mod;
//                        } else {
//                            ans = 2 * ans * fact[du.size() - 2] % mod;
//                        }
//                    }
//                }
//            } else {
//                if (du.size() > 1) {
//                    if (du[1] == 0) {
//                        if (du[0] == 0) {
//                            ans = ans * fact[du.size()] % mod;
//                        } else {
//                            ans = ans * fact[du.size() - 1] % mod;
//                        }
//                    } else ans = 0;
//                }
//            }
//            return (int)du.size();
//        };
//        if (n == 2) ans = 1;
//        else {
//            int i = 1;
//            while (g[i].size() == 1) i++;
//            dfs(i, 0, 1);
//        }
//        cout << 2 * ans % mod << endl;
//    }
//}
//
//signed main() {
//    fact[0] = 1;
//    for (int i = 1; i < N; i++) fact[i] = i * fact[i - 1] % mod;
//    int T;
//    cin >> T;
//    while (T--) {
//        solve();
//    }
//    return 0;
//}

// 2025.8.25   VP Educational Codeforces Round 160 (Rated for Div. 2)
// 313. A
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        string s;
//        cin >> s;
//        int n = s.size();
//        if (s[0] == '0') {
//            cout << -1 << endl;
//            continue;
//        }
//        bool have_ans = false;
//        for (int i = 0; i < n - 1; i++) {
//            if (s[i + 1] != '0') {
//                string a = s.substr(0, i + 1);
//                string b = s.substr(i + 1, n - i - 1);
//                if (stoi(b) > stoi(a)) {
//                    cout << a << ' ' << b << endl;
//                    have_ans = true;
//                    break;
//                }
//            }
//        }
//        if (!have_ans) cout << -1 << endl;
//    }
//    return 0;
//}

// 314. B
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        string s;
//        cin >> s;
//        int n = s.size();
//        int cnt0 = 0, cnt1 = 0;
//        for (char c : s) {
//            cnt0 += c == '0';
//            cnt1 += c == '1';
//        }
//        int ans = 0;
//        for (int i = 0; i < n; i++) {
//            if (s[i] == '0') {
//                if (cnt1 == 0) {
//                    ans = n - i;
//                    break;
//                }
//                cnt1--;
//            } else {
//                if (cnt0 == 0) {
//                    ans = n - i;
//                    break;
//                }
//                cnt0--;
//            }
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 315. C
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int T;
//    cin >> T;
//    vector<int> a(31);
//    while (T--) {
//        int t, v;
//        cin >> t >> v;
//        if (t == 1) a[v]++;
//        else {
//            int x = 0;
//            bool have_ans = true;
//            for (int i = 0; i <= 30; i++) {
//                if (v >> i & 1) {
//                    if (a[i] + x >= 1) {
//                        x = (a[i] + x - 1) / 2;
//                    } else {
//                        have_ans = false;
//                        break;
//                    }
//                } else {
//                    x = (a[i] + x) / 2;
//                }
//            }
//            if (have_ans) cout << "YES" << endl;
//            else cout << "NO" << endl;
//        }
//    }
//    return 0;
//}

// 316. D
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//const int mod = 998244353;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        vector<vector<int>> dp(n + 1, vector<int>(2));
//        vector<int> sum(n + 1);
//        sum[0] = 1;
//        dp[0][1] = 1;
//        stack<int> st;
//        st.push(0);
//        for (int i = 1; i <= n; i++) {
//            while (a[st.top()] > a[i]) st.pop();
//            int p = st.top();
//            if (p) {
//                dp[i][0] = (dp[p][0] + dp[p][1]) % mod;
//                dp[i][1] = (sum[i - 1] - sum[p - 1] + dp[p][0] + mod) % mod;
//            } else {
//                dp[i][1] = sum[i - 1];
//            }
//            sum[i] = (sum[i - 1] + dp[i][1]) % mod;
//            st.push(i);
//        }
//        cout << (dp[n][0] + dp[n][1]) % mod << endl;
//    }
//    return 0;
//}

// 317. https://atcoder.jp/contests/abc420/tasks/abc420_g
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int x;
//    cin >> x;
//    x = 4 * x - 1;
//    set<int> ans;
//    for (int i = 1; i * i <= abs(x); i++) {
//        if (x % i == 0) {
//            int x_ = i, y_ = x / i;
//            if ((y_ - x_) % 2 == 0) {
//                int a = (y_ - x_) / 2;
//                a--;
//                if (a % 2 == 0) {
//                    ans.insert(a / 2);
//                }
//            }
//            swap(x_, y_);
//            if ((y_ - x_) % 2 == 0) {
//                int a = (y_ - x_) / 2;
//                a--;
//                if (a % 2 == 0) {
//                    ans.insert(a / 2);
//                }
//            }
//        }
//    }
//    cout << ans.size() << endl;
//    for (int i : ans) cout << i << ' ';
//    cout << endl;
//    return 0;
//}

// 2025.8.26 VP Educational Codeforces Round 159 (Rated for Div. 2)
// 318. A
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        string s;
//        cin >> s;
//        int cnt0 = 0, cnt1 = 0;
//        bool yes = false;
//        for (int i = 0; i < n - 1; i++) {
//            if (s[i] != s[i + 1]) {
//                yes = true;
//                break;
//            }
//            cnt0 += s[i] == '0';
//            cnt1 += s[i] == '1';
//        }
//        cnt0 += s[n - 1] == '0';
//        cnt1 += s[n - 1] == '1';
//        if (cnt0 > cnt1 || yes) cout << "YES" << endl;
//        else cout << "NO" << endl;
//    }
//    return 0;
//}

// 319. B
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, p, l, t;
//        cin >> n >> p >> l >> t;
//        int mx;
//        if (n >= 8) mx = (n - 8) / 14 + 1;
//        else mx = 0;
//        int cnt = (p + l + 2 * t - 1) / (l + 2 * t);
//        if (cnt <= mx) {
//            cout << n - cnt << endl;
//        } else {
//            int sum = 0;
//            cnt = mx;
//            p -= mx * (l + 2 * t);
//            int n_;
//            if (n >= 8) n_ = n - (8 + (n - 8) / 14 * 14);
//            else n_ = 7;
//            if (n_ >= 7) {
//                cnt++;
//                sum += l + t;
//            }
//            if (sum >= p) {
//                cout << n - cnt << endl;
//            } else {
//                if (n_ >= 7) p -= l + t;
//                cnt += (p + l - 1) / l;
//                cout << n - cnt << endl;
//            }
//        }
//    }
//    return 0;
//}

// 320. C
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1);
//        map<int, int> mp;
//        int mx = -1e9;
//        for (int i = 1; i <= n; i++) cin >> a[i], mp[a[i]]++, mx = max(mx, a[i]);
//        if (n == 1) cout << 1 << endl;
//        else {
//            int g = 0;
//            for (int i = 2; i <= n; i++) g = gcd(g, abs(a[i] - a[i - 1]));
//            int tar = mx;
//            int tmp = 0;
//            for (int i = 1; i <= n; i++) tmp += abs(a[i] - tar) / g;
//            int ans = tmp + n;
//            for (int i = 1; i < n; i++) {
//                if (!mp[mx - i * g]) {
//                    ans = min(ans, tmp + i);
//                    break;
//                }
//            }
//            cout << ans << endl;
//        }
//    }
//    return 0;
//}

// 321. E
//#include <bits/stdc++.h>
//using namespace std;
//using ll = long long;
//
//struct node {
//    int cnt = 0;
//    unordered_map<char, int> mp;
//};
//
//signed main() {
//    int n;
//    cin >> n;
//    vector<string> a(n + 1);
//    ll sum = 0;
//    for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i].size();
//    sum = sum * 2 * n;
//    vector<node> tr(1);
//    auto add = [&](const string& s) -> void {
//        int p = 0;
//        for (char c : s) {
//            if (!tr[p].mp[c]) {
//                tr[p].mp[c] = tr.size();
//                tr.emplace_back();
//                tr.back().cnt = 1;
//                p = tr[p].mp[c];
//            } else {
//                p = tr[p].mp[c];
//                tr[p].cnt++;
//            }
//        }
//    };
//    auto calc = [&](const string& s) -> void {
//        int p = 0;
//        int su = 0;
//        for (int i = s.size() - 1; i >= 0; i--) {
//            char c = s[i];
//            if (!tr[p].mp[c]) {
//                break;
//            } else {
//                p = tr[p].mp[c];
//                su += tr[p].cnt;
//            }
//        }
//        sum -= su * 2;
//    };
//    for (int i = 1; i <= n; i++) add(a[i]);
//    for (int i = 1; i <= n; i++) calc(a[i]);
//    cout << sum << endl;
//    return 0;
//}

// 2025.8.27   VP Educational Codeforces Round 158 (Rated for Div. 2)
// 322. A
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, x;
//        cin >> n >> x;
//        vector<int> a(n + 2);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        a[n + 1] = x;
//        int ans = 0;
//        for (int i = 1; i <= n + 1; i++) ans = max(ans, a[i] - a[i - 1]);
//        ans = max(2 * (a[n + 1] - a[n]), ans);
//        cout << ans << endl;
//    }
//    return 0;
//}

// 323. B
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        for (int i = n; i >= 1; i--) a[i] = a[i] - a[i - 1];
//        int ans = 0;
//        for (int i = 1; i <= n; i++) ans += max(0LL, a[i]);
//        cout << ans - 1 << endl;
//    }
//    return 0;
//}

// 324. C   https://www.luogu.com.cn/problem/CF1901C
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1);
//        int mx = 0, mi = 1e9;
//        for (int i = 1; i <= n; i++) cin >> a[i], mx = max(mx, a[i]), mi = min(mi, a[i]);
//        vector<int> ans;
//        while (mi != mx) {
//            int mi_ji = mi & 1, mx_ji = mx & 1;
//            if ((mi_ji && mx_ji) || (!mi_ji && !mx_ji) || (mx_ji && !mi_ji)) {
//                ans.push_back(0);
//                mi >>= 1;
//                mx >>= 1;
//            } else {
//                ans.push_back(1);
//                mi = (mi + 1) >> 1;
//                mx = (mx + 1) >> 1;
//            }
//        }
//        cout << ans.size() << endl;
//        if (ans.size() <= n) {
//            for (int i : ans) cout << i << ' ';
//            cout << endl;
//        }
//    }
//    return 0;
//}

// 325. D   https://www.luogu.com.cn/problem/CF1901D
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int n;
//    cin >> n;
//    vector<int> a(n + 1);
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    auto check = [&](int mid) {
//        int l = 0, r = n;
//        for (int i = 1; i <= n; i++) {
//            if (mid < a[i]) return false;
//            if (mid - i + 1 < a[i]) l = i;
//            if (mid - (n - i) < a[i]) r = min(r, i);
//        }
//        return (l <= r);
//    };
//    int l = 1, r = 1e18;
//    while (l <= r) {
//        int mid = (l + r) >> 1;
//        if (check(mid)) r = mid - 1;
//        else l = mid + 1;
//    }
//    cout << r + 1 << endl;
//    return 0;
//}

// 326. https://www.luogu.com.cn/problem/CF2131E
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1), b(n + 1), c(n + 1, -1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        for (int i = 1; i <= n; i++) cin >> b[i];
//        int yes = true;
//        for (int i = n; i >= 1; i--) {
//            if (i == n && a[i] != b[i]) {
//                yes = false;
//                break;
//            }
//            if (a[i] != b[i]) {
//                c[i] = a[i] ^ a[i + 1];
//                if (c[i] != b[i]) {
//                    if (c[i + 1] != -1) {
//                        c[i] = a[i] ^ c[i + 1];
//                        if (c[i] != b[i]) {
//                            yes = false;
//                            break;
//                        }
//                    } else {
//                        yes = false;
//                        break;
//                    }
//                }
//            }
//        }
//        if (yes) cout << "YES" << endl;
//        else cout << "NO" << endl;
//    }
//    return 0;
//}

// 327. https://www.luogu.com.cn/problem/CF2131D
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<vector<int>> g(n + 1, vector<int>());
//        for (int i = 1; i < n; i++) {
//            int u, v;
//            cin >> u >> v;
//            g[u].emplace_back(v);
//            g[v].emplace_back(u);
//        }
//        vector<int> ye;
//        for (int i = 1; i <= n; i++)
//            if (g[i].size() == 1) ye.emplace_back(i);
//        int ye_cnt = ye.size();
//        int ans = ye_cnt - 1;
//        vector<int> vis(n + 1);
//        for (int i : ye) {
//            int u = g[i][0];
//            if (vis[u]) continue;
//            vis[u] = 1;
//            int cnt = 0;
//            for (int v : g[u]) {
//                cnt += g[v].size() == 1;
//            }
//            ans = min(ans, ye_cnt - cnt);
//        }
//        if (n == 2) ans = 0;
//        cout << ans << endl;
//    }
//    return 0;
//}

// 328. https://www.luogu.com.cn/problem/CF2131F
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        string a, b;
//        cin >> a >> b;
//        a = " " + a, b = " " + b;
//        int ans = n * (n + 1) / 2 * n;
//        int jian = 0;
//        vector<int> x(n + 1), y(n + 1);
//        for (int i = 1; i <= n; i++) {
//            y[i] = y[i - 1] + (a[i] == '0' ? 1 : -1);
//            x[i] = x[i - 1] + (b[i] == '0' ? -1 : 1);
//        }
//        sort(x.begin() + 1, x.end());
//        sort(y.begin() + 1, y.end());
//        for (int i = 1; i <= n; i++) {
//            auto it = upper_bound(x.begin() + 1, x.end(), y[i]);
//            int da = x.end() - it;
//            jian += (n - da * 2) * y[i];
//        }
//        for (int i = 1; i <= n; i++) {
//            auto it = lower_bound(y.begin() + 1, y.end(), x[i]);
//            int da = y.end() - it;
//            jian += (n - da * 2) * x[i];
//        }
//        ans -= jian / 2;
//        cout << ans << endl;
//    }
//    return 0;
//}

// 329. https://codeforces.com/contest/2135
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        vector<int> dp(n + 1);
//        vector<vector<int>> mp(n + 1);
//        dp[1] = (a[1] == 1);
//        int mx = dp[1];
//        mp[a[1]].emplace_back(1);
//        for (int i = 2; i <= n; i++) {
//            mp[a[i]].emplace_back(i);
//            if (mp[a[i]].size() >= a[i]) dp[i] = max(mx, dp[mp[a[i]][mp[a[i]].size() - a[i]] - 1] + a[i]);
//            else dp[i] = mx;
//            mx = max(mx, dp[i]);
//        }
//        cout << mx << endl;
//    }
//    return 0;
//}

// 330. https://codeforces.com/contest/2135/problem/B
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//int query(char c, int d) {
//    cout << "? " << c << ' ' << d << endl;
//    int ans;
//    cin >> ans;
//    return ans;
//}
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> x(n), y(n);
//        for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
//        int mi1 = 1e18, mi2 = 1e18;
//        for (int i = 0; i < n; i++) {
//            mi1 = min(mi1, x[i] - y[i]);
//            mi2 = min(mi2, x[i] + y[i]);
//        }
//        query('L', 1e9);
//        query('L', 1e9);
//        query('D', 1e9);
//        int jia = query('D', 1e9);
//        jia = -jia + (int)4e9 + mi2;
//        query('U', 1e9);
//        query('U', 1e9);
//        query('U', 1e9);
//        int jian = query('U', 1e9);
//        jian = -jian + (int)4e9 + mi1;
//        cout << "! " << (jia + jian) / 2 << ' ' << (jia - jian) / 2 << endl;
//    }
//    return 0;
//}

// 331. https://www.luogu.com.cn/problem/CF2132D
// 写死我了，真的。
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int T;
//    cin >> T;
//    vector<int> wei(15);
//    wei[1] = 9;
//    int x = 10;
//    for (int i = 2; wei[i - 1] <= 1e15; i++) {
//        int x_ = x;
//        x = 10 * x;
//        wei[i] = (x - x_) * i + wei[i - 1];
//    }
//    vector<int> dp(15);
//    dp[1] = 45;
//    for (int i = 2; i <= 14; i++) {
//        dp[i] = 45 * (int)pow(10, i - 1) + 9 * dp[i - 1];
//        dp[i] += dp[i - 1];
//    }
//    while (T--) {
//        int k;
//        cin >> k;
//        int id = 0;
//        while (wei[id] <= k) id++;
//        id--;
//        int ans = dp[id];
//        k -= wei[id];
//        int len = k / (id + 1);
//        int mx = (int)pow(10, id) + len - 1;
//        string mx_s = to_string(mx);
//        if (len != 0) {
//            for (int i = mx_s.size() - 1; i >= 0; i--) {
//                int d = mx_s[i] - '0';
//                int xiao = (i == 0 ? 1 : stoll(mx_s.substr(0, i)) - (int)pow(10, i - 1) + 1);
//                int da = (i == 0 ? 0 : stoll(mx_s.substr(0, i)) - (int)pow(10, i - 1));
//
//                int xiao_ = (i == mx_s.size() - 1 ? 1 : (int)pow(10, mx_s.size() - 1 - i));
//
//                int den = (i == mx_s.size() - 1 ? 1 : stoll(mx_s.substr(i + 1)) + 1);
//                for (int j = 1; j <= 9; j++) {
//                    if (j < d) {
//                        ans += j * xiao * xiao_;
//                    } else if (j > d) {
//                        ans += j * da * xiao_;
//                    } else {
//                        ans += j * da * xiao_;
//                        ans += j * den;
//                    }
//                }
//            }
//        }
//        int cnt = 0;
//        int mu = k % (id + 1);
//        while (cnt < mu) {
//            mx++;
//            mx_s = to_string(mx);
//            for (int i = 0; i < mx_s.size() && cnt < mu; i++) {
//                ans += mx_s[i] - '0';
//                cnt++;
//            }
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 332. https://www.luogu.com.cn/problem/P1836
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int n;
//    cin >> n;
//    int wei = (int)log10(n);
//    vector<int> dp(wei + 2);
//    dp[1] = 45;
//    for (int i = 2; i <= wei; i++) {
//        dp[i] = 45 * (int)pow(10, i - 1) + 9 * dp[i - 1];
//        dp[i] += dp[i - 1];
//    }
//    string s = " " + to_string(n);
//    int ans = dp[wei];
//    for (int i = s.size() - 1; i >= 1; i--) {
//        int d = s[i] - '0';
//        int qian = (i == 1 ? 1 : stoll(s.substr(1, i - 1)) - (int)pow(10, i - 2) + 1);
//        int hou = (int)pow(10, s.size() - 1 - i);
//        int x = (i == s.size() - 1 ? 1 : stoll(s.substr(i + 1)) + 1);
//        for (int j = 1; j <= 9; j++) {
//            if (j > d) ans += j * (qian - 1) * hou;
//            else if (j < d) ans += j * qian * hou;
//            else {
//                ans += j * (qian - 1) * hou;
//                ans += j * x;
//            }
//        }
//    }
//    cout << ans << endl;
//    return 0;
//}

// 333. https://www.luogu.com.cn/problem/P2602
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int a, b;
//    cin >> a >> b;
//    int wei = (int)log10(b);
//    vector<vector<int>> dp(wei + 2, vector<int>(10));
//    dp[0][0] = 1;
//    for (int i = 0; i <= 9; i++) dp[1][i] = 1;
//    vector<int> d(wei + 2);
//    d[1] = 1;
//    int x = 10;
//    for (int i = 2; i <= wei; i++) d[i] = 10 * d[i - 1] + x, x *= 10;
//    for (int i = 2; i <= wei; i++) {
//        dp[i][0] = 9 * d[i - 1];
//        for (int j = 1; j <= 9; j++) {
//            dp[i][j] = (int)pow(10, i - 1) + 9 * dp[i - 1][j];
//        }
//        for (int j = 1; j <= 9; j++) {
//            dp[i][j] += dp[i - 1][j];
//        }
//        dp[i][0] += dp[i - 1][0];
//    }
//    auto calc = [&](int n) -> vector<int> {
//        string s = " " + to_string(n);
//        int wei_n = (int)log10(n);
//        vector<int> res = dp[wei_n];
//        for (int i = s.size() - 1; i >= 1; i--) {
//            int d = s[i] - '0';
//            int qian = (i == 1 ? 1 : stoll(s.substr(1, i - 1)) - (int)pow(10, i - 2) + 1);
//            int hou = (int)pow(10, s.size() - 1 - i);
//            int x = (i == s.size() - 1 ? 1 : stoll(s.substr(i + 1)) + 1);
//            for (int j = 0; j <= 9; j++) {
//                if (j == 0 && i == 1) continue;
//                if (j > d) res[j] += (qian - 1) * hou;
//                else if (j < d) res[j] += qian * hou;
//                else {
//                    res[j] += (qian - 1) * hou;
//                    res[j] += x;
//                }
//            }
//        }
//        return res;
//    };
//    vector<int> ans1 = calc(b);
//    vector<int> ans2 = calc(a - 1);
//    for (int i = 0; i <= 9; i++) cout << max(0LL, ans1[i] - ans2[i]) << ' ';
//    return 0;
//}

// 334. https://www.luogu.com.cn/problem/CF1895C
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int n;
//    cin >> n;
//    map<tuple<int, int, int, int>, int> mp;
//    vector<string> a(n + 1);
//    for (int i = 1; i <= n; i++) {
//        cin >> a[i];
//        string& s = a[i];
//        int sum = 0;
//        for (char c : s) sum += c - '0';
//        int qian = 0;
//        int siz = s.size();
//        int to = siz / 2 - 1;
//        mp[{0, siz, 0, sum}]++;
//        for (int j = 0; j <= to; j++) {
//            qian += s[j] - '0';
//            mp[{j + 1, siz - j - 1, qian, sum - qian}]++;
//        }
//    }
//    long long ans = 0;
//    for (int i = 1; i <= n; i++) {
//        string& s = a[i];
//        int sum = 0;
//        for (char j : s) sum += j - '0';
//        int qian = 0;
//        int chang_z = 1;
//        int chang_y = s.size() - 1;
//        for (int j = 0; j <= 4; j++, chang_z++, chang_y--) {
//            if (j < s.size()) {
//                qian += s[j] - '0';
//                ans += mp[{0, chang_z - chang_y, 0, 2 * qian - sum}];
//            } else {
//                for (int k = 1; k <= 18; k++) {
//                    ans += mp[{chang_z - s.size(), chang_z, k, qian + k}];
//                }
//            }
//        }
//    }
//    cout << ans << endl;
//    return 0;
//}

// 335. https://www.luogu.com.cn/problem/CF1895D
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int n;
//    cin >> n;
//    vector<int> a(n);
//    int mx = 0;
//    for (int i = 1; i < n; i++) cin >> a[i], mx = max(mx, a[i]);
//    int len = 0;
//    while (mx) {
//        len++;
//        mx >>= 1;
//    }
//    vector<vector<int>> wei(len, vector<int>(2));
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < len; j++) {
//            int ji = i >> j & 1;
//            wei[j][ji]++;
//        }
//    }
//    vector<vector<int>> wei_2(len, vector<int>(2));
//    for (int i = 0; i < len; i++) wei_2[i][0]++;
//    int t = 0;
//    for (int i = 1; i < n; i++) {
//        int t_ = 0;
//        for (int j = 0; j < len; j++) {
//            int qian = t >> j & 1;
//            int hou = a[i] >> j & 1;
//            int zhi = qian ^ hou;
//            wei_2[j][zhi]++;
//            t_ = t_ | (zhi << j);
//        }
//        t = t_;
//    }
//    int fi = 0;
//    for (int i = 0; i < len; i++) {
//        if (wei[i][0] != wei_2[i][0]) {
//            fi = fi | (1 << i);
//        }
//    }
//    vector<int> ans(n + 1);
//    ans[1] = fi;
//    for (int i = 1; i < n; i++) {
//        ans[i + 1] = ans[i] ^ a[i];
//    }
//    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
//    return 0;
//}

// 336. https://www.luogu.com.cn/problem/CF2131G
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//const int mod = 1e9 + 7;
//
//signed main() {
//    vector<int> bu(33), ji(33);
//    bu[1] = 1, ji[1] = 1;
//    for (int i = 2; i <= 32; i++) bu[i] = 2 * bu[i - 1];
//    int j = 1;
//    for (int i = 2; i <= 32; i++) {
//        ji[i] = i * j % mod;
//        j = j * ji[i] % mod;
//    }
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, k;
//        cin >> n >> k;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        sort(a.begin() + 1, a.end());
//        int ans = 1;
//        int i;
//        for (i = 1; i <= n && k != 0; i++) {
//            if (a[i] <= 30) {
//                if (k >= bu[a[i]]) {
//                    k -= bu[a[i]];
//                    ans = ans * ji[a[i]] % mod;
//                } else {
//                    if (k >= 1) {
//                        ans = ans * a[i] % mod;
//                        k--;
//                    }
//                    break;
//                }
//            } else {
//                if (k >= 1) {
//                    ans = ans * a[i] % mod;
//                    k--;
//                }
//                break;
//            }
//        }
//        function<void()> dfs = [&]() -> void {
//            if (k <= 0) return;
//            int sum = 0;
//            int i;
//            for (i = 1; i <= 30; i++) {
//                sum += bu[i];
//                if (k >= sum) {
//                    ans = ans * ji[i] % mod;
//                } else {
//                    sum -= bu[i];
//                    k -= sum;
//                    if (k >= 1) {
//                        ans = ans * i % mod;
//                        k--;
//                    }
//                    break;
//                }
//            }
//            dfs();
//        };
//        dfs();
//        cout << ans << endl;
//    }
//    return 0;
//}

// 337. https://www.luogu.com.cn/problem/CF2131C
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, k;
//        cin >> n >> k;
//        vector<int> a(n + 1), b(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        for (int i = 1; i <= n; i++) cin >> b[i];
//        map<int, int> mp;
//        for (int i = 1; i <= n; i++) mp[b[i] % k]++;
//        bool yes = true;
//        for (int i = 1; i <= n; i++) {
//            int c = a[i] % k;
//            if (mp[c]) {
//                mp[c]--;
//            } else {
//                if (mp[k - c]) {
//                    mp[k - c]--;
//                } else {
//                    yes = false;
//                    break;
//                }
//            }
//        }
//        if (yes) cout << "YES" << endl;
//        else cout << "NO" << endl;
//    }
//    return 0;
//}

// 338. https://www.luogu.com.cn/problem/CF2128C
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        vector<int> mi(n + 1);
//        mi[1] = a[1];
//        bool yes = true;
//        for (int i = 2; i <= n; i++) {
//            if (2 * mi[i - 1] - 1 < a[i]) {
//                yes = false;
//                break;
//            }
//            mi[i] = min(mi[i - 1], a[i]);
//        }
//        if (yes) cout << "YES" << endl;
//        else cout << "NO" << endl;
//    }
//    return 0;
//}

// 339. https://www.luogu.com.cn/problem/CF1753B
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int n, x;
//    cin >> n >> x;
//    unordered_map<int, int> mp;
//    for (int i = 1; i <= n; i++) {
//        int y;
//        cin >> y;
//        mp[y]++;
//    }
//    bool yes = true;
//    for (int i = 1; i < x; i++) {
//        mp[i + 1] += mp[i] / (i + 1);
//        mp[i] %= (i + 1);
//        if (mp[i] != 0) {
//            yes = false;
//            break;
//        }
//    }
//    if (yes) cout << "YES" << endl;
//    else cout << "NO" << endl;
//    return 0;
//}

// 340. https://www.luogu.com.cn/problem/CF2122C
//#include <bits/stdc++.h>
//using namespace std;
//
//struct node {
//    int x, y, id;
//};
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<node> a(n + 1);
//        for (int i = 1; i <= n; i++) {
//            cin >> a[i].x >> a[i].y;
//            a[i].id = i;
//        }
//        sort(a.begin() + 1, a.end(), [&](node& x, node& y) {
//           return x.x < y.x;
//        });
//        sort(a.begin() + 1, a.begin() + 1 + n / 2, [&](node& x, node& y) {
//            return x.y < y.y;
//        });
//        sort(a.begin() + 1 + n / 2, a.end(), [&](node& x, node& y) {
//            return x.y > y.y;
//        });
//        for (int i = 1; i <= n / 2; i++) {
//            cout << a[i].id << ' ' << a[i + n / 2].id << endl;
//        }
//    }
//    return 0;
//}

// 暑假结束了！整个暑假340题（其实更多，应该有370多道），一般一般。