N, M = map(int, input().split())
arr = [i for i in range(1, N + 1)]
path = [0] * N

def abc(start,level):
    if level == M:
        for i in range(M):
            print(path[i], end = ' ')
        print()
        return

    for i in range(start, N):
        path[level] = arr[i]
        abc(i, level + 1)


abc(0, 0)