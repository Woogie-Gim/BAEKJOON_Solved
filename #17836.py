from collections import deque

def bfs(sty, stx, edy, edx):
    q = deque()
    directy = [-1, 1, 0, 0]
    directx = [0, 0, -1, 1]
    visited = [[0] * M for _ in range(N)]
    visited[sty][stx] = 1
    q.append([sty, stx, 0])

    while q:
        y, x, Time = q.popleft()

        for i in range(4):
            dy = y + directy[i]
            dx = x + directx[i]

            if dy < 0 or dx < 0 or dy > N - 1 or dx > M - 1:
                continue
            if visited[dy][dx] == 1:
                continue
            if Map[dy][dx] == 1:
                continue
            if dy == edy and dx == edx:
                return Time + 1
            visited[dy][dx] = 1
            q.append([dy, dx, Time + 1])
    return 21e8


N, M, T = map(int, input().split())
Map = [list(map(int, input().split())) for _ in range(N)]

ans = bfs(0, 0, N - 1, M - 1)
for i in range(N):
    for j in range(M):
        if Map[i][j] == 2:
            if ans:
                ret = bfs(0, 0, i, j) + abs(N - 1 - i) + abs(M - 1 - j)
                ans = min(ans, ret)
            else:
                break

if ans:
    if ans <= T:
        print(ans)
    else:
        print('Fail')
else:
    print('Fail')