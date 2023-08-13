n, m = map(int, input().split())

v = [[] for i in range(n + 1)]

for i in range(m):
    s, e = map(int, input().split())

    v[s].append(e)
    v[e].append(s)


visited = [False for i in range(n + 1)]

def dfs(now):
    visited[now] = True

    for i in v[now]:
        if visited[i]:
            continue

        dfs(i)

cnt = 0

for i in range(n + 1):
    if not visited[i]:
        cnt += 1
        dfs(i)

print(cnt - 1)