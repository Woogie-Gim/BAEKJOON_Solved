N, M = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()
ans = []
visited = [0] * N

def abc(start, level, lst):
    if level == M:
        ans.append(lst)
        return

    prev = 0
    for i in range(start, N):
        if visited[i] == 0 and prev != arr[i]:
            prev = arr[i]
            visited[i] = 1
            abc(i, level + 1, lst + [arr[i]])
            visited[i] = 0

abc(0, 0, [])

for arr in ans:
    print(*arr)