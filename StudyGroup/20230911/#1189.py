import sys
sys.setrecursionlimit(9999)
r, c, k = map(int, input().split())
arr = [list(input()) for _ in range(r)]
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
dict = {}


def dfs(x, y, d, visited):
    visited.append([x, y])
    if x == 0 and y == c - 1:
        if d in dict:
            dict[d] += 1
        else:
            dict[d] = 1
        return

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if 0 <= nx < r and 0 <= ny < c and arr[nx][ny] != 'T' and [nx, ny] not in visited:
            dfs(nx, ny, d + 1, visited + [nx, ny])


dfs(r-1, 0, 1, [])
print(dict[k] if k in dict else 0)