N = int(input())

arr = [[0] * 1002 for _ in range(1002)]
for i in range(1, N + 1):
    a, b, c, d = map(int, input().split())

    for j in range(b, b + d):
        for k in range(a, a + c):
            arr[j][k] = i

ans = []
for k in range(1, N + 1):
    Sum = 0
    for i in range(1002):
        for j in range(1002):
            if arr[i][j] == k:
                Sum += 1
    ans.append(Sum)

for i in ans:
    print(i)