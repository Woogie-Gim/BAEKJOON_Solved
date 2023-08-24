from pprint import pprint
def polygon(start, end, arr):
    for i in range(start, end + 1):
        if arr[i] == 0:
            arr[i] = 1



N = int(input())

arr = [[0] * 1001 for _ in range(1001)]
for i in range(N):
    L, H = map(int, input().split())

    for i in range(H):
        for j in range(L, L + 1):
            arr[i][j] = 1

for i in arr:
    start = 0
    end = 0
    for j in range(len(i)):
        if i[j] == 1:
            if start == 0:
                start = j
            end = j
    if start != 0 and end != 0:
        polygon(start, end, i)

cnt = 0
for i in range(1001):
    for j in range(1001):
        if arr[i][j] == 1:
            cnt += 1

print(cnt)