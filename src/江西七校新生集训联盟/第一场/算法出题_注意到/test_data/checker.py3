inp = open('input')
# inp = open('./test_data/1.in')
n = int(inp.readline().strip())
inp.close()

user_output = open('user_output')
# user_output = open('./test_data/1.out')
ans = user_output.readline().split()
user_output.close()

if len(ans) != 6:
    exit(1)

for i in range(6):
    try:
        ans[i] = int(ans[i])
        ans[i] = ans[i] ** 3
    except:
        exit(1)

if ans[1] == 0 or ans[3] == 0 or ans[5] == 0:
    exit(1)

fenzi = ans[0] * ans[3] * ans[5] + ans[1] * ans[2] * ans[5] + ans[1] * ans[3] * ans[4]
fenmu = ans[1] * ans[3] * ans[5]

res = fenzi / fenmu
if res == n:
    exit(0)
else:
    exit(1) 


