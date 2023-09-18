from collections import deque


# BFS
def bfs(x, y, color):
    cnt = 0
    queue = deque()
    queue.append((x, y))
    graph[x][y] = 0

    while queue:
        x, y = queue.popleft()
        cnt += 1
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < m and 0 <= ny < n:
                if (graph[nx][ny] == color):
                    queue.append((nx, ny))
                    graph[nx][ny] = 0
    return cnt


n, m = map(int, input().split())
graph = [list(input()) for _ in range(m)]
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

white = 0
blue = 0
for i in range(m):
    for j in range(n):
        if (graph[i][j] == 'W'):
            white += (bfs(i, j, 'W')) ** 2
        elif (graph[i][j] == 'B'):
            blue += (bfs(i, j, 'B')) ** 2

print(white, blue)