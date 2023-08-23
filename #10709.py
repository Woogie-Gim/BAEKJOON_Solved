n, m = map(int, input().split())
arr = [list(input()) for _ in range(n)]
ans = [[-1] * m for _ in range(n)]
cnt = 1
level = 0

for i in range(n):
    for j in range(m):
        if arr[i][j] == 'c':
            if ans[i][j] != -1:
                continue
            ans[i][j] = level


while level < m - 1:
    level += 1
    cloud = [['.'] * m for _ in range(n)]
    for i in range(n):
        for j in range(1, m):
            cloud[i][j] = arr[i][j - 1]

    for i in range(n):
        for j in range(m):
            if cloud[i][j] == 'c':
                if ans[i][j] != -1:
                    continue
                ans[i][j] = level

    arr = cloud

for i in ans:
    print(*i, sep = ' ')