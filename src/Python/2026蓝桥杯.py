# 1. https://www.luogu.com.cn/problem/P16261
# mxa = 20269876543210
# mxb = 20260123456789
# mod = 998244353
#
# ans = 0
# i = 0
#
# while True:
#     x = i * i
#     if x > mxa + mxb:
#         break
#     maxa = min(x, mxa)
#     mina = max(0, x - mxb)
#     ans += maxa - mina + 1
#     ans %= mod
#     i += 1
#
# print(ans)

# 2. https://www.luogu.com.cn/problem/P16262
# import sys
#
# from math import isqrt
#
# input = lambda : sys.stdin.readline().strip()
#
# def is_prime(x):
#     if x == 1 or x == 2:
#         return True
#     for i in range(2, isqrt(x) + 1):
#         if x % i == 0:
#             return False
#     return True
#
# T = int(input())
# ans = []
#
# for _ in range(T):
#     x = int(input())
#     if not is_prime(x):
#         ans.append(x)
#     else:
#         ans.append(max(4, (x + 1) // 2 * 2))
#
# print('\n'.join(map(str, ans)))

# 3. https://www.luogu.com.cn/problem/P16264
# import sys
#
# input = lambda : sys.stdin.readline().strip()
#
# T = int(input())
# ans = []
#
# for _ in range(T):
#     n = int(input())
#     a = list(map(int, input().split()))
#     cnt = 0
#     for i in a:
#         if i == 1:
#             cnt += 1
#             cnt %= 2
#     if cnt == 0:
#         ans.append('Q')
#     else:
#         ans.append('L')
#
# print('\n'.join(ans))

# 4. https://www.luogu.com.cn/problem/P16265
# import sys
#
# input = lambda : sys.stdin.readline().strip()
#
# ans = []
#
# n, q = list(map(int, input().split()))
#
# fa = [i for i in range(n + 1)]
# huo = [0 for i in range(n + 1)]
# fa_huo = [0 for i in range(n + 1)]
# siz = [1 for i in range(n + 1)]
# ren = [[i] for i in range(n + 1)]
#
# def find(x):
#     if x != fa[x]:
#         fa[x] = find(fa[x])
#     return fa[x]
#
# def merge(x, y):
#     fax = find(x)
#     fay = find(y)
#     if fax == fay:
#         return
#     if siz[fax] < siz[fay]:
#         fax, fay = fay, fax
#     for i in ren[fay]:
#         ren[fax].append(i)
#         huo[i] = huo[i] + fa_huo[fay] - fa_huo[fax]
#     siz[fax] += siz[fay]
#     fa[fay] = fax
#
# for _ in range(q):
#     a = list(map(int, input().split()))
#     if a[0] == 1:
#         merge(a[1], a[2])
#     elif a[0] == 2:
#         huo[a[1]] += a[2]
#     elif a[0] == 3:
#         fa_huo[find(a[1])] += a[2]
#     else:
#         ans.append(huo[a[1]] + fa_huo[find(a[1])])
#
# print('\n'.join(map(str, ans)))

# 5. https://www.luogu.com.cn/problem/P16266
# import sys
#
# mod = 10 ** 9 + 7
#
# input = lambda : sys.stdin.readline().strip()
#
# n, k = list(map(int, input().split()))
#
# dp = [[[0 for _ in range(k + 1)] for __ in range(n + 1)] for ___ in range(2)]
#
# dp[0][0][0] = 1
#
# for i in range(1, n + 1):
#     i_ = i % 2
#     i__ = (i - 1) % 2
#
#     # 1. 必须先清空当前轮次的滚动数组
#     for j in range(i + 1):
#         for k_ in range(k):
#             dp[i_][j][k_] = 0
#
#     # 2. 状态转移
#     for j in range(i):  # j 是上一位的连续1长度
#         for k_ in range(k):
#             if dp[i__][j][k_] == 0: continue
#
#             # 操作 A：当前位填 '0'
#             # 连续 1 的长度断掉，变成 0，共鸣数 k_ 不变
#             dp[i_][0][k_] = (dp[i_][0][k_] + dp[i__][j][k_]) % mod
#
#             # 操作 B：当前位填 '1'
#             # 连续 1 的长度变成 j+1，共鸣数增加 j+1
#             nxt_k = k_ + j + 1
#             if nxt_k < k:  # 我们只关心共鸣数 < k 的情况
#                 dp[i_][j + 1][nxt_k] = (dp[i_][j + 1][nxt_k] + dp[i__][j][k_]) % mod
#
# ans = 1
# for i in range(n):
#     ans = ans * 2 % mod
#
# t = n % 2
#
# su = 0
# for i in range(n + 1):
#     for j in range(k):
#         su = (su + dp[t][i][j]) % mod
#
# ans = ((ans - su) % mod + mod) % mod
#
# print(ans)

















