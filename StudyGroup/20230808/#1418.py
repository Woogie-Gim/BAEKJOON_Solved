N = int(input())
M = int(input())

arr = [0 for k in range(N+1)]

for i in range(2, N+1):
    if arr[i] == 0:
        for j in range(i, N+1, i):
            if j % i == 0:
                arr[j] = max(arr[j], i)
cnt = 0

for i in arr:
    if i <= M:
        cnt += 1

print(cnt-1)