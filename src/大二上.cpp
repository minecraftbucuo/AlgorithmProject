// 大二上学期，启动！！！
// 1. 重做 https://codeforces.com/contest/1506/problem/G
// 再次做依然 wa 了很多发。
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
//        s = " " + s;
//        stack<char> st;
//        unordered_map<char, int> cnt, vis;
//        for (int i = 1; i <= n; i++) cnt[s[i]]++;
//        for (int i = 1; i <= n; i++) {
//            while (!st.empty() && s[i] > st.top() && cnt[st.top()] > 0 && !vis[s[i]]) {
//                vis[st.top()] = 0;
//                st.pop();
//            }
//            if (!vis[s[i]]) {
//                st.push(s[i]);
//                vis[s[i]] = 1;
//            }
//            cnt[s[i]]--;
//        }
//        string ans;
//        while (!st.empty()) {
//            ans += st.top();
//            st.pop();
//        }
//        reverse(ans.begin(), ans.end());
//        cout << ans << endl;
//    }
//    return 0;
//}

// 2025.9.2
// 2. https://www.luogu.com.cn/problem/CF2108C
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
//        a.erase(unique(a.begin() + 1, a.end()), a.end());
//        n = a.size() - 1;
//        vector<int> id(n + 1);
//        iota(id.begin(), id.end(), 0);
//        sort(id.begin() + 1, id.end(), [&](int x, int y) {
//            return a[x] > a[y];
//        });
//        int ans = 0;
//        set<int> st;
//        for (int i = 1; i <= n; i++) {
//            if (st.find(id[i]) == st.end()) {
//                ans++;
//                st.insert(id[i]);
//                if (id[i] - 1 > 0 && id[i] - 1 <= n) st.insert(id[i] - 1);
//                if (id[i] + 1 > 0 && id[i] + 1 <= n) st.insert(id[i] + 1);
//            } else {
//                if (id[i] - 1 > 0 && id[i] - 1 <= n) st.insert(id[i] - 1);
//                if (id[i] + 1 > 0 && id[i] + 1 <= n) st.insert(id[i] + 1);
//            }
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 3. https://www.luogu.com.cn/problem/CF2101B
//#include <bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 10;
//
//int tr[N], n;
//
//int sum(int x) {
//    int res = 0;
//    for (int i = x; i; i -= i & -i)
//        res += tr[i];
//    return res;
//}
//
//void add(int x, int y) {
//    for (int i = x; i <= n; i += i & -i)
//        tr[i] += y;
//}
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        cin >> n;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        vector<int> ans(n + 1);
//        set<int> ji, ou;
//        for (int i = 1; i <= n; i++) {
//            if (i & 1) ji.insert(i);
//            else ou.insert(i);
//        }
//        vector<int> id(n + 1);
//        iota(id.begin(), id.end(), 0);
//        sort(id.begin() + 1, id.end(), [&](int x, int y) {
//            return a[x] < a[y];
//        });
//        for (int i = 1; i <= n; i++) {
//            if (id[i] & 1) {
//                ans[*ji.begin()] = a[id[i]];
//                ji.erase(*ji.begin());
//            } else {
//                ans[*ou.begin()] = a[id[i]];
//                ou.erase(*ou.begin());
//            }
//        }
//        int ji_cnt = 0, ou_cnt = 0;
//        memset(tr, 0, sizeof(int) * (n + 1));
//        for (int i = 1; i <= n; i += 2) {
//            ji_cnt += sum(n) - sum(a[i]);
//            add(a[i], 1);
//        }
//        memset(tr, 0, sizeof(int) * (n + 1));
//        for (int i = 2; i <= n; i += 2) {
//            ou_cnt += sum(n) - sum(a[i]);
//            add(a[i], 1);
//        }
//        if ((ji_cnt & 1) ^ (ou_cnt & 1)) swap(ans[n], ans[n - 2]);
//        for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
//        cout << endl;
//    }
//    return 0;
//}

// 4. https://www.luogu.com.cn/problem/CF2096D
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        unordered_map<int, int> xie, shu;
//        for (int i = 1; i <= n; i++) {
//            int x, y;
//            cin >> x >> y;
//            xie[x + y]++;
//            shu[x]++;
//        }
//        int x = 1e9 + 1, y = 1e9 + 1;
//        for (auto& [a, b] : shu) {
//            if (b & 1) {
//                x = a;
//                break;
//            }
//        }
//        for (auto& [a, b] : xie) {
//            if (b & 1) {
//                y = a - x;
//                break;
//            }
//        }
//        cout << x << ' ' << y << endl;
//    }
//    return 0;
//}

// 5. https://www.luogu.com.cn/problem/CF2094G
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        deque<int> que;
//        int sum = 0;
//        int ans0 = 0, ans1 = 0;
//        int last = 0;
//        int q;
//        cin >> q;
//        while (q--) {
//            int s;
//            cin >> s;
//            if (s == 1) {
//                if (last == 0) {
//                    ans0 = ans0 - (int)que.size() * que.back() + sum;
//                    ans1 = ans1 - sum + (int)que.size() * que.back();
//                    que.push_front(que.back());
//                    que.pop_back();
//                    cout << ans0 << endl;
//                } else {
//                    ans1 = ans1 - (int)que.size() * que.front() + sum;
//                    ans0 = ans0 - sum + (int)que.size() * que.front();
//                    que.push_back(que.front());
//                    que.pop_front();
//                    cout << ans1 << endl;
//                }
//            } else if (s == 2) {
//                last = last ^ 1;
//                if (last == 0) cout << ans0 << endl;
//                else cout << ans1 << endl;
//            } else {
//                int k;
//                cin >> k;
//                if (last == 0) {
//                    que.push_back(k);
//                    ans0 += (int)que.size() * k;
//                    ans1 = ans1 + sum + k;
//                    cout << ans0 << endl;
//                } else {
//                    que.push_front(k);
//                    ans0 = ans0 + sum + k;
//                    ans1 += (int)que.size() * k;
//                    cout << ans1 << endl;
//                }
//                sum += k;
//            }
//        }
//    }
//    return 0;
//}

// 6. https://www.luogu.com.cn/problem/CF2118D2
//#include <bits/stdc++.h>
//using namespace std;
//using ll = long long;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        ll k;
//        cin >> n >> k;
//        vector<ll> p(n + 1), d(n + 1);
//        map<ll, int> pos;
//        for (int i = 1; i <= n; i++) cin >> p[i], pos[p[i]] = i;
//        for (int i = 1; i <= n; i++) cin >> d[i];
//        map<ll, int> mp;
//        vector<vector<int>> g(2 * n + 1);
//        for (int i = 1; i <= n; i++) {
//            ll t = (p[i] + d[i]) % k;
//            if (mp[t] == 0) g[0].emplace_back(i);
//            else g[mp[t] + n].emplace_back(i);
//            mp[t] = i;
//        }
//        mp.clear();
//        for (int i = n; i >= 1; i--) {
//            ll t = ((p[i] - d[i]) % k + k) % k;
//            g[mp[t]].emplace_back(i + n);
//            mp[t] = i;
//        }
//        vector<int> esc(2 * n + 1);
//        function<void(int)> dfs = [&](int u) -> void {
//            esc[u] = 1;
//            for (int i : g[u]) {
//                if (!esc[i]) dfs(i);
//            }
//        };
//        dfs(0);
//        map<ll, set<ll>> ms;
//        for (int i = 1; i <= n; i++) {
//            ms[((p[i] - d[i]) % k + k) % k].insert(p[i]);
//        }
//        int q;
//        cin >> q;
//        while (q--) {
//            ll a;
//            cin >> a;
//            ll a_ = a % k;
//            auto it = ms[a_].lower_bound(a);
//            if (it == ms[a_].end()) cout << "YES" << endl;
//            else {
//                if (esc[pos[*it]]) cout << "YES" << endl;
//                else cout << "NO" << endl;
//            }
//        }
//    }
//    return 0;
//}

// 2025.9.4
// 7. https://codeforces.com/problemset/problem/22/D
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int n;
//    cin >> n;
//    vector<pair<int, int>> a(n + 1);
//    for (int i = 1; i <= n; i++) {
//        cin >> a[i].first >> a[i].second;
//        if (a[i].first > a[i].second) swap(a[i].first, a[i].second);
//    }
//    vector<int> ans;
//    sort(a.begin() + 1, a.end());
//    int fi = a[1].first, ed = a[1].second;
//    for (int i = 2; i <= n; i++) {
//        if (a[i].first > ed) {
//            ans.push_back(fi);
//            fi = a[i].first;
//            ed = a[i].second;
//        } else {
//            fi = max(fi, a[i].first);
//            ed = min(ed, a[i].second);
//        }
//    }
//    ans.push_back(fi);
//    cout << ans.size() << endl;
//    for (int i : ans) cout << i << ' ';
//    return 0;
//}

// 8. https://www.luogu.com.cn/problem/CF3C
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    vector<string> a(3);
//    auto win = [&](char c) {
//        for (int i = 0; i < 3; i++) {
//            int cnt = 0;
//            for (char c_ : a[i]) {
//                cnt += c_ == c;
//            }
//            if (cnt == 3) return true;
//        }
//        for (int i = 0; i < 3; i++) {
//            int cnt = 0;
//            for (int j = 0; j < 3; j++) {
//                cnt += a[j][i] == c;
//            }
//            if (cnt == 3) return true;
//        }
//        int cnt = 0;
//        for (int i = 0; i < 3; i++) {
//            cnt += a[i][i] == c;
//        }
//        if (cnt == 3) return true;
//        cnt = 0;
//        for (int i = 0; i < 3; i++) {
//            cnt += a[i][2 - i] == c;
//        }
//        if (cnt == 3) return true;
//        return false;
//    };
//    cin >> a[0] >> a[1] >> a[2];
//    int o_cnt = 0, x_cnt = 0;
//    for (int i = 0; i < 3; i++) {
//        for (char c : a[i]) {
//            o_cnt += (c == '0');
//            x_cnt += (c == 'X');
//        }
//    }
//    if (x_cnt < o_cnt || x_cnt - o_cnt >= 2 || (win('X') && win('0'))) cout << "illegal" << endl;
//    else {
//        if (win('0')) {
//            if (o_cnt == x_cnt) cout << "the second player won" << endl;
//            else cout << "illegal" << endl;
//        }
//        else if (win('X')) {
//            if (o_cnt + 1 == x_cnt) cout << "the first player won" << endl;
//            else cout << "illegal" << endl;
//        }
//        else {
//            if (o_cnt + x_cnt == 9) cout << "draw" << endl;
//            else {
//                if (x_cnt == o_cnt) cout << "first" << endl;
//                else cout << "second" << endl;
//            }
//        }
//    }
//    return 0;
//}

// 9. https://www.luogu.com.cn/problem/CF2094F
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, m, k;
//        cin >> n >> m >> k;
//        vector<vector<int>> a(n + 1, vector<int>(m + 1));
//        if (m % k == 0) {
//            for (int i = 1; i <= n; i++) {
//                int x = (i % 2 == 0 ? 2 : 1);
//                for (int j = 1; j <= m; j++) {
//                    a[i][j] = x;
//                    x++;
//                    if (x > k) x = 1;
//                }
//            }
//        } else {
//            int x = 1;
//            for (int i = 1; i <= n; i++) {
//                for (int j = 1; j <= m; j++) {
//                    a[i][j] = x;
//                    x++;
//                    if (x > k) x = 1;
//                }
//            }
//        }
//        for (int i = 1; i <= n; i++) {
//            for (int j = 1; j <= m; j++) {
//                cout << a[i][j] << ' ';
//            }
//            cout << endl;
//        }
//    }
//    return 0;
//}

// 10. https://www.luogu.com.cn/problem/CF2084D
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, m, k;
//        cin >> n >> m >> k;
//        int ans = 0;
//        int x = -1;
//        for (int i = k; n - m * i >= 0; i++) {
//            int x_ = min(i, n - m * i);
//            if (x_ > ans) {
//                ans = x_;
//                x = i;
//            }
//        }
//        vector<int> a(n + 1);
//        int y = 0;
//        for (int i = 1; i <= n; i++) {
//            a[i] = y;
//            y++;
//            y %= x;
//        }
//        for (int i = 1; i <= n; i++) cout << a[i] << ' ';
//        cout << endl;
//    }
//    return 0;
//}

// https://codeforces.com/gym/105358   VP The 2024 ICPC Asia EC Regionals Online Contest (II)
// 11. F
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int a = 1500;
//    int n;
//    cin >> n;
//    for (int i = 1; i <= n; i++) {
//        int x;
//        cin >> x;
//        a += x;
//        if (a >= 4000) {
//            cout << i << endl;
//            return 0;
//        }
//    }
//    cout << -1 << endl;
//    return 0;
//}

// 12. J
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//struct node {
//    int w, v, c;
//};
//
//signed main() {
//    int n;
//    cin >> n;
//    vector<node> a(n + 1);
//    for (int i = 1; i <= n; i++) cin >> a[i].w >> a[i].v >> a[i].c;
//    vector<int> id(n + 1);
//    iota(id.begin(), id.end(), 0);
//    sort(id.begin() + 1, id.end(), [&](int x, int y) {
//       return a[x].c * a[y].w < a[y].c * a[x].w;
//    });
//    int ans = 0;
//    int sum = 0;
//    for (int i = 1; i <= n; i++) {
//        ans += a[id[i]].v - a[id[i]].c * sum;
//        sum += a[id[i]].w;
//    }
//    cout << ans << endl;
//    return 0;
//}

// 13. I
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
//        vector<int> ans(32, -1);
//        ans[31] = 1;
//        if (n == 0) cout << "NO" << endl;
//        else {
//            n--;
//            if ((n & 1) == 1 && (n >> 1 & 1) == 1) cout << "NO" << endl;
//            else {
//                cout << "YES" << endl;
//                for (int i = 0; i <= 30; i++) {
//                    if (n >> i & 1) {
//                        if (i == 0) ans[i] = 0;
//                        else ans[i - 1] = 1;
//                    }
//                }
//                int cnt = 0;
//                for (int i = 0; i <= 31; i++) {
//                    cout << ans[i] << ' ';
//                    cnt++;
//                    if (cnt == 8) {
//                        cout << endl;
//                        cnt = 0;
//                    }
//                }
//            }
//        }
//    }
//    return 0;
//}

// 14. G
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//const int mod = 998244353;
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
//int sum(int p, int t) {
//    if (t == 0) return 1;
//    if (t & 1) {
//        return (1 + ksm(p, (t + 1) / 2)) % mod * sum(p, t / 2) % mod;
//    } else {
//        return (1 + p * sum(p, t - 1) % mod) % mod;
//    }
//}
//
//signed main() {
//    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
//    int T;
//    cin >> T;
//    while (T--) {
//        int x, y, a0, a1, b_;
//        cin >> x >> y >> a0 >> a1 >> b_;
//        b_ = a0 + a1;
//        int ni_b = ksm(b_, mod - 2);
//        int p0 = a0 * ni_b % mod, p1 = a1 * ni_b % mod;
//
//        function<int(int, int)> dfs = [&](int a, int b) -> int {
//            if (a <= 0) return 0;
//            else if (b <= 0) return 1;
//            if (a == b) return p0;
//            if (a > b) {
//                int t = (a - b) / b;
//                return (p0 * (sum(p1, t)) % mod + ksm(p1, t + 1) * dfs(a - (t + 1) * b, b) % mod) % mod;
//            } else {
//                int t = (b - a) / a + 1;
//                return ksm(p0, t) * dfs(a, b - t * a) % mod;
//            }
//        };
//
//        cout << dfs(x, y) << endl;
//    }
//    return 0;
//}

// 15. A
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int n, k;
//    cin >> n >> k;
//    int c = 1e9;
//    for (int i = 1; i <= k; i++) {
//        int x;
//        cin >> x;
//        c = min(c, x);
//    }
//    vector<pair<int, string>> a(n + 1);
//    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
//    vector<int> ans(n + 1), id(n + 1);
//    iota(id.begin() + 1, id.end(), 1);
//    sort(id.begin() + 1, id.end(), [&](int x, int y) {
//       return a[x].first > a[y].first;
//    });
//    unordered_map<string, int> mp;
//    int ren = 0;
//    for (int i = 1; i <= n; i++) {
//        ans[id[i]] = ren + 1;
//        if (mp[a[id[i]].second] >= c) ans[id[i]]--;
//        mp[a[id[i]].second]++;
//        if (mp[a[id[i]].second] <= c) ren++;
//    }
//    for (int i = 1; i <= n; i++) cout << ans[i] << endl;
//    return 0;
//}

// 16. L
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//
//signed main() {
//    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
//    int T;
//    cin >> T;
//    while (T--) {
//        int t;
//        cin >> t;
//        int c = (int)sqrtl(t * 2);
//        int a1 = c * c - c + 2 * t;
//        int b1 = 2 * c;
//        int d = gcd(a1, b1);
//        a1 /= d, b1 /= d;
//        c++;
//        int a2 = c * c - c + 2 * t;
//        int b2 = 2 * c;
//        d = gcd(a2, b2);
//        a2 /= d, b2 /= d;
//        if (a1 * b2 < a2 * b1) cout << a1 << ' ' << b1 << endl;
//        else cout << a2 << ' ' << b2 << endl;
//    }
//    return 0;
//}

// 17. E
//#include <bits/stdc++.h>
//using namespace std;
//#define inf 1000000000
//#define endl '\n'
//
//signed main() {
//    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, m, d;
//        cin >> n >> m >> d;
//        vector<vector<int>> g(n + 1);
//        for (int i = 1; i <= m; i++) {
//            int u, v;
//            cin >> u >> v;
//            g[u].emplace_back(v);
//            g[v].emplace_back(u);
//        }
//        int k;
//        cin >> k;
//        vector<vector<int>> dist(n + 1, vector<int>(2, inf));
//        queue<int> q;
//        for (int i = 1; i <= k; i++) {
//            int x;
//            cin >> x;
//            dist[x][0] = 0;
//            q.push(x);
//        }
//        while (!q.empty()) {
//            int u = q.front();
//            q.pop();
//            int ji = dist[u][0] + 1;
//            int ou = dist[u][1] + 1;
//            for (int v : g[u]) {
//                if (ji <= d && dist[v][1] > ji) {
//                    dist[v][1] = ji;
//                    q.push(v);
//                }
//                if (ou <= d && dist[v][0] > ou) {
//                    dist[v][0] = ou;
//                    q.push(v);
//                }
//            }
//        }
//        vector<vector<int>> pre(n + 1, vector<int>(2));
//        vector<vector<int>> di(n + 1, vector<int>(2, inf));
//        di[1][0] = 0;
//        queue<pair<int, int>> q_;
//        q_.emplace(1, 0);
//        while (!q_.empty()) {
//            auto [u, ji] = q_.front();
//            q_.pop();
//            for (int v : g[u]) {
//                if (di[v][ji ^ 1] != inf) continue;
//                if (di[u][ji] + 1 < dist[v][ji ^ 1]) {
//                    di[v][ji ^ 1] = di[u][ji] + 1;
//                    pre[v][ji ^ 1] = u;
//                    q_.emplace(v, ji ^ 1);
//                }
//            }
//        }
//        if (di[n][0] == inf && di[n][1] == inf) cout << -1 << endl;
//        else {
//            vector<int> ans;
//            int st = n;
//            int ji = 0;
//            if (di[n][0] > di[n][1]) ji = 1;
//            while (st != 1 || ji != 0) {
//                ans.emplace_back(st);
//                st = pre[st][ji];
//                ji ^= 1;
//            }
//            ans.emplace_back(1);
//            reverse(ans.begin(), ans.end());
//            cout << ans.size() - 1 << endl;
//            for (int i : ans) cout << i << ' ';
//            cout << endl;
//        }
//    }
//    return 0;
//}

// 18. https://codeforces.com/contest/2139/problem/E1
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, k;
//        cin >> n >> k;
//        vector<int> cnt(n + 1), dep(n + 1), du(n + 1);
//        dep[1] = 1, cnt[1] = 1;
//        for (int i = 2; i <= n; i++) {
//            int p;
//            cin >> p;
//            dep[i] = dep[p] + 1;
//            cnt[dep[i]]++;
//            du[p]++;
//        }
//        int mxdep = 1e9;
//        for (int i = 1; i <= n; i++) {
//            if (!du[i]) {
//                mxdep = min(mxdep, dep[i]);
//            }
//        }
//        vector<int> dp(n + 1);
//        dp[0] = 1;
//        int sum = 0;
//        for (int i = 1; i <= mxdep; i++) {
//            for (int j = sum; j >= 0; j--) dp[j + cnt[i]] |= dp[j];
//            sum += cnt[i];
//        }
//        bool have_ans = false;
//        for (int i = 1; i <= sum; i++) {
//            if (dp[i]) {
//                if ((i <= k && sum - i <= n - k) || (i <= n - k && sum - i <= k)) {
//                    cout << mxdep << endl;
//                    have_ans = true;
//                    break;
//                }
//            }
//        }
//        if (!have_ans) cout << mxdep - 1 << endl;
//    }
//    return 0;
//}

// VP Educational Codeforces Round 156 (Rated for Div. 2)
// 19. A
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        if (n <= 6) cout << "NO" << endl;
//        else {
//            if (n % 3 == 0) {
//                int t = n - 1 - 4;
//                if (t == 1 || t == 4) cout << "NO" << endl;
//                else {
//                    cout << "YES" << endl;
//                    cout << 1 << ' ' << 4 << ' ' << t << endl;
//                }
//            } else {
//                cout << "YES" << endl;
//                cout << 1 << ' ' << 2 << ' ' << n - 3 << endl;
//            }
//        }
//    }
//    return 0;
//}

// 20. B
//#include <bits/stdc++.h>
//using namespace std;
//#define int double
//
//double dist(int x1, int y1, int x2, int y2) {
//    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
//}
//
//signed main() {
//    signed T;
//    cin >> T;
//    while (T--) {
//        int px, py, ax, ay, bx, by;
//        cin >> px >> py >> ax >> ay >> bx >> by;
//        double l = 0, r = 1e18;
//        auto check = [&](double mid) -> bool {
//            double dist0_a = dist(0, 0, ax, ay);
//            double distp_a = dist(px, py, ax, ay);
//            double dist0_b = dist(0, 0, bx, by);
//            double distp_b = dist(px, py, bx, by);
//            if (dist0_a <= mid && distp_a <= mid) return true;
//            if (dist0_b <= mid && distp_b <= mid) return true;
//            if (dist(ax, ay, bx, by) <= 2 * mid) {
//                if ((dist0_a <= mid || dist0_b <= mid) && (distp_a <= mid || distp_b <= mid))
//                    return true;
//                return false;
//            }
//            return false;
//        };
//        while (r - l > 1e-7) {
//            double mid = (l + r) / 2;
//            if (check(mid)) r = mid;
//            else l = mid;
//        }
//        printf("%.10lf\n", l);
//    }
//    return 0;
//}

// 21. C
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
//        int n;
//        cin >> n;
//        int cnt = 0, x = s.size();
//        int sum = 0;
//        while (sum + x < n) {
//            sum += x;
//            x--;
//            cnt++;
//        }
//        stack<char> st;
//        for (char c : s) {
//            while (!st.empty() && cnt > 0 && st.top() > c) {
//                st.pop();
//                cnt--;
//            }
//            st.push(c);
//        }
//        while (cnt) {
//            st.pop();
//            cnt--;
//        }
//        n -= sum;
//        string ans;
//        while (!st.empty()) {
//            ans += st.top();
//            st.pop();
//        }
//        reverse(ans.begin(), ans.end());
//        cout << ans[n - 1];
//    }
//    return 0;
//}

// 22. D
//#include <bits/stdc++.h>
//using namespace std;
//const int mod = 998244353, N = 3e5 + 10;
//
//struct node {
//    int l, r;
//    int sum;
//} tr[N << 2];
//
//int a[N];
//
//void pushup(int u) {
//    tr[u].sum = 1LL * tr[u << 1].sum * tr[u << 1 | 1].sum % mod;
//}
//
//void build(int u, int l, int r) {
//    tr[u] = {l, r, 0};
//    if (l == r) tr[u].sum = a[l];
//    else {
//        int mid = (l + r) >> 1;
//        build(u << 1, l, mid);
//        build(u << 1 | 1, mid + 1, r);
//        pushup(u);
//    }
//}
//
//void modify(int u, int x, int y) {
//    if (tr[u].l == tr[u].r) {
//        tr[u].sum = y;
//    } else {
//        int mid = (tr[u].l + tr[u].r) >> 1;
//        if (x <= mid) modify(u << 1, x, y);
//        else modify(u << 1 | 1, x, y);
//        pushup(u);
//    }
//}
//
//signed main() {
//    int n, m;
//    cin >> n >> m;
//    string s;
//    cin >> s;
//    s = " " + s;
//    for (int i = n - 1; i >= 1; i--) {
//        if (s[i] == '?') a[i] = i - 1;
//        else a[i] = 1;
//    }
//    build(1, 1, n - 1);
//    cout << tr[1].sum << endl;
//    while (m--) {
//        int i;
//        char c;
//        cin >> i >> c;
//        if (c == '?') modify(1, i, i - 1);
//        else modify(1, i, 1);
//        cout << tr[1].sum << endl;
//    }
//    return 0;
//}

// VP Educational Codeforces Round 155 (Rated for Div. 2)
// 23. A
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
//        int a1 = a[1].first, a2 = a[1].second;
//        int ans = a1;
//        for (int i = 2; i <= n; i++) {
//            if (a[i].first >= ans && a[i].second >= a2) {
//                ans = -1;
//                break;
//            }
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 24. B
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
//        vector<int> a(n + 1), b(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        for (int i = 1; i <= n; i++) cin >> b[i];
//        sort(a.begin() + 1, a.end());
//        sort(b.begin() + 1, b.end());
//        int suma = 0, sumb = 0;
//        for (int i = 1; i <= n; i++) {
//            suma += a[i];
//            sumb += b[i];
//        }
//        int ans = min(suma + n * b[1], sumb + n * a[1]);
//        cout << ans << endl;
//    }
//    return 0;
//}

// 25. C
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//const int mod = 998244353;
//const int N = 2e5 + 10;
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
//int fact[N], infact[N];
//
//void init() {
//    fact[0] = 1, infact[0] = 1;
//    for (int i = 1; i < N; i++) {
//        fact[i] = fact[i - 1] * i % mod;
//        infact[i] = infact[i - 1] * ksm(i, mod - 2) % mod;
//    }
//}
//
//int C(int n, int m) {
//    return (fact[n] * infact[n - m] % mod) * infact[m] % mod;
//}
//
//signed main() {
//    init();
//    int T;
//    cin >> T;
//    while (T--) {
//        string s;
//        cin >> s;
//        int n = s.size();
//        s = " " + s;
//        vector<int> a(n + 1);
//        a[1] = 1;
//        int id = 1;
//        for (int i = 2; i <= n; i++) {
//            if (s[i] == s[i - 1]) a[id]++;
//            else a[++id]++;
//        }
//        int ans = 0;
//        for (int i = 1; i <= id; i++) ans += a[i] - 1;
//        int m_ = 0, cnt = 1;
//        for (int i = 1; i <= id; i++) {
//            if (a[i] != 1) {
//                m_ += a[i] - 1;
//                cnt *= C(a[i], a[i] - 1);
//                cnt %= mod;
//            }
//        }
//        cout << ans << ' ' << cnt * fact[m_] % mod << endl;
//    }
//    return 0;
//}

// 26. D
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//const int mod = 998244353;
//
//signed main() {
//    int n;
//    cin >> n;
//    vector<int> a(n + 1);
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    int ans = 0;
//    vector<vector<int>> wei(31, vector<int>(n + 1));
//    for (int i = 0; i <= 30; i++) {
//        for (int j = 1; j <= n; j++) {
//            wei[i][j] = (a[j] >> i) & 1;
//        }
//    }
//    for (int i = 0; i <= 30; i++) {
//        int base = 1 << i;
//        int ji = 0, ou = 0, ji_cnt = 0, ou_cnt = 0;
//        int chang = 0;
//        for (int j = 1; j <= n; j++) {
//            if (wei[i][j] == 1) {
//                int ji_new_c = ou_cnt + 1;
//                int ji_new = ou + ji_new_c;
//                int ou_new_c = ji_cnt;
//                int ou_new = ji + ji_cnt;
//                ji = ji_new;
//                ji_cnt = ji_new_c;
//                ou = ou_new;
//                ou_cnt = ou_new_c;
//                chang += ji;
//            } else {
//                ji += ji_cnt;
//                ou_cnt += 1;
//                ou += ou_cnt;
//                chang += ji;
//            }
//            chang %= mod;
//        }
//        ans = (ans + base % mod * chang % mod) % mod;
//    }
//    cout << ans << endl;
//    return 0;
//}

// 27. https://codeforces.com/problemset/problem/1934/C
//#include <bits/stdc++.h>
//using namespace std;
//
//int n, m;
//
//int query(int x, int y) {
//    if (x >= 1 && x <= n && y >= 1 && y <= m) {
//        cout << '?' << ' ' << x << ' ' << y << endl;
//        int res;
//        cin >> res;
//        return res;
//    }
//    return -1;
//}
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        cin >> n >> m;
//        int d1 = query(1, 1);
//        int d2 = query(1, m);
//        int x = (d1 + 2 + d2 + 1 - m) / 2;
//        int y = (d1 + 2 - (d2 + 1 - m)) / 2;
//        int d3 = query(x, y);
//        if (d3 == 0) {
//            cout << "! " << x << ' ' << y << endl;
//        } else {
//            int d4 = query(n, 1);
//            x = (d1 + 2 - (d4 + 1 - n)) / 2;
//            y = (d1 + 2 + d4 + 1 - n) / 2;
//            cout << "! " << x << ' ' << y << endl;
//        }
//    }
//    return 0;
//}

// 参加 https://codeforces.com/contest/2148
// 28. A
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, x;
//        cin >> n >> x;
//        if (x & 1) cout << n << endl;
//        else cout << 0 << endl;
//    }
//    return 0;
//}

// 29. B
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, m, x, y;
//        cin >> n >> m >> x >> y;
//        int us;
//        for (int i = 1; i <= n; i++) cin >> us;
//        for (int i = 1; i <= m; i++) cin >> us;
//        cout << n + m << endl;
//    }
//    return 0;
//}

// 30. C
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, m;
//        cin >> n >> m;
//        vector<int> a(n + 1), b(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
//        int lasta = 0, lastb = 0;
//        int ans = 0;
//        for (int i = 1; i <= n; i++) {
//            if ((a[i] - lasta) & 1) {
//                if (lastb != b[i]) ans += a[i] - lasta;
//                else ans += a[i] - lasta - 1;
//            } else {
//                if (lastb == b[i]) ans += a[i] - lasta;
//                else ans += a[i] - lasta - 1;
//            }
//            lasta = a[i];
//            lastb = b[i];
//        }
//        ans += m - a[n];
//        cout << ans << endl;
//    }
//    return 0;
//}

// 31. D
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
//        vector<int> ji, ou;
//        for (int i : a) {
//            if (i & 1) ji.emplace_back(i);
//            else ou.emplace_back(i);
//        }
//        int ans = 0;
//        if (ji.size() != 0) {
//            for (int i : ou) ans += i;
//            sort(ji.begin(), ji.end(), greater<>());
//            for (int i = 1; i <= (ji.size() + 1) / 2; i++) ans += ji[i - 1];
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 32. E
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
//        map<int, int> mp;
//        for (int i = 1; i <= n; i++) mp[a[i]]++;
//        int ans = 0;
//        for (auto& [x, y] : mp) {
//            if (y % k != 0) {
//                ans = -1;
//                break;
//            }
//        }
//        if (ans == -1) cout << 0 << endl;
//        else {
//            map<int, int> mp2;
//            for (int i = 1, j = 1; i <= n; i++) {
//                mp2[a[i]]++;
//                while (mp2[a[i]] > mp[a[i]] / k) mp2[a[j++]]--;
//                ans += i - j + 1;
//            }
//            cout << ans << endl;
//        }
//    }
//    return 0;
//}

// 33. F
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<vector<int>> a(n + 1);
//        int mx = 0;
//        for (int i = 1; i <= n; i++) {
//            int k;
//            cin >> k;
//            mx = max(mx, k);
//            a[i].resize(k + 1);
//            for (int j = 1; j <= k; j++) cin >> a[i][j];
//        }
//        a[0].resize(mx + 1, 1e9);
//        vector<int> ans(mx + 1);
//        for (int i = 1; i <= mx; i++) {
//            int mi = 0;
//            for (int j = 1; j <= n; j++) {
//                if (a[j].size() > i && a[j][i] < a[mi][i]) {
//                    mi = j;
//                } else if (a[j].size() > i && a[j][i] == a[mi][i]) {
//                    auto is_mi = [&]() -> bool {
//                        int mi_ = min(a[j].size(), a[mi].size());
//                        for (int i_ = i; i_ < mi_; i_++) {
//                            if (a[j][i_] < a[mi][i_]) return true;
//                            else if (a[j][i_] > a[mi][i_]) return false;
//                        }
//                        return a[j].size() < a[mi].size();
//                    };
//                    if (is_mi()) mi = j;
//                }
//            }
//            while (i < a[mi].size()) ans[i++] = a[mi][i];
//            i--;
//        }
//        for (int i = 1; i <= mx; i++) cout << ans[i] << ' ';
//        cout << endl;
//    }
//    return 0;
//}

// 34. https://www.luogu.com.cn/problem/CF2137E
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
//        auto calc = [&]() {
//            vector<int> c(n + 2);
//            int mex = 0;
//            for (int i = 1; i <= n; i++) c[a[i]]++;
//            for (int i = 0; i <= n + 1; i++) {
//                if (c[i] == 0) {
//                    mex = i;
//                    break;
//                }
//            }
//            for (int i = 1; i <= n; i++) {
//                if (a[i] > mex || c[a[i]] > 1) a[i] = mex;
//            }
//        };
//        calc();
//        int ans = 0;
//        if (k == 1) for (int i = 1; i <= n; i++) ans += a[i];
//        else {
//            k = k % 2 + 1;
//            while (k--) calc();
//            for (int i = 1; i <= n; i++) ans += a[i];
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 35. https://codeforces.com/contest/2140/problem/D
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
//        int ans = 0;
//        for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second, ans += a[i].second - a[i].first;
//        sort(a.begin(), a.end(), [&](pair<int, int>& x, pair<int, int>& y) {
//           return x.first + x.second < y.first + y.second;
//        });
//        int suml = 0, sumr = 0;
//        for (int i = 1; i <= n; i++) {
//            suml += a[i].first * (i <= n / 2);
//            sumr += a[i].second * (i > n / 2);
//        }
//        if (n % 2 == 0) cout << ans + sumr - suml << endl;
//        else {
//            int res = 0;
//            for (int i = 1; i <= n; i++) {
//                if (i <= n / 2) res = max(res, ans + sumr - a[n / 2 + 1].second - (suml + a[n / 2 + 1].first - a[i].first));
//                else res = max(res, ans + sumr - a[i].second - suml);
//            }
//            cout << res << endl;
//        }
//    }
//    return 0;
//}

// VP https://codeforces.com/contest/2144
// 36. A
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
//        for (int i = 1; i <= n; i++) a[i] += a[i - 1];
//        bool have_ans = false;
//        for (int l = 1; l < n; l++) {
//            for (int r = l + 1; r < n; r++) {
//                int s1 = a[l] % 3, s2 = (a[r] - a[l]) % 3, s3 = (a[n] - a[r]) % 3;
//                vector<int> b(3);
//                b[s1]++, b[s2]++, b[s3]++;
//                if ((s1 == s2 && s2 == s3) || (b[0] == 1 && b[1] == 1 && b[2] == 1)) {
//                    cout << l << ' ' << r << endl;
//                    have_ans = true;
//                    break;
//                }
//            }
//            if (have_ans) break;
//        }
//        if (!have_ans) cout << 0 << ' ' << 0 << endl;
//    }
//    return 0;
//}

// 37. B
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
//        int l = 1e9, r = 0;
//        set<int> s;
//        for (int i = 1; i <= n; i++) s.insert(i);
//        for (int i = 1; i <= n; i++) if (a[i] != 0) s.erase(a[i]);
//        for (int i = 1; i <= n; i++) {
//            if (a[i] != 0 && a[i] != i) l = min(i, l), r = max(r, i);
//            if (a[i] == 0) {
//                if (s.size() == 1 && *s.begin() != i) l = min(i, l), r = max(r, i);
//                else if (s.size() >= 2) l = min(i, l), r = max(r, i);
//            }
//        }
//        cout << max(r - l + 1, 0) << endl;
//    }
//    return 0;
//}

// 38. C
//#include <bits/stdc++.h>
//using namespace std;
//const int mod = 998244353;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1), b(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        for (int i = 1; i <= n; i++) cin >> b[i];
//        vector<vector<int>> dp(n + 1, vector<int>(2));
//        dp[1][0] = dp[1][1] = 1;
//        for (int i = 2; i <= n; i++) {
//            if (a[i] >= a[i - 1] && b[i] >= b[i - 1]) dp[i][0] = (dp[i][0] + dp[i - 1][0]) % mod;
//            if (a[i] >= b[i - 1] && b[i] >= a[i - 1]) dp[i][0] = (dp[i][0] + dp[i - 1][1]) % mod;
//            if (a[i] >= a[i - 1] && b[i] >= b[i - 1]) dp[i][1] = (dp[i][1] + dp[i - 1][1]) % mod;
//            if (a[i] >= b[i - 1] && b[i] >= a[i - 1]) dp[i][1] = (dp[i][1] + dp[i - 1][0]) % mod;
//        }
//        cout << (dp[n][0] + dp[n][1]) % mod << endl;
//    }
//    return 0;
//}

// 39. 未知
//#include <bits/stdc++.h>
//using namespace std;
//#define endl '\n'
//
//signed main() {
//    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<vector<int>> a(n + 1);
//        vector<int> du(n + 1);
//        for (int i = 1; i < n; i++) {
//            int u, v, x, y;
//            cin >> u >> v >> x >> y;
//            if (u > v) {
//                swap(u, v);
//                swap(x, y);
//            }
//            if (x > y) a[v].emplace_back(u), du[u]++;
//            else a[u].emplace_back(v), du[v]++;
//        }
//        queue<int> q;
//        vector<int> ans(n + 1);
//        for (int i = 1; i <= n; i++)
//            if (!du[i]) q.emplace(i);
//        int id = 1;
//        while (!q.empty()) {
//            int u = q.front();
//            q.pop();
//            ans[u] = id++;
//            for (int v : a[u]) {
//                du[v]--;
//                if (!du[v]) q.push(v);
//            }
//        }
//        for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
//        cout << endl;
//    }
//    return 0;
//}

// 40. https://www.luogu.com.cn/problem/CF2140C
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
//        int ans = 0;
//        for (int i = 1; i <= n; i++) {
//            if (i & 1) ans += a[i];
//            else ans -= a[i];
//        }
//        int mx = (n & 1 ? n : n - 1) - 1;
//        vector<int> zuo(n + 3, 1e18), you(n + 3, 1e18);
//        for (int i = 1; i <= n; i += 2) {
//            zuo[i] = 2 * a[i] + i;
//            zuo[i] = min(zuo[i], i - 2 < 0 ? 1000000000000000000LL : zuo[i - 2]);
//        }
//        for (int i = (n & 1 ? n : n - 1); i >= 1; i -= 2) {
//            you[i] = 2 * a[i] - i;
//            you[i] = min(you[i], you[i + 2]);
//        }
//        for (int i = 2; i <= n; i += 2) {
//            mx = max(mx, 2 * a[i] + i - zuo[i - 1]);
//            mx = max(mx, 2 * a[i] - i - you[i + 1]);
//        }
//        cout << ans + mx << endl;
//    }
//    return 0;
//}

// 41. https://www.luogu.com.cn/problem/CF2127C
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
//        int ans = 0;
//        int mi = 1e18;
//        for (int i = 1; i <= n; i++) ans += abs(a[i] - b[i]);
//        vector<int> id(n + 1);
//        iota(id.begin(), id.end(), 0);
//        sort(id.begin() + 1, id.end(), [&](int x, int y) {
//            return a[x] + b[y] < a[y] + b[y];
//        });
//        for (int i = 1; i <= n - 1; i++) {
//            int t = i;
//            i = id[i];
//            int i_ = id[t + 1];
//            int yuan = abs(a[i] - b[i]) + abs(a[i_] - b[i_]);
//            vector<int> tmp = {a[i], a[i_], b[i], b[i_]};
//            sort(tmp.begin(), tmp.end());
//            int mx = tmp[3] + tmp[2] - tmp[1] - tmp[0];
//            if (mi > mx - yuan) {
//                mi = mx - yuan;
//            }
//            i = t;
//        }
//        cout << ans + mi << endl;
//    }
//    return 0;
//}

// 42. https://www.luogu.com.cn/problem/CF2065G
//#include <bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 10;
//
//int cnt, primes[N], vis[N];
//
//void euler() {
//    for (int i = 2; i < N; i++) {
//        if (!vis[i]) primes[cnt++] = i;
//        for (int j = 0; 1LL * primes[j] * i < N; j++) {
//            vis[primes[j] * i] = 1;
//            if (i % primes[j] == 0) break;
//        }
//    }
//}
//
//bool fuhe(int x, int& fi) {
//    for (int i = 0; i < cnt && 1LL * primes[i] * primes[i] <= x; i++) {
//        int p = primes[i];
//        if (x % p == 0) {
//            int t = x / p;
//            if (!vis[t]) {
//                fi = p;
//                return true;
//            }
//            else return false;
//        }
//    }
//    return false;
//}
//
//signed main() {
//    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
//    euler();
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        vector<int> s(n + 1), c(n + 1), b(n + 1);
//        long long ans = 0;
//        for (int i = 1; i <= n; i++) {
//            s[i] = !vis[a[i]];
//            s[i] += s[i - 1];
//            c[a[i]]++;
//
//            for (int j = 0; j < cnt && primes[j] * primes[j] <= a[i]; j++) {
//                int p = primes[j];
//                if (a[i] % p == 0) {
//                    int t = a[i] / p;
//                    if (!vis[t]) {
//                        b[p]++;
//                        if (p != t) b[t]++;
//                    }
//                }
//            }
//
//            if (!vis[a[i]]) {
//                ans += s[i] - c[a[i]];
//                ans += b[a[i]];
//            }
//            int t;
//            if (fuhe(a[i], t)) {
//                ans += c[a[i]] + c[t];
//                if (a[i] / t != t) ans += c[a[i] / t];
//            }
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 43. https://www.luogu.com.cn/problem/P2709
//#include <bits/stdc++.h>
//using namespace std;
//const int N = 5e4 + 10;
//
//int a[N], B, c[N];
//long long sum;
//struct node {
//    int l, r, id;
//    bool operator<(const node& b) const {
//        if (l / B != b.l / B) return l < b.l;
//        if (l / B & 1) return r < b.r;
//        return r > b.r;
//    }
//} q[N];
//
//void add(int x) {
//    sum -= 1LL * c[x] * c[x];
//    c[x]++;
//    sum += 1LL * c[x] * c[x];
//}
//
//void del(int x) {
//    sum -= 1LL * c[x] * c[x];
//    c[x]--;
//    sum += 1LL * c[x] * c[x];
//}
//
//signed main() {
//    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
//    int n, m, k;
//    cin >> n >> m >> k;
//    B = (int)sqrt(n);
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    for (int i = 1; i <= m; i++) {
//        cin >> q[i].l >> q[i].r;
//        q[i].id = i;
//    }
//    sort(q + 1, q + 1 + m);
//    vector<long long> ans(m + 1);
//    for (int i = 1, l = 1, r = 0; i <= m; i++) {
//        while (l > q[i].l) add(a[--l]);
//        while (r < q[i].r) add(a[++r]);
//        while (l < q[i].l) del(a[l++]);
//        while (r > q[i].r) del(a[r--]);
//        ans[q[i].id] = sum;
//    }
//    for (int i = 1; i <= m; i++) cout << ans[i] << endl;
//    return 0;
//}

// 44. https://www.luogu.com.cn/problem/CF622C
//#include <bits/stdc++.h>
//using namespace std;
//const int N = 1e6;
//
//struct node {
//    int l, r, x, id;
//    bool operator<(const node& a) const {
//        return x < a.x;
//    }
//};
//
//signed main() {
//    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
//    int n, m;
//    cin >> n >> m;
//    set<int> s;
//    vector<vector<int>> a(N + 1);
//    vector<node> q(m + 1);
//    for (int i = 1; i <= N; i++) s.insert(i);
//    for (int i = 1; i <= n; i++) {
//        int x;
//        cin >> x;
//        a[x].emplace_back(i);
//    }
//    for (int i = 1; i <= m; i++) {
//        cin >> q[i].l >> q[i].r >> q[i].x;
//        q[i].id = i;
//    }
//    sort(q.begin() + 1, q.end());
//    vector<int> ans(m + 1);
//    bool shan = true;
//    for (int i = 1; i <= m; i++) {
//        int x = q[i].x;
//        if (shan)
//            for (int j : a[x]) s.erase(j);
//        auto it = s.lower_bound(q[i].l);
//        if (it != s.end() && *it <= q[i].r) ans[q[i].id] = *it;
//        else ans[q[i].id] = -1;
//        if (i != m && q[i].x != q[i + 1].x) {
//            for (int j : a[x]) s.insert(j);
//            shan = true;
//        } else shan = false;
//    }
//    for (int i = 1; i <= m; i++) cout << ans[i] << endl;
//    return 0;
//}

// 2025.9.21
// 45.
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int n;
//    cin >> n;
//    vector<int> a(n + 1);
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    int ans = 0;
//    vector<int> dp1(n + 1), dp2(n + 1);
//    for (int i = 1; i <= n; i++) {
//        if (a[i] == 1) {
//            dp1[i] = dp1[i - 1] + 1;
//        } else {
//            dp2[i] = dp2[i - 1] + 1;
//        }
//        ans = max(ans, 2 * max(min(dp1[i], dp2[i - dp1[i]]), min(dp2[i], dp1[i - dp2[i]])));
//    }
//    cout << ans << endl;
//    return 0;
//}

// 46.
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int w1, h1, w2, h2;
//    cin >> w1 >> h1 >> w2 >> h2;
//    int h = h1 + h2 + 2;
//    int w = max(w1, w2) + 2;
//    cout << 2 * h + 2 * w - 4;
//    return 0;
//}

// 47.
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int n;
//    cin >> n;
//    vector<int> a(n + 1);
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    for (int i = 1; i <= n; i++) a[i] ^= a[i - 1];
//    unordered_map<int, int> ji, ou;
//    ou[0]++;
//    int ans = 0;
//    for (int i = 1; i <= n; i++) {
//        if (i & 1) {
//            ans += ji[a[i]];
//            ji[a[i]]++;
//        } else {
//            ans += ou[a[i]];
//            ou[a[i]]++;
//        }
//    }
//    cout << ans << endl;
//    return 0;
//}

// 48.
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int n, v;
//    cin >> n >> v;
//    int ans = 0, you = 0;
//    for (int i = 1; i <= n; i++) {
//        if (i + you >= n) break;
//        ans += i * min(v - you, n - i);
//        you += min(v - you, n - i);
//        you--;
//    }
//    cout << ans << endl;
//    return 0;
//}

// 49.
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int n;
//    cin >> n;
//    vector<int> a(n + 1);
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    sort(a.begin() + 1, a.end(), greater<>());
//    vector<int> ans;
//    ans.push_back(a[1]);
//    for (int i = 2; i <= n; i++) {
//        if (i & 1) {
//            ans.push_back(a[i]);
//        } else {
//            ans.insert(ans.begin(), a[i]);
//        }
//    }
//    for (int i : ans) cout << i << ' ';
//    return 0;
//}

// 50.
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//const int N = 2e5 + 10;
//
//signed main() {
//    int n;
//    cin >> n;
//    vector<int> a(n + 1);
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    vector<vector<int>> dp(N, vector<int>(2));
//    for (int i = 1; i <= n; i++) {
//        dp[a[i]][0]++;
//        for (int j = i - 1; j >= 1; j--) {
//            dp[a[i] + a[j]][1]++;
//        }
//    }
//    int mx = 0;
//    for (int i = 0; i < N; i++) mx = max(mx, dp[i][1]);
//    cout << mx << endl;
//    return 0;
//}

// 51.
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int n, m, k;
//    cin >> n >> m >> k;
//    vector<int> a(n + 1), s(n + 1), c(k + 1);
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    for (int i = 1; i <= n; i++) cin >> s[i];
//    for (int i = 1; i <= k; i++) cin >> c[i];
//    vector<int> mx(m + 1);
//    for (int i = 1; i <= n; i++) {
//        mx[s[i]] = max(mx[s[i]], a[i]);
//    }
//    int ans = 0;
//    for (int i = 1; i <= k; i++) {
//        if (a[c[i]] < mx[s[c[i]]]) ans++;
//    }
//    cout << ans << endl;
//    return 0;
//}

// 52.
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int n;
//    cin >> n;
//    vector<int> a(n + 1);
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    int mi = 1e9, mi2 = 1e9, sum = 0;
//    for (int i = 1; i <= n; i++) {
//        sum += a[i];
//        if (mi > a[i]) mi = a[i];
//        else if (mi < a[i] && mi2 > a[i]) mi2 = a[i];
//    }
//    int ans = 1e9;
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= a[i]; j++) {
//            if (a[i] % j == 0) {
//                if (a[i] == mi) {
//                    ans = min(ans, sum - mi2 + j * mi2 - a[i] + a[i] / j);
//                } else {
//                    ans = min(ans, sum - mi + j * mi - a[i] + a[i] / j);
//                }
//            }
//        }
//    }
//    cout << ans << endl;
//    return 0;
//}

// 53.
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int n;
//    cin >> n;
//    vector<pair<int, int>> a(n + 1);
//    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
//    int fi = 0, se = 0;
//    int ans = 0;
//    map<pair<int, int>, bool> vis;
//    for (int i = 1; i <= n; i++) {
//        if (vis[{a[i].first, a[i].second}]) continue;
//        ans += max(0LL, -max(fi, se) + min(a[i].first, a[i].second) + 1);
//        if (fi == se) ans -= vis[{fi, se}];
//        vis[{a[i].first, a[i].second}] = true;
//        fi = a[i].first, se = a[i].second;
//    }
//    cout << ans << endl;
//    return 0;
//}

// 54.
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//bool is_hui(string& s) {
//    for (int i = 0; i <= s.size() / 2 - 1; i++)
//        if (s[i] != s[s.size() - i - 1]) return false;
//    return true;
//}
//
//bool have(string s) {
//    if (!is_hui(s)) return true;
//    if (s.size() & 1) return false;
//    return have(s.substr(0, s.size() / 2));
//}
//
//signed main() {
//    string s;
//    cin >> s;
//    int n = s.size();
//    s = " " + s;
//    unordered_map<char, int> st;
//    for (int i = 1; i <= n; i++) st[s[i]]++;
//    if (st.size() == 1) {
//        cout << "Impossible" << endl;
//        return 0;
//    }
//    if (n & 1) {
//        if (st.size() == 2) {
//            if (st[s[n / 2 + 1]] == 1) {
//                cout << "Impossible" << endl;
//                return 0;
//            } else {
//                cout << 2 << endl;
//                return 0;
//            }
//        }
//        cout << 2 << endl;
//    } else {
//        string sub = s.substr(1, n / 2);
//        if (is_hui(sub)) {
//            if (have(sub)) cout << 1 << endl;
//            else {
//                cout << 2 << endl;
//            }
//        } else {
//            cout << 1 << endl;
//        }
//    }
//    return 0;
//}

// 2025.9.22
// 55. https://codeforces.com/contest/1861/problem/C
//#include <bits/stdc++.h>
//using namespace std;
//
//void solve() {
//    string s;
//    cin >> s;
//    int n = s.size();
//    vector<int> a(n + 1, -1);
//    int len = 0, fi0 = -1, not0 = 1;
//    a[0] = a[1] = 1;
//    for (int i = 0; i < n; i++) {
//        if (s[i] == '+') {
//            if (len >= 1)
//                a[++len] = -1 * not0;
//            else len++;
//        } else if (s[i] == '-') {
//             if (len >= 2) {
//                 if (a[len] == 0 && len == fi0) {
//                     fi0 = -1;
//                     not0 = 1;
//                 }
//                 a[len] = -1;
//             }
//             len--;
//        } else if (s[i] == '1') {
//            if (a[len] == 0) {
//                cout << "NO" << endl;
//                return;
//            } else {
//                if (a[len] == -1) {
//                    for (int j = len; j >= 0; j--) {
//                        if (a[j] == 1) break;
//                        a[j] = 1;
//                    }
//                }
//            }
//        } else {
//            if (a[len] == 1) {
//                cout << "NO" << endl;
//                return;
//            } else {
//                a[len] = 0;
//                if (fi0 == -1) {
//                    fi0 = len;
//                    not0 = 0;
//                }
//            }
//        }
//    }
//    cout << "YES" << endl;
//}
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        solve();
//    }
//    return 0;
//}

// 56. https://www.luogu.com.cn/problem/CF1861D
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 2);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        vector<int> qian(n + 2), hou(n + 2);
//        qian[1] = 1;
//        for (int i = 2; i <= n; i++) {
//            if (a[i] < a[i - 1]) qian[i] = qian[i - 1];
//            else qian[i] = qian[i - 1] + 1;
//        }
//        hou[n] = 1;
//        for (int i = n - 1; i >= 1; i--) {
//            if (a[i] < a[i + 1]) hou[i] = hou[i + 1];
//            else hou[i] = hou[i + 1] + 1;
//        }
//        int ans = 1e9;
//        for (int i = 1; i <= n; i++) ans = min(ans, qian[i - 1] + hou[i] - 1);
//        ans = min(ans, qian[n]);
//        cout << ans << endl;
//    }
//    return 0;
//}

// 57. https://codeforces.com/contest/2116/problem/C
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
//        int g = 0;
//        for (int i = 1; i <= n; i++) cin >> a[i], g = gcd(g, a[i]);
//        vector<int> mi(5001, 1000000);
//        int step = 1000000;
//        bool have_g = false;
//        for (int i = 1; i <= n; i++) {
//            if (a[i] == g) {
//                have_g = true;
//                break;
//            }
//        }
//        if (have_g) {
//            int ans = 0;
//            for (int i = 1; i <= n; i++) ans += (a[i] != g);
//            cout << ans << endl;
//            continue;
//        }
//        for (int i = 1; i <= n; i++) {
//            for (int j = 1; j <= 5000; j++) {
//                mi[gcd(j, a[i])] = min(mi[gcd(j, a[i])], mi[j] + 1);
//            }
//            mi[a[i]] = 1;
//            step = min(step, mi[g]);
//        }
//        for (int i = 1; i <= n; i++) {
//            if (a[i] != g) step++;
//        }
//        cout << step - 2 << endl;
//    }
//    return 0;
//}

// 58. https://www.luogu.com.cn/problem/CF1860B
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int m, k, a1, ak;
//        cin >> m >> k >> a1 >> ak;
//        if (m % k == 0 && ak >= m / k) {
//            cout << 0 << endl;
//        } else {
//            m -= k * min(ak, m / k);
//            if (m <= a1) cout << 0 << endl;
//            else {
//                int mo = m % k;
//                if (mo <= a1) {
//                    cout << (m - a1 + k - 1) / k << endl;
//                } else {
//                    cout << m / k + mo - a1 << endl;
//                }
//            }
//        }
//    }
//    return 0;
//}

// 59. https://www.luogu.com.cn/problem/CF1860C
//#include <bits/stdc++.h>
//using namespace std;
//const int N = 3e5 + 10;
//
//int tr1[N], tr2[N], n;
//
//void add(int x, int y, int tr[]) {
//    for (int i = x; i < n + 1; i += i & -i)
//        tr[i] += y;
//}
//
//int sum(int x, const int tr[]) {
//    int res = 0;
//    for (int i = x; i; i -= i & -i)
//        res += tr[i];
//    return res;
//}
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        cin >> n;
//        memset(tr1, 0, sizeof(int) * (n + 1));
//        memset(tr2, 0, sizeof(int) * (n + 1));
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        int ans = 0;
//        for (int i = 1; i <= n; i++) {
//            if (sum(a[i], tr2) == 0 || sum(a[i], tr1) != sum(a[i], tr2)) {
//                add(a[i], 1, tr1);
//            } else {
//                ans++;
//            }
//            add(a[i], 1, tr2);
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// VP Codeforces Round 1002 (Div. 2)
// 60. A
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        set<int> a, b;
//        for (int i = 1; i <= n; i++) {
//            int x;
//            cin >> x;
//            a.insert(x);
//        }
//        for (int i = 1; i <= n; i++) {
//            int x;
//            cin >> x;
//            b.insert(x);
//        }
//        if (a.size() + b.size() >= 4) cout << "YES" << endl;
//        else cout << "NO" << endl;
//    }
//    return 0;
//}

// 61. C
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<vector<int>> a(n + 1, vector<int>(n + 1));
//        for (int i = 1; i <= n; i++) {
//            for (int j = 1; j <= n; j++) {
//                cin >> a[i][j];
//            }
//        }
//        multiset<int> s;
//        for (int i = 1; i <= n; i++) {
//            int cnt = 0;
//            for (int j = n; j >= 1; j--) {
//                if (a[i][j] == 1) cnt++;
//                else break;
//            }
//            s.insert(cnt);
//        }
//        int i;
//        for (i = 0; i <= n; i++) {
//            if (s.empty()) {
//                break;
//            }
//            s.erase(s.begin());
//            auto it = s.upper_bound(i);
//            if (it != s.begin()) s.erase(s.begin(), it);
//        }
//        cout << i << endl;
//    }
//    return 0;
//}

// 62. D
//#include <bits/stdc++.h>
//using namespace std;
//
//struct node {
//    int x, y, v;
//    bool operator<(const node& a) const {
//        return v > a.v;
//    }
//};
//
//signed main() {
//    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, s1, s2;
//        cin >> n >> s1 >> s2;
//        int m1, m2;
//        cin >> m1;
//        vector<vector<vector<int>>> e(2, vector<vector<int>>(n + 1, vector<int>(n + 1)));
//        vector<vector<int>> g1(n + 1), g2(n + 1);
//        for (int i = 1, u, v; i <= m1; i++) {
//            cin >> u >> v;
//            e[0][u][v] = 1;
//            e[0][v][u] = 1;
//            g1[u].emplace_back(v);
//            g1[v].emplace_back(u);
//        }
//        cin >> m2;
//        for (int i = 1, u, v; i <= m2; i++) {
//            cin >> u >> v;
//            e[1][u][v] = 1;
//            e[1][v][u] = 1;
//            g2[u].emplace_back(v);
//            g2[v].emplace_back(u);
//        }
//        vector<int> f(n + 1);
//        for (int i = 1; i <= n; i++) {
//            for (int j = 1; j <= n; j++) {
//                f[i] |= (e[0][i][j] && e[1][i][j]);
//            }
//        }
//        vector<vector<int>> dist(n + 1, vector<int>(n + 1, 2e9));
//        vector<vector<bool>> vis(n + 1, vector<bool>(n + 1));
//        dist[s1][s2] = 0;
//        priority_queue<node> q;
//        q.push({s1, s2, 0});
//        while (!q.empty()) {
//            node d = q.top();
//            q.pop();
//            if (vis[d.x][d.y]) continue;
//            vis[d.x][d.y] = true;
//            for (int v1 : g1[d.x]) {
//                for (int v2 : g2[d.y]) {
//                    if (!vis[v1][v2]) {
//                        if (d.v + abs(v1 - v2) < dist[v1][v2]) {
//                            dist[v1][v2] = d.v + abs(v1 - v2);
//                            q.push({v1, v2, dist[v1][v2]});
//                        }
//                    }
//                }
//            }
//        }
//        int ans = 2e9;
//        for (int i = 1; i <= n; i++)
//            if (f[i]) ans = min(ans, dist[i][i]);
//        if (ans == 2e9) ans = -1;
//        cout << ans << endl;
//    }
//    return 0;
//}

// 63. https://atcoder.jp/contests/abc424/tasks/abc424_f
//#include <bits/stdc++.h>
//using namespace std;
//const int N = 1e6 + 10;
//
//struct node {
//    int l, r;
//    int mx, mi;
//} tr[N << 2];
//
//void pushup(int u) {
//    tr[u].mx = max(tr[u << 1].mx, tr[u << 1 | 1].mx);
//    tr[u].mi = min(tr[u << 1].mi, tr[u << 1 | 1].mi);
//}
//
//void pushup(node& rt, node& le, node& ri) {
//    rt.mx = max(le.mx, ri.mx);
//    rt.mi = min(le.mi, ri.mi);
//}
//
//void build(int u, int l, int r) {
//    tr[u] = {l, r, -1, N};
//    if (l == r) return;
//    int mid = (l + r) >> 1;
//    build(u << 1, l, mid);
//    build(u << 1 | 1, mid + 1, r);
//    pushup(u);
//}
//
//node query(int u, int l, int r) {
//    if (l <= tr[u].l && tr[u].r <= r) return tr[u];
//    int mid = (tr[u].l + tr[u].r) >> 1;
//    if (r <= mid) return query(u << 1, l, r);
//    else if (l > mid) return query(u << 1 | 1, l, r);
//    else {
//        node rt;
//        node le = query(u << 1, l, mid);
//        node ri = query(u << 1 | 1, mid + 1, r);
//        pushup(rt, le, ri);
//        return rt;
//    }
//}
//
//void modify(int u, int x, int y, int op) {
//    if (tr[u].l == tr[u].r) {
//        if (op == 1) tr[u].mx = max(tr[u].mx, y);
//        else tr[u].mi = min(tr[u].mi, y);
//    } else {
//        int mid = (tr[u].l + tr[u].r) >> 1;
//        if (x <= mid) modify(u << 1, x, y, op);
//        else modify(u << 1 | 1, x, y, op);
//        pushup(u);
//    }
//}
//
//signed main() {
//    int n, q;
//    cin >> n >> q;
//    build(1, 1, n);
//    for (int i = 1, l, r; i <= q; i++) {
//        cin >> l >> r;
//        node d = query(1, l, r);
//        if (d.mx > r || d.mi < l) cout << "No" << endl;
//        else {
//            cout << "Yes" << endl;
//            modify(1, l, r, 1);
//            modify(1, r, l, 2);
//        }
//    }
//    return 0;
//}

// 64. https://codeforces.com/contest/2151/problem/D
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//const int N = 2e5 + 10;
//const int mod = 998244353;
//int fact[N], infact[N];
//
//int ksm(int a, int k, int mod) {
//    int res = 1;
//    a %= mod;
//    while (k) {
//        if (k & 1) res = 1LL * res * a % mod;
//        a = 1LL * a * a % mod;
//        k >>= 1;
//    }
//    return res;
//}
//
//void init() {
//    infact[0] = fact[0] = 1;
//    for (int i = 1; i < N; i++) {
//        fact[i] = 1LL * fact[i - 1] * i % mod;
//        infact[i] = 1LL * infact[i - 1] * ksm(i, mod - 2, mod) % mod;
//    }
//}
//// 从 n 个里面选 m 个
//int C(int n, int m) {
//    return (1LL * fact[n] * infact[n - m] % mod) * infact[m] % mod;
//}
//
//
//signed main() {
//    init();
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1);
//        int sum = 0;
//        for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
//        if (sum != n) cout << 0 << endl;
//        else {
//            int ans = 1;
//            int zi = (n & 1 ? 1 : 2);
//            for (int i = (n + 1) / 2; i >= 1; i--) {
//                if (a[i] > zi) {
//                    ans = 0;
//                    break;
//                }
//                if (i == 1 && zi != a[i]) {
//                    ans = 0;
//                    break;
//                }
//                ans = ans * C(zi, zi - a[i]) % mod;
//                zi = 2 + zi - a[i];
//            }
//            cout << ans << endl;
//        }
//    }
//    return 0;
//}

// 65. https://codeforces.com/contest/2151/problem/B
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, m;
//        cin >> n >> m;
//        string s;
//        cin >> s;
//        set<int> st;
//        for (int i = 1, x; i <= m; i++) {
//            cin >> x;
//            st.insert(x);
//        }
//        int wei = 1;
//        for (int i = 0; i < n; i++) {
//            if (s[i] == 'A') {
//                wei++;
//                st.insert(wei);
//            } else {
//                wei++;
//                for (; st.find(wei) != st.end(); wei++);
//                st.insert(wei);
//                for (; st.find(wei) != st.end(); wei++);
//            }
//        }
//        cout << st.size() << endl;
//        for (int i : st) cout << i << ' ';
//        cout << endl;
//    }
//    return 0;
//}

// 66. https://codeforces.com/contest/2151/problem/C
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
//        int n2 = n << 1;
//        vector<int> a(n2 + 1);
//        for (int i = 1; i <= n2; i++) cin >> a[i];
//        vector<int> jia(n2 + 1);
//        for (int i = 1; i <= n2; i++) {
//            jia[i] = (i & 1 ? -a[i] : a[i]);
//            jia[i] += jia[i - 1];
//        }
//        int qian = 0;
//        for (int i = 1, l = 1, r = n2; i <= n; i++, l++, r--) {
//            qian += a[r] - a[l];
//            if (i & 1) cout << qian + (jia[r - 1] - jia[l]) << ' ';
//            else cout << qian - (jia[r - 1] - jia[l]) << ' ';
//        }
//        cout << endl;
//    }
//    return 0;
//}

// 67. https://codeforces.com/contest/2149/problem/D
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
//        vector<int> a, b;
//        for (int i = 1; i <= n; i++) {
//            if (s[i] == 'a') a.emplace_back(i);
//            else b.emplace_back(i);
//        }
//        if (a.empty() || b.empty()) {
//            cout << 0 << endl;
//            continue;
//        }
//        for (int i = 0; i < a.size(); i++) a[i] -= i + 1;
//        for (int i = 0; i < b.size(); i++) b[i] -= i + 1;
//        int mid = a[a.size() / 2];
//        int ans1 = 0;
//        for (int i : a) ans1 += abs(i - mid);
//        int ans2 = 0;
//        mid = b[b.size() / 2];
//        for (int i : b) ans2 += abs(i - mid);
//        cout << min(ans1, ans2) << endl;
//    }
//    return 0;
//}

// 68. https://codeforces.com/contest/2149/problem/E
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, k, l, r;
//        cin >> n >> k >> l >> r;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        set<int> st;
//        map<int, int> cnt;
//        vector<int> mx(n + 1), mi(n + 1);
//        for (int i = 1, j = 0; i <= n; i++) {
//            while (j <= n && st.size() <= k) {
//                st.insert(a[++j]);
//                cnt[a[j]]++;
//            }
//            mx[i] = j - 1;
//            cnt[a[i]]--;
//            if (cnt[a[i]] == 0) st.erase(a[i]);
//        }
//        st.clear(), cnt.clear();
//        for (int i = 1, j = 0; i <= n; i++) {
//            while (j <= n && st.size() < k) {
//                st.insert(a[++j]);
//                cnt[a[j]]++;
//            }
//            mi[i] = j;
//            cnt[a[i]]--;
//            if (cnt[a[i]] == 0) st.erase(a[i]);
//        }
//        long long ans = 0;
//        for (int i = 1; i <= n; i++) {
//            ans += max(0, min(i + r - 1, mx[i]) - max(i + l - 1, mi[i]) + 1);
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 2025.9.29
// VP Educational Codeforces Round 152 (Rated for Div. 2)
// 69. A
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int a, b, c;
//        cin >> a >> b >> c;
//        b += c;
//        cout << min(2 * a - 1, 2 * b + 1) << endl;
//    }
//    return 0;
//}

// 70. B
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
//        for (int i = 1; i <= n; i++) {
//            cin >> a[i];
//            a[i] %= k;
//            if (a[i] == 0) a[i] = k;
//        }
//        vector<int> ans(n + 1);
//        iota(ans.begin(), ans.end(), 0);
//        sort(ans.begin() + 1, ans.end(), [&](int x, int y) {
//           if (a[x] != a[y]) return a[x] > a[y];
//           return x < y;
//        });
//        for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
//        cout << endl;
//    }
//    return 0;
//}

// 71. C
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//const int P = 131, N = 2e5 + 10;
//
//unsigned long long p[N], p2[N];
//
//signed main() {
//    int T;
//    cin >> T;
//    p[0] = 1;
//    for (int i = 1; i < N; i++) p[i] = P * p[i - 1];
//    for (int i = 1; i < N; i++) p2[i] = P * p2[i - 1] + 1;
//    while (T--) {
//        int n, m;
//        cin >> n >> m;
//        string s;
//        cin >> s;
//        s = " " + s;
//        set<unsigned long long> st;
//        vector<int> hash(n + 1), one(n + 1);
//        for (int i = 1; i <= n; i++) {
//            hash[i] = P * hash[i - 1] + s[i] - '0';
//            one[i] = one[i - 1] + s[i] - '0';
//        }
//        auto get = [&](int l, int r) -> unsigned long long {
//            if (l > r) return 0;
//            return hash[r] - hash[l - 1] * p[r - l + 1];
//        };
//        auto calc = [&](int l, int r) -> unsigned long long {
//            int cnt = one[r] - one[l - 1];
//            return hash[l - 1] * p[n - l + 1] + p2[cnt] * p[n - r] + get(r + 1, n);
//        };
//        for (int i = 1; i <= m; i++) {
//            int l, r;
//            cin >> l >> r;
//            st.insert(calc(l, r));
//        }
//        cout << st.size() << endl;
//    }
//    return 0;
//}

// 72. D
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int T = 1;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        vector<vector<int>> dp(n + 1, vector<int>(3, 1e18));
//        vector<int> pre(n + 1);
//        pre[1] = 1;
//        for (int i = 2; i <= n; i++) pre[i] = a[i] ? pre[i - 1] : i;
//        dp[0][0] = 0;
//        for (int i = 1; i <= n; i++) {
//            dp[i][a[i]] = min(1 + dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2]));
//            if (a[i] > 0) dp[i][a[i] - 1] = 1 + min(dp[pre[i] - 1][0], min(dp[pre[i] - 1][1], dp[pre[i] - 1][2]));
//        }
//        cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << endl;
//    }
//    return 0;
//}

// 2025.9.30
// 73. https://www.luogu.com.cn/problem/CF2134B
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
//        for (int i = 1; i <= n; i++) {
//            int mod = a[i] % (k + 1);
//            a[i] += mod * k;
//        }
//        for (int i = 1; i <= n; i++) cout << a[i] << ' ';
//        cout << endl;
//    }
//    return 0;
//}

// 74. https://www.luogu.com.cn/problem/CF2134C
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
//        int ans = 0;
//        for (int i = 2; i <= n; i += 2) {
//            if (a[i - 1] > a[i]) {
//                ans += a[i - 1] - a[i];
//                a[i - 1] = a[i];
//            }
//            if (a[i - 1] + a[i + 1] > a[i]) {
//                ans += a[i + 1] + a[i - 1] - a[i];
//                a[i + 1] -= a[i + 1] + a[i - 1] - a[i];
//            }
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 2025.10.1   VP https://codeforces.com/contest/1845
// 75. A
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, k, x;
//        cin >> n >> k >> x;
//        if (x != 1) {
//            cout << "YES" << endl;
//            cout << n << endl;
//            for (int i = 1; i <= n; i++) cout << 1 << ' ';
//            cout << endl;
//        } else {
//            if (k == 1) cout << "NO" << endl;
//            else {
//                if (k == 2) {
//                    if (n % 2 == 0) {
//                        cout << "YES" << endl;
//                        cout << n / 2 << endl;
//                        for (int i = 1; i <= n / 2; i++) cout << 2 << ' ';
//                        cout << endl;
//                    } else cout << "NO" << endl;
//                } else {
//                    cout << "YES" << endl;
//                    vector<int> ans;
//                    if (n % 3 == 0) {
//                        for (int i = 1; i <= n / 3; i++) ans.emplace_back(3);
//                    } else if (n % 3 == 1) {
//                        ans.emplace_back(2);
//                        ans.emplace_back(2);
//                        n -= 4;
//                        for (int i = 1; i <= n / 3; i++) ans.emplace_back(3);
//                    } else {
//                        ans.emplace_back(2);
//                        n -= 2;
//                        for (int i = 1; i <= n / 3; i++) ans.emplace_back(3);
//                    }
//                    cout << ans.size() << endl;
//                    for (int i : ans) cout << i << ' ';
//                    cout << endl;
//                }
//            }
//        }
//    }
//    return 0;
//}

// 76. B
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//int dist(int x, int y, int a, int b) {
//    return abs(x - a) + abs(y - b) + 1;
//}
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int xa, xb, xc, ya, yb, yc;
//        cin >> xa >> ya >> xb >> yb >> xc >> yc;
//        int y1 = yb - ya, y2 = yc - ya;
//        int x1 = xb - xa, x2 = xc - xa;
//        if (y1 * y2 < 0) {
//            if (x1 * x2 < 0) cout << 1 << endl;
//            else cout << min(abs(x1), abs(x2)) + 1 << endl;
//        } else {
//            if (x1 * x2 < 0) cout << min(abs(y1), abs(y2)) + 1 << endl;
//            else {
//                if (x1 == x2 || y1 == y2) {
//                    cout << min(dist(xa, ya, xb, yb), dist(xa, ya, xc, yc)) << endl;
//                } else {
//                    if ((abs(x1) > abs(x2) && abs(y1) > abs(y2)) || (abs(x1) < abs(x2) && abs(y1) < abs(y2))) {
//                        cout << min(dist(xa, ya, xb, yb), dist(xa, ya, xc, yc)) << endl;
//                    } else {
//                        cout << min(abs(x1), abs(x2)) + min(abs(y1), abs(y2)) + 1 << endl;
//                    }
//                }
//            }
//        }
//    }
//    return 0;
//}

// 77. C
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
//        int m;
//        string l, r;
//        cin >> m >> l >> r;
//        l = " " + l;
//        r = " " + r;
//        unordered_map<char, vector<int>> mp;
//        for (int i = 1; i <= n; i++) mp[s[i]].emplace_back(i);
//        int id = 0;
//        for (int i = 1; i <= m; i++) {
//            int nxt = 0;
//            for (char c = l[i]; c <= r[i]; c++) {
//                auto it = upper_bound(mp[c].begin(), mp[c].end(), id);
//                if (it == mp[c].end()) {
//                    nxt = 1e9;
//                    break;
//                }
//                nxt = max(nxt, *it);
//            }
//            id = nxt;
//            if (id == (int)1e9) break;
//        }
//        if (id == (int)1e9) cout << "YES" << endl;
//        else cout << "NO" << endl;
//    }
//    return 0;
//}

// 78. D
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
//        vector<int> dp(n + 2), sum(n + 1);
//        for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
//        dp[n] = a[n] < 0 ? n + 1 : n;
//        dp[n + 1] = n + 1;
//        for (int i = n - 1; i >= 1; i--) {
//            if (a[i] < 0) dp[i] = dp[i + 1];
//            else {
//                if (sum[dp[i + 1] - 1] - sum[i - 1] <= 0) dp[i] = dp[i + 1];
//                else dp[i] = i;
//            }
//        }
//        int mx = sum[0] + sum[n] - sum[dp[1] - 1], ans = 0;
//        for (int i = 1; i <= n; i++) {
//            int t = sum[i] + sum[n] - sum[dp[i + 1] - 1];
//            if (t > mx) {
//                mx = t;
//                ans = sum[i];
//            }
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 79. https://codeforces.com/problemset/problem/1841/C
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//unordered_map<char, int> fen = {
//        {'A', 1},
//        {'B', 10},
//        {'C', 100},
//        {'D', 1000},
//        {'E', 10000},
//};
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        string s;
//        cin >> s;
//        int n = s.size();
//        s = " " + s;
//        unordered_map<char, int> fi, ed;
//        for (int i = 1; i <= n; i++) {
//            if (fi.find(s[i]) == fi.end()) {
//                fi[s[i]] = i;
//            }
//            ed[s[i]] = i;
//        }
//        auto calc = [&]() -> int {
//            char mx = s[n];
//            int res = fen[s[n]];
//            for (int i = n - 1; i >= 1; i--) {
//                if (mx > s[i]) res -= fen[s[i]];
//                else res += fen[s[i]];
//                mx = max(mx, s[i]);
//            }
//            return res;
//        };
//        int ans = calc();
//        for (char c = 'A'; c <= 'E'; c++) {
//            for (char b = 'A'; b <= 'E'; b++) {
//                if (c == b) continue;
//                if (c > b) {
//                    if (ed[c]) {
//                        s[ed[c]] = b;
//                        ans = max(ans, calc());
//                        s[ed[c]] = c;
//                    }
//                } else {
//                    if (fi[c]) {
//                        s[fi[c]] = b;
//                        ans = max(ans, calc());
//                        s[fi[c]] = c;
//                    }
//                }
//            }
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 80. https://www.luogu.com.cn/problem/P2388
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int n;
//    cin >> n;
//    auto gauss_sum = [](int x) {
//        return 1LL * (x + 1) * x / 2;
//    };
//    long long ans = 0;
//    long long sum = gauss_sum(n);
//    for (int j = 5; j <= n; j *= 5) {
//        long long he = sum - (gauss_sum(j - 1) * (n / j) + gauss_sum(n % j));
//        ans += he / j;
//    }
//    cout << ans << endl;
//    return 0;
//}

// 2025.10.6
// VP https://codeforces.com/contest/1837
// 81. A
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, k;
//        cin >> n >> k;
//        if (n % k != 0) {
//            cout << 1 << endl << n << endl;
//        } else {
//            cout << 2 << endl << n - 1 << ' ' << 1 << endl;
//        }
//    }
//    return 0;
//}

// 82. B
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
//        int ans = 1;
//        int x = 1;
//        for (int i = 1; i < n; i++) {
//            if (s[i] == s[i - 1]) x++;
//            else x = 1;
//            ans = max(ans, x);
//        }
//        cout << ans + 1 << endl;
//    }
//    return 0;
//}

// 83. C
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        string s;
//        cin >> s;
//        char pre = '.';
//        for (char i : s) {
//            if (i != '?') {
//                pre = i;
//                break;
//            }
//        }
//        if (pre == '.') {
//            cout << string(s.size(), '0') << endl;
//        } else {
//            for (char & i : s) {
//                if (i == '?') i = pre;
//                else pre = i;
//            }
//            cout << s << endl;
//        }
//    }
//    return 0;
//}

// 84. D
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
//        if (n & 1) {
//            cout << -1 << endl;
//            continue;
//        }
//        int zuo = 0, you = 0;
//        for (int i = 1; i <= n; i++) {
//            if (s[i] == '(') zuo++;
//            else you++;
//        }
//        if (zuo != you) {
//            cout << -1 << endl;
//            continue;
//        }
//        auto fuhe = [](string& s) -> bool {
//            int x = 0;
//            int n = s.size() - 1;
//            for (int i = 1; i <= n; i++) {
//                x += (s[i] == '(' ? 1 : -1);
//                if (x < 0) return false;
//            }
//            return true;
//        };
//        string s2 = s;
//        for (int i = 1; i <= n; i++) {
//            if (s2[i] == ')') s2[i] = '(';
//            else s2[i] = ')';
//        }
//        if (fuhe(s) || fuhe(s2)) {
//            cout << 1 << endl;
//            for (int i = 1; i <= n; i++) cout << 1 << ' ';
//            cout << endl;
//        } else {
//            cout << 2 << endl;
//            vector<int> ans(n + 1, 1);
//            stack<int> st;
//            for (int i = 1; i <= n; i++) {
//                if (s[i] == '(') st.push(i);
//                else {
//                    if (!st.empty()) {
//                        ans[st.top()] = 2;
//                        ans[i] = 2;
//                        st.pop();
//                    }
//                }
//            }
//            for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
//            cout << endl;
//        }
//    }
//    return 0;
//}

// 2025.10.6 两极反转
// 85.
//#include <bits/stdc++.h>
//using namespace std;
//#define int unsigned
//
//signed main() {
//    int n, q;
//    cin >> n >> q;
//    vector<int> a(n + 1);
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    vector<int> l(n + 1);
//    l[1] = 1;
//    auto keyi = [](int x, int y) -> bool {
//        if (x >> 31 & 1) x = ~x;
//        if (y >> 31 & 1) y = ~y;
//        if ((x & 1) != (y & 1)) return false;
//        vector<int> a, b;
//        a.push_back(0), b.push_back(0);
//        for (signed i = 31; i >= 0; i--) {
//            if (a.back() != (x >> i & 1)) a.push_back(x >> i & 1);
//            if (b.back() != (y >> i & 1)) b.push_back(y >> i & 1);
//        }
//        int ac = 0, bc = 0;
//        for (int i : a) ac += i;
//        for (int i : b) bc += i;
//        return ac == bc;
//    };
//    for (int i = 2; i <= n; i++) {
//        if (keyi(a[i], a[i - 1])) l[i] = l[i - 1];
//        else l[i] = i;
//    }
//    while (q--) {
//        int x, y;
//        cin >> x >> y;
//        if (x < l[y]) cout << "No" << endl;
//        else cout << "Yes" << endl;
//    }
//    return 0;
//}

// VP Educational Codeforces Round 183 (Rated for Div. 2)   好菜
// 86. A
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        cout << (3 - n % 3) % 3 << endl;
//    }
//    return 0;
//}

// 87. B
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, k;
//        cin >> n >> k;
//        string s;
//        cin >> s;
//        s = " " + s;
//        string ans(n + 1, '+');
//        int l = 1, r = n, cnt = 0;
//        for (int i = 1; i <= k; i++) {
//            if (s[i] == '0') ans[l++] = '-';
//            else if (s[i] == '1') ans[r--] = '-';
//            else cnt++;
//        }
//        for (int i = l, x = 1; x <= cnt; x++, i++) {
//            ans[i] = '?';
//        }
//        for (int i = r, x = 1; x <= cnt; x++, i--) {
//            ans[i] = '?';
//        }
//        if (cnt >= r - l + 1) cout << string(n, '-') << endl;
//        else cout << ans.substr(1) << endl;
//    }
//    return 0;
//}

// 88. C
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
//        int sum = 0;
//        for (int i = 1; i <= n; i++) {
//            if (s[i] == 'a') sum += 1;
//            else sum += -1;
//        }
//        unordered_map<int, int> mp;
//        mp[0] = 0;
//        int x = 0, ans = 1e9;
//        if (sum == 0) ans = 0;
//        for (int i = 1; i <= n; i++) {
//            if (s[i] == 'a') x += 1;
//            else x += -1;
//            if (mp.find(x - sum) != mp.end()) {
//                ans = min(ans, i - mp[x - sum]);
//            }
//            mp[x] = i;
//        }
//        cout << (ans == 1e9 || ans == n ? -1 : ans) << endl;
//    }
//    return 0;
//}

// 89. D
//#include <bits/stdc++.h>
//using namespace std;
//const int N = 31;
//
//int dp[N][N * N], last[N][N * N];
//
//signed main() {
//    dp[0][0] = 1;
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N * N; j++) {
//            if (!dp[i][j]) continue;
//            for (int k = 1; k + i < N; k++) {
//                dp[i + k][j + k * (k - 1) / 2] = 1;
//                last[i + k][j + k * (k - 1) / 2] = k;
//            }
//        }
//    }
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, k;
//        cin >> n >> k;
//        k = n * (n - 1) / 2 - k;
//        if (dp[n][k]) {
//            vector<int> ans(n + 1);
//            int id = 0, len = n;
//            int p = last[n][k];
//            int n_ = n;
//            while (n_) {
//                id += p;
//                for (int i = id; i > id - p; i--) ans[len--] = i;
//                n_ -= p;
//                k -= p * (p - 1) / 2;
//                p = last[n_][k];
//            }
//            for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
//            cout << endl;
//        } else {
//            cout << 0 << endl;
//        }
//    }
//    return 0;
//}

// 90. https://www.luogu.com.cn/problem/CF2146D1
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//struct node {
//    int cnt = 0, nxt0 = 0, nxt1 = 0;
//    int& operator[](int x) {
//        if (x == 1) return nxt1;
//        return nxt0;
//    }
//};
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int l, r;
//        cin >> l >> r;
//        vector<node> a(1);
//        auto add = [&](int x) -> void {
//            int p = 0;
//            for (int i = 29; i >= 0; i--) {
//                int bit = x >> i & 1;
//                if (a[p][bit]) {
//                    a[a[p][bit]].cnt++;
//                    p = a[p][bit];
//                } else {
//                    a[p][bit] = a.size();
//                    a.push_back({1, 0, 0});
//                    p = a[p][bit];
//                }
//            }
//        };
//        auto calc = [&](int x) -> int {
//            int p = 0;
//            int res = 0;
//            for (int i = 29; i >= 0; i--) {
//                int bit = x >> i & 1;
//                if (a[p][!bit] && a[a[p][!bit]].cnt) {
//                    res = (res << 1) + !bit;
//                    a[a[p][!bit]].cnt--;
//                    p = a[p][!bit];
//                } else {
//                    res = (res << 1) + bit;
//                    a[a[p][bit]].cnt--;
//                    p = a[p][bit];
//                }
//            }
//            return res;
//        };
//        unordered_map<int, int> ans;
//        int res = 0;
//        for (int i = l; i <= r; i++) add(i);
//        for (int i = l; i <= r; i++) {
//            ans[i] = calc(i);
//            res += (ans[i] | i);
//        }
//        cout << res << endl;
//        for (int i = l; i <= r; i++) {
//            cout << ans[i] << ' ';
//        }
//        cout << endl;
//    }
//    return 0;
//}

// 2025.10.10   VP Educational Codeforces Round 147 (Rated for Div. 2)
// 91. A
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        string s;
//        cin >> s;
//        if (s[0] == '0') cout << 0 << endl;
//        else {
//            int ans = 1;
//            for (int i = 0; i < s.size(); i++) {
//                if (s[i] == '?') {
//                    if (i == 0) ans *= 9;
//                    else ans *= 10;
//                }
//            }
//            cout << ans << endl;
//        }
//    }
//    return 0;
//}

// 92. B
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1), b(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        for (int i = 1; i <= n; i++) cin >> b[i];
//        int l = 1e9, r = -1;
//        for (int i = 1; i <= n; i++) {
//            if (a[i] != b[i]) {
//                l = min(l, i);
//                r = max(r, i);
//            }
//        }
//        int mi = *min_element(a.begin() + l, a.begin() + r + 1);
//        int mx = *max_element(a.begin() + l, a.begin() + r + 1);
//        while (l > 1 && a[l - 1] <= mi) {
//            l--;
//            mi = a[l];
//        }
//        while (r < n && a[r + 1] >= mx) {
//            r++;
//            mx = a[r];
//        }
//        cout << l << ' ' << r << endl;
//    }
//    return 0;
//}

// 93. C
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
//        s = " " + s;
//        if (n == 1) {
//            cout << 0 << endl;
//            continue;
//        }
//        auto get = [](auto&& self, int x) -> int {
//            if (x <= 2) return x;
//            return 1 + self(self, x / 2);
//        };
//        unordered_map<char, vector<int>> mp;
//        for (int i = 1; i <= n; i++) mp[s[i]].emplace_back(i);
//        int ans = 1e9;
//        for (char c = 'a'; c <= 'z'; c++) {
//            if (mp[c].empty()) continue;
//            int mx = max(mp[c].front() - 1, n - mp[c].back());
//            for (int i = 1; i < mp[c].size(); i++) mx = max(mx, mp[c][i] - mp[c][i - 1] - 1);
//            ans = min(ans, get(get, mx));
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 94. D
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
//        vector<int> l(n + 1), r(n + 1);
//        for (int i = 1; i <= n; i++) cin >> l[i];
//        for (int i = 1; i <= n; i++) cin >> r[i];
//        int sum = 0;
//        for (int i = 1; i <= n; i++) sum += r[i] - l[i] + 1;
//        if (sum < k) {
//            cout << -1 << endl;
//            continue;
//        }
//        sum = 0;
//        int one = 0, two = 0, ans = 1e18;
//        for (int i = 1; i <= n; i++) {
//            int len = r[i] - l[i] + 1;
//            if (len == 1) one++;
//            else {
//                two++;
//                sum += len;
//            }
//            if (sum >= k) {
//                ans = min(ans, r[i] - (sum - k) + 2 * two);
//            }
//            if (sum + one >= k && sum < k) {
//                ans = min(ans, r[i] + two * 2 + (k - sum) * 2);
//            }
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 2025.10.10   Codeforces Round 1057 (Div. 2)
// 95. A
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        set<int> s;
//        for (int i = 1, x; i <= n; i++) {
//            cin >> x;
//            s.insert(x);
//        }
//        cout << s.size() << endl;
//    }
//    return 0;
//}

// 96. B
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int x, y, z;
//        cin >> x >> y >> z;
//        bool yes = true;
//        for (int i = 0; i <= 30; i++) {
//            int sum = (x >> i & 1) + (y >> i & 1) + (z >> i & 1);
//            if (sum == 2) {
//                yes = false;
//                break;
//            }
//        }
//        if (yes) cout << "YES" << endl;
//        else cout << "NO" << endl;
//    }
//    return 0;
//}

// 97. C
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
//        map<int, int> mp;
//        for (int i = 1; i <= n; i++) {
//            int x;
//            cin >> x;
//            mp[x]++;
//        }
//        int ans = 0, c = 0;
//        bool is_o = true;
//        for (auto& [x, cnt] : mp) {
//            if (cnt >= 2) {
//                is_o = false;
//                ans += x * (cnt / 2 * 2);
//                c += (cnt / 2 * 2);
//                cnt -= (cnt / 2 * 2);
//            }
//        }
//        priority_queue<int> q;
//        for (auto& [x, cnt] : mp) {
//            if (cnt) q.push(x);
//        }
//        if (is_o) cout << 0 << endl;
//        else {
//            int res = ans;
//            while (!q.empty()) {
//                int mx = q.top();
//                q.pop();
//                if (ans > mx) res = max(res, ans + mx);
//                if (!q.empty()) {
//                    int ne = q.top();
//                    if (ne + ans > mx) res = max(res, ans + mx + ne);
//                }
//            }
//            if (res == ans && c == 2) cout << 0 << endl;
//            else cout << res << endl;
//        }
//    }
//    return 0;
//}

// 98. D
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//int calc(int a, int b, int c) {
//    int mx = max(a, max(b, c));
//    int mi = min(a, min(b, c));
//    return mx - mi;
//}
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 3);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        a[n + 1] = a[1], a[n + 2] = a[2];
//        vector<int> dp(n + 3, 1e18);
//        dp[0] = 0;
//        dp[2] = abs(a[2] - a[1]);
//        for (int i = 3; i <= n; i++) {
//            dp[i] = min(dp[i], dp[i - 2] + abs(a[i] - a[i - 1]));
//            dp[i] = min(dp[i], dp[i - 3] + calc(a[i], a[i - 1], a[i - 2]));
//        }
//        int ans = dp[n];
//        dp.assign(n + 3, 1e18);
//        dp[1] = 0;
//        dp[3] = abs(a[3] - a[2]);
//        for (int i = 4; i <= n + 1; i++) {
//            dp[i] = min(dp[i], dp[i - 2] + abs(a[i] - a[i - 1]));
//            dp[i] = min(dp[i], dp[i - 3] + calc(a[i], a[i - 1], a[i - 2]));
//        }
//        ans = min(dp[n + 1], ans);
//        dp.assign(n + 3, 1e18);
//        dp[2] = 0;
//        dp[4] = abs(a[4] - a[3]);
//        for (int i = 5; i <= n + 2; i++) {
//            dp[i] = min(dp[i], dp[i - 2] + abs(a[i] - a[i - 1]));
//            dp[i] = min(dp[i], dp[i - 3] + calc(a[i], a[i - 1], a[i - 2]));
//        }
//        cout << min(dp[n + 2], ans) << endl;
//    }
//    return 0;
//}

// 99. 
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
//        unordered_map<int, int> mp;
//        int ans = 0;
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        for (int i = 1; i <= n; i++) {
//            if (mp[k - a[i]]) {
//                ans++;
//                mp[k - a[i]]--;
//            } else mp[a[i]]++;
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 100. https://codeforces.com/problemset/problem/2155/B
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, k;
//        cin >> n >> k;
//        if (k == n * n - 1) cout << "NO" << endl;
//        else {
//            cout << "YES" << endl;
//            vector<vector<char>> ans(n + 1, vector<char>(n + 1, ' '));
//            int x = 1, y = 1;
//            for (int i = 1; i <= k; i++) {
//                ans[x][y] = 'U';
//                y++;
//                if (y == n + 1) {
//                    x++;
//                    y = 1;
//                }
//            }
//            if (x == n + 1) {
//                for (int i = 1; i <= n; i++) {
//                    for (int j = 1; j <= n; j++) {
//                        cout << ans[i][j];
//                    }
//                    cout << endl;
//                }
//                continue;
//            }
//            if (y == n) ans[x][y] = 'D';
//            else {
//                ans[x][y] = 'R';
//                for (y++; y <= n; y++) ans[x][y] = 'L';
//            }
//            x++, y = 1;
//            while (x != n + 1) {
//                if (y == 1) ans[x][y] = 'R';
//                else ans[x][y] = 'L';
//                y++;
//                if (y == n + 1) {
//                    x++;
//                    y = 1;
//                }
//            }
//            for (int i = 1; i <= n; i++) {
//                for (int j = 1; j <= n; j++) {
//                    cout << ans[i][j];
//                }
//                cout << endl;
//            }
//        }
//    }
//    return 0;
//}

// 101. https://ac.nowcoder.com/acm/contest/119225/E
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//const int mod = 1e9 + 7, N = 495;
//
//signed main() {
//    int n;
//    cin >> n;
//    vector<int> a(n + 1), b(n + 1);
//    for (int i = 1; i <= n; i++) cin >> a[i], a[i] %= N;
//    for (int i = 1; i <= n; i++) cin >> b[i], b[i] %= N;
//    vector<vector<int>> dpa(N, vector<int>(n + 1));
//    vector<vector<int>> dpb(N, vector<int>(n + 1));
//    dpa[0][0] = 1, dpb[0][0] = 1;
//    for (int i = 1; i <= n; i++) {
//        for (int j = n; j >= 1; j--) {
//            for (int k = 0; k < N; k++) {
//                dpa[(k + a[i]) % N][j] = (dpa[(k + a[i]) % N][j] + dpa[k][j - 1]) % mod;
//                dpb[(k + b[i]) % N][j] = (dpb[(k + b[i]) % N][j] + dpb[k][j - 1]) % mod;
//            }
//        }
//    }
//    for (int i = 0; i < N; i++) {
//        for (int j = 1; j <= n; j++) {
//            dpb[i][j] = (dpb[i][j] + dpb[i][j - 1]) % mod;
//        }
//    }
//    vector<int> ans(N);
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            for (int k = 0; k <= n; k++) {
//                ans[i] = (ans[i] + dpa[j][k] * dpb[(i - j + N) % N][k] % mod) % mod;
//            }
//        }
//    }
//    for (int i = 0; i < N; i++) cout << ans[i] << ' ';
//    return 0;
//}

// 2025.10.15   Educational Codeforces Round 148 (Rated for Div. 2)
// 102. A
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
//        bool is = false;
//        for (int i = 1; i < n / 2; i++) {
//            if (s[i] != s[i - 1]) {
//                is = true;
//                break;
//            }
//        }
//        if (is) cout << "YES" << endl;
//        else cout << "NO" << endl;
//    }
//    return 0;
//}

// 103. B
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
//        int ans = -1;
//        for (int i = 1; i <= n; i++) a[i] += a[i - 1];
//        int sum = a[n];
//        for (int i = 0; i <= k; i++) {
//            ans = max(ans, sum - a[i * 2] - a[n] + a[n - k + i]);
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 104. C
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
//        vector<int> ans;
//        for (int i = 1; i <= n; i++) {
//            if (ans.size() < 2) {
//                if (ans.empty()) ans.push_back(a[i]);
//                else {
//                    if (ans.back() == a[i]) continue;
//                    ans.push_back(a[i]);
//                }
//            } else {
//                if (a[i] == ans.back()) continue;
//                if (a[i] <= ans.back() && ans.back() <= ans[ans.size() - 2] || a[i] >= ans.back() && ans.back() >= ans[ans.size() - 2]) {
//                    ans.back() = a[i];
//                } else {
//                    ans.push_back(a[i]);
//                }
//            }
//        }
//        cout << ans.size() << endl;
//    }
//    return 0;
//}

// 105. https://www.luogu.com.cn/problem/CF1869B
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, k, a, b;
//        cin >> n >> k >> a >> b;
//        vector<pair<int, int>> pos(n + 1);
//        for (int i = 1; i <= n; i++) cin >> pos[i].first >> pos[i].second;
//        if (a <= k && b <= k) cout << 0 << endl;
//        else {
//            if ((a <= k && b > k) || (b <= k && a > k)) {
//                if (b <= k && a > k) swap(a, b);
//                int ans = 1e18;
//                for (int i = 1; i <= k; i++) {
//                    ans = min(ans, abs(pos[i].first - pos[b].first) + abs(pos[i].second - pos[b].second));
//                }
//                cout << ans << endl;
//            } else {
//                int ans = abs(pos[a].first - pos[b].first) + abs(pos[a].second - pos[b].second);
//                int ans1 = 1e18, ans2 = 1e18;
//                for (int i = 1; i <= k; i++) {
//                    ans1 = min(ans1, abs(pos[i].first - pos[b].first) + abs(pos[i].second - pos[b].second));
//                    ans2 = min(ans2, abs(pos[i].first - pos[a].first) + abs(pos[i].second - pos[a].second));
//                }
//                cout << min(ans, ans1 + ans2) << endl;
//            }
//        }
//    }
//    return 0;
//}

// 106. https://codeforces.com/problemset/problem/2045/B
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int n, d, s;
//    cin >> n >> d >> s;
//    n /= s, d /= s;
//    if (2 * d <= n) cout << max(2 * d * s, s) << endl;
//    else {
//        if (n % 2 == 0 || n - 1 == d) cout << n * s << endl;
//        else {
//            bool is = false;
//            for (int i = 2; i * i <= n; i++) {
//                if (n % i == 0) {
//                    if (i - 1 <= d && n - i <= d) {
//                        is = true;
//                        break;
//                    }
//                    int t = n / i;
//                    if (t - 1 <= d && n - t <= d) {
//                        is = true;
//                        break;
//                    }
//                }
//            }
//            if (is) cout << n * s << endl;
//            else cout << max((n - 1) * s, s) << endl;
//        }
//    }
//    return 0;
//}

// 107. https://atcoder.jp/contests/abc423/tasks/abc423_a
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int x, c;
//    cin >> x >> c;
//    int t = x / (1000 + c) * 1000;
//    cout << t << endl;
//    return 0;
//}

// 108. https://atcoder.jp/contests/abc423/tasks/abc423_e
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int n, q;
//    cin >> n >> q;
//    vector<int> a(n + 1);
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    vector<int> s1(n + 1), s2(n + 1), s3(n + 1), s_(n + 1);
//    for (int i = 1; i <= n; i++) {
//        s1[i] = s1[i - 1] + a[i];
//        s2[i] = s2[i - 1] + s1[i];
//        s3[i] = s3[i - 1] + s2[i];
//        s_[i] = i * s1[i];
//    }
//
//    for (int i = 1; i <= n; i++) s_[i] += s_[i - 1];
//
//    auto ans = [&](int l, int r) -> int {
//        return (r - l + 1) * s2[r] - (s3[r - 1] - s3[max(l - 2, 0LL)]) - r * (s2[r - 1] - s2[max(l - 2, 0LL)]) + s_[r - 1] - s_[max(l - 2, 0LL)];
//    };
//
//    while (q--) {
//        int l, r;
//        cin >> l >> r;
//        cout << ans(l, r) << endl;
//    }
//
//    return 0;
//}

// 109. https://codeforces.com/problemset/problem/1870/B
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, m;
//        cin >> n >> m;
//        vector<int> a(n + 1), b(m + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        for (int i = 1; i <= m; i++) cin >> b[i];
//        int ans1 = 0;
//        for (int i = 1; i <= n; i++) ans1 ^= a[i];
//        int t = 0;
//        for (int i = 1; i <= m; i++) t |= b[i];
//        int ans2 = 0;
//        for (int i = 1; i <= n; i++) ans2 ^= (a[i] | t);
//        cout << min(ans1, ans2) << ' ' << max(ans1, ans2) << endl;
//    }
//    return 0;
//}

// 110. https://www.luogu.com.cn/problem/CF2137F
//#include <bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 10;
//using ll = long long;
//
//struct node {
//    int l, r, x;
//} tr[N << 3];
//
//int a[N], b[N];
//
//void build(int u, int l, int r) {
//    tr[u] = {l, r, 0};
//    if (l == r) return;
//    else {
//        int mid = (l + r) >> 1;
//        build(u << 1, l, mid);
//        build(u << 1 | 1, mid + 1, r);
//    }
//}
//
//int query(int u, int l, int r) {
//    if (l <= tr[u].l && tr[u].r <= r) return tr[u].x;
//    else {
//        int mid = (tr[u].l + tr[u].r) >> 1;
//        if (r <= mid) return query(u << 1, l, r);
//        else if (l > mid) return query(u << 1 | 1, l, r);
//        else {
//            int res = max(query(u << 1, l, mid), query(u << 1 | 1, mid + 1, r));
//            return res;
//        }
//    }
//}
//
//void modify(int u, int l, int x) {
//    if (tr[u].l == tr[u].r) tr[u].x = x;
//    else {
//        int mid = (tr[u].l + tr[u].r) >> 1;
//        if (l <= mid) modify(u << 1, l, x);
//        else modify(u << 1 | 1, l, x);
//        tr[u].x = max(tr[u << 1].x, tr[u << 1 | 1].x);
//    }
//}
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        build(1, 1, 2 * n);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        for (int i = 1; i <= n; i++) cin >> b[i];
//        vector<ll> dp(n + 1);
//        dp[1] = a[1] == b[1];
//        modify(1, a[1], 1);
//        for (int i = 2; i <= n; i++) {
//            dp[i] = dp[i - 1];
//            if (a[i] == b[i]) dp[i] += i;
//            else {
//                int t = max(a[i], b[i]);
//                dp[i] += query(1, t, 2 * n);
//            }
//            modify(1, a[i], i);
//        }
//        ll ans = 0;
//        for (int i = 1; i <= n; i++) ans += dp[i];
//        cout << ans << endl;
//    }
//    return 0;
//}

// 111. https://www.luogu.com.cn/problem/CF2155C
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
//        auto work = [&](int x) -> int {
//            vector<int> f(n + 1);
//            f[1] = x;
//            for (int i = 2; i <= n; i++) {
//                if (abs(a[i] - a[i - 1]) >= 2) return 0;
//                if (a[i] == a[i - 1]) f[i] = f[i - 1] ^ 1;
//                else f[i] = f[i - 1];
//            }
//            for (int i = 1; i <= n; i++) f[i] += f[i - 1];
//            for (int i = 1; i <= n; i++) {
//                if (1 + f[i - 1] + n - i - (f[n] - f[i]) != a[i]) return 0;
//            }
//            return 1;
//        };
//        cout << work(0) + work(1) << endl;
//    }
//    return 0;
//}

// 112. https://codeforces.com/problemset/problem/1790/C
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<vector<int>> a(n + 1, vector<int>(n));
//        for (int i = 1; i <= n; i++) {
//            for (int j = 1; j < n; j++) {
//                cin >> a[i][j];
//            }
//        }
//        unordered_map<int, int> mp;
//        int id = 0;
//        for (int i = 1; i <= n; i++) mp[a[i][1]]++;
//        int t = 0, t2 = 0;
//        for (auto & [i, j] : mp) {
//            if (j == 1) {
//                t = i;
//            } else {
//                t2 = i;
//            }
//        }
//        for (; id <= n; id++) {
//            if (a[id][1] == t) {
//                break;
//            }
//        }
//        cout << t2 << ' ';
//        for (int i = 1; i < n; i++) cout << a[id][i] << ' ';
//        cout << endl;
//    }
//    return 0;
//}

// 113. https://www.luogu.com.cn/problem/CF1900D
//#include <bits/stdc++.h>
//using namespace std;
//const int N = 1e5;
//using ll = long long;
//
//signed main() {
//    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
//    int T;
//    cin >> T;
//    vector<vector<int>> fac(N);
//    for (int i = 1; i <= N; i++)
//        for (int j = i; j <= N; j += i)
//            fac[j].emplace_back(i);
//    for (int i = 1; i <= N; i++) reverse(fac[i].begin(), fac[i].end());
//
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        sort(a.begin() + 1, a.end());
//        ll ans = 0, he = 0;
//        vector<int> f(N + 1), g(N + 1);
//        for (int i = 1; i <= n; i++) {
//            ans += he;
//            for (int fa : fac[a[i]]) {
//                f[fa] = g[fa];
//                for (int t : fac[a[i] / fa])
//                    f[fa] -= (t != 1) * f[t * fa];
//                he += 1LL * f[fa] * fa;
//            }
//            for (int fa : fac[a[i]]) g[fa]++;
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 114. https://www.luogu.com.cn/problem/AT_abc423_f
//#include <bits/stdc++.h>
//using namespace std;
//#define int __int128
//
//const int N = 30;
//int C[N][N];
//
//void init() {
//    for (int i = 0; i < N; i++) C[i][0] = 1;
//    for (int i = 1; i < N; i++)
//        for (int j = 1; j <= i; j++)
//            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]);
//}
//
//std::ostream& operator<<(std::ostream& os, __int128 n) {
//    if (n == 0) return os << 0;
//    std::string s;
//    while (n > 0) {
//        s += char('0' + n % 10);
//        n /= 10;
//    }
//    std::reverse(s.begin(), s.end());
//    return os << s;
//}
//
//std::istream& operator>>(std::istream& is, __int128& x) {
//    char c;
//    while(c = is.get(), c != '-' && !isdigit(c));
//    if(c == '-') {
//        x = '0' - is.get();
//        while(isdigit(c = is.get())) x = x * 10 + '0' - c;
//    } else {
//        x = c - '0';
//        while(isdigit(c = is.get())) x = x * 10 - '0' + c;
//    }
//    return is;
//}
//
//signed main() {
//    init();
//    signed n, m;
//    long long y;
//    cin >> n >> m >> y;
//    vector<long long> a(n);
//    for (signed i = 0; i < n; i++) cin >> a[i];
//    auto lcm_ = [&](int x) -> int {
//        int res = 1;
//        for (int i = 0; i < n; i++) {
//            if (x >> i & 1) {
//                res = lcm(res, a[i]);
//                if (res > y) return y + 1;
//            }
//        }
//        return res;
//    };
//    auto count = [&](signed x) -> signed {
//        signed res = 0;
//        while (x) {
//            res++;
//            x -= x & -x;
//        }
//        return res;
//    };
//    int ans = 0;
//    for (signed i = 0; i < 1 << n; i++) {
//        signed cnt = count(i);
//        if (cnt < m) continue;
//        int t = y / lcm_(i);
//        if ((cnt - m) % 2 == 0) ans += C[cnt][m] * t;
//        else ans -= C[cnt][m] * t;
//    }
//    cout << ans << endl;
//    return 0;
//}

// 115. https://codeforces.com/problemset/problem/2020/B
//#include <bits/stdc++.h>
//using namespace std;
//using ll = long long;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        ll k;
//        cin >> k;
//        int jian = (int)sqrtl(k);
//        ll ans = k + jian;
//        int jian2 = (int)sqrtl(ans);
//        if (jian2 - jian) ans += jian2 - jian;
//        cout << ans << endl;
//    }
//    return 0;
//}

// 116. https://codeforces.com/problemset/problem/1882/B
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        set<int> s;
//        vector<unordered_map<int, int>> mp(n + 1);
//        int ans = 0;
//        for (int i = 1; i <= n; i++) {
//            int k;
//            cin >> k;
//            for (int j = 1, x; j <= k; j++) {
//                cin >> x;
//                s.insert(x);
//                mp[i][x] = 1;
//            }
//        }
//        for (int i : s) {
//            set<int> x;
//            for (int j = 1; j <= n; j++) {
//                if (!mp[j][i]) {
//                    for (auto& [y, z] : mp[j]) {
//                        if (z) x.insert(y);
//                    }
//                }
//            }
//            ans = max(ans, (int)x.size());
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 117. https://codeforces.com/contest/2162/problem/F
//#include <bits/stdc++.h>
//using namespace std;
//
//void solve() {
//    int n, m;
//    cin >> n >> m;
//    vector<int> a(n + 2), st(n + 1), en(n + 1);
//    vector<int> ans(n + 1, -1);
//    for (int i = 1; i <= m; i++) {
//        int l, r;
//        cin >> l >> r;
//        a[l]++, a[r + 1]--;
//        st[l] = 1, en[r] = 1;
//    }
//    auto fill = [&]() {
//        vector<int> vis(n + 1);
//        for (int i = 1; i <= n; i++) if (ans[i] != -1) vis[ans[i]] = 1;
//        int x = 0;
//        for (int i = 1; i <= n; i++) {
//            if (ans[i] != -1) continue;
//            while (vis[x]) x++;
//            vis[x] = 1;
//            ans[i] = x;
//        }
//    };
//    for (int i = 1; i <= n; i++) a[i] += a[i - 1];
//    for (int i = 1; i <= n; i++) {
//        if (a[i] == m) {
//            ans[i] = 0;
//            fill();
//            for (int j = 1; j <= n; j++) cout << ans[j] << " \n"[j == n];
//            return;
//        }
//    }
//    for (int i = 1; i < n; i++) {
//        if (en[i] == 0) {
//            ans[i] = 0, ans[i + 1] = 1;
//            fill();
//            for (int j = 1; j <= n; j++) cout << ans[j] << " \n"[j == n];
//            return;
//        }
//        if (st[i + 1] == 0) {
//            ans[i + 1] = 0, ans[i] = 1;
//            fill();
//            for (int j = 1; j <= n; j++) cout << ans[j] << " \n"[j == n];
//            return;
//        }
//    }
//    ans[1] = 0, ans[2] = 2, ans[3] = 1;
//    fill();
//    for (int j = 1; j <= n; j++) cout << ans[j] << " \n"[j == n];
//}
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        solve();
//    }
//    return 0;
//}

// 118. https://codeforces.com/contest/2162/problem/G
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        if (n == 2) cout << -1 << endl;
//        else if (n == 3) cout << "1 3\n2 3" << endl;
//        else if (n == 4) cout << "1 2\n3 1\n4 1" << endl;
//        else {
//            cout << "3 4\n2 3\n1 2" << endl;
//            cout << "1 " << n << endl;
//            for (int i = 5; i < n; i++) cout << "2 " << i << endl;
//        }
//    }
//    return 0;
//}

// 119. https://codeforces.com/problemset/problem/2152/D
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, q;
//        cin >> n >> q;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        vector<int> cnt(n + 1), mi(n + 1);
//        for (int i = 1; i <= n; i++) {
//            int x = a[i];
//            if ((x - 2) > 0 && ((x - 1) & (x - 2)) == 0) mi[i]++;
//            else if (x & (x - 1)) cnt[i]++;
//            while (x != 1) {
//                x /= 2;
//                cnt[i]++;
//            }
//            cnt[i] += cnt[i - 1];
//            mi[i] += mi[i - 1];
//        }
//        while (q--) {
//            int l, r;
//            cin >> l >> r;
//            cout << cnt[r] - cnt[l - 1] + (mi[r] - mi[l - 1]) / 2 << endl;
//        }
//    }
//    return 0;
//}

// 120. https://www.luogu.com.cn/problem/CF2152C
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, q;
//        cin >> n >> q;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        vector<int> dp(n + 1), zero(n + 1), one(n + 1);
//        for (int i = 1; i <= n; i++) {
//            zero[i] = zero[i - 1] + (a[i] == 0);
//            one[i] = one[i - 1] + (a[i] == 1);
//            if (a[i] != a[i - 1]) dp[i] = dp[i - 1];
//            else dp[i] = i;
//        }
//        while (q--) {
//            int l, r;
//            cin >> l >> r;
//            int n0 = zero[r] - zero[l - 1];
//            int n1 = one[r] - one[l - 1];
//            if (n0 % 3 == 0 && n1 % 3 == 0) {
//                if (l >= dp[r]) cout << 1 + n0 / 3 + n1 / 3 << endl;
//                else cout << n0 / 3 + n1 / 3 << endl;
//            } else cout << -1 << endl;
//        }
//    }
//    return 0;
//}

// 121. https://qoj.ac/contest/1802/problem/9422
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//void solve() {
//    int n, m, k;
//    cin >> n >> m >> k;
//    vector<vector<int>> a(n + 1, vector<int>(m + 1));
//    vector<vector<int>> cnt(n + 1);
//    vector<int> sum(n + 1);
//    for (int i = 1; i <= n; i++) {
//        cin >> a[i][0];
//        for (int j = 1; j <= m; j++) {
//            cin >> a[i][j];
//            if (a[i][j] == -1) cnt[i].emplace_back(j);
//            else sum[i] += a[i][j];
//        }
//    }
//    vector<int> id(n + 1);
//    iota(id.begin() + 1, id.end(), 1);
//    sort(id.begin() + 1, id.end(), [&](auto x, auto y) {
//        if (a[x][0] != a[y][0]) return a[x][0] < a[y][0];
//        return x < y;
//    });
//    int mi = -1;
//    for (int x = 2; x <= n; x++) {
//        int i = id[x];
//        if (a[id[x - 1]][0] != a[i][0]) mi = sum[id[x - 1]];
//        if (mi >= sum[i]) {
//            int cha = mi - sum[i];
//            int mx = (int)cnt[i].size() * k;
//            if (mx <= cha) {
//                cout << "No" << endl;
//                return;
//            } else {
//                for (int j : cnt[i]) {
//                    if (k <= cha) {
//                        a[i][j] = k;
//                        sum[i] += k;
//                        cha -= k;
//                    } else {
//                        a[i][j] = cha + 1;
//                        sum[i] += cha + 1;
//                        break;
//                    }
//                }
//            }
//        }
//        if (a[id[x - 1]][0] == a[i][0]) sum[i] = max(sum[i], sum[id[x - 1]]);
//    }
//    cout << "Yes" << endl;
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//            cout << max(a[i][j], 0LL) << ' ';
//        }
//        cout << endl;
//    }
//}
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        solve();
//    }
//    return 0;
//}

// 122. https://qoj.ac/contest/1802/problem/9426
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//void solve() {
//    int n, k;
//    cin >> n >> k;
//    vector<int> a(n + 1), en(n + 2), st(n + 1);
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    for (int i = n; i >= 1; i--) a[i] -= a[i - 1];
//    for (int i = n; i >= 1; i--) en[i] = gcd(en[i + 1], a[i]);
//    for (int i = 1; i <= n; i++) st[i] = gcd(st[i - 1], a[i]);
//    set<int> s;
//    s.insert(a[1] + k);
//    int ans = st[n];
//    for (int i = 2; i <= n; i++) {
//        set<int> s_;
//        for (int j : s) {
//            ans = max(ans, gcd(gcd(j, a[i] - k), en[i + 1]));
//        }
//        for (int j : s) {
//            s_.insert(gcd(j, a[i]));
//        }
//        s_.insert(gcd(st[i - 1], a[i] + k));
//        swap(s_, s);
//    }
//    for (int j : s) ans = max(ans, j);
//    cout << ans << endl;
//}
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        solve();
//    }
//    return 0;
//}

// 123. https://qoj.ac/contest/1802/problem/9423
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, k, m;
//        cin >> n >> k;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        cin >> m;
//        vector<int> b(n + 1);
//        for (int i = 1; i <= n; i++) b[i] = k - a[i] % k;
//        vector<int> id(n + 1);
//        iota(id.begin(), id.end(), 0);
//        sort(id.begin() + 1, id.end(), [&](int x, int y) {
//           return b[x] < b[y];
//        });
//        for (int x = 1; x <= n; x++) {
//            int i = id[x];
//            if (b[i] <= m) {
//                a[i] += b[i];
//                m -= b[i];
//            } else break;
//        }
//        a[1] += m;
//        int ans = 0;
//        for (int i = 1; i <= n; i++) ans += a[i] / k;
//        cout << ans << endl;
//    }
//    return 0;
//}

// 124. https://qoj.ac/contest/1802/problem/9430
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
//        vector<int> a;
//        a.push_back(1);
//        for (int i = 1; i < s.size(); i++) {
//            if (s[i] != s[i - 1]) a.push_back(1);
//            else a.back()++;
//        }
//        if (a.size() == 1) {
//            cout << a[0] / 2 << endl;
//            continue;
//        }
//        int ans = 0;
//        bool flag = false;
//        for (int x = 0; x < a.size(); x++) {
//            int i = a[x];
//            ans += i / 2;
//            if (x >= 1 && x < a.size() - 1) {
//                flag = (i % 2 == 0) || flag;
//            }
//        }
//        int t = 0;
//        if (s[0] != s.back()) {
//            flag = (a[0] % 2 == 0 || flag || a.back() % 2 == 0);
//            if (flag) t = 1;
//        } else if (flag && (a[0] + a.back()) % 2 != 0) t = 1;
//        else if (!(a[0] % 2 + a.back() % 2)) t = 1;
//        cout << max(0LL, ans - t) << endl;
//    }
//    return 0;
//}

// 125. https://qoj.ac/contest/1802/problem/9428
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        int x = 0;
//        for (int i = 1; i < n; i++) x ^= i;
//        if (x == 0) cout << "impossible" << endl;
//        else {
//            set<int> s;
//            for (int i = 0; i < n; i++) s.insert(i);
//            vector<int> ans(n + 1);
//            x = 0;
//            for (int i = 1; i <= n; i++) {
//                for (int j : s) {
//                    if (x ^ j) {
//                        ans[i] = j;
//                        x ^= j;
//                        s.erase(j);
//                        break;
//                    }
//                }
//            }
//            for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
//            cout << endl;
//        }
//    }
//    return 0;
//}

// 126. https://codeforces.com/contest/2156/problem/C
//#include <bits/stdc++.h>
//using namespace std;
//
//void solve() {
//    int n, k;
//    cin >> n >> k;
//    vector<int> a(n + 1);
//    int mx = 0;
//    for (int i = 1; i <= n; i++) cin >> a[i], mx = max(mx, a[i]);
//    sort(a.begin() + 1, a.end());
//    vector<int> mp(mx + 1);
//    for (int i = 1; i <= n; i++) mp[a[i]]++;
//    for (int i = mx; i >= 1; i--) {
//        int cnt = lower_bound(a.begin() + 1, a.end(), 4 * i) - a.begin() - 1;
//        for (int j = 1; j <= 3; j++) {
//            if (j * i <= mx) cnt -= mp[j * i];
//        }
//        if (cnt <= k) {
//            cout << i << endl;
//            return;
//        }
//    }
//}
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        solve();
//    }
//    return 0;
//}

// 127. https://www.luogu.com.cn/problem/CF545C
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int n;
//    cin >> n;
//    vector<int> x(n + 2), h(n + 1);
//    for (int i = 1; i <= n; i++) cin >> x[i] >> h[i];
//    int ans = 1;
//    x[n + 1] = 2e10;
//    for (int i = 2; i <= n; i++) {
//        if (x[i] - h[i] > x[i - 1]) {
//            ans++;
//        } else if (x[i] + h[i] < x[i + 1]) {
//            ans++;
//            x[i] += h[i];
//        }
//    }
//    cout << ans << endl;
//    return 0;
//}

// 128. https://codeforces.com/problemset/problem/2118/B
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        cout << 2 * n - 1 << endl;
//        for (int i = 1; i <= n; i++) {
//            cout << i << ' ' << 1 << ' ' << i << endl;
//            if (i != n) cout << i << ' ' << i + 1 << ' ' << n << endl;
//        }
//    }
//    return 0;
//}

// 129. https://www.luogu.com.cn/problem/P9749
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int n, d;
//    cin >> n >> d;
//    vector<int> a(n + 1), v(n + 1);
//    for (int i = 2; i <= n; i++) cin >> v[i], v[i] += v[i - 1];
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    vector<int> dp(n + 1), shen(n + 1);
//    int id = 1;
//    for (int i = 2; i <= n; i++) {
//        int dis = v[i] - v[id];
//        int t = (dis - shen[id] + d - 1) / d;
//        dp[i] = dp[id] + t * a[id];
//        shen[i] = t * d + shen[id] - dis;
//        if (a[i] < a[id]) id = i;
//    }
//    cout << dp[n] << endl;
//    return 0;
//}

// 130. https://www.luogu.com.cn/problem/P7072
//#include <bits/stdc++.h>
//using namespace std;
//const int N = 602;
//
//int tr[N];
//
//void add(int p, int x) {
//    for (int i = p; i < N; i += i & -i)
//        tr[i] += x;
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
//    int n, w;
//    cin >> n >> w;
//    for (int i = 1; i <= n; i++) {
//        int x;
//        cin >> x;
//        x++;
//        add(x, 1);
//        int l = 1, r = 601, num = max(1, i * w / 100);
//        while (l <= r) {
//            int mid = (l + r) >> 1;
//            int t = sum(601) - sum(mid - 1);
//            if (t >= num) l = mid + 1;
//            else r = mid - 1;
//        }
//        cout << l - 2 << ' ';
//    }
//    return 0;
//}

// 131. https://www.luogu.com.cn/problem/P14258
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        string s;
//        cin >> n >> s;
//        s = " " + s;
//        auto fan = [&]() {
//            for (int i = 1; i <= n; i++) s[i] = '0' + ((s[i] - '0') ^ 1);
//        };
//        auto calc = [&]() {
//            string s_ = s;
//            int l = 1, r = n;
//            int res = 0;
//            while (l <= r) {
//                if (s_[l] == '1') res++, s_[l] = '0';
//                while (l <= r && s_[r] == '0') r--;
//                if (l <= r) {
//                    res += r - l + 1;
//                    r--;
//                    l++;
//                }
//            }
//            return res;
//        };
//        int ans = calc();
//        fan();
//        ans = min(ans, calc());
//        cout << ans << endl;
//    }
//    return 0;
//}

// 132. https://codeforces.com/contest/2156/problem/D
//#include <bits/stdc++.h>
//using namespace std;
//
//int query(int i, int x) {
//    cout << "? " << i << ' ' << x << endl;
//    int y;
//    cin >> y;
//    return y;
//}
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        set<int> s, pos;
//        for (int i = 1; i <= n; i++) s.insert(i);
//        for (int i = 1; i < n; i++) pos.insert(i);
//        for (int i = 0; s.size() != 1; i++) {
//            vector<int> zero, one, s_zero, s_one;
//            for (int j : pos) {
//                int t = query(j, 1 << i);
//                if (t == 0) zero.push_back(j);
//                else one.push_back(j);
//            }
//            for (int j : s) {
//                if ((j & (1 << i)) >> i) s_one.push_back(j);
//                else s_zero.push_back(j);
//            }
//            if (s_one.size() == one.size()) {
//                for (int j : s_one) s.erase(j);
//                for (int j : one) pos.erase(j);
//            } else {
//                for (int j : s_zero) s.erase(j);
//                for (int j : zero) pos.erase(j);
//            }
//        }
//        cout << "! " << *s.begin() << endl;
//    }
//    return 0;
//}

// 133. https://www.luogu.com.cn/problem/CF2147D
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
//        int sum = 0;
//        map<int, int> mp;
//        for (int i = 1, x; i <= n; i++) {
//            cin >> x;
//            sum += x;
//            if (x & 1) mp[x]++;
//        }
//        vector<int> b;
//        for (auto & [x, y] : mp) b.push_back(y);
//        sort(b.begin(), b.end(), greater<>());
//        int t = 0, si = 1;
//        for (int i : b) t += si * i, si = -si;
//        cout << (sum + t) / 2 << ' ' << (sum - t) / 2 << endl;
//    }
//    return 0;
//}

// 134. https://www.luogu.com.cn/problem/CF2143D1
//#include <bits/stdc++.h>
//using namespace std;
//const int mod = 1e9 + 7;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1)));
//        dp[0][0][0] = 1;
//        for (int i = 1; i <= n; i++) {
//            for (int j = 0; j <= n; j++) {
//                for (int k = 0; k <= n; k++) {
//                    if (!dp[i - 1][j][k]) continue;
//                    dp[i][j][k] = (dp[i - 1][j][k] + dp[i][j][k]) % mod;
//                    if (a[i] >= j) dp[i][a[i]][k] = (dp[i][a[i]][k] + dp[i - 1][j][k]) % mod;
//                    else if (a[i] >= k) dp[i][j][a[i]] = (dp[i][j][a[i]] + dp[i - 1][j][k]) % mod;
//                }
//            }
//        }
//        int ans = 0;
//        for (int i = 0; i <= n; i++)
//            for (int j = 0; j <= n; j++)
//                ans = (ans + dp[n][i][j]) % mod;
//        cout << ans << endl;
//    }
//    return 0;
//}

// 135. https://www.luogu.com.cn/problem/CF2143D2
//#include <bits/stdc++.h>
//using namespace std;
//const int mod = 1e9 + 7;
//
//template<typename T> T pred(T a, T b) { return (a + b) % mod; }
//template<typename T, T (*Pred)(T, T) = pred<T>, T Init = 0>
//struct BIT {
//public:
//    size_t n;
//    vector<T> data;
//
//    BIT(size_t n) : BIT(vector<T>(n + 1, Init)) {}
//
//    BIT(const vector<T> &v) : n(v.size() - 1), data(v) {
//        for (size_t i = 1; i <= n; i++) {
//            size_t j = i + (i & -i);
//            if (j <= n) data[j] = Pred(data[j], data[i]);
//        }
//    }
//
//    void modify(size_t i, T v = 1) {
//        i++;
//        for (; i <= n; i += i & -i) {
//            data[i] = Pred(data[i], v);
//        }
//    }
//
//    T query(size_t i) {
//        i++;
//        T res = Init;
//        for (; i; i -= i & -i) {
//            res = Pred(res, data[i]);
//        }
//        return res;
//    }
//
//    T query(size_t l, size_t r) {
//        return query(r) - query(l - 1);
//    }
//};
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        vector<vector<BIT<int>>> t(2, vector<BIT<int>>(n + 1, BIT<int>(n + 1)));
//        t[0][0].modify(0, 1);
//        t[1][0].modify(0, 1);
//        for (int i = 1; i <= n; i++) {
//            vector<pair<int, pair<int, int>>> v;
//            for (int k = 0; k < a[i]; k++) v.push_back({t[0][k].query(a[i]), {a[i], k}});
//            for (int j = a[i] + 1; j <= n; j++) v.push_back({t[1][j].query(a[i]), {j, a[i]}});
//            for (auto [u, pos]: v) {
//                auto [l, c] = pos;
//                t[0][c].modify(l, u);
//                t[1][l].modify(c, u);
//            }
//        }
//        int ans = 0;
//        for (int i = 0; i <= n; i++) ans = (ans + t[0][i].query(n)) % mod;
//        cout << ans << endl;
//    }
//    return 0;
//}

// 136. https://www.luogu.com.cn/problem/CF2061D
//#include <bits/stdc++.h>
//using namespace std;
//
//void solve() {
//    int n, m;
//    cin >> n >> m;
//    vector<int> a(n + 1), b(m + 1);
//    long long sum = 0;
//    for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
//    for (int i = 1; i <= m; i++) cin >> b[i], sum -= b[i];
//    if (sum) {
//        cout << "No" << endl;
//        return;
//    }
//    multiset<int> sa, sb;
//    for (int i = 1; i <= n; i++) sa.insert(a[i]);
//    for (int i = 1; i <= m; i++) sb.insert(b[i]);
//    while (!sa.empty() && !sb.empty()) {
//        int mxa = *sa.rbegin(), mxb = *sb.rbegin();
//        if (mxa == mxb) {
//            sa.erase(sa.find(mxa));
//            sb.erase(sb.find(mxb));
//        } else if (mxa > mxb) {
//            cout << "No" << endl;
//            return;
//        } else {
//            sb.erase(sb.find(mxb));
//            sb.insert(mxb >> 1), sb.insert((mxb + 1) >> 1);
//        }
//    }
//    if (sa.empty() && sb.empty()) cout << "Yes" << endl;
//    else cout << "No" << endl;
//}
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        solve();
//    }
//    return 0;
//}

// 137. https://codeforces.com/problemset/problem/2057/D
//#include <bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 10;
//
//struct node {
//    int l, r;
//    int mi1, mx1, mi2, mx2;
//    int ans;
//} tr[N << 2];
//int a[N];
//
//void pushup(int u) {
//    tr[u].mi1 = min(tr[u << 1].mi1, tr[u << 1 | 1].mi1);
//    tr[u].mi2 = min(tr[u << 1].mi2, tr[u << 1 | 1].mi2);
//    tr[u].mx1 = max(tr[u << 1].mx1, tr[u << 1 | 1].mx1);
//    tr[u].mx2 = max(tr[u << 1].mx2, tr[u << 1 | 1].mx2);
//    tr[u].ans = max({
//        tr[u << 1].mx2 - tr[u << 1 | 1].mi2,
//        tr[u << 1 | 1].mx1 - tr[u << 1].mi1,
//        tr[u << 1].ans, tr[u << 1 | 1].ans
//    });
//}
//
//void build(int u, int l, int r) {
//    if (l == r) {
//        tr[u] = {l, r, a[l] - l, a[r] - r, a[l] + l, a[r] + r, 0};
//        return;
//    }
//    tr[u] = {l, r};
//    int mid = (l + r) >> 1;
//    build(u << 1, l, mid);
//    build(u << 1 | 1, mid + 1, r);
//    pushup(u);
//}
//
//void modify(int u, int p, int x) {
//    if (tr[u].l == tr[u].r) {
//        tr[u].mi1 = x - p;
//        tr[u].mx1 = x - p;
//        tr[u].mx2 = x + p;
//        tr[u].mi2 = x + p;
//        return;
//    }
//    int mid = (tr[u].l + tr[u].r) >> 1;
//    if (p <= mid) modify(u << 1, p, x);
//    else modify(u << 1 | 1, p, x);
//    pushup(u);
//}
//
//signed main() {
//    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, q;
//        cin >> n >> q;
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        build(1, 1, n);
//        cout << tr[1].ans << endl;
//        while (q--) {
//            int p, x;
//            cin >> p >> x;
//            modify(1, p, x);
//            cout << tr[1].ans << endl;
//        }
//    }
//    return 0;
//}

// 138. https://codeforces.com/contest/2154/problem/C1
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//void solve() {
//    int n;
//    cin >> n;
//    vector<int> a(n + 1), b(n + 1);
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    for (int i = 1; i <= n; i++) cin >> b[i];
//    unordered_map<int, int> vis;
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j * j <= a[i]; j++) {
//            if (a[i] % j == 0) {
//                if (j != 1) {
//                    vis[j]++;
//                    if (vis[j] >= 2) {
//                        cout << 0 << endl;
//                        return;
//                    }
//                }
//                if (a[i] / j != j) {
//                    vis[a[i] / j]++;
//                    if (vis[a[i] / j] >= 2) {
//                        cout << 0 << endl;
//                        return;
//                    }
//                }
//            }
//        }
//    }
//    unordered_map<int, int> mp;
//    for (int i = 1; i <= n; i++) mp[a[i]]++;
//    for (int i = 1; i <= n; i++) {
//        mp[a[i]++]--;
//        for (int j = 1; j * j <= a[i]; j++) {
//            if (a[i] % j == 0) {
//                if ((j != 1 && vis[j]) || (a[i] / j != 1 && vis[a[i] / j])) {
//                    cout << 1 << endl;
//                    return;
//                }
//            }
//        }
//        mp[--a[i]]++;
//    }
//    cout << 2 << endl;
//}
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        solve();
//    }
//    return 0;
//}

// 139. https://codeforces.com/contest/2154/problem/C2
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//const int N = 2e5 + 10;
//
//vector<vector<int>> fact(N);
//
//void solve() {
//    int n;
//    cin >> n;
//    vector<int> a(n + 1), b(n + 1);
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    for (int i = 1; i <= n; i++) cin >> b[i];
//    map<int, int> vis;
//    for (int i = 1; i <= n; i++) {
//        for (int j : fact[a[i]]) {
//            vis[j]++;
//            if (vis[j] >= 2) {
//                cout << 0 << endl;
//                return;
//            }
//        }
//    }
//    vector<int> id(n + 1);
//    iota(id.begin(), id.end(), 0);
//    sort(id.begin() + 1, id.end(), [&](int x, int y) {
//        return b[x] < b[y];
//    });
//    int ans = b[id[1]] + b[id[2]];
//    for (int i = 1; i <= n; i++) {
//        for (int j : fact[a[i]]) vis[j]--;
//        for (int j : fact[a[i] + 1]) {
//            if (vis[j] >= 1) {
//                ans = min(ans, b[i]);
//                break;
//            }
//        }
//        for (int j : fact[a[i]]) vis[j]++;
//    }
//    vector<int> check;
//    for (int i = 1; i <= n; i++) {
//        if (i == id[1]) continue;
//        for (int j : fact[a[i]]) check.push_back(j);
//    }
//    for (int i : check) {
//        int t = i - (a[id[1]] % i);
//        ans = min(ans, t * b[id[1]]);
//    }
//    cout << ans << endl;
//}
//
//signed main() {
//    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
//    int T;
//    cin >> T;
//    for (int i = 2; i < N; i++) {
//        for (int j = i; j < N; j += i) {
//            fact[j].emplace_back(i);
//        }
//    }
//    while (T--) {
//        solve();
//    }
//    return 0;
//}

// 140. https://www.luogu.com.cn/problem/P3842
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int n;
//    cin >> n;
//    vector<pair<int, int>> a(n + 1);
//    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
//    vector<vector<int>> dp(n + 1,vector<int>(2, 1e9));
//    dp[1][0] = a[1].second - 1 + a[1].second - a[1].first;
//    dp[1][1] = a[1].second - 1;
//    for (int i = 2; i <= n; i++) {
//        if (a[i - 1].first < a[i].first) {
//            dp[i][0] = min(dp[i][0], dp[i - 1][0] + a[i].second - a[i - 1].first + a[i].second - a[i].first);
//            dp[i][1] = min(dp[i][1], dp[i - 1][0] + a[i].second - a[i - 1].first);
//        } else if (a[i - 1].first > a[i].second) {
//            dp[i][0] = min(dp[i][0], dp[i - 1][0] + a[i - 1].first - a[i].first);
//            dp[i][1] = min(dp[i][1], dp[i - 1][0] + a[i - 1].first - a[i].first + a[i].second - a[i].first);
//        } else {
//            dp[i][0] = min(dp[i][0], dp[i - 1][0] + a[i].second - a[i - 1].first + a[i].second - a[i].first);
//            dp[i][1] = min(dp[i][1], dp[i - 1][0] + a[i - 1].first - a[i].first + a[i].second - a[i].first);
//        }
//
//        if (a[i - 1].second < a[i].first) {
//            dp[i][0] = min(dp[i][0], dp[i - 1][1] + a[i].second - a[i - 1].second + a[i].second - a[i].first);
//            dp[i][1] = min(dp[i][1], dp[i - 1][1] + a[i].second - a[i - 1].second);
//        } else if (a[i - 1].second > a[i].second) {
//            dp[i][0] = min(dp[i][0], dp[i - 1][1] + a[i - 1].second - a[i].first);
//            dp[i][1] = min(dp[i][1], dp[i - 1][1] + a[i - 1].second - a[i].first + a[i].second - a[i].first);
//        } else {
//            dp[i][0] = min(dp[i][0], dp[i - 1][1] + a[i].second - a[i - 1].second + a[i].second - a[i].first);
//            dp[i][1] = min(dp[i][1], dp[i - 1][1] + a[i - 1].second - a[i].first + a[i].second - a[i].first);
//        }
//    }
//    cout << min(dp[n][0] + n - a[n].first, dp[n][1] + n - a[n].second) + n - 1 << endl;
//    return 0;
//}

// 141. https://codeforces.com/problemset/problem/2149/G
//#include <bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 10;
//
//struct node {
//    int l, r;
//    int val1, cnt1, val2, cnt2;
//} tr[N << 2];
//int a[N];
//
//void pushup(node& p, node ls, node rs) {
//    if(rs.cnt1 && rs.val1 == ls.val1) ls.cnt1 += rs.cnt1;
//    else if(rs.cnt1 && rs.val1 == ls.val2) ls.cnt2 += rs.cnt1;
//    else if(rs.cnt1)
//    {
//        int mn = min(rs.cnt1, min(ls.cnt1, ls.cnt2));
//        rs.cnt1 -= mn;
//        ls.cnt1 -= mn;
//        ls.cnt2 -= mn;
//        if(rs.cnt1 && ls.cnt1 == 0) ls.val1 = rs.val1, ls.cnt1 = rs.cnt1;
//        else if(rs.cnt1 && ls.cnt2 == 0) ls.val2 = rs.val1, ls.cnt2 = rs.cnt1;
//    }
//
//    if(rs.cnt2 && rs.val2 == ls.val1) ls.cnt1 += rs.cnt2;
//    else if(rs.cnt2 && rs.val2 == ls.val2) ls.cnt2 += rs.cnt2;
//    else if(rs.cnt2)
//    {
//        int mn = min(rs.cnt2, min(ls.cnt1, ls.cnt2));
//        rs.cnt2 -= mn;
//        ls.cnt1 -= mn;
//        ls.cnt2 -= mn;
//        if(rs.cnt2 && ls.cnt1 == 0) ls.val1 = rs.val2, ls.cnt1 = rs.cnt2;
//        else if(rs.cnt2 && ls.cnt2 == 0) ls.val2 = rs.val2, ls.cnt2 = rs.cnt2;
//    }
//
//    p.val1 = ls.val1;
//    p.val2 = ls.val2;
//    p.cnt1 = ls.cnt1;
//    p.cnt2 = ls.cnt2;
//}
//
//void build(int u, int l, int r) {
//    if (l == r) {
//        tr[u] = {l, r, a[l], 1, 0, 0};
//        return;
//    }
//    tr[u] = {l, r};
//    int mid = (l + r) >> 1;
//    build(u << 1, l, mid);
//    build(u << 1 | 1, mid + 1, r);
//    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
//}
//
//node query(int u, int l, int r) {
//    if (l <= tr[u].l && tr[u].r <= r) return tr[u];
//    int mid = (tr[u].l + tr[u].r) >> 1;
//    if (r <= mid) return query(u << 1, l, r);
//    else if (l > mid) return query(u << 1 | 1, l, r);
//    else {
//        node res{};
//        pushup(res, query(u << 1, l, mid), query(u << 1 | 1, mid + 1, r));
//        return res;
//    }
//}
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, q;
//        cin >> n >> q;
//        for (int i = 1; i <= n; i++) cin >> a[i];
//        build(1, 1, n);
//        map<int, vector<int>> mp;
//        auto get_cnt = [&](int x, int l, int r) -> int {
//            return upper_bound(mp[x].begin(), mp[x].end(), r) - lower_bound(mp[x].begin(), mp[x].end(), l);
//        };
//        for (int i = 1; i <= n; i++) mp[a[i]].push_back(i);
//        while (q--) {
//            int l, r;
//            cin >> l >> r;
//            node res = query(1, l, r);
//            if (res.val1 > res.val2) swap(res.val1, res.val2);
//            int mi = (r - l + 1) / 3;
//            int cnt = 0;
//            if (get_cnt(res.val1, l, r) > mi) {
//                cout << res.val1 << ' ';
//                cnt++;
//            }
//            if (get_cnt(res.val2, l, r) > mi) {
//                cout << res.val2 << ' ';
//                cnt++;
//            }
//            if (!cnt) cout << -1 << ' ';
//            cout << endl;
//        }
//    }
//    return 0;
//}

// 142. https://codeforces.com/problemset/problem/2149/F
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int h, d;
//        cin >> h >> d;
//        int l = 0, r = d;
//        while (l <= r) {
//            int mid = (l + r) >> 1;
//            int duan = min(d, mid + 1);
//            int t = d / duan;
//            int cnt2 = d - t * duan;
//            int cnt1 = duan - cnt2;
//            int c = t * (t + 1) / 2 * cnt1 + (t + 1) * (t + 2) / 2 * cnt2;
//            if (h + mid > c) r = mid - 1;
//            else l = mid + 1;
//        }
//        cout << d + r + 1 << endl;
//    }
//    return 0;
//}

// 143. https://www.luogu.com.cn/problem/P3834   P3834 【模板】可持久化线段树 2
//#include <bits/stdc++.h>
//#define endl '\n'
//using namespace std;
//const int N = 2e5 + 10;
//
//struct node {
//    int lc, rc, sum;
//} tr[22 * N];
//int cnt, root[N];
//
//void build(int& u, int l, int r) {
//    u = ++cnt;
//    if (l == r) return;
//    int mid = (l + r) >> 1;
//    build(tr[u].lc, l, mid);
//    build(tr[u].rc, mid + 1, r);
//}
//
//void insert(int pre, int& u, int l, int r, int pos) {
//    u = ++cnt;
//    tr[u] = tr[pre], tr[u].sum++;
//    if (l == r) return;
//    int mid = (l + r) >> 1;
//    if (pos <= mid) insert(tr[pre].lc, tr[u].lc, l, mid, pos);
//    else insert(tr[pre].rc, tr[u].rc, mid + 1, r, pos);
//}
//
//int query(int ql, int qr, int l, int r, int x) {
//    if (l == r) return r;
//    int mid = (l + r) >> 1;
//    int sum = tr[tr[qr].lc].sum - tr[tr[ql].lc].sum;
//    if (sum >= x) return query(tr[ql].lc, tr[qr].lc, l, mid, x);
//    else return query(tr[ql].rc, tr[qr].rc, mid + 1, r, x - sum);
//}
//
//signed main() {
//    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
//    int n, m;
//    cin >> n >> m;
//    vector<int> a(n + 1);
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    vector<int> b = a;
//    sort(b.begin() + 1, b.end());
//    b.erase(unique(b.begin() + 1, b.end()), b.end());
//    vector<int> id(n + 1);
//    for (int i = 1; i <= n; i++) id[i] = lower_bound(b.begin() + 1, b.end(), a[i]) - b.begin();
//    int len = b.size() + 1;
//    build(root[0], 1, len);
//    for (int i = 1; i <= n; i++) insert(root[i - 1], root[i], 1, len, id[i]);
//    while (m--) {
//        int l, r, x;
//        cin >> l >> r >> x;
//        cout << b[query(root[l - 1], root[r], 1, len, x)] << endl;
//    }
//    return 0;
//}

// 144. https://www.luogu.com.cn/problem/P3919
//#include <iostream>
//#include <vector>
//using namespace std;
//#define endl '\n'
//const int N = 1e6 + 10;
//
//struct node {
//    int lc, rc;
//    int x;
//};
//vector<node> tr;
//int a[N], root[N];
//
//int build(int l, int r) {
//    int u = (int)tr.size();
//    tr.push_back({0, 0, 0});
//    if (l == r) {
//        tr[u].x = a[l];
//        return u;
//    }
//    int mid = (l + r) >> 1;
//    int x1 = build(l, mid);
//    int x2 = build(mid + 1, r);
//    tr[u].lc = x1, tr[u].rc = x2;
//    return u;
//}
//
//int insert(int pre, int l, int r, int pos, int x) {
//    int u = (int)tr.size();
//    tr.push_back({0, 0, 0});
//    tr[u] = tr[pre];
//    if (l == r) {
//        tr[u].x = x;
//        return u;
//    }
//    int mid = (l + r) >> 1;
//    if (pos <= mid) {
//        int t = insert(tr[pre].lc, l, mid, pos, x);
//        tr[u].lc = t;
//    } else {
//        int t = insert(tr[pre].rc, mid + 1, r, pos, x);
//        tr[u].rc = t;
//    }
//    return u;
//}
//
//int query(int u, int l, int r, int pos) {
//    if (l == r) return tr[u].x;
//    int mid = (l + r) >> 1;
//    if (pos <= mid) return query(tr[u].lc, l, mid, pos);
//    else return query(tr[u].rc, mid + 1, r, pos);
//}
//
//signed main() {
//    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
//    int n, m;
//    cin >> n >> m;
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    root[0] = build(1, n);
//    for (int i = 1; i <= m; i++) {
//        int v, op;
//        cin >> v >> op;
//        if (op == 1) {
//            int p, c;
//            cin >> p >> c;
//            root[i] = insert(root[v], 1, n, p, c);
//        } else {
//            int p;
//            cin >> p;
//            root[i] = root[v];
//            cout << query(root[i], 1, n, p) << endl;
//        }
//    }
//    return 0;
//}

// 145. https://www.luogu.com.cn/problem/P3379
// 最近公共祖先 tarjan 算法
//#include <bits/stdc++.h>
//using namespace std;
//const int N = 5e5 + 10;
//
//vector<pair<int, int>> q[N];
//vector<int> g[N];
//int vis[N], ans[N], fa[N];
//
//int find(int x) {
//    if (x != fa[x]) fa[x] = find(fa[x]);
//    return fa[x];
//}
//
//void tarjan(int u) {
//    vis[u] = 1;
//    fa[u] = u;
//    for (int v : g[u]) {
//        if (!vis[v]) {
//            tarjan(v);
//            fa[v] = u;
//        }
//    }
//
//    for (auto & [v, i] : q[u]) {
//        if (vis[v]) ans[i] = find(v);
//    }
//}
//
//signed main() {
//    int n, m, s;
//    cin >> n >> m >> s;
//    for (int i = 1; i < n; i++) {
//        int x, y;
//        cin >> x >> y;
//        g[x].emplace_back(y);
//        g[y].emplace_back(x);
//    }
//    for (int i = 1; i <= m; i++) {
//        int a, b;
//        cin >> a >> b;
//        q[a].emplace_back(b, i);
//        q[b].emplace_back(a, i);
//    }
//    tarjan(s);
//    for (int i = 1; i <= m; i++) cout << ans[i] << endl;
//    return 0;
//}


//
// Created by MINEC on 2025/11/17.
//

// 146. https://www.luogu.com.cn/problem/P2863
//#include <bits/stdc++.h>
//using namespace std;
//const int N = 1e4 + 10;
//
//vector<int> g[N];
//stack<int> stk;
//int instk[N], siz[N], dfn[N], low[N], scc[N];
//int cnt, tot;
//
//void tarjan(int u) {
//    dfn[u] = low[u] = ++tot;
//    stk.push(u), instk[u] = 1;
//    for (int v : g[u]) {
//        if (!dfn[v]) {
//            tarjan(v);
//            low[u] = min(low[u], low[v]);
//        } else if (instk[v]) {
//            low[u] = min(low[u], dfn[v]);
//        }
//    }
//
//    if (dfn[u] == low[u]) {
//        int v;
//        cnt++;
//        do {
//            v = stk.top();
//            stk.pop();
//            instk[v] = 0;
//            scc[v] = cnt;
//            siz[cnt]++;
//        } while (v != u);
//    }
//}
//
//signed main() {
//    int n, m;
//    cin >> n >> m;
//    for (int i = 1, a, b; i <= m; i++) {
//        cin >> a >> b;
//        g[a].push_back(b);
//    }
//    for (int i = 1; i <= n; i++) {
//        if (!dfn[i]) tarjan(i);
//    }
//    int ans = 0;
//    for (int i = 1; i <= cnt; i++) if (siz[i] > 1) ans++;
//    cout << ans << endl;
//    return 0;
//}

// 147. https://www.luogu.com.cn/problem/B3647
//#include <bits/stdc++.h>
//using namespace std;
//const int N = 110;
//
//int d[N][N], n, m;
//
//void floyd() {
//    for (int k = 1; k <= n; k++) {
//        for (int i = 1; i <= n; i++) {
//            for (int j = 1; j <= n; j++) {
//                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
//            }
//        }
//    }
//}
//
//signed main() {
//    cin >> n >> m;
//    memset(d, 0x3f, sizeof d);
//    for (int i = 1; i <= m; i++) {
//        int u, v, w;
//        cin >> u >> v >> w;
//        d[u][v] = min(d[u][v], w);
//        d[v][u] = min(d[u][v], w);
//    }
//    for (int i = 1; i <= n; i++) d[i][i] = 0;
//    floyd();
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= n; j++) {
//            cout << d[i][j] << ' ';
//        }
//        cout << endl;
//    }
//    return 0;
//}

// 148. https://www.luogu.com.cn/problem/B3647
//#include <bits/stdc++.h>
//using namespace std;
//const int N = 110;
//
//int n, m, d[N][N], ans[N][N];
//vector<int> g[N];
//
//void dijkstra(int i) {
//    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
//    vector<int> vis(n + 1);
//    q.emplace(0, i);
//    while (!q.empty()) {
//        auto [w, u] = q.top();
//        q.pop();
//        if (vis[u]) continue;
//        vis[u] = 1;
//        for (int v : g[u]) {
//            if (w + d[u][v] < ans[i][v]) {
//                ans[i][v] = w + d[u][v];
//                q.emplace(ans[i][v], v);
//            }
//        }
//    }
//}
//
//signed main() {
//    cin >> n >> m;
//    memset(d, 0x3f, sizeof d);
//    memset(ans, 0x3f, sizeof ans);
//    for (int i = 1, u, v, w; i <= m; i++) {
//        cin >> u >> v >> w;
//        d[u][v] = min(d[u][v], w);
//        d[v][u] = min(d[v][u], w);
//        g[u].emplace_back(v);
//        g[v].emplace_back(u);
//    }
//    for (int i = 1; i <= n; i++) d[i][i] = 0, ans[i][i] = 0;
//    for (int i = 1; i <= n; i++) dijkstra(i);
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= n; j++)
//            cout << ans[i][j] << ' ';
//        cout << endl;
//    }
//    return 0;
//}

// 149. https://codeforces.com/problemset/problem/2161/B
//#include <bits/stdc++.h>
//using namespace std;
//
//void solve() {
//    int n;
//    cin >> n;
//    int sum = 0;
//    vector<vector<char>> a(n + 1, vector<char>(n + 1));
//    for (int i = 1; i <= n; i++)
//        for (int j = 1; j <= n; j++)
//            cin >> a[i][j], sum += (a[i][j] == '#');
//    if (n <= 2) {
//        cout << "YES" << endl;
//        return;
//    }
//    for (int i = 2; i <= n; i++) {
//        for (int j = 2; j <= n; j++) {
//            int s = (a[i][j] == '#') + (a[i - 1][j] == '#') + (a[i][j - 1] == '#') + (a[i - 1][j - 1] == '#');
//            if (s == sum) {
//                cout << "YES" << endl;
//                return;
//            }
//        }
//    }
//    for (int i = 2; i <= 2 * n - 1; i++) {
//        int s = 0;
//        for (int j = 1; j <= n; j++) if (i - j > 0 && i - j <= n) s += (a[j][i - j] == '#');
//        for (int j = 1; j <= n; j++) if (i - j + 1 > 0 && i - j + 1 <= n) s += (a[j][i - j + 1] == '#');
//        if (s == sum) {
//            cout << "YES" << endl;
//            return;
//        }
//    }
//    for (int i = 1 - n; i <= n - 2; i++) {
//        int s = 0;
//        for (int j = 1; j <= n; j++) if (j - i > 0 && j - i <= n) s += (a[j][j - i] == '#');
//        for (int j = 1; j <= n; j++) if (j - i - 1 > 0 && j - i - 1 <= n) s += (a[j][j - i - 1] == '#');
//        if (s == sum) {
//            cout << "YES" << endl;
//            return;
//        }
//    }
//    cout << "NO" << endl;
//}
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        solve();
//    }
//    return 0;
//}

// 150. https://www.luogu.com.cn/problem/AT_abc386_e
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//const int N = 2e5 + 10;
//
//int ans, n, k, a[N];
//
//void dfs(int deep, int res, int start) {
//    if (deep == k) {
//        ans = max(ans, res);
//        return;
//    }
//    for (int i = start; n - i + 1 >= k - deep; i++)
//        dfs(deep + 1, res ^ a[i], i + 1);
//}
//
//signed main() {
//    cin >> n >> k;
//    int sum = 0;
//    for (int i = 1; i <= n; i++) cin >> a[i], sum ^= a[i];
//    if (n - k > k) sum = 0;
//    else k = n - k;
//    dfs(0, sum, 1);
//    cout << ans << endl;
//    return 0;
//}

// 2025.11.28 VP Educational Codeforces Round 145 (Rated for Div. 2)
// 151. A
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        set<char> st;
//        string s;
//        cin >> s;
//        for (char c : s) st.insert(c);
//        if (st.size() == 1) {
//            cout << -1 << endl;
//        } else if (st.size() == 2) {
//            sort(s.begin(), s.end());
//            if (s[1] == s[2]) cout << 6 << endl;
//            else cout << 4 << endl;
//        } else {
//            cout << 4 << endl;
//        }
//    }
//    return 0;
//}

// 152. B
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
//        int l = 0, r = 1e9;
//        while (l <= r) {
//            int mid = (l + r) >> 1;
//            if ((mid + 1) * (mid + 1) >= n) r = mid - 1;
//            else l = mid + 1;
//        }
//        cout << r + 1 << endl;
//    }
//    return 0;
//}

// 153. C
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
//        vector<int> a(n + 1, -999);
//        int cnt = 0;
//        int i;
//        for (i = 1; i <= n; i++) {
//            if (cnt == k) break;
//            if (cnt + i <= k) a[i] = 1, cnt += i;
//            else break;
//        }
//        i = 0;
//        while (cnt != k) {
//            i++;
//            cnt++;
//        }
//        a[i] = 1000;
//        for (i = 1; i <= n; i++) cout << a[i] << ' ';
//        cout << endl;
//    }
//    return 0;
//}

// 154. D
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int t = 1e12;
//    int T;
//    cin >> T;
//    while (T--) {
//        string s;
//        cin >> s;
//        s = " " + s;
//        int n = s.size() - 1;
//        vector<int> a(n + 1);
//        for (int i = 1; i <= n; i++) a[i] = a[i - 1] + (s[i] - '0');
//        int ans = 1e18;
//        for (int i = 1; i <= n; i++) {
//            if (s[i] == '0' && s[i - 1] == '1') {
//                ans = min(ans, t + (t + 1) * (a[i - 2] - a[n] + a[i] + n - i));
//            } else {
//                ans = min(ans, (t + 1) * (a[i - 1] - a[n] + a[i] + n - i));
//            }
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

// 155. https://ac.nowcoder.com/acm/contest/122017/G
//#include <bits/stdc++.h>
//#define int long long
//const int N = 2e5 + 10, INF = 1e18;
//
//struct node {
//    int l, r;
//    int mx;
//} tr1[N << 2], tr2[N << 2];
//
//std::vector<int> a, b, idx;
//
//void build(int u, int l, int r) {
//    tr1[u] = {l, r};
//    tr2[u] = {l, r};
//    if (l == r) {
//        tr1[u].mx = tr2[u].mx = -INF;
//        return;
//    }
//    int mid = (l + r) >> 1;
//    build(u << 1, l, mid);
//    build(u << 1 | 1, mid + 1, r);
//}
//
//void modify(node tr[], int u, int pos, int v) {
//    if (tr[u].l == tr[u].r) {
//        tr[u].mx = std::max(tr[u].mx, v);
//        return;
//    }
//    int mid = (tr[u].l + tr[u].r) >> 1;
//    if (pos <= mid) modify(tr, u << 1, pos, v);
//    else modify(tr, u << 1 | 1, pos, v);
//    tr[u].mx = std::max(tr[u << 1].mx, tr[u << 1 | 1].mx);
//}
//
//int query(node tr[], int u, int l, int r) {
//    if (l > r) return -INF;
//    if (l <= tr[u].l && tr[u].r <= r) return tr[u].mx;
//    int mid = (tr[u].l + tr[u].r) >> 1;
//    if (r <= mid) return query(tr, u << 1, l, r);
//    else if (l > mid) return query(tr, u << 1 | 1, l, r);
//    else return std::max(query(tr, u << 1, l, mid), query(tr, u << 1 | 1, mid + 1, r));
//}
//
//signed main() {
//    int n, k;
//    std::cin >> n >> k;
//    a.resize(n + 1);
//    idx.resize(n + 1);
//    for (int i = 1; i <= n; i++) std::cin >> a[i];
//    b = a;
//    std::sort(b.begin() + 1, b.end());
//    b.erase(std::unique(b.begin() + 1, b.end()), b.end());
//    for (int i = 1; i <= n; i++) idx[i] = std::lower_bound(b.begin() + 1, b.end(), a[i]) - b.begin();
//    int M = b.size() - 1;
//    build(1, 1, M);
//    int ans = 0;
//    for (int i = 1; i <= n; i++) {
//        int id = idx[i];
//        int v1 = query(tr2, 1, 1, id - 1);
//        int v2 = query(tr1, 1, id + 1, M);
//
//        int dp1 = a[i], dp2 = a[i];
//        dp1 = std::max(dp1, dp1 + v1 - i * k + k);
//        dp2 = std::max(dp2, dp2 + v2 - i * k + k);
//        ans = std::max({ans, dp1, dp2});
//
//        modify(tr1, 1, id, dp1 + i * k);
//        modify(tr2, 1, id, dp2 + i * k);
//    }
//    std::cout << ans << std::endl;
//    return 0;
//}

// 156. https://ac.nowcoder.com/acm/contest/122017/C
//#include <bits/stdc++.h>
//const int N = 1e4 + 5;
//#define int long long
//
//std::vector<int> g[N], g0[N], g1[N];
//int dfn[N], low[N], scc[N], instk[N], cnt, tim;
//std::stack<int> st;
//std::bitset<N> bin[N], bout[N];
//int in0[N], in1[N], n, m;
//
//void tarjan(int u) {
//    dfn[u] = low[u] = ++tim;
//    st.push(u);
//    instk[u] = 1;
//    for (int v : g[u]) {
//        if (!dfn[v]) {
//            tarjan(v);
//            low[u] = std::min(low[u], low[v]);
//        } else if (instk[v]) {
//            low[u] = std::min(low[u], dfn[v]);
//        }
//    }
//    if (dfn[u] == low[u]) {
//        cnt++;
//        int v;
//        do {
//            v = st.top();
//            st.pop();
//            instk[v] = 0;
//            scc[v] = cnt;
//        } while (v != u);
//    }
//}
//
//void topo() {
//    std::queue<int> q;
//    for (int i = 1; i <= cnt; i++) {
//        if (!in0[i]) q.push(i);
//    }
//    while (!q.empty()) {
//        int u = q.front();
//        q.pop();
//        for (int v : g0[u]) {
//            bin[v] |= bin[u];
//            in0[v]--;
//            if (!in0[v]) q.push(v);
//        }
//    }
//    for (int i = 1; i <= cnt; i++) {
//        if (!in1[i]) q.push(i);
//    }
//    while (!q.empty()) {
//        int u = q.front();
//        q.pop();
//        for (int v : g1[u]) {
//            bout[v] |= bout[u];
//            in1[v]--;
//            if (!in1[v]) q.push(v);
//        }
//    }
//}
//
//signed main() {
//    std::cin >> n >> m;
//    for (int i = 1; i <= m; i++) {
//        int u, v;
//        std::cin >> u >> v;
//        g[u].emplace_back(v);
//    }
//    for (int i = 1; i <= n; i++) {
//        if (!dfn[i]) tarjan(i);
//    }
//    for (int i = 1; i <= n; i++) {
//        bin[scc[i]][i] = true;
//        bout[scc[i]][i] = true;
//        for (int v : g[i]) {
//            if (scc[v] != scc[i]) {
//                g0[scc[i]].emplace_back(scc[v]);
//                in0[scc[v]]++;
//                g1[scc[v]].emplace_back(scc[i]);
//                in1[scc[i]]++;
//            }
//        }
//    }
//    topo();
//    for (int i = 1; i <= n; i++) {
//        std::cout << (bin[scc[i]].count() - 1) * (bout[scc[i]].count() - 1) - (bin[scc[i]] & bout[scc[i]]).count() + 1 << std::endl;
//    }
//    return 0;
//}

// 157. https://codeforces.com/contest/2172/problem/F
//#include <bits/stdc++.h>
//#define int long long
//
//signed main() {
//    int n;
//    std::cin >> n;
//    std::vector<int> a(n + 1), st(n + 1), en(n + 2);
//    for (int i = 1; i <= n; i++) std::cin >> a[i];
//    for (int i = 1; i <= n; i++) st[i] = std::gcd(st[i - 1], a[i]);
//    for (int i = n; i >= 1; i--) en[i] = std::gcd(en[i + 1], a[i]);
//    int ans = st[n];
//    for (int i = 2; i <= n - 1; i++) ans += std::min(st[i], en[i]);
//    std::cout << ans << std::endl;
//    return 0;
//}

// 2025.12.2 VP Educational Codeforces Round 144 (Rated for Div. 2)
// 158. A
//#include <bits/stdc++.h>
//using namespace std;
//
//signed main() {
//    string s = "FBFFBFFBFBFFBFFBFBFFBFFBFBFFBFFBFBFFBFFBFBFFBFFBFBF";
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        string t;
//        cin >> t;
//        if (s.find(t) != string::npos) cout << "YES" << endl;
//        else cout << "NO" << endl;
//    }
//    return 0;
//}

// 159. B
// #include <bits/stdc++.h>
// using namespace std;
//
// void solve() {
//     string a, b;
//     cin >> a >> b;
//     if (a[0] == b[0]) {
//         cout << "YES" << endl;
//         cout << a[0] << '*' << endl;
//     } else if (a.back() == b.back()) {
//         cout << "YES" << endl;
//         cout << '*' << a.back() << endl;
//     } else {
//         for (int i = 0; i < a.size() - 1; i++) {
//             string t = a.substr(i, 2);
//             if (b.find(t) != string::npos) {
//                 cout << "YES" << endl;
//                 cout << "*" + t + "*" << endl;
//                 return;
//             }
//         }
//         cout << "NO" << endl;
//     }
// }
//
// signed main() {
//     int T;
//     cin >> T;
//     while (T--) {
//         solve();
//     }
//     return 0;
// }

// 160. C
// #include <bits/stdc++.h>
// using namespace std;
//
// void solve() {
//     int l, r;
//     cin >> l >> r;
//     int mx = (int)log2l(r / l);
//     int ans = r / (1 << mx) - l + 1;
//     int t = r / (1 << (mx - 1)) / 3 - l + 1;
//     if (t > 0) ans += t * mx;
//     cout << mx + 1 << ' ' << ans << endl;
// }
//
// signed main() {
//     int T;
//     cin >> T;
//     while (T--) {
//         solve();
//     }
//     return 0;
// }

// 161. https://www.luogu.com.cn/problem/CF559C
// #include <bits/stdc++.h>
// #define int long long
//
// constexpr int N = 2e5 + 10;
// constexpr int mod = 1e9 + 7;
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
// signed main() {
//     init();
//     int h, w, n;
//     std::cin >> h >> w >> n;
//     std::vector<std::pair<int, int>> a(n + 1);
//     for (int i = 0; i < n; i++) std::cin >> a[i].first >> a[i].second;
//     a[n].first = h, a[n].second = w;
//     std::sort(a.begin(), a.end());
//     std::vector<int> dp(n + 1);
//     for (int i = 0; i <= n; i++) {
//         dp[i] = C(a[i].first + a[i].second - 2, a[i].first - 1);
//         for (int j = i - 1; j >= 0; j--) {
//             if (a[j].first <= a[i].first && a[j].second <= a[i].second) {
//                 int jian = C(a[i].first - a[j].first + a[i].second - a[j].second, a[i].first - a[j].first);
//                 jian = jian * dp[j] % mod;
//                 dp[i] = ((dp[i] - jian) % mod + mod) % mod;
//             }
//         }
//     }
//     std::cout << dp[n] << std::endl;
//     return 0;
// }

// 162. https://codeforces.com/gym/105901/problem/G
// #include <bits/stdc++.h>
// #define int long long
//
// constexpr int N = 1e5 + 10;
// constexpr int mod = 998244353;
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
// signed main() {
//     std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
//     init();
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n, m;
//         std::cin >> n >> m;
//         std::vector a(n + 1, std::vector<int>(m + 1));
//         std::vector cnt(n * m + 1, 0);
//         for (int i = 1; i <= n; i++) {
//             for (int j = 1; j <= m; j++) {
//                 std::cin >> a[i][j];
//                 cnt[a[i][j]]++;
//             }
//         }
//         std::unordered_map<int, std::vector<std::pair<int, int>>> mp;
//         for (int i = 1; i <= n; i++) {
//             for (int j = 1; j <= m; j++) {
//                 mp[a[i][j]].emplace_back(i, j);
//             }
//         }
//         const int B = static_cast<long long>(sqrtl(n * m));
//         int ans = 0;
//         for (int z = 1; z <= n * m; z++) {
//             if (cnt[z] < B) {
//                 auto& v = mp[z];
//                 v.emplace_back(n, m);
//                 std::vector<int> dp(v.size());
//                 for (int i = 0; i < v.size(); i++) {
//                     const int xi = v[i].first, yi = v[i].second;
//                     dp[i] = C(xi + yi - 2, xi - 1);
//                     for (int j = i - 1; j >= 0; j--) {
//                         const int yj = v[j].second;
//                         if (const int xj = v[j].first; xi >= xj && yi >= yj) {
//                             const int jian = dp[j] * C(xi - xj + yi - yj, xi - xj) % mod;
//                             dp[i] = (dp[i] - jian) % mod;
//                         }
//                     }
//                 }
//                 ans = (ans + C(n + m - 2, n - 1) - dp.back()) % mod;
//             } else {
//                 std::vector dp(n + 1, std::vector<int>(m + 1));
//                 dp[1][1] = (z != a[1][1]);
//                 for (int i = 1; i <= n; i++) {
//                     for (int j = 1; j <= m; j++) {
//                         if (i == 1 && j == 1) continue;
//                         if (a[i][j] == z) dp[i][j] = 0;
//                         else dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
//                     }
//                 }
//                 ans = (ans + C(n + m - 2, n - 1) - dp[n][m]) % mod;
//             }
//         }
//         std::cout << (ans + mod) % mod << '\n';
//     }
//     return 0;
// }

// 163. https://codeforces.com/gym/105901/problem/A
// #include <bits/stdc++.h>
// #define int long long
//
// void solve() {
//     int n, q;
//     std::cin >> n >> q;
//     std::vector<int> a(n + 1);
//     for (int i = 1; i <= n; i++) std::cin >> a[i];
//     std::vector<std::pair<int, int>> b(n + 1);
//     for (int i = 1; i <= q; i++) {
//         int p, l, r;
//         std::cin >> p >> l >> r;
//         if (b[p].first == 0) b[p] = {l, r};
//         else b[p] = {std::max(b[p].first, l), std::min(b[p].second, r)};
//     }
//     int ans = 0;
//     for (int i = 1; i <= n; i++) {
//         if (b[i].first > b[i].second) {
//             std::cout << -1 << std::endl;
//             return;
//         }
//         if (!b[i].first) continue;
//         const int l = b[i].first, r = b[i].second, x = a[i];
//         ans += l <= x && x <= r ? 0 : std::min(std::abs(l - x), std::abs(r - x));
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

// 164. https://codeforces.com/gym/105901/problem/L
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
//         int ans = 1;
//         for (int i = 1; i <= n; i++) std::cin >> a[i];
//         std::sort(a.begin() + 1, a.end());
//         std::map<int, int> id;
//         for (int i = 1; i <= n; i++) id[a[i]] = i;
//         for (int i = 1; i <= n; i++) {
//             for (int j = i; j <= n; j++) {
//                 const int x = 2 * a[j] - a[i];
//                 if (id.find(x) == id.end()) continue;
//                 if (id[x] - j < j - i) ans = std::max(2 * (id[x] - j) + 1, ans);
//                 else if (id[x] - j > j - i) ans = std::max(ans, 2 * (j - i + 1));
//                 else ans = std::max(ans, 2 * (j - i) + 1);
//             }
//         }
//         std::cout << ans << '\n';
//     }
//     return 0;
// }

// 165. https://codeforces.com/gym/105901/problem/I
// #include <bits/stdc++.h>
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n, k;
//         std::cin >> n >> k;
//         if (k <= n - 1 || k >= n * n - n + 2) std::cout << "No" << std::endl;
//         else {
//             std::cout << "Yes" << std::endl;
//             std::vector a(n + 1, std::vector<int>(n + 1));
//             std::set<int> s;
//             for (int i = 1; i <= n * n; i++) s.insert(i);
//             a[1][1] = k;
//             s.erase(k);
//             int t = 1;
//             for (int i = 2; i <= n; i++) a[1][i] = t, s.erase(t++);
//             t = n * n;
//             for (int i = 2; i <= n; i++) {
//                 a[i][i] = t;
//                 s.erase(t--);
//             }
//             for (int i = 2; i <= n; i++) {
//                 for (int j = 1; j <= n; j++) {
//                     if (!a[i][j]) {
//                         a[i][j] = *s.begin();
//                         s.erase(s.begin());
//                     }
//                 }
//             }
//             for (int i = 1; i <= n; i++) {
//                 for (int j = 1; j <= n; j++) {
//                     std::cout << a[i][j] << ' ';
//                 }
//                 std::cout << std::endl;
//             }
//         }
//     }
//     return 0;
// }

// 166. https://codeforces.com/problemset/problem/1978/E
// #include <bits/stdc++.h>
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n;
//         std::cin >> n;
//         std::string a, b;
//         std::cin >> a >> b;
//         a = " " + a, b = " " + b;
//         std::vector<int> dp(n + 1), sum(n + 1), x1(n + 1), x2(n + 1);
//         for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + (a[i] == '1');
//         for (int i = 3; i <= n; i++) {
//             dp[i] = dp[i - 1] - x1[i - 2];
//             if (a[i - 1] == '0') {
//                 if ((a[i - 3] == '0' || b[i - 2] == '1') && b[i] == '1') {
//                     dp[i]++;
//                     x1[i - 1]++;
//                 }
//             }
//             if (a[i - 2] == '0') {
//                 if ((b[i - 1] == '1' || a[i] == '0') && (b[i - 3] == '1' || (i > 4 && a[i - 4] == '0'))) {
//                     dp[i]++;
//                     x2[i - 2]++;
//                 }
//             }
//         }
//         int q;
//         std::cin >> q;
//         while (q--) {
//             int l, r;
//             std::cin >> l >> r;
//             if (r - l + 1 <= 2) std::cout << sum[r] - sum[l - 1] << std::endl;
//             else {
//                 int ans = sum[r] - sum[l - 1] + dp[r] - dp[l + 2] + x1[l + 1];
//                 if (x1[l + 1] || (x2[l + 1] && l + 3 <= r)) {
//                     if (b[l] != '1') ans--;
//                 }
//                 std::cout << ans << std::endl;
//             }
//         }
//     }
//     return 0;
// }

// 167. https://www.luogu.com.cn/problem/CF2171D
// #include <bits/stdc++.h>
//
// void solve() {
//     std::set<int> sa, sb;
//     int n;
//     std::cin >> n;
//     std::vector<int> a(n + 1);
//     for (int i = 1; i <= n; i++) std::cin >> a[i];
//     for (int i = 1; i <= n; i++) sb.insert(a[i]);
//     for (int i = 1; i < n; i++) {
//         sa.insert(a[i]), sb.erase(a[i]);
//         if (*sa.begin() > *sb.rbegin()) {
//             std::cout << "No" << std::endl;
//             return;
//         }
//     }
//     std::cout << "Yes" << std::endl;
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

// 168. https://codeforces.com/contest/2171/problem/F
// #include <bits/stdc++.h>
//
// void solve() {
//     int n;
//     std::cin >> n;
//     std::vector<int> a(n + 1);
//     for (int i = 1; i <= n; i++) std::cin >> a[i];
//     std::set<int> sa, sb;
//     for (int i = 1; i <= n; i++) sb.insert(a[i]);
//     std::vector<std::pair<int, int>> tr;
//     int mx = 0;
//     for (int i = 1; i < n; i++) {
//         sa.insert(a[i]), sb.erase(a[i]);
//         if (*sa.begin() > *sb.rbegin()) {
//             std::cout << "No" << std::endl;
//             return;
//         }
//         if (mx == *sb.rbegin()) {
//             tr.emplace_back(a[i], *sb.rbegin());
//         } else {
//             tr.emplace_back(*sa.begin(), *sb.rbegin());
//         }
//         mx = *sb.rbegin();
//     }
//     std::cout << "Yes" << std::endl;
//     for (const auto& [l, r] : tr) {
//         std::cout << l << ' ' << r << std::endl;
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

// 169. 区间乘
// #include <bits/stdc++.h>
// #define int long long
//
// signed main() {
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n, q;
//         std::cin >> n >> q;
//         std::vector<int> a(n + 1);
//         for (int i = 1; i <= n; i++) std::cin >> a[i];
//         std::unordered_map<int, int> mp;
//         for (int i = 1; i <= n; i++) mp[a[i]] = 1;
//         std::vector<int> b;
//         for (int i = 1; i <= n; i++) {
//             if (a[i] != 1) b.emplace_back(a[i]);
//         }
//         int m = b.size();
//         for (int i = 0; i < m; i++) {
//             int t = b[i];
//             for (int j = 1; j <= 30 && i + j < m; j++) {
//                 t *= b[i + j];
//                 if (t > 1e9) break;
//                 mp[t] = 1;
//             }
//         }
//         while (q--) {
//             int x;
//             std::cin >> x;
//             if (mp[x]) std::cout << "YES" << std::endl;
//             else std::cout << "NO" << std::endl;
//         }
//     }
//     return 0;
// }

// 170. https://codeforces.com/gym/105143/problem/B
// #include <bits/stdc++.h>
// #define int long long
//
// signed main() {
//     int n;
//     std::cin >> n;
//     int sum = 0;
//     for (int i = 1, y; i <= n; i++) std::cin >> y, sum += y;
//     if (sum == 0) {
//         std::cout << 0 << std::endl;
//         return 0;
//     }
//     int l = 0, r = 1e12;
//     while (l <= r) {
//         int mid = (l + r) >> 1;
//         std::stack<int> st;
//         int t = mid;
//         while (t) {
//             st.push(t & 1);
//             t >>= 1;
//         }
//         int s = sum;
//         bool f = false;
//         while (!st.empty()) {
//             int x = (1LL << (st.size() - 1)) * st.top();
//             st.pop();
//             if (!x) continue;
//             if (x * n >= s) {
//                 int mx = x * n - n;
//                 if (s <= mx || st.empty()) {
//                     f = true;
//                     r = mid - 1;
//                     break;
//                 }
//                 s %= x;
//                 if (s == 0) {
//                     f = true;
//                     r = mid - 1;
//                     break;
//                 }
//             } else {
//                 s -= x * n;
//             }
//         }
//         if (!f) {
//             l = mid + 1;
//         }
//     }
//     std::cout << r + 1 << std::endl;
//     return 0;
// }

// 171. https://codeforces.com/gym/105143/problem/I
// #include <bits/stdc++.h>
// using namespace std;
//
// signed main() {
//     std::string s;
//     std::cin >> s;
//     std::vector<char> a;
//     for (char c : s) {
//         if (a.empty() || a.back() != c) a.emplace_back(c);
//     }
//     int ans = a.size();
//     if (a.front() == '0') ans--;
//     if (a.back() == '1') ans--;
//     ans /= 2;
//     std::cout << ans << std::endl;
//     return 0;
// }

// 172. https://codeforces.com/gym/105143/problem/K
// #include <bits/stdc++.h>
//
// int main() {
//     std::vector<std::string> ans = {"", "Fluttershy", "Pinkie Pie", "Pinkie Pie", "Fluttershy"};
//     int T;
//     std::cin >> T;
//     while (T--) {
//         int n;
//         std::cin >> n;
//         n %= 4;
//         if (n == 0) n = 4;
//         std::cout << ans[n] << std::endl;
//     }
//     return 0;
// }

// 173. https://codeforces.com/contest/1936/problem/B
// #include <bits/stdc++.h>
// #define int long long
//
// void solve() {
//     int n;
//     std::string s;
//     std::cin >> n >> s;
//     s = " " + s;
//     std::vector<int> cntl(n + 1), cntr(n + 1);
//     std::vector<int> suml(n + 1), sumr(n + 1);
//     for (int i = 1; i <= n; i++) {
//         cntl[i] = cntl[i - 1] + (s[i] == '<');
//         suml[i] = suml[i - 1] + (s[i] == '<') * i;
//         cntr[i] = cntr[i - 1] + (s[i] == '>');
//         sumr[i] = sumr[i - 1] + (s[i] == '>') * i;
//     }
//     for (int i = 1; i <= n; i++) {
//         if (s[i] == '<') {
//             int l_r = cntr[i - 1];
//             int r_l = cntl[n] - cntl[i];
//             if (l_r <= r_l) {
//                 int c = l_r;
//                 int sum = i;
//                 int l = i, r = n;
//                 while (l <= r) {
//                     int mid = (l + r) >> 1;
//                     int cnt = cntl[mid] - cntl[i];
//                     if (cnt >= c) r = mid - 1;
//                     else l = mid + 1;
//                 }
//                 int r_sum = suml[r + 1] - suml[i] - c * i;
//                 int l_sum = c * i - sumr[i];
//                 sum += 2 * (l_sum + r_sum);
//                 std::cout << sum << ' ';
//             } else {
//                 int c = r_l + 1;
//                 int sum = n - i + 1;
//                 int l = 1, r = i;
//                 while (l <= r) {
//                     int mid = (l + r) >> 1;
//                     int cnt = cntr[i] - cntr[mid - 1];
//                     if (cnt >= c) l = mid + 1;
//                     else r = mid - 1;
//                 }
//                 int r_sum = suml[n] - suml[i] - (c - 1) * i;
//                 int l_sum = c * i - (sumr[i] - sumr[l - 2]);
//                 sum += 2 * (l_sum + r_sum);
//                 std::cout << sum << ' ';
//             }
//         } else {
//             int l_r = cntr[i - 1];
//             int r_l = cntl[n] - cntl[i];
//             if (l_r < r_l) {
//                 int c = l_r + 1;
//                 int sum = i;
//                 int l = i, r = n;
//                 while (l <= r) {
//                     int mid = (l + r) >> 1;
//                     int cnt = cntl[mid] - cntl[i];
//                     if (cnt >= c) r = mid - 1;
//                     else l = mid + 1;
//                 }
//                 int r_sum = suml[r + 1] - suml[i] - c * i;
//                 int l_sum = (c - 1) * i - sumr[i - 1];
//                 sum += 2 * (l_sum + r_sum);
//                 std::cout << sum << ' ';
//             } else {
//                 int c = r_l;
//                 int sum = n - i + 1;
//                 int l = 1, r = i;
//                 while (l <= r) {
//                     int mid = (l + r) >> 1;
//                     int cnt = cntr[i - 1] - cntr[mid - 1];
//                     if (cnt >= c) l = mid + 1;
//                     else r = mid - 1;
//                 }
//                 int r_sum = suml[n] - suml[i] - c * i;
//                 int l_sum = c * i - (sumr[i - 1] - sumr[l - 2]);
//                 sum += 2 * (l_sum + r_sum);
//                 std::cout << sum << ' ';
//             }
//         }
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

// 174. https://www.luogu.com.cn/problem/P8600
// #include <bits/stdc++.h>
// const int N = 50010;
//
// struct node {
//     int l, r, mi, cnt, tag;
// } tr[N << 2];
//
// int a[N], st1[N], st2[N], top1, top2;
//
// void pushup(int u) {
//     tr[u].mi = std::min(tr[u << 1].mi, tr[u << 1 | 1].mi);
//     tr[u].cnt = (tr[u << 1].mi == tr[u].mi ? tr[u << 1].cnt : 0) +
//         (tr[u << 1 | 1].mi == tr[u].mi ? tr[u << 1 | 1].cnt : 0);
// }
//
// void pushdown(int u) {
//     if (tr[u].tag) {
//         tr[u << 1].tag += tr[u].tag;
//         tr[u << 1].mi += tr[u].tag;
//         tr[u << 1 | 1].tag += tr[u].tag;
//         tr[u << 1 | 1].mi += tr[u].tag;
//         tr[u].tag = 0;
//     }
// }
//
// void build(int u, int l, int r) {
//     tr[u] = {l, r};
//     if (l == r) {
//         tr[u].mi = l;
//         tr[u].cnt = 1;
//         return;
//     }
//     int mid = (l + r) >> 1;
//     build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
//     pushup(u);
// }
//
// void modify(int u, int l, int r, int val) {
//     if (l <= tr[u].l && tr[u].r <= r) {
//         tr[u].mi += val;
//         tr[u].tag += val;
//         return;
//     }
//     pushdown(u);
//     int mid = (tr[u].l + tr[u].r) >> 1;
//     if (r <= mid) modify(u << 1, l, r, val);
//     else if (l > mid) modify(u << 1 | 1, l, r, val);
//     else modify(u << 1, l, mid, val), modify(u << 1 | 1, mid + 1, r, val);
//     pushup(u);
// }
//
// signed main() {
//     int n;
//     std::cin >> n;
//     for (int i = 1; i <= n; i++) std::cin >> a[i];
//     build(1, 1, n);
//     long long ans = 0;
//     for (int i = 1; i <= n; i++) {
//         int p = i;
//         while (top1 && a[i] < a[st1[top1]]) {
//             modify(1, st1[top1 - 1] + 1, p - 1, a[st1[top1]] - a[i]);
//             p = st1[top1 - 1] + 1;
//             top1--;
//         }
//         p = i;
//         while (top2 && a[i] > a[st2[top2]]) {
//             modify(1, st2[top2 - 1] + 1, p - 1, a[i] - a[st2[top2]]);
//             p = st2[top2 - 1] + 1;
//             top2--;
//         }
//         st1[++top1] = st2[++top2] = i;
//         ans += tr[1].cnt;
//     }
//     std::cout << ans << std::endl;
//     return 0;
// }

// 175. https://www.luogu.com.cn/problem/CF526F   和上题类似，双倍经验
// #include <bits/stdc++.h>
// constexpr int N = 3e5 + 10;
//
// struct node {
//     int l, r, mi, cnt, tag;
// } tr[N << 2];
//
// int a[N], st1[N], st2[N], top1, top2;
//
// void pushup(int u) {
//     tr[u].mi = std::min(tr[u << 1].mi, tr[u << 1 | 1].mi);
//     tr[u].cnt = (tr[u << 1].mi == tr[u].mi ? tr[u << 1].cnt : 0) +
//                 (tr[u << 1 | 1].mi == tr[u].mi ? tr[u << 1 | 1].cnt : 0);
// }
//
// void pushdown(int u) {
//     if (tr[u].tag) {
//         tr[u << 1].mi += tr[u].tag;
//         tr[u << 1].tag += tr[u].tag;
//         tr[u << 1 | 1].mi += tr[u].tag;
//         tr[u << 1 | 1].tag += tr[u].tag;
//         tr[u].tag = 0;
//     }
// }
//
// void build(int u, int l, int r) {
//     tr[u] = {l, r};
//     if (l == r) {
//         tr[u].mi = l;
//         tr[u].cnt = 1;
//         return;
//     }
//     int mid = (l + r) >> 1;
//     build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
//     pushup(u);
// }
//
// void modify(int u, int l, int r, int val) {
//     if (l <= tr[u].l && tr[u].r <= r) {
//         tr[u].mi += val;
//         tr[u].tag += val;
//         return;
//     }
//     pushdown(u);
//     int mid = (tr[u].l + tr[u].r) >> 1;
//     if (r <= mid) modify(u << 1, l, r, val);
//     else if (l > mid) modify(u << 1 | 1, l, r, val);
//     else modify(u << 1, l, mid, val), modify(u << 1 | 1, mid + 1, r, val);
//     pushup(u);
// }
//
// signed main() {
//     int n;
//     std::cin >> n;
//     for (int i = 1; i <= n; i++) {
//         int r, c;
//         std::cin >> r >> c;
//         a[c] = r;
//     }
//     build(1, 1, n);
//     long long ans = 0;
//     for (int i = 1; i <= n; i++) {
//         int p = i;
//         while (top1 && a[i] < a[st1[top1]]) {
//             modify(1, st1[top1 - 1] + 1, p - 1, a[st1[top1]] - a[i]);
//             top1--;
//             p = st1[top1] + 1;
//         }
//         p = i;
//         while (top2 && a[i] > a[st2[top2]]) {
//             modify(1, st2[top2 - 1] + 1, p - 1, a[i] - a[st2[top2]]);
//             top2--;
//             p = st2[top2] + 1;
//         }
//         st1[++top1] = st2[++top2] = i;
//         ans += tr[1].cnt;
//     }
//     std::cout << ans << std::endl;
//     return 0;
// }

// 176. https://www.luogu.com.cn/problem/P1972
// #include <bits/stdc++.h>
// constexpr int N = 1e6 + 10;
//
// int tr[N], a[N];
//
// void add(int p, int val) {
//     for (int i = p; i < N; i += i & -i)
//         tr[i] += val;
// }
//
// int sum(int x) {
//     int res = 0;
//     for (int i = x; i; i -= i & -i)
//         res += tr[i];
//     return res;
// }
//
// signed main() {
//     std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
//     int n;
//     std::cin >> n;
//     for (int i = 1; i <= n; i++) std::cin >> a[i];
//     int q;
//     std::cin >> q;
//     std::vector<std::array<int, 3>> query(q);
//     for (int i = 0, l, r; i < q; i++) {
//         std::cin >> l >> r;
//         query[i] = {r, l, i};
//     }
//     std::vector<int> ans(q);
//     std::unordered_map<int, int> mp;
//     std::sort(query.begin(), query.end());
//     int st = 1;
//     for (const auto& [r, l, id] : query) {
//         for (int i = st; i <= r; i++, st++) {
//             if (mp.find(a[i]) != mp.end()) add(mp[a[i]], -1);
//             add(i, 1);
//             mp[a[i]] = i;
//         }
//         ans[id] = sum(r) - sum(l - 1);
//     }
//     for (int i = 0; i < q; i++) std::cout << ans[i] << std::endl;
//     return 0;
// }

// 177. https://www.luogu.com.cn/problem/P4113
// #include <bits/stdc++.h>
// constexpr int N = 2e6 + 10;
//
// int tr[N], a[N];
//
// void add(int p, int val) {
//     for (int i = p; i < N; i += i & -i)
//         tr[i] += val;
// }
//
// int sum(int p) {
//     int res = 0;
//     for (int i = p; i; i -= i & -i)
//         res += tr[i];
//     return res;
// }
//
// signed main() {
//     std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
//     int n, c, m;
//     std::cin >> n >> c >> m;
//     for (int i = 1; i <= n; i++) std::cin >> a[i];
//     std::vector<std::array<int, 3>> query(m);
//     for (int i = 0, l, r; i < m; i++) {
//         std::cin >> l >> r;
//         query[i] = {r, l, i};
//     }
//     std::sort(query.begin(), query.end());
//     std::unordered_map<int, std::vector<int>> mp;
//     std::vector<int> ans(m);
//
//     int st = 1;
//     for (const auto& [r, l, id] : query) {
//         for (int i = st; i <= r; i++, st++) {
//             if (mp.find(a[i]) != mp.end() && mp[a[i]].size() >= 2) {
//                 const unsigned int sz = mp[a[i]].size();
//                 add(mp[a[i]][sz - 2], -1);
//             }
//             mp[a[i]].emplace_back(i);
//             if (mp[a[i]].size() >= 2) add(mp[a[i]][mp[a[i]].size() - 2], 1);
//         }
//         ans[id] = sum(r) - sum(l - 1);
//     }
//     for (int i = 0; i < m; i++) std::cout << ans[i] << '\n';
//     return 0;
// }

// 完结啦孩子们，准备装到寒假专属代码文件中！












