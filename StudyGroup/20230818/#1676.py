import sys
input = sys.stdin.readline

def factorial(n):
    rtn = 1
    for i in range(1, n + 1):
        rtn *= i

    return rtn

n = int(input())
ans = factorial(n)
strr = str(ans)
cnt = 0
for i in range(len(strr)-1, -1, -1):
    if strr[i] == '0':
        cnt += 1
    else:
        break

print(cnt)