n = int(input())

arr = [[0] * 102 for _ in range(102)]

for _ in range(n):
    a, b = map(int, input().split())

    for i in range(b, b + 10):
        for j in range(a, a + 10):
            arr[i][j] = 1

cnt = 0
for i in range(1, 101):
    for j in range(1, 101):
        if arr[i][j] == 1:
            cnt += 4
            if arr[i - 1][j] == 1:
                cnt -= 1
            if arr[i + 1][j] == 1:
                cnt -= 1
            if arr[i][j - 1] == 1:
                cnt -= 1
            if arr[i][j + 1] == 1:
                cnt -= 1

print(cnt)
