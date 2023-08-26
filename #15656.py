N, M = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()
path = [0] * N
def abc(level):
    if level == M:
        for i in range(M):
            print(path[i], end = ' ')
        print()
        return

    for i in range(N):
        path[level] = arr[i]
        abc(level + 1)

abc(0)