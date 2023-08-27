def dfs(level, Sum):
    global Max
    if level == 11:
        if Max < Sum:
            Max = Sum
        return


    for i in range(11):
        if visited[i] == 1:
            continue
        if arr[i][level] == 0:
            continue
        visited[i] = 1
        dfs(level + 1, Sum + arr[i][level])
        visited[i] = 0

T = int(input())

for i in range(T):
    arr = [list(map(int, input().split())) for _ in range(11)]
    Max = -21e8
    visited = [0] * 11

    dfs(0, 0)
    print(Max)