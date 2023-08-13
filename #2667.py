n = int(input())
arr = list(input() for i in range(n))
visited = [[False for _ in range(n)] for _ in range(n)]
dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

def dfs(y, x):
    ret = 1
    visited[y][x] = True

    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if ny < 0 or nx < 0 or ny > n - 1 or nx > n - 1:
            continue
        if visited[ny][nx]:
            continue
        if arr[ny][nx] == '0':
            continue

        ret += dfs(ny, nx) # 연결 요소의 크기 구하기

    return ret

cnt = 0
ans = []

for i in range(n):
    for j in range(n):
        if visited[i][j] or arr[i][j] == '0':
            continue

        cnt += 1 # 연결 요소 개수 구하기
        ans.append(dfs(i, j))

ans.sort()

print(cnt)
for i in ans:
    print(i)