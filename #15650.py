N, M = map(int, input().split())
arr = []

def abc(start):
    if len(arr) == M:
       print(' '.join(map(str, arr)))
       return

    for i in range(start, N + 1):
        if i in arr:
            continue
        arr.append(i)
        abc(i + 1)
        arr.pop()

abc(1)