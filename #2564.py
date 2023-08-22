from collections import deque
def bfs(sty, stx, edy, edx):
    q = deque()
    q.append((sty, stx, 0))

    directy = [-1, 1, 0, 0]
    directx = [0, 0, -1, 1]
    visited = [[0] * (n + 1) for _ in range(m + 1)]
    visited[sty][stx] = 1

    while q:
        y, x, level = q.popleft()

        if y == edy and x == edx:
            return level

        for i in range(4):
            dy = y + directy[i]
            dx = x + directx[i]

            if dy < 0 or dx < 0 or dy > m or dx > n:
                continue
            if visited[dy][dx] == 1:
                continue
            if arr[dy][dx] == 1:
                continue
            visited[dy][dx] = 1
            q.append((dy, dx, level + 1))


n, m = map(int, input().split())
k = int(input())
lst = []
for i in range(k):
    y, x = map(int, input().split())
    lst.append((y, x))

sty, stx = map(int, input().split())

if sty == 1:
    sty = 0
elif sty == 2:
    sty = m
elif sty == 3:
    sty = stx
    stx = 0
elif sty == 4:
    sty = stx
    stx = n

arr = [[0] * (n + 1) for _ in range(m + 1)]
for i in range(1, m):
    for j in range(1, n):
        arr[i][j] = 1

ans = 0
for i in range(k):
    edy, edx = lst[i][0], lst[i][1]
    if edy == 1:
        edy = 0
    elif edy == 2:
        edy = m
    elif edy == 3:
        edy = edx
        edx = 0
    elif edy == 4:
        edy = edx
        edx = n

    ans += bfs(sty, stx, edy, edx)

print(ans)