import sys

input = sys.stdin.readline

n = int(input())
check = [0] * (n + 1)
arr = []
for i in range(2, n + 1):
    if check[i] == 1:
        continue
    for j in range(i + i, n + 1, i):
        check[j] = 1

for i in range(2, n + 1):
    if check[i] == 0:
        arr.append(i)

cnt, Sum = 0, 0
low, high = 0, 0
while 1:
    if Sum == n:
        cnt += 1

    if Sum > n:
        Sum -= arr[low]
        low += 1
    elif high == len(arr):
        break
    else:
        Sum += arr[high]
        high += 1

print(cnt)