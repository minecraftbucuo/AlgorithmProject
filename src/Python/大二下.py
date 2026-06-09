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

# 2. https://www.luogu.com.cn/problem/CF27A
# import sys
#
# input = lambda : sys.stdin.readline().strip()
#
# n = int(input())
#
# a = list(map(int, input().split()))
#
# vis = [False for _ in range(3002)]
#
# for i in a:
#     vis[i] = True
#
# i = 1
# while vis[i]:
#     i += 1
# print(i)

# 3. https://www.luogu.com.cn/problem/CF27B
# import sys
# from collections import deque
#
# input = lambda : sys.stdin.readline().strip()
#
# n = int(input())
#
# g = [[] for _ in range(n + 1)]
#
# du = [0 for _ in range(n + 1)]
#
# vis = [[False for _ in range(n + 1)] for __ in range(n + 1)]
#
# for i in range(1, n * (n - 1) // 2):
#     u, v = list(map(int, input().split()))
#     g[v].append(u)
#     du[u] += 1
#     vis[u][v] = vis[v][u] = True
#
# val = [0 for _ in range(n + 1)]
#
# id = 1
#
# q = deque()
#
# for i in range(1, n + 1):
#     if du[i] == 0:
#         q.append(i)
#
# while len(q) != 0:
#     x = q.popleft()
#     val[x] = id
#     id += 1
#     for v in g[x]:
#         du[v] -= 1
#         if du[v] == 0:
#             q.append(v)
#
# for i in range(1, n + 1):
#     for j in range(i + 1, n + 1):
#         if not vis[i][j]:
#             if val[i] < val[j]:
#                 print(f"{j} {i}")
#             else:
#                 print(f"{i} {j}")

# 4. https://www.luogu.com.cn/problem/CF27C
# import sys
#
# input = lambda : sys.stdin.readline().strip()
#
# n = int(input())
#
# a = [0] +  list(map(int, input().split()))
#
# mx_qian = [-1 for _ in range(n + 1)]
# mx_hou = [-1 for _ in range(n + 1)]
# mi_qian = [-1 for _ in range(n + 1)]
# mi_hou = [-1 for _ in range(n + 1)]
#
# mx_qian[1] = 1
# mi_qian[1] = 1
# mx_hou[n] = n
# mi_hou[n] = n
#
# for i in range(2, n + 1):
#     if a[i] > a[mx_qian[i - 1]]:
#         mx_qian[i] = i
#     else:
#         mx_qian[i] = mx_qian[i - 1]
#     if a[i] < a[mi_qian[i - 1]]:
#         mi_qian[i] = i
#     else:
#         mi_qian[i] = mi_qian[i - 1]
#
# for i in range(n - 1, 0, -1):
#     if a[i] > a[mx_hou[i + 1]]:
#         mx_hou[i] = i
#     else:
#         mx_hou[i] = mx_hou[i + 1]
#     if a[i] < a[mi_hou[i + 1]]:
#         mi_hou[i] = i
#     else:
#         mi_hou[i] = mi_hou[i + 1]
#
# ans = []
#
# for i in range(2, n):
#     if a[i] > a[mi_qian[i - 1]] and a[i] > a[mi_hou[i + 1]]:
#         ans.append(mi_qian[i - 1])
#         ans.append(i)
#         ans.append(mi_hou[i + 1])
#         break
#     if a[i] < a[mx_qian[i - 1]] and a[i] < a[mx_hou[i + 1]]:
#         ans.append(mx_qian[i - 1])
#         ans.append(i)
#         ans.append(mx_hou[i + 1])
#         break
#
# if len(ans) == 0:
#     print(0)
# else:
#     print(3)
#     print(' '.join(map(str, ans)))





