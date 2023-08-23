def rectangle(i):
    global cnt
    for j in range(2, n + 1):
        if i >= j * j and i % j == 0:
            cnt += 1


n = int(input())

cnt = 0
for i in range(1, n + 1):
    cnt += 1
    rectangle(i)

print(cnt)