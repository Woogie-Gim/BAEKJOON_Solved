N, M = map(int, input().split())
arr = []
for i in range(1, N + 1):
    arr.append(i)
path = [0] * N
visited = [0] * len(arr)

def abc(level):
    if level == M:
        for i in range(M):
            print(path[i], end = ' ')
        print()
        return

    for i in range(N):
        if visited[i] == 1:
            continue
        path[level] = arr[i]
        visited[i] = 1
        abc(level + 1)
        visited[i] = 0

abc(0)