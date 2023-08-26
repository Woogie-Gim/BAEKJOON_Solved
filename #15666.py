N, M = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()
ans = []

def abc(start, level, lst):
    if level == M:
        ans.append(lst)
        return

    prev = 0
    for i in range(start, N):
        if prev != arr[i]:
            prev = arr[i]
            abc(i, level + 1, lst + [arr[i]])

abc(0, 0, [])

for arr in ans:
    print(*arr)