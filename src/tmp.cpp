//
// Created by MINEC on 2026/3/28.
//

// k大数查询，C++版
// 初始时有n个空集合，编号1~n，实现如下两种类型的操作，操作一共发生m次
// 操作 1 l r v : 数字v放入编号范围[l,r]的每一个集合中
// 操作 2 l r k : 编号范围[l,r]的所有集合，如果生成不去重的并集，返回第k大的数字
// 1 <= n、m <= 5 * 10^4
// -n <= v <= +n
// 1 <= k < 2^63，题目保证第k大的数字一定存在
// 测试链接 : https://www.luogu.com.cn/problem/P3332
// 如下实现是C++的版本，C++版本和java版本逻辑完全一样
// 提交如下代码，可以通过所有测试用例

// #include <bits/stdc++.h>
//
// using namespace std;
//
// const int MAXM = 50001;
// const int MAXT = MAXM * 230;
// int n, m, s;
// int ques[MAXM][4];
// int sorted[MAXM];
// int root[MAXM << 2];
// int ls[MAXT];
// int rs[MAXT];
// long long sum[MAXT];
// int lazy[MAXT];
// int cnt;
//
// int kth(int num) {
//     int l = 1, r = s;
//     while (l <= r) {
//         int mid = (l + r) >> 1;
//         if (sorted[mid] == num) {
//             return mid;
//         } else if (sorted[mid] < num) {
//             l = mid + 1;
//         } else {
//             r = mid - 1;
//         }
//     }
//     return -1;
// }
//
// void up(int i) {
//     sum[i] = sum[ls[i]] + sum[rs[i]];
// }
//
// void down(int i, int ln, int rn) {
//     if (lazy[i]) {
//         if (!ls[i]) ls[i] = ++cnt;
//         if (!rs[i]) rs[i] = ++cnt;
//         sum[ls[i]] += 1LL * lazy[i] * ln;
//         lazy[ls[i]] += lazy[i];
//         sum[rs[i]] += 1LL * lazy[i] * rn;
//         lazy[rs[i]] += lazy[i];
//         lazy[i] = 0;
//     }
// }
//
// int innerAdd(int jobl, int jobr, int l, int r, int i) {
//     if (!i) i = ++cnt;
//     if (jobl <= l && r <= jobr) {
//         sum[i] += (long long)(r - l + 1);
//         lazy[i]++;
//     } else {
//         int mid = (l + r) >> 1;
//         down(i, mid - l + 1, r - mid);
//         if (jobl <= mid) ls[i] = innerAdd(jobl, jobr, l, mid, ls[i]);
//         if (jobr > mid) rs[i] = innerAdd(jobl, jobr, mid + 1, r, rs[i]);
//         up(i);
//     }
//     return i;
// }
//
// long long innerQuery(int jobl, int jobr, int l, int r, int i) {
//     if (!i) return 0;
//     if (jobl <= l && r <= jobr) {
//         return sum[i];
//     }
//     int mid = (l + r) >> 1;
//     down(i, mid - l + 1, r - mid);
//     long long ans = 0;
//     if (jobl <= mid) ans += innerQuery(jobl, jobr, l, mid, ls[i]);
//     if (jobr > mid) ans += innerQuery(jobl, jobr, mid + 1, r, rs[i]);
//     return ans;
// }
//
// void outerAdd(int jobl, int jobr, int jobv, int l, int r, int i) {
//     root[i] = innerAdd(jobl, jobr, 1, n, root[i]);
//     if (l < r) {
//         int mid = (l + r) >> 1;
//         if (jobv <= mid) {
//             outerAdd(jobl, jobr, jobv, l, mid, i << 1);
//         } else {
//             outerAdd(jobl, jobr, jobv, mid + 1, r, i << 1 | 1);
//         }
//     }
// }
//
// int outerQuery(int jobl, int jobr, long long jobk, int l, int r, int i) {
//     if (l == r) {
//         return l;
//     }
//     int mid = (l + r) >> 1;
//     long long rightsum = innerQuery(jobl, jobr, 1, n, root[i << 1 | 1]);
//     if (jobk > rightsum) {
//         return outerQuery(jobl, jobr, jobk - rightsum, l, mid, i << 1);
//     } else {
//         return outerQuery(jobl, jobr, jobk, mid + 1, r, i << 1 | 1);
//     }
// }
//
// void prepare() {
//     s = 0;
//     for (int i = 1; i <= m; i++) {
//         if (ques[i][0] == 1) {
//             sorted[++s] = ques[i][3];
//         }
//     }
//     sort(sorted + 1, sorted + s + 1);
//     int len = 1;
//     for (int i = 2; i <= s; i++) {
//         if (sorted[len] != sorted[i]) {
//             sorted[++len] = sorted[i];
//         }
//     }
//     s = len;
//     for (int i = 1; i <= m; i++) {
//         if (ques[i][0] == 1) {
//             ques[i][3] = kth(ques[i][3]);
//         }
//     }
// }
//
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cin >> n >> m;
//     for (int i = 1; i <= m; i++) {
//         cin >> ques[i][0] >> ques[i][1] >> ques[i][2] >> ques[i][3];
//     }
//     prepare();
//     for (int i = 1; i <= m; i++) {
//         if (ques[i][0] == 1) {
//             outerAdd(ques[i][1], ques[i][2], ques[i][3], 1, s, 1);
//         } else {
//             int idx = outerQuery(ques[i][1], ques[i][2], ques[i][3], 1, s, 1);
//             cout << sorted[idx] << "\n";
//         }
//     }
//     return 0;
// }

// 替罪羊树的实现(C++版)
// 实现一种结构，支持如下操作，要求单次调用的时间复杂度O(log n)
// 1，增加x，重复加入算多个词频
// 2，删除x，如果有多个，只删掉一个
// 3，查询x的排名，x的排名为，比x小的数的个数+1
// 4，查询数据中排名为x的数
// 5，查询x的前驱，x的前驱为，小于x的数中最大的数，不存在返回整数最小值
// 6，查询x的后继，x的后继为，大于x的数中最小的数，不存在返回整数最大值
// 所有操作的次数 <= 10^5
// -10^7 <= x <= +10^7
// 测试链接 : https://www.luogu.com.cn/problem/P3369
// 如下实现是C++的版本，C++版本和java版本逻辑完全一样
// 提交如下代码，可以通过所有测试用例

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <cmath>
// #include <climits>
// #include <cstring>
//
// using namespace std;
//
// const double ALPHA = 0.7;
// const int MAXN = 100001;
// int head = 0;
// int cnt = 0;
// int key[MAXN];
// int key_count[MAXN];
// int ls[MAXN];
// int rs[MAXN];
// int siz[MAXN];
// int diff[MAXN];
// int collect[MAXN];
// int ci;
// int top;
// int father;
// int side;
//
// int init(int num) {
//     key[++cnt] = num;
//     ls[cnt] = rs[cnt] = 0;
//     key_count[cnt] = siz[cnt] = diff[cnt] = 1;
//     return cnt;
// }
//
// void up(int i) {
//     siz[i] = siz[ls[i]] + siz[rs[i]] + key_count[i];
//     diff[i] = diff[ls[i]] + diff[rs[i]] + (key_count[i] > 0 ? 1 : 0);
// }
//
// void inorder(int i) {
//     if (i != 0) {
//         inorder(ls[i]);
//         if (key_count[i] > 0) {
//             collect[++ci] = i;
//         }
//         inorder(rs[i]);
//     }
// }
//
// int build(int l, int r) {
//     if (l > r) {
//         return 0;
//     }
//     int m = (l + r) / 2;
//     int h = collect[m];
//     ls[h] = build(l, m - 1);
//     rs[h] = build(m + 1, r);
//     up(h);
//     return h;
// }
//
// void rebuild() {
//     if (top != 0) {
//         ci = 0;
//         inorder(top);
//         if (ci > 0) {
//             if (father == 0) {
//                 head = build(1, ci);
//             } else if (side == 1) {
//                 ls[father] = build(1, ci);
//             } else {
//                 rs[father] = build(1, ci);
//             }
//         }
//     }
// }
//
// bool balance(int i) {
//     return ALPHA * diff[i] >= max(diff[ls[i]], diff[rs[i]]);
// }
//
// void add(int i, int f, int s, int num) {
//     if (i == 0) {
//         if (f == 0) {
//             head = init(num);
//         } else if (s == 1) {
//             ls[f] = init(num);
//         } else {
//             rs[f] = init(num);
//         }
//     } else {
//         if (key[i] == num) {
//             key_count[i]++;
//         } else if (key[i] > num) {
//             add(ls[i], i, 1, num);
//         } else {
//             add(rs[i], i, 2, num);
//         }
//         up(i);
//         if (!balance(i)) {
//             top = i;
//             father = f;
//             side = s;
//         }
//     }
// }
//
// void add(int num) {
//     top = father = side = 0;
//     add(head, 0, 0, num);
//     rebuild();
// }
//
// int small(int i, int num) {
//     if (i == 0) {
//         return 0;
//     }
//     if (key[i] >= num) {
//         return small(ls[i], num);
//     } else {
//         return siz[ls[i]] + key_count[i] + small(rs[i], num);
//     }
// }
//
// int getRank(int num) {
//     return small(head, num) + 1;
// }
//
// int index(int i, int x) {
//     if (siz[ls[i]] >= x) {
//         return index(ls[i], x);
//     } else if (siz[ls[i]] + key_count[i] < x) {
//         return index(rs[i], x - siz[ls[i]] - key_count[i]);
//     }
//     return key[i];
// }
//
// int index(int x) {
//     return index(head, x);
// }
//
// int pre(int num) {
//     int kth = getRank(num);
//     if (kth == 1) {
//         return INT_MIN;
//     } else {
//         return index(kth - 1);
//     }
// }
//
// int post(int num) {
//     int kth = getRank(num + 1);
//     if (kth == siz[head] + 1) {
//         return INT_MAX;
//     } else {
//         return index(kth);
//     }
// }
//
// void remove(int i, int f, int s, int num) {
//     if (key[i] == num) {
//         key_count[i]--;
//     } else if (key[i] > num) {
//         remove(ls[i], i, 1, num);
//     } else {
//         remove(rs[i], i, 2, num);
//     }
//     up(i);
//     if (!balance(i)) {
//         top = i;
//         father = f;
//         side = s;
//     }
// }
//
// void remove(int num) {
//     if (getRank(num) != getRank(num + 1)) {
//         top = father = side = 0;
//         remove(head, 0, 0, num);
//         rebuild();
//     }
// }
//
// void clear() {
//     memset(key, 0, sizeof(key));
//     memset(key_count, 0, sizeof(key_count));
//     memset(ls, 0, sizeof(ls));
//     memset(rs, 0, sizeof(rs));
//     memset(siz, 0, sizeof(siz));
//     memset(diff, 0, sizeof(diff));
//     cnt = 0;
//     head = 0;
// }
//
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n;
//     cin >> n;
//     for (int i = 1; i <= n; i++) {
//         int op, x;
//         cin >> op >> x;
//         if (op == 1) {
//             add(x);
//         } else if (op == 2) {
//             remove(x);
//         } else if (op == 3) {
//             cout << getRank(x) << "\n";
//         } else if (op == 4) {
//             cout << index(x) << "\n";
//         } else if (op == 5) {
//             cout << pre(x) << "\n";
//         } else {
//             cout << post(x) << "\n";
//         }
//     }
//     clear();
//     return 0;
// }

// 2026西安邀请赛 C AI
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;
// 由于N<=5000，使用 short 以减少内存占用 (5000*5000*2 bytes ≈ 50MB)
short memo[5005][5005];

// 预处理数组：记录指定要求的最早/最晚块的边界位置
int L1[5005], L2[5005], R1[5005], R2[5005];
int nxt[5005][2], prv[5005][2];

int solve_dp(int l, int r) {
    if (l > r) return 0;
    if (memo[l][r] != -1) return memo[l][r];

    int ans = 0;

    // 尝试策略 1：左侧匹配 ()，右侧匹配 )(
    int p2 = L1[l];
    int q2 = R1[r];
    if (p2 != INF && q2 != -INF && p2 < q2) {
        ans = max(ans, 4 + solve_dp(p2 + 1, q2 - 1));
    }

    // 尝试策略 2：左侧匹配 )(，右侧匹配 ()
    p2 = L2[l];
    q2 = R2[r];
    if (p2 != INF && q2 != -INF && p2 < q2) {
        ans = max(ans, 4 + solve_dp(p2 + 1, q2 - 1));
    }

    return memo[l][r] = ans;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // 转换为 1-based index 方便处理
    string S = " " + s;

    // 预处理 nxt 数组 (找寻其后的第一个 '(' 或 ')')
    nxt[n + 1][0] = nxt[n + 1][1] = INF;
    for (int i = n; i >= 1; i--) {
        nxt[i][0] = nxt[i + 1][0];
        nxt[i][1] = nxt[i + 1][1];
        if (S[i] == '(') nxt[i][0] = i;
        else nxt[i][1] = i;
    }

    // 预处理 prv 数组 (找寻其前的第一个 '(' 或 ')')
    prv[0][0] = prv[0][1] = -INF;
    for (int i = 1; i <= n; i++) {
        prv[i][0] = prv[i - 1][0];
        prv[i][1] = prv[i - 1][1];
        if (S[i] == '(') prv[i][0] = i;
        else prv[i][1] = i;
    }

    // 预处理4种关键 Block 的边界
    for (int i = 1; i <= n; i++) {
        // L1[i]: >= i 的最早的 () 的结束位置
        L1[i] = INF;
        int p1 = nxt[i][0];
        if (p1 != INF) L1[i] = nxt[p1 + 1][1];

        // L2[i]: >= i 的最早的 )( 的结束位置
        L2[i] = INF;
        p1 = nxt[i][1];
        if (p1 != INF) L2[i] = nxt[p1 + 1][0];

        // R1[i]: <= i 的最晚的 )( 的起始位置
        R1[i] = -INF;
        int q1 = prv[i][0];
        if (q1 != -INF) R1[i] = prv[q1 - 1][1];

        // R2[i]: <= i 的最晚的 () 的起始位置
        R2[i] = -INF;
        q1 = prv[i][1];
        if (q1 != -INF) R2[i] = prv[q1 - 1][0];
    }

    // O(N^2) 初始化当前测试用例的 DP 记忆化数组
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            memo[i][j] = -1;
        }
    }

    // 寻找最外层的 '(' 和 ')'
    int first_open = nxt[1][0];
    int last_close = prv[n][1];

    if (first_open != INF && last_close != -INF && first_open < last_close) {
        // 长度为 最外层2个字符 + 内部最多能匹配出的 H+H^R 长度
        cout << 2 + solve_dp(first_open + 1, last_close - 1) << "\n";
    } else {
        // 无法构造出有效的包含括号的 PBBS，退化为空串
        cout << 0 << "\n";
    }
}

int main() {
    // 解除与 C 标准 I/O 的同步，提高执行速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
