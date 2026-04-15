//
// Created by MINEC on 2025/10/30.
//


// A
//#include <bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 10;
//
//signed main() {
//    int n;
//    cin >> n;
//    vector<int> a(n), dp(N);
//    int ans = 0;
//    for (int i = 0; i < n; i++) {
//        cin >> a[i];
//        int x = a[i];
//        int t = 1;
//        for (int d = 1; d * d <= x; d++) {
//            if (x % d == 0) {
//                t = max(t, dp[d] + 1);
//                if (d != x / d) {
//                    t = max(t, dp[x / d] + 1);
//                }
//            }
//        }
//        dp[x] = max(dp[x], t);
//        ans = max(ans, t);
//    }
//    cout << ans << endl;
//    return 0;
//}


// B
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int n;
//    cin >> n;
//    vector<int> a(n + 1), b(n + 1);
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    for (int i = 1; i <= n; i++) cin >> b[i];
//    unordered_map<int, int> mp;
//    mp[0] = 1;
//    for (int i = 1; i <= n; i++) {
//        a[i] ^= a[i - 1];
//        if (mp[a[i] ^ b[i]]) cout << 1 << ' ';
//        else cout << 0 << ' ';
//        mp[a[i]] = 1;
//    }
//    return 0;
//}


// C
//#include <bits/stdc++.h>
//using namespace std;
//
//int dx[] = {1, -1, 0, 0};
//int dy[] = {0, 0, 1, -1};
//
//signed main() {
//    int n;
//    cin >> n;
//    cin.ignore();
//    vector<string> a(n + 1);
//    for (int i = 1; i <= n; i++) {
//        getline(cin, a[i]);
//        a[i] = " " + a[i];
//    }
//    vector<vector<pair<int, int>>> pre(n + 1, vector<pair<int, int>>(n + 1));
//    vector<vector<int>> vis(n + 1, vector<int>(n + 1));
//    queue<pair<int, int>> q;
//    q.emplace(2, 2);
//    vis[2][2] = 1;
//    while (!q.empty()) {
//        auto [x, y] = q.front();
//        q.pop();
//        for (int i = 0; i < 4; i++) {
//            int xx = x + dx[i];
//            int yy = y + dy[i];
//            if (1 <= xx && xx <= n && 1 <= yy && yy <= n && !vis[xx][yy] && a[xx][yy] != '#') {
//                q.emplace(xx, yy);
//                pre[xx][yy] = {x, y};
//                vis[xx][yy] = 1;
//            }
//        }
//    }
//    auto [x, y] = pre[n - 1][n - 1];
//    while (x != 2 || y != 2) {
//        a[x][y] = '*';
//        int x_ = x;
//        x = pre[x][y].first;
//        y = pre[x_][y].second;
//    }
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= n; j++)
//            cout << a[i][j];
//        cout << endl;
//    }
//    return 0;
//}


// D
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//signed main() {
//    int n, k;
//    cin >> n >> k;
//    vector<int> a(n + 1);
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    sort(a.begin() + 1, a.end());
//    int l = 1, r = 1e12;
//    int t = (n + 1) / 2;
//    auto check = [&](int mid) -> bool {
//        int sum = 0;
//        for (int i = t; i <= n; i++) {
//            if (a[i] < mid) sum += mid - a[i];
//            else break;
//        }
//        return sum <= k;
//    };
//    while (l <= r) {
//        int mid = (l + r) >> 1;
//        if (check(mid)) l = mid + 1;
//        else r = mid - 1;
//    }
//    cout << l - 1 << endl;
//    return 0;
//}


// E
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//int ksm(int a, int k, int mod) {
//    int res = 1;
//    a %= mod;
//    while (k) {
//        if (k & 1) res = a * res % mod;
//        a = a * a % mod;
//        k >>= 1;
//    }
//    return res;
//}
//
//int calc(int x, int n, int mod) {
//    int len = 0;
//    int x_ = x;
//    while (x_) len++, x_ /= 10;
//    int res = 0;
//    int cur_len = 0;
//    stack<int> st;
//    while (n) {
//        st.push(n & 1);
//        n >>= 1;
//    }
//    while (!st.empty()) {
//        int t = st.top();
//        st.pop();
//        res = (res * ksm(10, cur_len, mod) % mod + res % mod) % mod;
//        cur_len += cur_len;
//        if (t) {
//            res = (res * ksm(10, len, mod) % mod + x % mod) % mod;
//            cur_len += len;
//        }
//    }
//    return res;
//}
//
//signed main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        int x, n, mod;
//        cin >> x >> n >> mod;
//        if (calc(x, n, mod)) cout << "No" << endl;
//        else cout << "Yes" << endl;
//    }
//    return 0;
//}


// F
//#include <bits/stdc++.h>
//using namespace std;
//const int N = 2e5 + 10;
//
//struct node {
//    int l, r, mx;
//} tr[N << 2];
//
//void build(int u, int l, int r) {
//    tr[u] = {l, r, 0};
//    if (l == r) return;
//    int mid = (l + r) >> 1;
//    build(u << 1, l, mid);
//    build(u << 1 | 1, mid + 1, r);
//}
//
//int query(int u, int l, int r) {
//    if (l > r) return 0;
//    if (l <= tr[u].l && tr[u].r <= r) return tr[u].mx;
//    int mid = (tr[u].l + tr[u].r) >> 1;
//    if (r <= mid) return query(u << 1, l, r);
//    else if (l > mid) return query(u << 1 | 1, l, r);
//    else return max(query(u << 1, l, mid), query(u << 1 | 1, mid + 1, r));
//}
//
//void modify(int u, int p, int x) {
//    if (tr[u].l == tr[u].r) tr[u].mx = max(tr[u].mx, x);
//    else {
//        int mid = (tr[u].l + tr[u].r) >> 1;
//        if (p <= mid) modify(u << 1, p, x);
//        else modify(u << 1 | 1, p, x);
//        tr[u].mx = max(tr[u << 1].mx, tr[u << 1 | 1].mx);
//    }
//}
//
//struct SparseTable {
//    vector<vector<int>> st;
//    vector<int> log_table;
//
//    void build(vector<int>& arr) {
//        int n = arr.size();
//        log_table.resize(n + 1);
//        log_table[1] = 0;
//        for (int i = 2; i <= n; i++) {
//            log_table[i] = log_table[i / 2] + 1;
//        }
//        int k = log_table[n] + 1;
//        st.resize(n, vector<int>(k));
//        for (int i = 0; i < n; i++) {
//            st[i][0] = arr[i];
//        }
//        for (int j = 1; j < k; j++) {
//            for (int i = 0; i + (1 << j) <= n; i++) {
//                st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
//            }
//        }
//    }
//
//    int query(int l, int r) { // 查询 [l, r] 闭区间最大值
//        int j = log_table[r - l + 1];
//        return max(st[l][j], st[r - (1 << j) + 1][j]);
//    }
//};
//
//signed main() {
//    int n, q;
//    cin >> n >> q;
//    vector<int> a(n + 1);
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    vector<int> b = a;
//    sort(b.begin() + 1, b.end());
//    b.erase(unique(b.begin() + 1, b.end()), b.end());
//    build(1, 1, b.size() + 1);
//    vector<int> id(n + 1);
//    for (int i = 1; i <= n; i++) id[i] = lower_bound(b.begin() + 1, b.end(), a[i]) - b.begin();
//    vector<int> pre(n + 1);
//    stack<int> st;
//    st.push(0);
//    for (int i = 1; i <= n; i++) {
//        while (a[st.top()] >= a[i]) st.pop();
//        pre[i] = st.top();
//        st.push(i);
//    }
//    vector<int> mx(n + 1);
//    for (int i = 1; i <= n; i++) {
//        mx[i] = query(1, 1, id[i] - 1);
//        modify(1, id[i], pre[i]);
//    }
//    SparseTable spt;
//    spt.build(mx);
//    while (q--) {
//        int l, r;
//        cin >> l >> r;
//        if (spt.query(l, r) >= l) cout << "Yes" << endl;
//        else cout << "No" << endl;
//    }
//    return 0;
//}

// F 加强
//#include <bits/stdc++.h>
//#define endl '\n'
//
//signed main() {
//    std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
//    int n, q;
//    std::cin >> n >> q;
//    std::vector<int> a(n + 2);
//    for (int i = 1; i <= n; i++) std::cin >> a[i];
//    a[n + 1] = 2e9;
//    std::stack<int> st;
//    st.push(0);
//    std::vector<int> pre(n + 1), en(n + 2), mx(n + 1);
//    for (int i = 1; i <= n; i++) {
//        while (a[st.top()] >= a[i]) st.pop();
//        pre[i] = st.top();
//        st.push(i);
//    }
//    while (!st.empty()) st.pop();
//    st.push(n + 1);
//    for (int i = n; i >= 1; i--) {
//        while (a[st.top()] <= a[i]) st.pop();
//        en[i] = st.top();
//        st.push(i);
//    }
//    for (int i = 1; i <= n; i++) mx[en[i]] = std::max(mx[en[i]], pre[i]);
//    for (int i = 1; i <= n; i++) mx[i] = std::max(mx[i], mx[i - 1]);
//
//    while (q--) {
//        int l, r;
//        std::cin >> l >> r;
//        if (l <= mx[r]) std::cout << "Yes" << endl;
//        else std::cout << "No" << endl;
//    }
//    return 0;
//}
