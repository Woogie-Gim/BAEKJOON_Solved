lst = []
for i in range(4):
    a, b, c, d = map(int, input().split())
    lst.append((a, b))
    lst.append((c, d))

arr = [[0] * 100 for _ in range(100)]

for i in range(0, 7, 2):
    for k in range(lst[i][1], lst[i + 1][1]):
        for l in range(lst[i][0], lst[i + 1][0]):
            arr[k][l] = 1

cnt = 0
for i in range(100):
    for j in range(100):
        if arr[i][j] == 1:
            cnt += 1

print(cnt)