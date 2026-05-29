# 1. https://www.luogu.com.cn/problem/CF27D
# import sys
#
# input = lambda : sys.stdin.readline().strip()
#
# n, m = map(int, input().split())
#
# a = []
#
# for _ in range(m):
#     u, v = map(int, input().split())
#     if u > v:
#         u, v = v, u
#     a.append((u, v))
#
# g = [[] for _ in range(m)]
#
# for i in range(m):
#     for j in range(i + 1, m):
#         u1, v1 = a[i]
#         u2, v2 = a[j]
#         if u1 < u2 < v1 < v2 or u2 < u1 < v2 < v1:
#             g[i].append(j)
#             g[j].append(i)
#
# c = [-1 for _ in range(m)]
#
# def dfs(u_, x):
#     c[u_] = x
#     for i_ in g[u_]:
#         if c[i_] == -1:
#             if not dfs(i_, x ^ 1):
#                 return False
#         elif c[i_] == c[u_]:
#             return False
#     return True
#
# have_ans = True
#
# for i in range(m):
#     if c[i] == -1:
#         if not dfs(i, 0):
#             have_ans = False
#             break
#
# ans = []
# if have_ans:
#     for i in range(m):
#         if c[i] == 0:
#             ans.append('o')
#         else:
#             ans.append('i')
#     print(''.join(ans))
# else:
#     print("Impossible")
