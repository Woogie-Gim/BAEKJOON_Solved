N, M = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()
path = [0] * N
visited = [0] * N

def abc(start, level):
    if level == M:
        for i in range(M):
            print(path[i], end = ' ')
        print()
        return

    for i in range(N):
        if visited[i] == 1:
            continue
        visited[i] = 1
        path[level] = arr[i]
        abc(i, level + 1)
        visited[i] = 0


abc(1, 0)