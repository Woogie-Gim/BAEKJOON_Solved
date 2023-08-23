def dfs(level, Sum):
    if Sum > M:
        return
    if level == 3:
        ans.append(Sum)
        return

    for i in range(N):
        if visited[i] == 1:
            continue
        visited[i] = 1
        dfs(level + 1, Sum + arr[i])
        visited[i] = 0

N, M = map(int, input().split())
arr = list(map(int, input().split()))

level = 0
Max = -21e8
ans = []
visited = [0] * N
dfs(0, 0)

for i in ans:
    if i > Max:
        Max = i

print(Max)