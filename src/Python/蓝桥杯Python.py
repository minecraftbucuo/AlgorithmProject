# 2026.3.6 创建
# 1. https://codeforces.com/contest/2200/problem/A
# t = int(input())
# while t:
#     t -= 1
#     n = int(input())
#     a = list(map(int, input().split()))
#     mx = max(a)
#     cnt = 0
#     for i in a:
#         if i == mx:
#             cnt += 1
#     print(cnt)

# 2. https://codeforces.com/contest/2200/problem/B
# def is_sorted(aa):
#     for i in range(len(aa) - 1):
#         if aa[i] > aa[i + 1]:
#             return False
#     return True
#
# t = int(input())
# while t:
#     t -= 1
#     n = int(input())
#     a = list(map(int, input().split()))
#     if is_sorted(a):
#         print(len(a))
#     else:
#         print(1)

# 3. https://codeforces.com/contest/2200/problem/C
# t = int(input())
# while t:
#     t -= 1
#     n = int(input())
#     s = input()
#     st = list()
#     for i in s:
#         if len(st) == 0:
#             st.append(i)
#         else:
#             if st[-1] == i:
#                 st.pop()
#             else:
#                 st.append(i)
#     if len(st) == 0:
#         print("YES")
#     else:
#         print("NO")

# 4. https://codeforces.com/contest/2205/problem/A
# t = int(input())
#
# for _ in range(t):
#     n = int(input())
#     a = list(map(int, input().split()))
#     idx = 0
#     for i in range(n):
#         if a[i] == n:
#           idx = i
#           break
#     a[0], a[idx] = a[idx], a[0]
#     print(*a)

# 5. https://www.luogu.com.cn/problem/P12164
# h, w = map(int, input().split())
#
# a = list()
# b = list([2, 0, 2, 5])
#
# w_ = (w + 3) // 4 * 4
#
# b_i = 0
# for i in range(w_):
#     a.append(b[b_i])
#     b_i += 1
#     b_i %= len(b)
#
# for i in range(h):
#     for j in range(w):
#         print(a[(i + j) % len(a)], end="")
#     print("")

# 6. https://www.luogu.com.cn/problem/P12173
# s = input()
# st = {"lqb", "lbq", "qlb", "qbl", "blq", "bql"}
#
# ans = 0
# i = 0
#
# while i < len(s) - 2:
#     if s[i : i + 3] in st:
#         ans += 1
#         i += 3
#     else:
#         i += 1
#
# print(ans)

# 7. https://www.luogu.com.cn/problem/P12174
# l = int(input())
# fact = [0 for i in range(l + 1)]
# for i in range(1, l + 1):
#     for j in range(i, l + 1, i):
#         fact[j] += 1
#
# fact_ = fact[:]
# for i in range(1, l + 1):
#     fact_[i] += fact_[i - 1]
#
# ans = 0
# for i in range(1, l):
#     j = l - i
#     ans += fact[i] * fact_[j]
#
# print(ans)

# 8. https://www.luogu.com.cn/problem/P12177
# import copy
#
# n = int(input())
#
# a = [0] + list(map(int, input().split()))
#
# b = [[0 for __ in range(len(a))] for _ in range(21)]
#
# for i in range(1, n + 1):
#     for j in range(21):
#         b[j][i] = a[i] >> j & 1
#
# sum_ = copy.deepcopy(b)
# for i in range(21):
#     for j in range(1, n + 1):
#         sum_[i][j] += sum_[i][j - 1]
#
# ans = 0
# for i in range(2, n + 1):
#     for j in range(21):
#         if a[i] >> j & 1:
#             ans += i * ((i - 1 - sum_[j][i - 1]) << j)
#         else:
#             ans += i * (sum_[j][i - 1] << j)
#
# for i in range(n - 1, 0, -1):
#     for j in range(21):
#         b[j][i] += b[j][i + 1]
#         if a[i] >> j & 1:
#             ans -= i * ((n - i - b[j][i + 1]) << j)
#         else:
#             ans -= i * (b[j][i + 1] << j)
#
# print(ans)

# 9. https://www.luogu.com.cn/problem/P12874
# 超时搞不出来
# import sys
# sys.setrecursionlimit(100000)
#
# input = sys.stdin.readline
#
# n, k = map(int, input().split())
#
# class Node:
#     def __init__(self, v, w):
#         self.v = v
#         self.w = w
#
# g = [[] for _ in range(n + 1)]
#
# for _ in range(n - 1):
#     u, v, w = map(int, input().split())
#     g[u].append(Node(v, w))
#     g[v].append(Node(u, w))
#
# sum_ = 0
#
# vis = [False for _ in range(n + 1)]
#
# def dfs(st, cnt, w_):
#     global sum_
#     if cnt == k:
#         sum_ += w_
#         return
#     for i in g[st]:
#         if not vis[i.v]:
#             vis[i.v] = True
#             dfs(i.v, cnt + 1, i.w + w_)
#             vis[i.v] = False
#
# for i in range(1, n + 1):
#     vis[i] = True
#     dfs(i, 0, 0)
#     vis[i] = False
#
# print(sum_)

# 10. https://codeforces.com/contest/2205/problem/B
# t = int(input())
#
# for _ in range(t):
#     n = int(input())
#     mp = {}
#     t = 2
#     ans = 1
#     while t * t <= n:
#         if n % t == 0:
#             ans *= t
#             while n % t == 0:
#                 n //= t
#         t += 1
#     ans *= n
#     print(ans)

# 11. https://codeforces.com/contest/2205/problem/D
# 超时
# class Node:
#     def __init__(self, l, r, mx):
#         self.l = l
#         self.r = r
#         self.mx = mx
#
#     def set(self, l, r):
#         self.l = l
#         self.r = r
#
#     def set_max(self, mx):
#         self.mx = mx
#
# class SegTree:
#     def __init__(self, vec):
#         self.tr = [Node(0, 0, 0) for _ in range(len(vec) << 2)]
#         self.build(vec, 1, 1, len(vec) - 1)
#
#     def pushup(self, u):
#         self.tr[u].set_max(max(self.tr[u << 1].mx, self.tr[u << 1 | 1].mx))
#
#     def build(self, vec, u, l, r):
#         self.tr[u].set(l, r)
#         if l == r:
#             self.tr[u].set_max(vec[l])
#             return
#         mid = (l + r) // 2
#         self.build(vec, u << 1, l, mid)
#         self.build(vec, u << 1 | 1, mid + 1, r)
#         self.pushup(u)
#
#     def query(self, l, r):
#         return self.query_(1, l, r)
#
#     def query_(self, u, l, r):
#         if l <= self.tr[u].l and self.tr[u].r <= r:
#             return self.tr[u].mx
#         mid = (self.tr[u].l + self.tr[u].r) // 2
#         if r <= mid:
#             return self.query_(u << 1, l, r)
#         if l > mid:
#             return self.query_(u << 1 | 1, l, r)
#         return max(self.query_(u << 1, l, mid), self.query_(u << 1 | 1, mid + 1, r))
#
# def dfs(l, r, s):
#     global ans, segTree
#     if l + 1 == r:
#         ans = min(ans, s)
#         return
#     id_ = mp[segTree.query(l + 1, r - 1)]
#     if id_ == l + 1:
#         dfs(id_, r, s)
#     elif id_ == r - 1:
#         dfs(l, id_, s)
#     else:
#         dfs(l, id_, s + r - id_ - 1)
#         dfs(id_, r, s + id_ - l - 1)
#
#
# t = int(input())
#
# for _ in range(t):
#     n = int(input())
#     a = [0] + list(map(int, input().split()))
#     segTree = SegTree(a)
#     mp = {}
#     for i in range(1, len(a)):
#         mp[a[i]] = i
#     ans = 10 ** 9
#     dfs(0, n + 1, 0)
#     print(ans)

# 12. https://codeforces.com/contest/2207/problem/A
# t = int(input())
#
# for _ in range(t):
#     n = int(input())
#     s = " " + input()
#     s_c = list(s)
#     for i in range(2, n):
#         if s_c[i - 1] == '1' and s_c[i + 1] == '1':
#             s_c[i] = '1'
#     mx = s_c.count('1')
#     for i in range(2, n):
#         if s_c[i - 1] == '1' and s_c[i + 1] == '1':
#             s_c[i] = '0'
#     mi = s_c.count('1')
#
#     print(mi, mx, sep=' ')

# 13. https://codeforces.com/contest/2207/problem/B
# import heapq
# from collections import Counter
# import sys
#
# input = lambda: sys.stdin.readline().strip()
#
# class MultiSet:
#     """模拟multiset，可快速获取最小值、最大值，删除任意值。"""
#     def __init__(self):
#         self.min_heap = []  # 最小堆
#         self.max_heap = []  # 最大堆（存负数）
#         self.min_pending = Counter()  # 最小堆中待删除的元素
#         self.max_pending = Counter()  # 最大堆中待删除的元素（存负数的计数）
#         self.mp = Counter()
#         self._size = 0
#
#     def insert(self, x):
#         heapq.heappush(self.min_heap, x)
#         heapq.heappush(self.max_heap, -x)
#         self.mp[x] += 1
#         self._size += 1
#
#     def erase(self, x):
#         if self._size <= 0:
#             return
#         if self.mp[x] == 0:
#             return
#         self.min_pending[x] += 1
#         self.max_pending[-x] += 1
#         self.mp[x] -= 1
#         self._size -= 1
#         self._clean()
#
#     def get_min(self):
#         self._clean()
#         return self.min_heap[0] if self.min_heap else None
#
#     def get_max(self):
#         self._clean()
#         return -self.max_heap[0] if self.max_heap else None
#
#     def _clean(self):
#         # 清理两个堆顶的无效元素
#         while self.min_heap and self.min_pending[self.min_heap[0]] > 0:
#             self.min_pending[self.min_heap[0]] -= 1
#             heapq.heappop(self.min_heap)
#         while self.max_heap and self.max_pending[self.max_heap[0]] > 0:
#             self.max_pending[self.max_heap[0]] -= 1
#             heapq.heappop(self.max_heap)
#
#     def __len__(self):
#         return self._size
#
# t = int(input())
#
# ans = []
#
# for _ in range(t):
#     n, m, l = map(int, input().split())
#     a = [0] + list(map(int, input().split()))
#     t = 1
#     s = MultiSet()
#     for i in range(1, n + 1):
#         while len(s) > n - i + 2: s.erase(s.get_min())
#         while t <= a[i]:
#             t += 1
#             if len(s) < n - i + 2 and len(s) < m:
#                 s.insert(1)
#             else:
#                 s.insert(s.get_min() + 1)
#                 s.erase(s.get_min())
#         s.erase(s.get_max())
#         s.insert(0)
#
#     mx = s.get_max() + l - a[n]
#     ans.append(mx)
#
# print('\n'.join(map(str, ans)))

# 14. https://codeforces.com/contest/2197/problem/A
# t = int(input())
#
# def dig(x):
#     x = str(x)
#     res = 0
#     for i in x:
#         res += int(i)
#     return res
#
# ans_ = []
#
# for _ in range(t):
#     n = int(input())
#     ans = 0
#     for i in range(n + 1, n + 100):
#         if i - dig(i) == n:
#            ans += 1
#
#     ans_.append(ans)
#
# print('\n'.join(map(str, ans_)))

# 15. https://www.luogu.com.cn/problem/B2064
# import sys
# from functools import cache
# sys.setrecursionlimit(1 << 30)
#
# input = lambda : sys.stdin.readline().strip()
#
# t = int(input())
# res = []
#
# @cache
# def get_ans(n):
#     if n == 1 or n == 2:
#         return 1
#     return get_ans(n - 1) + get_ans(n - 2)
#
# for _ in range(t):
#     n = int(input())
#     res.append(get_ans(n))
#
# print('\n'.join(map(str, res)))

# 16. https://www.luogu.com.cn/problem/P3374   树状数组模版
# import sys
#
# class BIT:
#     __slots__ = ("n", "tr")
#     def __init__(self, nums : list):
#         self.n = len(nums)
#         self.tr = [0] * self.n
#         for i in range(1, self.n):
#             self.add(i, nums[i])
#
#     def add(self, idx : int, x_ : int) -> None:
#         while idx < self.n:
#             self.tr[idx] += x_
#             idx += idx & -idx
#
#     def query(self, l : int, r : int) -> int:
#         return self._sum(r) - self._sum(l - 1)
#
#     def _sum(self, idx : int) -> int:
#         res_ = 0
#         while idx != 0:
#             res_ += self.tr[idx]
#             idx -= idx & -idx
#         return res_
#
# input = lambda : sys.stdin.readline().strip()
#
# n, m = map(int, input().split())
# a = [0] + list(map(int, input().split()))
#
# bit = BIT(a)
#
# res = []
#
# for _ in range(m):
#     op, x, y = map(int, input().split())
#     if op == 1:
#         bit.add(x, y)
#     else:
#         res.append(bit.query(x, y))
#
# print("\n".join(map(str, res)))

# 17. https://www.luogu.com.cn/problem/P9231
# import sys
#
# input = lambda : sys.stdin.readline().strip()
#
# l, r = map(int, input().split())
#
# def calc(x):
#     return (x + 1) // 2 + x // 4
#
# print(calc(r) - calc(l - 1))

# 18. https://www.luogu.com.cn/problem/P9232
# import sys
#
# input = lambda : sys.stdin.readline().strip()
#
# s = input()
#
# n = len(s)
#
# s = " " + s
#
# dp = [[0 for _ in range(n + 1)] for _ in range(n + 1)]
#
# for i in range(1, n):
#     dp[i][i + 1] = 1 if s[i] > s[i + 1] else 0
#
# for l in range(3, n + 1):
#     for i in range(1, n - l + 2):
#         j = i + l - 1
#         dp[i][j] = 1 if s[i] > s[j] else (dp[i + 1][j - 1] if s[i] == s[j] else 0)
#
# ans = 0
#
# for i in range(1, n + 1):
#     for j in range(i + 1, n + 1):
#         ans += dp[i][j]
#
# print(ans)

# 19. https://www.luogu.com.cn/problem/P9236
import sys

input = lambda : sys.stdin.readline().strip()

n = int(input())

a = [0] + list(map(int, input().split()))

ans = 0

for i in range(0, 21):
    gong = 1 << i
    b = [0 for _ in range(n + 1)]
    cnt = [1, 0]
    for j in range(1, n + 1):
        b[j] = b[j - 1] ^ (a[j] >> i & 1)
        ans += cnt[b[j] ^ 1] * gong
        cnt[b[j]] += 1

print(ans)





