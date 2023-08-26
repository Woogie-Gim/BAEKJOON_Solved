N, M = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()
ans = []
def abc(level, lst):
    if level == M:
        ans.append(lst)
        return

    prev = 0
    for i in range(N):
        if prev != arr[i]:
            prev = arr[i]
            abc(level + 1, lst + [arr[i]])

abc(0, [])

for arr in ans:
    print(*arr)