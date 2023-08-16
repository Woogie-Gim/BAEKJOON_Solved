n = int(input())
arr = []
a, b = 0, 0
cnt = 0
for i in range(n):
    arr.append(list(input()))
for i in range(n):
    cnt = 0
    for j in range(n):
        if arr[i][j] == '.':
            cnt += 1
        else:
            cnt = 0
        if cnt == 2:
            a += 1
for i in range(n):
    cnt = 0
    for j in range(n):
        if arr[j][i] == '.':
            cnt += 1
        else:
            cnt = 0
        if cnt == 2:
            b += 1
print(a, b)