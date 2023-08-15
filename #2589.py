from collections import deque

n, m = map(int, input().split())
arr = [input() for i in range(n)]
visited = [[[False for k in range(3)] for i in range(m)] for j in range(n)]
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]
que = deque()

def in_range(x, y):
    return 0 <= x < n and 0 <= y < m

def bfs(x, y):
    global ans
    que = deque()
    visited = [[False for i in range(m)] for j in range(n)]

    d = 0
    que.append([x, y])
    visited[x][y] = True
    while len(que) > 0:
        size = len(que)

        for _ in range(size):
            x, y = que[0][0], que[0][1]
            que.popleft()

            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]

                if not in_range(nx, ny) or visited[nx][ny] or arr[nx][ny] != 'L':
                    continue

                que.append([nx, ny])
                visited[nx][ny] = True

        d += 1

    return d - 1

ans = 0
for i in range(n):
    for j in range(m):
        if arr[i][j] == 'L':
            ans = max(ans, bfs(i, j))

print(ans)